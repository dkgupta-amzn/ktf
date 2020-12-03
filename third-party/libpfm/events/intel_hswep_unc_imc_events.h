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
 * PMU: hswep_unc_imc (Intel Haswell-EP IMC uncore PMU)
 */

static const intel_x86_umask_t hswep_unc_m_cas_count[] = {
    {
        .uname = "ALL",
        .udesc = "Counts total number of DRAM CAS commands issued on this channel",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "RD",
        .udesc = "Counts all DRAM reads on this channel, incl. underfills",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RD_REG",
        .udesc = "Counts number of DRAM read CAS commands issued on this channel, incl. "
                 "regular read CAS and those with implicit precharge",
        .ucode = 0x100,
    },
    {
        .uname = "RD_UNDERFILL",
        .udesc = "Counts number of underfill reads issued by the memory controller",
        .ucode = 0x200,
    },
    {
        .uname = "WR",
        .udesc = "Counts number of DRAM write CAS commands on this channel",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WR_RMM",
        .udesc = "Counts Number of opportunistic DRAM write CAS commands issued on this "
                 "channel",
        .ucode = 0x800,
    },
    {
        .uname = "WR_WMM",
        .udesc = "Counts number of DRAM write CAS commands issued on this channel while "
                 "in Write-Major mode",
        .ucode = 0x400,
    },
    {
        .uname = "RD_RMM",
        .udesc = "Counts Number of opportunistic DRAM read CAS commands issued on this "
                 "channel",
        .ucode = 0x1000,
    },
    {
        .uname = "RD_WMM",
        .udesc = "Counts number of DRAM read CAS commands issued on this channel while "
                 "in Write-Major mode",
        .ucode = 0x2000,
    },
};

