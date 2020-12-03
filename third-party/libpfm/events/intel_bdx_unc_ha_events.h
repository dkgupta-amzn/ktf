/*
 * Copyright (c) 2017 Google Inc. All rights reserved
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
 * PMU: bdx_unc_ha
 */

static intel_x86_umask_t bdx_unc_h_bypass_imc[] = {
    {
        .uname = "NOT_TAKEN",
        .ucode = 0x200,
        .udesc = "HA to iMC Bypass -- Not Taken",
    },
    {
        .uname = "TAKEN",
        .ucode = 0x100,
        .udesc = "HA to iMC Bypass -- Taken",
    },
};

static intel_x86_umask_t bdx_unc_h_directory_lookup[] = {
    {
        .uname = "NO_SNP",
        .ucode = 0x200,
        .udesc = "Directory Lookups -- Snoop Not Needed",
    },
    {
        .uname = "SNP",
        .ucode = 0x100,
        .udesc = "Directory Lookups -- Snoop Needed",
    },
};

static intel_x86_umask_t bdx_unc_h_directory_update[] = {
    {
        .uname = "ANY",
        .ucode = 0x300,
        .udesc = "Directory Updates -- Any Directory Update",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "CLEAR",
        .ucode = 0x200,
        .udesc = "Directory Updates -- Directory Clear",
    },
    {
        .uname = "SET",
        .ucode = 0x100,
        .udesc = "Directory Updates -- Directory Set",
    },
};

static intel_x86_umask_t bdx_unc_h_hitme_hit[] = {
    {
        .uname = "ACKCNFLTWBI",
        .ucode = 0x400,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is AckCnfltWbI",
    },
    {
        .uname = "ALL",
        .ucode = 0xff00,
        .udesc = "Counts Number of Hits in HitMe Cache -- All Requests",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALLOCS",
        .ucode = 0x7000,
        .udesc = "Counts Number of Hits in HitMe Cache -- Allocations",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "EVICTS",
        .ucode = 0x4200,
        .udesc = "Counts Number of Hits in HitMe Cache -- Allocations",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .ucode = 0xf00,
        .udesc = "Counts Number of Hits in HitMe Cache -- HOM Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INVALS",
        .ucode = 0x2600,
        .udesc = "Counts Number of Hits in HitMe Cache -- Invalidations",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "READ_OR_INVITOE",
        .ucode = 0x100,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is RdCode, RdData, "
                 "RdDataMigratory, RdInvOwn, RdCur or InvItoE",
    },
    {
        .uname = "RSP",
        .ucode = 0x8000,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is RspI, RspIWb, RspS, "
                 "RspSWb, RspCnflt or RspCnfltWbI",
    },
    {
        .uname = "RSPFWDI_LOCAL",
        .ucode = 0x2000,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is RspIFwd or RspIFwdWb for "
                 "a local request",
    },
    {
        .uname = "RSPFWDI_REMOTE",
        .ucode = 0x1000,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is RspIFwd or RspIFwdWb for "
                 "a remote request",
    },
    {
        .uname = "RSPFWDS",
        .ucode = 0x4000,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is RsSFwd or RspSFwdWb",
    },
    {
        .uname = "WBMTOE_OR_S",
        .ucode = 0x800,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is WbMtoE or WbMtoS",
    },
    {
        .uname = "WBMTOI",
        .ucode = 0x200,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is WbMtoI",
    },
};

static intel_x86_umask_t bdx_unc_h_hitme_hit_pv_bits_set[] = {
    {
        .uname = "ACKCNFLTWBI",
        .ucode = 0x400,
        .udesc =
            "Accumulates Number of PV bits set on HitMe Cache Hits -- op is AckCnfltWbI",
    },
    {
        .uname = "ALL",
        .ucode = 0xff00,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- All Requests",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "HOM",
        .ucode = 0xf00,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- HOM Requests",
    },
    {
        .uname = "READ_OR_INVITOE",
        .ucode = 0x100,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is RdCode, "
                 "RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
    },
    {
        .uname = "RSP",
        .ucode = 0x8000,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is RspI, "
                 "RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
    },
    {
        .uname = "RSPFWDI_LOCAL",
        .ucode = 0x2000,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is RspIFwd "
                 "or RspIFwdWb for a local request",
    },
    {
        .uname = "RSPFWDI_REMOTE",
        .ucode = 0x1000,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is RspIFwd "
                 "or RspIFwdWb for a remote request",
    },
    {
        .uname = "RSPFWDS",
        .ucode = 0x4000,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is RsSFwd "
                 "or RspSFwdWb",
    },
    {
        .uname = "WBMTOE_OR_S",
        .ucode = 0x800,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is WbMtoE "
                 "or WbMtoS",
    },
    {
        .uname = "WBMTOI",
        .ucode = 0x200,
        .udesc = "Accumulates Number of PV bits set on HitMe Cache Hits -- op is WbMtoI",
    },
};

