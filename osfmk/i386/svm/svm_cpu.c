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

#include <i386/cpu_data.h>
#include <i386/cpu_threads.h>
#include <i386/cpuid.h>
#include <i386/proc_reg.h>
#include <i386/svm/svm_cpu.h>
#include <i386/vmx/vmx_shims.h>
#include <pexpert/pexpert.h>

#define SVM_KPRINTF(x...) kprintf("svm: " x)

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

static struct svm_features {
    uint32_t flag;
    const char *name;
} svm_features_table[] = {
    {SVM_FEATURE_NESTEDPAGING, "NESTED PAGING"},
    {SVM_FEATURE_LBRVIRT,      "LBR VIRTUALIZATION"},
    {SVM_FEATURE_SVML,         "SVM LOCK"},
    {SVM_FEATURE_NRIPS,        "NRIPS"},
    {SVM_FEATURE_TSCRATE,      "TSC RATE MSR"},
};

boolean_t svm_hv_support()
{
    if (svm_is_available() && !svm_disabled_by_firmware()) {
        SVM_KPRINTF("SVM is available on this machine.\n");
        return TRUE;
    }

    /* Hypervisor support for VT-x is dependent on the availability of EPT; nested page tables. */

    return FALSE;
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


void
svm_cpu_init(void)
{
    uint32_t reg[4];
    svm_cpu_t *cpu = &current_cpu_datap()->cpu_svm;

    if (cpu->specs.inited) {
        return;
    }

    svm_enable();

    /* Fetch this CPU's features. */
    do_cpuid(0x8000000a, reg);
    cpu->specs.revision = bitfield32(reg[eax], 7, 0);
    cpu->specs.num_asids = reg[ebx];
    cpu->specs.features = reg[edx];
}

boolean_t
svm_has_feature(uint32_t feature)
{
    return 0 != (current_cpu_datap()->cpu_svm.specs.features & feature);
}
