/*
 * Copyright (c) 2025, Samuel Zormeister
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 /*
  * Portions Copyright (c) 2006-2012 Apple Computer, Inc. All rights reserved.
  *
  * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
  *
  * This file contains Original Code and/or Modifications of Original Code
  * as defined in and that are subject to the Apple Public Source License
  * Version 2.0 (the 'License'). You may not use this file except in
  * compliance with the License. The rights granted to you under the License
  * may not be used to create, or enable the creation or redistribution of,
  * unlawful or unlicensed copies of an Apple operating system, or to
  * circumvent, violate, or enable the circumvention or violation of, any
  * terms of an Apple operating system software license agreement.
  *
  * Please obtain a copy of the License at
  * http://www.opensource.apple.com/apsl/ and read it before using this file.
  *
  * The Original Code and all software distributed under the License are
  * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
  * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
  * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
  * Please see the License for the specific language governing rights and
  * limitations under the License.
  *
  * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
  */

#include <i386/cpu_data.h>
#include <i386/cpu_threads.h>
#include <i386/cpuid.h>
#include <i386/mp.h>
#include <i386/proc_reg.h>
#include <i386/svm.h>
#include <i386/svm/svm_cpu.h>
#include <i386/vmx/vmx_shims.h>
#include <mach/i386/vm_param.h>
#include <pexpert/pexpert.h>
#include <vm/vm_kern.h>

#define SVM_KPRINTF(x...) kprintf("svm: " x)

/* DISABLE THIS WHEN SVM IS PRODUCTION READY!!! */
#define SVM_DIAGNOSTICS 1

int svm_use_count = 0;
boolean_t svm_exclusive = FALSE;

lck_grp_t *svm_lck_grp = NULL;
lck_mtx_t *svm_lck_mtx = NULL;

void svm_init(void)
{
    svm_lck_grp = lck_grp_alloc_init("svm", LCK_GRP_ATTR_NULL);
    assert(svm_lck_grp);
    svm_lck_mtx = lck_mtx_alloc_init(svm_lck_grp, LCK_ATTR_NULL);
    assert(svm_lck_mtx);
}

static
boolean_t svm_is_available(void)
{
    return !((cpuid_extfeatures() & CPUID_EXTFEATURE_SVM) == 0);
}

static
boolean_t svm_disabled_by_firmware(void)
{
    uint64_t msr = rdmsr64(MSR_AMD64_VM_CR);
    return ((msr & MSR_AMD64_VM_CR_LOCK) && (msr & MSR_AMD64_VM_CR_SVME_DISABLE));
}

static boolean_t
svm_locked(void)
{
    uint64_t msr = rdmsr64(MSR_AMD64_VM_CR);
    return ((msr & MSR_AMD64_VM_CR_LOCK));
}

static struct svm_feature {
    uint32_t flag;
    const char *name;
} svm_features_table[] = {
    {SVM_FEATURE_NESTEDPAGING,  "NESTED PAGING"},
    {SVM_FEATURE_LBRVIRT,       "LBR VIRTUALIZATION"},
    {SVM_FEATURE_SVML,          "SVM LOCK"},
    {SVM_FEATURE_NRIPS,         "NRIPS"},
    {SVM_FEATURE_TSCRATE,       "TSC RATE MSR"},
    {SVM_FEATURE_VMCBCLEAN,     "VMCB CLEAN"},
    {SVM_FEATURE_FLUSHBYASID,   "FLUSH BY ASID"},
    {SVM_FEATURE_DECODEASSISTS, "DECODE ASSISTS"},
    {SVM_FEATURE_PAUSEFILTER,   "PAUSE FILTER"},
    {SVM_FEATURE_PFTHRESHOLD,   "PF THRESHOLD"},
    {SVM_FEATURE_AVIC,          "AVIC"},
    {SVM_FEATURE_NESTED_VIRT,   "NESTED VIRTUALIZATION"},
    {SVM_FEATURE_VGIF,          "VGIF"},
};

