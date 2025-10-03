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

#ifndef _I386_SVM_CPU_H_
#define _I386_SVM_CPU_H_

#include <mach/boolean.h>
#include <mach/machine/vm_types.h>

/* For this subsystem; I'll use a similar naming scheme to the VMX functions */

boolean_t svm_hv_support(void);

#define SVM_FEATURE_NESTEDPAGING  (1 << 0)  /* Available K10+ */
#define SVM_FEATURE_LBRVIRT       (1 << 1)  /* Available on K8+ */
#define SVM_FEATURE_SVML          (1 << 2)  /* Available K10+ */
#define SVM_FEATURE_NRIPS         (1 << 3)  /* Available K10 (Revision C)+ */
#define SVM_FEATURE_TSCRATE       (1 << 4)
#define SVM_FEATURE_VMCBCLEAN     (1 << 5)
#define SVM_FEATURE_FLUSHBYASID   (1 << 6)
#define SVM_FEATURE_DECODEASSISTS (1 << 7)
#define SVM_FEATURE_PAUSEFILTER   (1 << 10) /* Available K10 (Revision D)+ */
#define SVM_FEATURE_PFTHRESHOLD   (1 << 12)
#define SVM_FEATURE_AVIC          (1 << 13)
#define SVM_FEATURE_NESTED_VIRT   (1 << 15)
#define SVM_FEATURE_VGIF          (1 << 16)


typedef struct svm_specs {
    boolean_t   svm_present;    /* If the host supports SVM */
    boolean_t   svm_enabled;    /* If the current CPU has SVM enabled */

    uint32_t    revision;   /* The revision of SVM as detected from CPUID. */
    uint32_t    num_asids;      /* The number of available ASIDs */

    uint32_t    features;       /* CPUID 8000000a - EDX */

    boolean_t   inited;
} svm_specs_t;

typedef struct svm_cpu {
    svm_specs_t     specs;
    void            *svm_hsave_page; /* Written to HSAVE_PA */
    void            *svm_vmcb_page;  /* The main VMCB page */
} svm_cpu_t;

void svm_cpu_init(void);

boolean_t svm_has_feature(uint32_t feature);

/*
 * TODO: rest of the SVM subsytem for a hv to use.
 *
 * host_svm_get_vmcb
 * host_svm_get_features
 *
 * i believe the HSAVE only needs to be programmed once?
 */

#endif
