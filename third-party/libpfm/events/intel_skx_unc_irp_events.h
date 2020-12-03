/*
 * Copyright (c) 2017 Google LLC
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
 * PMU: skx_unc_irp
 */

static intel_x86_umask_t skx_unc_i_cache_total_occupancy[] = {
    {
        .uname = "ANY",
        .ucode = 0x100,
        .udesc = "Total Write Cache Occupancy -- Any Source",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IV_Q",
        .ucode = 0x200,
        .udesc = "Total Write Cache Occupancy -- Snoops",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MEM",
        .ucode = 0x400,
        .udesc = "Total Write Cache Occupancy -- Mem",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t skx_unc_i_coherent_ops[] = {
    {
        .uname = "CLFLUSH",
        .ucode = 0x8000,
        .udesc = "Coherent Ops -- CLFlush",
    },
    {
        .uname = "CRD",
        .ucode = 0x200,
        .udesc = "Coherent Ops -- CRd",
    },
    {
        .uname = "DRD",
        .ucode = 0x400,
        .udesc = "Coherent Ops -- DRd",
    },
    {
        .uname = "PCIDCAHINT",
        .ucode = 0x2000,
        .udesc = "Coherent Ops -- PCIDCAHin5t",
    },
    {
        .uname = "PCIRDCUR",
        .ucode = 0x100,
        .udesc = "Coherent Ops -- PCIRdCur",
    },
    {
        .uname = "PCITOM",
        .ucode = 0x1000,
        .udesc = "Coherent Ops -- PCIItoM",
    },
    {
        .uname = "RFO",
        .ucode = 0x800,
        .udesc = "Coherent Ops -- RFO",
    },
    {
        .uname = "WBMTOI",
        .ucode = 0x4000,
        .udesc = "Coherent Ops -- WbMtoI",
    },
};

static intel_x86_umask_t skx_unc_i_irp_all[] = {
    {
        .uname = "INBOUND_INSERTS",
        .ucode = 0x100,
        .udesc = " -- All Inserts Inbound (p2p + faf + cset)",
    },
    {
        .uname = "OUTBOUND_INSERTS",
        .ucode = 0x200,
        .udesc = " -- All Inserts Outbound (BL, AK, Snoops)",
    },
};

static intel_x86_umask_t skx_unc_i_misc0[] = {
    {
        .uname = "2ND_ATOMIC_INSERT",
        .ucode = 0x1000,
        .udesc =
            "Misc Events - Set 0 -- Cache Inserts of Atomic Transactions as Secondary",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "2ND_RD_INSERT",
        .ucode = 0x400,
        .udesc = "Misc Events - Set 0 -- Cache Inserts of Read Transactions as Secondary",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "2ND_WR_INSERT",
        .ucode = 0x800,
        .udesc =
            "Misc Events - Set 0 -- Cache Inserts of Write Transactions as Secondary",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FAST_REJ",
        .ucode = 0x200,
        .udesc = "Misc Events - Set 0 -- Fastpath Rejects",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FAST_REQ",
        .ucode = 0x100,
        .udesc = "Misc Events - Set 0 -- Fastpath Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FAST_XFER",
        .ucode = 0x2000,
        .udesc = "Misc Events - Set 0 -- Fastpath Transfers From Primary to Secondary",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_ACK_HINT",
        .ucode = 0x4000,
        .udesc = "Misc Events - Set 0 -- Prefetch Ack Hints From Primary to Secondary",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNKNOWN",
        .ucode = 0x8000,
        .udesc = "Misc Events - Set 0 -- ",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t skx_unc_i_misc1[] = {
    {
        .uname = "LOST_FWD",
        .ucode = 0x1000,
        .udesc = "Misc Events - Set 1 -- Lost Forward",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SEC_RCVD_INVLD",
        .ucode = 0x2000,
        .udesc = "Misc Events - Set 1 -- Received Invalid",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SEC_RCVD_VLD",
        .ucode = 0x4000,
        .udesc = "Misc Events - Set 1 -- Received Valid",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_E",
        .ucode = 0x400,
        .udesc = "Misc Events - Set 1 -- Slow Transfer of E Line",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_I",
        .ucode = 0x100,
        .udesc = "Misc Events - Set 1 -- Slow Transfer of I Line",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_M",
        .ucode = 0x800,
        .udesc = "Misc Events - Set 1 -- Slow Transfer of M Line",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_S",
        .ucode = 0x200,
        .udesc = "Misc Events - Set 1 -- Slow Transfer of S Line",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t skx_unc_i_p2p_transactions[] = {
    {
        .uname = "CMPL",
        .ucode = 0x800,
        .udesc = "P2P Transactions -- P2P completions",
    },
    {
        .uname = "LOC",
        .ucode = 0x4000,
        .udesc = "P2P Transactions -- match if local only",
    },
    {
        .uname = "LOC_AND_TGT_MATCH",
        .ucode = 0x8000,
        .udesc = "P2P Transactions -- match if local and target matches",
    },
    {
        .uname = "MSG",
        .ucode = 0x400,
        .udesc = "P2P Transactions -- P2P Message",
    },
    {
        .uname = "RD",
        .ucode = 0x100,
        .udesc = "P2P Transactions -- P2P reads",
    },
    {
        .uname = "REM",
        .ucode = 0x1000,
        .udesc = "P2P Transactions -- Match if remote only",
    },
    {
        .uname = "REM_AND_TGT_MATCH",
        .ucode = 0x2000,
        .udesc = "P2P Transactions -- match if remote and target matches",
    },
    {
        .uname = "WR",
        .ucode = 0x200,
        .udesc = "P2P Transactions -- P2P Writes",
    },
};

static intel_x86_umask_t skx_unc_i_snoop_resp[] = {
    {
        .uname = "HIT_ES",
        .ucode = 0x400,
        .udesc = "Snoop Responses -- Hit E or S",
    },
    {
        .uname = "HIT_I",
        .ucode = 0x200,
        .udesc = "Snoop Responses -- Hit I",
    },
    {
        .uname = "HIT_M",
        .ucode = 0x800,
        .udesc = "Snoop Responses -- Hit M",
    },
    {
        .uname = "MISS",
        .ucode = 0x100,
        .udesc = "Snoop Responses -- Miss",
    },
    {
        .uname = "SNPCODE",
        .ucode = 0x1000,
        .udesc = "Snoop Responses -- SnpCode",
    },
    {
        .uname = "SNPDATA",
        .ucode = 0x2000,
        .udesc = "Snoop Responses -- SnpData",
    },
    {
        .uname = "SNPINV",
        .ucode = 0x4000,
        .udesc = "Snoop Responses -- SnpInv",
    },
};

static intel_x86_umask_t skx_unc_i_transactions[] = {
    {
        .uname = "ATOMIC",
        .ucode = 0x1000,
        .udesc = "Inbound Transaction Count -- Atomic",
    },
    {
        .uname = "OTHER",
        .ucode = 0x2000,
        .udesc = "Inbound Transaction Count -- Other",
    },
    {
        .uname = "RD_PREF",
        .ucode = 0x400,
        .udesc = "Inbound Transaction Count -- Read Prefetches",
    },
    {
        .uname = "READS",
        .ucode = 0x100,
        .udesc = "Inbound Transaction Count -- Reads",
    },
    {
        .uname = "WRITES",
        .ucode = 0x200,
        .udesc = "Inbound Transaction Count -- Writes",
    },
    {
        .uname = "WR_PREF",
        .ucode = 0x800,
        .udesc = "Inbound Transaction Count -- Write Prefetches",
    },
};

static intel_x86_entry_t intel_skx_unc_i_pe[] = {
    {
        .name = "UNC_I_CACHE_TOTAL_OCCUPANCY",
        .code = 0xf,
        .desc = "Accumulates the number of reads and writes that are outstanding in the "
                "uncore in each cycle.  This is effectively the sum of the "
                "READ_OCCUPANCY and WRITE_OCCUPANCY events.",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_cache_total_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_cache_total_occupancy),
    },
    {
        .name = "UNC_I_CLOCKTICKS",
        .code = 0x1,
        .desc = "IRP Clocks",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_COHERENT_OPS",
        .code = 0x10,
        .desc = "Counts the number of coherency related operations servied by the IRP",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_coherent_ops,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_coherent_ops),
    },
    {
        .name = "UNC_I_FAF_FULL",
        .code = 0x17,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_FAF_INSERTS",
        .code = 0x18,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_FAF_OCCUPANCY",
        .code = 0x19,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_FAF_TRANSACTIONS",
        .code = 0x16,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_IRP_ALL",
        .code = 0x1e,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_i_irp_all,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_irp_all),
    },
    {
        .name = "UNC_I_MISC0",
        .code = 0x1c,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_misc0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_misc0),
    },
    {
        .name = "UNC_I_MISC1",
        .code = 0x1d,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_misc1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_misc1),
    },
    {
        .name = "UNC_I_P2P_INSERTS",
        .code = 0x14,
        .desc = "P2P requests from the ITC",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_P2P_OCCUPANCY",
        .code = 0x15,
        .desc = "P2P B & S Queue Occupancy",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_I_P2P_TRANSACTIONS",
        .code = 0x13,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_i_p2p_transactions,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_p2p_transactions),
    },
    {
        .name = "UNC_I_SNOOP_RESP",
        .code = 0x12,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_snoop_resp,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_snoop_resp),
    },
    {
        .name = "UNC_I_TRANSACTIONS",
        .code = 0x11,
        .desc = "Counts the number of Inbound transactions from the IRP to the Uncore.  "
                "This can be filtered based on request type in addition to the source "
                "queue.  Note the special filtering equation.  We do OR-reduction on the "
                "request type.  If the SOURCE bit is set, then we also do AND "
                "qualification based on the source portItID.",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = skx_unc_i_transactions,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_i_transactions),
    },
    {
        .name = "UNC_I_TXC_AK_INSERTS",
        .code = 0xb,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_DRS_CYCLES_FULL",
        .code = 0x5,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_DRS_INSERTS",
        .code = 0x2,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_DRS_OCCUPANCY",
        .code = 0x8,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCB_CYCLES_FULL",
        .code = 0x6,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCB_INSERTS",
        .code = 0x3,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCB_OCCUPANCY",
        .code = 0x9,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCS_CYCLES_FULL",
        .code = 0x7,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCS_INSERTS",
        .code = 0x4,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXC_BL_NCS_OCCUPANCY",
        .code = 0xa,
        .desc = "TBD",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXR2_AD_STALL_CREDIT_CYCLES",
        .code = 0x1a,
        .desc = "Counts the number times when it is not possible to issue a request to "
                "the R2PCIe because there are no AD Egress Credits available.",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXR2_BL_STALL_CREDIT_CYCLES",
        .code = 0x1b,
        .desc = "Counts the number times when it is not possible to issue data to the "
                "R2PCIe because there are no BL Egress Credits available.",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXS_DATA_INSERTS_NCB",
        .code = 0xd,
        .desc =
            "Counts the number of requests issued to the switch (towards the devices).",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXS_DATA_INSERTS_NCS",
        .code = 0xe,
        .desc =
            "Counts the number of requests issued to the switch (towards the devices).",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
    {
        .name = "UNC_I_TXS_REQUEST_OCCUPANCY",
        .code = 0xc,
        .desc = "Accumultes the number of outstanding outbound requests from the IRP to "
                "the switch (towards the devices).  This can be used in conjuection with "
                "the allocations event in order to calculate average latency of outbound "
                "requests.",
        .modmsk = SKX_UNC_IRP_ATTRS,
        .cntmsk = 0x3,
    },
};
