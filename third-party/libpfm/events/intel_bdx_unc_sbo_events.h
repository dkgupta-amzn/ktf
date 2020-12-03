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
 * PMU: bdx_unc_sbo
 */

static intel_x86_umask_t bdx_unc_s_ring_ad_used[] = {
    {
        .uname = "DOWN_EVEN",
        .ucode = 0x400,
        .udesc = "Down and Event",
    },
    {
        .uname = "DOWN_ODD",
        .ucode = 0x800,
        .udesc = "Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Up and Odd",
    },
    {
        .uname = "UP",
        .ucode = 0x300,
        .udesc = "Up",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DOWN",
        .ucode = 0xcc00,
        .udesc = "Down",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_s_ring_bounces[] = {
    {
        .uname = "AD_CACHE",
        .ucode = 0x100,
        .udesc = "Number of LLC responses that bounced on the Ring. -- ",
    },
    {
        .uname = "AK_CORE",
        .ucode = 0x200,
        .udesc = "Number of LLC responses that bounced on the Ring. -- Acknowledgements "
                 "to core",
    },
    {
        .uname = "BL_CORE",
        .ucode = 0x400,
        .udesc =
            "Number of LLC responses that bounced on the Ring. -- Data Responses to core",
    },
    {
        .uname = "IV_CORE",
        .ucode = 0x800,
        .udesc = "Number of LLC responses that bounced on the Ring. -- Snoops of "
                 "processors cachee.",
    },
};

static intel_x86_umask_t bdx_unc_s_ring_iv_used[] = {
    {
        .uname = "DN",
        .ucode = 0xc00,
        .udesc = "BL Ring in Use -- Any",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UP",
        .ucode = 0x300,
        .udesc = "BL Ring in Use -- Any",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_s_rxr_bypass[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x200,
        .udesc = "Bypass -- AD - Bounces",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x100,
        .udesc = "Bypass -- AD - Credits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AK",
        .ucode = 0x1000,
        .udesc = "Bypass -- AK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x800,
        .udesc = "Bypass -- BL - Bounces",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x400,
        .udesc = "Bypass -- BL - Credits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IV",
        .ucode = 0x2000,
        .udesc = "Bypass -- IV",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_s_rxr_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x200,
        .udesc = "Ingress Allocations -- AD - Bounces",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x100,
        .udesc = "Ingress Allocations -- AD - Credits",
    },
    {
        .uname = "AK",
        .ucode = 0x1000,
        .udesc = "Ingress Allocations -- AK",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x800,
        .udesc = "Ingress Allocations -- BL - Bounces",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x400,
        .udesc = "Ingress Allocations -- BL - Credits",
    },
    {
        .uname = "IV",
        .ucode = 0x2000,
        .udesc = "Ingress Allocations -- IV",
    },
};

static intel_x86_umask_t bdx_unc_s_rxr_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x200,
        .udesc = "Ingress Occupancy -- AD - Bounces",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x100,
        .udesc = "Ingress Occupancy -- AD - Credits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AK",
        .ucode = 0x1000,
        .udesc = "Ingress Occupancy -- AK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x800,
        .udesc = "Ingress Occupancy -- BL - Bounces",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x400,
        .udesc = "Ingress Occupancy -- BL - Credits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IV",
        .ucode = 0x2000,
        .udesc = "Ingress Occupancy -- IV",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_s_txr_ads_used[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t bdx_unc_s_txr_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x200,
        .udesc = "Egress Allocations -- AD - Bounces",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x100,
        .udesc = "Egress Allocations -- AD - Credits",
    },
    {
        .uname = "AK",
        .ucode = 0x1000,
        .udesc = "Egress Allocations -- AK",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x800,
        .udesc = "Egress Allocations -- BL - Bounces",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x400,
        .udesc = "Egress Allocations -- BL - Credits",
    },
    {
        .uname = "IV",
        .ucode = 0x2000,
        .udesc = "Egress Allocations -- IV",
    },
};

static intel_x86_umask_t bdx_unc_s_txr_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x200,
        .udesc = "Egress Occupancy -- AD - Bounces",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x100,
        .udesc = "Egress Occupancy -- AD - Credits",
    },
    {
        .uname = "AK",
        .ucode = 0x1000,
        .udesc = "Egress Occupancy -- AK",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x800,
        .udesc = "Egress Occupancy -- BL - Bounces",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x400,
        .udesc = "Egress Occupancy -- BL - Credits",
    },
    {
        .uname = "IV",
        .ucode = 0x2000,
        .udesc = "Egress Occupancy -- IV",
    },
};

