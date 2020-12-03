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
 * PMU: hswep_unc_qpi (Intel Haswell-EP QPI uncore)
 */

static const intel_x86_umask_t hswep_unc_q_direct2core[] = {
    {
        .uname = "FAILURE_CREDITS",
        .udesc = "Number of spawn failures due to lack of Egress credits",
        .ucode = 0x200,
    },
    {
        .uname = "FAILURE_CREDITS_RBT",
        .udesc = "Number of spawn failures due to lack of Egress credit and route-back "
                 "table (RBT) bit was not set",
        .ucode = 0x800,
    },
    {
        .uname = "FAILURE_RBT_HIT",
        .udesc = "Number of spawn failures because route-back table (RBT) specified that "
                 "the transaction should not trigger a direct2core transaction",
        .ucode = 0x400,
    },
    {
        .uname = "SUCCESS_RBT_HIT",
        .udesc = "Number of spawn successes",
        .ucode = 0x100,
    },
    {
        .uname = "FAILURE_MISS",
        .udesc = "Number of spawn failures due to RBT tag not matching although the "
                 "valid bit was set and there was enough Egress credits",
        .ucode = 0x1000,
    },
    {
        .uname = "FAILURE_CREDITS_MISS",
        .udesc = "Number of spawn failures due to RBT tag not matching and they were not "
                 "enough Egress credits. The valid bit was set",
        .ucode = 0x2000,
    },
    {
        .uname = "FAILURE_RBT_MISS",
        .udesc = "Number of spawn failures due to RBT tag not matching, the valid bit "
                 "was not set but there were enough Egress credits",
        .ucode = 0x4000,
    },
    {
        .uname = "FAILURE_CREDITS_RBT_MISS",
        .udesc = "Number of spawn failures due to RBT tag not matching, the valid bit "
                 "was not set and there were not enough Egress credits",
        .ucode = 0x8000,
    },
};

static const intel_x86_umask_t hswep_unc_q_rxl_credits_consumed_vn0[] = {
    {
        .uname = "DRS",
        .udesc = "Number of times VN0 consumed for DRS message class",
        .ucode = 0x100,
    },
    {
        .uname = "HOM",
        .udesc = "Number of times VN0 consumed for HOM message class",
        .ucode = 0x800,
    },
    {
        .uname = "NCB",
        .udesc = "Number of times VN0 consumed for NCB message class",
        .ucode = 0x200,
    },
    {
        .uname = "NCS",
        .udesc = "Number of times VN0 consumed for NCS message class",
        .ucode = 0x400,
    },
    {
        .uname = "NDR",
        .udesc = "Number of times VN0 consumed for NDR message class",
        .ucode = 0x2000,
    },
    {
        .uname = "SNP",
        .udesc = "Number of times VN0 consumed for SNP message class",
        .ucode = 0x1000,
    },
};

static const intel_x86_umask_t hswep_unc_q_rxl_credits_consumed_vn1[] = {
    {
        .uname = "DRS",
        .udesc = "Number of times VN1 consumed for DRS message class",
        .ucode = 0x100,
    },
    {
        .uname = "HOM",
        .udesc = "Number of times VN1 consumed for HOM message class",
        .ucode = 0x800,
    },
    {
        .uname = "NCB",
        .udesc = "Number of times VN1 consumed for NCB message class",
        .ucode = 0x200,
    },
    {
        .uname = "NCS",
        .udesc = "Number of times VN1 consumed for NCS message class",
        .ucode = 0x400,
    },
    {
        .uname = "NDR",
        .udesc = "Number of times VN1 consumed for NDR message class",
        .ucode = 0x2000,
    },
    {
        .uname = "SNP",
        .udesc = "Number of times VN1 consumed for SNP message class",
        .ucode = 0x1000,
    },
};