#define SVM_FEATURE_NUM sizeof(svm_features_table) / \
                            sizeof(struct svm_feature)

boolean_t svm_hv_support()
{
    /*
     * TLDR; AppleHV relies on Extended Page Tables and Unrestricted Guest modes.
     *
     * AMD-V's equivalent to EPT is Nesed Page Tables.
     *
     * As for URG, AMD-V can run V8086 mode just fine, and also enable paging in V8086 mode.
     * I'm serious about that last one by the way, read the "Paged Real Mode" section of the
     * AMD64 Architecture Programmer’s Manual, section 15.19 - Paged Real Mode.
     */

    if (!(svm_is_available() && !svm_disabled_by_firmware())) {
        SVM_KPRINTF("AMD-V is either unavailable or locked by the firmware.\n");
        return FALSE;
    }

    if ((current_cpu_datap()->cpu_svm.specs.features & SVM_FEATURE_NESTEDPAGING) == 0) {
        SVM_KPRINTF("No nested paging support, returning FALSE for HV support.\n");
        return FALSE;
    }

    return TRUE;
}

/*
 * Later OSRR/BKDGs refer to the HSAVE region as a "4K region" instead of "4K aligned page"
 */
static void *
svm_allocate_hsave_region(void)
{
    char            *pptr;
	kern_return_t   ret;
	ret = kmem_alloc_kobject(kernel_map, (vm_offset_t *)&pptr, (PAGE_SIZE * KB), VM_KERN_MEMORY_OSFMK);
	if (ret != KERN_SUCCESS) {
		return NULL;
	}
	bzero(pptr, (PAGE_SIZE * KB));
	return pptr;
}

static void
svm_enable(void)
{
    uint64_t efer = rdmsr64(MSR_IA32_EFER);
    uint64_t cr = rdmsr64(MSR_AMD64_VM_CR);

    /* if somehow this happens */
    if (0 == (cr & MSR_AMD64_VM_CR_LOCK)) {
        /* Well this is a weird scenario. But one that could happen; lord knows. */
        cr &= ~(MSR_AMD64_VM_CR_SVME_DISABLE);
        cr |= MSR_AMD64_VM_CR_LOCK;
        wrmsr64(MSR_AMD64_VM_CR, cr);
    } else {
        if (0 == (cr & MSR_AMD64_VM_CR_SVME_DISABLE)) {
            efer |= MSR_IA32_EFER_SVME;
            wrmsr64(MSR_IA32_EFER, efer);
        }
    }
}

#if DEVELOPMENT || DEBUG
static void
svm_dump_features(cpu_data_t *cpu)
{
    unsigned int i;

    kprintf("CPU%d AMD-V Features: ", cpu->cpu_number);

    for (i = 0; i < SVM_FEATURE_NUM; i++) {
        if (cpu->cpu_svm.specs.features & svm_features_table[i].flag) {
            kprintf("%s", svm_features_table[i].name);
        }
    }

    kprintf("\n");
}
#endif

static void
svm_allocate_hsave_regions(void)
{
    unsigned int i;

    for (i = 0; i < real_ncpus; i++) {
        svm_cpu_t *cpu = &cpu_datap(i)->cpu_svm;

        cpu->hsave_region = svm_allocate_hsave_region();
        if (cpu->hsave_region == NULL) {
            panic("svm_allocate_hsave_regions: failed to allocated hsave for CPU%d", cpu_datap(i)->cpu_number);
        }

#if SVM_DIAGNOSTICS
        SVM_KPRINTF("CPU%d HSAVE location: %p", cpu_datap(i)->cpu_number, cpu->hsave_region);
#endif
    }
}

