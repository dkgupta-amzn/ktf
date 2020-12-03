/*
 * Copyright (c) 2014 Google Inc. All rights reserved
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
 * PMU: ivbep_unc_r3qpi (Intel IvyBridge-EP R3QPI uncore)
 */

static const intel_x86_umask_t ivbep_unc_r3_ring_ad_used[] = {
    {
        .uname = "CCW_VR0_EVEN",
        .udesc = "Counter-Clockwise and even ring polarity on virtual ring 0",
        .ucode = 0x400,
    },
    {
        .uname = "CCW_VR0_ODD",
        .udesc = "Counter-Clockwise and odd ring polarity on virtual ring 0",
        .ucode = 0x800,
    },
    {
        .uname = "CW_VR0_EVEN",
        .udesc = "Clockwise and even ring polarity on virtual ring 0",
        .ucode = 0x100,
    },
    {
        .uname = "CW_VR0_ODD",
        .udesc = "Clockwise and odd ring polarity on virtual ring 0",
        .ucode = 0x200,
    },
    {
        .uname = "CW",
        .udesc = "Clockwise with any polarity on either virtual rings",
        .ucode = 0x3300,
    },
    {
        .uname = "CCW",
        .udesc = "Counter-clockwise with any polarity on either virtual rings",
        .ucode = 0xcc00,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_ring_iv_used[] = {
    {
        .uname = "CW",
        .udesc = "Clockwise with any polarity on either virtual rings",
        .ucode = 0x3300,
    },
    {
        .uname = "CCW",
        .udesc = "Counter-clockwise with any polarity on either virtual rings",
        .ucode = 0xcc00,
    },
    {
        .uname = "ANY",
        .udesc = "Counter-clockwise with any polarity on either virtual rings",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_rxr_cycles_ne[] = {
    {
        .uname = "HOM",
        .udesc = "HOM Ingress queue",
        .ucode = 0x100,
    },
    {
        .uname = "SNP",
        .udesc = "SNP Ingress queue",
        .ucode = 0x200,
    },
    {
        .uname = "NDR",
        .udesc = "NDR Ingress queue",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_rxr_inserts[] = {
    {
        .uname = "DRS",
        .udesc = "DRS Ingress queue",
        .ucode = 0x800,
    },
    {
        .uname = "HOM",
        .udesc = "HOM Ingress queue",
        .ucode = 0x100,
    },
    {
        .uname = "NCB",
        .udesc = "NCB Ingress queue",
        .ucode = 0x1000,
    },
    {
        .uname = "NCS",
        .udesc = "NCS Ingress queue",
        .ucode = 0x2000,
    },
    {
        .uname = "NDR",
        .udesc = "NDR Ingress queue",
        .ucode = 0x400,
    },
    {
        .uname = "SNP",
        .udesc = "SNP Ingress queue",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_vn0_credits_used[] = {
    {
        .uname = "HOM",
        .udesc = "Filter HOM message class",
        .ucode = 0x100,
    },
    {
        .uname = "SNP",
        .udesc = "Filter SNP message class",
        .ucode = 0x200,
    },
    {
        .uname = "NDR",
        .udesc = "Filter NDR message class",
        .ucode = 0x400,
    },
    {
        .uname = "DRS",
        .udesc = "Filter DRS message class",
        .ucode = 0x800,
    },
    {
        .uname = "NCB",
        .udesc = "Filter NCB message class",
        .ucode = 0x1000,
    },
    {
        .uname = "NCS",
        .udesc = "Filter NCS message class",
        .ucode = 0x2000,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_c_hi_ad_credits_empty[] = {
    {
        .uname = "CBO8",
        .udesc = "CBox 8",
        .ucode = 0x100,
    },
    {
        .uname = "CBO9",
        .udesc = "CBox 9",
        .ucode = 0x200,
    },
    {
        .uname = "CBO10",
        .udesc = "CBox 10",
        .ucode = 0x400,
    },
    {
        .uname = "CBO11",
        .udesc = "CBox 11",
        .ucode = 0x800,
    },
    {
        .uname = "CBO12",
        .udesc = "CBox 12",
        .ucode = 0x1000,
    },
    {
        .uname = "CBO13",
        .udesc = "CBox 13",
        .ucode = 0x2000,
    },
    {
        .uname = "CBO14",
        .udesc = "CBox 14 & 16",
        .ucode = 0x4000,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_c_lo_ad_credits_empty[] = {
    {
        .uname = "CBO0",
        .udesc = "CBox 0",
        .ucode = 0x100,
    },
    {
        .uname = "CBO1",
        .udesc = "CBox 1",
        .ucode = 0x200,
    },
    {
        .uname = "CBO2",
        .udesc = "CBox 2",
        .ucode = 0x400,
    },
    {
        .uname = "CBO3",
        .udesc = "CBox 3",
        .ucode = 0x800,
    },
    {
        .uname = "CBO4",
        .udesc = "CBox 4",
        .ucode = 0x1000,
    },
    {
        .uname = "CBO5",
        .udesc = "CBox 5",
        .ucode = 0x2000,
    },
    {
        .uname = "CBO6",
        .udesc = "CBox 6",
        .ucode = 0x4000,
    },
    {
        .uname = "CBO7",
        .udesc = "CBox 7",
        .ucode = 0x8000,
    }};

static const intel_x86_umask_t ivbep_unc_r3_ha_r2_bl_credits_empty[] = {
    {
        .uname = "HA0",
        .udesc = "HA0",
        .ucode = 0x100,
    },
    {
        .uname = "HA1",
        .udesc = "HA1",
        .ucode = 0x200,
    },
    {
        .uname = "R2_NCB",
        .udesc = "R2 NCB messages",
        .ucode = 0x400,
    },
    {
        .uname = "R2_NCS",
        .udesc = "R2 NCS messages",
        .ucode = 0x800,
    }};

static const intel_x86_umask_t ivbep_unc_r3_qpi0_ad_credits_empty[] = {
    {
        .uname = "VNA",
        .udesc = "VNA",
        .ucode = 0x100,
    },
    {
        .uname = "VN0_HOM",
        .udesc = "VN0 HOM messages",
        .ucode = 0x200,
    },
    {
        .uname = "VN0_SNP",
        .udesc = "VN0 SNP messages",
        .ucode = 0x400,
    },
    {
        .uname = "VN0_NDR",
        .udesc = "VN0 NDR messages",
        .ucode = 0x800,
    },
    {
        .uname = "VN1_HOM",
        .udesc = "VN1 HOM messages",
        .ucode = 0x1000,
    },
    {
        .uname = "VN1_SNP",
        .udesc = "VN1 SNP messages",
        .ucode = 0x2000,
    },
    {
        .uname = "VN1_NDR",
        .udesc = "VN1 NDR messages",
        .ucode = 0x4000,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_txr_nack_ccw[] = {
    {
        .uname = "AD",
        .udesc = "BL counter-clockwise Egress queue",
        .ucode = 0x100,
    },
    {
        .uname = "AK",
        .udesc = "AD clockwise Egress queue",
        .ucode = 0x200,
    },
    {
        .uname = "BL",
        .udesc = "AD counter-clockwise Egress queue",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_txr_nack_cw[] = {
    {
        .uname = "AD",
        .udesc = "AD clockwise Egress queue",
        .ucode = 0x100,
    },
    {
        .uname = "AK",
        .udesc = "AD counter-clockwise Egress queue",
        .ucode = 0x200,
    },
    {
        .uname = "BL",
        .udesc = "BL clockwise Egress queue",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t ivbep_unc_r3_vna_credits_acquired[] = {
    {
        .uname = "AD",
        .udesc = "For AD ring",
        .ucode = 0x100,
    },
    {
        .uname = "BL",
        .udesc = "For BL ring",
        .ucode = 0x400,
    },
};

static const intel_x86_entry_t intel_ivbep_unc_r3_pe[] = {
    {
        .name = "UNC_R3_CLOCKTICKS",
        .desc = "Number of uclks in domain",
        .code = 0x1,
        .cntmsk = 0x7,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_RING_AD_USED",
     .desc = "R3 AD Ring in Use",
     .code = 0x7,
     .cntmsk = 0x7,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_ring_ad_used),
     .umasks = ivbep_unc_r3_ring_ad_used},
    {
        .name = "UNC_R3_RING_AK_USED",
        .desc = "R3 AK Ring in Use",
        .code = 0x8,
        .cntmsk = 0x7,
        .ngrp = 1,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_ring_ad_used),
        .umasks = ivbep_unc_r3_ring_ad_used /* shared */
    },
    {
        .name = "UNC_R3_RING_BL_USED",
        .desc = "R3 BL Ring in Use",
        .code = 0x9,
        .cntmsk = 0x7,
        .ngrp = 1,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_ring_ad_used),
        .umasks = ivbep_unc_r3_ring_ad_used /* shared */
    },
    {.name = "UNC_R3_RING_IV_USED",
     .desc = "R3 IV Ring in Use",
     .code = 0xa,
     .cntmsk = 0x7,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_ring_iv_used),
     .umasks = ivbep_unc_r3_ring_iv_used},
    {
        .name = "UNC_R3_RXR_AD_BYPASSED",
        .desc = "Ingress Bypassed",
        .code = 0x12,
        .cntmsk = 0x3,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_RXR_CYCLES_NE",
     .desc = "Ingress Cycles Not Empty",
     .code = 0x10,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_rxr_cycles_ne),
     .umasks = ivbep_unc_r3_rxr_cycles_ne},
    {.name = "UNC_R3_RXR_INSERTS",
     .desc = "Ingress Allocations",
     .code = 0x11,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_rxr_inserts),
     .umasks = ivbep_unc_r3_rxr_inserts},
    {
        .name = "UNC_R3_RXR_OCCUPANCY",
        .desc = "Ingress Occupancy Accumulator",
        .code = 0x13,
        .cntmsk = 0x1,
        .ngrp = 1,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_rxr_inserts),
        .umasks = ivbep_unc_r3_rxr_inserts /* shared */
    },
    {
        .name = "UNC_R3_TXR_CYCLES_FULL",
        .desc = "Egress cycles full",
        .code = 0x25,
        .cntmsk = 0x3,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_VN0_CREDITS_REJECT",
     .desc = "VN0 Credit Acquisition Failed",
     .code = 0x37,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vn0_credits_used),
     .umasks = ivbep_unc_r3_vn0_credits_used},
    {.name = "UNC_R3_VN0_CREDITS_USED",
     .desc = "VN0 Credit Used",
     .code = 0x36,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vn0_credits_used),
     .umasks = ivbep_unc_r3_vn0_credits_used},
    {.name = "UNC_R3_VNA_CREDITS_ACQUIRED",
     .desc = "VNA credit Acquisitions",
     .code = 0x33,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vna_credits_acquired),
     .umasks = ivbep_unc_r3_vna_credits_acquired},
    {
        .name = "UNC_R3_VNA_CREDITS_REJECT",
        .desc = "VNA Credit Reject",
        .code = 0x34,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vn0_credits_used),
        .umasks = ivbep_unc_r3_vn0_credits_used /* shared */
    },
    {
        .name = "UNC_R3_VNA_CREDIT_CYCLES_OUT",
        .desc = "Cycles with no VNA credits available",
        .code = 0x31,
        .cntmsk = 0x3,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {
        .name = "UNC_R3_VNA_CREDIT_CYCLES_USED",
        .desc = "Cycles with 1 or more VNA credits in use",
        .code = 0x32,
        .cntmsk = 0x3,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_C_HI_AD_CREDITS_EMPTY",
     .desc = "Cbox AD credits empty",
     .code = 0x2c,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_c_hi_ad_credits_empty),
     .umasks = ivbep_unc_r3_c_hi_ad_credits_empty},
    {.name = "UNC_R3_C_LO_AD_CREDITS_EMPTY",
     .desc = "Cbox AD credits empty",
     .code = 0x2b,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_c_lo_ad_credits_empty),
     .umasks = ivbep_unc_r3_c_lo_ad_credits_empty},
    {.name = "UNC_R3_HA_R2_BL_CREDITS_EMPTY",
     .desc = "HA/R2 AD credits  empty",
     .code = 0x2f,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_ha_r2_bl_credits_empty),
     .umasks = ivbep_unc_r3_ha_r2_bl_credits_empty},
    {.name = "UNC_R3_QPI0_AD_CREDITS_EMPTY",
     .desc = "QPI0 AD credits empty",
     .code = 0x29,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_qpi0_ad_credits_empty),
     .umasks = ivbep_unc_r3_qpi0_ad_credits_empty},
    {.name = "UNC_R3_QPI0_BL_CREDITS_EMPTY",
     .desc = "QPI0 BL credits empty",
     .code = 0x2d,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_qpi0_ad_credits_empty), /* shared */
     .umasks = ivbep_unc_r3_qpi0_ad_credits_empty},
    {.name = "UNC_R3_QPI1_AD_CREDITS_EMPTY",
     .desc = "QPI1 AD credits empty",
     .code = 0x2a,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_qpi0_ad_credits_empty), /* shared */
     .umasks = ivbep_unc_r3_qpi0_ad_credits_empty},
    {.name = "UNC_R3_QPI1_BL_CREDITS_EMPTY",
     .desc = "QPI1 BL credits empty",
     .code = 0x2e,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_qpi0_ad_credits_empty), /* shared */
     .umasks = ivbep_unc_r3_qpi0_ad_credits_empty},
    {
        .name = "UNC_R3_TXR_CYCLES_NE",
        .desc = "Egress cycles not empty",
        .code = 0x23,
        .cntmsk = 0x3,
        .modmsk = IVBEP_UNC_R3QPI_ATTRS,
    },
    {.name = "UNC_R3_TXR_NACK_CCW",
     .desc = "Egress NACK counter-clockwise",
     .code = 0x28,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_txr_nack_ccw),
     .umasks = ivbep_unc_r3_txr_nack_ccw},
    {.name = "UNC_R3_TXR_NACK_CW",
     .desc = "Egress NACK counter-clockwise",
     .code = 0x26,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_txr_nack_cw),
     .umasks = ivbep_unc_r3_txr_nack_cw},
    {.name = "UNC_R3_VN1_CREDITS_REJECT",
     .desc = "VN1 Credit Acquisition Failed",
     .code = 0x39,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vn0_credits_used), /* shared */
     .umasks = ivbep_unc_r3_vn0_credits_used},
    {.name = "UNC_R3_VN1_CREDITS_USED",
     .desc = "VN0 Credit Used",
     .code = 0x38,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = IVBEP_UNC_R3QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_r3_vn0_credits_used), /* shared */
     .umasks = ivbep_unc_r3_vn0_credits_used},
};
