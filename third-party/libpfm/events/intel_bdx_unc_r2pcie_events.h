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
 * PMU: bdx_unc_r2pcie
 */

static intel_x86_umask_t bdx_unc_r2_iio_credit[] = {
    {
        .uname = "ISOCH_QPI0",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "ISOCH_QPI1",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "PRQ_QPI0",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "PRQ_QPI1",
        .ucode = 0x200,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t bdx_unc_r2_ring_ad_used[] = {
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

static intel_x86_umask_t bdx_unc_r2_ring_ak_bounces[] = {
    {
        .uname = "DN",
        .ucode = 0x200,
        .udesc = "AK Ingress Bounced -- Dn",
    },
    {
        .uname = "UP",
        .ucode = 0x100,
        .udesc = "AK Ingress Bounced -- Up",
    },
};

static intel_x86_umask_t bdx_unc_r2_ring_iv_used[] = {
    {
        .uname = "ANY",
        .ucode = 0xf00,
        .udesc = "Any directions",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "CCW",
        .ucode = 0xc00,
        .udesc = "Counterclockwise",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CW",
        .ucode = 0x300,
        .udesc = "Clockwise",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_r2_rxr_cycles_ne[] = {
    {
        .uname = "NCB",
        .ucode = 0x1000,
        .udesc = "NCB",
    },
    {
        .uname = "NCS",
        .ucode = 0x2000,
        .udesc = "NCS",
    },
};

static intel_x86_umask_t bdx_unc_r2_rxr_occupancy[] = {
    {
        .uname = "DRS",
        .ucode = 0x800,
        .udesc = "Ingress Occupancy Accumulator -- DRS",
        .uflags = INTEL_X86_DFL,
    },
};

static intel_x86_umask_t bdx_unc_r2_sbo0_credits_acquired[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "SBo0 Credits Acquired -- For AD Ring",
    },
    {
        .uname = "BL",
        .ucode = 0x200,
        .udesc = "SBo0 Credits Acquired -- For BL Ring",
    },
};

static intel_x86_umask_t bdx_unc_r2_stall_no_sbo_credit[] = {
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

static intel_x86_umask_t bdx_unc_r2_txr_cycles_full[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Egress Cycles Full -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Egress Cycles Full -- AK",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Egress Cycles Full -- BL",
    },
};

static intel_x86_umask_t bdx_unc_r2_txr_cycles_ne[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Egress Cycles Not Empty -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Egress Cycles Not Empty -- AK",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Egress Cycles Not Empty -- BL",
    },
};

static intel_x86_umask_t bdx_unc_r2_txr_nack_cw[] = {
    {
        .uname = "DN_AD",
        .ucode = 0x100,
        .udesc = "Egress CCW NACK -- AD CCW",
    },
    {
        .uname = "DN_AK",
        .ucode = 0x400,
        .udesc = "Egress CCW NACK -- AK CCW",
    },
    {
        .uname = "DN_BL",
        .ucode = 0x200,
        .udesc = "Egress CCW NACK -- BL CCW",
    },
    {
        .uname = "UP_AD",
        .ucode = 0x800,
        .udesc = "Egress CCW NACK -- AK CCW",
    },
    {
        .uname = "UP_AK",
        .ucode = 0x2000,
        .udesc = "Egress CCW NACK -- BL CW",
    },
    {
        .uname = "UP_BL",
        .ucode = 0x1000,
        .udesc = "Egress CCW NACK -- BL CCW",
    },
};

static intel_x86_entry_t intel_bdx_unc_r2_pe[] = {
    {
        .name = "UNC_R2_CLOCKTICKS",
        .code = 0x1,
        .desc = "Counts the number of uclks in the R2PCIe uclk domain.  This could be "
                "slightly different than the count in the Ubox because of enable/freeze "
                "delays.  However, because the R2PCIe is close to the Ubox, they "
                "generally should not diverge by more than a handful of cycles.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_R2_IIO_CREDIT",
        .code = 0x2d,
        .desc = "TBD",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_iio_credit,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_iio_credit),
    },
    {
        .name = "UNC_R2_RING_AD_USED",
        .code = 0x7,
        .desc =
            "Counts the number of cycles that the AD ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_r2_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_ring_ad_used),
    },
    {
        .name = "UNC_R2_RING_AK_BOUNCES",
        .code = 0x12,
        .desc = "Counts the number of times when a request destined for the AK ingress "
                "bounced.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_r2_ring_ak_bounces,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_ring_ak_bounces),
    },
    {
        .name = "UNC_R2_RING_AK_USED",
        .code = 0x8,
        .desc =
            "Counts the number of cycles that the AK ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_r2_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_ring_ad_used),
    },
    {
        .name = "UNC_R2_RING_BL_USED",
        .code = 0x9,
        .desc =
            "Counts the number of cycles that the BL ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sunk, but does not include when packets are being sent from the ring stop.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_r2_ring_ad_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_ring_ad_used),
    },
    {
        .name = "UNC_R2_RING_IV_USED",
        .code = 0xa,
        .desc =
            "Counts the number of cycles that the IV ring is being used at this ring "
            "stop.  This includes when packets are passing by and when packets are being "
            "sent, but does not include when packets are being sunk into the ring stop.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_r2_ring_iv_used,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_ring_iv_used),
    },
    {
        .name = "UNC_R2_RXR_CYCLES_NE",
        .code = 0x10,
        .desc =
            "Counts the number of cycles when the R2PCIe Ingress is not empty.  This "
            "tracks one of the three rings that are used by the R2PCIe agent.  This can "
            "be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event "
            "in order to calculate average queue occupancy.  Multiple ingress buffers "
            "can be tracked at a given time using multiple counters.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_rxr_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_rxr_cycles_ne),
    },
    {
        .name = "UNC_R2_RXR_INSERTS",
        .code = 0x11,
        .desc = "Counts the number of allocations into the R2PCIe Ingress.  This tracks "
                "one of the three rings that are used by the R2PCIe agent.  This can be "
                "used in conjunction with the R2PCIe Ingress Occupancy Accumulator event "
                "in order to calculate average queue latency.  Multiple ingress buffers "
                "can be tracked at a given time using multiple counters.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_rxr_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_rxr_cycles_ne),
    },
    {
        .name = "UNC_R2_RXR_OCCUPANCY",
        .code = 0x13,
        .desc = "Accumulates the occupancy of a given R2PCIe Ingress queue in each "
                "cycles.  This tracks one of the three ring Ingress buffers.  This can "
                "be used with the R2PCIe Ingress Not Empty event to calculate average "
                "occupancy or the R2PCIe Ingress Allocations event in order to calculate "
                "average queuing latency.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = bdx_unc_r2_rxr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_rxr_occupancy),
    },
    {
        .name = "UNC_R2_SBO0_CREDITS_ACQUIRED",
        .code = 0x28,
        .desc = "Number of Sbo 0 credits acquired in a given cycle, per ring.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_sbo0_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_sbo0_credits_acquired),
    },
    {
        .name = "UNC_R2_STALL_NO_SBO_CREDIT",
        .code = 0x2c,
        .desc = "Number of cycles Egress is stalled waiting for an Sbo credit to become "
                "available.  Per Sbo, per Ring.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_stall_no_sbo_credit,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_stall_no_sbo_credit),
    },
    {
        .name = "UNC_R2_TXR_CYCLES_FULL",
        .code = 0x25,
        .desc = "Counts the number of cycles when the R2PCIe Egress buffer is full.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = bdx_unc_r2_txr_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_txr_cycles_full),
    },
    {
        .name = "UNC_R2_TXR_CYCLES_NE",
        .code = 0x23,
        .desc = "Counts the number of cycles when the R2PCIe Egress is not empty.  This "
                "tracks one of the three rings that are used by the R2PCIe agent.  This "
                "can be used in conjunction with the R2PCIe Egress Occupancy Accumulator "
                "event in order to calculate average queue occupancy.  Only a single "
                "Egress queue can be tracked at any given time.  It is not possible to "
                "filter based on direction or polarity.",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = bdx_unc_r2_txr_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_txr_cycles_ne),
    },
    {
        .name = "UNC_R2_TXR_NACK_CW",
        .code = 0x26,
        .desc = "TBD",
        .modmsk = BDX_UNC_R2PCIE_ATTRS,
        .cntmsk = 0x3,
        .ngrp = 1,
        .umasks = bdx_unc_r2_txr_nack_cw,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_r2_txr_nack_cw),
    },
};