static intel_x86_umask_t bdx_unc_h_hitme_lookup[] = {
    {
        .uname = "ACKCNFLTWBI",
        .ucode = 0x400,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is AckCnfltWbI",
    },
    {
        .uname = "ALL",
        .ucode = 0xff00,
        .udesc = "Counts Number of times HitMe Cache is accessed -- All Requests",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALLOCS",
        .ucode = 0x7000,
        .udesc = "Counts Number of times HitMe Cache is accessed -- Allocations",
    },
    {
        .uname = "HOM",
        .ucode = 0xf00,
        .udesc = "Counts Number of times HitMe Cache is accessed -- HOM Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INVALS",
        .ucode = 0x2600,
        .udesc = "Counts Number of times HitMe Cache is accessed -- Invalidations",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "READ_OR_INVITOE",
        .ucode = 0x100,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is RdCode, "
                 "RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
    },
    {
        .uname = "RSP",
        .ucode = 0x8000,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is RspI, RspIWb, "
                 "RspS, RspSWb, RspCnflt or RspCnfltWbI",
    },
    {
        .uname = "RSPFWDI_LOCAL",
        .ucode = 0x2000,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is RspIFwd or "
                 "RspIFwdWb for a local request",
    },
    {
        .uname = "RSPFWDI_REMOTE",
        .ucode = 0x1000,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is RspIFwd or "
                 "RspIFwdWb for a remote request",
    },
    {
        .uname = "RSPFWDS",
        .ucode = 0x4000,
        .udesc =
            "Counts Number of times HitMe Cache is accessed -- op is RsSFwd or RspSFwdWb",
    },
    {
        .uname = "WBMTOE_OR_S",
        .ucode = 0x800,
        .udesc =
            "Counts Number of times HitMe Cache is accessed -- op is WbMtoE or WbMtoS",
    },
    {
        .uname = "WBMTOI",
        .ucode = 0x200,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is WbMtoI",
    },
};

static intel_x86_umask_t bdx_unc_h_igr_no_credit_cycles[] = {
    {
        .uname = "AD_QPI0",
        .ucode = 0x100,
        .udesc = "Cycles without QPI Ingress Credits -- AD to QPI Link 0",
    },
    {
        .uname = "AD_QPI1",
        .ucode = 0x200,
        .udesc = "Cycles without QPI Ingress Credits -- AD to QPI Link 1",
    },
    {
        .uname = "AD_QPI2",
        .ucode = 0x1000,
        .udesc = "Cycles without QPI Ingress Credits -- BL to QPI Link 0",
    },
    {
        .uname = "BL_QPI0",
        .ucode = 0x400,
        .udesc = "Cycles without QPI Ingress Credits -- BL to QPI Link 0",
    },
    {
        .uname = "BL_QPI1",
        .ucode = 0x800,
        .udesc = "Cycles without QPI Ingress Credits -- BL to QPI Link 1",
    },
    {
        .uname = "BL_QPI2",
        .ucode = 0x2000,
        .udesc = "Cycles without QPI Ingress Credits -- BL to QPI Link 1",
    },
};

static intel_x86_umask_t bdx_unc_h_imc_reads[] = {
    {
        .uname = "NORMAL",
        .ucode = 0x100,
        .udesc = "HA to iMC Normal Priority Reads Issued -- Normal Priority",
        .uflags = INTEL_X86_DFL,
    },
};

static intel_x86_umask_t bdx_unc_h_imc_writes[] = {
    {
        .uname = "ALL",
        .ucode = 0xf00,
        .udesc = "HA to iMC Full Line Writes Issued -- All Writes",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "FULL",
        .ucode = 0x100,
        .udesc = "HA to iMC Full Line Writes Issued -- Full Line Non-ISOCH",
    },
    {
        .uname = "FULL_ISOCH",
        .ucode = 0x400,
        .udesc = "HA to iMC Full Line Writes Issued -- ISOCH Full Line",
    },
    {
        .uname = "PARTIAL",
        .ucode = 0x200,
        .udesc = "HA to iMC Full Line Writes Issued -- Partial Non-ISOCH",
    },
    {
        .uname = "PARTIAL_ISOCH",
        .ucode = 0x800,
        .udesc = "HA to iMC Full Line Writes Issued -- ISOCH Partial",
    },
};

static intel_x86_umask_t bdx_unc_h_osb[] = {
    {
        .uname = "CANCELLED",
        .ucode = 0x1000,
        .udesc = "OSB Snoop Broadcast -- Cancelled",
    },
    {
        .uname = "INVITOE_LOCAL",
        .ucode = 0x400,
        .udesc = "OSB Snoop Broadcast -- Local InvItoE",
    },
    {
        .uname = "READS_LOCAL",
        .ucode = 0x200,
        .udesc = "OSB Snoop Broadcast -- Local Reads",
    },
    {
        .uname = "READS_LOCAL_USEFUL",
        .ucode = 0x2000,
        .udesc = "OSB Snoop Broadcast -- Reads Local -  Useful",
    },
    {
        .uname = "REMOTE",
        .ucode = 0x800,
        .udesc = "OSB Snoop Broadcast -- Remote",
    },
    {
        .uname = "REMOTE_USEFUL",
        .ucode = 0x4000,
        .udesc = "OSB Snoop Broadcast -- Remote - Useful",
    },
};

