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
 * PMU: atom (Intel Atom)
 */

static const intel_x86_umask_t atom_l2_reject_busq[] = {
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "I_STATE",
        .udesc = "Invalid cacheline",
        .ucode = 0x100,
        .grpid = 0,
    },
    {
        .uname = "S_STATE",
        .udesc = "Shared cacheline",
        .ucode = 0x200,
        .grpid = 0,
    },
    {
        .uname = "E_STATE",
        .udesc = "Exclusive cacheline",
        .ucode = 0x400,
        .grpid = 0,
    },
    {
        .uname = "M_STATE",
        .udesc = "Modified cacheline",
        .ucode = 0x800,
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
        .grpid = 1,
    },
    {
        .uname = "ANY",
        .udesc = "All inclusive",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 2,
    },
    {
        .uname = "PREFETCH",
        .udesc = "Hardware prefetch only",
        .ucode = 0x1000,
        .grpid = 2,
    },
};

static const intel_x86_umask_t atom_icache[] = {
    {
        .uname = "ACCESSES",
        .udesc = "Instruction fetches, including uncacheacble fetches",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISSES",
        .udesc =
            "Count all instructions fetches that miss the icache or produce memory "
            "requests. This includes uncacheache fetches. Any instruction fetch miss is "
            "counted only once and not once for every cycle it is outstanding",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t atom_l2_lock[] = {
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "I_STATE",
        .udesc = "Invalid cacheline",
        .ucode = 0x100,
        .grpid = 0,
    },
    {
        .uname = "S_STATE",
        .udesc = "Shared cacheline",
        .ucode = 0x200,
        .grpid = 0,
    },
    {
        .uname = "E_STATE",
        .udesc = "Exclusive cacheline",
        .ucode = 0x400,
        .grpid = 0,
    },
    {
        .uname = "M_STATE",
        .udesc = "Modified cacheline",
        .ucode = 0x800,
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
        .grpid = 1,
    },
};

static const intel_x86_umask_t atom_uops_retired[] = {
    {
        .uname = "ANY",
        .udesc = "Micro-ops retired",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "STALLED_CYCLES",
        .udesc = "Cycles no micro-ops retired",
        .ucode = 0x1000 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS",
        .udesc = "Periods no micro-ops retired",
        .ucode = 0x1000 | INTEL_X86_MOD_EDGE | INTEL_X86_MOD_INV |
                 (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_l2_m_lines_out[] = {
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
        .grpid = 1,
    },
};

static const intel_x86_umask_t atom_simd_comp_inst_retired[] = {
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

static const intel_x86_umask_t atom_simd_sat_uop_exec[] = {
    {
        .uname = "S",
        .udesc = "SIMD saturated arithmetic micro-ops executed",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AR",
        .udesc = "SIMD saturated arithmetic micro-ops retired",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Instructions retired using generic counter (precise event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_PEBS | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_l1d_cache[] = {
    {
        .uname = "LD",
        .udesc = "L1 Cacheable Data Reads",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ST",
        .udesc = "L1 Cacheable Data Writes",
        .ucode = 0x2200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_mul[] = {
    {
        .uname = "S",
        .udesc = "Multiply operations executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AR",
        .udesc = "Multiply operations retired",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_div[] = {
    {
        .uname = "S",
        .udesc = "Divide operations executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AR",
        .udesc = "Divide operations retired",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_bus_trans_p[] = {
    {
        .uname = "THIS_AGENT",
        .udesc = "This agent",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "ALL_AGENTS",
        .udesc = "Any agent on the bus",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
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
        .grpid = 1,
    },
};

static const intel_x86_umask_t atom_bus_io_wait[] = {
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
    },
};

static const intel_x86_umask_t atom_bus_hitm_drv[] = {
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

static const intel_x86_umask_t atom_itlb[] = {
    {
        .uname = "FLUSH",
        .udesc = "ITLB flushes",
        .ucode = 0x400,
    },
    {
        .uname = "MISSES",
        .udesc = "ITLB misses",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t atom_simd_uop_type_exec[] = {
    {
        .uname = "MUL_S",
        .udesc = "SIMD packed multiply micro-ops executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MUL_AR",
        .udesc = "SIMD packed multiply micro-ops retired",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SHIFT_S",
        .udesc = "SIMD packed shift micro-ops executed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SHIFT_AR",
        .udesc = "SIMD packed shift micro-ops retired",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACK_S",
        .udesc = "SIMD packed micro-ops executed",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACK_AR",
        .udesc = "SIMD packed micro-ops retired",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNPACK_S",
        .udesc = "SIMD unpacked micro-ops executed",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "UNPACK_AR",
        .udesc = "SIMD unpacked micro-ops retired",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOGICAL_S",
        .udesc = "SIMD packed logical micro-ops executed",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LOGICAL_AR",
        .udesc = "SIMD packed logical micro-ops retired",
        .ucode = 0x9000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ARITHMETIC_S",
        .udesc = "SIMD packed arithmetic micro-ops executed",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ARITHMETIC_AR",
        .udesc = "SIMD packed arithmetic micro-ops retired",
        .ucode = 0xa000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_simd_inst_retired[] = {
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
        .udesc = "Retired Streaming SIMD Extensions 2 (SSE2) vector instructions",
        .ucode = 0x1000,
    },
    {
        .uname = "ANY",
        .udesc = "Retired Streaming SIMD instructions",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_prefetch[] = {
    {
        .uname = "PREFETCHT0",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT0 instructions executed",
        .ucode = 0x100,
    },
    {
        .uname = "SW_L2",
        .udesc = "Streaming SIMD Extensions (SSE) PrefetchT1 and PrefetchT2 instructions "
                 "executed",
        .ucode = 0x600,
    },
    {
        .uname = "PREFETCHNTA",
        .udesc = "Streaming SIMD Extensions (SSE) Prefetch NTA instructions executed",
        .ucode = 0x800,
    },
};

static const intel_x86_umask_t atom_l2_rqsts[] = {
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
        .grpid = 1,
    },
    {
        .uname = "MESI",
        .udesc = "Any cacheline access",
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

static const intel_x86_umask_t atom_simd_uops_exec[] = {
    {
        .uname = "S",
        .udesc = "Number of SIMD saturated arithmetic micro-ops executed",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AR",
        .udesc = "Number of SIMD saturated arithmetic micro-ops retired",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_machine_clears[] = {
    {
        .uname = "SMC",
        .udesc = "Self-Modifying Code detected",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_br_inst_retired[] = {
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
        .uname = "MISPRED",
        .udesc = "Retired mispredicted branch instructions",
        .ucode = 0xa00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN",
        .udesc = "Retired taken branch instructions",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY1",
        .udesc = "Retired branch instructions",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_macro_insts[] = {
    {
        .uname = "NON_CISC_DECODED",
        .udesc = "Non-CISC macro instructions decoded ",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DECODED",
        .udesc = "All Instructions decoded",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_segment_reg_loads[] = {
    {
        .uname = "ANY",
        .udesc = "Number of segment register loads",
        .ucode = 0x8000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_baclears[] = {
    {
        .uname = "ANY",
        .udesc = "BACLEARS asserted",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_cycles_int_masked[] = {
    {
        .uname = "CYCLES_INT_MASKED",
        .udesc = "Cycles during which interrupts are disabled",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES_INT_PENDING_AND_MASKED",
        .udesc = "Cycles during which interrupts are pending and disabled",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_fp_assist[] = {
    {
        .uname = "S",
        .udesc = "Floating point assists for executed instructions",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AR",
        .udesc = "Floating point assists for retired instructions",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_data_tlb_misses[] = {
    {
        .uname = "DTLB_MISS",
        .udesc = "Memory accesses that missed the DTLB",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DTLB_MISS_LD",
        .udesc = "DTLB misses due to load operations",
        .ucode = 0x500,
    },
    {
        .uname = "L0_DTLB_MISS_LD",
        .udesc = "L0 (micro-TLB) misses due to load operations",
        .ucode = 0x900,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DTLB_MISS_ST",
        .udesc = "DTLB misses due to store operations",
        .ucode = 0x600,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_store_forwards[] = {
    {
        .uname = "GOOD",
        .udesc = "Good store forwards",
        .ucode = 0x8100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t atom_cpu_clk_unhalted[] = {
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
        .udesc = "Bus cycles when core is active and other is halted",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_mem_load_retired[] = {
    {
        .uname = "L2_HIT",
        .udesc = "Retired loads that hit the L2 cache (precise event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "L2_MISS",
        .udesc = "Retired loads that miss the L2 cache (precise event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "DTLB_MISS",
        .udesc = "Retired loads that miss the DTLB (precise event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t atom_x87_comp_ops_exe[] = {
    {
        .uname = "ANY_S",
        .udesc = "Floating point computational micro-ops executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_AR",
        .udesc = "Floating point computational micro-ops retired",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t atom_page_walks[] = {
    {
        .uname = "WALKS",
        .udesc = "Number of page-walks executed",
        .uequiv = "CYCLES",
        .ucode = 0x300 | INTEL_X86_MOD_EDGE,
        .modhw = _INTEL_X86_ATTR_E,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES",
        .udesc = "Duration of page-walks in core cycles",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_entry_t intel_atom_pe[] = {
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Unhalted core cycles",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x200000003ull,
        .code = 0x3c,
    },
    {
        .name = "UNHALTED_REFERENCE_CYCLES",
        .desc = "Unhalted reference cycle",
        .modmsk = INTEL_FIXED3_ATTRS,
        .cntmsk = 0x400000000ull,
        .code = 0x0300, /* pseudo encoding */
        .flags = INTEL_X86_FIXED,
    },
    {
        .name = "INSTRUCTION_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x100000003ull,
        .code = 0xc0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "This is an alias for INSTRUCTION_RETIRED",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "INSTRUCTION_RETIRED",
        .cntmsk = 0x10003,
        .code = 0xc0,
    },
    {
        .name = "LLC_REFERENCES",
        .desc = "Last level of cache references",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LAST_LEVEL_CACHE_REFERENCES",
        .desc = "This is an alias for LLC_REFERENCES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LLC_REFERENCES",
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LLC_MISSES",
        .desc = "Last level of cache misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "LAST_LEVEL_CACHE_MISSES",
        .desc = "This is an alias for LLC_MISSES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LLC_MISSES",
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Branch instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "BR_INST_RETIRED:ANY",
        .cntmsk = 0x3,
        .code = 0xc4,
    },
    {
        .name = "MISPREDICTED_BRANCH_RETIRED",
        .desc = "Mispredicted branch instruction retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
    },
    {
        .name = "SIMD_INSTR_RETIRED",
        .desc = "SIMD Instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xce,
    },
    {
        .name = "L2_REJECT_BUSQ",
        .desc = "Rejected L2 cache requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x30,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_reject_busq),
        .ngrp = 3,
        .umasks = atom_l2_reject_busq,
    },
    {
        .name = "SIMD_SAT_INSTR_RETIRED",
        .desc = "Saturated arithmetic instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcf,
    },
    {
        .name = "ICACHE",
        .desc = "Instruction fetches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x80,
        .numasks = LIBPFM_ARRAY_SIZE(atom_icache),
        .ngrp = 1,
        .umasks = atom_icache,
    },
    {
        .name = "L2_LOCK",
        .desc = "L2 locked accesses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2b,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_lock),
        .ngrp = 2,
        .umasks = atom_l2_lock,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Micro-ops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc2,
        .numasks = LIBPFM_ARRAY_SIZE(atom_uops_retired),
        .ngrp = 1,
        .umasks = atom_uops_retired,
    },
    {
        .name = "L2_M_LINES_OUT",
        .desc = "Modified lines evicted from the L2 cache",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x27,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks = atom_l2_m_lines_out,
    },
    {
        .name = "SIMD_COMP_INST_RETIRED",
        .desc = "Retired computational Streaming SIMD Extensions (SSE) instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xca,
        .numasks = LIBPFM_ARRAY_SIZE(atom_simd_comp_inst_retired),
        .ngrp = 1,
        .umasks = atom_simd_comp_inst_retired,
    },
    {
        .name = "SNOOP_STALL_DRV",
        .desc = "Bus stalled for snoops",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7e,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_BURST",
        .desc = "Burst (full cache-line) bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6e,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "SIMD_SAT_UOP_EXEC",
        .desc = "SIMD saturated arithmetic micro-ops executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb1,
        .numasks = LIBPFM_ARRAY_SIZE(atom_simd_sat_uop_exec),
        .ngrp = 1,
        .umasks = atom_simd_sat_uop_exec,
    },
    {
        .name = "BUS_TRANS_IO",
        .desc = "IO bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6c,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_RFO",
        .desc = "RFO bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x66,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "SIMD_ASSIST",
        .desc = "SIMD assists invoked",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcd,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(atom_inst_retired),
        .ngrp = 1,
        .umasks = atom_inst_retired,
    },
    {
        .name = "L1D_CACHE",
        .desc = "L1 Cacheable Data Reads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x40,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l1d_cache),
        .ngrp = 1,
        .umasks = atom_l1d_cache,
    },
    {
        .name = "MUL",
        .desc = "Multiply operations executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x12,
        .numasks = LIBPFM_ARRAY_SIZE(atom_mul),
        .ngrp = 1,
        .umasks = atom_mul,
    },
    {
        .name = "DIV",
        .desc = "Divide operations executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x13,
        .numasks = LIBPFM_ARRAY_SIZE(atom_div),
        .ngrp = 1,
        .umasks = atom_div,
    },
    {
        .name = "BUS_TRANS_P",
        .desc = "Partial bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6b,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_trans_p),
        .ngrp = 2,
        .umasks = atom_bus_trans_p,
    },
    {
        .name = "BUS_IO_WAIT",
        .desc = "IO requests waiting in the bus queue",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7f,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait,
    },
    {
        .name = "L2_M_LINES_IN",
        .desc = "L2 cache line modifications",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x25,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_LINES_IN",
        .desc = "L2 cache misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUSQ_EMPTY",
        .desc = "Bus queue is empty",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7d,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_IFETCH",
        .desc = "L2 cacheable instruction fetch requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x28,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_lock),
        .ngrp = 2,
        .umasks = atom_l2_lock, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_HITM_DRV",
        .desc = "HITM signal asserted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7b,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_hitm_drv),
        .ngrp = 1,
        .umasks = atom_bus_hitm_drv,
    },
    {
        .name = "ITLB",
        .desc = "ITLB hits",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x82,
        .numasks = LIBPFM_ARRAY_SIZE(atom_itlb),
        .ngrp = 1,
        .umasks = atom_itlb,
    },
    {
        .name = "BUS_TRANS_MEM",
        .desc = "Memory bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6f,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_PWR",
        .desc = "Partial write bus transaction",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6a,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "BR_INST_DECODED",
        .desc = "Branch instructions decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x1e0,
    },
    {
        .name = "BUS_TRANS_INVAL",
        .desc = "Invalidate bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x69,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "SIMD_UOP_TYPE_EXEC",
        .desc = "SIMD micro-ops executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb3,
        .numasks = LIBPFM_ARRAY_SIZE(atom_simd_uop_type_exec),
        .ngrp = 1,
        .umasks = atom_simd_uop_type_exec,
    },
    {
        .name = "SIMD_INST_RETIRED",
        .desc = "Retired Streaming SIMD Extensions (SSE) instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc7,
        .numasks = LIBPFM_ARRAY_SIZE(atom_simd_inst_retired),
        .ngrp = 1,
        .umasks = atom_simd_inst_retired,
    },
    {
        .name = "CYCLES_DIV_BUSY",
        .desc = "Cycles the divider is busy",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x14,
    },
    {
        .name = "PREFETCH",
        .desc = "Streaming SIMD Extensions (SSE) PrefetchT0 instructions executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7,
        .numasks = LIBPFM_ARRAY_SIZE(atom_prefetch),
        .ngrp = 1,
        .umasks = atom_prefetch,
    },
    {
        .name = "L2_RQSTS",
        .desc = "L2 cache requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_rqsts),
        .ngrp = 3,
        .umasks = atom_l2_rqsts,
    },
    {
        .name = "SIMD_UOPS_EXEC",
        .desc = "SIMD micro-ops executed (excluding stores)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xb0,
        .numasks = LIBPFM_ARRAY_SIZE(atom_simd_uops_exec),
        .ngrp = 1,
        .umasks = atom_simd_uops_exec,
    },
    {
        .name = "HW_INT_RCV",
        .desc = "Hardware interrupts received (warning overcounts by 2x)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x1c8,
    },
    {
        .name = "BUS_TRANS_BRD",
        .desc = "Burst read bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x65,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_trans_p),
        .ngrp = 2,
        .umasks = atom_bus_trans_p, /* identical to actual umasks list for this event */
    },
    {
        .name = "BOGUS_BR",
        .desc = "Bogus branches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe4,
    },
    {
        .name = "BUS_DATA_RCV",
        .desc = "Bus cycles while processor receives data",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x64,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
    {
        .name = "MACHINE_CLEARS",
        .desc = "Self-Modifying Code detected",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc3,
        .numasks = LIBPFM_ARRAY_SIZE(atom_machine_clears),
        .ngrp = 1,
        .umasks = atom_machine_clears,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc4,
        .numasks = LIBPFM_ARRAY_SIZE(atom_br_inst_retired),
        .ngrp = 1,
        .umasks = atom_br_inst_retired,
    },
    {
        .name = "L2_ADS",
        .desc = "Cycles L2 address bus is in use",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x21,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
    {
        .name = "EIST_TRANS",
        .desc = "Number of Enhanced Intel SpeedStep(R) Technology (EIST) transitions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3a,
    },
    {
        .name = "BUS_TRANS_WB",
        .desc = "Explicit writeback bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x67,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "MACRO_INSTS",
        .desc = "Macro-instructions decoded",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xaa,
        .numasks = LIBPFM_ARRAY_SIZE(atom_macro_insts),
        .ngrp = 1,
        .umasks = atom_macro_insts,
    },
    {
        .name = "L2_LINES_OUT",
        .desc = "L2 cache lines evicted. ",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x26,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_LD",
        .desc = "L2 cache reads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x29,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_rqsts),
        .ngrp = 3,
        .umasks = atom_l2_rqsts, /* identical to actual umasks list for this event */
    },
    {
        .name = "SEGMENT_REG_LOADS",
        .desc = "Number of segment register loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6,
        .numasks = LIBPFM_ARRAY_SIZE(atom_segment_reg_loads),
        .ngrp = 1,
        .umasks = atom_segment_reg_loads,
    },
    {
        .name = "L2_NO_REQ",
        .desc = "Cycles no L2 cache requests are pending",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x32,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
    {
        .name = "THERMAL_TRIP",
        .desc = "Number of thermal trips",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc03b,
    },
    {
        .name = "EXT_SNOOP",
        .desc = "External snoops",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x77,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_lock),
        .ngrp = 2,
        .umasks = atom_l2_lock, /* identical to actual umasks list for this event */
    },
    {
        .name = "BACLEARS",
        .desc = "Branch address calculator",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe6,
        .numasks = LIBPFM_ARRAY_SIZE(atom_baclears),
        .ngrp = 1,
        .umasks = atom_baclears,
    },
    {
        .name = "CYCLES_INT_MASKED",
        .desc = "Cycles during which interrupts are disabled",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc6,
        .numasks = LIBPFM_ARRAY_SIZE(atom_cycles_int_masked),
        .ngrp = 1,
        .umasks = atom_cycles_int_masked,
    },
    {
        .name = "FP_ASSIST",
        .desc = "Floating point assists",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x11,
        .numasks = LIBPFM_ARRAY_SIZE(atom_fp_assist),
        .ngrp = 1,
        .umasks = atom_fp_assist,
    },
    {
        .name = "L2_ST",
        .desc = "L2 store requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2a,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_lock),
        .ngrp = 2,
        .umasks = atom_l2_lock, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_DEF",
        .desc = "Deferred bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x6d,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "DATA_TLB_MISSES",
        .desc = "Memory accesses that missed the DTLB",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x8,
        .numasks = LIBPFM_ARRAY_SIZE(atom_data_tlb_misses),
        .ngrp = 1,
        .umasks = atom_data_tlb_misses,
    },
    {
        .name = "BUS_BNR_DRV",
        .desc = "Number of Bus Not Ready signals asserted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x61,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_hitm_drv),
        .ngrp = 1,
        .umasks = atom_bus_hitm_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "STORE_FORWARDS",
        .desc = "All store forwards",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2,
        .numasks = LIBPFM_ARRAY_SIZE(atom_store_forwards),
        .ngrp = 1,
        .umasks = atom_store_forwards,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Core cycles when core is not halted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3c,
        .numasks = LIBPFM_ARRAY_SIZE(atom_cpu_clk_unhalted),
        .ngrp = 1,
        .umasks = atom_cpu_clk_unhalted,
    },
    {
        .name = "BUS_TRANS_ANY",
        .desc = "All bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x70,
        .numasks = LIBPFM_ARRAY_SIZE(atom_l2_m_lines_out),
        .ngrp = 2,
        .umasks =
            atom_l2_m_lines_out, /* identical to actual umasks list for this event */
    },
    {
        .name = "MEM_LOAD_RETIRED",
        .desc = "Retired loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcb,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(atom_mem_load_retired),
        .ngrp = 1,
        .umasks = atom_mem_load_retired,
    },
    {
        .name = "X87_COMP_OPS_EXE",
        .desc = "Floating point computational micro-ops executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x10,
        .numasks = LIBPFM_ARRAY_SIZE(atom_x87_comp_ops_exe),
        .ngrp = 1,
        .umasks = atom_x87_comp_ops_exe,
    },
    {
        .name = "PAGE_WALKS",
        .desc = "Number of page-walks executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc,
        .numasks = LIBPFM_ARRAY_SIZE(atom_page_walks),
        .ngrp = 1,
        .umasks = atom_page_walks,
    },
    {
        .name = "BUS_LOCK_CLOCKS",
        .desc = "Bus cycles when a LOCK signal is asserted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x63,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_trans_p),
        .ngrp = 2,
        .umasks = atom_bus_trans_p, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_REQUEST_OUTSTANDING",
        .desc = "Outstanding cacheable data read bus requests duration",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x60,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_trans_p),
        .ngrp = 2,
        .umasks = atom_bus_trans_p, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_TRANS_IFETCH",
        .desc = "Instruction-fetch bus transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x68,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_trans_p),
        .ngrp = 2,
        .umasks = atom_bus_trans_p, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_HIT_DRV",
        .desc = "HIT signal asserted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x7a,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_hitm_drv),
        .ngrp = 1,
        .umasks = atom_bus_hitm_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "BUS_DRDY_CLOCKS",
        .desc = "Bus cycles when data is sent on the bus",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x62,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_hitm_drv),
        .ngrp = 1,
        .umasks = atom_bus_hitm_drv, /* identical to actual umasks list for this event */
    },
    {
        .name = "L2_DBUS_BUSY",
        .desc = "Cycles the L2 cache data bus is busy",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x3,
        .code = 0x22,
        .numasks = LIBPFM_ARRAY_SIZE(atom_bus_io_wait),
        .ngrp = 1,
        .umasks = atom_bus_io_wait, /* identical to actual umasks list for this event */
    },
};
