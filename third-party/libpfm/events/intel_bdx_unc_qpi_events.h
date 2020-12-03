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
 * PMU: bdx_unc_qpi
 */

static intel_x86_umask_t bdx_unc_q_direct2core[] = {
    {
        .uname = "FAILURE_CREDITS",
        .ucode = 0x200,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - Egress Credits",
    },
    {
        .uname = "FAILURE_CREDITS_MISS",
        .ucode = 0x2000,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Miss",
    },
    {
        .uname = "FAILURE_CREDITS_RBT",
        .ucode = 0x800,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Invalid",
    },
    {
        .uname = "FAILURE_CREDITS_RBT_MISS",
        .ucode = 0x8000,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Miss, Invalid",
    },
    {
        .uname = "FAILURE_MISS",
        .ucode = 0x1000,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - RBT Miss",
    },
    {
        .uname = "FAILURE_RBT_HIT",
        .ucode = 0x400,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - RBT Invalid",
    },
    {
        .uname = "FAILURE_RBT_MISS",
        .ucode = 0x4000,
        .udesc = "Direct 2 Core Spawning -- Spawn Failure - RBT Miss and Invalid",
    },
    {
        .uname = "SUCCESS_RBT_HIT",
        .ucode = 0x100,
        .udesc = "Direct 2 Core Spawning -- Spawn Success",
    },
};

static intel_x86_umask_t bdx_unc_q_rxl_credits_consumed_vn0[] = {
    {
        .uname = "DRS",
        .ucode = 0x100,
        .udesc = "VN0 Credit Consumed -- DRS",
    },
    {
        .uname = "HOM",
        .ucode = 0x800,
        .udesc = "VN0 Credit Consumed -- HOM",
    },
    {
        .uname = "NCB",
        .ucode = 0x200,
        .udesc = "VN0 Credit Consumed -- NCB",
    },
    {
        .uname = "NCS",
        .ucode = 0x400,
        .udesc = "VN0 Credit Consumed -- NCS",
    },
    {
        .uname = "NDR",
        .ucode = 0x2000,
        .udesc = "VN0 Credit Consumed -- NDR",
    },
    {
        .uname = "SNP",
        .ucode = 0x1000,
        .udesc = "VN0 Credit Consumed -- SNP",
    },
};