static intel_x86_umask_t bdx_unc_h_osb_edr[] = {
    {
        .uname = "ALL",
        .ucode = 0x100,
        .udesc = "OSB Early Data Return -- All",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "READS_LOCAL_I",
        .ucode = 0x200,
        .udesc = "OSB Early Data Return -- Reads to Local  I",
    },
    {
        .uname = "READS_LOCAL_S",
        .ucode = 0x800,
        .udesc = "OSB Early Data Return -- Reads to Local S",
    },
    {
        .uname = "READS_REMOTE_I",
        .ucode = 0x400,
        .udesc = "OSB Early Data Return -- Reads to Remote I",
    },
    {
        .uname = "READS_REMOTE_S",
        .ucode = 0x1000,
        .udesc = "OSB Early Data Return -- Reads to Remote S",
    },
};

static intel_x86_umask_t bdx_unc_h_requests[] = {
    {
        .uname = "INVITOE_LOCAL",
        .ucode = 0x1000,
        .udesc = "Read and Write Requests -- Local InvItoEs",
    },
    {
        .uname = "INVITOE_REMOTE",
        .ucode = 0x2000,
        .udesc = "Read and Write Requests -- Remote InvItoEs",
    },
    {
        .uname = "READS",
        .ucode = 0x300,
        .udesc = "Read and Write Requests -- Reads",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "READS_LOCAL",
        .ucode = 0x100,
        .udesc = "Read and Write Requests -- Local Reads",
    },
    {
        .uname = "READS_REMOTE",
        .ucode = 0x200,
        .udesc = "Read and Write Requests -- Remote Reads",
    },
    {
        .uname = "WRITES",
        .ucode = 0xc00,
        .udesc = "Read and Write Requests -- Writes",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WRITES_LOCAL",
        .ucode = 0x400,
        .udesc = "Read and Write Requests -- Local Writes",
    },
    {
        .uname = "WRITES_REMOTE",
        .ucode = 0x800,
        .udesc = "Read and Write Requests -- Remote Writes",
    },
};

static intel_x86_umask_t bdx_unc_h_ring_ad_used[] = {
    {
        .uname = "CCW",
        .ucode = 0xc00,
        .udesc = "Counterclockwise",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CCW_EVEN",
        .ucode = 0x400,
        .udesc = "Counterclockwise and Even",
    },
    {
        .uname = "CCW_ODD",
        .ucode = 0x800,
        .udesc = "Counterclockwise and Odd",
    },
    {
        .uname = "CW",
        .ucode = 0x300,
        .udesc = "Clockwise",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CW_EVEN",
        .ucode = 0x100,
        .udesc = "Clockwise and Even",
    },
    {
        .uname = "CW_ODD",
        .ucode = 0x200,
        .udesc = "Clockwise and Odd",
    },
};

static intel_x86_umask_t bdx_unc_h_rpq_cycles_no_reg_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "iMC RPQ Credits Empty - Regular -- Channel 0",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "iMC RPQ Credits Empty - Regular -- Channel 1",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "iMC RPQ Credits Empty - Regular -- Channel 2",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN3",
        .ucode = 0x800,
        .udesc = "iMC RPQ Credits Empty - Regular -- Channel 3",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_sbo0_credits_acquired[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "For AD Ring",
    },
    {
        .uname = "BL",
        .ucode = 0x200,
        .udesc = "For BL Ring",
    },
};

static intel_x86_umask_t bdx_unc_h_snoops_rsp_after_data[] = {
    {
        .uname = "LOCAL",
        .ucode = 0x100,
        .udesc = "Data beat the Snoop Responses -- Local Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REMOTE",
        .ucode = 0x200,
        .udesc = "Data beat the Snoop Responses -- Remote Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_snoop_cycles_ne[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "Cycles with Snoops Outstanding -- All Requests",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "LOCAL",
        .ucode = 0x100,
        .udesc = "Cycles with Snoops Outstanding -- Local Requests",
    },
    {
        .uname = "REMOTE",
        .ucode = 0x200,
        .udesc = "Cycles with Snoops Outstanding -- Remote Requests",
    },
};