static void
__svm_configure(void *arg __unused)
{
    svm_cpu_t *svm = &current_cpu_datap()->cpu_svm;
    addr64_t hsave_paddr;

    if (svm->hsave_region == NULL) {
        panic("__svm_configure: HSAVE region cannot be null!");
    }

    hsave_paddr = vmx_paddr(svm->hsave_region);
    if (hsave_paddr > svm->specs.highest_hsave_pa) {
        panic("__svm_configure: HSAVE region is too high in physical memory!!!");
    }

    wrmsr64(MSR_AMD64_VM_HSAVE_PA, hsave_paddr);
}

static void
__svm_unlock_with_key(void *arg)
{
    host_svm_key_t *key = (host_svm_key_t *)arg;
    uint64_t       vm_cr;

    if (current_cpu_datap()->cpu_svm.locked == FALSE) {
        return;
    }

    wrmsr64(MSR_AMD64_VM_LOCK_KEY, *key);

    vm_cr = rdmsr64(MSR_AMD64_VM_CR);
    if ((vm_cr & MSR_AMD64_VM_CR_LOCK) == 0) {
        current_cpu_datap()->cpu_svm.locked = FALSE;
    }
}

static boolean_t
svm_is_enabled(void)
{
    return !((rdmsr64(MSR_IA32_EFER) & MSR_IA32_EFER_SVME) == 0);
}

void
svm_cpu_init(void)
{
    uint32_t        reg[4];
    svm_cpu_t       *cpu = &current_cpu_datap()->cpu_svm;
    i386_cpu_info_t *info_p = cpuid_info();

    if (cpu->specs.inited) {
        return;
    }

    svm_enable();

    /* Fetch this CPU's features. */
    do_cpuid(0x8000000a, reg);
    cpu->specs.revision = bitfield32(reg[eax], 7, 0);
    cpu->specs.num_asids = reg[ebx];
    cpu->specs.features = reg[edx];

    switch (info_p->cpuid_cpufamily) {
        case CPUFAMILY_AMD_ZEN3:
        case CPUFAMILY_AMD_ZEN2:
        case CPUFAMILY_AMD_ZENX:
        case CPUFAMILY_AMD_ZEN:
            cpu->specs.highest_hsave_pa = SVM_ZEN_HSAVE_LIMIT;
            break;
        case CPUFAMILY_AMD_BOBCAT:
            cpu->specs.highest_hsave_pa = SVM_BOBCAT_HSAVE_LIMIT;
            break;
        default:
            cpu->specs.highest_hsave_pa = SVM_K10_HSAVE_LIMIT;
            break;
    }

    cpu->specs.svm_present = svm_is_enabled();

    cpu->locked = svm_locked();

    cpu->specs.inited = TRUE;

#if DEVELOPMENT || DEBUG
    svm_dump_features(current_cpu_datap());
#endif
}

static boolean_t
svm_globally_available(void)
{
	unsigned int i;
	unsigned int ncpus = ml_get_max_cpus();
	boolean_t available = TRUE;

	for (i = 0; i < ncpus; i++) {
		svm_cpu_t *cpu = &cpu_datap(i)->cpu_svm;

		if (!cpu->specs.svm_present) {
			available = FALSE;
		}
	}
	SVM_KPRINTF("SVM available: %d\n", available);
	return available;
}

int host_svm_enable(boolean_t exclusive)
{
   	int error;

	assert(0 == get_preemption_level());

	if (!svm_globally_available()) {
		return SVM_UNSUPPORTED;
	}

	lck_mtx_lock(svm_lck_mtx);

	if (svm_exclusive || (exclusive && svm_use_count)) {
		error = SVM_INUSE;
	} else {
		if (0 == svm_use_count) {
			svm_allocate_hsave_regions();
			svm_exclusive = exclusive;
			svm_use_count = 1;
			mp_cpus_call(CPUMASK_ALL, ASYNC, __svm_configure, NULL);
		} else {
			svm_use_count++;
		}

		SVM_KPRINTF("SVM use count: %d\n", svm_use_count);
		error = SVM_SUCCESS;
	}

	lck_mtx_unlock(svm_lck_mtx);

	return error;
}