static intel_x86_umask_t bdx_unc_s_txr_ordering[] = {
    {
        .uname = "IVSNOOPGO_UP",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "IVSNOOP_DN",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "AK_U2C_UP_EVEN",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "AK_U2C_UP_ODD",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "AK_U2C_DN_EVEN",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
    {
        .uname = "AK_U2C_DN_ODD",
        .ucode = 0x2000,
        .udesc = "TBD",
    },
};

static intel_x86_entry_t intel_bdx_unc_s_pe[] = {
    {
        .name = "UNC_S_BOUNCE_CONTROL",
        .code = 0xa,
        .desc = "TBD",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_S_CLOCKTICKS",
        .code = 0x0,
        .desc = "TBD",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_S_FAST_ASSERTED",
        .code = 0x9,
        .desc = "Counts the number of cycles either the local or incoming distress "
                "signals are asserted.  Incoming distress includes up, dn and across.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_S_RING_AD_USED",
        .code = 0x1b,
        .desc =
            "Counts the number of cycles that the AD ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sent, but does not include when packets are being sunk into the ring stop.  "
            "We really have two rings in BDX -- a clockwise ring and a counter-clockwise "
            "ring.  On the left side of the ring, the UP direction is on the clockwise "
            "ring and DN is on the counter-clockwise ring.  On the right side of the "
            "ring, this is reversed.  The first half of the CBos are on the left side of "
            "the ring, and the 2nd half are on the right side of the ring.  In other "
            "words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo "
            "2 UP AD because they are on opposite sides of the rhe ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_ring_ad_used),
    },
    {
        .name = "UNC_S_RING_AK_USED",
        .code = 0x1c,
        .desc =
            "Counts the number of cycles that the AK ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sent, but does not include when packets are being sunk into the ring stop. "
            "We really have two rings in BDX -- a clockwise ring and a counter-clockwise "
            "ring.  On the left side of the ring, the UP direction is on the clockwise "
            "ring and DN is on the counter-clockwise ring.  On the right side of the "
            "ring, this is reversed.  The first half of the CBos are on the left side of "
            "the ring, and the 2nd half are on the right side of the ring.  In other "
            "words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo "
            "2 UP AD because they are on opposite sides of the rhe ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_ring_ad_used),
    },
    {
        .name = "UNC_S_RING_BL_USED",
        .code = 0x1d,
        .desc =
            "Counts the number of cycles that the BL ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sent, but does not include when packets are being sunk into the ring stop. "
            "We really have two rings in BDX -- a clockwise ring and a counter-clockwise "
            "ring.  On the left side of the ring, the UP direction is on the clockwise "
            "ring and DN is on the counter-clockwise ring.  On the right side of the "
            "ring, this is reversed.  The first half of the CBos are on the left side of "
            "the ring, and the 2nd half are on the right side of the ring.  In other "
            "words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo "
            "2 UP AD because they are on opposite sides of the rhe ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_ring_ad_used),
    },
    {
        .name = "UNC_S_RING_BOUNCES",
        .code = 0x5,
        .desc = "TBD",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_ring_bounces,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_ring_bounces),
    },
    {
        .name = "UNC_S_RING_IV_USED",
        .code = 0x1e,
        .desc = "Counts the number of cycles that the BL ring is being used at this ring "
                "stop.  This includes when packets are passing by and when packets are "
                "being sent, but does not include when packets are being sunk into the "
                "ring stop.  There is only 1 IV ring in BDX.  Therefore, if one wants to "
                "monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To "
                "monitor the Odd ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_ring_iv_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_ring_iv_used),
    },
    {
        .name = "UNC_S_RXR_BYPASS",
        .code = 0x12,
        .desc = "Bypass the Sbo Ingress.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_rxr_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_rxr_bypass),
    },
    {
        .name = "UNC_S_RXR_INSERTS",
        .code = 0x13,
        .desc = "Number of allocations into the Sbo Ingress  The Ingress is used to "
                "queue up requests received from the ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_rxr_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_rxr_inserts),
    },
    {
        .name = "UNC_S_RXR_OCCUPANCY",
        .code = 0x11,
        .desc = "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is "
                "used to queue up requests received from the ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_rxr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_rxr_occupancy),
    },
    {
        .name = "UNC_S_TXR_ADS_USED",
        .code = 0x4,
        .desc = "TBD",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_txr_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_txr_ads_used),
    },
    {
        .name = "UNC_S_TXR_INSERTS",
        .code = 0x2,
        .desc = "Number of allocations into the Sbo Egress.  The Egress is used to queue "
                "up requests destined for the ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_txr_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_txr_inserts),
    },
    {
        .name = "UNC_S_TXR_OCCUPANCY",
        .code = 0x1,
        .desc = "Occupancy event for the Egress buffers in the Sbo.  The egress is used "
                "to queue up requests destined for the ring.",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_txr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_txr_occupancy),
    },
    {
        .name = "UNC_S_TXR_ORDERING",
        .code = 0x7,
        .desc = "TB",
        .modmsk = BDX_UNC_SBO_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_s_txr_ordering,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_s_txr_ordering),
    },
};
