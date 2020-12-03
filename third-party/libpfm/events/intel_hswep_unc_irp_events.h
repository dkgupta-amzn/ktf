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
 * PMU: hswep_unc_irp (Intel Haswell-EP IRP uncore)
 */

static const intel_x86_umask_t hswep_unc_i_cache_ack_pending_occupancy[] = {
    {
        .uname = "ANY",
        .udesc = "Any source",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "SOURCE",
        .udesc = "Track all requests from any source port",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t hswep_unc_i_coherent_ops[] = {
    {
        .uname = "PCIRDCUR",
        .udesc = "PCI read current",
        .ucode = 0x100,
    },
    {
        .uname = "CRD",
        .udesc = "CRD",
        .ucode = 0x200,
    },
    {
        .uname = "DRD",
        .udesc = "DRD",
        .ucode = 0x400,
    },
    {
        .uname = "RFO",
        .udesc = "RFO",
        .ucode = 0x800,
    },
    {
        .uname = "PCITOM",
        .udesc = "DRITOM",
        .ucode = 0x1000,
    },
    {
        .uname = "PCIDCAHINT",
        .udesc = "PCIDCAHINT",
        .ucode = 0x2000,
    },
    {
        .uname = "WBMTOI",
        .udesc = "WBMTOI",
        .ucode = 0x4000,
    },
    {
        .uname = "CFLUSH",
        .udesc = "CFLUSH",
        .ucode = 0x8000,
    },
};

static const intel_x86_umask_t hswep_unc_i_misc0[] = {
    {
        .uname = "FAST_REQ",
        .udesc = "Fastpath requests",
        .ucode = 0x100,
    },
    {
        .uname = "FAST_REJ",
        .udesc = "Fastpath rejects",
        .ucode = 0x200,
    },
    {
        .uname = "2ND_RD_INSERT",
        .udesc = "Cache insert of read transaction as secondary",
        .ucode = 0x400,
    },
    {
        .uname = "2ND_WR_INSERT",
        .udesc = "Cache insert of write transaction as secondary",
        .ucode = 0x800,
    },
    {
        .uname = "2ND_ATOMIC_INSERT",
        .udesc = "Cache insert of atomic transaction as secondary",
        .ucode = 0x1000,
    },
    {
        .uname = "FAST_XFER",
        .udesc = "Fastpath trasnfers from primary to secondary",
        .ucode = 0x2000,
    },
    {
        .uname = "PF_ACK_HINT",
        .udesc = "Prefetch ack hints from primary to secondary",
        .ucode = 0x4000,
    },
    {
        .uname = "PF_TIMEOUT",
        .udesc = "Prefetch timeout",
        .ucode = 0x8000,
    },
};

static const intel_x86_umask_t hswep_unc_i_misc1[] = {
    {
        .uname = "SLOW_I",
        .udesc = "Slow transfer of I-state cacheline",
        .ucode = 0x100,
    },
    {
        .uname = "SLOW_S",
        .udesc = "Slow transfer of S-state cacheline",
        .ucode = 0x200,
    },
    {
        .uname = "SLOW_E",
        .udesc = "Slow transfer of e-state cacheline",
        .ucode = 0x400,
    },
    {
        .uname = "SLOW_M",
        .udesc = "Slow transfer of M-state cacheline",
        .ucode = 0x800,
    },
    {
        .uname = "LOST_FWD",
        .udesc = "LOST forwards",
        .ucode = 0x1000,
    },
    {
        .uname = "SEC_RCVD_INVLD",
        .udesc = "Received Invalid",
        .ucode = 0x2000,
    },
    {
        .uname = "SEC_RCVD_VLD",
        .udesc = "Received Valid",
        .ucode = 0x4000,
    },
    {
        .uname = "DATA_THROTTLE",
        .udesc = "Data throttled",
        .ucode = 0x8000,
    },
};

static const intel_x86_umask_t hswep_unc_i_snoop_resp[] = {
    {
        .uname = "MISS",
        .udesc = "Miss",
        .ucode = 0x100,
    },
    {
        .uname = "HIT_I",
        .udesc = "Hit in Invalid state",
        .ucode = 0x200,
    },
    {
        .uname = "HIT_ES",
        .udesc = "Hit in Exclusive or Shared state",
        .ucode = 0x400,
    },
    {
        .uname = "HIT_M",
        .udesc = "Hit in Modified state",
        .ucode = 0x800,
    },
    {
        .uname = "SNPCODE",
        .udesc = "Snoop Code",
        .ucode = 0x1000,
    },
    {
        .uname = "SNPDATA",
        .udesc = "Snoop Data",
        .ucode = 0x2000,
    },
    {
        .uname = "SNPINV",
        .udesc = "Snoop Invalid",
        .ucode = 0x4000,
    },
};

static const intel_x86_umask_t hswep_unc_i_transactions[] = {
    {
        .uname = "READS",
        .udesc = "Reads (not including prefetches)",
        .ucode = 0x100,
    },
    {
        .uname = "WRITES",
        .udesc = "Writes",
        .ucode = 0x200,
    },
    {
        .uname = "RD_PREF",
        .udesc = "Read prefetches",
        .ucode = 0x400,
    },
    {
        .uname = "WR_PREF",
        .udesc = "Write prefetches",
        .ucode = 0x800,
    },
    {
        .uname = "ATOMIC",
        .udesc = "Atomic transactions",
        .ucode = 0x1000,
    },
    {
        .uname = "OTHER",
        .udesc = "Other kinds of transactions",
        .ucode = 0x2000,
    },
    {
        .uname = "ORDERINGQ",
        .udesc = "Track request coming from port designated in IRP OrderingQ filter",
        .ucode = 0x4000,
    },
};

static const intel_x86_entry_t intel_hswep_unc_i_pe[] = {
    {
        .name = "UNC_I_CLOCKTICKS",
        .desc = "Number of uclks in domain",
        .code = 0x0,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_SNOOP_RESP",
        .desc = "Snoop responses",
        .code = 0x17,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_snoop_resp),
        .umasks = hswep_unc_i_snoop_resp,
    },
    {
        .name = "UNC_I_MISC0",
        .desc = "Miscellaneous events",
        .code = 0x14,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_misc0),
        .umasks = hswep_unc_i_misc0,
    },
    {
        .name = "UNC_I_COHERENT_OPS",
        .desc = "Coherent operations",
        .code = 0x13,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_coherent_ops),
        .umasks = hswep_unc_i_coherent_ops,
    },
    {
        .name = "UNC_I_CACHE_TOTAL_OCCUPANCY",
        .desc = "Total write cache occupancy",
        .code = 0x12,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_cache_ack_pending_occupancy),
        .umasks = hswep_unc_i_cache_ack_pending_occupancy /* shared */
    },
    {
        .name = "UNC_I_RXR_AK_INSERTS",
        .desc = "Egress cycles full",
        .code = 0xa,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x4,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_INSERTS",
        .desc = "BL Ingress occupancy DRS",
        .code = 0x1,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_OCCUPANCY",
        .desc = "TBD",
        .code = 0x7,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x5,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_INSERTS",
        .desc = "BL Ingress occupancy NCB",
        .code = 0x2,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_OCCUPANCY",
        .desc = "TBD",
        .code = 0x8,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x6,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_INSERTS",
        .desc = "BL Ingress Occupancy NCS",
        .code = 0x3,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_OCCUPANCY",
        .desc = "TBD",
        .code = 0x9,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TRANSACTIONS",
        .desc = "Inbound transactions",
        .code = 0x16,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_transactions),
        .umasks = hswep_unc_i_transactions,
    },
    {
        .name = "UNC_I_MISC1",
        .desc = "Misc events",
        .code = 0x15,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_i_misc1),
        .umasks = hswep_unc_i_misc1,
    },
    {
        .name = "UNC_I_TXR_AD_STALL_CREDIT_CYCLES",
        .desc = "No AD Egress credit stalls",
        .code = 0x18,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_BL_STALL_CREDIT_CYCLES",
        .desc = "No BL Egress credit stalls",
        .code = 0x19,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_DATA_INSERTS_NCB",
        .desc = "Outbound read requests",
        .code = 0xe,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_DATA_INSERTS_NCS",
        .desc = "Outbound read requests",
        .code = 0xf,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_REQUEST_OCCUPANCY",
        .desc = "Outbound request queue occupancy",
        .code = 0xd,
        .cntmsk = 0x3,
        .modmsk = HSWEP_UNC_IRP_ATTRS,
    },
};
