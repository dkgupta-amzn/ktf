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
 * PMU: core (Intel Core)
 */

static const intel_x86_umask_t core_rs_uops_dispatched_cycles[] = {
    {
        .uname = "PORT_0",
        .udesc = "On port 0",
        .ucode = 0x100,
    },
    {
        .uname = "PORT_1",
        .udesc = "On port 1",
        .ucode = 0x200,
    },
    {
        .uname = "PORT_2",
        .udesc = "On port 2",
        .ucode = 0x400,
    },
    {
        .uname = "PORT_3",
        .udesc = "On port 3",
        .ucode = 0x800,
    },
    {
        .uname = "PORT_4",
        .udesc = "On port 4",
        .ucode = 0x1000,
    },
    {
        .uname = "PORT_5",
        .udesc = "On port 5",
        .ucode = 0x2000,
    },
    {
        .uname = "ANY",
        .udesc = "On any port",
        .uequiv = "PORT_0:PORT_1:PORT_2:PORT_3:PORT_4:PORT_5",
        .ucode = 0x3f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_load_block[] = {
    {
        .uname = "STA",
        .udesc = "Loads blocked by a preceding store with unknown address",
        .ucode = 0x200,
    },
    {
        .uname = "STD",
        .udesc = "Loads blocked by a preceding store with unknown data",
        .ucode = 0x400,
    },
    {
        .uname = "OVERLAP_STORE",
        .udesc = "Loads that partially overlap an earlier store, or 4K equived with a "
                 "previous store",
        .ucode = 0x800,
    },
    {
        .uname = "UNTIL_RETIRE",
        .udesc = "Loads blocked until retirement",
        .ucode = 0x1000,
    },
    {
        .uname = "L1D",
        .udesc = "Loads blocked by the L1 data cache",
        .ucode = 0x2000,
    },
};

static const intel_x86_umask_t core_store_block[] = {
    {
        .uname = "ORDER",
        .udesc =
            "Cycles while store is waiting for a preceding store to be globally observed",
        .ucode = 0x200,
    },
    {
        .uname = "SNOOP",
        .udesc =
            "A store is blocked due to a conflict with an external or internal snoop",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t core_sse_pre_exec[] = {
    {
        .uname = "NTA",
        .udesc = "Streaming SIMD Extensions (SSE) Prefetch NTA instructions executed",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT0 instructions executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT1 and PrefetchT2 instructions "
                 "executed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STORES",
        .udesc =
            "Streaming SIMD Extensions (SSE) Weakly-ordered store instructions executed",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_dtlb_misses[] = {
    {
        .uname = "ANY",
        .udesc = "Any memory access that missed the DTLB",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "MISS_LD",
        .udesc = "DTLB misses due to load operations",
        .ucode = 0x200,
    },
    {
        .uname = "L0_MISS_LD",
        .udesc = "L0 DTLB misses due to load operations",
        .ucode = 0x400,
    },
    {
        .uname = "MISS_ST",
        .udesc = "DTLB misses due to store operations",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t core_memory_disambiguation[] = {
    {
        .uname = "RESET",
        .udesc = "Memory disambiguation reset cycles",
        .ucode = 0x100,
    },
    {
        .uname = "SUCCESS",
        .udesc = "Number of loads that were successfully disambiguated",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_page_walks[] = {
    {
        .uname = "COUNT",
        .udesc = "Number of page-walks executed",
        .ucode = 0x100,
    },
    {
        .uname = "CYCLES",
        .udesc = "Duration of page-walks in core cycles",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_delayed_bypass[] = {
    {
        .uname = "FP",
        .udesc = "Delayed bypass to FP operation",
        .ucode = 0x0,
    },
    {
        .uname = "SIMD",
        .udesc = "Delayed bypass to SIMD operation",
        .ucode = 0x100,
    },
    {
        .uname = "LOAD",
        .udesc = "Delayed bypass to load operation",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_l2_ads[] = {
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_l2_lines_in[] = {
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "ANY",
        .udesc = "All inclusive",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "PREFETCH",
        .udesc = "Hardware prefetch only",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
    {
        .uname = "EXCL_PREFETCH",
        .udesc = "Exclude hardware prefetch",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
};

static const intel_x86_umask_t core_l2_ifetch[] = {
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
        .uequiv = "M_STATE:E_STATE:S_STATE:I_STATE",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "I_STATE",
        .udesc = "Invalid cacheline",
        .ucode = 0x100,
        .grpid = 1,
    },
    {
        .uname = "S_STATE",
        .udesc = "Shared cacheline",
        .ucode = 0x200,
        .grpid = 1,
    },
    {
        .uname = "E_STATE",
        .udesc = "Exclusive cacheline",
        .ucode = 0x400,
        .grpid = 1,
    },
    {
        .uname = "M_STATE",
        .udesc = "Modified cacheline",
        .ucode = 0x800,
        .grpid = 1,
    },
};

static const intel_x86_umask_t core_l2_ld[] = {
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "ANY",
        .udesc = "All inclusive",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "PREFETCH",
        .udesc = "Hardware prefetch only",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
    {
        .uname = "EXCL_PREFETCH",
        .udesc = "Exclude hardware prefetch",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
        .uequiv = "M_STATE:E_STATE:S_STATE:I_STATE",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 2,
    },
    {
        .uname = "I_STATE",
        .udesc = "Invalid cacheline",
        .ucode = 0x100,
        .grpid = 2,
    },
    {
        .uname = "S_STATE",
        .udesc = "Shared cacheline",
        .ucode = 0x200,
        .grpid = 2,
    },
    {
        .uname = "E_STATE",
        .udesc = "Exclusive cacheline",
        .ucode = 0x400,
        .grpid = 2,
    },
    {
        .uname = "M_STATE",
        .udesc = "Modified cacheline",
        .ucode = 0x800,
        .grpid = 2,
    },
};

static const intel_x86_umask_t core_cpu_clk_unhalted[] = {
    {
        .uname = "CORE_P",
        .udesc = "Core cycles when core is not halted",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "BUS",
        .udesc = "Bus cycles when core is not halted. This event can give a measurement "
                 "of the elapsed time. This events has a constant ratio with "
                 "CPU_CLK_UNHALTED:REF event, which is the maximum bus to processor "
                 "frequency ratio",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NO_OTHER",
        .udesc = "Bus cycles when core is active and the other is halted",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_l1d_cache_ld[] = {
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
        .uequiv = "M_STATE:E_STATE:S_STATE:I_STATE",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "I_STATE",
        .udesc = "Invalid cacheline",
        .ucode = 0x100,
    },
    {
        .uname = "S_STATE",
        .udesc = "Shared cacheline",
        .ucode = 0x200,
    },
    {
        .uname = "E_STATE",
        .udesc = "Exclusive cacheline",
        .ucode = 0x400,
    },
    {
        .uname = "M_STATE",
        .udesc = "Modified cacheline",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t core_l1d_split[] = {
    {
        .uname = "LOADS",
        .udesc = "Cache line split loads from the L1 data cache",
        .ucode = 0x100,
    },
    {
        .uname = "STORES",
        .udesc = "Cache line split stores to the L1 data cache",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_sse_pre_miss[] = {
    {
        .uname = "NTA",
        .udesc = "Streaming SIMD Extensions (SSE) Prefetch NTA instructions missing all "
                 "cache levels",
        .ucode = 0x0,
    },
    {
        .uname = "L1",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT0 instructions missing all "
                 "cache levels",
        .ucode = 0x100,
    },
    {
        .uname = "L2",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT1 and PrefetchT2 instructions "
                 "missing all cache levels",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_l1d_prefetch[] = {
    {
        .uname = "REQUESTS",
        .udesc = "L1 data cache prefetch requests",
        .ucode = 0x1000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_bus_request_outstanding[] = {
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "THIS_AGENT",
        .udesc = "This agent",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "ALL_AGENTS",
        .udesc = "Any agent on the bus",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
};

static const intel_x86_umask_t core_bus_bnr_drv[] = {
    {
        .uname = "THIS_AGENT",
        .udesc = "This agent",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL_AGENTS",
        .udesc = "Any agent on the bus",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_ext_snoop[] = {
    {
        .uname = "ANY",
        .udesc = "Any external snoop response",
        .ucode = 0xb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "CLEAN",
        .udesc = "External snoop CLEAN response",
        .ucode = 0x100,
        .grpid = 0,
    },
    {
        .uname = "HIT",
        .udesc = "External snoop HIT response",
        .ucode = 0x200,
        .grpid = 0,
    },
    {
        .uname = "HITM",
        .udesc = "External snoop HITM response",
        .ucode = 0x800,
        .grpid = 0,
    },
    {
        .uname = "THIS_AGENT",
        .udesc = "This agent",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "ALL_AGENTS",
        .udesc = "Any agent on the bus",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
};

static const intel_x86_umask_t core_cmp_snoop[] = {
    {
        .uname = "ANY",
        .udesc = "L1 data cache is snooped by other core",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "SHARE",
        .udesc = "L1 data cache is snooped for sharing by other core",
        .ucode = 0x100,
        .grpid = 0,
    },
    {
        .uname = "INVALIDATE",
        .udesc = "L1 data cache is snooped for Invalidation by other core",
        .ucode = 0x200,
        .grpid = 0,
    },
    {
        .uname = "SELF",
        .udesc = "This core",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "BOTH_CORES",
        .udesc = "Both cores",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 1,
    },
};

static const intel_x86_umask_t core_itlb[] = {
    {
        .uname = "SMALL_MISS",
        .udesc = "ITLB small page misses",
        .ucode = 0x200,
    },
    {
        .uname = "LARGE_MISS",
        .udesc = "ITLB large page misses",
        .ucode = 0x1000,
    },
    {
        .uname = "FLUSH",
        .udesc = "ITLB flushes",
        .ucode = 0x4000,
    },
    {
        .uname = "MISSES",
        .udesc = "ITLB misses",
        .ucode = 0x1200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_inst_queue[] = {
    {
        .uname = "FULL",
        .udesc = "Cycles during which the instruction queue is full",
        .ucode = 0x200,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_macro_insts[] = {
    {
        .uname = "DECODED",
        .udesc = "Instructions decoded",
        .ucode = 0x100,
    },
    {
        .uname = "CISC_DECODED",
        .udesc = "CISC instructions decoded",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t core_esp[] = {
    {
        .uname = "SYNCH",
        .udesc = "ESP register content synchronization",
        .ucode = 0x100,
    },
    {
        .uname = "ADDITIONS",
        .udesc = "ESP register automatic additions",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t core_simd_uop_type_exec[] = {
    {
        .uname = "MUL",
        .udesc = "SIMD packed multiply micro-ops executed",
        .ucode = 0x100,
    },
    {
        .uname = "SHIFT",
        .udesc = "SIMD packed shift micro-ops executed",
        .ucode = 0x200,
    },
    {
        .uname = "PACK",
        .udesc = "SIMD pack micro-ops executed",
        .ucode = 0x400,
    },
    {
        .uname = "UNPACK",
        .udesc = "SIMD unpack micro-ops executed",
        .ucode = 0x800,
    },
    {
        .uname = "LOGICAL",
        .udesc = "SIMD packed logical micro-ops executed",
        .ucode = 0x1000,
    },
    {
        .uname = "ARITHMETIC",
        .udesc = "SIMD packed arithmetic micro-ops executed",
        .ucode = 0x2000,
    },
};

static const intel_x86_umask_t core_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Instructions retired (Precise Event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "LOADS",
        .udesc = "Instructions retired, which contain a load",
        .ucode = 0x100,
    },
    {
        .uname = "STORES",
        .udesc = "Instructions retired, which contain a store",
        .ucode = 0x200,
    },
    {
        .uname = "OTHER",
        .udesc = "Instructions retired, with no load or store operation",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t core_x87_ops_retired[] = {
    {
        .uname = "FXCH",
        .udesc = "FXCH instructions retired",
        .ucode = 0x100,
    },
    {
        .uname = "ANY",
        .udesc = "Retired floating-point computational operations (Precise Event)",
        .ucode = 0xfe00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_uops_retired[] = {
    {
        .uname = "LD_IND_BR",
        .udesc = "Fused load+op or load+indirect branch retired",
        .ucode = 0x100,
    },
    {
        .uname = "STD_STA",
        .udesc = "Fused store address + data retired",
        .ucode = 0x200,
    },
    {
        .uname = "MACRO_FUSION",
        .udesc = "Retired instruction pairs fused into one micro-op",
        .ucode = 0x400,
    },
    {
        .uname = "NON_FUSED",
        .udesc = "Non-fused micro-ops retired",
        .ucode = 0x800,
    },
    {
        .uname = "FUSED",
        .udesc = "Fused micro-ops retired",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "Micro-ops retired",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_machine_nukes[] = {
    {
        .uname = "SMC",
        .udesc = "Self-Modifying Code detected",
        .ucode = 0x100,
    },
    {
        .uname = "MEM_ORDER",
        .udesc = "Execution pipeline restart due to memory ordering conflict or memory "
                 "disambiguation misprediction",
        .ucode = 0x400,
    },
};

static const intel_x86_umask_t core_br_inst_retired[] = {
    {
        .uname = "ANY",
        .udesc = "Retired branch instructions",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "PRED_NOT_TAKEN",
        .udesc = "Retired branch instructions that were predicted not-taken",
        .ucode = 0x100,
    },
    {
        .uname = "MISPRED_NOT_TAKEN",
        .udesc = "Retired branch instructions that were mispredicted not-taken",
        .ucode = 0x200,
    },
    {
        .uname = "PRED_TAKEN",
        .udesc = "Retired branch instructions that were predicted taken",
        .ucode = 0x400,
    },
    {
        .uname = "MISPRED_TAKEN",
        .udesc = "Retired branch instructions that were mispredicted taken",
        .ucode = 0x800,
    },
    {
        .uname = "TAKEN",
        .udesc = "Retired taken branch instructions",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t core_simd_inst_retired[] = {
    {
        .uname = "PACKED_SINGLE",
        .udesc = "Retired Streaming SIMD Extensions (SSE) packed-single instructions",
        .ucode = 0x100,
    },
    {
        .uname = "SCALAR_SINGLE",
        .udesc = "Retired Streaming SIMD Extensions (SSE) scalar-single instructions",
        .ucode = 0x200,
    },
    {
        .uname = "PACKED_DOUBLE",
        .udesc = "Retired Streaming SIMD Extensions 2 (SSE2) packed-double instructions",
        .ucode = 0x400,
    },
    {
        .uname = "SCALAR_DOUBLE",
        .udesc = "Retired Streaming SIMD Extensions 2 (SSE2) scalar-double instructions",
        .ucode = 0x800,
    },
    {
        .uname = "VECTOR",
        .udesc = "Retired Streaming SIMD Extensions 2 (SSE2) vector integer instructions",
        .ucode = 0x1000,
    },
    {
        .uname = "ANY",
        .udesc = "Retired Streaming SIMD instructions (Precise Event)",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_simd_comp_inst_retired[] = {
    {
        .uname = "PACKED_SINGLE",
        .udesc = "Retired computational Streaming SIMD Extensions (SSE) packed-single "
                 "instructions",
        .ucode = 0x100,
    },
    {
        .uname = "SCALAR_SINGLE",
        .udesc = "Retired computational Streaming SIMD Extensions (SSE) scalar-single "
                 "instructions",
        .ucode = 0x200,
    },
    {
        .uname = "PACKED_DOUBLE",
        .udesc = "Retired computational Streaming SIMD Extensions 2 (SSE2) packed-double "
                 "instructions",
        .ucode = 0x400,
    },
    {
        .uname = "SCALAR_DOUBLE",
        .udesc = "Retired computational Streaming SIMD Extensions 2 (SSE2) scalar-double "
                 "instructions",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t core_mem_load_retired[] = {
    {
        .uname = "L1D_MISS",
        .udesc = "Retired loads that miss the L1 data cache (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "L1D_LINE_MISS",
        .udesc = "L1 data cache line missed by retired loads (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "L2_MISS",
        .udesc = "Retired loads that miss the L2 cache (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "L2_LINE_MISS",
        .udesc = "L2 cache line missed by retired loads (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "DTLB_MISS",
        .udesc = "Retired loads that miss the DTLB (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t core_fp_mmx_trans[] = {
    {
        .uname = "TO_FP",
        .udesc = "Transitions from MMX (TM) Instructions to Floating Point Instructions",
        .ucode = 0x200,
    },
    {
        .uname = "TO_MMX",
        .udesc = "Transitions from Floating Point to MMX (TM) Instructions",
        .ucode = 0x100,
    },
};

static const intel_x86_umask_t core_rat_stalls[] = {
    {
        .uname = "ROB_READ_PORT",
        .udesc = "ROB read port stalls cycles",
        .ucode = 0x100,
    },
    {
        .uname = "PARTIAL_CYCLES",
        .udesc = "Partial register stall cycles",
        .ucode = 0x200,
    },
    {
        .uname = "FLAGS",
        .udesc = "Flag stall cycles",
        .ucode = 0x400,
    },
    {
        .uname = "FPSW",
        .udesc = "FPU status word stall",
        .ucode = 0x800,
    },
    {
        .uname = "ANY",
        .udesc = "All RAT stall cycles",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_seg_rename_stalls[] = {
    {
        .uname = "ES",
        .udesc = "Segment rename stalls - ES ",
        .ucode = 0x100,
    },
    {
        .uname = "DS",
        .udesc = "Segment rename stalls - DS",
        .ucode = 0x200,
    },
    {
        .uname = "FS",
        .udesc = "Segment rename stalls - FS",
        .ucode = 0x400,
    },
    {
        .uname = "GS",
        .udesc = "Segment rename stalls - GS",
        .ucode = 0x800,
    },
    {
        .uname = "ANY",
        .udesc = "Any (ES/DS/FS/GS) segment rename stall",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_seg_reg_renames[] = {
    {
        .uname = "ES",
        .udesc = "Segment renames - ES",
        .ucode = 0x100,
    },
    {
        .uname = "DS",
        .udesc = "Segment renames - DS",
        .ucode = 0x200,
    },
    {
        .uname = "FS",
        .udesc = "Segment renames - FS",
        .ucode = 0x400,
    },
    {
        .uname = "GS",
        .udesc = "Segment renames - GS",
        .ucode = 0x800,
    },
    {
        .uname = "ANY",
        .udesc = "Any (ES/DS/FS/GS) segment rename",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t core_resource_stalls[] = {
    {
        .uname = "ROB_FULL",
        .udesc = "Cycles during which the ROB is full",
        .ucode = 0x100,
    },
    {
        .uname = "RS_FULL",
        .udesc = "Cycles during which the RS is full",
        .ucode = 0x200,
    },
    {
        .uname = "LD_ST",
        .udesc = "Cycles during which the pipeline has exceeded load or store limit or "
                 "waiting to commit all stores",
        .ucode = 0x400,
    },
    {
        .uname = "FPCW",
        .udesc = "Cycles stalled due to FPU control word write",
        .ucode = 0x800,
    },
    {
        .uname = "BR_MISS_CLEAR",
        .udesc = "Cycles stalled due to branch misprediction",
        .ucode = 0x1000,
    },
    {
        .uname = "ANY",
        .udesc = "Resource related stalls",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_entry_t intel_core_pe[] = {
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Count core clock cycles whenever the clock signal on the specific core "
                "is running (not halted)",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x200000003ull,
        .code = 0x3c,
    },
    {
        .name = "INSTRUCTION_RETIRED",
        .desc = "Count the number of instructions at retirement",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x100000003ull,
        .code = 0xc0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "This is an alias from INSTRUCTION_RETIRED",
        .modmsk = INTEL_X86_ATTRS,
        .equiv = "INSTRUCTION_RETIRED",
        .cntmsk = 0x100000003ull,
        .code = 0xc0,
    },
    {
        .name = "UNHALTED_REFERENCE_CYCLES",
        .desc = "Unhalted reference cycles",
        .modmsk = INTEL_FIXED2_ATTRS,
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
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LAST_LEVEL_CACHE_REFERENCES",
        .desc = "This is an alias for LLC_REFERENCES",
        .modmsk = INTEL_X86_ATTRS,
        .equiv = "LLC_REFERENCES",
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LLC_MISSES",
        .desc = "Count each cache miss condition for references to the last level cache. "
                "The event count may include speculation, but excludes cache line fills "
                "due to hardware prefetch. Alias to event L2_RQSTS:SELF_DEMAND_I_STATE",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "LAST_LEVEL_CACHE_MISSES",
        .desc = "This is an alias for LLC_MISSES",
        .modmsk = INTEL_X86_ATTRS,
        .equiv = "LLC_MISSES",
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Count branch instructions at retirement. Specifically, this event "
                "counts the retirement of the last micro-op of a branch instruction.",
        .modmsk = INTEL_X86_ATTRS,
        .equiv = "BR_INST_RETIRED:ANY",
        .cntmsk = 0x3,
        .code = 0xc4,
    },
    {
        .name = "MISPREDICTED_BRANCH_RETIRED",
        .desc = "Count mispredicted branch instructions at retirement. Specifically, "
                "this event counts at retirement of the last micro-op of a branch "
                "instruction in the architectural path of the execution and experienced "
                "misprediction in the branch prediction hardware.",
        .modmsk = INTEL_X86_ATTRS,
        .equiv = "BR_INST_RETIRED_MISPRED",
        .cntmsk = 0x3,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
    },
    {
        .name = "RS_UOPS_DISPATCHED_CYCLES",
        .desc = "Cycles micro-ops dispatched for execution",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x1,
        .code = 0xa1,
        .numasks = LIBPFM_ARRAY_SIZE(core_rs_uops_dispatched_cycles),
        .ngrp = 1,
        .umasks = core_rs_uops_dispatched_cycles,
    },
    {
        .name = "RS_UOPS_DISPATCHED",
        .desc = "Number of micro-ops dispatched for execution",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xa0,
    },
    {
        .name = "RS_UOPS_DISPATCHED_NONE",
        .desc = "Number of of cycles in which no micro-ops is dispatched for execution",
        .modmsk = 0x0,
        .equiv = "RS_UOPS_DISPATCHED:i=1:c=1",
        .cntmsk = 0x3,
        .code = 0xa0 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
    },
    {
        .name = "LOAD_BLOCK",
        .desc = "Loads blocked",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3,
        .numasks = LIBPFM_ARRAY_SIZE(core_load_block),
        .ngrp = 1,
        .umasks = core_load_block,
    },
    {
        .name = "SB_DRAIN_CYCLES",
        .desc = "Cycles while stores are blocked due to store buffer drain",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x104,
    },
    {
        .name = "STORE_BLOCK",
        .desc = "Cycles while store is waiting",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4,
        .numasks = LIBPFM_ARRAY_SIZE(core_store_block),
        .ngrp = 1,
        .umasks = core_store_block,
    },
    {
        .name = "SEGMENT_REG_LOADS",
        .desc = "Number of segment register loads",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6,
    },
    {
        .name = "SSE_PRE_EXEC",
        .desc = "Streaming SIMD Extensions (SSE) Prefetch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7,
        .numasks = LIBPFM_ARRAY_SIZE(core_sse_pre_exec),
        .ngrp = 1,
        .umasks = core_sse_pre_exec,
    },
    {
        .name = "DTLB_MISSES",
        .desc = "Memory accesses that missed the DTLB",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8,
        .numasks = LIBPFM_ARRAY_SIZE(core_dtlb_misses),
        .ngrp = 1,
        .umasks = core_dtlb_misses,
    },
    {
        .name = "MEMORY_DISAMBIGUATION",
        .desc = "Memory disambiguation",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x9,
        .numasks = LIBPFM_ARRAY_SIZE(core_memory_disambiguation),
        .ngrp = 1,
        .umasks = core_memory_disambiguation,
    },
    {
        .name = "PAGE_WALKS",
        .desc = "Number of page-walks executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc,
        .numasks = LIBPFM_ARRAY_SIZE(core_page_walks),
        .ngrp = 1,
        .umasks = core_page_walks,
    },
    {
        .name = "FP_COMP_OPS_EXE",
        .desc = "Floating point computational micro-ops executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x1,
        .code = 0x10,
    },
    {
        .name = "FP_ASSIST",
        .desc = "Floating point assists",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x2,
        .code = 0x11,
    },
    {
        .name = "MUL",
        .desc = "Multiply operations executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x2,
        .code = 0x12,
    },
    {
        .name = "DIV",
        .desc = "Divide operations executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x2,
        .code = 0x13,
    },
    {
        .name = "CYCLES_DIV_BUSY",
        .desc = "Cycles the divider is busy",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x1,
        .code = 0x14,
    },
    {
        .name = "IDLE_DURING_DIV",
        .desc = "Cycles the divider is busy and all other execution units are idle",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x1,
        .code = 0x18,
    },
    {
        .name = "DELAYED_BYPASS",
        .desc = "Delayed bypass",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x2,
        .code = 0x19,
        .numasks = LIBPFM_ARRAY_SIZE(core_delayed_bypass),
        .ngrp = 1,
        .umasks = core_delayed_bypass,
    },
    {
        .name = "L2_ADS",
        .desc = "Cycles L2 address bus is in use",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x21,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads,
    },
    {
        .name = "L2_DBUS_BUSY_RD",
        .desc = "Cycles the L2 transfers data to the core",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x23,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_LINES_IN",
        .desc = "L2 cache misses",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_lines_in),
        .ngrp = 2,
        .umasks = core_l2_lines_in,
    },
    {
        .name = "L2_M_LINES_IN",
        .desc = "L2 cache line modifications",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x25,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_LINES_OUT",
        .desc = "L2 cache lines evicted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x26,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_lines_in),
        .ngrp = 2,
        .umasks = core_l2_lines_in, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_M_LINES_OUT",
        .desc = "Modified lines evicted from the L2 cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x27,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_lines_in),
        .ngrp = 2,
        .umasks = core_l2_lines_in, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_IFETCH",
        .desc = "L2 cacheable instruction fetch requests",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x28,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ifetch),
        .ngrp = 2,
        .umasks = core_l2_ifetch,
    },
    {
        .name = "L2_LD",
        .desc = "L2 cache reads",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x29,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ld),
        .ngrp = 3,
        .umasks = core_l2_ld,
    },
    {
        .name = "L2_ST",
        .desc = "L2 store requests",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2a,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ifetch),
        .ngrp = 2,
        .umasks = core_l2_ifetch, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_LOCK",
        .desc = "L2 locked accesses",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2b,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ifetch),
        .ngrp = 2,
        .umasks = core_l2_ifetch, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_RQSTS",
        .desc = "L2 cache requests",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ld),
        .ngrp = 3,
        .umasks = core_l2_ld, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_REJECT_BUSQ",
        .desc = "Rejected L2 cache requests",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x30,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ld),
        .ngrp = 3,
        .umasks = core_l2_ld, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_NO_REQ",
        .desc = "Cycles no L2 cache requests are pending",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x32,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads, /* identical to actual umasks list for this event */
    },
    {
        .name = "EIST_TRANS",
        .desc = "Number of Enhanced Intel SpeedStep(R) Technology (EIST) transitions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3a,
    },
    {
        .name = "THERMAL_TRIP",
        .desc = "Number of thermal trips",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc03b,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Core cycles when core is not halted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3c,
        .numasks = LIBPFM_ARRAY_SIZE(core_cpu_clk_unhalted),
        .ngrp = 1,
        .umasks = core_cpu_clk_unhalted,
    },
    {
        .name = "L1D_CACHE_LD",
        .desc = "L1 cacheable data reads",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x40,
        .numasks = LIBPFM_ARRAY_SIZE(core_l1d_cache_ld),
        .ngrp = 1,
        .umasks = core_l1d_cache_ld,
    },
    {
        .name = "L1D_CACHE_ST",
        .desc = "L1 cacheable data writes",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x41,
        .numasks = LIBPFM_ARRAY_SIZE(core_l1d_cache_ld),
        .ngrp = 1,
        .umasks = core_l1d_cache_ld, /* identical to actual umasks list for this event */
    },
    {
        .name = "L1D_CACHE_LOCK",
        .desc = "L1 data cacheable locked reads",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x42,
        .numasks = LIBPFM_ARRAY_SIZE(core_l1d_cache_ld),
        .ngrp = 1,
        .umasks = core_l1d_cache_ld, /* identical to actual umasks list for this event */
    },
    {
        .name = "L1D_ALL_REF",
        .desc = "All references to the L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x143,
    },
    {
        .name = "L1D_ALL_CACHE_REF",
        .desc = "L1 Data cacheable reads and writes",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x243,
    },
    {
        .name = "L1D_REPL",
        .desc = "Cache lines allocated in the L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xf45,
    },
    {
        .name = "L1D_M_REPL",
        .desc = "Modified cache lines allocated in the L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x46,
    },
    {
        .name = "L1D_M_EVICT",
        .desc = "Modified cache lines evicted from the L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x47,
    },
    {
        .name = "L1D_PEND_MISS",
        .desc = "Total number of outstanding L1 data cache misses at any cycle",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x48,
    },
    {
        .name = "L1D_SPLIT",
        .desc = "Cache line split from L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x49,
        .numasks = LIBPFM_ARRAY_SIZE(core_l1d_split),
        .ngrp = 1,
        .umasks = core_l1d_split,
    },
    {
        .name = "SSE_PRE_MISS",
        .desc = "Streaming SIMD Extensions (SSE) instructions missing all cache levels",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4b,
        .numasks = LIBPFM_ARRAY_SIZE(core_sse_pre_miss),
        .ngrp = 1,
        .umasks = core_sse_pre_miss,
    },
    {
        .name = "LOAD_HIT_PRE",
        .desc =
            "Load operations conflicting with a software prefetch to the same address",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4c,
    },
    {
        .name = "L1D_PREFETCH",
        .desc = "L1 data cache prefetch",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4e,
        .numasks = LIBPFM_ARRAY_SIZE(core_l1d_prefetch),
        .ngrp = 1,
        .umasks = core_l1d_prefetch,
    },
    {
        .name = "BUS_REQUEST_OUTSTANDING",
        .desc = "Number of pending full cache line read transactions on the bus "
                "occurring in each cycle",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x60,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding,
    },
    {
        .name = "BUS_BNR_DRV",
        .desc = "Number of Bus Not Ready signals asserted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x61,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_bnr_drv),
        .ngrp = 1,
        .umasks = core_bus_bnr_drv,
    },
    {
        .name = "BUS_DRDY_CLOCKS",
        .desc = "Bus cycles when data is sent on the bus",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x62,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_bnr_drv),
        .ngrp = 1,
        .umasks = core_bus_bnr_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_LOCK_CLOCKS",
        .desc = "Bus cycles when a LOCK signal is asserted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x63,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_DATA_RCV",
        .desc = "Bus cycles while processor receives data",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x64,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_BRD",
        .desc = "Burst read bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x65,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_RFO",
        .desc = "RFO bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x66,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_WB",
        .desc = "Explicit writeback bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x67,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_IFETCH",
        .desc = "Instruction-fetch bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x68,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_INVAL",
        .desc = "Invalidate bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x69,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_PWR",
        .desc = "Partial write bus transaction",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6a,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_P",
        .desc = "Partial bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6b,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_IO",
        .desc = "IO bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6c,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_DEF",
        .desc = "Deferred bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6d,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_BURST",
        .desc = "Burst (full cache-line) bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6e,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_MEM",
        .desc = "Memory bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6f,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_TRANS_ANY",
        .desc = "All bus transactions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x70,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "EXT_SNOOP",
        .desc = "External snoops responses",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x77,
        .numasks = LIBPFM_ARRAY_SIZE(core_ext_snoop),
        .ngrp = 2,
        .umasks = core_ext_snoop,
    },
    {
        .name = "CMP_SNOOP",
        .desc = "L1 data cache is snooped by other core",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x78,
        .numasks = LIBPFM_ARRAY_SIZE(core_cmp_snoop),
        .ngrp = 2,
        .umasks = core_cmp_snoop,
    },
    {
        .name = "BUS_HIT_DRV",
        .desc = "HIT signal asserted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7a,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_bnr_drv),
        .ngrp = 1,
        .umasks = core_bus_bnr_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_HITM_DRV",
        .desc = "HITM signal asserted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7b,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_bnr_drv),
        .ngrp = 1,
        .umasks = core_bus_bnr_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUSQ_EMPTY",
        .desc = "Bus queue is empty",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7d,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_bnr_drv),
        .ngrp = 1,
        .umasks = core_bus_bnr_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "SNOOP_STALL_DRV",
        .desc = "Bus stalled for snoops",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7e,
        .numasks = LIBPFM_ARRAY_SIZE(core_bus_request_outstanding),
        .ngrp = 2,
        .umasks = core_bus_request_outstanding, /* identical to actual umasks list for
                                                   this event */
    },
    {
        .name = "BUS_IO_WAIT",
        .desc = "IO requests waiting in the bus queue",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7f,
        .numasks = LIBPFM_ARRAY_SIZE(core_l2_ads),
        .ngrp = 1,
        .umasks = core_l2_ads, /* identical to actual umasks list for this event */
    },
    {
        .name = "L1I_READS",
        .desc = "Instruction fetches",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x80,
    },
    {
        .name = "L1I_MISSES",
        .desc = "Instruction Fetch Unit misses",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x81,
    },
    {
        .name = "ITLB",
        .desc = "ITLB small page misses",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x82,
        .numasks = LIBPFM_ARRAY_SIZE(core_itlb),
        .ngrp = 1,
        .umasks = core_itlb,
    },
    {
        .name = "INST_QUEUE",
        .desc = "Cycles during which the instruction queue is full",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x83,
        .numasks = LIBPFM_ARRAY_SIZE(core_inst_queue),
        .ngrp = 1,
        .umasks = core_inst_queue,
    },
    {
        .name = "CYCLES_L1I_MEM_STALLED",
        .desc = "Cycles during which instruction fetches are stalled",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x86,
    },
    {
        .name = "ILD_STALL",
        .desc = "Instruction Length Decoder stall cycles due to a length changing prefix",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x87,
    },
    {
        .name = "BR_INST_EXEC",
        .desc = "Branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x88,
    },
    {
        .name = "BR_MISSP_EXEC",
        .desc = "Mispredicted branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x89,
    },
    {
        .name = "BR_BAC_MISSP_EXEC",
        .desc = "Branch instructions mispredicted at decoding",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8a,
    },
    {
        .name = "BR_CND_EXEC",
        .desc = "Conditional branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8b,
    },
    {
        .name = "BR_CND_MISSP_EXEC",
        .desc = "Mispredicted conditional branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8c,
    },
    {
        .name = "BR_IND_EXEC",
        .desc = "Indirect branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8d,
    },
    {
        .name = "BR_IND_MISSP_EXEC",
        .desc = "Mispredicted indirect branch instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8e,
    },
    {
        .name = "BR_RET_EXEC",
        .desc = "RET instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8f,
    },
    {
        .name = "BR_RET_MISSP_EXEC",
        .desc = "Mispredicted RET instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x90,
    },
    {
        .name = "BR_RET_BAC_MISSP_EXEC",
        .desc = "RET instructions executed mispredicted at decoding",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x91,
    },
    {
        .name = "BR_CALL_EXEC",
        .desc = "CALL instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x92,
    },
    {
        .name = "BR_CALL_MISSP_EXEC",
        .desc = "Mispredicted CALL instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x93,
    },
    {
        .name = "BR_IND_CALL_EXEC",
        .desc = "Indirect CALL instructions executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x94,
    },
    {
        .name = "BR_TKN_BUBBLE_1",
        .desc = "Branch predicted taken with bubble I",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x97,
    },
    {
        .name = "BR_TKN_BUBBLE_2",
        .desc = "Branch predicted taken with bubble II",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x98,
    },
    {
        .name = "MACRO_INSTS",
        .desc = "Instructions decoded",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xaa,
        .numasks = LIBPFM_ARRAY_SIZE(core_macro_insts),
        .ngrp = 1,
        .umasks = core_macro_insts,
    },
    {
        .name = "ESP",
        .desc = "ESP register content synchronization",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xab,
        .numasks = LIBPFM_ARRAY_SIZE(core_esp),
        .ngrp = 1,
        .umasks = core_esp,
    },
    {
        .name = "SIMD_UOPS_EXEC",
        .desc = "SIMD micro-ops executed (excluding stores)",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb0,
    },
    {
        .name = "SIMD_SAT_UOP_EXEC",
        .desc = "SIMD saturated arithmetic micro-ops executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb1,
    },
    {
        .name = "SIMD_UOP_TYPE_EXEC",
        .desc = "SIMD packed multiply micro-ops executed",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb3,
        .numasks = LIBPFM_ARRAY_SIZE(core_simd_uop_type_exec),
        .ngrp = 1,
        .umasks = core_simd_uop_type_exec,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(core_inst_retired),
        .ngrp = 1,
        .umasks = core_inst_retired,
    },
    {
        .name = "X87_OPS_RETIRED",
        .desc = "FXCH instructions retired",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc1,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(core_x87_ops_retired),
        .ngrp = 1,
        .umasks = core_x87_ops_retired,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Fused load+op or load+indirect branch retired",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc2,
        .numasks = LIBPFM_ARRAY_SIZE(core_uops_retired),
        .ngrp = 1,
        .umasks = core_uops_retired,
    },
    {
        .name = "MACHINE_NUKES",
        .desc = "Self-Modifying Code detected",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc3,
        .numasks = LIBPFM_ARRAY_SIZE(core_machine_nukes),
        .ngrp = 1,
        .umasks = core_machine_nukes,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc4,
        .numasks = LIBPFM_ARRAY_SIZE(core_br_inst_retired),
        .ngrp = 1,
        .umasks = core_br_inst_retired,
    },
    {
        .name = "BR_INST_RETIRED_MISPRED",
        .desc = "Retired mispredicted branch instructions (Precise_Event)",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
    },
    {
        .name = "CYCLES_INT_MASKED",
        .desc = "Cycles during which interrupts are disabled",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x1c6,
    },
    {
        .name = "CYCLES_INT_PENDING_AND_MASKED",
        .desc = "Cycles during which interrupts are pending and disabled",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2c6,
    },
    {
        .name = "SIMD_INST_RETIRED",
        .desc = "Retired Streaming SIMD Extensions (SSE) packed-single instructions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc7,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(core_simd_inst_retired),
        .ngrp = 1,
        .umasks = core_simd_inst_retired,
    },
    {
        .name = "HW_INT_RCV",
        .desc = "Hardware interrupts received",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc8,
    },
    {
        .name = "ITLB_MISS_RETIRED",
        .desc = "Retired instructions that missed the ITLB",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc9,
    },
    {
        .name = "SIMD_COMP_INST_RETIRED",
        .desc = "Retired computational Streaming SIMD Extensions (SSE) packed-single "
                "instructions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xca,
        .numasks = LIBPFM_ARRAY_SIZE(core_simd_comp_inst_retired),
        .ngrp = 1,
        .umasks = core_simd_comp_inst_retired,
    },
    {
        .name = "MEM_LOAD_RETIRED",
        .desc = "Retired loads that miss the L1 data cache",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x1,
        .code = 0xcb,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(core_mem_load_retired),
        .ngrp = 1,
        .umasks = core_mem_load_retired,
    },
    {
        .name = "FP_MMX_TRANS",
        .desc = "Transitions from MMX (TM) Instructions to Floating Point Instructions",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcc,
        .numasks = LIBPFM_ARRAY_SIZE(core_fp_mmx_trans),
        .ngrp = 1,
        .umasks = core_fp_mmx_trans,
    },
    {
        .name = "SIMD_ASSIST",
        .desc = "SIMD assists invoked",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcd,
    },
    {
        .name = "SIMD_INSTR_RETIRED",
        .desc = "SIMD Instructions retired",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xce,
    },
    {
        .name = "SIMD_SAT_INSTR_RETIRED",
        .desc = "Saturated arithmetic instructions retired",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcf,
    },
    {
        .name = "RAT_STALLS",
        .desc = "ROB read port stalls cycles",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xd2,
        .numasks = LIBPFM_ARRAY_SIZE(core_rat_stalls),
        .ngrp = 1,
        .umasks = core_rat_stalls,
    },
    {
        .name = "SEG_RENAME_STALLS",
        .desc = "Segment rename stalls - ES ",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xd4,
        .numasks = LIBPFM_ARRAY_SIZE(core_seg_rename_stalls),
        .ngrp = 1,
        .umasks = core_seg_rename_stalls,
    },
    {
        .name = "SEG_REG_RENAMES",
        .desc = "Segment renames - ES",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xd5,
        .numasks = LIBPFM_ARRAY_SIZE(core_seg_reg_renames),
        .ngrp = 1,
        .umasks = core_seg_reg_renames,
    },
    {
        .name = "RESOURCE_STALLS",
        .desc = "Cycles during which the ROB is full",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xdc,
        .numasks = LIBPFM_ARRAY_SIZE(core_resource_stalls),
        .ngrp = 1,
        .umasks = core_resource_stalls,
    },
    {
        .name = "BR_INST_DECODED",
        .desc = "Branch instructions decoded",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe0,
    },
    {
        .name = "BOGUS_BR",
        .desc = "Bogus branches",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe4,
    },
    {
        .name = "BACLEARS",
        .desc = "BACLEARS asserted",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe6,
    },
    {
        .name = "PREF_RQSTS_UP",
        .desc = "Upward prefetches issued from the DPL",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xf0,
    },
    {
        .name = "PREF_RQSTS_DN",
        .desc = "Downward prefetches issued from the DPL",
        .modmsk = INTEL_X86_ATTRS,
        .cntmsk = 0x3,
        .code = 0xf8,
    },
};
