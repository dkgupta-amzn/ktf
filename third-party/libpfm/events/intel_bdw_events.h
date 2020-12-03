/*
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
 * PMU: bdw (Intel Broadwell)
 */

static const intel_x86_umask_t bdw_baclears[] = {
    {
        .uname = "ANY",
        .udesc = "Number of front-end re-steers due to BPU misprediction",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_br_inst_exec[] = {
    {
        .uname = "NONTAKEN_CONDITIONAL",
        .udesc = "All macro conditional nontaken branch instructions",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NONTAKEN_COND",
        .udesc = "All macro conditional nontaken branch instructions",
        .ucode = 0x4100,
        .uequiv = "NONTAKEN_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },

    {
        .uname = "TAKEN_CONDITIONAL",
        .udesc = "Taken speculative and retired macro-conditional branches",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_COND",
        .udesc = "Taken speculative and retired macro-conditional branches",
        .ucode = 0x8100,
        .uequiv = "TAKEN_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_DIRECT_JUMP",
        .udesc = "Taken speculative and retired macro-conditional branch instructions "
                 "excluding calls and indirects",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .udesc =
            "Taken speculative and retired indirect branches excluding calls and returns",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_NEAR_RETURN",
        .udesc = "Taken speculative and retired indirect branches with return mnemonic",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_DIRECT_NEAR_CALL",
        .udesc = "Taken speculative and retired direct near calls",
        .ucode = 0x9000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_CONDITIONAL",
        .udesc = "Speculative and retired macro-conditional branches",
        .ucode = 0xc100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_COND",
        .udesc = "Speculative and retired macro-conditional branches",
        .ucode = 0xc100,
        .uequiv = "ALL_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_COND",
        .udesc = "Speculative and retired macro-conditional branches",
        .ucode = 0xc100,
        .uequiv = "ALL_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DIRECT_JMP",
        .udesc = "Speculative and retired macro-unconditional branches excluding calls "
                 "and indirects",
        .ucode = 0xc200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "Speculative and retired indirect branches excluding calls and returns",
        .ucode = 0xc400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_INDIRECT_NEAR_RETURN",
        .udesc = "Speculative and retired indirect return branches",
        .ucode = 0xc800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DIRECT_NEAR_CALL",
        .udesc = "Speculative and retired direct near calls",
        .ucode = 0xd000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_NEAR_CALL",
        .udesc = "All indirect calls, including both register and memory indirect",
        .ucode = 0xa000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All branch instructions executed",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_br_inst_retired[] = {
    {
        .uname = "CONDITIONAL",
        .udesc = "Counts all taken and not taken macro conditional branch instructions",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "COND",
        .udesc = "Counts all taken and not taken macro conditional branch instructions",
        .ucode = 0x100,
        .uequiv = "CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_CALL",
        .udesc = "Counts all macro direct and indirect near calls",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Counts all taken and not taken macro branches including far branches "
                 "(architectural event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_RETURN",
        .udesc = "Counts the number of near ret instructions retired",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NOT_TAKEN",
        .udesc = "Counts all not taken macro branch instructions retired",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NEAR_TAKEN",
        .udesc = "Counts the number of near branch taken instructions retired",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "FAR_BRANCH",
        .udesc = "Counts the number of far branch instructions retired",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_br_misp_exec[] = {
    {
        .uname = "NONTAKEN_CONDITIONAL",
        .udesc =
            "Not taken speculative and retired mispredicted macro conditional branches",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NONTAKEN_COND",
        .udesc =
            "Not taken speculative and retired mispredicted macro conditional branches",
        .ucode = 0x4100,
        .uequiv = "NONTAKEN_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_CONDITIONAL",
        .udesc = "Taken speculative and retired mispredicted macro conditional branches",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_COND",
        .udesc = "Taken speculative and retired mispredicted macro conditional branches",
        .ucode = 0x8100,
        .uequiv = "TAKEN_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "Taken speculative and retired mispredicted indirect branches excluding "
                 "calls and returns",
        .ucode = 0x8400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_CONDITIONAL",
        .udesc = "Speculative and retired mispredicted macro conditional branches",
        .ucode = 0xc100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_COND",
        .udesc = "Speculative and retired mispredicted macro conditional branches",
        .ucode = 0xc100,
        .uequiv = "ALL_CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_INDIRECT_JUMP_NON_CALL_RET",
        .udesc = "All mispredicted indirect branches that are not calls nor returns",
        .ucode = 0xc400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Speculative and retired mispredicted macro conditional branches",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "TAKEN_INDIRECT_NEAR_CALL",
        .udesc = "Taken speculative and retired mispredicted indirect calls",
        .ucode = 0xa000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "TAKEN_RETURN_NEAR",
        .udesc = "Taken speculative and retired mispredicted direct returns",
        .ucode = 0x8800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_br_misp_retired[] = {
    {
        .uname = "CONDITIONAL",
        .udesc = "All mispredicted macro conditional branch instructions",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "COND",
        .udesc = "All mispredicted macro conditional branch instructions",
        .ucode = 0x100,
        .uequiv = "CONDITIONAL",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All mispredicted macro branches (architectural event)",
        .ucode = 0x0, /* architectural encoding */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "NEAR_TAKEN",
        .udesc =
            "Number of near branch instructions retired that were mispredicted and taken",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "RET",
        .udesc = "Number of mispredicted ret instructions retired",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_cpl_cycles[] = {
    {
        .uname = "RING0",
        .udesc = "Unhalted core cycles when the thread is in ring 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RING123",
        .udesc = "Unhalted core cycles when thread is in rings 1, 2, or 3",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RING0_TRANS",
        .udesc = "Number of intervals between processor halts while thread is in ring 0",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t bdw_cpu_clk_thread_unhalted[] = {
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
        .uname = "REF_P",
        .udesc = "Cycles when the core is unhalted (count at 100 Mhz)",
        .ucode = 0x100,
        .uequiv = "REF_XCLK",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "THREAD_P",
        .udesc = "Cycles when thread is not halted",
        .ucode = 0x000,
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

static const intel_x86_umask_t bdw_cycle_activity[] = {
    {
        .uname = "CYCLES_L2_PENDING",
        .udesc = "Cycles with pending L2 miss loads (must use with HT off only)",
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
        .uequiv = "CYCLES_MEM_ANY",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES_MEM_ANY",
        .udesc = "Cycles with pending memory loads",
        .ucode = 0x0200 | (0x2 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES_L1D_PENDING",
        .udesc = "Cycles with pending L1D load cache misses",
        .ucode = 0x0800 | (0x8 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_LDM_PENDING",
        .udesc =
            "Executions stalls when there is at least one pending demand load request",
        .ucode = 0x0600 | (0x6 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_L1D_PENDING",
        .udesc =
            "Executions stalls while there is at least one L1D demand load outstanding",
        .ucode = 0x0c00 | (0xc << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_L2_PENDING",
        .udesc = "Execution stalls while there is at least one L2 demand load pending "
                 "outstanding",
        .ucode = 0x0500 | (0x5 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALLS_TOTAL",
        .udesc = "Cycles during which no instructions were executed in the execution "
                 "stage of the pipeline",
        .ucode = 0x0400 | (0x4 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES_NO_EXECUTE",
        .udesc = "Cycles during which no instructions were executed in the execution "
                 "stage of the pipeline",
        .ucode = 0x0400 | (0x4 << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_C,
        .uequiv = "STALLS_TOTAL",
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_dtlb_load_misses[] = {
    {
        .uname = "MISS_CAUSES_A_WALK",
        .udesc = "Misses in all DTLB levels that cause page walks",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_4K",
        .udesc = "Misses in all TLB levels causes a page walk that completes (4K)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_2M_4M",
        .udesc = "Misses in all TLB levels causes a page walk of 2MB/4MB page sizes that "
                 "completes",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_1G",
        .udesc = "Misses in all TLB levels causes a page walk of 1GB page sizes that "
                 "completes",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc =
            "Misses in all TLB levels causes a page walk of any page size that completes",
        .ucode = 0xe00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_DURATION",
        .udesc = "Cycles when PMH is busy with page walks",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT_4K",
        .udesc = "Misses that miss the DTLB and hit the STLB (4KB)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT_2M",
        .udesc = "Misses that miss the DTLB and hit the STLB (2MB)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "Number of cache load STLB hits. No page walk",
        .ucode = 0x6000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_itlb_misses[] = {
    {
        .uname = "MISS_CAUSES_A_WALK",
        .udesc = "Misses in all DTLB levels that cause page walks",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_4K",
        .udesc = "Misses in all TLB levels causes a page walk that completes (4KB)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_2M_4M",
        .udesc = "Misses in all TLB levels causes a page walk that completes (2MB/4MB)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED_1G",
        .udesc = "Misses in all TLB levels causes a page walk that completes (1GB)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_COMPLETED",
        .udesc =
            "Misses in all TLB levels causes a page walk of any page size that completes",
        .ucode = 0xe00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "WALK_DURATION",
        .udesc = "Cycles when PMH is busy with page walks",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT_4K",
        .udesc = "Misses that miss the DTLB and hit the STLB (4KB)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT_2M",
        .udesc = "Misses that miss the DTLB and hit the STLB (2MB)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_HIT",
        .udesc = "Number of cache load STLB hits. No page walk",
        .ucode = 0x6000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_fp_assist[] = {
    {
        .uname = "X87_OUTPUT",
        .udesc = "Number of X87 FP assists due to output values",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "X87_INPUT",
        .udesc = "Number of X87 FP assists due to input values",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_OUTPUT",
        .udesc = "Number of SIMD FP assists due to output values",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_INPUT",
        .udesc = "Number of SIMD FP assists due to input values",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "Cycles with any input/output SEE or FP assists",
        .ucode = 0x1e00 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL",
        .udesc = "Cycles with any input and output SSE or FP assist",
        .ucode = 0x1e00 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "ANY",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t bdw_icache[] = {
    {
        .uname = "MISSES",
        .udesc = "Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. "
                 "Includes Uncacheable accesses",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "IFDATA_STALL",
        .udesc = "Number of cycles where a code fetch is stalled due to L1 miss",
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

static const intel_x86_umask_t bdw_idq[] = {
    {
        .uname = "EMPTY",
        .udesc = "Cycles the Instruction Decode Queue (IDQ) is empty",
        .ucode = 0x200,
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MITE_UOPS",
        .udesc =
            "Number of uops delivered to Instruction Decode Queue (IDQ) from MITE path",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DSB_UOPS",
        .udesc = "Number of uops delivered to Instruction Decode Queue (IDQ) from Decode "
                 "Stream Buffer (DSB) path",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_DSB_UOPS",
        .udesc =
            "Uops initiated by Decode Stream Buffer (DSB) that are being delivered to "
            "Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_MITE_UOPS",
        .udesc = "Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) "
                 "while Microcode Sequencer (MS) is busy",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_UOPS",
        .udesc = "Number of Uops were delivered into Instruction Decode Queue (IDQ) from "
                 "MS, initiated by Decode Stream Buffer (DSB) or MITE",
        .ucode = 0x3000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MS_UOPS_CYCLES",
        .udesc =
            "Number of cycles that Uops were delivered into Instruction Decode Queue "
            "(IDQ) when MS_Busy, initiated by Decode Stream Buffer (DSB) or MITE",
        .ucode = 0x3000 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "MS_UOPS:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
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
        .uname = "MITE_UOPS_CYCLES",
        .udesc = "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) "
                 "from MITE path",
        .ucode = 0x400 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "MITE_UOPS:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "DSB_UOPS_CYCLES",
        .udesc = "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) "
                 "from Decode Stream Buffer (DSB) path",
        .ucode = 0x800 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "DSB_UOPS:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "MS_DSB_UOPS_CYCLES",
        .udesc = "Cycles when uops initiated by Decode Stream Buffer (DSB) are being "
                 "delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer "
                 "(MS) is busy",
        .ucode = 0x1000 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "MS_DSB_UOPS:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "MS_DSB_OCCUR",
        .udesc = "Deliveries to Instruction Decode Queue (IDQ) initiated by Decode "
                 "Stream Buffer (DSB) while Microcode Sequencer (MS) is busy",
        .ucode =
            0x1000 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uequiv = "MS_DSB_UOPS:c=1:e=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_DSB_CYCLES_4_UOPS",
        .udesc = "Cycles Decode Stream Buffer (DSB) is delivering 4 Uops",
        .ucode = 0x1800 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_DSB_CYCLES_ANY_UOPS",
        .udesc = "Cycles Decode Stream Buffer (DSB) is delivering any Uop",
        .ucode = 0x1800 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_MITE_CYCLES_4_UOPS",
        .udesc = "Cycles MITE is delivering 4 Uops",
        .ucode = 0x2400 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_MITE_CYCLES_ANY_UOPS",
        .udesc = "Cycles MITE is delivering any Uop",
        .ucode = 0x2400 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "ALL_MITE_UOPS",
        .udesc =
            "Number of uops delivered to Instruction Decode Queue (IDQ) from any path",
        .ucode = 0x3c00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_idq_uops_not_delivered[] = {
    {
        .uname = "CORE",
        .udesc = "Count number of non-delivered uops to Resource Allocation Table (RAT)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
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

static const intel_x86_umask_t bdw_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Number of instructions retired. General Counter - architectural event",
        .ucode = 0x000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL",
        .udesc = "Precise instruction retired event with HW to reduce effect of PEBS "
                 "shadow in IP distribution (Precise Event)",
        .ucode = 0x100,
        .uequiv = "PREC_DIST",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "TOTAL_CYCLES",
        .udesc = "Number of cycles using always true condition",
        .ucode =
            0x100 | INTEL_X86_MOD_INV | (10 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=10 */
        .uequiv = "PREC_DIST:i=1:c=10",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "PREC_DIST",
        .udesc = "Precise instruction retired event with HW to reduce effect of PEBS "
                 "shadow in IP distribution (Precise event)",
        .ucode = 0x100,
        .ucntmsk = 0x2,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "X87",
        .udesc = "Number of FPU operations retired (instructions with no exceptions)",
        .ucode = 0x200,
        .ucntmsk = 0x2,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_int_misc[] = {
    {
        .uname = "RECOVERY_CYCLES",
        .udesc =
            "Cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be "
            "recovered after Nuke due to all other cases except JEClear (e.g. whenever a "
            "ucode assist is needed like SSE exception, memory disambiguation, etc...)",
        .ucode = 0x300 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uflags = INTEL_X86_NCOMBO,
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
    {
        .uname = "RAT_STALL_CYCLES",
        .udesc = "Cycles when the Resource Allocation Table (RAT) external stall event "
                 "is sent to the Instruction Decode Queue (IDQ) for the thread. Also "
                 "includes cycles when the allocator is serving another thread",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_itlb[] = {
    {
        .uname = "ITLB_FLUSH",
        .udesc = "Flushing of the Instruction TLB (ITLB) pages independent of page size",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_l1d[] = {
    {
        .uname = "REPLACEMENT",
        .udesc = "L1D Data line replacements",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_sq_misc[] = {
    {
        .uname = "SPLIT_LOCK",
        .udesc = "Number of split locks in the super queue (SQ)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_l1d_pend_miss[] = {
    {
        .uname = "PENDING",
        .udesc = "Cycles with L1D load misses outstanding",
        .ucode = 0x100,
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "PENDING_CYCLES",
        .udesc = "Cycles with L1D load misses outstanding",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "PENDING:c=1",
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "PENDING_CYCLES_ANY",
        .udesc = "Cycles with L1D load misses outstanding from any thread",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT) | INTEL_X86_MOD_ANY, /* cnt=1 any=1 */
        .uequiv = "PENDING:c=1:t",
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_T,
    },
    {
        .uname = "OCCURRENCES",
        .udesc = "Number L1D miss outstanding",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uequiv = "PENDING:c=1:e=1",
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "EDGE",
        .udesc = "Number L1D miss outstanding",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uequiv = "PENDING:c=1:e=1",
        .ucntmsk = 0x4,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
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

static const intel_x86_umask_t bdw_l2_demand_rqsts[] = {
    {
        .uname = "WB_HIT",
        .udesc = "WB requests that hit L2 cache",
        .ucode = 0x5000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_l2_lines_in[] = {
    {
        .uname = "I",
        .udesc = "L2 cache lines in I state filling L2",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "S",
        .udesc = "L2 cache lines in S state filling L2",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "E",
        .udesc = "L2 cache lines in E state filling L2",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL",
        .udesc = "L2 cache lines filling L2",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ANY",
        .udesc = "L2 cache lines filling L2",
        .uequiv = "ALL",
        .ucode = 0x700,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_l2_lines_out[] = {
    {
        .uname = "DEMAND_CLEAN",
        .udesc = "Number of clean L2 cachelines evicted by demand",
        .ucode = 0x500,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_l2_rqsts[] = {
    {
        .uname = "DEMAND_DATA_RD_MISS",
        .udesc = "Demand Data Read requests that miss L2 cache",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD_HIT",
        .udesc = "Demand Data Read requests that hit L2 cache",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO_MISS",
        .udesc = "RFO requests that miss L2 cache",
        .ucode = 0x2200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_MISS",
        .udesc = "RFO requests that miss L2 cache",
        .ucode = 0x2200,
        .uequiv = "DEMAND_RFO_MISS",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO_HIT",
        .udesc = "RFO requests that hit L2 cache",
        .ucode = 0x4200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO_HIT",
        .udesc = "RFO requests that hit L2 cache",
        .ucode = 0x4200,
        .uequiv = "DEMAND_RFO_HIT",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_RD_MISS",
        .udesc = "L2 cache misses when fetching instructions",
        .ucode = 0x2400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DEMAND_MISS",
        .udesc = "All demand requests that miss the L2 cache",
        .ucode = 0x2700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_RD_HIT",
        .udesc = "L2 cache hits when fetching instructions, code reads",
        .ucode = 0x4400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_PF_MISS",
        .udesc = "Requests from the L2 hardware prefetchers that miss L2 cache",
        .ucode = 0x3800,
        .uequiv = "PF_MISS",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_MISS",
        .udesc = "Requests from the L2 hardware prefetchers that miss L2 cache",
        .ucode = 0x3800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISS",
        .udesc = "All requests that miss the L2 cache",
        .ucode = 0x3f00,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_PF_HIT",
        .udesc = "Requests from the L2 hardware prefetchers that hit L2 cache",
        .ucode = 0xd800,
        .uequiv = "PF_HIT",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PF_HIT",
        .udesc = "Requests from the L2 hardware prefetchers that hit L2 cache",
        .ucode = 0xd800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DEMAND_DATA_RD",
        .udesc = "Any data read request to L2 cache",
        .ucode = 0xe100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_RFO",
        .udesc = "Any data RFO request to L2 cache",
        .ucode = 0xe200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_CODE_RD",
        .udesc = "Any code read request to L2 cache",
        .ucode = 0xe400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DEMAND_REFERENCES",
        .udesc = "All demand requests to L2 cache ",
        .ucode = 0xe700,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_PF",
        .udesc = "Any L2 HW prefetch request to L2 cache",
        .ucode = 0xf800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REFERENCES",
        .udesc = "All requests to L2 cache",
        .ucode = 0xff00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_l2_trans[] = {
    {
        .uname = "DEMAND_DATA_RD",
        .udesc = "Demand Data Read requests that access L2 cache",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RFO",
        .udesc = "RFO requests that access L2 cache",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CODE_RD",
        .udesc = "L2 cache accesses when fetching instructions",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_PF",
        .udesc = "L2 or L3 HW prefetches that access L2 cache, including rejects",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L1D_WB",
        .udesc = "L1D writebacks that access L2 cache",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_FILL",
        .udesc = "L2 fill requests that access L2 cache",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "L2_WB",
        .udesc = "L2 writebacks that access L2 cache",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_REQUESTS",
        .udesc = "Transactions accessing L2 pipe",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_ld_blocks[] = {
    {
        .uname = "STORE_FORWARD",
        .udesc = "Counts the number of loads blocked by overlapping with store buffer "
                 "entries that cannot be forwarded",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NO_SR",
        .udesc = "number of times that split load operations are temporarily blocked "
                 "because all resources for handling the split accesses are in use",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_ld_blocks_partial[] = {
    {
        .uname = "ADDRESS_ALIAS",
        .udesc = "False dependencies in MOB due to partial compare on address",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_load_hit_pre[] = {
    {
        .uname = "HW_PF",
        .udesc = "Non software-prefetch load dispatches that hit FB allocated for "
                 "hardware prefetch",
        .ucode = 0x200,
    },
    {
        .uname = "SW_PF",
        .udesc = "Non software-prefetch load dispatches that hit FB allocated for "
                 "software prefetch",
        .ucode = 0x100,
    },
};

static const intel_x86_umask_t bdw_lock_cycles[] = {
    {
        .uname = "SPLIT_LOCK_UC_LOCK_DURATION",
        .udesc =
            "Cycles in which the L1D and L2 are locked, due to a UC lock or split lock",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CACHE_LOCK_DURATION",
        .udesc = "cycles that the L1D is locked",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_longest_lat_cache[] = {
    {
        .uname = "MISS",
        .udesc =
            "Core-originated cacheable demand requests missed LLC - architectural event",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REFERENCE",
        .udesc = "Core-originated cacheable demand requests that refer to LLC - "
                 "architectural event",
        .ucode = 0x4f00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_machine_clears[] = {
    {
        .uname = "CYCLES",
        .udesc = "Cycles there was a Nuke. Account for both thread-specific and All "
                 "Thread Nukes",
        .ucode = 0x100,
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
        .udesc = "Number of Self-modifying code (SMC) Machine Clears detected",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MASKMOV",
        .udesc =
            "This event counts the number of executed Intel AVX masked load operations "
            "that refer to an illegal address range with the mask bits set to 0",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "COUNT",
        .udesc = "Number of machine clears (nukes) of any type",
        .ucode =
            0x100 | INTEL_X86_MOD_EDGE | (1 << INTEL_X86_CMASK_BIT), /* edge=1 cnt=1 */
        .uequiv = "CYCLES:c=1:e",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t bdw_mem_load_uops_l3_hit_retired[] = {
    {
        .uname = "XSNP_MISS",
        .udesc = "Retired load uops which data sources were L3 hit and cross-core snoop "
                 "missed in on-pkg core cache",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_HIT",
        .udesc = "Retired load uops which data sources were L3 and cross-core snoop hits "
                 "in on-pkg core cache",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_HITM",
        .udesc =
            "Load had HitM Response from a core on same socket (shared L3). (Non PEBS",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "XSNP_NONE",
        .udesc = "Retired load uops which data sources were hits in L3 without snoops "
                 "required",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_mem_load_uops_l3_miss_retired[] = {
    {
        .uname = "LOCAL_DRAM",
        .udesc =
            "Retired load uops missing L3 cache but hitting local memory (Precise Event)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_DRAM",
        .udesc =
            "Number of retired load uops that missed L3 but were service by remote RAM, "
            "snoop not needed, snoop miss, snoop hit data not forwarded (Precise Event)",
        .ucode = 0x400,
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_HITM",
        .udesc = "Number of retired load uops whose data sources was remote HITM "
                 "(Precise Event)",
        .ucode = 0x1000,
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REMOTE_FWD",
        .udesc = "Load uops that miss in the L3 whose data source was forwarded from a "
                 "remote cache (Precise Event)",
        .ucode = 0x2000,
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_mem_load_uops_retired[] = {
    {
        .uname = "L1_HIT",
        .udesc = "Retired load uops with L1 cache hits as data source",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Retired load uops with L2 cache hits as data source",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_HIT",
        .udesc = "Retired load uops with L3 cache hits as data source",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L1_MISS",
        .udesc = "Retired load uops which missed the L1D",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L2_MISS",
        .udesc = "Retired load uops which missed the L2. Unknown data source excluded",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Retired load uops which missed the L3",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "HIT_LFB",
        .udesc = "Retired load uops which missed L1 but hit line fill buffer (LFB)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_mem_trans_retired[] = {
    {
        .uname = "LOAD_LATENCY",
        .udesc = "Memory load instructions retired above programmed clocks, minimum "
                 "threshold value is 3 (Precise Event and ldlat required)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_LDLAT | INTEL_X86_DFL,
    },
    {
        .uname = "LATENCY_ABOVE_THRESHOLD",
        .udesc = "Memory load instructions retired above programmed clocks, minimum "
                 "threshold value is 3 (Precise Event and ldlat required)",
        .ucode = 0x100,
        .uequiv = "LOAD_LATENCY",
        .uflags =
            INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_LDLAT | INTEL_X86_NO_AUTOENCODE,
    },
};

static const intel_x86_umask_t bdw_mem_uops_retired[] = {
    {
        .uname = "STLB_MISS_LOADS",
        .udesc = "Load uops with true STLB miss retired to architected path",
        .ucode = 0x1100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STLB_MISS_STORES",
        .udesc = "Store uops with true STLB miss retired to architected path",
        .ucode = 0x1200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LOCK_LOADS",
        .udesc = "Load uops with locked access retired",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SPLIT_LOADS",
        .udesc = "Line-splitted load uops retired",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "SPLIT_STORES",
        .udesc = "Line-splitted store uops retired",
        .ucode = 0x4200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_LOADS",
        .udesc = "All load uops retired",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_STORES",
        .udesc = "All store uops retired",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t bdw_misalign_mem_ref[] = {
    {
        .uname = "LOADS",
        .udesc = "Speculative cache-line split load uops dispatched to the L1D",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STORES",
        .udesc = "Speculative cache-line split store-address uops dispatched to L1D",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_move_elimination[] = {
    {
        .uname = "INT_ELIMINATED",
        .udesc = "Number of integer Move Elimination candidate uops that were eliminated",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_ELIMINATED",
        .udesc = "Number of SIMD Move Elimination candidate uops that were eliminated",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "INT_NOT_ELIMINATED",
        .udesc =
            "Number of integer Move Elimination candidate uops that were not eliminated",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SIMD_NOT_ELIMINATED",
        .udesc =
            "Number of SIMD Move Elimination candidate uops that were not eliminated",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_offcore_requests[] = {
    {
        .uname = "DEMAND_DATA_RD",
        .udesc = "Demand data read requests sent to uncore (use with HT off only)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD",
        .udesc = "Demand code read requests sent to uncore (use with HT off only)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO",
        .udesc = "Demand RFOs requests sent to uncore (use with HT off only)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DATA_RD",
        .udesc = "Data read requests sent to uncore (use with HT off only)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_other_assists[] = {
    {
        .uname = "AVX_TO_SSE",
        .udesc =
            "Number of transitions from AVX-256 to legacy SSE when penalty applicable",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SSE_TO_AVX",
        .udesc =
            "Number of transitions from legacy SSE to AVX-256 when penalty applicable",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_WB_ASSIST",
        .udesc =
            "Number of times any microcode assist is invoked by HW upon uop writeback",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_resource_stalls[] = {
    {
        .uname = "ANY",
        .udesc = "Cycles Allocation is stalled due to Resource Related reason",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL",
        .udesc = "Cycles Allocation is stalled due to Resource Related reason",
        .ucode = 0x100,
        .uequiv = "ANY",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RS",
        .udesc = "Stall cycles caused by absence of eligible entries in Reservation "
                 "Station (RS)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SB",
        .udesc = "Cycles Allocator is stalled due to Store Buffer full (not including "
                 "draining from synch)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ROB",
        .udesc = "ROB full stall cycles",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_rob_misc_events[] = {
    {
        .uname = "LBR_INSERTS",
        .udesc = "Count each time an new Last Branch Record (LBR) is inserted",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_rs_events[] = {
    {
        .uname = "EMPTY_CYCLES",
        .udesc = "Cycles the Reservation Station (RS) is empty for this thread",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "EMPTY_END",
        .udesc = "Number of times the reservation station (RS) was empty",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT) |
                 INTEL_X86_MOD_EDGE, /* inv=1, cmask=1,edge=1 */
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_E,
    },
};

static const intel_x86_umask_t bdw_tlb_flush[] = {
    {
        .uname = "DTLB_THREAD",
        .udesc = "Count number of DTLB flushes of thread-specific entries",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STLB_ANY",
        .udesc = "Count number of any STLB flushes",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_uops_executed[] = {
    {
        .uname = "CORE",
        .udesc = "Number of uops executed from any thread",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "THREAD",
        .udesc = "Number of uops executed per thread each cycle",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL | INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Number of cycles with no uops executed",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=1 */
        .uequiv = "THREAD:c=1:i",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_1_UOP_EXEC",
        .udesc = "Cycles where at least 1 uop was executed per thread",
        .ucode = 0x100 | (1 << INTEL_X86_CMASK_BIT), /* cnt=1 */
        .uequiv = "THREAD:c=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_2_UOPS_EXEC",
        .udesc = "Cycles where at least 2 uops were executed per thread",
        .ucode = 0x100 | (2 << INTEL_X86_CMASK_BIT), /* cnt=2 */
        .uequiv = "THREAD:c=2",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_3_UOPS_EXEC",
        .udesc = "Cycles where at least 3 uops were executed per thread",
        .ucode = 0x100 | (3 << INTEL_X86_CMASK_BIT), /* cnt=3 */
        .uequiv = "THREAD:c=3",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CYCLES_GE_4_UOPS_EXEC",
        .udesc = "Cycles where at least 4 uops were executed per thread",
        .ucode = 0x100 | (4 << INTEL_X86_CMASK_BIT), /* cnt=4 */
        .uequiv = "THREAD:c=4",
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

static const intel_x86_umask_t bdw_uops_executed_port[] = {
    {
        .uname = "PORT_0",
        .udesc = "Cycles which a Uop is executed on port 0",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_1",
        .udesc = "Cycles which a Uop is executed on port 1",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_2",
        .udesc = "Cycles which a Uop is executed on port 2",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_3",
        .udesc = "Cycles which a Uop is executed on port 3",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_4",
        .udesc = "Cycles which a Uop is executed on port 4",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_5",
        .udesc = "Cycles which a Uop is executed on port 5",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_6",
        .udesc = "Cycles which a Uop is executed on port 6",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_7",
        .udesc = "Cycles which a Uop is executed on port 7",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PORT_0_CORE",
        .udesc = "tbd",
        .ucode = 0x100 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_0:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_1_CORE",
        .udesc = "tbd",
        .ucode = 0x200 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_1:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_2_CORE",
        .udesc = "tbd",
        .ucode = 0x400 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_2:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_3_CORE",
        .udesc = "tbd",
        .ucode = 0x800 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_3:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_4_CORE",
        .udesc = "tbd",
        .ucode = 0x1000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_4:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_5_CORE",
        .udesc = "tbd",
        .ucode = 0x2000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_5:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_6_CORE",
        .udesc = "tbd",
        .ucode = 0x4000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_6:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
    {
        .uname = "PORT_7_CORE",
        .udesc = "tbd",
        .ucode = 0x8000 | INTEL_X86_MOD_ANY, /* any=1 */
        .uequiv = "PORT_7:t=1",
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T,
    },
};

static const intel_x86_umask_t bdw_uops_issued[] = {
    {
        .uname = "ANY",
        .udesc = "Number of Uops issued by the Resource Allocation Table (RAT) to the "
                 "Reservation Station (RS)",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL",
        .udesc = "Number of Uops issued by the Resource Allocation Table (RAT) to the "
                 "Reservation Station (RS)",
        .ucode = 0x100,
        .uequiv = "ANY",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "FLAGS_MERGE",
        .udesc = "Number of flags-merge uops being allocated. Such uops adds delay",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SLOW_LEA",
        .udesc = "Number of slow LEA or similar uops allocated. Such uop has 3 sources "
                 "regardless if result of LEA instruction or not",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SINGLE_MUL",
        .udesc = "Number of Multiply packed/scalar single precision uops allocated",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Counts the number of cycles no uops issued by this thread",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=1 */
        .uequiv = "ANY:c=1:i=1",
        .uflags = INTEL_X86_NCOMBO,
        .ucntmsk = 0xf,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_STALL_CYCLES",
        .udesc = "Counts the number of cycles no uops issued on this core",
        .ucode = 0x100 | INTEL_X86_MOD_ANY | INTEL_X86_MOD_INV |
                 (1 << INTEL_X86_CMASK_BIT), /* any=1 inv=1 cnt=1 */
        .uequiv = "ANY:c=1:i=1:t=1",
        .ucntmsk = 0xf,
        .uflags = INTEL_X86_NCOMBO,
        .modhw = _INTEL_X86_ATTR_T | _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
};

static const intel_x86_umask_t bdw_uops_retired[] = {
    {
        .uname = "ALL",
        .udesc = "All uops that actually retired",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "ANY",
        .udesc = "All uops that actually retired",
        .ucode = 0x100,
        .uequiv = "ALL",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "RETIRE_SLOTS",
        .udesc = "number of retirement slots used non PEBS",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "STALL_CYCLES",
        .udesc = "Cycles no executable uops retired (Precise Event)",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=1 */
        .uequiv = "ALL:i=1:c=1",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "TOTAL_CYCLES",
        .udesc = "Number of cycles using always true condition applied to PEBS uops "
                 "retired event",
        .ucode =
            0x100 | INTEL_X86_MOD_INV | (10 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=10 */
        .uequiv = "ALL:i=1:c=10",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "CORE_STALL_CYCLES",
        .udesc = "Cycles no executable uops retired on core (Precise Event)",
        .ucode = 0x100 | INTEL_X86_MOD_INV | (1 << INTEL_X86_CMASK_BIT), /* inv=1 cnt=1 */
        .uequiv = "ALL:i=1:c=1:t=1",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C,
    },
    {
        .uname = "STALL_OCCURRENCES",
        .udesc =
            "Number of transitions from stalled to unstalled execution (Precise Event)",
        .ucode = 0x100 | INTEL_X86_MOD_INV | INTEL_X86_MOD_EDGE |
                 (1 << INTEL_X86_CMASK_BIT), /* inv=1 edge=1 cnt=1 */
        .uequiv = "ALL:c=1:i=1:e=1",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .modhw = _INTEL_X86_ATTR_I | _INTEL_X86_ATTR_C | _INTEL_X86_ATTR_E,
    },
};

static const intel_x86_umask_t bdw_offcore_response[] = {
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
        .ucode = 0x24100,
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
        .ucode = 0x10300,
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
        .uname = "L3_HITM",
        .udesc = "Supplier: counts L3 hits in M-state (initial lookup)",
        .ucode = 1ULL << (18 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITM",
        .udesc = "Supplier: counts L3 hits in M-state (initial lookup)",
        .ucode = 1ULL << (18 + 8),
        .uequiv = "L3_HITM",
        .grpid = 1,
    },
    {
        .uname = "L3_HITE",
        .udesc = "Supplier: counts L3 hits in E-state",
        .ucode = 1ULL << (19 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITE",
        .udesc = "Supplier: counts L3 hits in E-state",
        .ucode = 1ULL << (19 + 8),
        .uequiv = "L3_HITE",
        .grpid = 1,
    },
    {
        .uname = "L3_HITS",
        .udesc = "Supplier: counts L3 hits in S-state",
        .ucode = 1ULL << (20 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITS",
        .udesc = "Supplier: counts L3 hits in S-state",
        .ucode = 1ULL << (20 + 8),
        .uequiv = "L3_HITS",
        .grpid = 1,
    },
    {
        .uname = "L3_HITF",
        .udesc = "Supplier: counts L3 hits in F-state",
        .ucode = 1ULL << (21 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_HITF",
        .udesc = "Supplier: counts L3 hits in F-state",
        .ucode = 1ULL << (20 + 8),
        .uequiv = "L3_HITF",
        .grpid = 1,
    },
    {
        .uname = "L3_HITMESF",
        .udesc = "Supplier: counts L3 hits in any state (M, E, S, F)",
        .ucode = 0xfULL << (18 + 8),
        .uequiv = "L3_HITM:L3_HITE:L3_HITS:L3_HITF",
        .grpid = 1,
    },
    {
        .uname = "LLC_HITMESF",
        .udesc = "Supplier: counts L3 hits in any state (M, E, S, F)",
        .ucode = 0xfULL << (18 + 8),
        .uequiv = "L3_HITMESF",
        .grpid = 1,
    },
    {
        .uname = "L3_HIT",
        .udesc = "Alias for L3_HITMESF",
        .ucode = 0xfULL << (18 + 8),
        .uequiv = "L3_HITM:L3_HITE:L3_HITS:L3_HITF",
        .grpid = 1,
    },
    {
        .uname = "LLC_HIT",
        .udesc = "Alias for LLC_HITMESF",
        .ucode = 0xfULL << (18 + 8),
        .uequiv = "L3_HITM:L3_HITE:L3_HITS:L3_HITF",
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_LOCAL",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 1ULL << (26 + 8),
        .grpid = 1,
    },
    {
        .uname = "LLC_MISS_LOCAL",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 1ULL << (26 + 8),
        .uequiv = "L3_MISS_LOCAL",
        .grpid = 1,
    },
    {
        .uname = "LLC_MISS_LOCAL_DRAM",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 1ULL << (26 + 8),
        .uequiv = "L3_MISS_LOCAL",
        .grpid = 1,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Supplier: counts L3 misses to local DRAM",
        .ucode = 1ULL << (26 + 8),
        .uequiv = "L3_MISS_LOCAL",
        .grpid = 1,
        .umodel = PFM_PMU_INTEL_BDW,
    },
    {
        .uname = "L3_MISS",
        .udesc = "Supplier: counts L3 misses to local or remote DRAM",
        .ucode = 0xfULL << (26 + 8),
        .uequiv =
            "L3_MISS_LOCAL:L3_MISS_REMOTE_HOP0:L3_MISS_REMOTE_HOP1:L3_MISS_REMOTE_HOP2P",
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP0",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 0 hop",
        .ucode = 0x1ULL << (27 + 8),
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP0_DRAM",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 0 hop",
        .ucode = 0x1ULL << (27 + 8),
        .uequiv = "L3_MISS_REMOTE_HOP0",
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP1",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 1 hop",
        .ucode = 0x1ULL << (28 + 8),
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP1_DRAM",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 1 hop",
        .ucode = 0x1ULL << (28 + 8),
        .uequiv = "L3_MISS_REMOTE_HOP1",
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP2P",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 2P hops",
        .ucode = 0x1ULL << (29 + 8),
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_HOP2P_DRAM",
        .udesc = "Supplier: counts L3 misses to remote DRAM with 2P hops",
        .ucode = 0x1ULL << (29 + 8),
        .uequiv = "L3_MISS_REMOTE_HOP2P",
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE",
        .udesc = "Supplier: counts L3 misses to remote node",
        .uequiv = "L3_MISS_REMOTE_HOP0:L3_MISS_REMOTE_HOP1:L3_MISS_REMOTE_HOP2P",
        .ucode = 0x7ULL << (27 + 8),
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "L3_MISS_REMOTE_DRAM",
        .udesc = "Supplier: counts L3 misses to remote node",
        .ucode = 0x7ULL << (27 + 8),
        .uequiv = "L3_MISS_REMOTE",
        .umodel = PFM_PMU_INTEL_BDW_EP,
        .grpid = 1,
    },
    {
        .uname = "SPL_HIT",
        .udesc = "Supplier: counts L3 supplier hit",
        .ucode = 0x1ULL << (30 + 8),
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
        .uequiv = "SNP_HITM",
        .grpid = 2,
    },
    {
        .uname = "SNP_HITM",
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

static const intel_x86_umask_t bdw_hle_retired[] = {
    {
        .uname = "START",
        .udesc = "Number of times an HLE execution started",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "COMMIT",
        .udesc = "Number of times an HLE execution successfully committed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED",
        .udesc = "Number of times an HLE execution aborted due to any reasons (multiple "
                 "categories may count as one) (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ABORTED_MISC1",
        .udesc = "Number of times an HLE execution aborted due to various memory events",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC2",
        .udesc = "Number of times an HLE execution aborted due to uncommon conditions",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC3",
        .udesc =
            "Number of times an HLE execution aborted due to HLE-unfriendly instructions",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC4",
        .udesc =
            "Number of times an HLE execution aborted due to incompatible memory type",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC5",
        .udesc = "Number of times an HLE execution aborted due to none of the other 4 "
                 "reasons (e.g., interrupt)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_rtm_retired[] = {
    {
        .uname = "START",
        .udesc = "Number of times an RTM execution started",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "COMMIT",
        .udesc = "Number of times an RTM execution successfully committed",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED",
        .udesc = "Number of times an RTM execution aborted due to any reasons (multiple "
                 "categories may count as one) (Precise Event)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ABORTED_MISC1",
        .udesc = "Number of times an RTM execution aborted due to various memory events",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC2",
        .udesc = "Number of times an RTM execution aborted due to uncommon conditions",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC3",
        .udesc =
            "Number of times an RTM execution aborted due to RTM-unfriendly instructions",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC4",
        .udesc =
            "Number of times an RTM execution aborted due to incompatible memory type",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORTED_MISC5",
        .udesc = "Number of times an RTM execution aborted due to none of the other 4 "
                 "reasons (e.g., interrupt)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_tx_mem[] = {
    {
        .uname = "ABORT_CONFLICT",
        .udesc = "Number of times a transactional abort was signaled due to data "
                 "conflict on a transactionally accessed address",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_CAPACITY",
        .udesc = "Number of times a transactional abort was signaled due to data "
                 "capacity limitation",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_HLE_STORE_TO_ELIDED_LOCK",
        .udesc =
            "Number of times a HLE transactional execution aborted due to a non xrelease "
            "prefixed instruction writing to an elided lock in the elision buffer",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_HLE_ELISION_BUFFER_NOT_EMPTY",
        .udesc = "Number of times a HLE transactional execution aborted due to "
                 "NoAllocatedElisionBuffer being non-zero",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_HLE_ELISION_BUFFER_MISMATCH",
        .udesc =
            "Number of times a HLE transaction execution aborted due to xrelease lock "
            "not satisfying the address and value requirements in the elision buffer",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_HLE_ELISION_BUFFER_UNSUPPORTED_ALIGNMENT",
        .udesc = "Number of times a HLE transaction execution aborted due to an "
                 "unsupported read alignment from the elision buffer",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ABORT_HLE_ELISION_BUFFER_FULL",
        .udesc = "Number of times a HLE clock could not be elided due to "
                 "ElisionBufferAvailable being zero",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_tx_exec[] = {
    {
        .uname = "MISC1",
        .udesc = "Number of times a class of instructions that may cause a transactional "
                 "abort was executed. Since this is the count of execution, it may not "
                 "always cause a transactional abort",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISC2",
        .udesc = "Number of times a class of instructions that may cause a transactional "
                 "abort was executed inside a transactional region",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISC3",
        .udesc = "Number of times an instruction execution caused the supported nest "
                 "count to be exceeded",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISC4",
        .udesc = "Number of times an instruction a xbegin instruction was executed "
                 "inside HLE transactional region",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISC5",
        .udesc = "Number of times an instruction with HLE xacquire prefix was executed "
                 "inside a RTM transactional region",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_offcore_requests_outstanding[] = {
    {
        .uname = "ALL_DATA_RD_CYCLES",
        .udesc = "Cycles with cacheable data read transactions in the superQ (use with "
                 "HT off only)",
        .uequiv = "ALL_DATA_RD:c=1",
        .ucode = 0x800 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD_CYCLES",
        .udesc = "Cycles with demand code reads transactions in the superQ (use with HT "
                 "off only)",
        .uequiv = "DEMAND_CODE_RD:c=1",
        .ucode = 0x200 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD_CYCLES",
        .udesc = "Cycles with demand data read transactions in the superQ (use with HT "
                 "off only)",
        .uequiv = "DEMAND_DATA_RD:c=1",
        .ucode = 0x100 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL_DATA_RD",
        .udesc = "Cacheable data read transactions in the superQ every cycle (use with "
                 "HT off only)",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_CODE_RD",
        .udesc =
            "Code read transactions in the superQ every cycle (use with HT off only)",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_DATA_RD",
        .udesc = "Demand data read transactions in the superQ every cycle (use with HT "
                 "off only)",
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
        .udesc = "Outstanding RFO (store) transactions in the superQ every cycle (use "
                 "with HT off only)",
        .ucode = 0x400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DEMAND_RFO_CYCLES",
        .udesc = "Cycles with outstanding RFO (store) transactions in the superQ (use "
                 "with HT off only)",
        .uequiv = "DEMAND_RFO:c=1",
        .ucode = 0x400 | (0x1 << INTEL_X86_CMASK_BIT),
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_ild_stall[] = {
    {
        .uname = "LCP",
        .udesc = "Stall caused by changing prefix length of the instruction",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_page_walker_loads[] = {
    {
        .uname = "DTLB_L1",
        .udesc =
            "Number of DTLB page walker loads that hit in the L1D and line fill buffer",
        .ucode = 0x1100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ITLB_L1",
        .udesc =
            "Number of ITLB page walker loads that hit in the L1I and line fill buffer",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DTLB_L2",
        .udesc = "Number of DTLB page walker loads that hit in the L2",
        .ucode = 0x1200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ITLB_L2",
        .udesc = "Number of ITLB page walker loads that hit in the L2",
        .ucode = 0x2200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DTLB_L3",
        .udesc = "Number of DTLB page walker loads that hit in the L3",
        .ucode = 0x1400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ITLB_L3",
        .udesc = "Number of ITLB page walker loads that hit in the L3",
        .ucode = 0x2400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DTLB_MEMORY",
        .udesc = "Number of DTLB page walker loads that hit memory",
        .ucode = 0x1800,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t bdw_lsd[] = {
    {
        .uname = "UOPS",
        .udesc = "Number of uops delivered by the Loop Stream Detector (LSD)",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL,
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

static const intel_x86_umask_t bdw_dsb2mite_switches[] = {
    {
        .uname = "PENALTY_CYCLES",
        .udesc = "Number of DSB to MITE switch true penalty cycles",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_ept[] = {
    {
        .uname = "WALK_CYCLES",
        .udesc = "Cycles for an extended page table walk",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_arith[] = {
    {
        .uname = "FPU_DIV_ACTIVE",
        .udesc = "Cycles when divider is busy execuing divide operations",
        .ucode = 0x0100,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_fp_arith[] = {
    {
        .uname = "SCALAR_DOUBLE",
        .udesc = "Number of scalar double precision floating-point arithmetic "
                 "instructions (multiply by 1 to get flops)",
        .ucode = 0x0100,
    },
    {
        .uname = "SCALAR_SINGLE",
        .udesc = "Number of scalar single precision floating-point arithmetic "
                 "instructions (multiply by 1 to get flops)",
        .ucode = 0x0200,
    },
    {
        .uname = "SCALAR",
        .udesc = "Number of SSE/AVX computational scalar floating-point instructions "
                 "retired. Applies to SSE* and AVX* scalar, double and single precision "
                 "floating-point: ADD SUB MUL DIV MIN MAX RSQRT RCP SQRT FM(N)ADD/SUB. "
                 "FM(N)ADD/SUB instructions count twice as they perform multiple "
                 "calculations per element",
        .ucode = 0x0300,
        .uequiv = "SCALAR_DOUBLE:SCALAR_SINGLE",
    },
    {
        .uname = "128B_PACKED_DOUBLE",
        .udesc = "Number of scalar 128-bit packed double precision floating-point "
                 "arithmetic instructions (multiply by 2 to get flops)",
        .ucode = 0x0400,
    },
    {
        .uname = "128B_PACKED_SINGLE",
        .udesc = "Number of scalar 128-bit packed single precision floating-point "
                 "arithmetic instructions (multiply by 4 to get flops)",
        .ucode = 0x0800,
    },
    {
        .uname = "256B_PACKED_DOUBLE",
        .udesc = "Number of scalar 256-bit packed double precision floating-point "
                 "arithmetic instructions (multiply by 4 to get flops)",
        .ucode = 0x1000,
    },
    {
        .uname = "256B_PACKED_SINGLE",
        .udesc = "Number of scalar 256-bit packed single precision floating-point "
                 "arithmetic instructions (multiply by 8 to get flops)",
        .ucode = 0x2000,
    },
    {
        .uname = "PACKED",
        .udesc = "Number of SSE/AVX computational packed floating-point instructions "
                 "retired. Applies to SSE* and AVX*, packed, double and single precision "
                 "floating-point: ADD SUB MUL DIV MIN MAX RSQRT RCP SQRT DPP "
                 "FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they "
                 "perform multiple calculations per element",
        .ucode = 0x3c00,
        .uequiv =
            "128B_PACKED_DOUBLE:128B_PACKED_SINGLE:256B_PACKED_SINGLE:256B_PACKED_DOUBLE",
    },
    {
        .uname = "SINGLE",
        .udesc = "Number of SSE/AVX computational single precision floating-point "
                 "instructions retired. Applies to SSE* and AVX*scalar, double and "
                 "single precision floating-point: ADD SUB MUL DIV MIN MAX RCP RSQRT "
                 "SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice "
                 "as they perform multiple calculations per element",
        .ucode = 0x2a00,
        .uequiv = "256B_PACKED_SINGLE:128B_PACKED_SINGLE:SCALAR_SINGLE",
    },
    {
        .uname = "DOUBLE",
        .udesc = "Number of SSE/AVX computational double precision floating-point "
                 "instructions retired. Applies to SSE* and AVX*scalar, double and "
                 "single precision floating-point: ADD SUB MUL DIV MIN MAX SQRT DPP "
                 "FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they "
                 "perform multiple calculations per element",
        .ucode = 0x1500,
        .uequiv = "SCALAR_DOUBLE:128B_PACKED_DOUBLE:256B_PACKED_DOUBLE",
    },
};

static const intel_x86_umask_t bdw_offcore_requests_buffer[] = {
    {
        .uname = "SQ_FULL",
        .udesc = "Number of cycles the offcore requests buffer is full",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t bdw_uops_dispatches_cancelled[] = {
    {
        .uname = "SIMD_PRF",
        .udesc =
            "Number of uops cancelled after they were dispatched from the scheduler to "
            "the execution units when the total number of physical register read ports "
            "exceeds the read bandwidth of the register file. This umask applies to "
            "instructions: DPPS, DPPS, VPCMPESTRI, PCMPESTRI, VPCMPESTRM, PCMPESTRM, "
            "VFMADD*, VFMADDSUB*, VFMSUB*, VMSUBADD*, VFNMADD*, VFNMSUB*",
        .ucode = 0x0300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_entry_t intel_bdw_pe[] = {
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Count core clock cycles whenever the clock signal on the specific core "
                "is running (not halted)",
        .modmsk = INTEL_V4_ATTRS,
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
        .name = "INSTRUCTION_RETIRED",
        .desc = "Number of instructions at retirement",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0x10000000full,
        .code = 0xc0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "This is an alias for INSTRUCTION_RETIRED",
        .modmsk = INTEL_V4_ATTRS,
        .equiv = "INSTRUCTION_RETIRED",
        .cntmsk = 0x10000000full,
        .code = 0xc0,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Count branch instructions at retirement. Specifically, this event "
                "counts the retirement of the last micro-op of a branch instruction",
        .modmsk = INTEL_V4_ATTRS,
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
        .modmsk = INTEL_V4_ATTRS,
        .equiv = "BR_MISP_RETIRED:ALL_BRANCHES",
        .cntmsk = 0xff,
        .code = 0xc5,
    },
    {.name = "BACLEARS",
     .desc = "Branch re-steered",
     .code = 0xe6,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_baclears),
     .umasks = bdw_baclears},
    {.name = "BR_INST_EXEC",
     .desc = "Branch instructions executed",
     .code = 0x88,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_br_inst_exec),
     .umasks = bdw_br_inst_exec},
    {.name = "BR_INST_RETIRED",
     .desc = "Branch instructions retired (Precise Event)",
     .code = 0xc4,
     .cntmsk = 0xff,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_br_inst_retired),
     .umasks = bdw_br_inst_retired},
    {.name = "BR_MISP_EXEC",
     .desc = "Mispredicted branches executed",
     .code = 0x89,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_br_misp_exec),
     .umasks = bdw_br_misp_exec},
    {.name = "BR_MISP_RETIRED",
     .desc = "Mispredicted retired branches (Precise Event)",
     .code = 0xc5,
     .cntmsk = 0xff,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_br_misp_retired),
     .umasks = bdw_br_misp_retired},
    {.name = "CPL_CYCLES",
     .desc = "Unhalted core cycles at a specific ring level",
     .code = 0x5c,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_cpl_cycles),
     .umasks = bdw_cpl_cycles},
    {.name = "CPU_CLK_THREAD_UNHALTED",
     .desc = "Count core clock cycles whenever the clock signal on the specific core is "
             "running (not halted)",
     .code = 0x3c,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_cpu_clk_thread_unhalted),
     .umasks = bdw_cpu_clk_thread_unhalted},
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Count core clock cycles whenever the clock signal on the specific core "
                "is running (not halted)",
        .code = 0x3c,
        .cntmsk = 0xff,
        .modmsk = INTEL_V4_ATTRS,
        .equiv = "CPU_CLK_THREAD_UNHALTED",
    },
    {.name = "CYCLE_ACTIVITY",
     .desc = "Stalled cycles",
     .code = 0xa3,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_cycle_activity),
     .umasks = bdw_cycle_activity},
    {.name = "DTLB_LOAD_MISSES",
     .desc = "Data TLB load misses",
     .code = 0x8,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_dtlb_load_misses),
     .umasks = bdw_dtlb_load_misses},
    {
        .name = "DTLB_STORE_MISSES",
        .desc = "Data TLB store misses",
        .code = 0x49,
        .cntmsk = 0xff,
        .ngrp = 1,
        .modmsk = INTEL_V4_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_dtlb_load_misses),
        .umasks = bdw_dtlb_load_misses /* shared */
    },
    {.name = "FP_ASSIST",
     .desc = "X87 floating-point assists",
     .code = 0xca,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_fp_assist),
     .umasks = bdw_fp_assist},
    {.name = "HLE_RETIRED",
     .desc = "HLE execution (Precise Event)",
     .code = 0xc8,
     .cntmsk = 0xff,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_hle_retired),
     .umasks = bdw_hle_retired},
    {.name = "ICACHE",
     .desc = "Instruction Cache",
     .code = 0x80,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_icache),
     .umasks = bdw_icache},
    {.name = "IDQ",
     .desc = "IDQ operations",
     .code = 0x79,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_idq),
     .umasks = bdw_idq},
    {.name = "IDQ_UOPS_NOT_DELIVERED",
     .desc = "Uops not delivered",
     .code = 0x9c,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_idq_uops_not_delivered),
     .umasks = bdw_idq_uops_not_delivered},
    {.name = "INST_RETIRED",
     .desc = "Number of instructions retired (Precise Event)",
     .code = 0xc0,
     .cntmsk = 0xff,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_inst_retired),
     .umasks = bdw_inst_retired},
    {.name = "INT_MISC",
     .desc = "Miscellaneous interruptions",
     .code = 0xd,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_int_misc),
     .umasks = bdw_int_misc},
    {.name = "ITLB",
     .desc = "Instruction TLB",
     .code = 0xae,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_itlb),
     .umasks = bdw_itlb},
    {.name = "ITLB_MISSES",
     .desc = "Instruction TLB misses",
     .code = 0x85,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_itlb_misses),
     .umasks = bdw_itlb_misses},
    {.name = "L1D",
     .desc = "L1D cache",
     .code = 0x51,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l1d),
     .umasks = bdw_l1d},
    {.name = "L1D_PEND_MISS",
     .desc = "L1D pending misses",
     .code = 0x48,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l1d_pend_miss),
     .umasks = bdw_l1d_pend_miss},
    {.name = "L2_DEMAND_RQSTS",
     .desc = "Demand Data Read requests to L2",
     .code = 0x27,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l2_demand_rqsts),
     .umasks = bdw_l2_demand_rqsts},
    {.name = "L2_LINES_IN",
     .desc = "L2 lines allocated",
     .code = 0xf1,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l2_lines_in),
     .umasks = bdw_l2_lines_in},
    {.name = "L2_LINES_OUT",
     .desc = "L2 lines evicted",
     .code = 0xf2,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l2_lines_out),
     .umasks = bdw_l2_lines_out},
    {.name = "L2_RQSTS",
     .desc = "L2 requests",
     .code = 0x24,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l2_rqsts),
     .umasks = bdw_l2_rqsts},
    {.name = "L2_TRANS",
     .desc = "L2 transactions",
     .code = 0xf0,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_l2_trans),
     .umasks = bdw_l2_trans},
    {.name = "LD_BLOCKS",
     .desc = "Blocking loads",
     .code = 0x3,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_ld_blocks),
     .umasks = bdw_ld_blocks},
    {.name = "LD_BLOCKS_PARTIAL",
     .desc = "Partial load blocks",
     .code = 0x7,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_ld_blocks_partial),
     .umasks = bdw_ld_blocks_partial},
    {.name = "LOAD_HIT_PRE",
     .desc = "Load dispatches",
     .code = 0x4c,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_load_hit_pre),
     .umasks = bdw_load_hit_pre},
    {.name = "LOCK_CYCLES",
     .desc = "Locked cycles in L1D and L2",
     .code = 0x63,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_lock_cycles),
     .umasks = bdw_lock_cycles},
    {.name = "LONGEST_LAT_CACHE",
     .desc = "L3 cache",
     .code = 0x2e,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_longest_lat_cache),
     .umasks = bdw_longest_lat_cache},
    {.name = "MACHINE_CLEARS",
     .desc = "Machine clear asserted",
     .code = 0xc3,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_machine_clears),
     .umasks = bdw_machine_clears},
    {.name = "MEM_LOAD_UOPS_L3_HIT_RETIRED",
     .desc = "L3 hit load uops retired (Precise Event)",
     .code = 0xd2,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_load_uops_l3_hit_retired),
     .umasks = bdw_mem_load_uops_l3_hit_retired},
    {.name = "MEM_LOAD_UOPS_LLC_HIT_RETIRED",
     .desc = "L3 hit load uops retired (Precise Event)",
     .equiv = "MEM_LOAD_UOPS_L3_HIT_RETIRED",
     .code = 0xd2,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_load_uops_l3_hit_retired),
     .umasks = bdw_mem_load_uops_l3_hit_retired},
    {.name = "MEM_LOAD_UOPS_L3_MISS_RETIRED",
     .desc = "Load uops retired that missed the L3 (Precise Event)",
     .code = 0xd3,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_load_uops_l3_miss_retired),
     .umasks = bdw_mem_load_uops_l3_miss_retired},
    {.name = "MEM_LOAD_UOPS_LLC_MISS_RETIRED",
     .desc = "Load uops retired that missed the L3 (Precise Event)",
     .equiv = "MEM_LOAD_UOPS_L3_MISS_RETIRED",
     .code = 0xd3,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_load_uops_l3_miss_retired),
     .umasks = bdw_mem_load_uops_l3_miss_retired},
    {.name = "MEM_LOAD_UOPS_RETIRED",
     .desc = "Retired load uops (Precise Event)",
     .code = 0xd1,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_load_uops_retired),
     .umasks = bdw_mem_load_uops_retired},
    {.name = "MEM_TRANS_RETIRED",
     .desc = "Memory transactions retired (Precise Event)",
     .code = 0xcd,
     .cntmsk = 0x8,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS | _INTEL_X86_ATTR_LDLAT,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_trans_retired),
     .umasks = bdw_mem_trans_retired},
    {.name = "MEM_UOPS_RETIRED",
     .desc = "Memory uops retired (Precise Event)",
     .code = 0xd0,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_mem_uops_retired),
     .umasks = bdw_mem_uops_retired},
    {.name = "MISALIGN_MEM_REF",
     .desc = "Misaligned memory references",
     .code = 0x5,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_misalign_mem_ref),
     .umasks = bdw_misalign_mem_ref},
    {.name = "MOVE_ELIMINATION",
     .desc = "Move Elimination",
     .code = 0x58,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_move_elimination),
     .umasks = bdw_move_elimination},
    {.name = "OFFCORE_REQUESTS",
     .desc = "Demand Data Read requests sent to uncore",
     .code = 0xb0,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_offcore_requests),
     .umasks = bdw_offcore_requests},
    {.name = "OTHER_ASSISTS",
     .desc = "Software assist",
     .code = 0xc1,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_other_assists),
     .umasks = bdw_other_assists},
    {.name = "RESOURCE_STALLS",
     .desc = "Cycles Allocation is stalled due to Resource Related reason",
     .code = 0xa2,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_resource_stalls),
     .umasks = bdw_resource_stalls},
    {.name = "ROB_MISC_EVENTS",
     .desc = "ROB miscellaneous events",
     .code = 0xcc,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_rob_misc_events),
     .umasks = bdw_rob_misc_events},
    {.name = "RS_EVENTS",
     .desc = "Reservation Station",
     .code = 0x5e,
     .cntmsk = 0xf,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_rs_events),
     .umasks = bdw_rs_events},
    {.name = "RTM_RETIRED",
     .desc = "Restricted Transaction Memory execution (Precise Event)",
     .code = 0xc9,
     .cntmsk = 0xf,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_rtm_retired),
     .umasks = bdw_rtm_retired},
    {.name = "TLB_FLUSH",
     .desc = "TLB flushes",
     .code = 0xbd,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_tlb_flush),
     .umasks = bdw_tlb_flush},
    {.name = "UOPS_EXECUTED",
     .desc = "Uops executed",
     .code = 0xb1,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_uops_executed),
     .umasks = bdw_uops_executed},
    {
        .name = "LSD",
        .desc = "Loop stream detector",
        .code = 0xa8,
        .cntmsk = 0xff,
        .ngrp = 1,
        .modmsk = INTEL_V4_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_lsd),
        .umasks = bdw_lsd,
    },

    {.name = "UOPS_EXECUTED_PORT",
     .desc = "Uops dispatch to specific ports",
     .code = 0xa1,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_uops_executed_port),
     .umasks = bdw_uops_executed_port},
    {.name = "UOPS_ISSUED",
     .desc = "Uops issued",
     .code = 0xe,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_uops_issued),
     .umasks = bdw_uops_issued},
    {.name = "ARITH",
     .desc = "Arithmetic uop",
     .code = 0x14,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_arith),
     .umasks = bdw_arith},
    {.name = "UOPS_RETIRED",
     .desc = "Uops retired (Precise Event)",
     .code = 0xc2,
     .cntmsk = 0xff,
     .ngrp = 1,
     .flags = INTEL_X86_PEBS,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_uops_retired),
     .umasks = bdw_uops_retired},
    {
        .name = "TX_MEM",
        .desc = "Transactional memory aborts",
        .code = 0x54,
        .cntmsk = 0xff,
        .ngrp = 1,
        .modmsk = INTEL_V4_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_tx_mem),
        .umasks = bdw_tx_mem,
    },
    {.name = "TX_EXEC",
     .desc = "Transactional execution",
     .code = 0x5d,
     .cntmsk = 0xff,
     .ngrp = 1,
     .modmsk = INTEL_V4_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(bdw_tx_exec),
     .umasks = bdw_tx_exec},
    {
        .name = "OFFCORE_REQUESTS_OUTSTANDING",
        .desc = "Outstanding offcore requests",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xff,
        .code = 0x60,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_offcore_requests_outstanding),
        .ngrp = 1,
        .umasks = bdw_offcore_requests_outstanding,
    },
    {
        .name = "ILD_STALL",
        .desc = "Instruction Length Decoder stalls",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xff,
        .code = 0x87,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_ild_stall),
        .ngrp = 1,
        .umasks = bdw_ild_stall,
    },
    {
        .name = "PAGE_WALKER_LOADS",
        .desc = "Page walker loads",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xbc,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_page_walker_loads),
        .ngrp = 1,
        .umasks = bdw_page_walker_loads,
    },
    {
        .name = "DSB2MITE_SWITCHES",
        .desc = "Number of DSB to MITE switches",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xff,
        .code = 0xab,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_dsb2mite_switches),
        .ngrp = 1,
        .umasks = bdw_dsb2mite_switches,
    },
    {
        .name = "EPT",
        .desc = "Extended page table",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xff,
        .code = 0x4f,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_ept),
        .ngrp = 1,
        .umasks = bdw_ept,
    },
    {
        .name = "FP_ARITH",
        .desc = "Floating-point instructions retired",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc7,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_fp_arith),
        .ngrp = 1,
        .umasks = bdw_fp_arith,
        .equiv = "FP_ARITH_INST_RETIRED",
    },
    {
        .name = "FP_ARITH_INST_RETIRED",
        .desc = "Floating-point instructions retired",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xc7,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_fp_arith),
        .ngrp = 1,
        .umasks = bdw_fp_arith,
    },
    {
        .name = "OFFCORE_REQUESTS_BUFFER",
        .desc = "Offcore reqest buffer",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xff,
        .code = 0xb2,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_offcore_requests_buffer),
        .ngrp = 1,
        .umasks = bdw_offcore_requests_buffer,
    },
    {
        .name = "UOPS_DISPATCHES_CANCELLED",
        .desc = "Micro-ops cancelled",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xa0,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_uops_dispatches_cancelled),
        .ngrp = 1,
        .umasks = bdw_uops_dispatches_cancelled,
    },
    {
        .name = "SQ_MISC",
        .desc = "SuperQueue miscellaneous",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0xf4,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_sq_misc),
        .ngrp = 1,
        .umasks = bdw_sq_misc,
    },
    {
        .name = "OFFCORE_RESPONSE_0",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1b7,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_offcore_response),
        .ngrp = 3,
        .umasks = bdw_offcore_response,
    },
    {
        .name = "OFFCORE_RESPONSE_1",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V4_ATTRS,
        .cntmsk = 0xf,
        .code = 0x1bb,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(bdw_offcore_response),
        .ngrp = 3,
        .umasks =
            bdw_offcore_response, /* identical to actual umasks list for this event */
    },
};
