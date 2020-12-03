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
 * PMU: skx_unc_m3upi
 */

static intel_x86_umask_t skx_unc_m3_ag0_ad_crd_acquired[] = {
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

static intel_x86_umask_t skx_unc_m3_ag0_ad_crd_occupancy[] = {
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

static intel_x86_umask_t skx_unc_m3_cha_ad_credits_empty[] = {
    {
        .uname = "REQ",
        .ucode = 0x400,
        .udesc = "CBox AD Credits Empty -- Requests",
    },
    {
        .uname = "SNP",
        .ucode = 0x800,
        .udesc = "CBox AD Credits Empty -- Snoops",
    },
    {
        .uname = "VNA",
        .ucode = 0x100,
        .udesc = "CBox AD Credits Empty -- VNA Messages",
    },
    {
        .uname = "WB",
        .ucode = 0x200,
        .udesc = "CBox AD Credits Empty -- Writebacks",
    },
};

static intel_x86_umask_t skx_unc_m3_egress_ordering[] = {
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

static intel_x86_umask_t skx_unc_m3_fast_asserted[] = {
    {
        .uname = "HORZ",
        .ucode = 0x200,
        .udesc = "FaST wire asserted -- Horizontal",
    },
    {
        .uname = "VERT",
        .ucode = 0x100,
        .udesc = "FaST wire asserted -- Vertical",
    },
};

static intel_x86_umask_t skx_unc_m3_horz_ring_ad_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_horz_ring_ak_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_horz_ring_bl_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_horz_ring_iv_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_m2_bl_credits_empty[] = {
    {
        .uname = "IIO0_IIO1_NCB",
        .ucode = 0x100,
        .udesc = "M2 BL Credits Empty -- IIO0 and IIO1 share the same ring destination. "
                 "(1 VN0 credit only)",
    },
    {
        .uname = "IIO2_NCB",
        .ucode = 0x200,
        .udesc = "M2 BL Credits Empty -- IIO2",
    },
    {
        .uname = "IIO3_NCB",
        .ucode = 0x400,
        .udesc = "M2 BL Credits Empty -- IIO3",
    },
    {
        .uname = "IIO4_NCB",
        .ucode = 0x800,
        .udesc = "M2 BL Credits Empty -- IIO4",
    },
    {
        .uname = "IIO5_NCB",
        .ucode = 0x1000,
        .udesc = "M2 BL Credits Empty -- IIO5",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "M2 BL Credits Empty -- All IIO targets for NCS are in single mask. ORs "
                 "them together",
    },
    {
        .uname = "NCS_SEL",
        .ucode = 0x4000,
        .udesc = "M2 BL Credits Empty -- Selected M2p BL NCS credits",
    },
};

static intel_x86_umask_t skx_unc_m3_multi_slot_rcvd[] = {
    {
        .uname = "AD_SLOT0",
        .ucode = 0x100,
        .udesc = "Multi Slot Flit Received -- AD - Slot 0",
    },
    {
        .uname = "AD_SLOT1",
        .ucode = 0x200,
        .udesc = "Multi Slot Flit Received -- AD - Slot 1",
    },
    {
        .uname = "AD_SLOT2",
        .ucode = 0x400,
        .udesc = "Multi Slot Flit Received -- AD - Slot 2",
    },
    {
        .uname = "AK_SLOT0",
        .ucode = 0x1000,
        .udesc = "Multi Slot Flit Received -- AK - Slot 0",
    },
    {
        .uname = "AK_SLOT2",
        .ucode = 0x2000,
        .udesc = "Multi Slot Flit Received -- AK - Slot 2",
    },
    {
        .uname = "BL_SLOT0",
        .ucode = 0x800,
        .udesc = "Multi Slot Flit Received -- BL - Slot 0",
    },
};

static intel_x86_umask_t skx_unc_m3_ring_bounces_horz[] = {
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

static intel_x86_umask_t skx_unc_m3_ring_bounces_vert[] = {
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

static intel_x86_umask_t skx_unc_m3_ring_sink_starved_horz[] = {
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

static intel_x86_umask_t skx_unc_m3_ring_sink_starved_vert[] = {
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

static intel_x86_umask_t skx_unc_m3_rxc_arb_lost_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "Lost Arb for VN0 -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "Lost Arb for VN0 -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "Lost Arb for VN0 -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "Lost Arb for VN0 -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "Lost Arb for VN0 -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "Lost Arb for VN0 -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "Lost Arb for VN0 -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_lost_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "Lost Arb for VN1 -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "Lost Arb for VN1 -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "Lost Arb for VN1 -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "Lost Arb for VN1 -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "Lost Arb for VN1 -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "Lost Arb for VN1 -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "Lost Arb for VN1 -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_misc[] = {
    {
        .uname = "ADBL_PARALLEL_WIN",
        .ucode = 0x4000,
        .udesc = "Arb Miscellaneous -- AD, BL Parallel Win",
    },
    {
        .uname = "NO_PROG_AD_VN0",
        .ucode = 0x400,
        .udesc = "Arb Miscellaneous -- No Progress on Pending AD VN0",
    },
    {
        .uname = "NO_PROG_AD_VN1",
        .ucode = 0x800,
        .udesc = "Arb Miscellaneous -- No Progress on Pending AD VN1",
    },
    {
        .uname = "NO_PROG_BL_VN0",
        .ucode = 0x1000,
        .udesc = "Arb Miscellaneous -- No Progress on Pending BL VN0",
    },
    {
        .uname = "NO_PROG_BL_VN1",
        .ucode = 0x2000,
        .udesc = "Arb Miscellaneous -- No Progress on Pending BL VN1",
    },
    {
        .uname = "PAR_BIAS_VN0",
        .ucode = 0x100,
        .udesc = "Arb Miscellaneous -- Parallel Bias to VN0",
    },
    {
        .uname = "PAR_BIAS_VN1",
        .ucode = 0x200,
        .udesc = "Arb Miscellaneous -- Parallel Bias to VN1",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_noad_req_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "Cant Arb for VN0 -- REQ on AAD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "Cant Arb for VN0 -- RSP on AAD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "Cant Arb for VN0 -- SNP on AAD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "Cant Arb for VN0 -- NCB on BBL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "Cant Arb for VN0 -- NCS on BBL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "Cant Arb for VN0 -- RSP on BBL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "Cant Arb for VN0 -- WB on BBL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_noad_req_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "Cant Arb for VN1 -- REQ on AAD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "Cant Arb for VN1 -- RSP on AAD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "Cant Arb for VN1 -- SNP on AAD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "Cant Arb for VN1 -- NCB on BBL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "Cant Arb for VN1 -- NCS on BBL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "Cant Arb for VN1 -- RSP on BBL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "Cant Arb for VN1 -- WB on BBL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_nocred_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "No Credits to Arb for VN0 -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "No Credits to Arb for VN0 -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "No Credits to Arb for VN0 -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "No Credits to Arb for VN0 -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "No Credits to Arb for VN0 -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "No Credits to Arb for VN0 -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "No Credits to Arb for VN0 -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_arb_nocred_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "No Credits to Arb for VN1 -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "No Credits to Arb for VN1 -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "No Credits to Arb for VN1 -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "No Credits to Arb for VN1 -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "No Credits to Arb for VN1 -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "No Credits to Arb for VN1 -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "No Credits to Arb for VN1 -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_bypassed[] = {
    {
        .uname = "AD_S0_BL_ARB",
        .ucode = 0x200,
        .udesc = "Ingress Queue Bypasses -- AD to Slot 0 on BL Arb",
    },
    {
        .uname = "AD_S0_IDLE",
        .ucode = 0x100,
        .udesc = "Ingress Queue Bypasses -- AD to Slot 0 on Idle",
    },
    {
        .uname = "AD_S1_BL_SLOT",
        .ucode = 0x400,
        .udesc = "Ingress Queue Bypasses -- AD + BL to Slot 1",
    },
    {
        .uname = "AD_S2_BL_SLOT",
        .ucode = 0x800,
        .udesc = "Ingress Queue Bypasses -- AD + BL to Slot 2",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_collision_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN0 message lost contest for flit -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN0 message lost contest for flit -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN0 message lost contest for flit -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN0 message lost contest for flit -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN0 message lost contest for flit -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN0 message lost contest for flit -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN0 message lost contest for flit -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_collision_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN1 message lost contest for flit -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN1 message lost contest for flit -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN1 message lost contest for flit -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN1 message lost contest for flit -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN1 message lost contest for flit -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN1 message lost contest for flit -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN1 message lost contest for flit -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_crd_misc[] = {
    {
        .uname = "ANY_BGF_FIFO",
        .ucode = 0x100,
        .udesc = "Miscellaneous Credit Events -- Any In BGF FIFO",
    },
    {
        .uname = "ANY_BGF_PATH",
        .ucode = 0x200,
        .udesc = "Miscellaneous Credit Events -- Any in BGF Path",
    },
    {
        .uname = "NO_D2K_FOR_ARB",
        .ucode = 0x400,
        .udesc = "Miscellaneous Credit Events -- No D2K For Arb",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_crd_occ[] = {
    {
        .uname = "D2K_CRD",
        .ucode = 0x1000,
        .udesc = "Credit Occupancy -- D2K Credits",
    },
    {
        .uname = "FLITS_IN_FIFO",
        .ucode = 0x200,
        .udesc = "Credit Occupancy -- Packets in BGF FIFO",
    },
    {
        .uname = "FLITS_IN_PATH",
        .ucode = 0x400,
        .udesc = "Credit Occupancy -- Packets in BGF Path",
    },
    {
        .uname = "P1P_FIFO",
        .ucode = 0x4000,
        .udesc = "Credit Occupancy -- ",
    },
    {
        .uname = "P1P_TOTAL",
        .ucode = 0x2000,
        .udesc = "Credit Occupancy -- ",
    },
    {
        .uname = "TxQ_CRD",
        .ucode = 0x800,
        .udesc = "Credit Occupancy -- Transmit Credits",
    },
    {
        .uname = "VNA_IN_USE",
        .ucode = 0x100,
        .udesc = "Credit Occupancy -- VNA In Use",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_cycles_ne_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN0 Ingress (from CMS) Queue - Cycles Not Empty -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_cycles_ne_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN1 Ingress (from CMS) Queue - Cycles Not Empty -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flits_data_not_sent[] = {
    {
        .uname = "ALL",
        .ucode = 0x100,
        .udesc = "Data Flit Not Sent -- All",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "NO_BGF",
        .ucode = 0x200,
        .udesc = "Data Flit Not Sent -- No BGF Credits",
    },
    {
        .uname = "NO_TXQ",
        .ucode = 0x400,
        .udesc = "Data Flit Not Sent -- No TxQ Credits",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flits_gen_bl[] = {
    {
        .uname = "P0_WAIT",
        .ucode = 0x100,
        .udesc = "Generating BL Data Flit Sequence -- Wait on Pump 0",
    },
    {
        .uname = "P1P_AT_LIMIT",
        .ucode = 0x1000,
        .udesc = "Generating BL Data Flit Sequence -- ",
    },
    {
        .uname = "P1P_BUSY",
        .ucode = 0x800,
        .udesc = "Generating BL Data Flit Sequence -- ",
    },
    {
        .uname = "P1P_FIFO_FULL",
        .ucode = 0x4000,
        .udesc = "Generating BL Data Flit Sequence -- ",
    },
    {
        .uname = "P1P_HOLD_P0",
        .ucode = 0x2000,
        .udesc = "Generating BL Data Flit Sequence -- ",
    },
    {
        .uname = "P1P_TO_LIMBO",
        .ucode = 0x400,
        .udesc = "Generating BL Data Flit Sequence -- ",
    },
    {
        .uname = "P1_WAIT",
        .ucode = 0x200,
        .udesc = "Generating BL Data Flit Sequence -- Wait on Pump 1",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flits_sent[] = {
    {
        .uname = "1_MSG",
        .ucode = 0x100,
        .udesc = "Sent Header Flit -- One Message",
    },
    {
        .uname = "1_MSG_VNX",
        .ucode = 0x800,
        .udesc = "Sent Header Flit -- One Message in non-VNA",
    },
    {
        .uname = "2_MSGS",
        .ucode = 0x200,
        .udesc = "Sent Header Flit -- Two Messages",
    },
    {
        .uname = "3_MSGS",
        .ucode = 0x400,
        .udesc = "Sent Header Flit -- Three Messages",
    },
    {
        .uname = "SLOTS_1",
        .ucode = 0x1000,
        .udesc = "Sent Header Flit -- ",
    },
    {
        .uname = "SLOTS_2",
        .ucode = 0x2000,
        .udesc = "Sent Header Flit -- ",
    },
    {
        .uname = "SLOTS_3",
        .ucode = 0x4000,
        .udesc = "Sent Header Flit -- ",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flits_slot_bl[] = {
    {
        .uname = "ALL",
        .ucode = 0x100,
        .udesc = "Slotting BL Message Into Header Flit -- All",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "NEED_DATA",
        .ucode = 0x200,
        .udesc = "Slotting BL Message Into Header Flit -- Needs Data Flit",
    },
    {
        .uname = "P0_WAIT",
        .ucode = 0x400,
        .udesc = "Slotting BL Message Into Header Flit -- Wait on Pump 0",
    },
    {
        .uname = "P1_NOT_REQ",
        .ucode = 0x1000,
        .udesc = "Slotting BL Message Into Header Flit -- Dont Need Pump  1",
    },
    {
        .uname = "P1_NOT_REQ_BUT_BUBBLE",
        .ucode = 0x2000,
        .udesc = "Slotting BL Message Into Header Flit -- Dont Need Pump 1 - Bubblle",
    },
    {
        .uname = "P1_NOT_REQ_NOT_AVAIL",
        .ucode = 0x4000,
        .udesc = "Slotting BL Message Into Header Flit -- Dont Need Pump 1 - Not Avaiil",
    },
    {
        .uname = "P1_WAIT",
        .ucode = 0x800,
        .udesc = "Slotting BL Message Into Header Flit -- Wait on Pump 1",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flit_gen_hdr1[] = {
    {
        .uname = "ACCUM",
        .ucode = 0x100,
        .udesc = "Flit Gen - Header 1 -- Acumullate",
    },
    {
        .uname = "ACCUM_READ",
        .ucode = 0x200,
        .udesc = "Flit Gen - Header 1 -- Accumulate Ready",
    },
    {
        .uname = "ACCUM_WASTED",
        .ucode = 0x400,
        .udesc = "Flit Gen - Header 1 -- Accumulate Wasted",
    },
    {
        .uname = "AHEAD_BLOCKED",
        .ucode = 0x800,
        .udesc = "Flit Gen - Header 1 -- Run-Ahead - Blocked",
    },
    {
        .uname = "AHEAD_MSG",
        .ucode = 0x1000,
        .udesc = "Flit Gen - Header 1 -- Run-Ahead - Message",
    },
    {
        .uname = "PAR",
        .ucode = 0x2000,
        .udesc = "Flit Gen - Header 1 -- Parallel Ok",
    },
    {
        .uname = "PAR_FLIT",
        .ucode = 0x8000,
        .udesc = "Flit Gen - Header 1 -- Parallel Flit Finished",
    },
    {
        .uname = "PAR_MSG",
        .ucode = 0x4000,
        .udesc = "Flit Gen - Header 1 -- Parallel Message",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flit_gen_hdr2[] = {
    {
        .uname = "RMSTALL",
        .ucode = 0x100,
        .udesc = "Flit Gen - Header 2 -- Rate-matching Stall",
    },
    {
        .uname = "RMSTALL_NOMSG",
        .ucode = 0x200,
        .udesc = "Flit Gen - Header 2 -- Rate-matching Stall - No Message",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_flit_not_sent[] = {
    {
        .uname = "ALL",
        .ucode = 0x100,
        .udesc = "Header Not Sent -- All",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "NO_BGF_CRD",
        .ucode = 0x200,
        .udesc = "Header Not Sent -- No BGF Credits",
    },
    {
        .uname = "NO_BGF_NO_MSG",
        .ucode = 0x800,
        .udesc = "Header Not Sent -- No BGF Credits + No Extra Message Slotted",
    },
    {
        .uname = "NO_TXQ_CRD",
        .ucode = 0x400,
        .udesc = "Header Not Sent -- No TxQ Credits",
    },
    {
        .uname = "NO_TXQ_NO_MSG",
        .ucode = 0x1000,
        .udesc = "Header Not Sent -- No TxQ Credits + No Extra Message Slotted",
    },
    {
        .uname = "ONE_TAKEN",
        .ucode = 0x2000,
        .udesc = "Header Not Sent -- Sent - One Slot Taken",
    },
    {
        .uname = "THREE_TAKEN",
        .ucode = 0x8000,
        .udesc = "Header Not Sent -- Sent - Three Slots Taken",
    },
    {
        .uname = "TWO_TAKEN",
        .ucode = 0x4000,
        .udesc = "Header Not Sent -- Sent - Two Slots Taken",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_held[] = {
    {
        .uname = "CANT_SLOT_AD",
        .ucode = 0x4000,
        .udesc = "Message Held -- Cant Slot AAD",
    },
    {
        .uname = "CANT_SLOT_BL",
        .ucode = 0x8000,
        .udesc = "Message Held -- Cant Slot BBL",
    },
    {
        .uname = "PARALLEL_AD_LOST",
        .ucode = 0x1000,
        .udesc = "Message Held -- Parallel AD Lost",
    },
    {
        .uname = "PARALLEL_ATTEMPT",
        .ucode = 0x400,
        .udesc = "Message Held -- Parallel Attempt",
    },
    {
        .uname = "PARALLEL_BL_LOST",
        .ucode = 0x2000,
        .udesc = "Message Held -- Parallel BL Lost",
    },
    {
        .uname = "PARALLEL_SUCCESS",
        .ucode = 0x800,
        .udesc = "Message Held -- Parallel Success",
    },
    {
        .uname = "VN0",
        .ucode = 0x100,
        .udesc = "Message Held -- VN0",
    },
    {
        .uname = "VN1",
        .ucode = 0x200,
        .udesc = "Message Held -- VN1",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_inserts_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN0 Ingress (from CMS) Queue - Inserts -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_inserts_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN1 Ingress (from CMS) Queue - Inserts -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_occupancy_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN0 Ingress (from CMS) Queue - Occupancy -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_occupancy_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- REQ on AD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- RSP on AD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- SNP on AD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- NCB on BL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- NCS on BL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- RSP on BL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN1 Ingress (from CMS) Queue - Occupancy -- WB on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_packing_miss_vn0[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN0 message cant slot into flit -- REQ on AAD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN0 message cant slot into flit -- RSP on AAD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN0 message cant slot into flit -- SNP on AAD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN0 message cant slot into flit -- NCB on BBL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN0 message cant slot into flit -- NCS on BBL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN0 message cant slot into flit -- RSP on BBL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN0 message cant slot into flit -- WB on BBL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_packing_miss_vn1[] = {
    {
        .uname = "AD_REQ",
        .ucode = 0x100,
        .udesc = "VN1 message cant slot into flit -- REQ on AAD",
    },
    {
        .uname = "AD_RSP",
        .ucode = 0x400,
        .udesc = "VN1 message cant slot into flit -- RSP on AAD",
    },
    {
        .uname = "AD_SNP",
        .ucode = 0x200,
        .udesc = "VN1 message cant slot into flit -- SNP on AAD",
    },
    {
        .uname = "BL_NCB",
        .ucode = 0x2000,
        .udesc = "VN1 message cant slot into flit -- NCB on BBL",
    },
    {
        .uname = "BL_NCS",
        .ucode = 0x4000,
        .udesc = "VN1 message cant slot into flit -- NCS on BBL",
    },
    {
        .uname = "BL_RSP",
        .ucode = 0x800,
        .udesc = "VN1 message cant slot into flit -- RSP on BBL",
    },
    {
        .uname = "BL_WB",
        .ucode = 0x1000,
        .udesc = "VN1 message cant slot into flit -- WB on BBL",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_smi3_pftch[] = {
    {
        .uname = "ARB_LOST",
        .ucode = 0x200,
        .udesc = "SMI3 Prefetch Messages -- Lost Arbitration",
    },
    {
        .uname = "ARRIVED",
        .ucode = 0x100,
        .udesc = "SMI3 Prefetch Messages -- Arrived",
    },
    {
        .uname = "DROP_OLD",
        .ucode = 0x800,
        .udesc = "SMI3 Prefetch Messages -- Dropped - Old",
    },
    {
        .uname = "DROP_WRAP",
        .ucode = 0x1000,
        .udesc = "SMI3 Prefetch Messages -- Dropped - Wrap",
    },
    {
        .uname = "SLOTTED",
        .ucode = 0x400,
        .udesc = "SMI3 Prefetch Messages -- Slotted",
    },
};

static intel_x86_umask_t skx_unc_m3_rxc_vna_crd[] = {
    {
        .uname = "ANY_IN_USE",
        .ucode = 0x2000,
        .udesc = "Remote VNA Credits -- Any In Use",
    },
    {
        .uname = "CORRECTED",
        .ucode = 0x200,
        .udesc = "Remote VNA Credits -- Corrected",
    },
    {
        .uname = "LT1",
        .ucode = 0x400,
        .udesc = "Remote VNA Credits -- Level < 1",
    },
    {
        .uname = "LT4",
        .ucode = 0x800,
        .udesc = "Remote VNA Credits -- Level < 4",
    },
    {
        .uname = "LT5",
        .ucode = 0x1000,
        .udesc = "Remote VNA Credits -- Level < 5",
    },
    {
        .uname = "USED",
        .ucode = 0x100,
        .udesc = "Remote VNA Credits -- Used",
    },
};

static intel_x86_umask_t skx_unc_m3_rxr_busy_starved[] = {
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

static intel_x86_umask_t skx_unc_m3_rxr_bypass[] = {
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

static intel_x86_umask_t skx_unc_m3_rxr_crd_starved[] = {
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

static intel_x86_umask_t skx_unc_m3_rxr_inserts[] = {
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

static intel_x86_umask_t skx_unc_m3_rxr_occupancy[] = {
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

static intel_x86_umask_t skx_unc_m3_stall_no_txr_horz_crd_ad_ag0[] = {
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

static intel_x86_umask_t skx_unc_m3_stall_no_txr_horz_crd_ad_ag1[] = {
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

static intel_x86_umask_t skx_unc_m3_stall_no_txr_horz_crd_bl_ag0[] = {
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

static intel_x86_umask_t skx_unc_m3_stall_no_txr_horz_crd_bl_ag1[] = {
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

static intel_x86_umask_t skx_unc_m3_txc_ad_arb_fail[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "Failed ARB for AD -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "Failed ARB for AD -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "Failed ARB for AD -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "Failed ARB for AD -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "Failed ARB for AD -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "Failed ARB for AD -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "Failed ARB for AD -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "Failed ARB for AD -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_flq_bypass[] = {
    {
        .uname = "AD_SLOT0",
        .ucode = 0x100,
        .udesc = "AD FlowQ Bypass -- ",
    },
    {
        .uname = "AD_SLOT1",
        .ucode = 0x200,
        .udesc = "AD FlowQ Bypass -- ",
    },
    {
        .uname = "AD_SLOT2",
        .ucode = 0x400,
        .udesc = "AD FlowQ Bypass -- ",
    },
    {
        .uname = "BL_EARLY_RSP",
        .ucode = 0x800,
        .udesc = "AD FlowQ Bypass -- ",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_flq_cycles_ne[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "AD Flow Q Not Empty -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "AD Flow Q Not Empty -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "AD Flow Q Not Empty -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "AD Flow Q Not Empty -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "AD Flow Q Not Empty -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "AD Flow Q Not Empty -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "AD Flow Q Not Empty -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "AD Flow Q Not Empty -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_flq_inserts[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "AD Flow Q Inserts -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "AD Flow Q Inserts -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "AD Flow Q Inserts -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "AD Flow Q Inserts -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "AD Flow Q Inserts -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "AD Flow Q Inserts -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "AD Flow Q Inserts -- VN1 SNP Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_flq_occupancy[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "AD Flow Q Occupancy -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "AD Flow Q Occupancy -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "AD Flow Q Occupancy -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "AD Flow Q Occupancy -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "AD Flow Q Occupancy -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "AD Flow Q Occupancy -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "AD Flow Q Occupancy -- VN1 SNP Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_snpf_grp1_vn1[] = {
    {
        .uname = "VN0_CHA",
        .ucode = 0x400,
        .udesc = "Number of Snoop Targets -- CHA on VN0",
    },
    {
        .uname = "VN0_NON_IDLE",
        .ucode = 0x4000,
        .udesc = "Number of Snoop Targets -- Non Idle cycles on VN0",
    },
    {
        .uname = "VN0_PEER_UPI0",
        .ucode = 0x100,
        .udesc = "Number of Snoop Targets -- Peer UPI0 on VN0",
    },
    {
        .uname = "VN0_PEER_UPI1",
        .ucode = 0x200,
        .udesc = "Number of Snoop Targets -- Peer UPI1 on VN0",
    },
    {
        .uname = "VN1_CHA",
        .ucode = 0x2000,
        .udesc = "Number of Snoop Targets -- CHA on VN1",
    },
    {
        .uname = "VN1_NON_IDLE",
        .ucode = 0x8000,
        .udesc = "Number of Snoop Targets -- Non Idle cycles on VN1",
    },
    {
        .uname = "VN1_PEER_UPI0",
        .ucode = 0x800,
        .udesc = "Number of Snoop Targets -- Peer UPI0 on VN1",
    },
    {
        .uname = "VN1_PEER_UPI1",
        .ucode = 0x1000,
        .udesc = "Number of Snoop Targets -- Peer UPI1 on VN1",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_snpf_grp2_vn1[] = {
    {
        .uname = "VN0_SNPFP_NONSNP",
        .ucode = 0x100,
        .udesc = "Snoop Arbitration -- FlowQ Won",
    },
    {
        .uname = "VN0_SNPFP_VN2SNP",
        .ucode = 0x400,
        .udesc = "Snoop Arbitration -- FlowQ SnpF Won",
    },
    {
        .uname = "VN1_SNPFP_NONSNP",
        .ucode = 0x200,
        .udesc = "Snoop Arbitration -- FlowQ Won",
    },
    {
        .uname = "VN1_SNPFP_VN0SNP",
        .ucode = 0x800,
        .udesc = "Snoop Arbitration -- FlowQ SnpF Won",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_spec_arb_crd_avail[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "Speculative ARB for AD  -  Credit Available -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_spec_arb_new_msg[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "Speculative ARB for AD  - New Message -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "Speculative ARB for AD  - New Message -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "Speculative ARB for AD  - New Message -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "Speculative ARB for AD  - New Message -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "Speculative ARB for AD  - New Message -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "Speculative ARB for AD  - New Message -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_ad_spec_arb_no_other_pend[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "Speculative ARB for AD  - No Credit -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "Speculative ARB for AD  - No Credit -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "Speculative ARB for AD  - No Credit -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "Speculative ARB for AD  - No Credit -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "Speculative ARB for AD  - No Credit -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "Speculative ARB for AD  - No Credit -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "Speculative ARB for AD  - No Credit -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "Speculative ARB for AD  - No Credit -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_arb_fail[] = {
    {
        .uname = "VN0_NCB",
        .ucode = 0x400,
        .udesc = "Failed ARB for BL -- VN0 NCB Messages",
    },
    {
        .uname = "VN0_NCS",
        .ucode = 0x800,
        .udesc = "Failed ARB for BL -- VN0 NCS Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x100,
        .udesc = "Failed ARB for BL -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x200,
        .udesc = "Failed ARB for BL -- VN0 WB Messages",
    },
    {
        .uname = "VN1_NCB",
        .ucode = 0x4000,
        .udesc = "Failed ARB for BL -- VN1 NCS Messages",
    },
    {
        .uname = "VN1_NCS",
        .ucode = 0x8000,
        .udesc = "Failed ARB for BL -- VN1 NCB Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x1000,
        .udesc = "Failed ARB for BL -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x2000,
        .udesc = "Failed ARB for BL -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_flq_cycles_ne[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x100,
        .udesc = "BL Flow Q Not Empty -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x400,
        .udesc = "BL Flow Q Not Empty -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x200,
        .udesc = "BL Flow Q Not Empty -- VN0 SNP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "BL Flow Q Not Empty -- VN0 WB Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "BL Flow Q Not Empty -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "BL Flow Q Not Empty -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "BL Flow Q Not Empty -- VN1 SNP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x8000,
        .udesc = "BL Flow Q Not Empty -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_flq_inserts[] = {
    {
        .uname = "VN0_NCB",
        .ucode = 0x100,
        .udesc = "BL Flow Q Inserts -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_NCS",
        .ucode = 0x200,
        .udesc = "BL Flow Q Inserts -- VN0 WB Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x800,
        .udesc = "BL Flow Q Inserts -- VN0 NCS Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x400,
        .udesc = "BL Flow Q Inserts -- VN0 NCB Messages",
    },
    {
        .uname = "VN1_NCB",
        .ucode = 0x1000,
        .udesc = "BL Flow Q Inserts -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_NCS",
        .ucode = 0x2000,
        .udesc = "BL Flow Q Inserts -- VN1 WB Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x8000,
        .udesc = "BL Flow Q Inserts -- VN1_NCB Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x4000,
        .udesc = "BL Flow Q Inserts -- VN1_NCS Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_flq_occupancy[] = {
    {
        .uname = "VN0_NCB",
        .ucode = 0x400,
        .udesc = "BL Flow Q Occupancy -- VN0 NCB Messages",
    },
    {
        .uname = "VN0_NCS",
        .ucode = 0x800,
        .udesc = "BL Flow Q Occupancy -- VN0 NCS Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x100,
        .udesc = "BL Flow Q Occupancy -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x200,
        .udesc = "BL Flow Q Occupancy -- VN0 WB Messages",
    },
    {
        .uname = "VN1_NCB",
        .ucode = 0x4000,
        .udesc = "BL Flow Q Occupancy -- VN1_NCS Messages",
    },
    {
        .uname = "VN1_NCS",
        .ucode = 0x8000,
        .udesc = "BL Flow Q Occupancy -- VN1_NCB Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x1000,
        .udesc = "BL Flow Q Occupancy -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x2000,
        .udesc = "BL Flow Q Occupancy -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_spec_arb_new_msg[] = {
    {
        .uname = "VN0_NCB",
        .ucode = 0x200,
        .udesc = "Speculative ARB for BL  - New Message -- VN0 WB Messages",
    },
    {
        .uname = "VN0_NCS",
        .ucode = 0x800,
        .udesc = "Speculative ARB for BL  - New Message -- VN0 NCS Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x100,
        .udesc = "Speculative ARB for BL  - New Message -- VN0 WB Messages",
    },
    {
        .uname = "VN1_NCB",
        .ucode = 0x2000,
        .udesc = "Speculative ARB for BL  - New Message -- VN1 WB Messages",
    },
    {
        .uname = "VN1_NCS",
        .ucode = 0x8000,
        .udesc = "Speculative ARB for BL  - New Message -- VN1 NCB Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x1000,
        .udesc = "Speculative ARB for BL  - New Message -- VN1 RSP Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txc_bl_spec_arb_no_other_pend[] = {
    {
        .uname = "VN0_NCB",
        .ucode = 0x400,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN0 NCB Messages",
    },
    {
        .uname = "VN0_NCS",
        .ucode = 0x800,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN0 NCS Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x100,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x200,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN0 WB Messages",
    },
    {
        .uname = "VN1_NCB",
        .ucode = 0x4000,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN1 NCS Messages",
    },
    {
        .uname = "VN1_NCS",
        .ucode = 0x8000,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN1 NCB Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x1000,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x2000,
        .udesc = "Speculative ARB for AD Failed - No Credit -- VN1 WB Messages",
    },
};

static intel_x86_umask_t skx_unc_m3_txr_horz_ads_used[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_bypass[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_cycles_full[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_cycles_ne[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_inserts[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_nack[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_occupancy[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_horz_starved[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_ads_used[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_bypass[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_cycles_full[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_cycles_ne[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_inserts[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_nack[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_occupancy[] = {
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

static intel_x86_umask_t skx_unc_m3_txr_vert_starved[] = {
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

static intel_x86_umask_t skx_unc_m3_upi_peer_ad_credits_empty[] = {
    {
        .uname = "VN0_REQ",
        .ucode = 0x200,
        .udesc = "UPI0 AD Credits Empty -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x800,
        .udesc = "UPI0 AD Credits Empty -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_SNP",
        .ucode = 0x400,
        .udesc = "UPI0 AD Credits Empty -- VN0 SNP Messages",
    },
    {
        .uname = "VN1_REQ",
        .ucode = 0x1000,
        .udesc = "UPI0 AD Credits Empty -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x4000,
        .udesc = "UPI0 AD Credits Empty -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_SNP",
        .ucode = 0x2000,
        .udesc = "UPI0 AD Credits Empty -- VN1 SNP Messages",
    },
    {
        .uname = "VNA",
        .ucode = 0x100,
        .udesc = "UPI0 AD Credits Empty -- VNA",
    },
};

static intel_x86_umask_t skx_unc_m3_upi_peer_bl_credits_empty[] = {
    {
        .uname = "VN0_NCS_NCB",
        .ucode = 0x400,
        .udesc = "UPI0 BL Credits Empty -- VN0 RSP Messages",
    },
    {
        .uname = "VN0_RSP",
        .ucode = 0x200,
        .udesc = "UPI0 BL Credits Empty -- VN0 REQ Messages",
    },
    {
        .uname = "VN0_WB",
        .ucode = 0x800,
        .udesc = "UPI0 BL Credits Empty -- VN0 SNP Messages",
    },
    {
        .uname = "VN1_NCS_NCB",
        .ucode = 0x2000,
        .udesc = "UPI0 BL Credits Empty -- VN1 RSP Messages",
    },
    {
        .uname = "VN1_RSP",
        .ucode = 0x1000,
        .udesc = "UPI0 BL Credits Empty -- VN1 REQ Messages",
    },
    {
        .uname = "VN1_WB",
        .ucode = 0x4000,
        .udesc = "UPI0 BL Credits Empty -- VN1 SNP Messages",
    },
    {
        .uname = "VNA",
        .ucode = 0x100,
        .udesc = "UPI0 BL Credits Empty -- VNA",
    },
};

static intel_x86_umask_t skx_unc_m3_vert_ring_ad_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_vert_ring_ak_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_vert_ring_bl_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_vert_ring_iv_in_use[] = {
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

static intel_x86_umask_t skx_unc_m3_vn0_credits_used[] = {
    {
        .uname = "NCB",
        .ucode = 0x1000,
        .udesc = "VN0 Credit Used -- WB on BL",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "VN0 Credit Used -- NCB on BL",
    },
    {
        .uname = "REQ",
        .ucode = 0x100,
        .udesc = "VN0 Credit Used -- REQ on AD",
    },
    {
        .uname = "RSP",
        .ucode = 0x400,
        .udesc = "VN0 Credit Used -- RSP on AD",
    },
    {
        .uname = "SNP",
        .ucode = 0x200,
        .udesc = "VN0 Credit Used -- SNP on AD",
    },
    {
        .uname = "WB",
        .ucode = 0x800,
        .udesc = "VN0 Credit Used -- RSP on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_vn0_no_credits[] = {
    {
        .uname = "NCB",
        .ucode = 0x1000,
        .udesc = "VN0 No Credits -- WB on BL",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "VN0 No Credits -- NCB on BL",
    },
    {
        .uname = "REQ",
        .ucode = 0x100,
        .udesc = "VN0 No Credits -- REQ on AD",
    },
    {
        .uname = "RSP",
        .ucode = 0x400,
        .udesc = "VN0 No Credits -- RSP on AD",
    },
    {
        .uname = "SNP",
        .ucode = 0x200,
        .udesc = "VN0 No Credits -- SNP on AD",
    },
    {
        .uname = "WB",
        .ucode = 0x800,
        .udesc = "VN0 No Credits -- RSP on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_vn1_credits_used[] = {
    {
        .uname = "NCB",
        .ucode = 0x1000,
        .udesc = "VN1 Credit Used -- WB on BL",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "VN1 Credit Used -- NCB on BL",
    },
    {
        .uname = "REQ",
        .ucode = 0x100,
        .udesc = "VN1 Credit Used -- REQ on AD",
    },
    {
        .uname = "RSP",
        .ucode = 0x400,
        .udesc = "VN1 Credit Used -- RSP on AD",
    },
    {
        .uname = "SNP",
        .ucode = 0x200,
        .udesc = "VN1 Credit Used -- SNP on AD",
    },
    {
        .uname = "WB",
        .ucode = 0x800,
        .udesc = "VN1 Credit Used -- RSP on BL",
    },
};

static intel_x86_umask_t skx_unc_m3_vn1_no_credits[] = {
    {
        .uname = "NCB",
        .ucode = 0x1000,
        .udesc = "VN1 No Credits -- WB on BL",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "VN1 No Credits -- NCB on BL",
    },
    {
        .uname = "REQ",
        .ucode = 0x100,
        .udesc = "VN1 No Credits -- REQ on AD",
    },
    {
        .uname = "RSP",
        .ucode = 0x400,
        .udesc = "VN1 No Credits -- RSP on AD",
    },
    {
        .uname = "SNP",
        .ucode = 0x200,
        .udesc = "VN1 No Credits -- SNP on AD",
    },
    {
        .uname = "WB",
        .ucode = 0x800,
        .udesc = "VN1 No Credits -- RSP on BL",
    },
};

static intel_x86_entry_t intel_skx_unc_m3_pe[] = {
    {
        .name = "UNC_M3_AG0_AD_CRD_ACQUIRED",
        .code = 0x80,
        .desc =
            "Number of CMS Agent 0 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M3_AG0_AD_CRD_OCCUPANCY",
        .code = 0x82,
        .desc =
            "Number of CMS Agent 0 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M3_AG0_BL_CRD_ACQUIRED",
        .code = 0x88,
        .desc =
            "Number of CMS Agent 0 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_acquired, /* shred */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M3_AG0_BL_CRD_OCCUPANCY",
        .code = 0x8a,
        .desc =
            "Number of CMS Agent 0 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M3_AG1_AD_CRD_ACQUIRED",
        .code = 0x84,
        .desc =
            "Number of CMS Agent 1 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_acquired, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M3_AG1_AD_CRD_OCCUPANCY",
        .code = 0x86,
        .desc =
            "Number of CMS Agent 1 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M3_AG1_BL_CRD_OCCUPANCY",
        .code = 0x8e,
        .desc =
            "Number of CMS Agent 1 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_occupancy, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_M3_AG1_BL_CREDITS_ACQUIRED",
        .code = 0x8c,
        .desc =
            "Number of CMS Agent 1 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ag0_ad_crd_acquired, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_M3_CHA_AD_CREDITS_EMPTY",
        .code = 0x22,
        .desc =
            "No credits available to send to Cbox on the AD Ring (covers higher CBoxes)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_cha_ad_credits_empty,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_cha_ad_credits_empty),
    },
    {
        .name = "UNC_M3_CLOCKTICKS",
        .code = 0x1,
        .desc = "Counts the number of uclks in the M3 uclk domain.  This could be "
                "slightly different than the count in the Ubox because of enable/freeze "
                "delays.  However, because the M3 is close to the Ubox, they generally "
                "should not diverge by more than a handful of cycles.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_CMS_CLOCKTICKS",
        .code = 0xc0,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_D2C_SENT",
        .code = 0x2b,
        .desc = "Count cases BL sends direct to core",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_D2U_SENT",
        .code = 0x2a,
        .desc = "Cases where SMI3 sends D2U command",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_EGRESS_ORDERING",
        .code = 0xae,
        .desc = "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO "
                "Ordering requirements",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_egress_ordering,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_egress_ordering),
    },
    {
        .name = "UNC_M3_FAST_ASSERTED",
        .code = 0xa5,
        .desc = "Counts the number of cycles either the local or incoming distress "
                "signals are asserted.  Incoming distress includes up, dn and across.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_fast_asserted,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_fast_asserted),
    },
    {
        .name = "UNC_M3_HORZ_RING_AD_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_horz_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_horz_ring_ad_in_use),
    },
    {
        .name = "UNC_M3_HORZ_RING_AK_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_horz_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_horz_ring_ak_in_use),
    },
    {
        .name = "UNC_M3_HORZ_RING_BL_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_horz_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_horz_ring_bl_in_use),
    },
    {
        .name = "UNC_M3_HORZ_RING_IV_IN_USE",
        .code = 0xad,
        .desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at "
            "this ring stop.  This includes when packets are passing by and when packets "
            "are being sunk, but does not include when packets are being sent from the "
            "ring stop.  There is only 1 IV ring.  Therefore, if one wants to monitor "
            "the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the "
            "Odd ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_horz_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_horz_ring_iv_in_use),
    },
    {
        .name = "UNC_M3_M2_BL_CREDITS_EMPTY",
        .code = 0x23,
        .desc = "No vn0 and vna credits available to send to M2",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_m2_bl_credits_empty,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_m2_bl_credits_empty),
    },
    {
        .name = "UNC_M3_MULTI_SLOT_RCVD",
        .code = 0x3e,
        .desc = "Multi slot flit received - S0, S1 and/or S2 populated (can use AK S0/S1 "
                "masks for AK allocations)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_multi_slot_rcvd,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_multi_slot_rcvd),
    },
    {
        .name = "UNC_M3_RING_BOUNCES_HORZ",
        .code = 0xa1,
        .desc = "Number of cycles incoming messages from the Horizontal ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ring_bounces_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ring_bounces_horz),
    },
    {
        .name = "UNC_M3_RING_BOUNCES_VERT",
        .code = 0xa0,
        .desc = "Number of cycles incoming messages from the Vertical ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ring_bounces_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ring_bounces_vert),
    },
    {
        .name = "UNC_M3_RING_SINK_STARVED_HORZ",
        .code = 0xa3,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ring_sink_starved_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ring_sink_starved_horz),
    },
    {
        .name = "UNC_M3_RING_SINK_STARVED_VERT",
        .code = 0xa2,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_ring_sink_starved_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_ring_sink_starved_vert),
    },
    {
        .name = "UNC_M3_RING_SRC_THRTL",
        .code = 0xa4,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_RXC_ARB_LOST_VN0",
        .code = 0x4b,
        .desc = "VN0 message requested but lost arbitration",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_lost_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_lost_vn0),
    },
    {
        .name = "UNC_M3_RXC_ARB_LOST_VN1",
        .code = 0x4c,
        .desc = "VN1 message requested but lost arbitration",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_lost_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_lost_vn1),
    },
    {
        .name = "UNC_M3_RXC_ARB_MISC",
        .code = 0x4d,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_misc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_misc),
    },
    {
        .name = "UNC_M3_RXC_ARB_NOAD_REQ_VN0",
        .code = 0x49,
        .desc = "VN0 message was not able to request arbitration while some other "
                "message won arbitration",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_noad_req_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_noad_req_vn0),
    },
    {
        .name = "UNC_M3_RXC_ARB_NOAD_REQ_VN1",
        .code = 0x4a,
        .desc = "VN1 message was not able to request arbitration while some other "
                "message won arbitration",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_noad_req_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_noad_req_vn1),
    },
    {
        .name = "UNC_M3_RXC_ARB_NOCRED_VN0",
        .code = 0x47,
        .desc = "VN0 message is blocked from requesting arbitration due to lack of "
                "remote UPI credits",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_nocred_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_nocred_vn0),
    },
    {
        .name = "UNC_M3_RXC_ARB_NOCRED_VN1",
        .code = 0x48,
        .desc = "VN1 message is blocked from requesting arbitration due to lack of "
                "remote UPI credits",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_arb_nocred_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_arb_nocred_vn1),
    },
    {
        .name = "UNC_M3_RXC_BYPASSED",
        .code = 0x40,
        .desc = "Number ot times message is bypassed around the Ingress Queue",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_bypassed,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_bypassed),
    },
    {
        .name = "UNC_M3_RXC_COLLISION_VN0",
        .code = 0x50,
        .desc = "Count cases where Ingress VN0 packets lost the contest for Flit Slot 0.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_collision_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_collision_vn0),
    },
    {
        .name = "UNC_M3_RXC_COLLISION_VN1",
        .code = 0x51,
        .desc = "Count cases where Ingress VN1 packets lost the contest for Flit Slot 0.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_collision_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_collision_vn1),
    },
    {
        .name = "UNC_M3_RXC_CRD_MISC",
        .code = 0x60,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_crd_misc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_crd_misc),
    },
    {
        .name = "UNC_M3_RXC_CRD_OCC",
        .code = 0x61,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_crd_occ,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_crd_occ),
    },
    {
        .name = "UNC_M3_RXC_CYCLES_NE_VN0",
        .code = 0x43,
        .desc = "Counts the number of cycles when the UPI Ingress is not empty.  This "
                "tracks one of the three rings that are used by the UPI agent.  This can "
                "be used in conjunction with the UPI Ingress Occupancy Accumulator event "
                "in order to calculate average queue occupancy.  Multiple ingress "
                "buffers can be tracked at a given time using multiple counters.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_cycles_ne_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_cycles_ne_vn0),
    },
    {
        .name = "UNC_M3_RXC_CYCLES_NE_VN1",
        .code = 0x44,
        .desc = "Counts the number of allocations into the UPI VN1  Ingress.  This "
                "tracks one of the three rings that are used by the UPI agent.  This can "
                "be used in conjunction with the UPI VN1  Ingress Occupancy Accumulator "
                "event in order to calculate average queue latency.  Multiple ingress "
                "buffers can be tracked at a given time using multiple counters.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_cycles_ne_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_cycles_ne_vn1),
    },
    {
        .name = "UNC_M3_RXC_FLITS_DATA_NOT_SENT",
        .code = 0x57,
        .desc = "Data flit is ready for transmission but could not be sent",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flits_data_not_sent,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flits_data_not_sent),
    },
    {
        .name = "UNC_M3_RXC_FLITS_GEN_BL",
        .code = 0x59,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flits_gen_bl,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flits_gen_bl),
    },
    {
        .name = "UNC_M3_RXC_FLITS_MISC",
        .code = 0x5a,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_RXC_FLITS_SENT",
        .code = 0x56,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flits_sent,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flits_sent),
    },
    {
        .name = "UNC_M3_RXC_FLITS_SLOT_BL",
        .code = 0x58,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flits_slot_bl,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flits_slot_bl),
    },
    {
        .name = "UNC_M3_RXC_FLIT_GEN_HDR1",
        .code = 0x53,
        .desc = "Events related to Header Flit Generation - Set 1",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flit_gen_hdr1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flit_gen_hdr1),
    },
    {
        .name = "UNC_M3_RXC_FLIT_GEN_HDR2",
        .code = 0x54,
        .desc = "Events related to Header Flit Generation - Set 2",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flit_gen_hdr2,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flit_gen_hdr2),
    },
    {
        .name = "UNC_M3_RXC_FLIT_NOT_SENT",
        .code = 0x55,
        .desc = "header flit is ready for transmission but could not be sent",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_flit_not_sent,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_flit_not_sent),
    },
    {
        .name = "UNC_M3_RXC_HELD",
        .code = 0x52,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_held,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_held),
    },
    {
        .name = "UNC_M3_RXC_INSERTS_VN0",
        .code = 0x41,
        .desc = "Counts the number of allocations into the UPI Ingress.  This tracks one "
                "of the three rings that are used by the UPI agent.  This can be used in "
                "conjunction with the UPI Ingress Occupancy Accumulator event in order "
                "to calculate average queue latency.  Multiple ingress buffers can be "
                "tracked at a given time using multiple counters.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_inserts_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_inserts_vn0),
    },
    {
        .name = "UNC_M3_RXC_INSERTS_VN1",
        .code = 0x42,
        .desc = "Counts the number of allocations into the UPI VN1  Ingress.  This "
                "tracks one of the three rings that are used by the UPI agent.  This can "
                "be used in conjunction with the UPI VN1  Ingress Occupancy Accumulator "
                "event in order to calculate average queue latency.  Multiple ingress "
                "buffers can be tracked at a given time using multiple counters.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_inserts_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_inserts_vn1),
    },
    {
        .name = "UNC_M3_RXC_OCCUPANCY_VN0",
        .code = 0x45,
        .desc = "Accumulates the occupancy of a given UPI VN1  Ingress queue in each "
                "cycle.  This tracks one of the three ring Ingress buffers.  This can be "
                "used with the UPI VN1  Ingress Not Empty event to calculate average "
                "occupancy or the UPI VN1  Ingress Allocations event in order to "
                "calculate average queuing latency.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_occupancy_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_occupancy_vn0),
    },
    {
        .name = "UNC_M3_RXC_OCCUPANCY_VN1",
        .code = 0x46,
        .desc = "Accumulates the occupancy of a given UPI VN1  Ingress queue in each "
                "cycle.  This tracks one of the three ring Ingress buffers.  This can be "
                "used with the UPI VN1  Ingress Not Empty event to calculate average "
                "occupancy or the UPI VN1  Ingress Allocations event in order to "
                "calculate average queuing latency.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_occupancy_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_occupancy_vn1),
    },
    {
        .name = "UNC_M3_RXC_PACKING_MISS_VN0",
        .code = 0x4e,
        .desc = "Count cases where Ingress has packets to send but did not have time to "
                "pack into flit before sending to Agent so slot was left NULL which "
                "could have been used.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_packing_miss_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_packing_miss_vn0),
    },
    {
        .name = "UNC_M3_RXC_PACKING_MISS_VN1",
        .code = 0x4f,
        .desc = "Count cases where Ingress has packets to send but did not have time to "
                "pack into flit before sending to Agent so slot was left NULL which "
                "could have been used.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x7,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_packing_miss_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_packing_miss_vn1),
    },
    {
        .name = "UNC_M3_RXC_SMI3_PFTCH",
        .code = 0x62,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_smi3_pftch,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_smi3_pftch),
    },
    {
        .name = "UNC_M3_RXC_VNA_CRD",
        .code = 0x5b,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxc_vna_crd,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxc_vna_crd),
    },
    {
        .name = "UNC_M3_RXR_BUSY_STARVED",
        .code = 0xb4,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, because a message from the "
                "other queue has higher priority",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxr_busy_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxr_busy_starved),
    },
    {
        .name = "UNC_M3_RXR_BYPASS",
        .code = 0xb2,
        .desc = "Number of packets bypassing the CMS Ingress",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxr_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxr_bypass),
    },
    {
        .name = "UNC_M3_RXR_CRD_STARVED",
        .code = 0xb3,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, the Ingress is unable to "
                "forward to the Egress due to a lack of credit.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxr_crd_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxr_crd_starved),
    },
    {
        .name = "UNC_M3_RXR_INSERTS",
        .code = 0xb1,
        .desc = "Number of allocations into the CMS Ingress  The Ingress is used to "
                "queue up requests received from the mesh",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxr_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxr_inserts),
    },
    {
        .name = "UNC_M3_RXR_OCCUPANCY",
        .code = 0xb0,
        .desc = "Occupancy event for the Ingress buffers in the CMS  The Ingress is used "
                "to queue up requests received from the mesh",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_rxr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_rxr_occupancy),
    },
    {
        .name = "UNC_M3_STALL_NO_TXR_HORZ_CRD_AD_AG0",
        .code = 0xd0,
        .desc = "Number of cycles the AD Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_stall_no_txr_horz_crd_ad_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_stall_no_txr_horz_crd_ad_ag0),
    },
    {
        .name = "UNC_M3_STALL_NO_TXR_HORZ_CRD_AD_AG1",
        .code = 0xd2,
        .desc = "Number of cycles the AD Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_stall_no_txr_horz_crd_ad_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_stall_no_txr_horz_crd_ad_ag1),
    },
    {
        .name = "UNC_M3_STALL_NO_TXR_HORZ_CRD_BL_AG0",
        .code = 0xd4,
        .desc = "Number of cycles the BL Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_stall_no_txr_horz_crd_bl_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_stall_no_txr_horz_crd_bl_ag0),
    },
    {
        .name = "UNC_M3_STALL_NO_TXR_HORZ_CRD_BL_AG1",
        .code = 0xd6,
        .desc = "Number of cycles the BL Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_stall_no_txr_horz_crd_bl_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_stall_no_txr_horz_crd_bl_ag1),
    },
    {
        .name = "UNC_M3_TXC_AD_ARB_FAIL",
        .code = 0x30,
        .desc = "AD arb but no win; arb request asserted but not won",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_arb_fail,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_arb_fail),
    },
    {
        .name = "UNC_M3_TXC_AD_FLQ_BYPASS",
        .code = 0x2c,
        .desc =
            "Counts cases when the AD flowQ is bypassed (S0, S1 and S2 indicate which "
            "slot was bypassed with S0 having the highest priority and S2 the least)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_flq_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_flq_bypass),
    },
    {
        .name = "UNC_M3_TXC_AD_FLQ_CYCLES_NE",
        .code = 0x27,
        .desc = "Number of cycles the AD Egress queue is Not Empty",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_flq_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_flq_cycles_ne),
    },
    {
        .name = "UNC_M3_TXC_AD_FLQ_INSERTS",
        .code = 0x2d,
        .desc = "Counts the number of allocations into the QPI FlowQ. This can be used "
                "in conjunction with the QPI FlowQ Occupancy Accumulator event in order "
                "to calculate average queue latency.  Only a single FlowQ queue can be "
                "tracked at any given time.  It is not possible to filter based on "
                "direction or polarity.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_flq_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_flq_inserts),
    },
    {
        .name = "UNC_M3_TXC_AD_FLQ_OCCUPANCY",
        .code = 0x1c,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_flq_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_flq_occupancy),
    },
    {
        .name = "UNC_M3_TXC_AD_SNPF_GRP1_VN1",
        .code = 0x3c,
        .desc = "Number of snpfanout targets and non-idle cycles can be used to "
                "calculate average snpfanout latency",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_snpf_grp1_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_snpf_grp1_vn1),
    },
    {
        .name = "UNC_M3_TXC_AD_SNPF_GRP2_VN1",
        .code = 0x3d,
        .desc = "Outcome of SnpF pending arbitration",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_snpf_grp2_vn1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_snpf_grp2_vn1),
    },
    {
        .name = "UNC_M3_TXC_AD_SPEC_ARB_CRD_AVAIL",
        .code = 0x34,
        .desc = "AD speculative arb request with prior cycle credit check complete and "
                "credit avail",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_spec_arb_crd_avail,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_spec_arb_crd_avail),
    },
    {
        .name = "UNC_M3_TXC_AD_SPEC_ARB_NEW_MSG",
        .code = 0x33,
        .desc = "AD speculative arb request due to new message arriving on a specific "
                "channel (MC/VN)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_spec_arb_new_msg,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_spec_arb_new_msg),
    },
    {
        .name = "UNC_M3_TXC_AD_SPEC_ARB_NO_OTHER_PEND",
        .code = 0x32,
        .desc = "AD speculative arb request asserted due to no other channel being "
                "active (have a valid entry but dont have credits to sendd)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_ad_spec_arb_no_other_pend,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_ad_spec_arb_no_other_pend),
    },
    {
        .name = "UNC_M3_TXC_AK_FLQ_INSERTS",
        .code = 0x2f,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_TXC_AK_FLQ_OCCUPANCY",
        .code = 0x1e,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x1,
    },
    {
        .name = "UNC_M3_TXC_BL_ARB_FAIL",
        .code = 0x35,
        .desc = "BL arb but no win; arb request asserted but not won",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_arb_fail,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_arb_fail),
    },
    {
        .name = "UNC_M3_TXC_BL_FLQ_CYCLES_NE",
        .code = 0x28,
        .desc = "Number of cycles the BL Egress queue is Not Empty",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_flq_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_flq_cycles_ne),
    },
    {
        .name = "UNC_M3_TXC_BL_FLQ_INSERTS",
        .code = 0x2e,
        .desc = "Counts the number of allocations into the QPI FlowQ. This can be used "
                "in conjunction with the QPI FlowQ Occupancy Accumulator event in order "
                "to calculate average queue latency.  Only a single FlowQ queue can be "
                "tracked at any given time.  It is not possible to filter based on "
                "direction or polarity.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_flq_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_flq_inserts),
    },
    {
        .name = "UNC_M3_TXC_BL_FLQ_OCCUPANCY",
        .code = 0x1d,
        .desc = "TBD",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_flq_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_flq_occupancy),
    },
    {
        .name = "UNC_M3_TXC_BL_SPEC_ARB_NEW_MSG",
        .code = 0x38,
        .desc = "BL speculative arb request due to new message arriving on a specific "
                "channel (MC/VN)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_spec_arb_new_msg,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_spec_arb_new_msg),
    },
    {
        .name = "UNC_M3_TXC_BL_SPEC_ARB_NO_OTHER_PEND",
        .code = 0x37,
        .desc = "BL speculative arb request asserted due to no other channel being "
                "active (have a valid entry but dont have credits to sendd)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txc_bl_spec_arb_no_other_pend,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txc_bl_spec_arb_no_other_pend),
    },
    {
        .name = "UNC_M3_TXR_HORZ_ADS_USED",
        .code = 0x9d,
        .desc = "Number of packets using the Horizontal Anti-Deadlock Slot, broken down "
                "by ring type and CMS Agent.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_ads_used),
    },
    {
        .name = "UNC_M3_TXR_HORZ_BYPASS",
        .code = 0x9f,
        .desc = "Number of packets bypassing the Horizontal Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_bypass),
    },
    {
        .name = "UNC_M3_TXR_HORZ_CYCLES_FULL",
        .code = 0x96,
        .desc =
            "Cycles the Transgress buffers in the Common Mesh Stop are Full.  The egress "
            "is used to queue up requests destined for the Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_cycles_full),
    },
    {
        .name = "UNC_M3_TXR_HORZ_CYCLES_NE",
        .code = 0x97,
        .desc = "Cycles the Transgress buffers in the Common Mesh Stop are Not-Empty.  "
                "The egress is used to queue up requests destined for the Horizontal "
                "Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_cycles_ne),
    },
    {
        .name = "UNC_M3_TXR_HORZ_INSERTS",
        .code = 0x95,
        .desc = "Number of allocations into the Transgress buffers in the Common Mesh "
                "Stop  The egress is used to queue up requests destined for the "
                "Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_inserts),
    },
    {
        .name = "UNC_M3_TXR_HORZ_NACK",
        .code = 0x99,
        .desc = "Counts number of Egress packets NACKed on to the Horizontal Rinng",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_nack),
    },
    {
        .name = "UNC_M3_TXR_HORZ_OCCUPANCY",
        .code = 0x94,
        .desc = "Occupancy event for the Transgress buffers in the Common Mesh Stop  The "
                "egress is used to queue up requests destined for the Horizontal Ring on "
                "the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_occupancy),
    },
    {
        .name = "UNC_M3_TXR_HORZ_STARVED",
        .code = 0x9b,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Transgress buffer cannot send a transaction onto the Horizontal ring "
                "for a long period of time.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_horz_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_horz_starved),
    },
    {
        .name = "UNC_M3_TXR_VERT_ADS_USED",
        .code = 0x9c,
        .desc = "Number of packets using the Vertical Anti-Deadlock Slot, broken down by "
                "ring type and CMS Agent.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_ads_used),
    },
    {
        .name = "UNC_M3_TXR_VERT_BYPASS",
        .code = 0x9e,
        .desc = "Number of packets bypassing the Vertical Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_bypass),
    },
    {
        .name = "UNC_M3_TXR_VERT_CYCLES_FULL",
        .code = 0x92,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Full.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_cycles_full),
    },
    {
        .name = "UNC_M3_TXR_VERT_CYCLES_NE",
        .code = 0x93,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Empty.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_cycles_ne),
    },
    {
        .name = "UNC_M3_TXR_VERT_INSERTS",
        .code = 0x91,
        .desc = "Number of allocations into the Common Mesh Stop Egress.  The Egress is "
                "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_inserts),
    },
    {
        .name = "UNC_M3_TXR_VERT_NACK",
        .code = 0x98,
        .desc = "Counts number of Egress packets NACKed on to the Vertical Rinng",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_nack),
    },
    {
        .name = "UNC_M3_TXR_VERT_OCCUPANCY",
        .code = 0x90,
        .desc =
            "Occupancy event for the Egress buffers in the Common Mesh Stop  The egress "
            "is used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_occupancy),
    },
    {
        .name = "UNC_M3_TXR_VERT_STARVED",
        .code = 0x9a,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Egress cannot send a transaction onto the Vertical ring for a long "
                "period of time.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_txr_vert_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_txr_vert_starved),
    },
    {
        .name = "UNC_M3_UPI_PEER_AD_CREDITS_EMPTY",
        .code = 0x20,
        .desc = "No credits available to send to UPIs on the AD Ring",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_upi_peer_ad_credits_empty,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_upi_peer_ad_credits_empty),
    },
    {
        .name = "UNC_M3_UPI_PEER_BL_CREDITS_EMPTY",
        .code = 0x21,
        .desc = "No credits available to send to UPI on the BL Ring (diff between "
                "non-SMI and SMI mode)",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_upi_peer_bl_credits_empty,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_upi_peer_bl_credits_empty),
    },
    {
        .name = "UNC_M3_UPI_PREFETCH_SPAWN",
        .code = 0x29,
        .desc = "Count cases where FlowQ causes spawn of Prefetch to iMC/SMI3 target",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_M3_VERT_RING_AD_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vert_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vert_ring_ad_in_use),
    },
    {
        .name = "UNC_M3_VERT_RING_AK_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vert_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vert_ring_ak_in_use),
    },
    {
        .name = "UNC_M3_VERT_RING_BL_IN_USE",
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
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vert_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vert_ring_bl_in_use),
    },
    {
        .name = "UNC_M3_VERT_RING_IV_IN_USE",
        .code = 0xac,
        .desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this "
            "ring stop.  This includes when packets are passing by and when packets are "
            "being sunk, but does not include when packets are being sent from the ring "
            "stop.  There is only 1 IV ring.  Therefore, if one wants to monitor the "
            "Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd "
            "ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vert_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vert_ring_iv_in_use),
    },
    {
        .name = "UNC_M3_VN0_CREDITS_USED",
        .code = 0x5c,
        .desc =
            "Number of times a VN0 credit was used on the DRS message channel.  In order "
            "for a request to be transferred across UPI, it must be guaranteed to have a "
            "flit buffer on the remote socket to sink into.  There are two credit pools, "
            "VNA and VN0.  VNA is a shared pool used to achieve high performance.  The "
            "VN0 pool has reserved entries for each message class and is used to prevent "
            "deadlock.  Requests first attempt to acquire a VNA credit, and then fall "
            "back to VN0 if they fail.  This counts the number of times a VN0 credit was "
            "used.  Note that a single VN0 credit holds access to potentially multiple "
            "flit buffers.  For example, a transfer that uses VNA could use 9 flit "
            "buffers and in that case uses 9 credits.  A transfer on VN0 will only count "
            "a single credit even though it may use multiple buffers.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vn0_credits_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vn0_credits_used),
    },
    {
        .name = "UNC_M3_VN0_NO_CREDITS",
        .code = 0x5e,
        .desc = "Number of Cycles there were no VN0 Credits",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vn0_no_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vn0_no_credits),
    },
    {
        .name = "UNC_M3_VN1_CREDITS_USED",
        .code = 0x5d,
        .desc =
            "Number of times a VN1 credit was used on the WB message channel.  In order "
            "for a request to be transferred across QPI, it must be guaranteed to have a "
            "flit buffer on the remote socket to sink into.  There are two credit pools, "
            "VNA and VN1.  VNA is a shared pool used to achieve high performance.  The "
            "VN1 pool has reserved entries for each message class and is used to prevent "
            "deadlock.  Requests first attempt to acquire a VNA credit, and then fall "
            "back to VN1 if they fail.  This counts the number of times a VN1 credit was "
            "used.  Note that a single VN1 credit holds access to potentially multiple "
            "flit buffers.  For example, a transfer that uses VNA could use 9 flit "
            "buffers and in that case uses 9 credits.  A transfer on VN1 will only count "
            "a single credit even though it may use multiple buffers.",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vn1_credits_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vn1_credits_used),
    },
    {
        .name = "UNC_M3_VN1_NO_CREDITS",
        .code = 0x5f,
        .desc = "Number of Cycles there were no VN1 Credits",
        .modmsk = SKX_UNC_M3UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_m3_vn1_no_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_m3_vn1_no_credits),
    },
};