static intel_x86_umask_t bdx_unc_h_snoop_occupancy[] = {
    {
        .uname = "LOCAL",
        .ucode = 0x100,
        .udesc = "Tracker Snoops Outstanding Accumulator -- Local Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REMOTE",
        .ucode = 0x200,
        .udesc = "Tracker Snoops Outstanding Accumulator -- Remote Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_snoop_resp[] = {
    {
        .uname = "RSPCNFLCT",
        .ucode = 0x4000,
        .udesc = "Snoop Responses Received -- RSPCNFLCT*",
    },
    {
        .uname = "RSPI",
        .ucode = 0x100,
        .udesc = "Snoop Responses Received -- RspI",
    },
    {
        .uname = "RSPIFWD",
        .ucode = 0x400,
        .udesc = "Snoop Responses Received -- RspIFwd",
    },
    {
        .uname = "RSPS",
        .ucode = 0x200,
        .udesc = "Snoop Responses Received -- RspS",
    },
    {
        .uname = "RSPSFWD",
        .ucode = 0x800,
        .udesc = "Snoop Responses Received -- RspSFwd",
    },
    {
        .uname = "RSP_FWD_WB",
        .ucode = 0x2000,
        .udesc = "Snoop Responses Received -- Rsp*Fwd*WB",
    },
    {
        .uname = "RSP_WB",
        .ucode = 0x1000,
        .udesc = "Snoop Responses Received -- Rsp*WB",
    },
};

static intel_x86_umask_t bdx_unc_h_snp_resp_recv_local[] = {
    {
        .uname = "OTHER",
        .ucode = 0x8000,
        .udesc = "Snoop Responses Received Local -- Other",
    },
    {
        .uname = "RSPCNFLCT",
        .ucode = 0x4000,
        .udesc = "Snoop Responses Received Local -- RspCnflct",
    },
    {
        .uname = "RSPI",
        .ucode = 0x100,
        .udesc = "Snoop Responses Received Local -- RspI",
    },
    {
        .uname = "RSPIFWD",
        .ucode = 0x400,
        .udesc = "Snoop Responses Received Local -- RspIFwd",
    },
    {
        .uname = "RSPS",
        .ucode = 0x200,
        .udesc = "Snoop Responses Received Local -- RspS",
    },
    {
        .uname = "RSPSFWD",
        .ucode = 0x800,
        .udesc = "Snoop Responses Received Local -- RspSFwd",
    },
    {
        .uname = "RSPxFWDxWB",
        .ucode = 0x2000,
        .udesc = "Snoop Responses Received Local -- Rsp*FWD*WB",
    },
    {
        .uname = "RSPxWB",
        .ucode = 0x1000,
        .udesc = "Snoop Responses Received Local -- Rsp*WB",
    },
};

static intel_x86_umask_t bdx_unc_h_stall_no_sbo_credit[] = {
    {
        .uname = "SBO0_AD",
        .ucode = 0x100,
        .udesc = "Stall on No Sbo Credits -- For SBo0, AD Ring",
    },
    {
        .uname = "SBO0_BL",
        .ucode = 0x400,
        .udesc = "Stall on No Sbo Credits -- For SBo0, BL Ring",
    },
    {
        .uname = "SBO1_AD",
        .ucode = 0x200,
        .udesc = "Stall on No Sbo Credits -- For SBo1, AD Ring",
    },
    {
        .uname = "SBO1_BL",
        .ucode = 0x800,
        .udesc = "Stall on No Sbo Credits -- For SBo1, BL Ring",
    },
};

static intel_x86_umask_t bdx_unc_h_tad_requests_g0[] = {
    {
        .uname = "REGION0",
        .ucode = 0x100,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 0",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION1",
        .ucode = 0x200,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 1",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION2",
        .ucode = 0x400,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 2",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION3",
        .ucode = 0x800,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 3",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION4",
        .ucode = 0x1000,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 4",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION5",
        .ucode = 0x2000,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 5",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION6",
        .ucode = 0x4000,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 6",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION7",
        .ucode = 0x8000,
        .udesc = "HA Requests to a TAD Region - Group 0 -- TAD Region 7",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_tad_requests_g1[] = {
    {
        .uname = "REGION10",
        .ucode = 0x400,
        .udesc = "HA Requests to a TAD Region - Group 1 -- TAD Region 10",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION11",
        .ucode = 0x800,
        .udesc = "HA Requests to a TAD Region - Group 1 -- TAD Region 11",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION8",
        .ucode = 0x100,
        .udesc = "HA Requests to a TAD Region - Group 1 -- TAD Region 8",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGION9",
        .ucode = 0x200,
        .udesc = "HA Requests to a TAD Region - Group 1 -- TAD Region 9",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_tracker_cycles_full[] = {
    {
        .uname = "ALL",
        .ucode = 0x200,
        .udesc = "Tracker Cycles Full -- Cycles Completely Used",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "GP",
        .ucode = 0x100,
        .udesc = "Tracker Cycles Full -- Cycles GP Completely Used",
    },
};

static intel_x86_umask_t bdx_unc_h_tracker_cycles_ne[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "Tracker Cycles Not Empty -- All Requests",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "LOCAL",
        .ucode = 0x100,
        .udesc = "Tracker Cycles Not Empty -- Local Requests",
    },
    {
        .uname = "REMOTE",
        .ucode = 0x200,
        .udesc = "Tracker Cycles Not Empty -- Remote Requests",
    },
};

static intel_x86_umask_t bdx_unc_h_tracker_occupancy[] = {
    {
        .uname = "INVITOE_LOCAL",
        .ucode = 0x4000,
        .udesc = "Tracker Occupancy Accumultor -- Local InvItoE Requests",
    },
    {
        .uname = "INVITOE_REMOTE",
        .ucode = 0x8000,
        .udesc = "Tracker Occupancy Accumultor -- Remote InvItoE Requests",
    },
    {
        .uname = "READS_LOCAL",
        .ucode = 0x400,
        .udesc = "Tracker Occupancy Accumultor -- Local Read Requests",
    },
    {
        .uname = "READS_REMOTE",
        .ucode = 0x800,
        .udesc = "Tracker Occupancy Accumultor -- Remote Read Requests",
    },
    {
        .uname = "WRITES_LOCAL",
        .ucode = 0x1000,
        .udesc = "Tracker Occupancy Accumultor -- Local Write Requests",
    },
    {
        .uname = "WRITES_REMOTE",
        .ucode = 0x2000,
        .udesc = "Tracker Occupancy Accumultor -- Remote Write Requests",
    },
};

static intel_x86_umask_t bdx_unc_h_tracker_pending_occupancy[] = {
    {
        .uname = "LOCAL",
        .ucode = 0x100,
        .udesc = "Data Pending Occupancy Accumultor -- Local Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REMOTE",
        .ucode = 0x200,
        .udesc = "Data Pending Occupancy Accumultor -- Remote Requests",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_h_txr_ad_cycles_full[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "All",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "SCHED0",
        .ucode = 0x100,
        .udesc = "Scheduler 0",
    },
    {
        .uname = "SCHED1",
        .ucode = 0x200,
        .udesc = "Scheduler 1",
    },
};

static intel_x86_umask_t bdx_unc_h_txr_bl[] = {
    {
        .uname = "DRS_CACHE",
        .ucode = 0x100,
        .udesc = "Outbound DRS Ring Transactions to Cache -- Data to Cache",
    },
    {
        .uname = "DRS_CORE",
        .ucode = 0x200,
        .udesc = "Outbound DRS Ring Transactions to Cache -- Data to Core",
    },
    {
        .uname = "DRS_QPI",
        .ucode = 0x400,
        .udesc = "Outbound DRS Ring Transactions to Cache -- Data to QPI",
    },
};

static intel_x86_umask_t bdx_unc_h_txr_starved[] = {
    {
        .uname = "AK",
        .ucode = 0x100,
        .udesc = "Injection Starvation -- For AK Ring",
    },
    {
        .uname = "BL",
        .ucode = 0x200,
        .udesc = "Injection Starvation -- For BL Ring",
    },
};

static intel_x86_umask_t bdx_unc_h_wpq_cycles_no_reg_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "HA iMC CHN0 WPQ Credits Empty - Regular -- Channel 0",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "HA iMC CHN0 WPQ Credits Empty - Regular -- Channel 1",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "HA iMC CHN0 WPQ Credits Empty - Regular -- Channel 2",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CHN3",
        .ucode = 0x800,
        .udesc = "HA iMC CHN0 WPQ Credits Empty - Regular -- Channel 3",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_entry_t intel_bdx_unc_h_pe[] = {
    /* ADDR_OPC_MATCH not supported (linux kernel has no support for HA OPC yet*/
    {
        .name = "UNC_H_BT_CYCLES_NE",
        .code = 0x42,
        .desc = "Cycles the Backup Tracker (BT) is not empty. The BT is the actual HOM "
                "tracker in IVT.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_BT_OCCUPANCY",
        .code = 0x43,
        .desc =
            "Accumulates the occupancy of te HA BT pool in every cycle. This can be used "
            "with the 'not empty' stat to calculate the average queue occupancy or the "
            "'allocations' stat to calculate average queue latency. HA BTs are allocated "
            "as son as a request enters the HA and are released after the snoop response "
            "and data return and the response is returned to the ring",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_BYPASS_IMC",
        .code = 0x14,
        .desc = "Counts the number of times when the HA was able to bypass was "
                "attempted.  This is a latency optimization for situations when there is "
                "light loadings on the memory subsystem.  This can be filted by when the "
                "bypass was taken and when it was not.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_bypass_imc,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_bypass_imc),
    },
    {
        .name = "UNC_H_CONFLICT_CYCLES",
        .code = 0xb,
        .desc = "TBD",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },

    {
        .name = "UNC_H_CLOCKTICKS",
        .code = 0x0,
        .desc =
            "Counts the number of uclks in the HA.  This will be slightly different than "
            "the count in the Ubox because of enable/freeze delays.  The HA is on the "
            "other side of the die from the fixed Ubox uclk counter, so the drift could "
            "be somewhat larger than in units that are closer like the QPI Agent.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_DIRECT2CORE_COUNT",
        .code = 0x11,
        .desc = "Number of Direct2Core messages sent",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_DIRECT2CORE_CYCLES_DISABLED",
        .code = 0x12,
        .desc = "Number of cycles in which Direct2Core was disabled",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_DIRECT2CORE_TXN_OVERRIDE",
        .code = 0x13,
        .desc = "Number of Reads where Direct2Core overridden",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_DIRECTORY_LAT_OPT",
        .code = 0x41,
        .desc = "Directory Latency Optimization Data Return Path Taken. When directory "
                "mode is enabled and the directory retuned for a read is Dir=I, then "
                "data can be returned using a faster path if certain conditions are met "
                "(credits, free pipeline, etc).",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_DIRECTORY_LOOKUP",
        .code = 0xc,
        .desc = "Counts the number of transactions that looked up the directory.  Can be "
                "filtered by requests that had to snoop and those that did not have to.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_directory_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_directory_lookup),
    },
    {
        .name = "UNC_H_DIRECTORY_UPDATE",
        .code = 0xd,
        .desc = "Counts the number of directory updates that were required.  These "
                "result in writes to the memory controller.  This can be filtered by "
                "directory sets and directory clears.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_directory_update,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_directory_update),
    },
    {
        .name = "UNC_H_HITME_HIT",
        .code = 0x71,
        .desc = "TBD",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_hitme_hit,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_hitme_hit),
    },
    {
        .name = "UNC_H_HITME_HIT_PV_BITS_SET",
        .code = 0x72,
        .desc = "TBD",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_hitme_hit_pv_bits_set,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_hitme_hit_pv_bits_set),
    },
    {
        .name = "UNC_H_HITME_LOOKUP",
        .code = 0x70,
        .desc = "TBD",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_hitme_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_hitme_lookup),
    },
    {
        .name = "UNC_H_IGR_NO_CREDIT_CYCLES",
        .code = 0x22,
        .desc = "Counts the number of cycles when the HA does not have credits to send "
                "messages to the QPI Agent.  This can be filtered by the different "
                "credit pools and the different links.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_igr_no_credit_cycles,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_igr_no_credit_cycles),
    },
    {
        .name = "UNC_H_IMC_READS",
        .code = 0x17,
        .desc = "Count of the number of reads issued to any of the memory controller "
                "channels.  This can be filtered by the priority of the reads.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_imc_reads,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_imc_reads),
    },
    {
        .name = "UNC_H_IMC_RETRY",
        .code = 0x1e,
        .desc = "TBD",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_H_IMC_WRITES",
        .code = 0x1a,
        .desc = "Counts the total number of full line writes issued from the HA into the "
                "memory controller.  This counts for all four channels.  It can be "
                "filtered by full/partial and ISOCH/non-ISOCH.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_imc_writes,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_imc_writes),
    },
    {
        .name = "UNC_H_OSB",
        .code = 0x53,
        .desc = "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB "
                "snoops to be broadcast. Does not count all the snoops generated by OSB.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_osb,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_osb),
    },
    {
        .name = "UNC_H_OSB_EDR",
        .code = 0x54,
        .desc = "Counts the number of transactions that broadcast snoop due to OSB, but "
                "found clean data in memory and was able to do early data return",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_osb_edr,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_osb_edr),
    },
    {
        .name = "UNC_H_REQUESTS",
        .code = 0x1,
        .desc = "Counts the total number of read requests made into the Home Agent. "
                "Reads include all read opcodes (including RFO).  Writes include all "
                "writes (streaming, evictions, HitM, etc).",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_requests,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_requests),
    },
    {
        .name = "UNC_H_RING_AD_USED",
        .code = 0x3e,
        .desc =
            "Counts the number of cycles that the AD ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_ring_ad_used),
    },
    {
        .name = "UNC_H_RING_AK_USED",
        .code = 0x3f,
        .desc =
            "Counts the number of cycles that the AK ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_ring_ad_used),
    },
    {
        .name = "UNC_H_RING_BL_USED",
        .code = 0x40,
        .desc =
            "Counts the number of cycles that the BL ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_ring_ad_used),
    },
    {
        .name = "UNC_H_RPQ_CYCLES_NO_REG_CREDITS",
        .code = 0x15,
        .desc =
            "Counts the number of cycles when there are no regular credits available for "
            "posting reads from the HA into the iMC.  In order to send reads into the "
            "memory controller, the HA must first acquire a credit for the iMCs RPQ "
            "(read pending queue).  This queue is broken into regular credits/buffers "
            "that are used by general reads, and special requests such as ISOCH reads.  "
            "This count only tracks the regular credits  Common high banwidth workloads "
            "should be able to make use of all of the regular buffers, but it will be "
            "difficult (and uncommon) to make use of both the regular and special "
            "buffers at the same time.  One can filter based on the memory controller "
            "channel.  One or more channels can be tracked at a given iven time.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_rpq_cycles_no_reg_credits,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_rpq_cycles_no_reg_credits),
    },
    {
        .name = "UNC_H_SBO0_CREDITS_ACQUIRED",
        .code = 0x68,
        .desc = "Number of Sbo 0 credits acquired in a given cycle, per ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_sbo0_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_sbo0_credits_acquired),
    },
    {
        .name = "UNC_H_SBO0_CREDIT_OCCUPANCY",
        .code = 0x6a,
        .desc = "Number of Sbo 0 credits in use in a given cycle, per ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_sbo0_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_sbo0_credits_acquired),
    },
    {
        .name = "UNC_H_SBO1_CREDITS_ACQUIRED",
        .code = 0x69,
        .desc = "Number of Sbo 1 credits acquired in a given cycle, per ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_sbo0_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_sbo0_credits_acquired),
    },
    {
        .name = "UNC_H_SBO1_CREDIT_OCCUPANCY",
        .code = 0x6b,
        .desc = "Number of Sbo 1 credits in use in a given cycle, per ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_sbo0_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_sbo0_credits_acquired),
    },
    {
        .name = "UNC_H_SNOOPS_RSP_AFTER_DATA",
        .code = 0xa,
        .desc = "Counts the number of reads when the snoop was on the critical path to "
                "the data return.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_snoops_rsp_after_data,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_snoops_rsp_after_data),
    },
    {
        .name = "UNC_H_SNOOP_CYCLES_NE",
        .code = 0x8,
        .desc = "Counts cycles when one or more snoops are outstanding.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_snoop_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_snoop_cycles_ne),
    },
    {
        .name = "UNC_H_SNOOP_OCCUPANCY",
        .code = 0x9,
        .desc = "Accumulates the occupancy of either the local HA tracker pool that have "
                "snoops pending in every cycle.    This can be used in conjection with "
                "the not empty stat to calculate average queue occupancy or the "
                "allocations stat in order to calculate average queue latency.  HA "
                "trackers are allocated as soon as a request enters the HA if an HT "
                "(HomeTracker) entry is available and this occupancy is decremented when "
                "all the snoop responses have retureturned.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_snoop_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_snoop_occupancy),
    },
    {
        .name = "UNC_H_SNOOP_RESP",
        .code = 0x21,
        .desc = "Counts the total number of RspI snoop responses received.  Whenever a "
                "snoops are issued, one or more snoop responses will be returned "
                "depending on the topology of the system.   In systems larger than 2s, "
                "when multiple snoops are returned this will count all the snoops that "
                "are received.  For example, if 3 snoops were issued and returned RspI, "
                "RspS, and RspSFwd; then each of these sub-events would increment by 1.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_snoop_resp,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_snoop_resp),
    },
    {
        .name = "UNC_H_SNP_RESP_RECV_LOCAL",
        .code = 0x60,
        .desc = "Number of snoop responses received for a Local  request",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_snp_resp_recv_local,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_snp_resp_recv_local),
    },
    {
        .name = "UNC_H_STALL_NO_SBO_CREDIT",
        .code = 0x6c,
        .desc = "Number of cycles Egress is stalled waiting for an Sbo credit to become "
                "available.  Per Sbo, per Ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_stall_no_sbo_credit,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_stall_no_sbo_credit),
    },
    {
        .name = "UNC_H_TAD_REQUESTS_G0",
        .code = 0x1b,
        .desc =
            "Counts the number of HA requests to a given TAD region.  There are up to 11 "
            "TAD (target address decode) regions in each home agent.  All requests "
            "destined for the memory controller must first be decoded to determine which "
            "TAD region they are in.  This event is filtered based on the TAD region ID, "
            "and covers regions 0 to 7.  This event is useful for understanding how "
            "applications are using the memory that is spread across the different "
            "memory regions.  It is particularly useful for Monroe systems that use the "
            "TAD to enable individual channels to enter self-refresh to save powewer.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tad_requests_g0,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tad_requests_g0),
    },
    {
        .name = "UNC_H_TAD_REQUESTS_G1",
        .code = 0x1c,
        .desc =
            "Counts the number of HA requests to a given TAD region.  There are up to 11 "
            "TAD (target address decode) regions in each home agent.  All requests "
            "destined for the memory controller must first be decoded to determine which "
            "TAD region they are in.  This event is filtered based on the TAD region ID, "
            "and covers regions 8 to 10.  This event is useful for understanding how "
            "applications are using the memory that is spread across the different "
            "memory regions.  It is particularly useful for Monroe systems that use the "
            "TAD to enable individual channels to enter self-refresh to save powewer.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tad_requests_g1,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tad_requests_g1),
    },
    {
        .name = "UNC_H_TRACKER_CYCLES_FULL",
        .code = 0x2,
        .desc =
            "Counts the number of cycles when the local HA tracker pool is completely "
            "used.  This can be used with edge detect to identify the number of "
            "situations when the pool became fully utilized.  This should not be "
            "confused with RTID credit usage -- which must be tracked inside each cbo "
            "individually -- but represents the actual tracker buffer structure.  In "
            "other words, the system could be starved for RTIDs but not fill up the HA "
            "trackers.  HA trackers are allocated as soon as a request enters the HA and "
            "is released after the snoop response and data return (or post in the case "
            "of a write) and the response is returned on the ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tracker_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tracker_cycles_full),
    },
    {
        .name = "UNC_H_TRACKER_CYCLES_NE",
        .code = 0x3,
        .desc =
            "Counts the number of cycles when the local HA tracker pool is not empty.  "
            "This can be used with edge detect to identify the number of situations when "
            "the pool became empty.  This should not be confused with RTID credit usage "
            "-- which must be tracked inside each cbo individually -- but represents the "
            "actual tracker buffer structure.  In other words, this buffer could be "
            "completely empty, but there may still be credits in use by the CBos.  This "
            "stat can be used in conjunction with the occupancy accumulation stat in "
            "order to calculate average queue occpancy.  HA trackers are allocated as "
            "soon as a request enters the HA if an HT (Home Tracker) entry is available "
            "and is released after the snoop response and data return (or post in the "
            "case of a write) and the response is returned on the ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tracker_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tracker_cycles_ne),
    },
    {
        .name = "UNC_H_TRACKER_OCCUPANCY",
        .code = 0x4,
        .desc = "Accumulates the occupancy of the local HA tracker pool in every cycle.  "
                "This can be used in conjection with the not empty stat to calculate "
                "average queue occupancy or the allocations stat in order to calculate "
                "average queue latency.  HA trackers are allocated as soon as a request "
                "enters the HA if a HT (Home Tracker) entry is available and is released "
                "after the snoop response and data return (or post in the case of a "
                "write) and the response is returned on the rhe ring.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tracker_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tracker_occupancy),
    },
    {
        .name = "UNC_H_TRACKER_PENDING_OCCUPANCY",
        .code = 0x5,
        .desc = "Accumulates the number of transactions that have data from the memory "
                "controller until they get scheduled to the Egress.  This can be used to "
                "calculate the queuing latency for two things.  (1) If the system is "
                "waiting for snoops, this will increase.  (2) If the system cant "
                "schedule to the Egress because of either (a) Egress Credits or (b) QPI "
                "BL IGR credits for remote requestss.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_tracker_pending_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_tracker_pending_occupancy),
    },
    {
        .name = "UNC_H_TXR_AD_CYCLES_FULL",
        .code = 0x2a,
        .desc = "AD Egress Full",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_txr_ad_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_txr_ad_cycles_full),
    },
    {
        .name = "UNC_H_TXR_AK_CYCLES_FULL",
        .code = 0x32,
        .desc = "AK Egress Full",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_txr_ad_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_txr_ad_cycles_full), /* shared */
    },
    {
        .name = "UNC_H_TXR_BL",
        .code = 0x10,
        .desc = "Counts the number of DRS messages sent out on the BL ring.   This can "
                "be filtered by the destination.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_txr_bl,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_txr_bl),
    },
    {
        .name = "UNC_H_TXR_BL_CYCLES_FULL",
        .code = 0x36,
        .desc = "BL Egress Full",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_txr_ad_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_txr_ad_cycles_full), /* shared */
    },
    {
        .name = "UNC_H_TXR_STARVED",
        .code = 0x6d,
        .desc =
            "Counts injection starvation.  This starvation is triggered when the Egress "
            "cannot send a transaction onto the ring for a long period of time.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_txr_starved,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_txr_starved),
    },
    {
        .name = "UNC_H_WPQ_CYCLES_NO_REG_CREDITS",
        .code = 0x18,
        .desc =
            "Counts the number of cycles when there are no regular credits available for "
            "posting writes from the HA into the iMC.  In order to send writes into the "
            "memory controller, the HA must first acquire a credit for the iMCs WPQ "
            "(write pending queue).  This queue is broken into regular credits/buffers "
            "that are used by general writes, and special requests such as ISOCH writes. "
            " This count only tracks the regular credits  Common high banwidth workloads "
            "should be able to make use of all of the regular buffers, but it will be "
            "difficult (and uncommon) to make use of both the regular and special "
            "buffers at the same time.  One can filter based on the memory controller "
            "channel.  One or more channels can be tracked at a given iven time.",
        .modmsk = BDX_UNC_HA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_h_wpq_cycles_no_reg_credits,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_h_wpq_cycles_no_reg_credits),
    },
};
