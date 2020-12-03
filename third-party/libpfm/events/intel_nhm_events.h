/*
 * Copyright (c) 2011 Google, Inc
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
 * This file has been automatically generated.
 *
 * PMU: nhm (Intel Nehalem)
 */

static const intel_x86_umask_t nhm_arith[] = {
    {
        .uname = "CYCLES_DIV_BUSY",
        .udesc =
            "Counts the number of cycles the divider is busy executing divide or square "
            "root operations. The divide can be integer, X87 or Streaming SIMD "
            "Extensions (SSE). The square root operation can be either X87 or SSE.",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIV",
        .udesc = "Counts the number of divide or square root operations. The divide can "
                 "be integer, X87 or Streaming SIMD Extensions (SSE). The square root "
                 "operation can be either X87 or SSE.",
        .uequiv = "CYCLES_DIV_BUSY:c=1:i=1:e=1",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MUL",
        .udesc =
            "Counts the number of multiply operations executed. This includes integer as "
            "well as floating point multiply operations but excludes DPPS mul and MPSAD.",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_baclear[] = {
    {
        .uname = "BAD_TARGET",
        .udesc = "BACLEAR asserted with bad target address",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CLEAR",
        .udesc = "BACLEAR asserted, regardless of cause",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_bpu_clears[] = {
    {
        .uname = "EARLY",
        .udesc = "Early Branch Prediction Unit clears",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LATE",
        .udesc = "Late Branch Prediction Unit clears",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "Count any Branch Prediction Unit clears",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_br_inst_exec[] = {
    {
        .uname = "ANY",
        .udesc = "Branch instructions executed",
        .ucode = 0x7f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "COND",
        .udesc = "Conditional branch instructions executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRECT",
        .udesc = "Unconditional branches executed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRECT_NEAR_CALL",
        .udesc = "Unconditional call branches executed",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INDIRECT_NEAR_CALL",
        .udesc = "Indirect call branches executed",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INDIRECT_NON_CALL",
        .udesc = "Indirect non call branches executed",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NEAR_CALLS",
        .udesc = "Call branches executed",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NON_CALLS",
        .udesc = "All non call branches executed",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RETURN_NEAR",
        .udesc = "Indirect return branches executed",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN",
        .udesc = "Taken branches executed",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_br_inst_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Retired branch instructions (Precise Event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "CONDITIONAL",
        .udesc = "Retired conditional branch instructions (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_CALL",
        .udesc = "Retired near call instructions (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_br_misp_exec[] = {
    {
        .uname = "ANY",
        .udesc = "Mispredicted branches executed",
        .ucode = 0x7f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "COND",
        .udesc = "Mispredicted conditional branches executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRECT",
        .udesc = "Mispredicted unconditional branches executed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRECT_NEAR_CALL",
        .udesc = "Mispredicted non call branches executed",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INDIRECT_NEAR_CALL",
        .udesc = "Mispredicted indirect call branches executed",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INDIRECT_NON_CALL",
        .udesc = "Mispredicted indirect non call branches executed",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NEAR_CALLS",
        .udesc = "Mispredicted call branches executed",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NON_CALLS",
        .udesc = "Mispredicted non call branches executed",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RETURN_NEAR",
        .udesc = "Mispredicted return branches executed",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN",
        .udesc = "Mispredicted taken branches executed",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_br_misp_retired[] = {
    {
        .uname = "NEAR_CALL",
        .udesc =
            "Counts mispredicted direct and indirect near unconditional retired calls",
        .ucode = 0x200,
        .uflags = INTEL_X86_PEBS | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_cache_lock_cycles[] = {
    {
        .uname = "L1D",
        .udesc = "Cycles L1D locked",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_L2",
        .udesc = "Cycles L1D and L2 locked",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_cpu_clk_unhalted[] = {
    {
        .uname = "THREAD_P",
        .udesc = "Cycles when thread is not halted (programmable counter)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "REF_P",
        .udesc = "Reference base clock (133 Mhz) cycles when thread is not halted",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TOTAL_CYCLES",
        .udesc = "Total number of elapsed cycles. Does not work when C-state enabled",
        .uequiv = "THREAD_P:c=2:i=1",
        .ucode = 0x0 | INTEL_X86_MOD_INV | (0x2 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_dtlb_load_misses[] = {
    {
        .uname = "ANY",
        .udesc = "DTLB load misses",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "PDE_MISS",
        .udesc = "DTLB load miss caused by low part of address",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc = "DTLB load miss page walks complete",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "DTLB second level hit",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PDP_MISS",
        .udesc = "Number of DTLB cache load misses where the high part of the linear to "
                 "physical address translation was missed",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LARGE_WALK_COMPLETED",
        .udesc =
            "Counts number of completed large page walks due to load miss in the STLB",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_dtlb_misses[] = {
    {
        .uname = "ANY",
        .udesc = "DTLB misses",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "DTLB first level misses but second level hit",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc = "DTLB miss page walks",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PDE_MISS",
        .udesc = "Number of DTLB cache misses where the low part of the linear to "
                 "physical address translation was missed",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PDP_MISS",
        .udesc = "Number of DTLB misses where the high part of the linear to physical "
                 "address translation was missed",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LARGE_WALK_COMPLETED",
        .udesc = "Counts number of completed large page walks due to misses in the STLB",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_ept[] = {
    {
        .uname = "EPDE_MISS",
        .udesc = "Extended Page Directory Entry miss",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "EPDPE_MISS",
        .udesc = "Extended Page Directory Pointer miss",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "EPDPE_HIT",
        .udesc = "Extended Page Directory Pointer hit",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_fp_assist[] = {
    {
        .uname = "ALL",
        .udesc = "Floating point assists (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "INPUT",
        .udesc = "Floating point assists for invalid input value (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "OUTPUT",
        .udesc = "Floating point assists for invalid output value (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_fp_comp_ops_exe[] = {
    {
        .uname = "MMX",
        .udesc = "MMX Uops",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_DOUBLE_PRECISION",
        .udesc = "SSE* FP double precision Uops",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_FP",
        .udesc = "SSE and SSE2 FP Uops",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_FP_PACKED",
        .udesc = "SSE FP packed Uops",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_FP_SCALAR",
        .udesc = "SSE FP scalar Uops",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_SINGLE_PRECISION",
        .udesc = "SSE* FP single precision Uops",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE2_INTEGER",
        .udesc = "SSE2 integer Uops",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "X87",
        .udesc = "Computational floating-point operations executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_fp_mmx_trans[] = {
    {
        .uname = "ANY",
        .udesc = "All Floating Point to and from MMX transitions",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "TO_FP",
        .udesc = "Transitions from MMX to Floating Point instructions",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TO_MMX",
        .udesc = "Transitions from Floating Point to MMX instructions",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_ifu_ivc[] = {
    {
        .uname = "FULL",
        .udesc = "Instruction Fetche unit victim cache full",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1I_EVICTION",
        .udesc = "L1 Instruction cache evictions",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_ild_stall[] = {
    {
        .uname = "ANY",
        .udesc = "Any Instruction Length Decoder stall cycles",
        .uequiv = "IQ_FULL:LCP:MRU:REGEN",
        .ucode = 0xf00,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "IQ_FULL",
        .udesc = "Instruction Queue full stall cycles",
        .ucode = 0x400,
    },
    {
        .uname = "LCP",
        .udesc = "Length Change Prefix stall cycles",
        .ucode = 0x100,
    },
    {
        .uname = "MRU",
        .udesc = "Stall cycles due to BPU MRU bypass",
        .ucode = 0x200,
    },
    {
        .uname = "REGEN",
        .udesc = "Regen stall cycles",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t nhm_inst_decoded[] = {
    {
        .uname = "DEC0",
        .udesc = "Instructions that must be decoded by decoder 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Instructions Retired (Precise Event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "X87",
        .udesc = "Retired floating-point operations (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_l1d[] = {
    {
        .uname = "M_EVICT",
        .udesc = "L1D cache lines replaced in M state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_REPL",
        .udesc = "L1D cache lines allocated in the M state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_SNOOP_EVICT",
        .udesc = "L1D snoop eviction of cache lines in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REPL",
        .udesc = "L1 data cache lines allocated",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l1d_all_ref[] = {
    {
        .uname = "ANY",
        .udesc = "All references to the L1 data cache",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "CACHEABLE",
        .udesc = "L1 data cacheable reads and writes",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l1d_cache_ld[] = {
    {
        .uname = "E_STATE",
        .udesc = "L1 data cache read in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I_STATE",
        .udesc = "L1 data cache read in I state (misses)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_STATE",
        .udesc = "L1 data cache read in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MESI",
        .udesc = "L1 data cache reads",
        .ucode = 0xf00,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "S_STATE",
        .udesc = "L1 data cache read in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l1d_cache_lock[] = {
    {
        .uname = "E_STATE",
        .udesc = "L1 data cache load locks in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HIT",
        .udesc = "L1 data cache load lock hits",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_STATE",
        .udesc = "L1 data cache load locks in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S_STATE",
        .udesc = "L1 data cache load locks in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l1d_cache_st[] = {
    {
        .uname = "E_STATE",
        .udesc = "L1 data cache stores in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I_STATE",
        .udesc = "L1 data cache store in the I state",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_STATE",
        .udesc = "L1 data cache stores in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S_STATE",
        .udesc = "L1 data cache stores in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MESI",
        .udesc = "L1 data cache store in all states",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_l1d_prefetch[] = {
    {
        .uname = "MISS",
        .udesc = "L1D hardware prefetch misses",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REQUESTS",
        .udesc = "L1D hardware prefetch requests",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TRIGGERS",
        .udesc = "L1D hardware prefetch requests triggered",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l1d_wb_l2[] = {
    {
        .uname = "E_STATE",
        .udesc = "L1 writebacks to L2 in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I_STATE",
        .udesc = "L1 writebacks to L2 in I state (misses)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "M_STATE",
        .udesc = "L1 writebacks to L2 in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S_STATE",
        .udesc = "L1 writebacks to L2 in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MESI",
        .udesc = "All L1 writebacks to L2",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_l1i[] = {
    {
        .uname = "CYCLES_STALLED",
        .udesc = "L1I instruction fetch stall cycles",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HITS",
        .udesc = "L1I instruction fetch hits",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISSES",
        .udesc = "L1I instruction fetch misses",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "READS",
        .udesc = "L1I Instruction fetches",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_data_rqsts[] = {
    {
        .uname = "ANY",
        .udesc = "All L2 data requests",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "DEMAND_E_STATE",
        .udesc = "L2 data demand loads in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_I_STATE",
        .udesc = "L2 data demand loads in I state (misses)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_M_STATE",
        .udesc = "L2 data demand loads in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_MESI",
        .udesc = "L2 data demand requests",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_S_STATE",
        .udesc = "L2 data demand loads in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_E_STATE",
        .udesc = "L2 data prefetches in E state",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_I_STATE",
        .udesc = "L2 data prefetches in the I state (misses)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_M_STATE",
        .udesc = "L2 data prefetches in M state",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_MESI",
        .udesc = "All L2 data prefetches",
        .ucode = 0xf000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_S_STATE",
        .udesc = "L2 data prefetches in the S state",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_hw_prefetch[] = {
    {
        .uname = "HIT",
        .udesc = "Count L2 HW prefetcher detector hits",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALLOC",
        .udesc = "Count L2 HW prefetcher allocations",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DATA_TRIGGER",
        .udesc = "Count L2 HW data prefetcher triggered",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_TRIGGER",
        .udesc = "Count L2 HW code prefetcher triggered",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DCA_TRIGGER",
        .udesc = "Count L2 HW DCA prefetcher triggered",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "KICK_START",
        .udesc = "Count L2 HW prefetcher kick started",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_lines_in[] = {
    {
        .uname = "ANY",
        .udesc = "L2 lines allocated",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "E_STATE",
        .udesc = "L2 lines allocated in the E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S_STATE",
        .udesc = "L2 lines allocated in the S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_lines_out[] = {
    {
        .uname = "ANY",
        .udesc = "L2 lines evicted",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "DEMAND_CLEAN",
        .udesc = "L2 lines evicted by a demand request",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DIRTY",
        .udesc = "L2 modified lines evicted by a demand request",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_CLEAN",
        .udesc = "L2 lines evicted by a prefetch request",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_DIRTY",
        .udesc = "L2 modified lines evicted by a prefetch request",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_rqsts[] = {
    {
        .uname = "MISS",
        .udesc = "All L2 misses",
        .ucode = 0xaa00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REFERENCES",
        .udesc = "All L2 requests",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFETCH_HIT",
        .udesc = "L2 instruction fetch hits",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFETCH_MISS",
        .udesc = "L2 instruction fetch misses",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFETCHES",
        .udesc = "L2 instruction fetches",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LD_HIT",
        .udesc = "L2 load hits",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LD_MISS",
        .udesc = "L2 load misses",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOADS",
        .udesc = "L2 requests",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_HIT",
        .udesc = "L2 prefetch hits",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_MISS",
        .udesc = "L2 prefetch misses",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCHES",
        .udesc = "All L2 prefetches",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_HIT",
        .udesc = "L2 RFO hits",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_MISS",
        .udesc = "L2 RFO misses",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFOS",
        .udesc = "L2 RFO requests",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_transactions[] = {
    {
        .uname = "ANY",
        .udesc = "All L2 transactions",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "FILL",
        .udesc = "L2 fill transactions",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFETCH",
        .udesc = "L2 instruction fetch transactions",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_WB",
        .udesc = "L1D writeback to L2 transactions",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOAD",
        .udesc = "L2 Load transactions",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH",
        .udesc = "L2 prefetch transactions",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO",
        .udesc = "L2 RFO transactions",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WB",
        .udesc = "L2 writeback to LLC transactions",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_l2_write[] = {
    {
        .uname = "LOCK_E_STATE",
        .udesc = "L2 demand lock RFOs in E state",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOCK_I_STATE",
        .udesc = "L2 demand lock RFOs in I state (misses)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOCK_S_STATE",
        .udesc = "L2 demand lock RFOs in S state",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOCK_HIT",
        .udesc = "All demand L2 lock RFOs that hit the cache",
        .ucode = 0xe000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOCK_M_STATE",
        .udesc = "L2 demand lock RFOs in M state",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOCK_MESI",
        .udesc = "All demand L2 lock RFOs",
        .ucode = 0xf000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_HIT",
        .udesc = "All L2 demand store RFOs that hit the cache",
        .ucode = 0xe00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_I_STATE",
        .udesc = "L2 demand store RFOs in I state (misses)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_E_STATE",
        .udesc = "L2 demand store RFOs in the E state (exclusive)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_M_STATE",
        .udesc = "L2 demand store RFOs in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_MESI",
        .udesc = "All L2 demand store RFOs",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_S_STATE",
        .udesc = "L2 demand store RFOs in S state",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_large_itlb[] = {
    {
        .uname = "HIT",
        .udesc = "Large ITLB hit",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_load_dispatch[] = {
    {
        .uname = "ANY",
        .udesc = "All loads dispatched",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "MOB",
        .udesc = "Loads dispatched from the MOB",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RS",
        .udesc = "Loads dispatched that bypass the MOB",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RS_DELAYED",
        .udesc = "Loads dispatched from stage 305",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_longest_lat_cache[] = {
    {
        .uname = "REFERENCE",
        .udesc = "Longest latency cache reference",
        .ucode = 0x4f00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISS",
        .udesc = "Longest latency cache miss",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_lsd[] = {
    {
        .uname = "ACTIVE",
        .udesc = "Cycles when uops were delivered by the LSD",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "INACTIVE",
        .udesc = "Cycles no uops were delivered by the LSD",
        .uequiv = "ACTIVE:i=1",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
    },
};

static const intel_x86_umask_t nhm_machine_clears[] = {
    {
        .uname = "SMC",
        .udesc = "Self-Modifying Code detected",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES",
        .udesc = "Cycles machine clear asserted",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MEM_ORDER",
        .udesc = "Execution pipeline restart due to Memory ordering conflicts",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FUSION_ASSIST",
        .udesc = "Counts the number of macro-fusion assists",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_macro_insts[] = {
    {
        .uname = "DECODED",
        .udesc = "Instructions decoded",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FUSIONS_DECODED",
        .udesc = "Macro-fused instructions decoded",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_memory_disambiguation[] = {
    {
        .uname = "RESET",
        .udesc = "Counts memory disambiguation reset cycles",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WATCHDOG",
        .udesc =
            "Counts the number of times the memory disambiguation watchdog kicked in",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WATCH_CYCLES",
        .udesc = "Counts the cycles that the memory disambiguation watchdog is active",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_mem_inst_retired[] = {
    {
        .uname = "LATENCY_ABOVE_THRESHOLD",
        .udesc = "Memory instructions retired above programmed clocks, minimum threshold "
                 "value is 3, (Precise Event and ldlat required)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_LDLAT,
    },
    {
        .uname = "LOADS",
        .udesc = "Instructions retired which contains a load (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STORES",
        .udesc = "Instructions retired which contains a store (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_mem_load_retired[] = {
    {
        .uname = "DTLB_MISS",
        .udesc = "Retired loads that miss the DTLB (Precise Event)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "HIT_LFB",
        .udesc = "Retired loads that miss L1D and hit an previously allocated LFB "
                 "(Precise Event)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L1D_HIT",
        .udesc = "Retired loads that hit the L1 data cache (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Retired loads that hit the L2 cache (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Retired loads that miss the L3 cache (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LLC_MISS",
        .udesc = "This is an alias for L3_MISS",
        .uequiv = "L3_MISS",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_UNSHARED_HIT",
        .udesc = "Retired loads that hit valid versions in the L3 cache (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LLC_UNSHARED_HIT",
        .udesc = "This is an alias for L3_UNSHARED_HIT",
        .uequiv = "L3_UNSHARED_HIT",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "OTHER_CORE_L2_HIT_HITM",
        .udesc = "Retired loads that hit sibling core's L2 in modified or unmodified "
                 "states (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_mem_store_retired[] = {
    {
        .uname = "DTLB_MISS",
        .udesc = "Retired stores that miss the DTLB (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_mem_uncore_retired[] = {
    {
        .uname = "OTHER_CORE_L2_HITM",
        .udesc = "Load instructions retired that HIT modified data in sibling core "
                 "(Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_CACHE_LOCAL_HOME_HIT",
        .udesc = "Load instructions retired remote cache HIT data source (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_DRAM",
        .udesc = "Load instructions retired remote DRAM and remote home-remote cache "
                 "HITM (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LOCAL_DRAM",
        .udesc = "Load instructions retired with a data source of local DRAM or locally "
                 "homed remote hitm (Precise Event)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_DATA_MISS_UNKNOWN",
        .udesc = "Load instructions retired where the memory reference missed L3 and "
                 "data source is unknown (Model 46 only, Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .umodel = PFM_PMU_INTEL_NHM_EX,
    },
    {
        .uname = "UNCACHEABLE",
        .udesc = "Load instructions retired where the memory reference missed L1, L2, L3 "
                 "caches and to perform I/O (Model 46 only, Precise Event)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .umodel = PFM_PMU_INTEL_NHM_EX,
    },
};

static const intel_x86_umask_t nhm_offcore_requests[] = {
    {
        .uname = "ANY",
        .udesc = "All offcore requests",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ANY_READ",
        .udesc = "Offcore read requests",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Offcore RFO requests",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_READ_CODE",
        .udesc = "Counts number of offcore demand code read requests. Does not count L2 "
                 "prefetch requests.",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_READ_DATA",
        .udesc = "Offcore demand data read requests",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO",
        .udesc = "Offcore demand RFO requests",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_WRITEBACK",
        .udesc = "Offcore L1 data cache writebacks",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNCACHED_MEM",
        .udesc = "Counts number of offcore uncached memory requests",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_pic_accesses[] = {
    {
        .uname = "TPR_READS",
        .udesc = "Counts number of TPR reads",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TPR_WRITES",
        .udesc = "Counts number of TPR writes",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_rat_stalls[] = {
    {
        .uname = "FLAGS",
        .udesc = "Flag stall cycles",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REGISTERS",
        .udesc = "Partial register stall cycles",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ROB_READ_PORT",
        .udesc = "ROB read port stalls cycles",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SCOREBOARD",
        .udesc = "Scoreboard stall cycles",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "All RAT stall cycles",
        .ucode = 0xf00,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_resource_stalls[] = {
    {
        .uname = "FPCW",
        .udesc = "FPU control word write stall cycles",
        .ucode = 0x2000,
    },
    {
        .uname = "LOAD",
        .udesc = "Load buffer stall cycles",
        .ucode = 0x200,
    },
    {
        .uname = "MXCSR",
        .udesc = "MXCSR rename stall cycles",
        .ucode = 0x4000,
    },
    {
        .uname = "RS_FULL",
        .udesc = "Reservation Station full stall cycles",
        .ucode = 0x400,
    },
    {
        .uname = "STORE",
        .udesc = "Store buffer stall cycles",
        .ucode = 0x800,
    },
    {
        .uname = "OTHER",
        .udesc = "Other Resource related stall cycles",
        .ucode = 0x8000,
    },
    {
        .uname = "ROB_FULL",
        .udesc = "ROB full stall cycles",
        .ucode = 0x1000,
    },
    {
        .uname = "ANY",
        .udesc = "Resource related stall cycles",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_simd_int_128[] = {
    {
        .uname = "PACK",
        .udesc = "128 bit SIMD integer pack operations",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_ARITH",
        .udesc = "128 bit SIMD integer arithmetic operations",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_LOGICAL",
        .udesc = "128 bit SIMD integer logical operations",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_MPY",
        .udesc = "128 bit SIMD integer multiply operations",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_SHIFT",
        .udesc = "128 bit SIMD integer shift operations",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SHUFFLE_MOVE",
        .udesc = "128 bit SIMD integer shuffle/move operations",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNPACK",
        .udesc = "128 bit SIMD integer unpack operations",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_simd_int_64[] = {
    {
        .uname = "PACK",
        .udesc = "SIMD integer 64 bit pack operations",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_ARITH",
        .udesc = "SIMD integer 64 bit arithmetic operations",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_LOGICAL",
        .udesc = "SIMD integer 64 bit logical operations",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_MPY",
        .udesc = "SIMD integer 64 bit packed multiply operations",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_SHIFT",
        .udesc = "SIMD integer 64 bit shift operations",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SHUFFLE_MOVE",
        .udesc = "SIMD integer 64 bit shuffle/move operations",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNPACK",
        .udesc = "SIMD integer 64 bit unpack operations",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_snoop_response[] = {
    {
        .uname = "HIT",
        .udesc = "Thread responded HIT to snoop",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HITE",
        .udesc = "Thread responded HITE to snoop",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HITM",
        .udesc = "Thread responded HITM to snoop",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_sq_misc[] = {
    {
        .uname = "PROMOTION",
        .udesc = "Counts the number of L2 secondary misses that hit the Super Queue",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PROMOTION_POST_GO",
        .udesc =
            "Counts the number of L2 secondary misses during the Super Queue filling L2",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LRU_HINTS",
        .udesc = "Counts number of Super Queue LRU hints sent to L3",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FILL_DROPPED",
        .udesc = "Counts the number of SQ L2 fills dropped due to L2 busy",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SPLIT_LOCK",
        .udesc = "Super Queue lock splits across a cache line",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_sse_mem_exec[] = {
    {
        .uname = "NTA",
        .udesc = "Streaming SIMD L1D NTA prefetch miss",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t nhm_ssex_uops_retired[] = {
    {
        .uname = "PACKED_DOUBLE",
        .udesc = "SIMD Packed-Double Uops retired (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "PACKED_SINGLE",
        .udesc = "SIMD Packed-Single Uops retired (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SCALAR_DOUBLE",
        .udesc = "SIMD Scalar-Double Uops retired (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SCALAR_SINGLE",
        .udesc = "SIMD Scalar-Single Uops retired (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "VECTOR_INTEGER",
        .udesc = "SIMD Vector Integer Uops retired (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_store_blocks[] = {
    {
        .uname = "AT_RET",
        .udesc = "Loads delayed with at-Retirement block code",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_BLOCK",
        .udesc = "Cacheable loads delayed with L1D block code",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NOT_STA",
        .udesc = "Loads delayed due to a store blocked for unknown data",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STA",
        .udesc = "Loads delayed due to a store blocked for an unknown address",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_uops_decoded[] = {
    {
        .uname = "ESP_FOLDING",
        .udesc = "Stack pointer instructions decoded",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ESP_SYNC",
        .udesc = "Stack pointer sync operations",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS",
        .udesc = "Uops decoded by Microcode Sequencer",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_CYCLES_ACTIVE",
        .udesc = "Cycles in which at least one uop is decoded by Microcode Sequencer",
        .uequiv = "MS:c=1",
        .ucode = 0x200 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_uops_executed[] = {
    {
        .uname = "PORT0",
        .udesc = "Uops executed on port 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT1",
        .udesc = "Uops executed on port 1",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT2_CORE",
        .udesc = "Uops executed on port 2 on any thread (core count only)",
        .ucode = 0x400 | INTEL_X86_MOD_ANY,
        .modhw = _INTEL_X86_ATTR_T,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT3_CORE",
        .udesc = "Uops executed on port 3 on any thread (core count only)",
        .ucode = 0x800 | INTEL_X86_MOD_ANY,
        .modhw = _INTEL_X86_ATTR_T,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT4_CORE",
        .udesc = "Uops executed on port 4 on any thread (core count only)",
        .ucode = 0x1000 | INTEL_X86_MOD_ANY,
        .modhw = _INTEL_X86_ATTR_T,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT5",
        .udesc = "Uops executed on port 5",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT015",
        .udesc = "Uops issued on ports 0, 1 or 5",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT234_CORE",
        .udesc = "Uops issued on ports 2, 3 or 4 on any thread (core count only)",
        .ucode = 0x8000 | INTEL_X86_MOD_ANY,
        .modhw = _INTEL_X86_ATTR_T,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT015_STALL_CYCLES",
        .udesc = "Cycles no Uops issued on ports 0, 1 or 5",
        .uequiv = "PORT015:c=1:i=1",
        .ucode = 0x4000 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_uops_issued[] = {
    {
        .uname = "ANY",
        .udesc = "Uops issued",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "STALLED_CYCLES",
        .udesc = "Cycles stalled no issued uops",
        .uequiv = "ANY:c=1:i=1",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FUSED",
        .udesc = "Fused Uops issued",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t nhm_uops_retired[] = {
    {
        .uname = "ANY",
        .udesc = "Uops retired (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "RETIRE_SLOTS",
        .udesc = "Retirement slots used (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ACTIVE_CYCLES",
        .udesc = "Cycles Uops are being retired (Precise Event)",
        .uequiv = "ANY:c=1",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Cycles No Uops retired (Precise Event)",
        .uequiv = "ANY:c=1:i=1",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "MACRO_FUSED",
        .udesc = "Macro-fused Uops retired (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t nhm_offcore_response_0[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc =
            "Request: counts the number of demand and DCU prefetch data reads of full "
            "and partial cachelines as well as demand data page table entry cacheline "
            "reads. Does not count L2 data read prefetches or instruction fetches",
        .ucode = 0x100,
        .grpid = 0,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Request: counts the number of demand and DCU prefetch reads for "
                 "ownership (RFO) requests generated by a write to data cacheline. Does "
                 "not count L2 RFO",
        .ucode = 0x200,
        .grpid = 0,
    },
    {
        .uname = "DMND_IFETCH",
        .udesc = "Request: counts the number of demand and DCU prefetch instruction "
                 "cacheline reads. Does not count L2 code read prefetches",
        .ucode = 0x400,
        .grpid = 0,
    },
    {
        .uname = "WB",
        .udesc = "Request: counts the number of writeback (modified to exclusive) "
                 "transactions",
        .ucode = 0x800,
        .grpid = 0,
    },
    {
        .uname = "PF_DATA_RD",
        .udesc = "Request: counts the number of data cacheline reads generated by L2 "
                 "prefetchers",
        .ucode = 0x1000,
        .grpid = 0,
    },
    {
        .uname = "PF_RFO",
        .udesc = "Request: counts the number of RFO requests generated by L2 prefetchers",
        .ucode = 0x2000,
        .grpid = 0,
    },
    {
        .uname = "PF_IFETCH",
        .udesc = "Request: counts the number of code reads generated by L2 prefetchers",
        .ucode = 0x4000,
        .grpid = 0,
    },
    {
        .uname = "OTHER",
        .udesc = "Request: counts one of the following transaction types, including L3 "
                 "invalidate, I/O, full or partial writes, WC or non-temporal stores, "
                 "CLFLUSH, Fences, lock, unlock, split lock",
        .ucode = 0x8000,
        .grpid = 0,
    },
    {
        .uname = "ANY_IFETCH",
        .udesc = "Request: combination of PF_IFETCH | DMND_IFETCH",
        .uequiv = "PF_IFETCH:DMND_IFETCH",
        .ucode = 0x4400,
        .grpid = 0,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Request: combination of all requests umasks",
        .uequiv =
            "DMND_DATA_RD:DMND_RFO:DMND_IFETCH:WB:PF_DATA_RD:PF_RFO:PF_IFETCH:OTHER",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "ANY_DATA",
        .udesc = "Request: any data read/write request",
        .uequiv = "DMND_DATA_RD:PF_DATA_RD:DMND_RFO:PF_RFO",
        .ucode = 0x3300,
        .grpid = 0,
    },
    {
        .uname = "ANY_DATA_RD",
        .udesc = "Request: any data read in request",
        .uequiv = "DMND_DATA_RD:PF_DATA_RD",
        .ucode = 0x1100,
        .grpid = 0,
    },

    {
        .uname = "ANY_RFO",
        .udesc = "Request: combination of DMND_RFO | PF_RFO",
        .uequiv = "DMND_RFO:PF_RFO",
        .ucode = 0x2200,
        .grpid = 0,
    },
    {
        .uname = "UNCORE_HIT",
        .udesc = "Response: counts L3 Hit: local or remote home requests that hit L3 "
                 "cache in the uncore with no coherency actions required (snooping)",
        .ucode = 0x10000,
        .grpid = 1,
    },
    {
        .uname = "OTHER_CORE_HIT_SNP",
        .udesc = "Response: counts L3 Hit: local or remote home requests that hit L3 "
                 "cache in the uncore and was serviced by another core with a cross core "
                 "snoop where no modified copies were found (clean)",
        .ucode = 0x20000,
        .grpid = 1,
    },
    {
        .uname = "OTHER_CORE_HITM",
        .udesc = "Response: counts L3 Hit: local or remote home requests that hit L3 "
                 "cache in the uncore and was serviced by another core with a cross core "
                 "snoop where modified copies were found (HITM)",
        .ucode = 0x40000,
        .grpid = 1,
    },
    {
        .uname = "REMOTE_CACHE_HITM",
        .udesc = "Response: counts L3 Hit: local or remote home requests that hit a "
                 "remote L3 cacheline in modified (HITM) state",
        .ucode = 0x80000,
        .grpid = 1,
    },
    {
        .uname = "REMOTE_CACHE_FWD",
        .udesc =
            "Response: counts L3 Miss: local homed requests that missed the L3 cache and "
            "was serviced by forwarded data following a cross package snoop where no "
            "modified copies found. (Remote home requests are not counted)",
        .ucode = 0x100000,
        .grpid = 1,
    },
    {
        .uname = "REMOTE_DRAM",
        .udesc = "Response: counts L3 Miss: remote home requests that missed the L3 "
                 "cache and were serviced by remote DRAM",
        .ucode = 0x200000,
        .grpid = 1,
    },
    {
        .uname = "LOCAL_DRAM",
        .udesc = "Response: counts L3 Miss: local home requests that missed the L3 cache "
                 "and were serviced by local DRAM",
        .ucode = 0x400000,
        .grpid = 1,
    },
    {
        .uname = "NON_DRAM",
        .udesc = "Response: Non-DRAM requests that were serviced by IOH",
        .ucode = 0x800000,
        .grpid = 1,
    },
    {
        .uname = "ANY_CACHE_DRAM",
        .udesc = "Response: requests serviced by any source but IOH",
        .uequiv = "UNCORE_HIT:OTHER_CORE_HIT_SNP:OTHER_CORE_HITM:REMOTE_CACHE_FWD:REMOTE_"
                  "CACHE_HITM:REMOTE_DRAM:LOCAL_DRAM",
        .ucode = 0x7f0000,
        .grpid = 1,
    },
    {
        .uname = "ANY_DRAM",
        .udesc = "Response: requests serviced by local or remote DRAM",
        .uequiv = "REMOTE_DRAM:LOCAL_DRAM",
        .ucode = 0x600000,
        .grpid = 1,
    },
    {
        .uname = "ANY_LLC_MISS",
        .udesc = "Response: requests that missed in L3",
        .uequiv = "REMOTE_CACHE_HITM:REMOTE_CACHE_FWD:REMOTE_DRAM:LOCAL_DRAM:NON_DRAM",
        .ucode = 0xf80000,
        .grpid = 1,
    },
    {
        .uname = "LOCAL_CACHE_DRAM",
        .udesc = "Response: requests hit local core or uncore caches or local DRAM",
        .uequiv = "UNCORE_HIT:OTHER_CORE_HIT_SNP:OTHER_CORE_HITM:LOCAL_DRAM",
        .ucode = 0x470000,
        .grpid = 1,
    },
    {
        .uname = "REMOTE_CACHE_DRAM",
        .udesc = "Response: requests that miss L3 and hit remote caches or DRAM",
        .uequiv = "REMOTE_CACHE_HITM:REMOTE_CACHE_FWD:REMOTE_DRAM",
        .ucode = 0x380000,
        .grpid = 1,
    },
    {
        .uname = "ANY_RESPONSE",
        .udesc = "Response: combination of all response umasks",
        .uequiv = "UNCORE_HIT:OTHER_CORE_HIT_SNP:OTHER_CORE_HITM:REMOTE_CACHE_FWD:REMOTE_"
                  "CACHE_HITM:REMOTE_DRAM:LOCAL_DRAM:NON_DRAM",
        .ucode = 0xff0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
};

static const intel_x86_entry_t intel_nhm_pe[] = {
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Count core clock cycles whenever the clock signal on the specific core "
                "is running (not halted)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x20000000full,
        .code = 0x3c,
    },
    {
        .name = "INSTRUCTION_RETIRED",
        .desc = "Count the number of instructions at retirement",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x10000000full,
        .code = 0xc0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "This is an alias for INSTRUCTION_RETIRED",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "INSTRUCTION_RETIRED",
        .cntmsk = 0x10000000full,
        .code = 0xc0,
    },
    {
        .name = "UNHALTED_REFERENCE_CYCLES",
        .desc = "Unhalted reference cycles",
        .modmsk = INTEL_FIXED3_ATTRS,
        .cntmsk = 0x400000000ull,
        .code = 0x0300, /* pseudo encoding */
        .flags = INTEL_X86_FIXED,
    },
    {
        .name = "LLC_REFERENCES",
        .desc =
            "Count each request originating equiv the core to reference a cache line in "
            "the last level cache. The count may include speculation, but excludes cache "
            "line fills due to hardware prefetch. Alias to L2_RQSTS:SELF_DEMAND_MESI",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x4f2e,
    },
    {
        .name = "LAST_LEVEL_CACHE_REFERENCES",
        .desc = "This is an alias for LLC_REFERENCES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LLC_REFERENCES",
        .cntmsk = 0xf,
        .code = 0x4f2e,
    },
    {
        .name = "LLC_MISSES",
        .desc = "Count each cache miss condition for references to the last level cache. "
                "The event count may include speculation, but excludes cache line fills "
                "due to hardware prefetch. Alias to event L2_RQSTS:SELF_DEMAND_I_STATE",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x412e,
    },
    {
        .name = "LAST_LEVEL_CACHE_MISSES",
        .desc = "This is an equiv for LLC_MISSES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LLC_MISSES",
        .cntmsk = 0xf,
        .code = 0x412e,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Count branch instructions at retirement. Specifically, this event "
                "counts the retirement of the last micro-op of a branch instruction.",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "BR_INST_RETIRED:ALL_BRANCHES",
        .cntmsk = 0xf,
        .code = 0xc4,
    },
    {
        .name = "ARITH",
        .desc = "Counts arithmetic multiply and divide operations",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x14,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_arith),
        .ngrp = 1,
        .umasks = nhm_arith,
    },
    {
        .name = "BACLEAR",
        .desc = "Branch address calculator",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xe6,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_baclear),
        .ngrp = 1,
        .umasks = nhm_baclear,
    },
    {
        .name = "BACLEAR_FORCE_IQ",
        .desc = "Instruction queue forced BACLEAR",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1a7,
    },
    {
        .name = "BOGUS_BR",
        .desc = "Counts the number of bogus branches.",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1e4,
    },
    {
        .name = "BPU_CLEARS",
        .desc = "Branch prediction Unit clears",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xe8,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_bpu_clears),
        .ngrp = 1,
        .umasks = nhm_bpu_clears,
    },
    {
        .name = "BPU_MISSED_CALL_RET",
        .desc = "Branch prediction unit missed call or return",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1e5,
    },
    {
        .name = "BR_INST_DECODED",
        .desc = "Branch instructions decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1e0,
    },
    {
        .name = "BR_INST_EXEC",
        .desc = "Branch instructions executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x88,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_br_inst_exec),
        .ngrp = 1,
        .umasks = nhm_br_inst_exec,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc4,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_br_inst_retired),
        .ngrp = 1,
        .umasks = nhm_br_inst_retired,
    },
    {
        .name = "BR_MISP_EXEC",
        .desc = "Mispredicted branches executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x89,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_br_misp_exec),
        .ngrp = 1,
        .umasks = nhm_br_misp_exec,
    },
    {
        .name = "BR_MISP_RETIRED",
        .desc = "Count Mispredicted Branch Activity",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_br_misp_retired),
        .ngrp = 1,
        .umasks = nhm_br_misp_retired,
    },
    {
        .name = "CACHE_LOCK_CYCLES",
        .desc = "Cache lock cycles",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x63,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_cache_lock_cycles),
        .ngrp = 1,
        .umasks = nhm_cache_lock_cycles,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Cycles when processor is not in halted state",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x3c,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_cpu_clk_unhalted),
        .ngrp = 1,
        .umasks = nhm_cpu_clk_unhalted,
    },
    {
        .name = "DTLB_LOAD_MISSES",
        .desc = "Data TLB load misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x8,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_dtlb_load_misses),
        .ngrp = 1,
        .umasks = nhm_dtlb_load_misses,
    },
    {
        .name = "DTLB_MISSES",
        .desc = "Data TLB misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x49,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_dtlb_misses),
        .ngrp = 1,
        .umasks = nhm_dtlb_misses,
    },
    {
        .name = "EPT",
        .desc = "Extended Page Directory",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x4f,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_ept),
        .ngrp = 1,
        .umasks = nhm_ept,
    },
    {
        .name = "ES_REG_RENAMES",
        .desc = "ES segment renames",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1d5,
    },
    {
        .name = "FP_ASSIST",
        .desc = "Floating point assists",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf7,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_fp_assist),
        .ngrp = 1,
        .umasks = nhm_fp_assist,
    },
    {
        .name = "FP_COMP_OPS_EXE",
        .desc = "Floating point computational micro-ops",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x10,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_fp_comp_ops_exe),
        .ngrp = 1,
        .umasks = nhm_fp_comp_ops_exe,
    },
    {
        .name = "FP_MMX_TRANS",
        .desc = "Floating Point to and from MMX transitions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xcc,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_fp_mmx_trans),
        .ngrp = 1,
        .umasks = nhm_fp_mmx_trans,
    },
    {
        .name = "IFU_IVC",
        .desc = "Instruction Fetch unit victim cache",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x81,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_ifu_ivc),
        .ngrp = 1,
        .umasks = nhm_ifu_ivc,
    },
    {
        .name = "ILD_STALL",
        .desc = "Instruction Length Decoder stalls",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x87,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_ild_stall),
        .ngrp = 1,
        .umasks = nhm_ild_stall,
    },
    {
        .name = "INST_DECODED",
        .desc = "Instructions decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x18,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_inst_decoded),
        .ngrp = 1,
        .umasks = nhm_inst_decoded,
    },
    {
        .name = "INST_QUEUE_WRITES",
        .desc = "Instructions written to instruction queue.",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x117,
    },
    {
        .name = "INST_QUEUE_WRITE_CYCLES",
        .desc = "Cycles instructions are written to the instruction queue",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x11e,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_inst_retired),
        .ngrp = 1,
        .umasks = nhm_inst_retired,
    },
    {
        .name = "IO_TRANSACTIONS",
        .desc = "I/O transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x16c,
    },
    {
        .name = "ITLB_FLUSH",
        .desc = "Counts the number of ITLB flushes",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1ae,
    },
    {
        .name = "ITLB_MISSES",
        .desc = "Instruction TLB misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x85,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_dtlb_misses),
        .ngrp = 1,
        .umasks = nhm_dtlb_misses, /* identical to actual umasks list for this event */
    },
    {
        .name = "ITLB_MISS_RETIRED",
        .desc = "Retired instructions that missed the ITLB (Precise Event)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x20c8,
        .flags = INTEL_X86_PEBS,
    },
    {
        .name = "L1D",
        .desc = "L1D cache",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x51,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d),
        .ngrp = 1,
        .umasks = nhm_l1d,
    },
    {
        .name = "L1D_ALL_REF",
        .desc = "L1D references",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x43,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_all_ref),
        .ngrp = 1,
        .umasks = nhm_l1d_all_ref,
    },
    {
        .name = "L1D_CACHE_LD",
        .desc = "L1D  cacheable loads. WARNING: event may overcount loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x40,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_cache_ld),
        .ngrp = 1,
        .umasks = nhm_l1d_cache_ld,
    },
    {
        .name = "L1D_CACHE_LOCK",
        .desc = "L1 data cache load lock",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x42,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_cache_lock),
        .ngrp = 1,
        .umasks = nhm_l1d_cache_lock,
    },
    {
        .name = "L1D_CACHE_LOCK_FB_HIT",
        .desc = "L1D load lock accepted in fill buffer",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x153,
    },
    {
        .name = "L1D_CACHE_PREFETCH_LOCK_FB_HIT",
        .desc = "L1D prefetch load lock accepted in fill buffer",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x152,
    },
    {
        .name = "L1D_CACHE_ST",
        .desc = "L1 data cache stores",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x41,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_cache_st),
        .ngrp = 1,
        .umasks = nhm_l1d_cache_st,
    },
    {
        .name = "L1D_PREFETCH",
        .desc = "L1D hardware prefetch",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4e,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_prefetch),
        .ngrp = 1,
        .umasks = nhm_l1d_prefetch,
    },
    {
        .name = "L1D_WB_L2",
        .desc = "L1 writebacks to L2",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x28,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1d_wb_l2),
        .ngrp = 1,
        .umasks = nhm_l1d_wb_l2,
    },
    {
        .name = "L1I",
        .desc = "L1I instruction fetches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x80,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l1i),
        .ngrp = 1,
        .umasks = nhm_l1i,
    },
    {
        .name = "L1I_OPPORTUNISTIC_HITS",
        .desc = "Opportunistic hits in streaming",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x183,
    },
    {
        .name = "L2_DATA_RQSTS",
        .desc = "L2 data requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x26,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_data_rqsts),
        .ngrp = 1,
        .umasks = nhm_l2_data_rqsts,
    },
    {
        .name = "L2_HW_PREFETCH",
        .desc = "L2 HW prefetches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf3,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_hw_prefetch),
        .ngrp = 1,
        .umasks = nhm_l2_hw_prefetch,
    },
    {
        .name = "L2_LINES_IN",
        .desc = "L2 lines allocated",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf1,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_lines_in),
        .ngrp = 1,
        .umasks = nhm_l2_lines_in,
    },
    {
        .name = "L2_LINES_OUT",
        .desc = "L2 lines evicted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf2,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_lines_out),
        .ngrp = 1,
        .umasks = nhm_l2_lines_out,
    },
    {
        .name = "L2_RQSTS",
        .desc = "L2 requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_rqsts),
        .ngrp = 1,
        .umasks = nhm_l2_rqsts,
    },
    {
        .name = "L2_TRANSACTIONS",
        .desc = "L2 transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf0,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_transactions),
        .ngrp = 1,
        .umasks = nhm_l2_transactions,
    },
    {
        .name = "L2_WRITE",
        .desc = "L2 demand lock/store RFO",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x27,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_l2_write),
        .ngrp = 1,
        .umasks = nhm_l2_write,
    },
    {
        .name = "LARGE_ITLB",
        .desc = "Large instruction TLB",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x82,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_large_itlb),
        .ngrp = 1,
        .umasks = nhm_large_itlb,
    },
    {
        .name = "LOAD_DISPATCH",
        .desc = "Loads dispatched",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x13,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_load_dispatch),
        .ngrp = 1,
        .umasks = nhm_load_dispatch,
    },
    {
        .name = "LOAD_HIT_PRE",
        .desc = "Load operations conflicting with software prefetches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x14c,
    },
    {
        .name = "LONGEST_LAT_CACHE",
        .desc = "Longest latency cache reference",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_longest_lat_cache),
        .ngrp = 1,
        .umasks = nhm_longest_lat_cache,
    },
    {
        .name = "LSD",
        .desc = "Loop stream detector",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xa8,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_lsd),
        .ngrp = 1,
        .umasks = nhm_lsd,
    },
    {
        .name = "MACHINE_CLEARS",
        .desc = "Machine Clear",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc3,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_machine_clears),
        .ngrp = 1,
        .umasks = nhm_machine_clears,
    },
    {
        .name = "MACRO_INSTS",
        .desc = "Macro-fused instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xd0,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_macro_insts),
        .ngrp = 1,
        .umasks = nhm_macro_insts,
    },
    {
        .name = "MEMORY_DISAMBIGUATION",
        .desc = "Memory Disambiguation Activity",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x9,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_memory_disambiguation),
        .ngrp = 1,
        .umasks = nhm_memory_disambiguation,
    },
    {
        .name = "MEM_INST_RETIRED",
        .desc = "Memory instructions retired",
        .modmsk = INTEL_V3_ATTRS | _INTEL_X86_ATTR_LDLAT,
        .cntmsk = 0xf,
        .code = 0xb,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_mem_inst_retired),
        .ngrp = 1,
        .umasks = nhm_mem_inst_retired,
    },
    {
        .name = "MEM_LOAD_RETIRED",
        .desc = "Retired loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xcb,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_mem_load_retired),
        .ngrp = 1,
        .umasks = nhm_mem_load_retired,
    },
    {
        .name = "MEM_STORE_RETIRED",
        .desc = "Retired stores",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_mem_store_retired),
        .ngrp = 1,
        .umasks = nhm_mem_store_retired,
    },
    {
        .name = "MEM_UNCORE_RETIRED",
        .desc = "Load instructions retired which hit offcore",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_mem_uncore_retired),
        .ngrp = 1,
        .umasks = nhm_mem_uncore_retired,
    },
    {
        .name = "OFFCORE_REQUESTS",
        .desc = "Offcore memory requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xb0,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_offcore_requests),
        .ngrp = 1,
        .umasks = nhm_offcore_requests,
    },
    {
        .name = "OFFCORE_REQUESTS_SQ_FULL",
        .desc = "Counts cycles the Offcore Request buffer or Super Queue is full.",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1b2,
    },
    {
        .name = "PARTIAL_ADDRESS_ALIAS",
        .desc = "False dependencies due to partial address forming",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x107,
    },
    {
        .name = "PIC_ACCESSES",
        .desc = "Programmable interrupt controller",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xba,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_pic_accesses),
        .ngrp = 1,
        .umasks = nhm_pic_accesses,
    },
    {
        .name = "RAT_STALLS",
        .desc = "Register allocation table stalls",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xd2,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_rat_stalls),
        .ngrp = 1,
        .umasks = nhm_rat_stalls,
    },
    {
        .name = "RESOURCE_STALLS",
        .desc = "Processor stalls",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xa2,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_resource_stalls),
        .ngrp = 1,
        .umasks = nhm_resource_stalls,
    },
    {
        .name = "SEG_RENAME_STALLS",
        .desc = "Segment rename stall cycles",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1d4,
    },
    {
        .name = "SEGMENT_REG_LOADS",
        .desc = "Counts number of segment register loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1f8,
    },
    {
        .name = "SIMD_INT_128",
        .desc = "128 bit SIMD integer operations",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x12,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_simd_int_128),
        .ngrp = 1,
        .umasks = nhm_simd_int_128,
    },
    {
        .name = "SIMD_INT_64",
        .desc = "64 bit SIMD integer operations",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xfd,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_simd_int_64),
        .ngrp = 1,
        .umasks = nhm_simd_int_64,
    },
    {
        .name = "SNOOP_RESPONSE",
        .desc = "Snoop",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xb8,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_snoop_response),
        .ngrp = 1,
        .umasks = nhm_snoop_response,
    },
    {
        .name = "SQ_FULL_STALL_CYCLES",
        .desc = "Counts cycles the Offcore Request buffer or Super Queue is full and "
                "request(s) are outstanding.",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1f6,
    },
    {
        .name = "SQ_MISC",
        .desc = "Super Queue Activity Related to L2 Cache Access",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf4,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_sq_misc),
        .ngrp = 1,
        .umasks = nhm_sq_misc,
    },
    {
        .name = "SSE_MEM_EXEC",
        .desc = "Streaming SIMD executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x4b,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_sse_mem_exec),
        .ngrp = 1,
        .umasks = nhm_sse_mem_exec,
    },
    {
        .name = "SSEX_UOPS_RETIRED",
        .desc = "SIMD micro-ops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc7,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_ssex_uops_retired),
        .ngrp = 1,
        .umasks = nhm_ssex_uops_retired,
    },
    {
        .name = "STORE_BLOCKS",
        .desc = "Delayed loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x6,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_store_blocks),
        .ngrp = 1,
        .umasks = nhm_store_blocks,
    },
    {
        .name = "TWO_UOP_INSTS_DECODED",
        .desc = "Two micro-ops instructions decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x119,
    },
    {
        .name = "UOPS_DECODED_DEC0",
        .desc = "Micro-ops decoded by decoder 0",
        .modmsk = 0x0,
        .cntmsk = 0xf,
        .code = 0x13d,
    },
    {
        .name = "UOPS_DECODED",
        .desc = "Micro-ops decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xd1,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_uops_decoded),
        .ngrp = 1,
        .umasks = nhm_uops_decoded,
    },
    {
        .name = "UOPS_EXECUTED",
        .desc = "Micro-ops executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xb1,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_uops_executed),
        .ngrp = 1,
        .umasks = nhm_uops_executed,
    },
    {
        .name = "UOPS_ISSUED",
        .desc = "Micro-ops issued",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xe,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_uops_issued),
        .ngrp = 1,
        .umasks = nhm_uops_issued,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Micro-ops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc2,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_uops_retired),
        .ngrp = 1,
        .umasks = nhm_uops_retired,
    },
    {
        .name = "UOP_UNFUSION",
        .desc = "Micro-ops unfusions due to FP exceptions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1db,
    },
    {
        .name = "OFFCORE_RESPONSE_0",
        .desc = "Offcore response 0 (must provide at least one request and one response "
                "umasks)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1b7,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(nhm_offcore_response_0),
        .ngrp = 2,
        .umasks = nhm_offcore_response_0,
    },
};