static intel_x86_umask_t bdx_unc_q_rxl_flits_g1[] = {
    {
        .uname = "DRS",
        .ucode = 0x1800,
        .udesc = "Flits Received - Group 1 -- DRS Flits (both Header and Data)",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_DATA",
        .ucode = 0x800,
        .udesc = "Flits Received - Group 1 -- DRS Data Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_NONDATA",
        .ucode = 0x1000,
        .udesc = "Flits Received - Group 1 -- DRS Header Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .ucode = 0x600,
        .udesc = "Flits Received - Group 1 -- HOM Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_NONREQ",
        .ucode = 0x400,
        .udesc = "Flits Received - Group 1 -- HOM Non-Request Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_REQ",
        .ucode = 0x200,
        .udesc = "Flits Received - Group 1 -- HOM Request Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SNP",
        .ucode = 0x100,
        .udesc = "Flits Received - Group 1 -- SNP Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_q_rxl_flits_g2[] = {
    {
        .uname = "NCB",
        .ucode = 0xc00,
        .udesc = "Flits Received - Group 2 -- Non-Coherent Rx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_DATA",
        .ucode = 0x400,
        .udesc = "Flits Received - Group 2 -- Non-Coherent data Rx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_NONDATA",
        .ucode = 0x800,
        .udesc = "Flits Received - Group 2 -- Non-Coherent non-data Rx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .ucode = 0x1000,
        .udesc = "Flits Received - Group 2 -- Non-Coherent standard Rx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AD",
        .ucode = 0x100,
        .udesc = "Flits Received - Group 2 -- Non-Data Response Rx Flits - AD",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AK",
        .ucode = 0x200,
        .udesc = "Flits Received - Group 2 -- Non-Data Response Rx Flits - AK",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_q_rxl_inserts_drs[] = {
    {
        .uname = "VN0",
        .ucode = 0x100,
        .udesc = "for VN0",
    },
    {
        .uname = "VN1",
        .ucode = 0x200,
        .udesc = "for VN1",
    },
};

static const intel_x86_umask_t bdx_unc_q_rxl_flits_g0[] = {
    {
        .uname = "IDLE",
        .udesc = "Number of data flits over QPI that do not hold payload. When QPI is "
                 "not in a power saving state, it continuously transmits flits across "
                 "the link. When there are no protocol flits to send, it will send IDLE "
                 "and NULL flits across",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
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

static intel_x86_umask_t bdx_unc_q_txl_flits_g0[] = {
    {
        .uname = "DATA",
        .ucode = 0x200,
        .udesc = "Flits Transferred - Group 0 -- Data Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NON_DATA",
        .ucode = 0x400,
        .udesc = "Flits Transferred - Group 0 -- Non-Data protocol Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_q_txl_flits_g1[] = {
    {
        .uname = "DRS",
        .ucode = 0x1800,
        .udesc = "Flits Transferred - Group 1 -- DRS Flits (both Header and Data)",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_DATA",
        .ucode = 0x800,
        .udesc = "Flits Transferred - Group 1 -- DRS Data Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DRS_NONDATA",
        .ucode = 0x1000,
        .udesc = "Flits Transferred - Group 1 -- DRS Header Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM",
        .ucode = 0x600,
        .udesc = "Flits Transferred - Group 1 -- HOM Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_NONREQ",
        .ucode = 0x400,
        .udesc = "Flits Transferred - Group 1 -- HOM Non-Request Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HOM_REQ",
        .ucode = 0x200,
        .udesc = "Flits Transferred - Group 1 -- HOM Request Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SNP",
        .ucode = 0x100,
        .udesc = "Flits Transferred - Group 1 -- SNP Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_q_txl_flits_g2[] = {
    {
        .uname = "NCB",
        .ucode = 0xc00,
        .udesc = "Flits Transferred - Group 2 -- Non-Coherent Bypass Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_DATA",
        .ucode = 0x400,
        .udesc = "Flits Transferred - Group 2 -- Non-Coherent data Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCB_NONDATA",
        .ucode = 0x800,
        .udesc = "Flits Transferred - Group 2 -- Non-Coherent non-data Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NCS",
        .ucode = 0x1000,
        .udesc = "Flits Transferred - Group 2 -- Non-Coherent standard Tx Flits",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AD",
        .ucode = 0x100,
        .udesc = "Flits Transferred - Group 2 -- Non-Data Response Tx Flits - AD",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NDR_AK",
        .ucode = 0x200,
        .udesc = "Flits Transferred - Group 2 -- Non-Data Response Tx Flits - AK",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_umask_t bdx_unc_q_txr_bl_drs_credit_acquired[] = {
    {
        .uname = "VN0",
        .ucode = 0x100,
        .udesc = "R3QPI Egress Credit Occupancy - DRS -- for VN0",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "VN1",
        .ucode = 0x200,
        .udesc = "R3QPI Egress Credit Occupancy - DRS -- for VN1",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "VN_SHR",
        .ucode = 0x400,
        .udesc = "R3QPI Egress Credit Occupancy - DRS -- for Shared VN",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static intel_x86_entry_t intel_bdx_unc_q_pe[] = {
    {
        .name = "UNC_Q_CLOCKTICKS",
        .code = 0x14,
        .desc = "Counts the number of clocks in the QPI LL.  This clock runs at 1/4th "
                "the GT/s speed of the QPI link.  For example, a 4GT/s link will have "
                "qfclk or 1GHz.  BDX does not support dynamic link speeds, so this "
                "frequency is fixexed.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_CTO_COUNT",
        .code = 0x38 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of CTO (cluster trigger outs) events that were "
                "asserted across the two slots.  If both slots trigger in a given cycle, "
                "the event will increment by 2.  You can use edge detect to count the "
                "number of cases when both events triggered.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_DIRECT2CORE",
        .code = 0x13,
        .desc =
            "Counts the number of DRS packets that we attempted to do direct2core on.  "
            "There are 4 mutually exlusive filters.  Filter [0] can be used to get "
            "successful spawns, while [1:3] provide the different failure cases.  Note "
            "that this does not count packets that are not candidates for Direct2Core.  "
            "The only candidates for Direct2Core are DRS packets destined for Cbos.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_direct2core,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_direct2core),
    },
    {
        .name = "UNC_Q_L1_POWER_CYCLES",
        .code = 0x12,
        .desc = "Number of QPI qfclk cycles spent in L1 power mode.  L1 is a mode that "
                "totally shuts down a QPI link.  Use edge detect to count the number of "
                "instances when the QPI link entered L1.  Link power states are per link "
                "and per direction, so for example the Tx direction could be in one "
                "state while Rx was in another. Because L1 totally shuts down the link, "
                "it takes a good amount of time to exit this mode.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL0P_POWER_CYCLES",
        .code = 0x10,
        .desc =
            "Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we "
            "disable 1/2 of the QPI lanes, decreasing our bandwidth in order to save "
            "power.  It increases snoop and data transfer latencies and decreases "
            "overall bandwidth.  This mode can be very useful in NUMA optimized "
            "workloads that largely only utilize QPI for snoops and their responses.  "
            "Use edge detect to count the number of instances when the QPI link entered "
            "L0p.  Link power states are per link and per direction, so for example the "
            "Tx direction could be in one state while Rx was in another.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL0_POWER_CYCLES",
        .code = 0xf,
        .desc = "Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  "
                "L0 is the default mode which provides the highest performance with the "
                "most power.  Use edge detect to count the number of instances that the "
                "link entered L0.  Link power states are per link and per direction, so "
                "for example the Tx direction could be in one state while Rx was in "
                "another.  The phy layer  sometimes leaves L0 for training, which will "
                "not be captured by this event.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_BYPASSED",
        .code = 0x9,
        .desc = "Counts the number of times that an incoming flit was able to bypass the "
                "flit buffer and pass directly across the BGF and into the Egress.  This "
                "is a latency optimization, and should generally be the common case.  If "
                "this value is less than the number of flits transfered, it implies that "
                "there was queueing getting onto the ring, and thus the transactions saw "
                "higher latency.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_CREDITS_CONSUMED_VN0",
        .code = 0x1e | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of times that an RxQ VN0 credit was consumed (i.e. "
                "message uses a VN0 credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_credits_consumed_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_credits_consumed_vn0),
    },
    {
        .name = "UNC_Q_RXL_CREDITS_CONSUMED_VN1",
        .code = 0x39 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of times that an RxQ VN1 credit was consumed (i.e. "
                "message uses a VN1 credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_credits_consumed_vn0,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_credits_consumed_vn0),
    },
    {
        .name = "UNC_Q_RXL_CREDITS_CONSUMED_VNA",
        .code = 0x1d | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of times that an RxQ VNA credit was consumed (i.e. "
                "message uses a VNA credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_CYCLES_NE",
        .code = 0xa,
        .desc =
            "Counts the number of cycles that the QPI RxQ was not empty.  Generally, "
            "when data is transmitted across QPI, it will bypass the RxQ and pass "
            "directly to the ring interface.  If things back up getting transmitted onto "
            "the ring, however, it may need to allocate into this buffer, thus "
            "increasing the latency.  This event can be used in conjunction with the "
            "Flit Buffer Occupancy Accumulator event to calculate the average occupancy.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_FLITS_G0",
        .code = 0x1,
        .desc = "Counts the number of flits received from the QPI Link.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_flits_g0,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_flits_g0),
    },
    {
        .name = "UNC_Q_RXL_FLITS_G1",
        .code = 0x2 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of flits received from the QPI Link.  This is one of "
                "three groups that allow us to track flits.  It includes filters for "
                "SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of "
                "information (in addition to some ECC data).  In full-width (L0) mode, "
                "flits are made up of four fits, each of which contains 20 bits of data "
                "(along with some additional ECC data).   In half-width (L0p) mode, the "
                "fits are only 10 bits, and therefore it takes twice as many fits to "
                "transmit a flit.  When one talks about QPI speed (for example, 8.0 "
                "GT/s), the transfers here refer to fits.  Therefore, in L0, the system "
                "will transfer 1 flit at the rate of 1/4th the QPI speed.  One can "
                "calculate the bandwidth of the link by taking: flits*80b/time.  Note "
                "that this is not the same as data bandwidth.  For example, when we are "
                "transfering a 64B cacheline across QPI, we will break it into 9 flits "
                "-- 1 with header information and 8 with 64 bits of actual data and an "
                "additional 16 bits of other information.  To calculate data bandwidth, "
                "one should therefore do: datld therefore do: data flits * 8B / time.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_flits_g1,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_flits_g1),
    },
    {
        .name = "UNC_Q_RXL_FLITS_G2",
        .code = 0x3 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of flits received from the QPI Link.  This is one of "
                "three groups that allow us to track flits.  It includes filters for "
                "NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of "
                "information (in addition to some ECC data).  In full-width (L0) mode, "
                "flits are made up of four fits, each of which contains 20 bits of data "
                "(along with some additional ECC data).   In half-width (L0p) mode, the "
                "fits are only 10 bits, and therefore it takes twice as many fits to "
                "transmit a flit.  When one talks about QPI speed (for example, 8.0 "
                "GT/s), the transfers here refer to fits.  Therefore, in L0, the system "
                "will transfer 1 flit at the rate of 1/4th the QPI speed.  One can "
                "calculate the bandwidth of the link by taking: flits*80b/time.  Note "
                "that this is not the same as data bandwidth.  For example, when we are "
                "transfering a 64B cacheline across QPI, we will break it into 9 flits "
                "-- 1 with header information and 8 with 64 bits of actual data and an "
                "additional 16 bits of other information.  To calculate data bandwidth, "
                "one should therefore do: datld therefore do: data flits * 8B / time.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_flits_g2,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_flits_g2),
    },
    {
        .name = "UNC_Q_RXL_INSERTS",
        .code = 0x8,
        .desc =
            "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is "
            "transmitted across QPI, it will bypass the RxQ and pass directly to the "
            "ring interface.  If things back up getting transmitted onto the ring, "
            "however, it may need to allocate into this buffer, thus increasing the "
            "latency.  This event can be used in conjunction with the Flit Buffer "
            "Occupancy event in order to calculate the average flit buffer lifetime.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_INSERTS_DRS",
        .code = 0x9 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only DRS flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_INSERTS_HOM",
        .code = 0xc | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only HOM flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NCB",
        .code = 0xa | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only NCB flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NCS",
        .code = 0xb | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only NCS flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_INSERTS_NDR",
        .code = 0xe | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only NDR flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_INSERTS_SNP",
        .code = 0xd | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of allocations into the QPI Rx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the RxQ and pass "
                "directly to the ring interface.  If things back up getting transmitted "
                "onto the ring, however, it may need to allocate into this buffer, thus "
                "increasing the latency.  This event can be used in conjunction with the "
                "Flit Buffer Occupancy event in order to calculate the average flit "
                "buffer lifetime.  This monitors only SNP flits.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY",
        .code = 0xb,
        .desc =
            "Accumulates the number of elements in the QPI RxQ in each cycle.  "
            "Generally, when data is transmitted across QPI, it will bypass the RxQ and "
            "pass directly to the ring interface.  If things back up getting transmitted "
            "onto the ring, however, it may need to allocate into this buffer, thus "
            "increasing the latency.  This event can be used in conjunction with the "
            "Flit Buffer Not Empty event to calculate average occupancy, or with the "
            "Flit Buffer Allocations event to track average lifetime.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_DRS",
        .code = 0x15 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors DRS flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_HOM",
        .code = 0x18 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors HOM flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NCB",
        .code = 0x16 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors NCB flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NCS",
        .code = 0x17 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors NCS flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_NDR",
        .code = 0x1a | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors NDR flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_RXL_OCCUPANCY_SNP",
        .code = 0x19 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Accumulates the number of elements in the QPI RxQ in each cycle.  "
                "Generally, when data is transmitted across QPI, it will bypass the RxQ "
                "and pass directly to the ring interface.  If things back up getting "
                "transmitted onto the ring, however, it may need to allocate into this "
                "buffer, thus increasing the latency.  This event can be used in "
                "conjunction with the Flit Buffer Not Empty event to calculate average "
                "occupancy, or with the Flit Buffer Allocations event to track average "
                "lifetime.  This monitors SNP flits only.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXL0P_POWER_CYCLES",
        .code = 0xd,
        .desc =
            "Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we "
            "disable 1/2 of the QPI lanes, decreasing our bandwidth in order to save "
            "power.  It increases snoop and data transfer latencies and decreases "
            "overall bandwidth.  This mode can be very useful in NUMA optimized "
            "workloads that largely only utilize QPI for snoops and their responses.  "
            "Use edge detect to count the number of instances when the QPI link entered "
            "L0p.  Link power states are per link and per direction, so for example the "
            "Tx direction could be in one state while Rx was in another.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXL0_POWER_CYCLES",
        .code = 0xc,
        .desc = "Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  "
                "L0 is the default mode which provides the highest performance with the "
                "most power.  Use edge detect to count the number of instances that the "
                "link entered L0.  Link power states are per link and per direction, so "
                "for example the Tx direction could be in one state while Rx was in "
                "another.  The phy layer  sometimes leaves L0 for training, which will "
                "not be captured by this event.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXL_BYPASSED",
        .code = 0x5,
        .desc = "Counts the number of times that an incoming flit was able to bypass the "
                "Tx flit buffer and pass directly out the QPI Link. Generally, when data "
                "is transmitted across QPI, it will bypass the TxQ and pass directly to "
                "the link.  However, the TxQ will be used with L0p and when LLR occurs, "
                "increasing latency to transfer out to the link.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXL_CYCLES_NE",
        .code = 0x6,
        .desc = "Counts the number of cycles when the TxQ is not empty. Generally, when "
                "data is transmitted across QPI, it will bypass the TxQ and pass "
                "directly to the link.  However, the TxQ will be used with L0p and when "
                "LLR occurs, increasing latency to transfer out to the link.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXL_FLITS_G0",
        .code = 0x0,
        .desc = "Counts the number of flits transmitted across the QPI Link.  It "
                "includes filters for Idle, protocol, and Data Flits.  Each flit is made "
                "up of 80 bits of information (in addition to some ECC data).  In "
                "full-width (L0) mode, flits are made up of four fits, each of which "
                "contains 20 bits of data (along with some additional ECC data).   In "
                "half-width (L0p) mode, the fits are only 10 bits, and therefore it "
                "takes twice as many fits to transmit a flit.  When one talks about QPI "
                "speed (for example, 8.0 GT/s), the transfers here refer to fits.  "
                "Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th "
                "the QPI speed.  One can calculate the bandwidth of the link by taking: "
                "flits*80b/time.  Note that this is not the same as data bandwidth.  For "
                "example, when we are transfering a 64B cacheline across QPI, we will "
                "break it into 9 flits -- 1 with header information and 8 with 64 bits "
                "of actual data and an additional 16 bits of other information.  To "
                "calculate data bandwidth, one should therefore do: data flits * 8B / "
                "time (for L0) or 4B instfor L0) or 4B instead of 8B for L0p.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_txl_flits_g0,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_txl_flits_g0),
    },
    {
        .name = "UNC_Q_TXL_FLITS_G1",
        .code = 0x0 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of flits transmitted across the QPI Link.  It "
                "includes filters for Idle, protocol, and Data Flits.  Each flit is made "
                "up of 80 bits of information (in addition to some ECC data).  In "
                "full-width (L0) mode, flits are made up of four fits, each of which "
                "contains 20 bits of data (along with some additional ECC data).   In "
                "half-width (L0p) mode, the fits are only 10 bits, and therefore it "
                "takes twice as many fits to transmit a flit.  When one talks about QPI "
                "speed (for example, 8.0 GT/s), the transfers here refer to fits.  "
                "Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th "
                "the QPI speed.  One can calculate the bandwidth of the link by taking: "
                "flits*80b/time.  Note that this is not the same as data bandwidth.  For "
                "example, when we are transfering a 64B cacheline across QPI, we will "
                "break it into 9 flits -- 1 with header information and 8 with 64 bits "
                "of actual data and an additional 16 bits of other information.  To "
                "calculate data bandwidth, one should therefore do: data flits * 8B / "
                "time (for L0) or 4B instfor L0) or 4B instead of 8B for L0p.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_txl_flits_g1,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_txl_flits_g1),
    },
    {
        .name = "UNC_Q_TXL_FLITS_G2",
        .code = 0x1 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Counts the number of flits trasmitted across the QPI Link.  This is one "
                "of three groups that allow us to track flits.  It includes filters for "
                "NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of "
                "information (in addition to some ECC data).  In full-width (L0) mode, "
                "flits are made up of four fits, each of which contains 20 bits of data "
                "(along with some additional ECC data).   In half-width (L0p) mode, the "
                "fits are only 10 bits, and therefore it takes twice as many fits to "
                "transmit a flit.  When one talks about QPI speed (for example, 8.0 "
                "GT/s), the transfers here refer to fits.  Therefore, in L0, the system "
                "will transfer 1 flit at the rate of 1/4th the QPI speed.  One can "
                "calculate the bandwidth of the link by taking: flits*80b/time.  Note "
                "that this is not the same as data bandwidth.  For example, when we are "
                "transfering a 64B cacheline across QPI, we will break it into 9 flits "
                "-- 1 with header information and 8 with 64 bits of actual data and an "
                "additional 16 bits of other information.  To calculate data bandwidth, "
                "one should therefore do: datld therefore do: data flits * 8B / time.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_txl_flits_g2,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_txl_flits_g2),
    },
    {
        .name = "UNC_Q_TXL_INSERTS",
        .code = 0x4,
        .desc = "Number of allocations into the QPI Tx Flit Buffer.  Generally, when "
                "data is transmitted across QPI, it will bypass the TxQ and pass "
                "directly to the link.  However, the TxQ will be used with L0p and when "
                "LLR occurs, increasing latency to transfer out to the link.  This event "
                "can be used in conjunction with the Flit Buffer Occupancy event in "
                "order to calculate the average flit buffer lifetime.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXL_OCCUPANCY",
        .code = 0x7,
        .desc = "Accumulates the number of flits in the TxQ.  Generally, when data is "
                "transmitted across QPI, it will bypass the TxQ and pass directly to the "
                "link.  However, the TxQ will be used with L0p and when LLR occurs, "
                "increasing latency to transfer out to the link. This can be used with "
                "the cycles not empty event to track average occupancy, or the "
                "allocations event to track average lifetime in the TxQ.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXR_AD_HOM_CREDIT_ACQUIRED",
        .code = 0x26 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of link layer credits into the R3 (for transactions across the "
                "BGF) acquired each cycle. Flow Control FIFO for Home messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AD_HOM_CREDIT_OCCUPANCY",
        .code = 0x22 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of link layer credits into the "
                "R3 (for transactions across the BGF) available in each cycle.  Flow "
                "Control FIFO for HOM messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AD_NDR_CREDIT_ACQUIRED",
        .code = 0x28 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of link layer credits into the R3 (for transactions across the "
                "BGF) acquired each cycle.  Flow Control FIFO for NDR messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AD_NDR_CREDIT_OCCUPANCY",
        .code = 0x24 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of link layer credits into the "
                "R3 (for transactions across the BGF) available in each cycle. Flow "
                "Control FIFO  for NDR messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AD_SNP_CREDIT_ACQUIRED",
        .code = 0x27 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of link layer credits into the R3 (for transactions across the "
                "BGF) acquired each cycle.  Flow Control FIFO for Snoop messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AD_SNP_CREDIT_OCCUPANCY",
        .code = 0x23 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of link layer credits into the "
                "R3 (for transactions across the BGF) available in each cycle.  Flow "
                "Control FIFO fro Snoop messages on AD.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_AK_NDR_CREDIT_ACQUIRED",
        .code = 0x29 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of credits into the R3 (for transactions across the BGF) "
                "acquired each cycle. Local NDR message class to AK Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXR_AK_NDR_CREDIT_OCCUPANCY",
        .code = 0x25 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of credits into the R3 (for "
                "transactions across the BGF) available in each cycle.  Local NDR "
                "message class to AK Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED",
        .code = 0x2a | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of credits into the R3 (for transactions across the BGF) "
                "acquired each cycle. DRS message class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_txr_bl_drs_credit_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_txr_bl_drs_credit_acquired),
    },
    {
        .name = "UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY",
        .code = 0x1f | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of credits into the R3 (for "
                "transactions across the BGF) available in each cycle.  DRS message "
                "class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_txr_bl_drs_credit_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_txr_bl_drs_credit_acquired),
    },
    {
        .name = "UNC_Q_TXR_BL_NCB_CREDIT_ACQUIRED",
        .code = 0x2b | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of credits into the R3 (for transactions across the BGF) "
                "acquired each cycle. NCB message class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_BL_NCB_CREDIT_OCCUPANCY",
        .code = 0x20 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of credits into the R3 (for "
                "transactions across the BGF) available in each cycle.  NCB message "
                "class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_BL_NCS_CREDIT_ACQUIRED",
        .code = 0x2c | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of credits into the R3 (for transactions across the BGF) "
                "acquired each cycle. NCS message class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_TXR_BL_NCS_CREDIT_OCCUPANCY",
        .code = 0x21 | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Occupancy event that tracks the number of credits into the R3 (for "
                "transactions across the BGF) available in each cycle.  NCS message "
                "class to BL Egress.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_q_rxl_inserts_drs,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_q_rxl_inserts_drs),
    },
    {
        .name = "UNC_Q_VNA_CREDIT_RETURNS",
        .code = 0x1c | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of VNA credits returned.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_Q_VNA_CREDIT_RETURN_OCCUPANCY",
        .code = 0x1b | (1 << 21), /* extra ev_sel_ext bit set */
        .desc = "Number of VNA credits in the Rx side that are waitng to be returned "
                "back across the link.",
        .modmsk = BDX_UNC_QPI_ATTRS,
        .cntmsk = 0xf,
    },
};