static const intel_x86_umask_t hswep_unc_m_dram_refresh[] = {
    {
        .uname = "HIGH",
        .udesc = "High",
        .ucode = 0x400,
    },
    {
        .uname = "PANIC",
        .udesc = "Panic",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t hswep_unc_m_major_modes[] = {
    {
        .uname = "ISOCH",
        .udesc = "Counts cycles in ISOCH Major mode",
        .ucode = 0x800,
    },
    {
        .uname = "PARTIAL",
        .udesc = "Counts cycles in Partial Major mode",
        .ucode = 0x400,
    },
    {
        .uname = "READ",
        .udesc = "Counts cycles in Read Major mode",
        .ucode = 0x100,
    },
    {
        .uname = "WRITE",
        .udesc = "Counts cycles in Write Major mode",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t hswep_unc_m_power_cke_cycles[] = {
    {
        .uname = "RANK0",
        .udesc = "Count cycles for rank 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK1",
        .udesc = "Count cycles for rank 1",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK2",
        .udesc = "Count cycles for rank 2",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK3",
        .udesc = "Count cycles for rank 3",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK4",
        .udesc = "Count cycles for rank 4",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK5",
        .udesc = "Count cycles for rank 5",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK6",
        .udesc = "Count cycles for rank 6",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RANK7",
        .udesc = "Count cycles for rank 7",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t hswep_unc_m_preemption[] = {
    {
        .uname = "RD_PREEMPT_RD",
        .udesc = "Counts read over read preemptions",
        .ucode = 0x100,
    },
    {
        .uname = "RD_PREEMPT_WR",
        .udesc = "Counts read over write preemptions",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t hswep_unc_m_pre_count[] = {
    {
        .uname = "PAGE_CLOSE",
        .udesc = "Counts number of DRAM precharge commands sent on this channel as a "
                 "result of the page close counter expiring",
        .ucode = 0x200,
    },
    {
        .uname = "PAGE_MISS",
        .udesc = "Counts number of DRAM precharge commands sent on this channel as a "
                 "result of page misses",
        .ucode = 0x100,
    },
    {
        .uname = "RD",
        .udesc = "Precharge due to read",
        .ucode = 0x400,
    },
    {
        .uname = "WR",
        .udesc = "Precharge due to write",
        .ucode = 0x800,
    },
    {
        .uname = "BYP",
        .udesc = "Precharge due to bypass",
        .ucode = 0x1000,
    },
};

static const intel_x86_umask_t hswep_unc_m_act_count[] = {
    {
        .uname = "RD",
        .udesc = "Activate due to read",
        .ucode = 0x100,
    },
    {
        .uname = "WR",
        .udesc = "Activate due to write",
        .ucode = 0x200,
    },
    {
        .uname = "BYP",
        .udesc = "Activate due to bypass",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t hswep_unc_m_byp_cmds[] = {
    {
        .uname = "ACT",
        .udesc = "ACT command issued by 2 cycle bypass",
        .ucode = 0x100,
    },
    {
        .uname = "CAS",
        .udesc = "CAS command issued by 2 cycle bypass",
        .ucode = 0x200,
    },
    {
        .uname = "PRE",
        .udesc = "PRE command issued by 2 cycle bypass",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t hswep_unc_m_rd_cas_prio[] = {
    {
        .uname = "LOW",
        .udesc = "Read CAS issued with low priority",
        .ucode = 0x100,
    },
    {
        .uname = "MED",
        .udesc = "Read CAS issued with medium priority",
        .ucode = 0x200,
    },
    {
        .uname = "HIGH",
        .udesc = "Read CAS issued with high priority",
        .ucode = 0x400,
    },
    {
        .uname = "PANIC",
        .udesc = "Read CAS issued with panic non isoch priority (starved)",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t hswep_unc_m_rd_cas_rank0[] = {
    {
        .uname = "BANK0",
        .udesc = "Bank 0",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK1",
        .udesc = "Bank 1",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK2",
        .udesc = "Bank 2",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK3",
        .udesc = "Bank 3",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK4",
        .udesc = "Bank 4",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK5",
        .udesc = "Bank 5",
        .ucode = 0x500,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK6",
        .udesc = "Bank 6",
        .ucode = 0x600,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK7",
        .udesc = "Bank 7",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK8",
        .udesc = "Bank 8",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK9",
        .udesc = "Bank 9",
        .ucode = 0x900,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK10",
        .udesc = "Bank 10",
        .ucode = 0xa00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK11",
        .udesc = "Bank 11",
        .ucode = 0xb00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK12",
        .udesc = "Bank 12",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK13",
        .udesc = "Bank 13",
        .ucode = 0xd000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK14",
        .udesc = "Bank 14",
        .ucode = 0xe000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANK15",
        .udesc = "Bank 15",
        .ucode = 0xf000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALLBANKS",
        .udesc = "Bank 15",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "BANKG0",
        .udesc = "Bank Group 0 (bank 0-3)",
        .ucode = 0x1100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANKG1",
        .udesc = "Bank Group 1 (bank 4-7)",
        .ucode = 0x12000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANKG2",
        .udesc = "Bank Group 2 (8-11)",
        .ucode = 0x13000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "BANKG3",
        .udesc = "Bank Group 3 (12-15)",
        .ucode = 0x14000,
        .uflags = INTEL_X86_NCOMBO,
    }};

static const intel_x86_umask_t hswep_unc_m_vmse_wr_push[] = {
    {
        .uname = "WMM",
        .udesc = "VMSE write push issued in WMM",
        .ucode = 0x100,
    },
    {
        .uname = "RMM",
        .udesc = "VMSE write push issued in RMM",
        .ucode = 0x200,
    }};

static const intel_x86_umask_t hswep_unc_m_wmm_to_rmm[] = {
    {
        .uname = "LOW_THRES",
        .udesc = "Transition from WMM to RMM because of starve counter",
        .ucode = 0x100,
    },
    {
        .uname = "STARVE",
        .udesc = "Starve",
        .ucode = 0x200,
    },
    {
        .uname = "VMSE_RETRY",
        .udesc = "VMSE retry",
        .ucode = 0x400,
    }};

static const intel_x86_entry_t intel_hswep_unc_m_pe[] = {
    {
        .name = "UNC_M_CLOCKTICKS",
        .desc = "IMC Uncore clockticks (fixed counter)",
        .modmsk = 0x0,
        .cntmsk = 0x100000000ull,
        .code = 0xff, /* perf pseudo encoding for fixed counter */
        .flags = INTEL_X86_FIXED,
    },
    {
        .name = "UNC_M_DCLOCKTICKS",
        .desc = "IMC Uncore clockticks (generic counters)",
        .modmsk = HSWEP_UNC_IMC_ATTRS,
        .cntmsk = 0xf,
        .code = 0x00, /*encoding for generic counters */
    },
    {.name = "UNC_M_ACT_COUNT",
     .desc = "DRAM Activate Count",
     .code = 0x1,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_act_count),
     .umasks = hswep_unc_m_act_count},
    {.name = "UNC_M_CAS_COUNT",
     .desc = "DRAM RD_CAS and WR_CAS Commands.",
     .code = 0x4,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_cas_count),
     .umasks = hswep_unc_m_cas_count},
    {
        .name = "UNC_M_DRAM_PRE_ALL",
        .desc = "DRAM Precharge All Commands",
        .code = 0x6,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_DRAM_REFRESH",
     .desc = "Number of DRAM Refreshes Issued",
     .code = 0x5,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_dram_refresh),
     .umasks = hswep_unc_m_dram_refresh},
    {
        .name = "UNC_M_ECC_CORRECTABLE_ERRORS",
        .desc = "ECC Correctable Errors",
        .code = 0x9,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_MAJOR_MODES",
     .desc = "Cycles in a Major Mode",
     .code = 0x7,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_major_modes),
     .umasks = hswep_unc_m_major_modes},
    {
        .name = "UNC_M_POWER_CHANNEL_DLLOFF",
        .desc = "Channel DLLOFF Cycles",
        .code = 0x84,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_POWER_CHANNEL_PPD",
        .desc = "Channel PPD Cycles",
        .code = 0x85,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_POWER_CKE_CYCLES",
     .desc = "CKE_ON_CYCLES by Rank",
     .code = 0x83,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_power_cke_cycles),
     .umasks = hswep_unc_m_power_cke_cycles},
    {
        .name = "UNC_M_POWER_CRITICAL_THROTTLE_CYCLES",
        .desc = "Critical Throttle Cycles",
        .code = 0x86,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_POWER_SELF_REFRESH",
        .desc = "Clock-Enabled Self-Refresh",
        .code = 0x43,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_POWER_THROTTLE_CYCLES",
        .desc = "Throttle Cycles",
        .code = 0x41,
        .cntmsk = 0xf,
        .ngrp = 1,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_power_cke_cycles),
        .umasks =
            hswep_unc_m_power_cke_cycles /* identical to snbep_unc_m_power_cke_cycles */
    },
    {
        .name = "UNC_M_POWER_PCU_THROTTLING",
        .desc = "PCU throttling",
        .code = 0x42,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_PREEMPTION",
     .desc = "Read Preemption Count",
     .code = 0x8,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_preemption),
     .umasks = hswep_unc_m_preemption},
    {.name = "UNC_M_PRE_COUNT",
     .desc = "DRAM Precharge commands.",
     .code = 0x2,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_pre_count),
     .umasks = hswep_unc_m_pre_count},
    {
        .name = "UNC_M_RPQ_CYCLES_NE",
        .desc = "Read Pending Queue Not Empty",
        .code = 0x11,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_RPQ_INSERTS",
        .desc = "Read Pending Queue Allocations",
        .code = 0x10,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_WPQ_CYCLES_FULL",
        .desc = "Write Pending Queue Full Cycles",
        .code = 0x22,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_WPQ_CYCLES_NE",
        .desc = "Write Pending Queue Not Empty",
        .code = 0x21,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_WPQ_READ_HIT",
        .desc = "Write Pending Queue CAM Match",
        .code = 0x23,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {
        .name = "UNC_M_WPQ_WRITE_HIT",
        .desc = "Write Pending Queue CAM Match",
        .code = 0x24,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_BYP_CMDS",
     .desc = "Bypass command event",
     .code = 0xa1,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_byp_cmds),
     .umasks = hswep_unc_m_byp_cmds},
    {.name = "UNC_M_RD_CAS_PRIO",
     .desc = "Read CAS priority",
     .code = 0xa0,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_prio),
     .umasks = hswep_unc_m_rd_cas_prio},
    {.name = "UNC_M_RD_CAS_RANK0",
     .desc = "Read CAS access to Rank 0",
     .code = 0xb0,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0),
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK1",
     .desc = "Read CAS access to Rank 1",
     .code = 0xb1,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK2",
     .desc = "Read CAS access to Rank 2",
     .code = 0xb2,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK3",
     .desc = "Read CAS access to Rank 3",
     .code = 0xb3,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK4",
     .desc = "Read CAS access to Rank 4",
     .code = 0xb4,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK5",
     .desc = "Read CAS access to Rank 5",
     .code = 0xb5,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK6",
     .desc = "Read CAS access to Rank 6",
     .code = 0xb6,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_RD_CAS_RANK7",
     .desc = "Read CAS access to Rank 7",
     .code = 0xb7,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {
        .name = "UNC_M_VMSE_MXB_WR_OCCUPANCY",
        .desc = "VMSE MXB write buffer occupancy",
        .code = 0x91,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_VMSE_WR_PUSH",
     .desc = "VMSE WR push issued",
     .code = 0x90,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_vmse_wr_push),
     .umasks = hswep_unc_m_vmse_wr_push},
    {.name = "UNC_M_WMM_TO_RMM",
     .desc = "Transitions from WMM to RMM because of low threshold",
     .code = 0xc0,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_wmm_to_rmm),
     .umasks = hswep_unc_m_wmm_to_rmm},
    {
        .name = "UNC_M_WRONG_MM",
        .desc = "Not getting the requested major mode",
        .code = 0xc1,
        .cntmsk = 0xf,
        .modmsk = HSWEP_UNC_IMC_ATTRS,
    },
    {.name = "UNC_M_WR_CAS_RANK0",
     .desc = "Write CAS access to Rank 0",
     .code = 0xb8,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK1",
     .desc = "Write CAS access to Rank 1",
     .code = 0xb9,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK2",
     .desc = "Write CAS access to Rank 2",
     .code = 0xba,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK3",
     .desc = "Write CAS access to Rank 3",
     .code = 0xbb,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK4",
     .desc = "Write CAS access to Rank 4",
     .code = 0xbc,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK5",
     .desc = "Write CAS access to Rank 5",
     .code = 0xbd,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK6",
     .desc = "Write CAS access to Rank 6",
     .code = 0xbe,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
    {.name = "UNC_M_WR_CAS_RANK7",
     .desc = "Write CAS access to Rank 7",
     .code = 0xbf,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = HSWEP_UNC_IMC_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(hswep_unc_m_rd_cas_rank0), /* shared */
     .umasks = hswep_unc_m_rd_cas_rank0},
};
