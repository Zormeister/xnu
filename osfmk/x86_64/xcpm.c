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

#include <pexpert/pexpert.h>

/*
 * What in the grand hell is XCPM?
 *
 * XCPM is (most likely) Apple's built-in power management for x86, which... sits in the kernel. for some reason.
 *
 * It runs for Haswell and newer, IIRC.
 *
 * Something something Intel SpeedStep, IDFK man.
 *
 * The reason why we need these godforsaken stubs is for linking compatibility with an actual macOS system.
 */

#define XCPM_STUB(func) \
    void func (void); \
                      \
    void func (void) {  \
        kprintf("%s has been called.", __FUNCTION__); \
    }

/* Stubs based on symbol dump from 10.15.7 (19H2026). */
/*
 * com.apple.kpi.private:
 * U _xcpm_bios_mbox_cmd_read
 * U _xcpm_bios_mbox_cmd_unsafe_read
 * U _xcpm_bios_mbox_cmd_write
 * U _xcpm_is_hwp_enabled
 * U _xcpm_mbox_lock
 * U _xcpm_mbox_unlock
 */

/* Symbols make mention of 'xcpm_mchbar', so I did some digging. */

XCPM_STUB(xcpm_bios_mbox_cmd_read);             /* Reads BIOS_Mailbox_Interface_0_0_0_MCHBAR_PCU */
XCPM_STUB(xcpm_bios_mbox_cmd_unsafe_read);      /* Reads BIOS_Mailbox_Interface_0_0_0_MCHBAR_PCU (presumably without a lock) */
XCPM_STUB(xcpm_bios_mbox_cmd_write);            /* Writes BIOS_Mailbox_Interface_0_0_0_MCHBAR_PCU */
XCPM_STUB(xcpm_is_hwp_enabled);                 /* Something. */
XCPM_STUB(xcpm_mbox_lock);                      /* Locks the BIOS Mailbox lock? */
XCPM_STUB(xcpm_mbox_unlock);                    /* Unlocks the BIOS Mailbox lock? */
