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
 * PMU: skx_unc_m2m
 */

static intel_x86_umask_t skx_unc_m2m_ag0_ad_crd_acquired[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 Credits Acquired -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_ag0_ad_crd_occupancy[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 Credits Occupancy -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_bypass_m2m_egress[] = {
    {
        .uname = "NOT_TAKEN",
        .ucode = 0x200,
        .udesc = "M2M to iMC Bypass -- Not Taken",
    },
    {
        .uname = "TAKEN",
        .ucode = 0x100,
        .udesc = "M2M to iMC Bypass -- Taken",
    },
};

static intel_x86_umask_t skx_unc_m2m_bypass_m2m_ingress[] = {
    {
        .uname = "NOT_TAKEN",
        .ucode = 0x200,
        .udesc = "M2M to iMC Bypass -- Not Taken",
    },
    {
        .uname = "TAKEN",
        .ucode = 0x100,
        .udesc = "M2M to iMC Bypass -- Taken",
    },
};

static intel_x86_umask_t skx_unc_m2m_directory_hit[] = {
    {
        .uname = "CLEAN_A",
        .ucode = 0x8000,
        .udesc = "Directory Hit -- On NonDirty Line in A State",
    },
    {
        .uname = "CLEAN_I",
        .ucode = 0x1000,
        .udesc = "Directory Hit -- On NonDirty Line in I State",
    },
    {
        .uname = "CLEAN_P",
        .ucode = 0x4000,
        .udesc = "Directory Hit -- On NonDirty Line in L State",
    },
    {
        .uname = "CLEAN_S",
        .ucode = 0x2000,
        .udesc = "Directory Hit -- On NonDirty Line in S State",
    },
    {
        .uname = "DIRTY_A",
        .ucode = 0x800,
        .udesc = "Directory Hit -- On Dirty Line in A State",
    },
    {
        .uname = "DIRTY_I",
        .ucode = 0x100,
        .udesc = "Directory Hit -- On Dirty Line in I State",
    },
    {
        .uname = "DIRTY_P",
        .ucode = 0x400,
        .udesc = "Directory Hit -- On Dirty Line in L State",
    },
    {
        .uname = "DIRTY_S",
        .ucode = 0x200,
        .udesc = "Directory Hit -- On Dirty Line in S State",
    },
};

static intel_x86_umask_t skx_unc_m2m_directory_lookup[] = {
    {
        .uname = "ANY",
        .ucode = 0x100,
        .udesc = "Directory Lookups -- Any state",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "STATE_A",
        .ucode = 0x800,
        .udesc = "Directory Lookups -- A State",
    },
    {
        .uname = "STATE_I",
        .ucode = 0x200,
        .udesc = "Directory Lookups -- I State",
    },
    {
        .uname = "STATE_S",
        .ucode = 0x400,
        .udesc = "Directory Lookups -- S State",
    },
};

static intel_x86_umask_t skx_unc_m2m_directory_miss[] = {
    {
        .uname = "CLEAN_A",
        .ucode = 0x8000,
        .udesc = "Directory Miss -- On NonDirty Line in A State",
    },
    {
        .uname = "CLEAN_I",
        .ucode = 0x1000,
        .udesc = "Directory Miss -- On NonDirty Line in I State",
    },
    {
        .uname = "CLEAN_P",
        .ucode = 0x4000,
        .udesc = "Directory Miss -- On NonDirty Line in L State",
    },
    {
        .uname = "CLEAN_S",
        .ucode = 0x2000,
        .udesc = "Directory Miss -- On NonDirty Line in S State",
    },
    {
        .uname = "DIRTY_A",
        .ucode = 0x800,
        .udesc = "Directory Miss -- On Dirty Line in A State",
    },
    {
        .uname = "DIRTY_I",
        .ucode = 0x100,
        .udesc = "Directory Miss -- On Dirty Line in I State",
    },
    {
        .uname = "DIRTY_P",
        .ucode = 0x400,
        .udesc = "Directory Miss -- On Dirty Line in L State",
    },
    {
        .uname = "DIRTY_S",
        .ucode = 0x200,
        .udesc = "Directory Miss -- On Dirty Line in S State",
    },
};

static intel_x86_umask_t skx_unc_m2m_directory_update[] = {
    {
        .uname = "A2I",
        .ucode = 0x2000,
        .udesc = "Directory Updates -- A2I",
    },
    {
        .uname = "A2S",
        .ucode = 0x4000,
        .udesc = "Directory Updates -- A2S",
    },
    {
        .uname = "ANY",
        .ucode = 0x100,
        .udesc = "Directory Updates -- Any",
    },
    {
        .uname = "I2A",
        .ucode = 0x400,
        .udesc = "Directory Updates -- I2A",
    },
    {
        .uname = "I2S",
        .ucode = 0x200,
        .udesc = "Directory Updates -- I2S",
    },
    {
        .uname = "S2A",
        .ucode = 0x1000,
        .udesc = "Directory Updates -- S2A",
    },
    {
        .uname = "S2I",
        .ucode = 0x800,
        .udesc = "Directory Updates -- S2I",
    },
};

static intel_x86_umask_t skx_unc_m2m_egress_ordering[] = {
    {
        .uname = "IV_SNOOPGO_DN",
        .ucode = 0x400,
        .udesc = "Egress Blocking due to Ordering requirements -- Down",
    },
    {
        .uname = "IV_SNOOPGO_UP",
        .ucode = 0x100,
        .udesc = "Egress Blocking due to Ordering requirements -- Up",
    },
};

static intel_x86_umask_t skx_unc_m2m_fast_asserted[] = {
    {
        .uname = "HORZ",
        .ucode = 0x200,
        .udesc = "FaST wire asserted -- Horizontal",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "VERT",
        .ucode = 0x100,
        .udesc = "FaST wire asserted -- Vertical",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t skx_unc_m2m_horz_ring_ad_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal AD Ring In Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal AD Ring In Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal AD Ring In Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal AD Ring In Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_horz_ring_ak_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal AK Ring In Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal AK Ring In Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal AK Ring In Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal AK Ring In Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_horz_ring_bl_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal BL Ring in Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal BL Ring in Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal BL Ring in Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal BL Ring in Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_horz_ring_iv_in_use[] = {
    {
        .uname = "LEFT",
        .ucode = 0x100,
        .udesc = "Horizontal IV Ring in Use -- Left",
    },
    {
        .uname = "RIGHT",
        .ucode = 0x400,
        .udesc = "Horizontal IV Ring in Use -- Right",
    },
};

static intel_x86_umask_t skx_unc_m2m_imc_reads[] = {
    {
        .uname = "ALL",
        .ucode = 0x400,
        .udesc = "M2M Reads Issued to iMC -- All, regardless of priority.",
    },
    {
        .uname = "FROM_TRANSGRESS",
        .ucode = 0x1000,
        .udesc = "M2M Reads Issued to iMC -- All, regardless of priority.",
    },
    {
        .uname = "ISOCH",
        .ucode = 0x200,
        .udesc = "M2M Reads Issued to iMC -- Critical Priority",
    },
    {
        .uname = "NORMAL",
        .ucode = 0x100,
        .udesc = "M2M Reads Issued to iMC -- Normal Priority",
    },
};

static intel_x86_umask_t skx_unc_m2m_imc_writes[] = {
    {
        .uname = "ALL",
        .ucode = 0x1000,
        .udesc = "M2M Writes Issued to iMC -- All Writes",
    },
    {
        .uname = "FROM_TRANSGRESS",
        .ucode = 0x4000,
        .udesc = "M2M Writes Issued to iMC -- All, regardless of priority.",
    },
    {
        .uname = "FULL",
        .ucode = 0x100,
        .udesc = "M2M Writes Issued to iMC -- Full Line Non-ISOCH",
    },
    {
        .uname = "FULL_ISOCH",
        .ucode = 0x400,
        .udesc = "M2M Writes Issued to iMC -- ISOCH Full Line",
    },
    {
        .uname = "NI",
        .ucode = 0x8000,
        .udesc = "M2M Writes Issued to iMC -- All, regardless of priority.",
    },
    {
        .uname = "PARTIAL",
        .ucode = 0x200,
        .udesc = "M2M Writes Issued to iMC -- Partial Non-ISOCH",
    },
    {
        .uname = "PARTIAL_ISOCH",
        .ucode = 0x800,
        .udesc = "M2M Writes Issued to iMC -- ISOCH Partial",
    },
};

static intel_x86_umask_t skx_unc_m2m_pkt_match[] = {
    {
        .uname = "MC",
        .ucode = 0x200,
        .udesc = "Number Packet Header Matches -- MC Match",
    },
    {
        .uname = "MESH",
        .ucode = 0x100,
        .udesc = "Number Packet Header Matches -- Mesh Match",
    },
};

static intel_x86_umask_t skx_unc_m2m_ring_bounces_horz[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Messages that bounced on the Horizontal Ring. -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Messages that bounced on the Horizontal Ring. -- AK",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Messages that bounced on the Horizontal Ring. -- BL",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Messages that bounced on the Horizontal Ring. -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_ring_bounces_vert[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Messages that bounced on the Vertical Ring. -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc =
            "Messages that bounced on the Vertical Ring. -- Acknowledgements to core",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Messages that bounced on the Vertical Ring. -- Data Responses to core",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc =
            "Messages that bounced on the Vertical Ring. -- Snoops of processors cachee.",
    },
};

static intel_x86_umask_t skx_unc_m2m_ring_sink_starved_horz[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Sink Starvation on Horizontal Ring -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Sink Starvation on Horizontal Ring -- AK",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Sink Starvation on Horizontal Ring -- Acknowledgements to Agent 1",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Sink Starvation on Horizontal Ring -- BL",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Sink Starvation on Horizontal Ring -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_ring_sink_starved_vert[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Sink Starvation on Vertical Ring -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Sink Starvation on Vertical Ring -- Acknowledgements to core",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Sink Starvation on Vertical Ring -- Data Responses to core",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Sink Starvation on Vertical Ring -- Snoops of processors cachee.",
    },
};

static intel_x86_umask_t skx_unc_m2m_rpq_cycles_reg_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Regular -- Channel 0",
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Regular -- Channel 1",
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Regular -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_rpq_cycles_spec_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Special -- Channel 0",
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Special -- Channel 1",
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "M2M to iMC RPQ Cycles w/Credits - Special -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_rxr_busy_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Injection Starvation -- AD - Credit",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Injection Starvation -- BL - Credit",
    },
};

static intel_x86_umask_t skx_unc_m2m_rxr_bypass[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Bypass -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Bypass -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Bypass -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Bypass -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Bypass -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Bypass -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_rxr_crd_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Injection Starvation -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Injection Starvation -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Injection Starvation -- BL - Credit",
    },
    {
        .uname = "IFV",
        .ucode = 0x8000,
        .udesc = "Transgress Injection Starvation -- IFV - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Injection Starvation -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_rxr_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Allocations -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Allocations -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Allocations -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Allocations -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Allocations -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Allocations -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_rxr_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Occupancy -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Occupancy -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Occupancy -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Occupancy -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Occupancy -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Occupancy -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_stall_no_txr_horz_crd_ad_ag0[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_stall_no_txr_horz_crd_ad_ag1[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_stall_no_txr_horz_crd_bl_ag0[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_stall_no_txr_horz_crd_bl_ag1[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_m2m_tracker_cycles_full[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Tracker Cycles Full -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Tracker Cycles Full -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Tracker Cycles Full -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_tracker_cycles_ne[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Tracker Cycles Not Empty -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Tracker Cycles Not Empty -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Tracker Cycles Not Empty -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_tracker_inserts[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Tracker Inserts -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Tracker Inserts -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Tracker Inserts -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_tracker_occupancy[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Tracker Occupancy -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Tracker Occupancy -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Tracker Occupancy -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak[] = {
    {
        .uname = "CRD_CBO",
        .ucode = 0x200,
        .udesc = "Outbound Ring Transactions on AK -- CRD Transactions to Cbo",
    },
    {
        .uname = "NDR",
        .ucode = 0x100,
        .udesc = "Outbound Ring Transactions on AK -- NDR Transactions",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_credits_acquired[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Credit Acquired -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Credit Acquired -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_credit_occupancy[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Credits Occupancy -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Credits Occupancy -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_cycles_full[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "AK Egress (to CMS) Full -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Full -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Full -- Common Mesh Stop - Far Side",
    },
    {
        .uname = "RDCRD0",
        .ucode = 0x800,
        .udesc = "AK Egress (to CMS) Full -- Read Credit Request",
    },
    {
        .uname = "RDCRD1",
        .ucode = 0x8800,
        .udesc = "AK Egress (to CMS) Full -- Read Credit Request",
    },
    {
        .uname = "WRCMP0",
        .ucode = 0x2000,
        .udesc = "AK Egress (to CMS) Full -- Write Compare Request",
    },
    {
        .uname = "WRCMP1",
        .ucode = 0xa000,
        .udesc = "AK Egress (to CMS) Full -- Write Compare Request",
    },
    {
        .uname = "WRCRD0",
        .ucode = 0x1000,
        .udesc = "AK Egress (to CMS) Full -- Write Credit Request",
    },
    {
        .uname = "WRCRD1",
        .ucode = 0x9000,
        .udesc = "AK Egress (to CMS) Full -- Write Credit Request",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_cycles_ne[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "AK Egress (to CMS) Not Empty -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Not Empty -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Not Empty -- Common Mesh Stop - Far Side",
    },
    {
        .uname = "RDCRD",
        .ucode = 0x800,
        .udesc = "AK Egress (to CMS) Not Empty -- Read Credit Request",
    },
    {
        .uname = "WRCMP",
        .ucode = 0x2000,
        .udesc = "AK Egress (to CMS) Not Empty -- Write Compare Request",
    },
    {
        .uname = "WRCRD",
        .ucode = 0x1000,
        .udesc = "AK Egress (to CMS) Not Empty -- Write Credit Request",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_inserts[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "AK Egress (to CMS) Allocations -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Allocations -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Allocations -- Common Mesh Stop - Far Side",
    },
    {
        .uname = "PREF_RD_CAM_HIT",
        .ucode = 0x4000,
        .udesc = "AK Egress (to CMS) Allocations -- Prefetch Read Cam Hit",
    },
    {
        .uname = "RDCRD",
        .ucode = 0x800,
        .udesc = "AK Egress (to CMS) Allocations -- Read Credit Request",
    },
    {
        .uname = "WRCMP",
        .ucode = 0x2000,
        .udesc = "AK Egress (to CMS) Allocations -- Write Compare Request",
    },
    {
        .uname = "WRCRD",
        .ucode = 0x1000,
        .udesc = "AK Egress (to CMS) Allocations -- Write Credit Request",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_no_credit_cycles[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc =
            "Cycles with No AK Egress (to CMS) Credits -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc =
            "Cycles with No AK Egress (to CMS) Credits -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_no_credit_stalled[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "Cycles Stalled with No AK Egress (to CMS) Credits -- Common Mesh Stop "
                 "- Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "Cycles Stalled with No AK Egress (to CMS) Credits -- Common Mesh Stop "
                 "- Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_occupancy[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "AK Egress (to CMS) Occupancy -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Occupancy -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Occupancy -- Common Mesh Stop - Far Side",
    },
    {
        .uname = "RDCRD",
        .ucode = 0x800,
        .udesc = "AK Egress (to CMS) Occupancy -- Read Credit Request",
    },
    {
        .uname = "WRCMP",
        .ucode = 0x2000,
        .udesc = "AK Egress (to CMS) Occupancy -- Write Compare Request",
    },
    {
        .uname = "WRCRD",
        .ucode = 0x1000,
        .udesc = "AK Egress (to CMS) Occupancy -- Write Credit Request",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_ak_sideband[] = {
    {
        .uname = "RD",
        .ucode = 0x100,
        .udesc = "AK Egress (to CMS) Sideband -- ",
    },
    {
        .uname = "WR",
        .ucode = 0x200,
        .udesc = "AK Egress (to CMS) Sideband -- ",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl[] = {
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
        .uname = "DRS_UPI",
        .ucode = 0x400,
        .udesc = "Outbound DRS Ring Transactions to Cache -- Data to QPI",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_credits_acquired[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Credit Acquired -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Credit Acquired -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_credit_occupancy[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Credits Occupancy -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Credits Occupancy -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_cycles_full[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "BL Egress (to CMS) Full -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Full -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Full -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_cycles_ne[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "BL Egress (to CMS) Not Empty -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Not Empty -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Not Empty -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_inserts[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "BL Egress (to CMS) Allocations -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Allocations -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Allocations -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_no_credit_cycles[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc =
            "Cycles with No BL Egress (to CMS) Credits -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc =
            "Cycles with No BL Egress (to CMS) Credits -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_no_credit_stalled[] = {
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "Cycles Stalled with No BL Egress (to CMS) Credits -- Common Mesh Stop "
                 "- Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "Cycles Stalled with No BL Egress (to CMS) Credits -- Common Mesh Stop "
                 "- Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txc_bl_occupancy[] = {
    {
        .uname = "ALL",
        .ucode = 0x300,
        .udesc = "BL Egress (to CMS) Occupancy -- All",
    },
    {
        .uname = "CMS0",
        .ucode = 0x100,
        .udesc = "BL Egress (to CMS) Occupancy -- Common Mesh Stop - Near Side",
    },
    {
        .uname = "CMS1",
        .ucode = 0x200,
        .udesc = "BL Egress (to CMS) Occupancy -- Common Mesh Stop - Far Side",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_ads_used[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal ADS Used -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal ADS Used -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal ADS Used -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal ADS Used -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal ADS Used -- BL - Credit",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_bypass[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Bypass Used -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Bypass Used -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Bypass Used -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Bypass Used -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Bypass Used -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Bypass Used -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_cycles_full[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_cycles_ne[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Inserts -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Egress Inserts -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Inserts -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Inserts -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress Inserts -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Inserts -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_nack[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress NACKs -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x2000,
        .udesc = "CMS Horizontal Egress NACKs -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress NACKs -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress NACKs -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress NACKs -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress NACKs -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Occupancy -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Egress Occupancy -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Occupancy -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Occupancy -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress Occupancy -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Occupancy -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_horz_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Injection Starvation -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Injection Starvation -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_ads_used[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 1",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_bypass[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical ADS Used -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_cycles_full[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_cycles_ne[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_inserts[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vert Egress Allocations -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vert Egress Allocations -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vert Egress Allocations -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vert Egress Allocations -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vert Egress Allocations -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vert Egress Allocations -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vert Egress Allocations -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_nack[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical Egress NACKs -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical Egress NACKs -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical Egress NACKs -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical Egress NACKs -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical Egress NACKs -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical Egress NACKs -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical Egress NACKs -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_occupancy[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vert Egress Occupancy -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vert Egress Occupancy -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vert Egress Occupancy -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vert Egress Occupancy -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vert Egress Occupancy -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vert Egress Occupancy -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vert Egress Occupancy -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_txr_vert_starved[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical Egress Injection Starvation -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical Egress Injection Starvation -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical Egress Injection Starvation -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical Egress Injection Starvation -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical Egress Injection Starvation -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical Egress Injection Starvation -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical Egress Injection Starvation -- IV",
    },
};

static intel_x86_umask_t skx_unc_m2m_vert_ring_ad_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical AD Ring In Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical AD Ring In Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical AD Ring In Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical AD Ring In Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_vert_ring_ak_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical AK Ring In Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical AK Ring In Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical AK Ring In Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical AK Ring In Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_vert_ring_bl_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical BL Ring in Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical BL Ring in Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical BL Ring in Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical BL Ring in Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_m2m_vert_ring_iv_in_use[] = {
    {
        .uname = "DN",
        .ucode = 0x400,
        .udesc = "Vertical IV Ring in Use -- Down",
    },
    {
        .uname = "UP",
        .ucode = 0x100,
        .udesc = "Vertical IV Ring in Use -- Up",
    },
};

static intel_x86_umask_t skx_unc_m2m_wpq_cycles_reg_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Regular -- Channel 0",
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Regular -- Channel 1",
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Regular -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_wpq_cycles_spec_credits[] = {
    {
        .uname = "CHN0",
        .ucode = 0x100,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Special -- Channel 0",
    },
    {
        .uname = "CHN1",
        .ucode = 0x200,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Special -- Channel 1",
    },
    {
        .uname = "CHN2",
        .ucode = 0x400,
        .udesc = "M2M->iMC WPQ Cycles w/Credits - Special -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_write_tracker_cycles_full[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Write Tracker Cycles Full -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Write Tracker Cycles Full -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Write Tracker Cycles Full -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_write_tracker_cycles_ne[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Write Tracker Cycles Not Empty -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Write Tracker Cycles Not Empty -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Write Tracker Cycles Not Empty -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_write_tracker_inserts[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Write Tracker Inserts -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Write Tracker Inserts -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Write Tracker Inserts -- Channel 2",
    },
};

static intel_x86_umask_t skx_unc_m2m_write_tracker_occupancy[] = {
    {
        .uname = "CH0",
        .ucode = 0x100,
        .udesc = "Write Tracker Occupancy -- Channel 0",
    },
    {
        .uname = "CH1",
        .ucode = 0x200,
        .udesc = "Write Tracker Occupancy -- Channel 1",
    },
    {
        .uname = "CH2",
        .ucode = 0x400,
        .udesc = "Write Tracker Occupancy -- Channel 2",
    },
};

static intel_x86_entry_t intel_skx_unc_m2m_pe[] = {
    {
        .name = "UNC_M2_AG0_AD_CRD_ACQUIRED",
        .code = 0x80,
        .desc =
            "Number of CMS Agent 0 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M2_AG0_AD_CRD_OCCUPANCY",
        .code = 0x82,
        .desc =
            "Number of CMS Agent 0 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M2_AG0_BL_CRD_ACQUIRED",
        .code = 0x88,
        .desc =
            "Number of CMS Agent 0 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_acquired, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M2_AG0_BL_CRD_OCCUPANCY",
        .code = 0x8a,
        .desc =
            "Number of CMS Agent 0 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M2_AG1_AD_CRD_ACQUIRED",
        .code = 0x84,
        .desc =
            "Number of CMS Agent 1 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_acquired, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M2_AG1_AD_CRD_OCCUPANCY",
        .code = 0x86,
        .desc =
            "Number of CMS Agent 1 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M2_AG1_BL_CRD_OCCUPANCY",
        .code = 0x8e,
        .desc =
            "Number of CMS Agent 1 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M2_AG1_BL_CREDITS_ACQUIRED",
        .code = 0x8c,
        .desc =
            "Number of CMS Agent 1 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ag0_ad_crd_acquired, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M2_BYPASS_M2M_EGRESS",
        .code = 0x22,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_bypass_m2m_egress,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_bypass_m2m_egress),
    },
    {
        .name = "UNC_M2_BYPASS_M2M_INGRESS",
        .code = 0x21,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_bypass_m2m_ingress,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_bypass_m2m_ingress),
    },
    {
        .name = "UNC_M2_CLOCKTICKS",
        .code = 0x0,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_CMS_CLOCKTICKS",
        .code = 0xc0,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2CORE_NOT_TAKEN_DIRSTATE",
        .code = 0x24,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2CORE_TAKEN",
        .code = 0x23,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2CORE_TXN_OVERRIDE",
        .code = 0x25,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2UPI_NOT_TAKEN_CREDITS",
        .code = 0x28,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2UPI_NOT_TAKEN_DIRSTATE",
        .code = 0x27,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2UPI_TAKEN",
        .code = 0x26,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECT2UPI_TXN_OVERRIDE",
        .code = 0x29,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_DIRECTORY_HIT",
        .code = 0x2a,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_directory_hit,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_directory_hit),
    },
    {
        .name = "UNC_M2_DIRECTORY_LOOKUP",
        .code = 0x2d,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_directory_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_directory_lookup),
    },
    {
        .name = "UNC_M2_DIRECTORY_MISS",
        .code = 0x2b,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_directory_miss,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_directory_miss),
    },
    {
        .name = "UNC_M2_DIRECTORY_UPDATE",
        .code = 0x2e,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_directory_update,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_directory_update),
    },
    {
        .name = "UNC_M2_EGRESS_ORDERING",
        .code = 0xae,
        .desc = "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO "
                "Ordering requirements",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_egress_ordering,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_egress_ordering),
    },
    {
        .name = "UNC_M2_FAST_ASSERTED",
        .code = 0xa5,
        .desc = "Counts the number of cycles either the local or incoming distress "
                "signals are asserted.  Incoming distress includes up, dn and across.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_fast_asserted,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_fast_asserted),
    },
    {
        .name = "UNC_M2_HORZ_RING_AD_IN_USE",
        .code = 0xa7,
        .desc = "Counts the number of cycles that the Horizontal AD ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.  We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_horz_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_horz_ring_ad_in_use),
    },
    {
        .name = "UNC_M2_HORZ_RING_AK_IN_USE",
        .code = 0xa9,
        .desc = "Counts the number of cycles that the Horizontal AK ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_horz_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_horz_ring_ak_in_use),
    },
    {
        .name = "UNC_M2_HORZ_RING_BL_IN_USE",
        .code = 0xab,
        .desc = "Counts the number of cycles that the Horizontal BL ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from  the ring stop.We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_horz_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_horz_ring_bl_in_use),
    },
    {
        .name = "UNC_M2_HORZ_RING_IV_IN_USE",
        .code = 0xad,
        .desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at "
            "this ring stop.  This includes when packets are passing by and when packets "
            "are being sunk, but does not include when packets are being sent from the "
            "ring stop.  There is only 1 IV ring.  Therefore, if one wants to monitor "
            "the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the "
            "Odd ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_horz_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_horz_ring_iv_in_use),
    },
    {
        .name = "UNC_M2_IMC_READS",
        .code = 0x37,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_imc_reads,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_imc_reads),
    },
    {
        .name = "UNC_M2_IMC_WRITES",
        .code = 0x38,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_imc_writes,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_imc_writes),
    },
    {
        .name = "UNC_M2_PKT_MATCH",
        .code = 0x4c,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_pkt_match,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_pkt_match),
    },
    {
        .name = "UNC_M2_PREFCAM_CYCLES_FULL",
        .code = 0x53,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_PREFCAM_CYCLES_NE",
        .code = 0x54,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_PREFCAM_DEMAND_PROMOTIONS",
        .code = 0x56,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_PREFCAM_INSERTS",
        .code = 0x57,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_PREFCAM_OCCUPANCY",
        .code = 0x55,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RING_BOUNCES_HORZ",
        .code = 0xa1,
        .desc = "Number of cycles incoming messages from the Horizontal ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ring_bounces_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ring_bounces_horz),
    },
    {
        .name = "UNC_M2_RING_BOUNCES_VERT",
        .code = 0xa0,
        .desc = "Number of cycles incoming messages from the Vertical ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ring_bounces_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ring_bounces_vert),
    },
    {
        .name = "UNC_M2_RING_SINK_STARVED_HORZ",
        .code = 0xa3,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ring_sink_starved_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ring_sink_starved_horz),
    },
    {
        .name = "UNC_M2_RING_SINK_STARVED_VERT",
        .code = 0xa2,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_ring_sink_starved_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_ring_sink_starved_vert),
    },
    {
        .name = "UNC_M2_RING_SRC_THRTL",
        .code = 0xa4,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RPQ_CYCLES_REG_CREDITS",
        .code = 0x43,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rpq_cycles_reg_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rpq_cycles_reg_credits),
    },
    {
        .name = "UNC_M2_RPQ_CYCLES_SPEC_CREDITS",
        .code = 0x44,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rpq_cycles_spec_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rpq_cycles_spec_credits),
    },
    {
        .name = "UNC_M2_RXC_AD_CYCLES_FULL",
        .code = 0x4,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_AD_CYCLES_NE",
        .code = 0x3,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_AD_INSERTS",
        .code = 0x1,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_AD_OCCUPANCY",
        .code = 0x2,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_BL_CYCLES_FULL",
        .code = 0x8,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_BL_CYCLES_NE",
        .code = 0x7,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_BL_INSERTS",
        .code = 0x5,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXC_BL_OCCUPANCY",
        .code = 0x6,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_RXR_BUSY_STARVED",
        .code = 0xb4,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, because a message from the "
                "other queue has higher priority",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rxr_busy_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rxr_busy_starved),
    },
    {
        .name = "UNC_M2_RXR_BYPASS",
        .code = 0xb2,
        .desc = "Number of packets bypassing the CMS Ingress",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rxr_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rxr_bypass),
    },
    {
        .name = "UNC_M2_RXR_CRD_STARVED",
        .code = 0xb3,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, the Ingress is unable to "
                "forward to the Egress due to a lack of credit.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rxr_crd_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rxr_crd_starved),
    },
    {
        .name = "UNC_M2_RXR_INSERTS",
        .code = 0xb1,
        .desc = "Number of allocations into the CMS Ingress  The Ingress is used to "
                "queue up requests received from the mesh",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rxr_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rxr_inserts),
    },
    {
        .name = "UNC_M2_RXR_OCCUPANCY",
        .code = 0xb0,
        .desc = "Occupancy event for the Ingress buffers in the CMS  The Ingress is used "
                "to queue up requests received from the mesh",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_rxr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_rxr_occupancy),
    },
    {
        .name = "UNC_M2_STALL_NO_TXR_HORZ_CRD_AD_AG0",
        .code = 0xd0,
        .desc = "Number of cycles the AD Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_stall_no_txr_horz_crd_ad_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_stall_no_txr_horz_crd_ad_ag0),
    },
    {
        .name = "UNC_M2_STALL_NO_TXR_HORZ_CRD_AD_AG1",
        .code = 0xd2,
        .desc = "Number of cycles the AD Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_stall_no_txr_horz_crd_ad_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_stall_no_txr_horz_crd_ad_ag1),
    },
    {
        .name = "UNC_M2_STALL_NO_TXR_HORZ_CRD_BL_AG0",
        .code = 0xd4,
        .desc = "Number of cycles the BL Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_stall_no_txr_horz_crd_bl_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_stall_no_txr_horz_crd_bl_ag0),
    },
    {
        .name = "UNC_M2_STALL_NO_TXR_HORZ_CRD_BL_AG1",
        .code = 0xd6,
        .desc = "Number of cycles the BL Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_stall_no_txr_horz_crd_bl_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_stall_no_txr_horz_crd_bl_ag1),
    },
    {
        .name = "UNC_M2_TGR_AD_CREDITS",
        .code = 0x41,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TGR_BL_CREDITS",
        .code = 0x42,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TRACKER_CYCLES_FULL",
        .code = 0x45,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_tracker_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_tracker_cycles_full),
    },
    {
        .name = "UNC_M2_TRACKER_CYCLES_NE",
        .code = 0x46,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_tracker_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_tracker_cycles_ne),
    },
    {
        .name = "UNC_M2_TRACKER_INSERTS",
        .code = 0x49,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_tracker_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_tracker_inserts),
    },
    {
        .name = "UNC_M2_TRACKER_OCCUPANCY",
        .code = 0x47,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_tracker_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_tracker_occupancy),
    },
    {
        .name = "UNC_M2_TRACKER_PENDING_OCCUPANCY",
        .code = 0x48,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_CREDITS_ACQUIRED",
        .code = 0xd,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_CREDIT_OCCUPANCY",
        .code = 0xe,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_CYCLES_FULL",
        .code = 0xc,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_CYCLES_NE",
        .code = 0xb,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_INSERTS",
        .code = 0x9,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_NO_CREDIT_CYCLES",
        .code = 0xf,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_NO_CREDIT_STALLED",
        .code = 0x10,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AD_OCCUPANCY",
        .code = 0xa,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M2_TXC_AK",
        .code = 0x39,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak),
    },
    {
        .name = "UNC_M2_TXC_AK_CREDITS_ACQUIRED",
        .code = 0x1d,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_credits_acquired),
    },
    {
        .name = "UNC_M2_TXC_AK_CREDIT_OCCUPANCY",
        .code = 0x1e,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_credit_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_credit_occupancy),
    },
    {
        .name = "UNC_M2_TXC_AK_CYCLES_FULL",
        .code = 0x14,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_cycles_full),
    },
    {
        .name = "UNC_M2_TXC_AK_CYCLES_NE",
        .code = 0x13,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_cycles_ne),
    },
    {
        .name = "UNC_M2_TXC_AK_INSERTS",
        .code = 0x11,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_inserts),
    },
    {
        .name = "UNC_M2_TXC_AK_NO_CREDIT_CYCLES",
        .code = 0x1f,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_no_credit_cycles,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_no_credit_cycles),
    },
    {
        .name = "UNC_M2_TXC_AK_NO_CREDIT_STALLED",
        .code = 0x20,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_no_credit_stalled,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_no_credit_stalled),
    },
    {
        .name = "UNC_M2_TXC_AK_OCCUPANCY",
        .code = 0x12,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_occupancy),
    },
    {
        .name = "UNC_M2_TXC_AK_SIDEBAND",
        .code = 0x6b,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_ak_sideband,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_ak_sideband),
    },
    {
        .name = "UNC_M2_TXC_BL",
        .code = 0x40,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl),
    },
    {
        .name = "UNC_M2_TXC_BL_CREDITS_ACQUIRED",
        .code = 0x19,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_credits_acquired),
    },
    {
        .name = "UNC_M2_TXC_BL_CREDIT_OCCUPANCY",
        .code = 0x1a,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_credit_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_credit_occupancy),
    },
    {
        .name = "UNC_M2_TXC_BL_CYCLES_FULL",
        .code = 0x18,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_cycles_full),
    },
    {
        .name = "UNC_M2_TXC_BL_CYCLES_NE",
        .code = 0x17,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_cycles_ne),
    },
    {
        .name = "UNC_M2_TXC_BL_INSERTS",
        .code = 0x15,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_inserts),
    },
    {
        .name = "UNC_M2_TXC_BL_NO_CREDIT_CYCLES",
        .code = 0x1b,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_no_credit_cycles,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_no_credit_cycles),
    },
    {
        .name = "UNC_M2_TXC_BL_NO_CREDIT_STALLED",
        .code = 0x1c,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_no_credit_stalled,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_no_credit_stalled),
    },
    {
        .name = "UNC_M2_TXC_BL_OCCUPANCY",
        .code = 0x16,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txc_bl_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txc_bl_occupancy),
    },
    {
        .name = "UNC_M2_TXR_HORZ_ADS_USED",
        .code = 0x9d,
        .desc = "Number of packets using the Horizontal Anti-Deadlock Slot, broken down "
                "by ring type and CMS Agent.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_ads_used),
    },
    {
        .name = "UNC_M2_TXR_HORZ_BYPASS",
        .code = 0x9f,
        .desc = "Number of packets bypassing the Horizontal Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_bypass),
    },
    {
        .name = "UNC_M2_TXR_HORZ_CYCLES_FULL",
        .code = 0x96,
        .desc =
            "Cycles the Transgress buffers in the Common Mesh Stop are Full.  The egress "
            "is used to queue up requests destined for the Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_cycles_full),
    },
    {
        .name = "UNC_M2_TXR_HORZ_CYCLES_NE",
        .code = 0x97,
        .desc = "Cycles the Transgress buffers in the Common Mesh Stop are Not-Empty.  "
                "The egress is used to queue up requests destined for the Horizontal "
                "Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_cycles_ne),
    },
    {
        .name = "UNC_M2_TXR_HORZ_INSERTS",
        .code = 0x95,
        .desc = "Number of allocations into the Transgress buffers in the Common Mesh "
                "Stop  The egress is used to queue up requests destined for the "
                "Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_inserts),
    },
    {
        .name = "UNC_M2_TXR_HORZ_NACK",
        .code = 0x99,
        .desc = "Counts number of Egress packets NACKed on to the Horizontal Rinng",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_nack),
    },
    {
        .name = "UNC_M2_TXR_HORZ_OCCUPANCY",
        .code = 0x94,
        .desc = "Occupancy event for the Transgress buffers in the Common Mesh Stop  The "
                "egress is used to queue up requests destined for the Horizontal Ring on "
                "the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_occupancy),
    },
    {
        .name = "UNC_M2_TXR_HORZ_STARVED",
        .code = 0x9b,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Transgress buffer cannot send a transaction onto the Horizontal ring "
                "for a long period of time.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_horz_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_horz_starved),
    },
    {
        .name = "UNC_M2_TXR_VERT_ADS_USED",
        .code = 0x9c,
        .desc = "Number of packets using the Vertical Anti-Deadlock Slot, broken down by "
                "ring type and CMS Agent.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_ads_used),
    },
    {
        .name = "UNC_M2_TXR_VERT_BYPASS",
        .code = 0x9e,
        .desc = "Number of packets bypassing the Vertical Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_bypass),
    },
    {
        .name = "UNC_M2_TXR_VERT_CYCLES_FULL",
        .code = 0x92,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Full.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_cycles_full),
    },
    {
        .name = "UNC_M2_TXR_VERT_CYCLES_NE",
        .code = 0x93,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Empty.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_cycles_ne),
    },
    {
        .name = "UNC_M2_TXR_VERT_INSERTS",
        .code = 0x91,
        .desc = "Number of allocations into the Common Mesh Stop Egress.  The Egress is "
                "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_inserts),
    },
    {
        .name = "UNC_M2_TXR_VERT_NACK",
        .code = 0x98,
        .desc = "Counts number of Egress packets NACKed on to the Vertical Rinng",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_nack),
    },
    {
        .name = "UNC_M2_TXR_VERT_OCCUPANCY",
        .code = 0x90,
        .desc =
            "Occupancy event for the Egress buffers in the Common Mesh Stop  The egress "
            "is used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_occupancy),
    },
    {
        .name = "UNC_M2_TXR_VERT_STARVED",
        .code = 0x9a,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Egress cannot send a transaction onto the Vertical ring for a long "
                "period of time.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_txr_vert_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_txr_vert_starved),
    },
    {
        .name = "UNC_M2_VERT_RING_AD_IN_USE",
        .code = 0xa6,
        .desc = "Counts the number of cycles that the Vertical AD ring is being used at "
                "this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.  We really have two rings  -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_vert_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_vert_ring_ad_in_use),
    },
    {
        .name = "UNC_M2_VERT_RING_AK_IN_USE",
        .code = 0xa8,
        .desc = "Counts the number of cycles that the Vertical AK ring is being used at "
                "this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.We really have two rings in -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_vert_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_vert_ring_ak_in_use),
    },
    {
        .name = "UNC_M2_VERT_RING_BL_IN_USE",
        .code = 0xaa,
        .desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this "
            "ring stop.  This includes when packets are passing by and when packets are "
            "being sunk, but does not include when packets are being sent from  the ring "
            "stop.We really have two rings -- a clockwise ring and a counter-clockwise "
            "ring.  On the left side of the ring, the UP direction is on the clockwise "
            "ring and DN is on the counter-clockwise ring.  On the right side of the "
            "ring, this is reversed.  The first half of the CBos are on the left side of "
            "the ring, and the 2nd half are on the right side of the ring.  In other "
            "words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo "
            "2 UP AD because they are on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_vert_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_vert_ring_bl_in_use),
    },
    {
        .name = "UNC_M2_VERT_RING_IV_IN_USE",
        .code = 0xac,
        .desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this "
            "ring stop.  This includes when packets are passing by and when packets are "
            "being sunk, but does not include when packets are being sent from the ring "
            "stop.  There is only 1 IV ring.  Therefore, if one wants to monitor the "
            "Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd "
            "ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_vert_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_vert_ring_iv_in_use),
    },
    {
        .name = "UNC_M2_WPQ_CYCLES_REG_CREDITS",
        .code = 0x4d,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_wpq_cycles_reg_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_wpq_cycles_reg_credits),
    },
    {
        .name = "UNC_M2_WPQ_CYCLES_SPEC_CREDITS",
        .code = 0x4e,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_wpq_cycles_spec_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_wpq_cycles_spec_credits),
    },
    {
        .name = "UNC_M2_WRITE_TRACKER_CYCLES_FULL",
        .code = 0x4a,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_write_tracker_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_write_tracker_cycles_full),
    },
    {
        .name = "UNC_M2_WRITE_TRACKER_CYCLES_NE",
        .code = 0x4b,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_write_tracker_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_write_tracker_cycles_ne),
    },
    {
        .name = "UNC_M2_WRITE_TRACKER_INSERTS",
        .code = 0x61,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_write_tracker_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_write_tracker_inserts),
    },
    {
        .name = "UNC_M2_WRITE_TRACKER_OCCUPANCY",
        .code = 0x60,
        .desc = "TBD",
        .modmsk = SKX_UNC_M2M_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m2m_write_tracker_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m2m_write_tracker_occupancy),
    },
};
