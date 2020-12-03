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
 * PMU: bdx_unc_pcu
 */

static intel_x86_umask_t bdx_unc_p_power_state_occupancy[] = {
    {
        .uname = "CORES_C0",
        .ucode = 0x4000,
        .udesc = "Number of cores in C-State -- C0 and C1",
    },
    {
        .uname = "CORES_C3",
        .ucode = 0x8000,
        .udesc = "Number of cores in C-State -- C3",
    },
    {
        .uname = "CORES_C6",
        .ucode = 0xc000,
        .udesc = "Number of cores in C-State -- C6 and C7",
    },
};

static intel_x86_entry_t intel_bdx_unc_p_pe[] = {
    {
        .name = "UNC_P_CLOCKTICKS",
        .code = 0x0,
        .desc = "The PCU runs off a fixed 1 GHz clock.  This event counts the number of "
                "pclk cycles measured while the counter was enabled.  The pclk, like the "
                "Memory Controllers dclk, counts at a constant rate making it a good "
                "measure of actual wall timee.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE0_TRANSITION_CYCLES",
        .code = 0x60,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE10_TRANSITION_CYCLES",
        .code = 0x6a,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE11_TRANSITION_CYCLES",
        .code = 0x6b,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE12_TRANSITION_CYCLES",
        .code = 0x6c,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE13_TRANSITION_CYCLES",
        .code = 0x6d,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE14_TRANSITION_CYCLES",
        .code = 0x6e,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE15_TRANSITION_CYCLES",
        .code = 0x6f,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE16_TRANSITION_CYCLES",
        .code = 0x70,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE17_TRANSITION_CYCLES",
        .code = 0x71,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE1_TRANSITION_CYCLES",
        .code = 0x61,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE2_TRANSITION_CYCLES",
        .code = 0x62,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE3_TRANSITION_CYCLES",
        .code = 0x63,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE4_TRANSITION_CYCLES",
        .code = 0x64,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE5_TRANSITION_CYCLES",
        .code = 0x65,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE6_TRANSITION_CYCLES",
        .code = 0x66,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE7_TRANSITION_CYCLES",
        .code = 0x67,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE8_TRANSITION_CYCLES",
        .code = 0x68,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE9_TRANSITION_CYCLES",
        .code = 0x69,
        .desc = "Number of cycles spent performing core C state transitions.  There is "
                "one event per core.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE0",
        .code = 0x30,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE1",
        .code = 0x31,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE10",
        .code = 0x3a,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE11",
        .code = 0x3b,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE12",
        .code = 0x3c,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE13",
        .code = 0x3d,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE14",
        .code = 0x3e,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE15",
        .code = 0x3f,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE16",
        .code = 0x40,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE17",
        .code = 0x41,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE2",
        .code = 0x32,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE3",
        .code = 0x33,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE4",
        .code = 0x34,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE5",
        .code = 0x35,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE6",
        .code = 0x36,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE7",
        .code = 0x37,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE8",
        .code = 0x38,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS_CORE9",
        .code = 0x39,
        .desc =
            "Counts the number of times when a configurable cores had a C-state demotion",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_MAX_LIMIT_THERMAL_CYCLES",
        .code = 0x4,
        .desc = "Counts the number of cycles when thermal conditions are the upper limit "
                "on frequency.  This is related to the THERMAL_THROTTLE "
                "CYCLES_ABOVE_TEMP event, which always counts cycles when we are above "
                "the thermal temperature.  This event (STRONGEST_UPPER_LIMIT) is sampled "
                "at the output of the algorithm that determines the actual frequency, "
                "while THERMAL_THROTTLE looks at the input.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_MAX_OS_CYCLES",
        .code = 0x6,
        .desc =
            "Counts the number of cycles when the OS is the upper limit on frequency.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_MAX_POWER_CYCLES",
        .code = 0x5,
        .desc = "Counts the number of cycles when power is the upper limit on frequency.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_MIN_IO_P_CYCLES",
        .code = 0x73,
        .desc =
            "Counts the number of cycles when IO P Limit is preventing us from dropping "
            "the frequency lower.  This algorithm monitors the needs to the IO subsystem "
            "on both local and remote sockets and will maintain a frequency high enough "
            "to maintain good IO BW.  This is necessary for when all the IA cores on a "
            "socket are idle but a user still would like to maintain high IO Bandwidth.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_TRANS_CYCLES",
        .code = 0x74,
        .desc = "Counts the number of cycles when the system is changing frequency.  "
                "This can not be filtered by thread ID.  One can also use it with the "
                "occupancy counter that monitors number of threads in C0 to estimate the "
                "performance impact that frequency transitions had on the system.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_MEMORY_PHASE_SHEDDING_CYCLES",
        .code = 0x2f,
        .desc = "Counts the number of cycles that the PCU has triggered memory phase "
                "shedding.  This is a mode that can be run in the iMC physicals that "
                "saves power at the expense of additional latency.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_POWER_STATE_OCCUPANCY",
        .code = 0x80,
        .desc =
            "This is an occupancy event that tracks the number of cores that are in the "
            "chosen C-State.  It can be used by itself to get the average number of "
            "cores in that C-state with threshholding to generate histograms, or with "
            "other PCU events and occupancy triggering to capture other details.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = bdx_unc_p_power_state_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(bdx_unc_p_power_state_occupancy),
    },
    {
        .name = "UNC_P_PROCHOT_EXTERNAL_CYCLES",
        .code = 0xa,
        .desc = "Counts the number of cycles that we are in external PROCHOT mode.  This "
                "mode is triggered when a sensor off the die determines that something "
                "off-die (like DRAM) is too hot and must throttle to avoid damaging the "
                "chip.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PROCHOT_INTERNAL_CYCLES",
        .code = 0x9,
        .desc = "Counts the number of cycles that we are in Interal PROCHOT mode.  This "
                "mode is triggered when a sensor on the die determines that we are too "
                "hot and must throttle to avoid damaging the chip.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_TOTAL_TRANSITION_CYCLES",
        .code = 0x72,
        .desc = "Number of cycles spent performing core C state transitions across all "
                "cores.",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_BANDWIDTH_MAX_RANGE",
        .code = 0x7e,
        .desc = "TBD",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_TRANSITIONS_DOWN",
        .code = 0x7c,
        .desc = "Ring GV down due to low traffic",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_TRANSITIONS_IO_P_LIMIT",
        .code = 0x7d,
        .desc = "TBD",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_TRANSITIONS_NO_CHANGE",
        .code = 0x79,
        .desc = "Ring GV with same final and inital frequency",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_TRANSITIONS_UP_RING",
        .code = 0x7a,
        .desc = "Ring GV up due to high ring traffic",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_UFS_TRANSITIONS_UP_STALL",
        .code = 0x7b,
        .desc = "Ring GV up due to high core stalls",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_VR_HOT_CYCLES",
        .code = 0x42,
        .desc = "TBD",
        .modmsk = BDX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_BAND0_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xb,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = BDX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND1_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xc,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = BDX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND2_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xd,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = BDX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND3_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xe,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = BDX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FIVR_PS_PS0_CYCLES",
        .desc = "Cycles spent in phase-shedding power state 0",
        .code = 0x75,
        .cntmsk = 0xf,
        .modmsk = BDX_UNC_PCU_ATTRS,
    },
    {
        .name = "UNC_P_FIVR_PS_PS1_CYCLES",
        .desc = "Cycles spent in phase-shedding power state 1",
        .code = 0x76,
        .cntmsk = 0xf,
        .modmsk = BDX_UNC_PCU_ATTRS,
    },
    {
        .name = "UNC_P_FIVR_PS_PS2_CYCLES",
        .desc = "Cycles spent in phase-shedding power state 2",
        .code = 0x77,
        .cntmsk = 0xf,
        .modmsk = BDX_UNC_PCU_ATTRS,
    },
    {
        .name = "UNC_P_FIVR_PS_PS3_CYCLES",
        .desc = "Cycles spent in phase-shedding power state 3",
        .code = 0x78,
        .cntmsk = 0xf,
        .modmsk = BDX_UNC_PCU_ATTRS,
    },
};
