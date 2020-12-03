/*
 * Copyright (c) 2012 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux.
 *
 * This file has been automatically generated.
 *
 * PMU: snbep_unc_r3qpi (Intel SandyBridge-EP R3QPI uncore)
 */

static const intel_x86_umask_t snbep_unc_r3_iio_credits_acquired[] = {
    {
        .uname = "DRS",
        .udesc = "DRS",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB",
        .udesc = "NCB",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .udesc = "NCS",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t snbep_unc_r3_ring_ad_used[] = {
    {
        .uname = "CCW_EVEN",
        .udesc = "Counter-Clockwise and even ring polarity",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CCW_ODD",
        .udesc = "Counter-Clockwise and odd ring polarity",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CW_EVEN",
        .udesc = "Clockwise and even ring polarity",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CW_ODD",
        .udesc = "Clockwise and odd ring polarity",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t snbep_unc_r3_ring_iv_used[] = {
    {
        .uname = "ANY",
        .udesc = "Any polarity",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t snbep_unc_r3_rxr_bypassed[] = {
    {
        .uname = "AD",
        .udesc = "Ingress Bypassed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t snbep_unc_r3_rxr_cycles_ne[] = {
    {
        .uname = "DRS",
        .udesc = "DRS Ingress queue",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .udesc = "HOM Ingress queue",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB",
        .udesc = "NCB Ingress queue",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .udesc = "NCS Ingress queue",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR",
        .udesc = "NDR Ingress queue",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SNP",
        .udesc = "SNP Ingress queue",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t snbep_unc_r3_vn0_credits_reject[] = {
    {
        .uname = "DRS",
        .udesc = "Filter DRS message class",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .udesc = "Filter HOM message class",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB",
        .udesc = "Filter NCB message class",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .udesc = "Filter NCS message class",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR",
        .udesc = "Filter NDR message class",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SNP",
        .udesc = "Filter SNP message class",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_entry_t intel_snbep_unc_r3_pe[] = {
    {
        .name = "UNC_R3_CLOCKTICKS",
        .desc = "Number of uclks in domain",
        .code = 0x1,
        .cntmsk = 0x7,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_IIO_CREDITS_ACQUIRED",
     .desc = "to IIO BL Credit Acquired",
     .code = 0x20,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_iio_credits_acquired),
     .umasks = snbep_unc_r3_iio_credits_acquired},
    {
        .name = "UNC_R3_IIO_CREDITS_REJECT",
        .desc = "to IIO BL Credit Rejected",
        .code = 0x21,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_iio_credits_acquired),
        .umasks = snbep_unc_r3_iio_credits_acquired /* shared */
    },
    {
        .name = "UNC_R3_IIO_CREDITS_USED",
        .desc = "to IIO BL Credit In Use",
        .code = 0x22,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_iio_credits_acquired),
        .umasks = snbep_unc_r3_iio_credits_acquired /* shared */
    },
    {.name = "UNC_R3_RING_AD_USED",
     .desc = "R3 AD Ring in Use",
     .code = 0x7,
     .cntmsk = 0x7,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_ring_ad_used),
     .umasks = snbep_unc_r3_ring_ad_used},
    {
        .name = "UNC_R3_RING_AK_USED",
        .desc = "R3 AK Ring in Use",
        .code = 0x8,
        .cntmsk = 0x7,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_ring_ad_used),
        .umasks = snbep_unc_r3_ring_ad_used /* shared */
    },
    {
        .name = "UNC_R3_RING_BL_USED",
        .desc = "R3 BL Ring in Use",
        .code = 0x9,
        .cntmsk = 0x7,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_ring_ad_used),
        .umasks = snbep_unc_r3_ring_ad_used /* shared */
    },
    {.name = "UNC_R3_RING_IV_USED",
     .desc = "R3 IV Ring in Use",
     .code = 0xa,
     .cntmsk = 0x7,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_ring_iv_used),
     .umasks = snbep_unc_r3_ring_iv_used},
    {.name = "UNC_R3_RXR_BYPASSED",
     .desc = "Ingress Bypassed",
     .code = 0x12,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_rxr_bypassed),
     .umasks = snbep_unc_r3_rxr_bypassed},
    {.name = "UNC_R3_RXR_CYCLES_NE",
     .desc = "Ingress Cycles Not Empty",
     .code = 0x10,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_rxr_cycles_ne),
     .umasks = snbep_unc_r3_rxr_cycles_ne},
    {
        .name = "UNC_R3_RXR_INSERTS",
        .desc = "Ingress Allocations",
        .code = 0x11,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_rxr_cycles_ne),
        .umasks = snbep_unc_r3_rxr_cycles_ne /* shared */
    },
    {
        .name = "UNC_R3_RXR_OCCUPANCY",
        .desc = "Ingress Occupancy Accumulator",
        .code = 0x13,
        .cntmsk = 0x1,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_rxr_cycles_ne),
        .umasks = snbep_unc_r3_rxr_cycles_ne /* shared */
    },
    {
        .name = "UNC_R3_TXR_CYCLES_FULL",
        .desc = "Egress cycles full",
        .code = 0x25,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {
        .name = "UNC_R3_TXR_INSERTS",
        .desc = "Egress allocations",
        .code = 0x24,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {
        .name = "UNC_R3_TXR_NACK",
        .desc = "Egress Nack",
        .code = 0x26,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_VN0_CREDITS_REJECT",
     .desc = "VN0 Credit Acquisition Failed on DRS",
     .code = 0x37,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_vn0_credits_reject),
     .umasks = snbep_unc_r3_vn0_credits_reject},
    {
        .name = "UNC_R3_VN0_CREDITS_USED",
        .desc = "VN0 Credit Used",
        .code = 0x36,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_vn0_credits_reject),
        .umasks = snbep_unc_r3_vn0_credits_reject /* shared */
    },
    {
        .name = "UNC_R3_VNA_CREDITS_ACQUIRED",
        .desc = "VNA credit Acquisitions",
        .code = 0x33,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {
        .name = "UNC_R3_VNA_CREDITS_REJECT",
        .desc = "VNA Credit Reject",
        .code = 0x34,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_r3_vn0_credits_reject),
        .umasks = snbep_unc_r3_vn0_credits_reject /* shared */
    },
    {
        .name = "UNC_R3_VNA_CREDIT_CYCLES_OUT",
        .desc = "Cycles with no VNA credits available",
        .code = 0x31,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
    {
        .name = "UNC_R3_VNA_CREDIT_CYCLES_USED",
        .desc = "Cycles with 1 or more VNA credits in use",
        .code = 0x32,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_R3QPI_ATTRS,
    },
};