static const intel_x86_umask_t hswep_unc_q_txl_flits_g0[] = {
    {
        .uname = "DATA",
        .udesc = "Number of data flits over QPI",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NON_DATA",
        .udesc = "Number of non-NULL non-data flits over QPI",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t hswep_unc_q_rxl_flits_g1[] = {
    {
        .uname = "DRS",
        .udesc = "Number of flits over QPI on the Data Response (DRS) channel",
        .ucode = 0x1800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_DATA",
        .udesc = "Number of data flits over QPI on the Data Response (DRS) channel",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_NONDATA",
        .udesc = "Number of protocol flits over QPI on the Data Response (DRS) channel",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .udesc = "Number of flits over QPI on the home channel",
        .ucode = 0x600,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_NONREQ",
        .udesc = "Number of non-request flits over QPI on the home channel",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_REQ",
        .udesc = "Number of data requests over QPI on the home channel",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SNP",
        .udesc = "Number of snoop requests flits over QPI",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t hswep_unc_q_rxl_flits_g2[] = {
    {
        .uname = "NCB",
        .udesc = "Number of non-coherent bypass flits",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_DATA",
        .udesc = "Number of non-coherent data flits",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_NONDATA",
        .udesc = "Number of bypass non-data flits",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .udesc = "Number of non-coherent standard (NCS) flits",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AD",
        .udesc = "Number of flits received over Non-data response (NDR) channel",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AK",
        .udesc = "Number of flits received on the Non-data response (NDR) channel)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t hswep_unc_q_txr_ad_hom_credit_acquired[] = {
    {
        .uname = "VN0",
        .udesc = "for VN0",
        .ucode = 0x100,
    },
    {
        .uname = "VN1",
        .udesc = "for VN1",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t hswep_unc_q_txr_bl_drs_credit_acquired[] = {
    {
        .uname = "VN0",
        .udesc = "for VN0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "VN1",
        .udesc = "for VN1",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "VN_SHR",
        .udesc = "for shared VN",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_entry_t intel_hswep_unc_q_pe[] = {
    {
        .name = "UNC_Q_CLOCKTICKS",
        .desc = "Number of qfclks",
        .code = 0x14,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_CTO_COUNT",
        .desc = "Count of CTO Events",
        .code = 0x38 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {.name = "UNC_Q_DIRECT2CORE",
     .desc = "Direct 2 Core Spawning",
     .code = 0x13,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_direct2core),
     .umasks = hswep_unc_q_direct2core},
    {
        .name = "UNC_Q_L1_POWER_CYCLES",
        .desc = "Cycles in L1",
        .code = 0x12,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL0P_POWER_CYCLES",
        .desc = "Cycles in L0p",
        .code = 0x10,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL0_POWER_CYCLES",
        .desc = "Cycles in L0",
        .code = 0xf,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL_BYPASSED",
        .desc = "Rx Flit Buffer Bypassed",
        .code = 0x9,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {.name = "UNC_Q_RXL_CREDITS_CONSUMED_VN0",
     .desc = "VN0 Credit Consumed",
     .code = 0x1e | (1ULL << 21), /* sel_ext */
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_credits_consumed_vn0),
     .umasks = hswep_unc_q_rxl_credits_consumed_vn0},
    {.name = "UNC_Q_RXL_CREDITS_CONSUMED_VN1",
     .desc = "VN1 Credit Consumed",
     .code = 0x39 | (1ULL << 21), /* sel_ext */
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_credits_consumed_vn1),
     .umasks = hswep_unc_q_rxl_credits_consumed_vn1},
    {
        .name = "UNC_Q_RXL_CREDITS_CONSUMED_VNA",
        .desc = "VNA Credit Consumed",
        .code = 0x1d | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL_CYCLES_NE",
        .desc = "RxQ Cycles Not Empty",
        .code = 0xa,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {.name = "UNC_Q_RXL_FLITS_G1",
     .desc = "Flits Received - Group 1",
     .code = 0x2 | (1ULL << 21), /* sel_ext */
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_flits_g1),
     .umasks = hswep_unc_q_rxl_flits_g1},

    {.name = "UNC_Q_RXL_FLITS_G2",
     .desc = "Flits Received - Group 2",
     .code = 0x3 | (1ULL << 21), /* sel_ext */
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_flits_g2),
     .umasks = hswep_unc_q_rxl_flits_g2},
    {
        .name = "UNC_Q_RXL_INSERTS",
        .desc = "Rx Flit Buffer Allocations",
        .code = 0x8,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_DRS",
        .desc = "Rx Flit Buffer Allocations - DRS",
        .code = 0x9 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_HOM",
        .desc = "Rx Flit Buffer Allocations - HOM",
        .code = 0xc | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NCB",
        .desc = "Rx Flit Buffer Allocations - NCB",
        .code = 0xa | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NCS",
        .desc = "Rx Flit Buffer Allocations - NCS",
        .code = 0xb | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NDR",
        .desc = "Rx Flit Buffer Allocations - NDR",
        .code = 0xe | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_SNP",
        .desc = "Rx Flit Buffer Allocations - SNP",
        .code = 0xd | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY",
        .desc = "RxQ Occupancy - All Packets",
        .code = 0xb,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_DRS",
        .desc = "RxQ Occupancy - DRS",
        .code = 0x15 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_HOM",
        .desc = "RxQ Occupancy - HOM",
        .code = 0x18 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NCB",
        .desc = "RxQ Occupancy - NCB",
        .code = 0x16 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NCS",
        .desc = "RxQ Occupancy - NCS",
        .code = 0x17 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NDR",
        .desc = "RxQ Occupancy - NDR",
        .code = 0x1a | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_SNP",
        .desc = "RxQ Occupancy - SNP",
        .code = 0x19 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXL0P_POWER_CYCLES",
        .desc = "Cycles in L0p",
        .code = 0xd,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_TXL0_POWER_CYCLES",
        .desc = "Cycles in L0",
        .code = 0xc,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_TXL_BYPASSED",
        .desc = "Tx Flit Buffer Bypassed",
        .code = 0x5,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_TXL_CYCLES_NE",
        .desc = "Tx Flit Buffer Cycles not Empty",
        .code = 0x6,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {.name = "UNC_Q_TXL_FLITS_G0",
     .desc = "Flits Transferred - Group 0",
     .code = 0x0,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_QPI_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txl_flits_g0),
     .umasks = hswep_unc_q_txl_flits_g0},
    {
        .name = "UNC_Q_TXL_FLITS_G1",
        .desc = "Flits Transferred - Group 1",
        .code = 0x0 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_flits_g1),
        .umasks = hswep_unc_q_rxl_flits_g1 /* shared with rxl_flits_g1 */
    },
    {
        .name = "UNC_Q_TXL_FLITS_G2",
        .desc = "Flits Transferred - Group 2",
        .code = 0x1 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_rxl_flits_g2),
        .umasks = hswep_unc_q_rxl_flits_g2 /* shared with rxl_flits_g2 */
    },
    {
        .name = "UNC_Q_TXL_INSERTS",
        .desc = "Tx Flit Buffer Allocations",
        .code = 0x4,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_TXL_OCCUPANCY",
        .desc = "Tx Flit Buffer Occupancy",
        .code = 0x7,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_VNA_CREDIT_RETURNS",
        .desc = "VNA Credits Returned",
        .code = 0x1c | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_VNA_CREDIT_RETURN_OCCUPANCY",
        .desc = "VNA Credits Pending Return - Occupancy",
        .code = 0x1b | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
    },
    {
        .name = "UNC_Q_TXR_AD_HOM_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy AD HOM",
        .code = 0x26 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AD_HOM_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy AD HOM",
        .code = 0x22 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AD_NDR_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy AD NDR",
        .code = 0x28 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AD_NDR_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy AD NDR",
        .code = 0x24 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AD_SNP_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy AD SNP",
        .code = 0x27 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AD_SNP_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy AD SNP",
        .code = 0x23 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AK_NDR_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy AK NDR",
        .code = 0x29 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_AK_NDR_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy AD NDR",
        .code = 0x25 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy BL DRS",
        .code = 0x2a | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_bl_drs_credit_acquired),
        .umasks = hswep_unc_q_txr_bl_drs_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy BL DRS",
        .code = 0x1f | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_bl_drs_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_bl_drs_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_NCB_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy BL NCB",
        .code = 0x2b | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_NCB_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy BL NCB",
        .code = 0x20 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_NCS_CREDIT_ACQUIRED",
        .desc = "R3QPI Egress credit occupancy BL NCS",
        .code = 0x2c | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired),
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
    {
        .name = "UNC_Q_TXR_BL_NCS_CREDIT_OCCUPANCY",
        .desc = "R3QPI Egress credit occupancy BL NCS",
        .code = 0x21 | (1ULL << 21), /* sel_ext */
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_QPI_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_q_txr_ad_hom_credit_acquired), /* shared */
        .umasks = hswep_unc_q_txr_ad_hom_credit_acquired,
    },
};
