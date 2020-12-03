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
 * PMU: skx_unc_pcu
 */

static intel_x86_umask_t skx_unc_p_power_state_occupancy[] = {
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

static intel_x86_entry_t intel_skx_unc_p_pe[] = {
    {
        .name = "UNC_P_CLOCKTICKS",
        .code = 0x0,
        .desc = "The PCU runs off a fixed 1 GHz clock.  This event counts the number of "
                "pclk cycles measured while the counter was enabled.  The pclk, like the "
                "Memory Controllers dclk, counts at a constant rate making it a good "
                "measure of actual wall timee.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CORE_TRANSITION_CYCLES",
        .code = 0x60,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CTS_EVENT0",
        .code = 0x11,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_CTS_EVENT1",
        .code = 0x12,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_DEMOTIONS",
        .code = 0x30,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FIVR_PS_PS0_CYCLES",
        .code = 0x75,
        .desc = "Cycles spent in phase-shedding power state 0",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FIVR_PS_PS1_CYCLES",
        .code = 0x76,
        .desc = "Cycles spent in phase-shedding power state 1",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FIVR_PS_PS2_CYCLES",
        .code = 0x77,
        .desc = "Cycles spent in phase-shedding power state 2",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FIVR_PS_PS3_CYCLES",
        .code = 0x78,
        .desc = "Cycles spent in phase-shedding power state 3",
        .modmsk = SKX_UNC_PCU_ATTRS,
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
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_MAX_POWER_CYCLES",
        .code = 0x5,
        .desc = "Counts the number of cycles when power is the upper limit on frequency.",
        .modmsk = SKX_UNC_PCU_ATTRS,
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
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_TRANS_CYCLES",
        .code = 0x74,
        .desc = "Counts the number of cycles when the system is changing frequency.  "
                "This can not be filtered by thread ID.  One can also use it with the "
                "occupancy counter that monitors number of threads in C0 to estimate the "
                "performance impact that frequency transitions had on the system.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_MCP_PROCHOT_CYCLES",
        .code = 0x6,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_MEMORY_PHASE_SHEDDING_CYCLES",
        .code = 0x2f,
        .desc = "Counts the number of cycles that the PCU has triggered memory phase "
                "shedding.  This is a mode that can be run in the iMC physicals that "
                "saves power at the expense of additional latency.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PKG_RESIDENCY_C0_CYCLES",
        .code = 0x2a,
        .desc = "Counts the number of cycles when the package was in C0.  This event can "
                "be used in conjunction with edge detect to count C0 entrances (or exits "
                "using invert).  Residency events do not include transition times.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PKG_RESIDENCY_C2E_CYCLES",
        .code = 0x2b,
        .desc = "Counts the number of cycles when the package was in C2E.  This event "
                "can be used in conjunction with edge detect to count C2E entrances (or "
                "exits using invert).  Residency events do not include transition times.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PKG_RESIDENCY_C3_CYCLES",
        .code = 0x2c,
        .desc = "Counts the number of cycles when the package was in C3.  This event can "
                "be used in conjunction with edge detect to count C3 entrances (or exits "
                "using invert).  Residency events do not include transition times.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PKG_RESIDENCY_C6_CYCLES",
        .code = 0x2d,
        .desc = "Counts the number of cycles when the package was in C6.  This event can "
                "be used in conjunction with edge detect to count C6 entrances (or exits "
                "using invert).  Residency events do not include transition times.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PMAX_THROTTLED_CYCLES",
        .code = 0x7,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PROCHOT_EXTERNAL_CYCLES",
        .code = 0xa,
        .desc = "Counts the number of cycles that we are in external PROCHOT mode.  This "
                "mode is triggered when a sensor off the die determines that something "
                "off-die (like DRAM) is too hot and must throttle to avoid damaging the "
                "chip.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_PROCHOT_INTERNAL_CYCLES",
        .code = 0x9,
        .desc = "Counts the number of cycles that we are in Interal PROCHOT mode.  This "
                "mode is triggered when a sensor on the die determines that we are too "
                "hot and must throttle to avoid damaging the chip.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_TOTAL_TRANSITION_CYCLES",
        .code = 0x72,
        .desc = "Number of cycles spent performing core C state transitions across all "
                "cores.",
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_P_FREQ_BAND0_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xb,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = SKX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND1_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xc,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = SKX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND2_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xd,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = SKX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_FREQ_BAND3_CYCLES",
        .desc = "Frequency Residency",
        .code = 0xe,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .modmsk = SKX_UNC_PCU_BAND_ATTRS,
        .modmsk_req = _SNBEP_UNC_ATTR_FF,
    },
    {
        .name = "UNC_P_VR_HOT_CYCLES",
        .code = 0x42,
        .desc = "TBD",
        .modmsk = SKX_UNC_PCU_ATTRS,
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
        .modmsk = SKX_UNC_PCU_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_p_power_state_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_p_power_state_occupancy),
    },
};
