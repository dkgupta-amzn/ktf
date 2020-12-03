/*
 * Copyright (c) 2012 Google, Inc
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
 * PMU: ivb (Intel Ivy Bridge)
 * PMU: ivb_ep (Intel Ivy Bridge EP)
 */

static const intel_x86_umask_t ivb_arith[] = {
    {
        .uname = "FPU_DIV_ACTIVE",
        .udesc = "Cycles that the divider is active, includes integer and floating point",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FPU_DIV",
        .udesc = "Number of cycles the divider is activated, includes integer and "
                 "floating point",
        .ucode = 0x400 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_br_inst_exec[] = {
    {
        .uname = "NONTAKEN_COND",
        .udesc = "All macro conditional non-taken branch instructions",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_COND",
        .udesc = "All macro conditional taken branch instructions",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_DIRECT_JUMP",
        .udesc = "All macro unconditional taken branch instructions, excluding calls and "
                 "indirects",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "All taken indirect branches that are not calls nor returns",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_NEAR_RETURN",
        .udesc = "All taken indirect branches that have a return mnemonic",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_DIRECT_NEAR_CALL",
        .udesc = "All taken non-indirect calls",
        .ucode = 0x9000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_NEAR_CALL",
        .udesc = "All taken indirect calls, including both register and memory indirect",
        .ucode = 0xa000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All near executed branches instructions (not necessarily retired)",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL_COND",
        .udesc = "All macro conditional branch instructions",
        .ucode = 0xc100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_COND",
        .udesc = "All macro conditional branch instructions",
        .ucode = 0xc100,
        .uequiv = "ALL_COND",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "All indirect branches that are not calls nor returns",
        .ucode = 0xc400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_DIRECT_NEAR_CALL",
        .udesc = "All non-indirect calls",
        .ucode = 0xd000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_DIRECT_JUMP",
        .udesc = "All direct jumps",
        .ucode = 0xc200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_INDIRECT_NEAR_RET",
        .udesc = "All indirect near returns",
        .ucode = 0xc800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_br_inst_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All taken and not taken macro branches including far branches (Precise "
                 "Event)",
        .ucode = 0x0000, /* architectural encoding */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "COND",
        .udesc = "All taken and not taken macro conditional branch instructions (Precise "
                 "Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "FAR_BRANCH",
        .udesc = "Number of far branch instructions retired (Precise Event)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_CALL",
        .udesc = "All macro direct and indirect near calls, does not count far calls "
                 "(Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_RETURN",
        .udesc = "Number of near ret instructions retired (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_TAKEN",
        .udesc = "Number of near branch taken instructions retired (Precise Event)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NOT_TAKEN",
        .udesc = "All not taken macro branch instructions retired (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_br_misp_exec[] = {
    {
        .uname = "NONTAKEN_COND",
        .udesc = "All non-taken mispredicted macro conditional branch instructions",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_COND",
        .udesc = "All taken mispredicted macro conditional branch instructions",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .udesc =
            "All taken mispredicted indirect branches that are not calls nor returns",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_NEAR_RETURN",
        .udesc = "All taken mispredicted indirect branches that have a return mnemonic",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_RETURN_NEAR",
        .udesc = "All taken mispredicted indirect branches that have a return mnemonic",
        .ucode = 0x8800,
        .uequiv = "TAKEN_NEAR_RETURN",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_NEAR_CALL",
        .udesc = "All taken mispredicted indirect calls, including both register and "
                 "memory indirect",
        .ucode = 0xa000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_COND",
        .udesc = "All mispredicted macro conditional branch instructions",
        .ucode = 0xc100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "All mispredicted indirect branches that are not calls nor returns",
        .ucode = 0xc400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All mispredicted branch instructions",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_br_misp_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All mispredicted macro branches (Precise Event)",
        .ucode = 0x0000, /* architectural encoding */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "COND",
        .udesc = "All mispredicted macro conditional branch instructions (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "CONDITIONAL",
        .udesc = "All mispredicted macro conditional branch instructions (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .uequiv = "COND",
    },
    {
        .uname = "NEAR_TAKEN",
        .udesc = "Number of branch instructions retired that were mispredicted and taken "
                 "(Precise Event)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_lock_cycles[] = {
    {
        .uname = "SPLIT_LOCK_UC_LOCK_DURATION",
        .udesc =
            "Cycles in which the L1D and L2 are locked, due to a UC lock or split lock",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CACHE_LOCK_DURATION",
        .udesc = "Cycles in which the L1D is locked",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_cpl_cycles[] = {
    {
        .uname = "RING0",
        .udesc = "Unhalted core cycles the thread was in ring 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RING0_TRANS",
        .udesc = "Transitions from rings 1, 2, or 3 to ring 0",
        .uequiv = "RING0:c=1:e=1",
        .ucode = 0x100 | INTEL_X86_MOD_EDGE | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RING123",
        .udesc = "Unhalted core cycles the thread was in rings 1, 2, or 3",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_cpu_clk_unhalted[] = {
    {
        .uname = "REF_P",
        .udesc = "Cycles when the core is unhalted (count at 100 Mhz)",
        .ucode = 0x100,
        .uequiv = "REF_XCLK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REF_XCLK",
        .udesc = "Count Xclk pulses (100Mhz) when the core is unhalted",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REF_XCLK_ANY",
        .udesc = "Count Xclk pulses (100Mhz) when the at least one thread on the "
                 "physical core is unhalted",
        .ucode = 0x100 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "REF_XCLK:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "THREAD_P",
        .udesc = "Cycles when thread is not halted",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ONE_THREAD_ACTIVE",
        .udesc = "Counts Xclk (100Mhz) pulses when this thread is unhalted and the other "
                 "thread is halted",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_dsb2mite_switches[] = {
    {
        .uname = "COUNT",
        .udesc = "Number of DSB to MITE switches",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PENALTY_CYCLES",
        .udesc = "Number of DSB to MITE switch true penalty cycles",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_dsb_fill[] = {
    {
        .uname = "EXCEED_DSB_LINES",
        .udesc = "DSB Fill encountered > 3 DSB lines",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_dtlb_load_misses[] = {
    {
        .uname = "MISS_CAUSES_A_WALK",
        .udesc = "Demand load miss in all TLB levels which causes a page walk of any "
                 "page size",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc = "Demand load miss in all TLB levels which causes a page walk that "
                 "completes for any page size",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_DURATION",
        .udesc = "Cycles PMH is busy with a walk due to demand loads",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_LD_MISS_CAUSES_A_WALK",
        .udesc = "Demand load miss in all TLB levels which causes a page walk of any "
                 "page size",
        .ucode = 0x8100,
        .uequiv = "MISS_CAUSES_A_WALK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_LD_WALK_COMPLETED",
        .udesc = "Demand load miss in all TLB levels which causes a page walk that "
                 "completes for any page size",
        .ucode = 0x8200,
        .uequiv = "WALK_COMPLETED",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_LD_WALK_DURATION",
        .udesc = "Cycles PMH is busy with a walk due to demand loads",
        .ucode = 0x8400,
        .uequiv = "WALK_DURATION",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "Number of load operations that missed L1TLB but hit L2TLB",
        .ucode = 0x45f, /* override event code */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_CODE_OVERRIDE,
    },
    {
        .uname = "LARGE_WALK_COMPLETED",
        .udesc = "Number of large page walks completed for demand loads",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
};
static const intel_x86_umask_t ivb_itlb_misses[] = {
    {
        .uname = "MISS_CAUSES_A_WALK",
        .udesc = "Miss in all TLB levels that causes a page walk of any page size "
                 "(4K/2M/4M/1G)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CAUSES_A_WALK",
        .udesc = "Miss in all TLB levels that causes a page walk of any page size "
                 "(4K/2M/4M/1G)",
        .ucode = 0x100,
        .uequiv = "MISS_CAUSES_A_WALK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "First level miss but second level hit; no page walk. Only relevant if "
                 "multiple levels",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc = "Miss in all TLB levels that causes a page walk that completes of any "
                 "page size (4K/2M/4M/1G)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_DURATION",
        .udesc = "Cycles PMH is busy with this walk",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LARGE_PAGE_WALK_COMPLETED",
        .udesc = "Number of completed page walks in ITLB due to STLB load misses for "
                 "large pages",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_dtlb_store_misses[] = {
    {
        .uname = "MISS_CAUSES_A_WALK",
        .udesc = "Miss in all TLB levels that causes a page walk of any page size "
                 "(4K/2M/4M/1G)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CAUSES_A_WALK",
        .udesc = "Miss in all TLB levels that causes a page walk of any page size "
                 "(4K/2M/4M/1G)",
        .ucode = 0x100,
        .uequiv = "MISS_CAUSES_A_WALK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "First level miss but second level hit; no page walk. Only relevant if "
                 "multiple levels",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc = "Miss in all TLB levels that causes a page walk that completes of any "
                 "page size (4K/2M/4M/1G)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_DURATION",
        .udesc = "Cycles PMH is busy with this walk",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_fp_assist[] = {
    {
        .uname = "ANY",
        .udesc = "Cycles with any input/output SSE or FP assists",
        .ucode = 0x1e00 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "SIMD_INPUT",
        .udesc = "Number of SIMD FP assists due to input values",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_OUTPUT",
        .udesc = "Number of SIMD FP assists due to output values",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "X87_INPUT",
        .udesc = "Number of X87 assists due to input value",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "X87_OUTPUT",
        .udesc = "Number of X87 assists due to output value",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_icache[] = {
    {
        .uname = "MISSES",
        .udesc = "Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. "
                 "Includes UC accesses",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFETCH_STALL",
        .udesc = "Number of cycles wher a code-fetch stalled due to L1 instruction cache "
                 "miss or iTLB miss",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HIT",
        .udesc = "Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. "
                 "Includes cacheable and uncacheable accesses and uncacheable fetches",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_idq[] = {
    {
        .uname = "EMPTY",
        .udesc = "Cycles IDQ is empty",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MITE_UOPS",
        .udesc = "Number of uops delivered to IDQ from MITE path",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DSB_UOPS",
        .udesc = "Number of uops delivered to IDQ from DSB path",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_DSB_UOPS",
        .udesc = "Number of uops delivered to IDQ when MS busy by DSB",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_MITE_UOPS",
        .udesc = "Number of uops delivered to IDQ when MS busy by MITE",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_UOPS",
        .udesc = "Number of uops were delivered to IDQ from MS by either DSB or MITE",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MITE_UOPS_CYCLES",
        .udesc = "Cycles where uops are delivered to IDQ from MITE (MITE active)",
        .uequiv = "MITE_UOPS:c=1",
        .ucode = 0x400 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DSB_UOPS_CYCLES",
        .udesc = "Cycles where uops are delivered to IDQ from DSB (DSB active)",
        .ucode = 0x800 | (0x1 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_DSB_UOPS_CYCLES",
        .udesc = "Cycles where uops delivered to IDQ when MS busy by DSB",
        .uequiv = "MS_DSB_UOPS:c=1",
        .ucode = 0x1000 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_MITE_UOPS_CYCLES",
        .udesc = "Cycles where uops delivered to IDQ when MS busy by MITE",
        .uequiv = "MS_MITE_UOPS:c=1",
        .ucode = 0x2000 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_UOPS_CYCLES",
        .udesc = "Cycles where uops delivered to IDQ from MS by either BSD or MITE",
        .uequiv = "MS_UOPS:c=1",
        .ucode = 0x3000 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_SWITCHES",
        .udesc =
            "Number of cycles that Uops were delivered into Instruction Decode Queue "
            "(IDQ) when MS_Busy, initiated by Decode Stream Buffer (DSB) or MITE",
        .ucode =
            0x3000 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uequiv = "MS_UOPS:c=1:e",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_DSB_UOPS",
        .udesc = "Number of uops delivered from either DSB paths",
        .ucode = 0x1800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DSB_CYCLES",
        .udesc = "Cycles MITE/MS delivered anything",
        .ucode = 0x1800 | (0x1 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DSB_CYCLES_4_UOPS",
        .udesc = "Cycles MITE/MS delivered 4 uops",
        .ucode = 0x1800 | (0x4 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_MITE_UOPS",
        .udesc = "Number of uops delivered from either MITE paths",
        .ucode = 0x2400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_MITE_CYCLES",
        .udesc = "Cycles DSB/MS delivered anything",
        .ucode = 0x2400 | (0x1 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_MITE_CYCLES_4_UOPS",
        .udesc = "Cycles MITE is  delivering 4 uops",
        .ucode = 0x2400 | (0x4 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_UOPS",
        .udesc = "Number of uops delivered to IDQ from any path",
        .ucode = 0x3c00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_DSB_UOPS_OCCUR",
        .udesc = "Occurrences of DSB MS going active",
        .uequiv = "MS_DSB_UOPS:c=1:e=1",
        .ucode = 0x1000 | INTEL_X86_MOD_EDGE | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_idq_uops_not_delivered[] = {
    {
        .uname = "CORE",
        .udesc = "Number of non-delivered uops to RAT (use cmask to qualify further)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "CYCLES_0_UOPS_DELIV_CORE",
        .udesc = "Cycles per thread when 4 or more uops are not delivered to the "
                 "Resource Allocation Table (RAT) when backend is not stalled",
        .ucode = 0x100 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uflags = INTEL_X86_NCOMBO,
        .uequiv = "CORE:c=4",
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_LE_1_UOP_DELIV_CORE",
        .udesc = "Cycles per thread when 3 or more uops are not delivered to the "
                 "Resource Allocation Table (RAT) when backend is not stalled",
        .ucode = 0x100 | (3 << INTEL_X86_CMASK_BIT), /* cnt=3 */
        .uequiv = "CORE:c=3",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_LE_2_UOP_DELIV_CORE",
        .udesc = "Cycles with less than 2 uops delivered by the front end",
        .ucode = 0x100 | (2 << INTEL_X86_CMASK_BIT), /* cnt=2 */
        .uequiv = "CORE:c=2",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_LE_3_UOP_DELIV_CORE",
        .udesc = "Cycles with less than 3 uops delivered by the front end",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "CORE:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_FE_WAS_OK",
        .udesc = "Cycles Front-End (FE) delivered 4 uops or Resource Allocation Table "
                 "(RAT) was stalling FE",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 inv=1 */
        .uequiv = "CORE:c=1:i",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_I,
    },
};

static const intel_x86_umask_t ivb_ild_stall[] = {
    {
        .uname = "LCP",
        .udesc = "Stall caused by changing prefix length of the instruction",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IQ_FULL",
        .udesc = "Stall cycles due to IQ full",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Number of instructions retired",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL",
        .udesc = "Precise instruction retired event to reduce effect of PEBS shadow IP "
                 "distribution (Precise Event)",
        .ucntmsk = 0x2,
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "PREC_DIST",
        .udesc = "Precise instruction retired event to reduce effect of PEBS shadow IP "
                 "distribution (Precise Event)",
        .ucntmsk = 0x2,
        .uequiv = "ALL",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },

};

static const intel_x86_umask_t ivb_itlb[] = {
    {
        .uname = "ITLB_FLUSH",
        .udesc = "Number of ITLB flushes, includes 4k/2M/4M pages",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "FLUSH",
        .udesc = "Number of ITLB flushes, includes 4k/2M/4M pages",
        .ucode = 0x100,
        .uequiv = "ITLB_FLUSH",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l1d[] = {
    {
        .uname = "REPLACEMENT",
        .udesc = "Number of cache lines brought into the L1D cache",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_move_elimination[] = {
    {
        .uname = "INT_NOT_ELIMINATED",
        .udesc =
            "Number of integer Move Elimination candidate uops that were not eliminated",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_NOT_ELIMINATED",
        .udesc =
            "Number of SIMD Move Elimination candidate uops that were not eliminated",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INT_ELIMINATED",
        .udesc = "Number of integer Move Elimination candidate uops that were eliminated",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_ELIMINATED",
        .udesc = "Number of SIMD Move Elimination candidate uops that were eliminated",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l1d_pend_miss[] = {
    {
        .uname = "OCCURRENCES",
        .udesc = "Occurrences of L1D_PEND_MISS going active",
        .uequiv = "PENDING:e=1:c=1",
        .ucode = 0x100 | INTEL_X86_MOD_EDGE | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "EDGE",
        .udesc = "Occurrences of L1D_PEND_MISS going active",
        .uequiv = "OCCURRENCES",
        .ucode = 0x100 | INTEL_X86_MOD_EDGE | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PENDING",
        .udesc = "Number of L1D load misses outstanding every cycle",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PENDING_CYCLES",
        .udesc = "Cycles with L1D load misses outstanding",
        .uequiv = "PENDING:c=1",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PENDING_CYCLES_ANY",
        .udesc = "Cycles with L1D load misses outstanding from any thread on the "
                 "physical core",
        .uequiv = "PENDING:c=1:t",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT) | INTEL_X86_MOD_ANY,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_T,
    },
    {
        .uname = "FB_FULL",
        .udesc = "Number of cycles a demand request was blocked due to Fill Buffer (FB) "
                 "unavailability",
        .ucode = 0x200 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_l2_l1d_wb_rqsts[] = {
    {
        .uname = "HIT_E",
        .udesc = "Non rejected writebacks from L1D to L2 cache lines in E state",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HIT_M",
        .udesc = "Non rejected writebacks from L1D to L2 cache lines in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISS",
        .udesc = "Not rejected writebacks that missed LLC",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL",
        .udesc = "Not rejected writebacks from L1D to L2 cache lines in any state",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l2_lines_in[] = {
    {
        .uname = "ANY",
        .udesc = "L2 cache lines filling (counting does not cover rejects)",
        .ucode = 0x700,
        .uequiv = "ALL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL",
        .udesc = "L2 cache lines filling (counting does not cover rejects)",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "E",
        .udesc = "L2 cache lines in E state (counting does not cover rejects)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I",
        .udesc = "L2 cache lines in I state (counting does not cover rejects)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S",
        .udesc = "L2 cache lines in S state (counting does not cover rejects)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l2_lines_out[] = {
    {
        .uname = "DEMAND_CLEAN",
        .udesc = "L2 clean line evicted by a demand",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DIRTY",
        .udesc = "L2 dirty line evicted by a demand",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_CLEAN",
        .udesc = "L2 clean line evicted by a prefetch",
        .ucode = 0x400,
        .uequiv = "PF_CLEAN",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_CLEAN",
        .udesc = "L2 clean line evicted by a prefetch",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PREFETCH_DIRTY",
        .udesc = "L2 dirty line evicted by an MLC Prefetch",
        .ucode = 0x800,
        .uequiv = "PF_DIRTY",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_DIRTY",
        .udesc = "L2 dirty line evicted by an MLC Prefetch",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRTY_ANY",
        .udesc = "Any L2 dirty line evicted (does not cover rejects)",
        .ucode = 0xa00,
        .uequiv = "DIRTY_ALL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DIRTY_ALL",
        .udesc = "Any L2 dirty line evicted (does not cover rejects)",
        .ucode = 0xa00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l2_rqsts[] = {
    {
        .uname = "ALL_CODE_RD",
        .udesc = "Any code request to L2 cache",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_RD_HIT",
        .udesc = "L2 cache hits when fetching instructions",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_RD_MISS",
        .udesc = "L2 cache misses when fetching instructions",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DEMAND_DATA_RD",
        .udesc = "Demand  data read requests to L2 cache",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD_HIT",
        .udesc = "Demand data read requests that hit L2",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_PF",
        .udesc = "Any L2 HW prefetch request to L2 cache",
        .ucode = 0xc000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_HIT",
        .udesc = "Requests from the L2 hardware prefetchers that hit L2 cache",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_MISS",
        .udesc = "Requests from the L2 hardware prefetchers that miss L2 cache",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_RFO",
        .udesc = "Any RFO requests to L2 cache",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_HIT",
        .udesc = "Store RFO requests that hit L2 cache",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_MISS",
        .udesc = "RFO requests that miss L2 cache",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l2_store_lock_rqsts[] = {
    {
        .uname = "MISS",
        .udesc = "RFOs that miss cache (I state)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "HIT_M",
        .udesc = "RFOs that hit cache lines in M state",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL",
        .udesc = "RFOs that access cache lines in any state",
        .ucode = 0xf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_l2_trans[] = {
    {
        .uname = "ALL",
        .udesc = "Transactions accessing the L2 pipe",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "CODE_RD",
        .udesc = "L2 cache accesses when fetching instructions",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_WB",
        .udesc = "L1D writebacks that access the L2 cache",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Demand Data Read requests that access the L2 cache",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_FILL",
        .udesc = "L2 fill requests that access the L2 cache",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_WB",
        .udesc = "L2 writebacks that access the L2 cache",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_PREFETCH",
        .udesc = "L2 or L3 HW prefetches that access the L2 cache (including rejects)",
        .ucode = 0x800,
        .uequiv = "ALL_PF",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_PF",
        .udesc = "L2 or L3 HW prefetches that access the L2 cache (including rejects)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO",
        .udesc = "RFO requests that access the L2 cache",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_ld_blocks[] = {
    {
        .uname = "STORE_FORWARD",
        .udesc =
            "Loads blocked by overlapping with store buffer that cannot be forwarded",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NO_SR",
        .udesc = "Number of times that split load operations are temporarily blocked "
                 "because all resources for handling the split accesses are in use",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_ld_blocks_partial[] = {
    {
        .uname = "ADDRESS_ALIAS",
        .udesc = "False dependencies in MOB due to partial compare on address",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_load_hit_pre[] = {
    {
        .uname = "HW_PF",
        .udesc = "Non sw-prefetch load dispatches that hit the fill buffer allocated for "
                 "HW prefetch",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SW_PF",
        .udesc = "Non sw-prefetch load dispatches that hit the fill buffer allocated for "
                 "SW prefetch",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_l3_lat_cache[] = {
    {
        .uname = "MISS",
        .udesc = "Core-originated cacheable demand requests missed L3",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REFERENCE",
        .udesc = "Core-originated cacheable demand requests that refer to L3",
        .ucode = 0x4f00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_machine_clears[] = {
    {
        .uname = "MASKMOV",
        .udesc = "The number of executed Intel AVX masked load operations that refer to "
                 "an illegal address range with the mask bits set to 0",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MEMORY_ORDERING",
        .udesc = "Number of Memory Ordering Machine Clears detected",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SMC",
        .udesc = "Self-Modifying Code detected",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "COUNT",
        .udesc = "Number of machine clears (nukes) of any type",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_mem_load_uops_llc_hit_retired[] = {
    {
        .uname = "XSNP_HIT",
        .udesc = "Load LLC Hit and a cross-core Snoop hits in on-pkg core cache (Precise "
                 "Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_HITM",
        .udesc = "Load had HitM Response from a core on same socket (shared LLC) "
                 "(Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_MISS",
        .udesc = "Load LLC Hit and a cross-core Snoop missed in on-pkg core cache "
                 "(Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_NONE",
        .udesc = "Load hit in last-level (L3) cache with no snoop needed (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_mem_load_uops_llc_miss_retired[] = {
    {
        .uname = "LOCAL_DRAM",
        .udesc = "Number of retired load uops that missed L3 but were service by local "
                 "RAM. Does not count hardware prefetches (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_DRAM",
        .udesc =
            "Number of retired load uops that missed L3 but were service by remote RAM, "
            "snoop not needed, snoop miss, snoop hit data not forwarded (Precise Event)",
        .ucode = 0xc00,
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_HITM",
        .udesc = "Number of retired load uops whose data sources was remote HITM "
                 "(Precise Event)",
        .ucode = 0x1000,
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_FWD",
        .udesc = "Load uops that miss in the L3 whose data source was forwarded from a "
                 "remote cache (Precise Event)",
        .ucode = 0x2000,
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_mem_load_uops_retired[] = {
    {
        .uname = "HIT_LFB",
        .udesc = "A load missed L1D but hit the Fill Buffer (Precise Event)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L1_MISS",
        .udesc = "Load miss in nearest-level (L1D) cache (Precise Event)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L1_HIT",
        .udesc = "Load hit in nearest-level (L1D) cache (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Load hit in mid-level (L2) cache (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L2_MISS",
        .udesc = "Load misses in mid-level (L2) cache (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_HIT",
        .udesc = "Load hit in last-level (L3) cache with no snoop needed (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Load miss in last-level (L3) cache (Precise Event)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_mem_trans_retired[] = {
    {
        .uname = "LATENCY_ABOVE_THRESHOLD",
        .udesc = "Memory load instructions retired above programmed clocks, minimum "
                 "threshold value is 3 (Precise Event and ldlat required)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_LDLAT,
    },
    {
        .uname = "PRECISE_STORE",
        .udesc =
            "Capture where stores occur, must use with PEBS (Precise Event required)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_mem_uops_retired[] = {
    {
        .uname = "ALL_LOADS",
        .udesc = "Any retired loads (Precise Event)",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ANY_LOADS",
        .udesc = "Any retired loads (Precise Event)",
        .ucode = 0x8100,
        .uequiv = "ALL_LOADS",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_STORES",
        .udesc = "Any retired stores (Precise Event)",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LOCK_LOADS",
        .udesc = "Locked retired loads (Precise Event)",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ANY_STORES",
        .udesc = "Any retired stores (Precise Event)",
        .ucode = 0x8200,
        .uequiv = "ALL_STORES",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SPLIT_LOADS",
        .udesc = "Retired loads causing cacheline splits (Precise Event)",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SPLIT_STORES",
        .udesc = "Retired stores causing cacheline splits (Precise Event)",
        .ucode = 0x4200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STLB_MISS_LOADS",
        .udesc = "STLB misses dues to retired loads (Precise Event)",
        .ucode = 0x1100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STLB_MISS_STORES",
        .udesc = "STLB misses dues to retired stores (Precise Event)",
        .ucode = 0x1200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_misalign_mem_ref[] = {
    {
        .uname = "LOADS",
        .udesc = "Speculative cache-line split load uops dispatched to the L1D",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STORES",
        .udesc = "Speculative cache-line split Store-address uops dispatched to L1D",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_offcore_requests[] = {
    {
        .uname = "ALL_DATA_RD",
        .udesc = "Demand and prefetch read requests sent to uncore",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DATA_READ",
        .udesc = "Demand and prefetch read requests sent to uncore",
        .uequiv = "ALL_DATA_RD",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD",
        .udesc = "Offcore code read requests, including cacheable and un-cacheables",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD",
        .udesc = "Demand Data Read requests sent to uncore",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO",
        .udesc = "Offcore Demand RFOs, includes regular RFO, Locks, ItoM",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_offcore_requests_outstanding[] = {
    {
        .uname = "ALL_DATA_RD_CYCLES",
        .udesc = "Cycles with cacheable data read transactions in the superQ",
        .uequiv = "ALL_DATA_RD:c=1",
        .ucode = 0x800 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD_CYCLES",
        .udesc = "Cycles with demand code reads transactions in the superQ",
        .uequiv = "DEMAND_CODE_RD:c=1",
        .ucode = 0x200 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD_CYCLES",
        .udesc = "Cycles with demand data read transactions in the superQ",
        .uequiv = "DEMAND_DATA_RD:c=1",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DATA_RD",
        .udesc = "Cacheable data read transactions in the superQ every cycle",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD",
        .udesc = "Code read transactions in the superQ every cycle",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD",
        .udesc = "Demand data read transactions in the superQ every cycle",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD_GE_6",
        .udesc = "Cycles with at lesat 6 offcore outstanding demand data read requests "
                 "in the uncore queue",
        .uequiv = "DEMAND_DATA_RD:c=6",
        .ucode = 0x100 | (6 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "DEMAND_RFO",
        .udesc = "Outstanding RFO (store) transactions in the superQ every cycle",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO_CYCLES",
        .udesc = "Cycles with outstanding RFO (store) transactions in the superQ",
        .uequiv = "DEMAND_RFO:c=1",
        .ucode = 0x400 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_other_assists[] = {
    {
        .uname = "AVX_TO_SSE",
        .udesc =
            "Number of transitions from AVX-256 to legacy SSE when penalty applicable",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_TO_AVX",
        .udesc =
            "Number of transitions from legacy SSE to AVX-256 when penalty applicable",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "AVX_STORE",
        .udesc = "Number of assists associated with 256-bit AVX stores",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WB",
        .udesc = "Number of times the microcode assist is invoked by hardware upon uop "
                 "writeback",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_resource_stalls[] = {
    {
        .uname = "ANY",
        .udesc = "Cycles stalled due to Resource Related reason",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "RS",
        .udesc = "Cycles stalled due to no eligible RS entry available",
        .ucode = 0x400,
    },
    {
        .uname = "SB",
        .udesc = "Cycles stalled due to no store buffers available (not including "
                 "draining from sync)",
        .ucode = 0x800,
    },
    {
        .uname = "ROB",
        .udesc = "Cycles stalled due to re-order buffer full",
        .ucode = 0x1000,
    },
};

static const intel_x86_umask_t ivb_rob_misc_events[] = {
    {
        .uname = "LBR_INSERTS",
        .udesc = "Count each time an new LBR record is saved by HW",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_rs_events[] = {
    {
        .uname = "EMPTY_CYCLES",
        .udesc = "Cycles the RS is empty for this thread",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "EMPTY_END",
        .udesc = "Counts number of time the Reservation Station (RS) goes from empty to "
                 "non-empty",
        .ucode = 0x100 | INTEL_X86_MOD_INV | INTEL_X86_MOD_EDGE |
                 (1 << INTEL_X86_CMASK_BIT), /* inv=1 edge=1 cnt=1 */
        .uequiv = "EMPTY_CYCLES:c=1:e:i",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_tlb_access[] = {
    {
        .uname = "STLB_HIT",
        .udesc = "Number of load operations that missed L1TLB but hit L2TLB",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "LOAD_STLB_HIT",
        .udesc = "Number of load operations that missed L1TLB but hit L2TLB",
        .ucode = 0x400,
        .uequiv = "STLB_HIT",
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_tlb_flush[] = {
    {
        .uname = "DTLB_THREAD",
        .udesc = "Number of DTLB flushes of thread-specific entries",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_ANY",
        .udesc = "Number of STLB flushes",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_uops_executed[] = {
    {
        .uname = "CORE",
        .udesc = "Counts total number of uops executed from any thread per cycle",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "THREAD",
        .udesc = "Counts total number of uops executed per thread each cycle",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Number of cycles with no uops executed",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_1_UOP_EXEC",
        .udesc = "Cycles where at least 1 uop was executed per thread",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_2_UOPS_EXEC",
        .udesc = "Cycles where at least 2 uops were executed per thread",
        .ucode = 0x100 | (2 << INTEL_X86_CMASK_BIT), /* cnt=2 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_3_UOPS_EXEC",
        .udesc = "Cycles where at least 3 uops were executed per thread",
        .ucode = 0x100 | (3 << INTEL_X86_CMASK_BIT), /* cnt=3 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_4_UOPS_EXEC",
        .udesc = "Cycles where at least 4 uops were executed per thread",
        .ucode = 0x100 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_CYCLES_GE_1",
        .udesc = "Cycles where at least 1 uop was executed from any thread",
        .ucode = 0x200 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "CORE:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_CYCLES_GE_2",
        .udesc = "Cycles where at least 2 uops were executed from any thread",
        .ucode = 0x200 | (2 << INTEL_X86_CMASK_BIT), /* cnt=2 */
        .uequiv = "CORE:c=2",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_CYCLES_GE_3",
        .udesc = "Cycles where at least 3 uops were executed from any thread",
        .ucode = 0x200 | (3 << INTEL_X86_CMASK_BIT), /* cnt=3 */
        .uequiv = "CORE:c=3",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_CYCLES_GE_4",
        .udesc = "Cycles where at least 4 uops were executed from any thread",
        .ucode = 0x200 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uequiv = "CORE:c=4",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_CYCLES_NONE",
        .udesc = "Cycles where no uop is executed on any thread",
        .ucode = 0x200 | INTEL_X86_MOD_INV, /* inv=1 */
        .uequiv = "CORE:i",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_I,
    },
};

static const intel_x86_umask_t ivb_uops_dispatched_port[] = {
    {
        .uname = "PORT_0",
        .udesc = "Cycles in which a uop is dispatched on port 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_1",
        .udesc = "Cycles in which a uop is dispatched on port 1",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_2",
        .udesc = "Cycles in which a uop is dispatched on port 2",
        .ucode = 0xc00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_3",
        .udesc = "Cycles in which a uop is dispatched on port 3",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_4",
        .udesc = "Cycles in which a uop is dispatched on port 4",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_5",
        .udesc = "Cycles in which a uop is dispatched on port 5",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_0_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 0 for any thread",
        .ucode = 0x100 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_0:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_1_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 1 for any thread",
        .ucode = 0x200 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_1:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_2_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 2 for any thread",
        .ucode = 0xc00 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_2:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_3_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 3 for any thread",
        .ucode = 0x3000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_3:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_4_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 4 for any thread",
        .ucode = 0x4000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_4:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_5_CORE",
        .udesc = "Cycles in which a uop is dispatched on port 5 for any thread",
        .ucode = 0x8000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_5:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
};

static const intel_x86_umask_t ivb_uops_issued[] = {
    {
        .uname = "ANY",
        .udesc = "Number of uops issued by the RAT to the Reservation Station (RS)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "CORE_STALL_CYCLES",
        .udesc = "Cycles no uops issued on this core (by any thread)",
        .uequiv = "ANY:c=1:i=1:t=1",
        .ucode =
            0x100 | INTEL_X86_MOD_ANY | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Cycles no uops issued by this thread",
        .uequiv = "ANY:c=1:i=1",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FLAGS_MERGE",
        .udesc = "Number of flags-merge uops allocated. Such uops adds delay",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_LEA",
        .udesc = "Number of slow LEA or similar uops allocated",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SINGLE_MUL",
        .udesc = "Number of multiply packed/scalar single precision uops allocated",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },

};

static const intel_x86_umask_t ivb_uops_retired[] = {
    {
        .uname = "ALL",
        .udesc = "All uops that actually retired (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "ANY",
        .udesc = "All uops that actually retired (Precise Event)",
        .ucode = 0x100,
        .uequiv = "ALL",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "RETIRE_SLOTS",
        .udesc = "Number of retirement slots used (Precise Event)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Cycles no executable uop retired (Precise Event)",
        .uequiv = "ALL:c=1:i=1",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "TOTAL_CYCLES",
        .udesc = "Total cycles using precise uop retired event (Precise Event)",
        .ucode =
            0x100 | INTEL_X86_MOD_INV | (10 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=10 */
        .uequiv = "ALL:c=10:i",
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t ivb_offcore_response[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Request: number of demand and DCU prefetch data reads of full and "
                 "partial cachelines as well as demand data page table entry cacheline "
                 "reads. Does not count L2 data read prefetches or instruction fetches",
        .ucode = 1ULL << (0 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Request: number of demand and DCU prefetch reads for ownership (RFO) "
                 "requests generated by a write to data cacheline. Does not count L2 RFO "
                 "prefetches",
        .ucode = 1ULL << (1 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_IFETCH",
        .udesc = "Request: number of demand and DCU prefetch instruction cacheline "
                 "reads. Does not count L2 code read prefetches",
        .ucode = 1ULL << (2 + 8),
        .grpid = 0,
    },
    {
        .uname = "WB",
        .udesc = "Request: number of writebacks (modified to exclusive) transactions",
        .ucode = 1ULL << (3 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_DATA_RD",
        .udesc = "Request: number of data cacheline reads generated by L2 prefetchers",
        .ucode = 1ULL << (4 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_RFO",
        .udesc = "Request: number of RFO requests generated by L2 prefetchers",
        .ucode = 1ULL << (5 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_IFETCH",
        .udesc = "Request: number of code reads generated by L2 prefetchers",
        .ucode = 1ULL << (6 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_LLC_DATA_RD",
        .udesc = "Request: number of L3 prefetcher requests to L2 for loads",
        .ucode = 1ULL << (7 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_LLC_RFO",
        .udesc = "Request: number of RFO requests generated by L2 prefetcher",
        .ucode = 1ULL << (8 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_LLC_IFETCH",
        .udesc =
            "Request: number of L2 prefetcher requests to L3 for instruction fetches",
        .ucode = 1ULL << (9 + 8),
        .grpid = 0,
    },
    {
        .uname = "BUS_LOCKS",
        .udesc = "Request: number bus lock and split lock requests",
        .ucode = 1ULL << (10 + 8),
        .grpid = 0,
    },
    {
        .uname = "STRM_ST",
        .udesc = "Request: number of streaming store requests",
        .ucode = 1ULL << (11 + 8),
        .grpid = 0,
    },
    {
        .uname = "OTHER",
        .udesc = "Request: counts one of the following transaction types, including L3 "
                 "invalidate, I/O, full or partial writes, WC or non-temporal stores, "
                 "CLFLUSH, Fences, lock, unlock, split lock",
        .ucode = 1ULL << (15 + 8),
        .grpid = 0,
    },
    {
        .uname = "ANY_IFETCH",
        .udesc = "Request: combination of PF_IFETCH | DMND_IFETCH | PF_LLC_IFETCH",
        .uequiv = "PF_IFETCH:DMND_IFETCH:PF_LLC_IFETCH",
        .ucode = 0x24400,
        .grpid = 0,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Request: combination of all request umasks",
        .uequiv = "DMND_DATA_RD:DMND_RFO:DMND_IFETCH:WB:PF_DATA_RD:PF_RFO:PF_IFETCH:PF_"
                  "LLC_DATA_RD:PF_LLC_RFO:PF_LLC_IFETCH:BUS_LOCKS:STRM_ST:OTHER",
        .ucode = 0x8fff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "ANY_DATA",
        .udesc = "Request: combination of DMND_DATA | PF_DATA_RD | PF_LLC_DATA_RD",
        .uequiv = "DMND_DATA_RD:PF_DATA_RD:PF_LLC_DATA_RD",
        .ucode = 0x9100,
        .grpid = 0,
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Request: combination of DMND_RFO | PF_RFO | PF_LLC_RFO",
        .uequiv = "DMND_RFO:PF_RFO:PF_LLC_RFO",
        .ucode = 0x12200,
        .grpid = 0,
    },

    {
        .uname = "ANY_RESPONSE",
        .udesc = "Response: count any response type",
        .ucode = 1ULL << (16 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_EXCL_GRP_GT,
        .grpid = 1,
    },
    {
        .uname = "NO_SUPP",
        .udesc = "Supplier: counts number of times supplier information is not available",
        .ucode = 1ULL << (17 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITM",
        .udesc = "Supplier: counts L3 hits in M-state (initial lookup)",
        .ucode = 1ULL << (18 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITE",
        .udesc = "Supplier: counts L3 hits in E-state",
        .ucode = 1ULL << (19 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITS",
        .udesc = "Supplier: counts L3 hits in S-state",
        .ucode = 1ULL << (20 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITF",
        .udesc = "Supplier: counts L3 hits in F-state",
        .ucode = 1ULL << (21 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_MISS_LOCAL",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 1ULL << (22 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_MISS_REMOTE",
        .udesc = "Supplier: counts L3 misses to remote DRAM",
        .ucode = 0xffULL << (23 + 8),
        .uequiv = "LLC_MISS_REMOTE_DRAM",
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 0x1ULL << (22 + 8),
        .grpid = 1,
        .uequiv = "LLC_MISS_LOCAL",
        .umodel = PFM_PMU_INTEL_IVB,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Supplier: counts L3 misses to local or remote DRAM",
        .ucode = 0x3ULL << (22 + 8),
        .uequiv = "LLC_MISS_LOCAL:LLC_MISS_REMOTE",
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .grpid = 1,
    },
    {
        .uname = "LLC_MISS_REMOTE_DRAM",
        .udesc = "Supplier: counts L3 misses to remote DRAM",
        .ucode = 0xffULL << (23 + 8),
        .umodel = PFM_PMU_INTEL_IVB_EP,
        .grpid = 1,
    },
    {
        .uname = "LLC_HITMESF",
        .udesc = "Supplier: counts L3 hits in any state (M, E, S, F)",
        .ucode = 0xfULL << (18 + 8),
        .uequiv = "LLC_HITM:LLC_HITE:LLC_HITS:LLC_HITF",
        .grpid = 1,
    },
    {
        .uname = "SNP_NONE",
        .udesc =
            "Snoop: counts number of times no snoop-related information is available",
        .ucode = 1ULL << (31 + 8),
        .grpid = 2,
    },
    {
        .uname = "SNP_NOT_NEEDED",
        .udesc = "Snoop: counts the number of times no snoop was needed to satisfy the "
                 "request",
        .ucode = 1ULL << (32 + 8),
        .grpid = 2,
    },
    {
        .uname = "SNP_MISS",
        .udesc = "Snoop: counts number of times a snoop was needed and it missed all "
                 "snooped caches",
        .ucode = 1ULL << (33 + 8),
        .grpid = 2,
    },
    {
        .uname = "SNP_NO_FWD",
        .udesc = "Snoop: counts number of times a snoop was needed and it hit in at leas "
                 "one snooped cache",
        .ucode = 1ULL << (34 + 8),
        .grpid = 2,
    },
    {
        .uname = "SNP_FWD",
        .udesc = "Snoop: counts number of times a snoop was needed and data was "
                 "forwarded from a remote socket",
        .ucode = 1ULL << (35 + 8),
        .grpid = 2,
    },
    {
        .uname = "HITM",
        .udesc = "Snoop: counts number of times a snoop was needed and it hitM-ed in "
                 "local or remote cache",
        .ucode = 1ULL << (36 + 8),
        .grpid = 2,
    },
    {
        .uname = "NON_DRAM",
        .udesc = "Snoop:  counts number of times target was a non-DRAM system address. "
                 "This includes MMIO transactions",
        .ucode = 1ULL << (37 + 8),
        .grpid = 2,
    },
    {
        .uname = "SNP_ANY",
        .udesc = "Snoop: any snoop reason",
        .ucode = 0x7fULL << (31 + 8),
        .uequiv = "SNP_NONE:SNP_NOT_NEEDED:SNP_MISS:SNP_NO_FWD:SNP_FWD:HITM:NON_DRAM",
        .uflags = INTEL_X86_DFL,
        .grpid = 2,
    },
};

static const intel_x86_umask_t ivb_baclears[] = {
    {
        .uname = "ANY",
        .udesc = "Counts the number of times the front end is re-steered, mainly when "
                 "the BPU cannot provide a correct prediction and this is corrected by "
                 "other branch handling mechanisms at the front end",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_cycle_activity[] = {
    {
        .uname = "CYCLES_L2_PENDING",
        .udesc = "Cycles with pending L2 miss loads",
        .ucode = 0x0100 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0xf,
    },
    {
        .uname = "CYCLES_LDM_PENDING",
        .udesc = "Cycles with pending memory loads",
        .ucode = 0x0200 | (0x2 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
        .ucntmsk = 0xf,
    },
    {
        .uname = "CYCLES_L1D_PENDING",
        .udesc = "Cycles with pending L1D load cache misses",
        .ucode = 0x0800 | (0x8 << INTEL_X86_CMASK_BIT),
        .ucntmsk = 0x4,
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES_NO_EXECUTE",
        .udesc = "Cycles of dispatch stalls",
        .ucode = 0x0400 | (0x4 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_L2_PENDING",
        .udesc = "Execution stalls due to L2 pending loads",
        .ucode = 0x0500 | (0x5 << INTEL_X86_CMASK_BIT),
        .ucntmsk = 0xf,
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_L1D_PENDING",
        .udesc = "Execution stalls due to L1D pending loads",
        .ucode = 0x0c00 | (0xc << INTEL_X86_CMASK_BIT),
        .ucntmsk = 0x4,
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_LDM_PENDING",
        .udesc = "Execution stalls due to memory loads",
        .ucode = 0x0600 | (0x6 << INTEL_X86_CMASK_BIT),
        .ucntmsk = 0xf,
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_fp_comp_ops_exe[] = {
    {
        .uname = "X87",
        .udesc = "Number of X87 uops executed",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_FP_PACKED_DOUBLE",
        .udesc = "Number of SSE or AVX-128 double precision FP packed uops executed",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_FP_SCALAR_SINGLE",
        .udesc = "Number of SSE or AVX-128 single precision FP scalar uops executed",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_PACKED_SINGLE",
        .udesc = "Number of SSE or AVX-128 single precision FP packed uops executed",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_SCALAR_DOUBLE",
        .udesc = "Number of SSE or AVX-128 double precision FP scalar uops executed",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_simd_fp_256[] = {
    {
        .uname = "PACKED_SINGLE",
        .udesc = "Counts 256-bit packed single-precision",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_DOUBLE",
        .udesc = "Counts 256-bit packed double-precision",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t ivb_lsd[] = {
    {
        .uname = "UOPS",
        .udesc = "Number of uops delivered by the Loop Stream Detector (LSD)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ACTIVE",
        .udesc =
            "Cycles with uops delivered by the LSD but which did not come from decoder",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "UOPS:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_4_UOPS",
        .udesc =
            "Cycles with 4 uops delivered by the LSD but which did not come from decoder",
        .ucode = 0x100 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uequiv = "UOPS:c=4",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_int_misc[] = {
    {
        .uname = "RECOVERY_CYCLES",
        .udesc =
            "Cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be "
            "recovered after Nuke due to all other cases except JEClear (e.g. whenever a "
            "ucode assist is needed like SSE exception, memory disambiguation, etc...)",
        .ucode = 0x300 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "RECOVERY_CYCLES_ANY",
        .udesc = "Core cycles the allocator was stalled due to recovery from earlier "
                 "clear event for any thread running on the physical core (e.g. "
                 "misprediction or memory nuke)",
        .ucode = 0x300 | (1 << INTEL_X86_CMASK_BIT) | INTEL_X86_MOD_ANY, /* cnt=1 any=1 */
        .uequiv = "RECOVERY_CYCLES:t",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_T,
    },
    {
        .uname = "RECOVERY_STALLS_COUNT",
        .udesc = "Number of occurrences waiting for Machine Clears",
        .ucode =
            0x300 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t ivb_ept[] = {
    {
        .uname = "WALK_CYCLES",
        .udesc = "Cycles for an extended page table walk",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_page_walks[] = {
    {
        .uname = "LLC_MISS",
        .udesc = "Number of page walks with a LLC miss",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_offcore_requests_buffer[] = {
    {
        .uname = "SQ_FULL",
        .udesc = "Number of cycles the offcore requests buffer is full",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t ivb_sq_misc[] = {
    {
        .uname = "SPLIT_LOCK",
        .udesc = "Number of split locks in the super queue (SQ)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_entry_t intel_ivb_pe[] = {
    {
        .name = "ARITH",
        .desc = "Counts arithmetic multiply operations",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x14,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_arith),
        .ngrp = 1,
        .umasks = ivb_arith,
    },
    {
        .name = "BACLEARS",
        .desc = "Branch re-steered",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xe6,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_baclears),
        .ngrp = 1,
        .umasks = ivb_baclears,
    },
    {
        .name = "BR_INST_EXEC",
        .desc = "Branch instructions executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x88,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_br_inst_exec),
        .ngrp = 1,
        .umasks = ivb_br_inst_exec,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc4,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_br_inst_retired),
        .ngrp = 1,
        .umasks = ivb_br_inst_retired,
    },
    {
        .name = "BR_MISP_EXEC",
        .desc = "Mispredicted branches executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x89,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_br_misp_exec),
        .ngrp = 1,
        .umasks = ivb_br_misp_exec,
    },
    {
        .name = "BR_MISP_RETIRED",
        .desc = "Mispredicted retired branches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_br_misp_retired),
        .ngrp = 1,
        .umasks = ivb_br_misp_retired,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Count branch instructions at retirement. Specifically, this event "
                "counts the retirement of the last micro-op of a branch instruction",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "BR_INST_RETIRED:ALL_BRANCHES",
        .cntmsk = 0xff,
        .code = 0xc4,
    },
    {
        .name = "MISPREDICTED_BRANCH_RETIRED",
        .desc = "Count mispredicted branch instructions at retirement. Specifically, "
                "this event counts at retirement of the last micro-op of a branch "
                "instruction in the architectural path of the execution and experienced "
                "misprediction in the branch prediction hardware",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "BR_MISP_RETIRED:ALL_BRANCHES",
        .cntmsk = 0xff,
        .code = 0xc5,
    },
    {
        .name = "LOCK_CYCLES",
        .desc = "Locked cycles in L1D and L2",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x63,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_lock_cycles),
        .ngrp = 1,
        .umasks = ivb_lock_cycles,
    },
    {
        .name = "CPL_CYCLES",
        .desc = "Unhalted core cycles at a specific ring level",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x5c,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_cpl_cycles),
        .ngrp = 1,
        .umasks = ivb_cpl_cycles,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Cycles when processor is not in halted state",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x3c,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_cpu_clk_unhalted),
        .ngrp = 1,
        .umasks = ivb_cpu_clk_unhalted,
    },
    {
        .name = "DSB2MITE_SWITCHES",
        .desc = "Number of DSB to MITE switches",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xab,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_dsb2mite_switches),
        .ngrp = 1,
        .umasks = ivb_dsb2mite_switches,
    },
    {
        .name = "DSB_FILL",
        .desc = "DSB fills",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xac,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_dsb_fill),
        .ngrp = 1,
        .umasks = ivb_dsb_fill,
    },
    {
        .name = "DTLB_LOAD_MISSES",
        .desc = "Data TLB load misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x8,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_dtlb_load_misses),
        .ngrp = 1,
        .umasks = ivb_dtlb_load_misses,
    },
    {
        .name = "DTLB_STORE_MISSES",
        .desc = "Data TLB store misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x49,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_dtlb_store_misses),
        .ngrp = 1,
        .umasks = ivb_dtlb_store_misses,
    },
    {
        .name = "FP_ASSIST",
        .desc = "X87 Floating point assists",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xca,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_fp_assist),
        .ngrp = 1,
        .umasks = ivb_fp_assist,
    },
    {
        .name = "ICACHE",
        .desc = "Instruction Cache accesses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x80,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_icache),
        .ngrp = 1,
        .umasks = ivb_icache,
    },
    {
        .name = "IDQ",
        .desc = "IDQ operations",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x79,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_idq),
        .ngrp = 1,
        .umasks = ivb_idq,
    },
    {
        .name = "IDQ_UOPS_NOT_DELIVERED",
        .desc = "Uops not delivered",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x9c,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_idq_uops_not_delivered),
        .ngrp = 1,
        .umasks = ivb_idq_uops_not_delivered,
    },
    {
        .name = "ILD_STALL",
        .desc = "Instruction Length Decoder stalls",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x87,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_ild_stall),
        .ngrp = 1,
        .umasks = ivb_ild_stall,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_inst_retired),
        .ngrp = 1,
        .umasks = ivb_inst_retired,
    },
    {
        .name = "INSTRUCTION_RETIRED",
        .desc = "Number of instructions at retirement",
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
        .name = "ITLB",
        .desc = "Instruction TLB",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xae,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_itlb),
        .ngrp = 1,
        .umasks = ivb_itlb,
    },
    {
        .name = "ITLB_MISSES",
        .desc = "Instruction TLB misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x85,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_itlb_misses),
        .ngrp = 1,
        .umasks = ivb_itlb_misses,
    },
    {
        .name = "L1D",
        .desc = "L1D cache",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x51,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l1d),
        .ngrp = 1,
        .umasks = ivb_l1d,
    },
    {
        .name = "MOVE_ELIMINATION",
        .desc = "Move Elimination",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x58,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_move_elimination),
        .ngrp = 1,
        .umasks = ivb_move_elimination,
    },
    {
        .name = "L1D_PEND_MISS",
        .desc = "L1D pending misses",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x4,
        .code = 0x48,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l1d_pend_miss),
        .ngrp = 1,
        .umasks = ivb_l1d_pend_miss,
    },
    {
        .name = "L2_L1D_WB_RQSTS",
        .desc = "Writeback requests from L1D to L2",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x28,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_l1d_wb_rqsts),
        .ngrp = 1,
        .umasks = ivb_l2_l1d_wb_rqsts,
    },
    {
        .name = "L2_LINES_IN",
        .desc = "L2 lines allocated",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xf1,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_lines_in),
        .ngrp = 1,
        .umasks = ivb_l2_lines_in,
    },
    {
        .name = "L2_LINES_OUT",
        .desc = "L2 lines evicted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xf2,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_lines_out),
        .ngrp = 1,
        .umasks = ivb_l2_lines_out,
    },
    {
        .name = "L2_RQSTS",
        .desc = "L2 requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_rqsts),
        .ngrp = 1,
        .umasks = ivb_l2_rqsts,
    },
    {
        .name = "L2_STORE_LOCK_RQSTS",
        .desc = "L2 store lock requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x27,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_store_lock_rqsts),
        .ngrp = 1,
        .umasks = ivb_l2_store_lock_rqsts,
    },
    {
        .name = "L2_TRANS",
        .desc = "L2 transactions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xf0,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l2_trans),
        .ngrp = 1,
        .umasks = ivb_l2_trans,
    },
    {
        .name = "LAST_LEVEL_CACHE_MISSES",
        .desc = "This is an alias for L3_LAT_CACHE:MISS",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "L3_LAT_CACHE:MISS",
        .cntmsk = 0xff,
        .code = 0x412e,
    },
    {
        .name = "LLC_MISSES",
        .desc = "Alias for LAST_LEVEL_CACHE_MISSES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LAST_LEVEL_CACHE_MISSES",
        .cntmsk = 0xff,
        .code = 0x412e,
    },
    {
        .name = "LAST_LEVEL_CACHE_REFERENCES",
        .desc = "This is an alias for L3_LAT_CACHE:REFERENCE",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "L3_LAT_CACHE:REFERENCE",
        .cntmsk = 0xff,
        .code = 0x4f2e,
    },
    {
        .name = "LLC_REFERENCES",
        .desc = "Alias for LAST_LEVEL_CACHE_REFERENCES",
        .modmsk = INTEL_V3_ATTRS,
        .equiv = "LAST_LEVEL_CACHE_REFERENCES",
        .cntmsk = 0xff,
        .code = 0x4f2e,
    },
    {
        .name = "LD_BLOCKS",
        .desc = "Blocking loads",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x3,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_ld_blocks),
        .ngrp = 1,
        .umasks = ivb_ld_blocks,
    },
    {
        .name = "LD_BLOCKS_PARTIAL",
        .desc = "Partial load blocks",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x7,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_ld_blocks_partial),
        .ngrp = 1,
        .umasks = ivb_ld_blocks_partial,
    },
    {
        .name = "LOAD_HIT_PRE",
        .desc = "Load dispatches that hit fill buffer",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x4c,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_load_hit_pre),
        .ngrp = 1,
        .umasks = ivb_load_hit_pre,
    },
    {
        .name = "L3_LAT_CACHE",
        .desc = "Core-originated cacheable demand requests to L3",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l3_lat_cache),
        .ngrp = 1,
        .umasks = ivb_l3_lat_cache,
    },
    {
        .name = "LONGEST_LAT_CACHE",
        .desc = "Core-originated cacheable demand requests to L3",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_l3_lat_cache),
        .ngrp = 1,
        .equiv = "L3_LAT_CACHE",
        .umasks = ivb_l3_lat_cache,
    },
    {
        .name = "MACHINE_CLEARS",
        .desc = "Machine clear asserted",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc3,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_machine_clears),
        .ngrp = 1,
        .umasks = ivb_machine_clears,
    },
    {
        .name = "MEM_LOAD_UOPS_LLC_HIT_RETIRED",
        .desc = "L3 hit loads uops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd2,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_load_uops_llc_hit_retired),
        .ngrp = 1,
        .umasks = ivb_mem_load_uops_llc_hit_retired,
    },
    {
        .name = "MEM_LOAD_LLC_HIT_RETIRED",
        .desc =
            "L3 hit loads uops retired (deprecated use MEM_LOAD_UOPS_LLC_HIT_RETIRED)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd2,
        .equiv = "MEM_LOAD_UOPS_LLC_HIT_RETIRED",
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_load_uops_llc_hit_retired),
        .ngrp = 1,
        .umasks = ivb_mem_load_uops_llc_hit_retired,
    },
    {
        .name = "MEM_LOAD_UOPS_LLC_MISS_RETIRED",
        .desc = "Load uops retired that missed the LLC",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd3,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_load_uops_llc_miss_retired),
        .ngrp = 1,
        .umasks = ivb_mem_load_uops_llc_miss_retired,
    },
    {
        .name = "MEM_LOAD_UOPS_RETIRED",
        .desc = "Memory loads uops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd1,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_load_uops_retired),
        .ngrp = 1,
        .umasks = ivb_mem_load_uops_retired,
    },
    {
        .name = "MEM_LOAD_RETIRED",
        .desc = "Memory loads uops retired (deprecated use MEM_LOAD_UOPS_RETIRED)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd1,
        .equiv = "MEM_LOAD_UOPS_RETIRED",
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_load_uops_retired),
        .ngrp = 1,
        .umasks = ivb_mem_load_uops_retired,
    },
    {
        .name = "MEM_TRANS_RETIRED",
        .desc = "Memory transactions retired",
        .modmsk = INTEL_V3_ATTRS | _INTEL_X86_ATTR_LDLAT,
        .cntmsk = 0x8,
        .code = 0xcd,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_trans_retired),
        .ngrp = 1,
        .umasks = ivb_mem_trans_retired,
    },
    {
        .name = "MEM_UOPS_RETIRED",
        .desc = "Memory uops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_uops_retired),
        .ngrp = 1,
        .umasks = ivb_mem_uops_retired,
    },
    {
        .name = "MEM_UOP_RETIRED",
        .desc = "Memory uops retired (deprecated use MEM_UOPS_RETIRED)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xd0,
        .equiv = "MEM_UOPS_RETIRED",
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_mem_uops_retired),
        .ngrp = 1,
        .umasks = ivb_mem_uops_retired,
    },

    {
        .name = "MISALIGN_MEM_REF",
        .desc = "Misaligned memory references",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x5,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_misalign_mem_ref),
        .ngrp = 1,
        .umasks = ivb_misalign_mem_ref,
    },
    {
        .name = "OFFCORE_REQUESTS",
        .desc = "Offcore requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xb0,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_offcore_requests),
        .ngrp = 1,
        .umasks = ivb_offcore_requests,
    },
    {
        .name = "OFFCORE_REQUESTS_OUTSTANDING",
        .desc = "Outstanding offcore requests",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x60,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_offcore_requests_outstanding),
        .ngrp = 1,
        .umasks = ivb_offcore_requests_outstanding,
    },
    {
        .name = "OTHER_ASSISTS",
        .desc = "Count hardware assists",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc1,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_other_assists),
        .ngrp = 1,
        .umasks = ivb_other_assists,
    },
    {
        .name = "RESOURCE_STALLS",
        .desc = "Resource related stall cycles",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xa2,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_resource_stalls),
        .ngrp = 1,
        .umasks = ivb_resource_stalls,
    },
    {
        .name = "CYCLE_ACTIVITY",
        .desc = "Stalled cycles",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xa3,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_cycle_activity),
        .ngrp = 1,
        .umasks = ivb_cycle_activity,
    },
    {
        .name = "ROB_MISC_EVENTS",
        .desc = "Reorder buffer events",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xcc,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_rob_misc_events),
        .ngrp = 1,
        .umasks = ivb_rob_misc_events,
    },
    {
        .name = "RS_EVENTS",
        .desc = "Reservation station events",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x5e,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_rs_events),
        .ngrp = 1,
        .umasks = ivb_rs_events,
    },
    {
        .name = "DTLB_LOAD_ACCESS",
        .desc = "TLB access",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x5f,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_tlb_access),
        .ngrp = 1,
        .umasks = ivb_tlb_access,
    },
    {
        .name = "TLB_ACCESS",
        .desc = "TLB access",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x5f,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_tlb_access),
        .ngrp = 1,
        .equiv = "DTLB_LOAD_ACCESS",
        .umasks = ivb_tlb_access,
    },
    {
        .name = "TLB_FLUSH",
        .desc = "TLB flushes",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xbd,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_tlb_flush),
        .ngrp = 1,
        .umasks = ivb_tlb_flush,
    },
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Count core clock cycles whenever the clock signal on the specific core "
                "is running (not halted)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0x20000000full,
        .code = 0x3c,
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
        .name = "UOPS_EXECUTED",
        .desc = "Uops executed",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xb1,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_uops_executed),
        .ngrp = 1,
        .umasks = ivb_uops_executed,
    },
    {
        .name = "UOPS_DISPATCHED_PORT",
        .desc = "Uops dispatch to specific ports",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xa1,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_uops_dispatched_port),
        .ngrp = 1,
        .umasks = ivb_uops_dispatched_port,
    },
    {
        .name = "UOPS_ISSUED",
        .desc = "Uops issued",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xe,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_uops_issued),
        .ngrp = 1,
        .umasks = ivb_uops_issued,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Uops retired",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xc2,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_uops_retired),
        .ngrp = 1,
        .umasks = ivb_uops_retired,
    },
    {
        .name = "FP_COMP_OPS_EXE",
        .desc = "Counts number of floating point events",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x10,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_fp_comp_ops_exe),
        .ngrp = 1,
        .umasks = ivb_fp_comp_ops_exe,
    },
    {
        .name = "SIMD_FP_256",
        .desc = "Counts 256-bit packed floating point instructions",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x11,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_simd_fp_256),
        .ngrp = 1,
        .umasks = ivb_simd_fp_256,
    },
    {
        .name = "LSD",
        .desc = "Loop stream detector",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xa8,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_lsd),
        .ngrp = 1,
        .umasks = ivb_lsd,
    },
    {
        .name = "EPT",
        .desc = "Extended page table",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0x4f,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_ept),
        .ngrp = 1,
        .umasks = ivb_ept,
    },
    {
        .name = "PAGE_WALKS",
        .desc = "page walker",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xbe,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_page_walks),
        .ngrp = 1,
        .umasks = ivb_page_walks,
    },
    {.name = "INT_MISC",
     .desc = "Miscellaneous interruptions",
     .code = 0xd,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V3_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivb_int_misc),
     .umasks = ivb_int_misc},
    {
        .name = "OFFCORE_REQUESTS_BUFFER",
        .desc = "Offcore reqest buffer",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xff,
        .code = 0xb2,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_offcore_requests_buffer),
        .ngrp = 1,
        .umasks = ivb_offcore_requests_buffer,
    },
    {
        .name = "SQ_MISC",
        .desc = "SuperQueue miscellaneous",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf4,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_sq_misc),
        .ngrp = 1,
        .umasks = ivb_sq_misc,
    },
    {
        .name = "OFFCORE_RESPONSE_0",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1b7,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_offcore_response),
        .ngrp = 3,
        .umasks = ivb_offcore_response,
    },
    {
        .name = "OFFCORE_RESPONSE_1",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V3_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1bb,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(ivb_offcore_response),
        .ngrp = 3,
        .umasks =
            ivb_offcore_response, /* identical to actual umasks list for this event */
    },
};
