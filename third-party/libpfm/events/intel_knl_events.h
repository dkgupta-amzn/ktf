/*
 * Copyright (c) 2016 Intel Corp. All rights reserved
 * Contributed by Peinan Zhang <peinan.zhang@intel.com>
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
 * PMU: knl (Intel Knights Landing)
 */

static const intel_x86_umask_t knl_icache[] = {
    {
        .uname = "HIT",
        .udesc = "Counts all instruction fetches that hit the instruction cache.",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISSES",
        .udesc = "Counts all instruction fetches that miss the instruction cache or "
                 "produce memory requests. An instruction fetch miss is counted only "
                 "once and not once for every cycle it is outstanding.",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ACCESSES",
        .udesc = "Counts all instruction fetches, including uncacheable fetches.",
        .ucode = 0x300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_uops_retired[] = {
    {
        .uname = "ALL",
        .udesc = "Counts the number of micro-ops retired.",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "MS",
        .udesc = "Counts the number of micro-ops retired that are from the complex flows "
                 "issued by the micro-sequencer (MS).",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "SCALAR_SIMD",
        .udesc =
            "Counts the number of scalar SSE, AVX, AVX2, AVX-512 micro-ops retired. More "
            "specifically, it counts scalar SSE, AVX, AVX2, AVX-512 micro-ops except for "
            "loads (memory-to-register mov-type micro ops), division, sqrt.",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "PACKED_SIMD",
        .udesc = "Counts the number of vector SSE, AVX, AVX2, AVX-512 micro-ops retired. "
                 "More specifically, it counts packed SSE, AVX, AVX2, AVX-512 micro-ops "
                 "(both floating point and integer) except for loads (memory-to-register "
                 "mov-type micro-ops), packed byte and word multiplies.",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc = "Instructions retired using generic counter (precise event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "ANY",
        .udesc = "Instructions retired using generic counter (precise event)",
        .uequiv = "ANY_P",
        .ucode = 0x0,
        .uflags = INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t knl_l2_requests_reject[] = {
    {
        .uname = "ALL",
        .udesc = "Counts the number of MEC requests from the L2Q that reference a cache "
                 "line excluding SW prefetches filling only to L2 cache and L1 evictions "
                 "(automatically exlcudes L2HWP, UC, WC) that were rejected - Multiple "
                 "repeated rejects should be counted multiple times.",
        .ucode = 0x000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_core_reject[] = {
    {
        .uname = "ALL",
        .udesc =
            "Counts the number of MEC requests that were not accepted into the L2Q "
            "because of any L2  queue reject condition. There is no concept of at-ret "
            "here. It might include requests due to instructions in the speculative path",
        .ucode = 0x000,
        .uflags = INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_machine_clears[] = {
    {
        .uname = "SMC",
        .udesc = "Counts the number of times that the machine clears due to program "
                 "modifying data within 1K of a recently fetched code page.",
        .ucode = 0x0100,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "MEMORY_ORDERING",
        .udesc = "Counts the number of times the machine clears due to memory ordering "
                 "hazards",
        .ucode = 0x0200,
    },
    {
        .uname = "FP_ASSIST",
        .udesc = "Counts the number of floating operations retired that required "
                 "microcode assists",
        .ucode = 0x0400,
    },
    {
        .uname = "ALL",
        .udesc = "Counts all nukes",
        .ucode = 0x0800,
    },
    {
        .uname = "ANY",
        .udesc = "Counts all nukes",
        .uequiv = "ALL",
        .ucode = 0x0800,
    },
};

static const intel_x86_umask_t knl_br_inst_retired[] = {
    {
        .uname = "ANY",
        .udesc = "Counts the number of branch instructions retired (Precise Event)",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Counts the number of branch instructions retired",
        .uequiv = "ANY",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "JCC",
        .udesc = "Counts the number of branch instructions retired that were conditional "
                 "jumps.",
        .ucode = 0x7e00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "TAKEN_JCC",
        .udesc = "Counts the number of branch instructions retired that were conditional "
                 "jumps and predicted taken.",
        .ucode = 0xfe00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "CALL",
        .udesc = "Counts the number of near CALL branch instructions retired.",
        .ucode = 0xf900,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REL_CALL",
        .udesc = "Counts the number of near relative CALL branch instructions retired.",
        .ucode = 0xfd00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "IND_CALL",
        .udesc = "Counts the number of near indirect CALL branch instructions retired. "
                 "(Precise Event)",
        .ucode = 0xfb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "RETURN",
        .udesc =
            "Counts the number of near RET branch instructions retired. (Precise Event)",
        .ucode = 0xf700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NON_RETURN_IND",
        .udesc = "Counts the number of branch instructions retired that were near "
                 "indirect CALL or near indirect JMP. (Precise Event)",
        .ucode = 0xeb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "FAR_BRANCH",
        .udesc = "Counts the number of far branch instructions retired. (Precise Event)",
        .uequiv = "FAR",
        .ucode = 0xbf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "FAR",
        .udesc = "Counts the number of far branch instructions retired. (Precise Event)",
        .ucode = 0xbf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t knl_fetch_stall[] = {
    {
        .uname = "ICACHE_FILL_PENDING_CYCLES",
        .udesc = "Counts the number of core cycles the fetch stalls because of an icache "
                 "miss. This is a cumulative count of core cycles the fetch stalled for "
                 "all icache misses",
        .ucode = 0x0400,
        .uflags = INTEL_X86_DFL | INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_baclears[] = {
    {
        .uname = "ALL",
        .udesc = "Counts the number of times the front end resteers for any branch as a "
                 "result of another branch handling mechanism in the front end.",
        .ucode = 0x100,
        .uflags = INTEL_X86_DFL | INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "Counts the number of times the front end resteers for any branch as a "
                 "result of another branch handling mechanism in the front end.",
        .uequiv = "ALL",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RETURN",
        .udesc = "Counts the number of times the front end resteers for RET branches as "
                 "a result of another branch handling mechanism in the front end.",
        .ucode = 0x800,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "COND",
        .udesc =
            "Counts the number of times the front end resteers for conditional branches "
            "as a result of another branch handling mechanism in the front end.",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_cpu_clk_unhalted[] = {
    {
        .uname = "THREAD_P",
        .udesc = "thread cycles when core is not halted",
        .ucode = 0x0,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "BUS",
        .udesc = "Bus cycles when core is not halted. This event can give a measurement "
                 "of the elapsed time. This events has a constant ratio with "
                 "CPU_CLK_UNHALTED:REF event, which is the maximum bus to processor "
                 "frequency ratio",
        .uequiv = "REF_P",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REF_P",
        .udesc = "Number of reference cycles that the cpu is not in a halted state. The "
                 "core enters the halted state when it is running the HLT instruction. "
                 "In mobile systems, the core frequency may change from time to time. "
                 "This event is not affected by core frequency changes but counts as if "
                 "the core is running a the same maximum frequency all the time",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_mem_uops_retired[] = {
    {
        .uname = "L1_MISS_LOADS",
        .udesc = "Counts the number of load micro-ops retired that miss in L1 D cache.",
        .ucode = 0x100,
    },
    {
        .uname = "LD_DCU_MISS",
        .udesc = "Counts the number of load micro-ops retired that miss in L1 D cache.",
        .uequiv = "L1_MISS_LOADS",
        .ucode = 0x100,
    },
    {
        .uname = "L2_HIT_LOADS",
        .udesc = "Counts the number of load micro-ops retired that hit in the L2.",
        .ucode = 0x200,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "L2_MISS_LOADS",
        .udesc = "Counts the number of load micro-ops retired that miss in the L2.",
        .ucode = 0x400,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "LD_L2_MISS",
        .udesc = "Counts the number of load micro-ops retired that miss in the L2.",
        .uequiv = "L2_MISS_LOADS",
        .ucode = 0x400,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "DTLB_MISS_LOADS",
        .udesc = "Counts the number of load micro-ops retired that cause a DTLB miss.",
        .ucode = 0x800,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "UTLB_MISS_LOADS",
        .udesc =
            "Counts the number of load micro-ops retired that caused micro TLB miss.",
        .ucode = 0x1000,
    },
    {
        .uname = "LD_UTLB_MISS",
        .udesc =
            "Counts the number of load micro-ops retired that caused micro TLB miss.",
        .uequiv = "UTLB_MISS_LOADS",
        .ucode = 0x1000,
    },
    {
        .uname = "HITM",
        .udesc = "Counts the loads retired that get the data from the other core in the "
                 "same tile in M state.",
        .ucode = 0x2000,
        .uflags = INTEL_X86_PEBS,
    },
    {
        .uname = "ALL_LOADS",
        .udesc = "Counts all the load micro-ops retired.",
        .ucode = 0x4000,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "ANY_LD",
        .udesc = "Counts all the load micro-ops retired.",
        .uequiv = "ALL_LOADS",
        .ucode = 0x4000,
    },
    {
        .uname = "ALL_STORES",
        .udesc = "Counts all the store micro-ops retired.",
        .ucode = 0x8000,
    },
    {
        .uname = "ANY_ST",
        .udesc = "Counts all the store micro-ops retired.",
        .uequiv = "ALL_STORES",
        .ucode = 0x8000,
    },
};

static const intel_x86_umask_t knl_page_walks[] = {
    {
        .uname = "D_SIDE_CYCLES",
        .udesc = "Counts the total D-side page walks that are completed or started. The "
                 "page walks started in the speculative path will also be counted.",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "D_SIDE_WALKS",
        .udesc =
            "Counts the total number of core cycles for all the D-side page walks. The "
            "cycles for page walks started in speculative path will also be included.",
        .ucode = 0x100 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I_SIDE_CYCLES",
        .udesc = "Counts the total I-side page walks that are completed.",
        .ucode = 0x200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "I_SIDE_WALKS",
        .udesc =
            "Counts the total number of core cycles for all the I-side page walks. The "
            "cycles for page walks started in speculative path will also be included.",
        .ucode = 0x200 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "CYCLES",
        .udesc = "Counts the total page walks completed (I-side and D-side)",
        .ucode = 0x300,
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "WALKS",
        .udesc =
            "Counts the total number of core cycles for all the page walks. The cycles "
            "for page walks started in speculative path will also be included.",
        .ucode = 0x300 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT),
        .modhw = _INTEL_X86_ATTR_E | _INTEL_X86_ATTR_C,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_l2_rqsts[] = {
    {
        .uname = "MISS",
        .udesc = "Counts the number of L2 cache misses",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "REFERENCE",
        .udesc = "Counts the total number of L2 cache references.",
        .ucode = 0x4f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_recycleq[] = {
    {
        .uname = "LD_BLOCK_ST_FORWARD",
        .udesc = "Counts the number of occurrences a retired load gets blocked because "
                 "its address partially overlaps with a store (Precise Event).",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LD_BLOCK_STD_NOTREADY",
        .udesc = "Counts the number of occurrences a retired load gets blocked because "
                 "its address overlaps with a store whose data is not ready.",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ST_SPLITS",
        .udesc = "Counts the number of occurrences a retired store that is a cache line "
                 "split. Each split should be counted only once.",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LD_SPLITS",
        .udesc = "Counts the number of occurrences a retired load that is a cache line "
                 "split. Each split should be counted only once (Precise Event).",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "LOCK",
        .udesc = "Counts all the retired locked loads. It does not include stores "
                 "because we would double count if we count stores.",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "STA_FULL",
        .udesc = "Counts the store micro-ops retired that were pushed in the rehad queue "
                 "because the store address buffer is full.",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY_LD",
        .udesc = "Counts any retired load that was pushed into the recycle queue for any "
                 "reason.",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ANY_ST",
        .udesc = "Counts any retired store that was pushed into the recycle queue for "
                 "any reason.",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_offcore_response_0[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Counts demand cacheable data and L1 prefetch data reads",
        .ucode = 1ULL << (0 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Counts Demand cacheable data writes",
        .ucode = 1ULL << (1 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_CODE_RD",
        .udesc = "Counts demand code reads and prefetch code reads",
        .ucode = 1ULL << (2 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L2_RFO",
        .udesc = "Counts L2 data RFO prefetches (includes PREFETCHW instruction)",
        .ucode = 1ULL << (5 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L2_CODE_RD",
        .udesc = "Request: number of code reads generated by L2 prefetchers",
        .ucode = 1ULL << (6 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_READS",
        .udesc = "Counts Partial reads (UC or WC and is valid only for Outstanding "
                 "response type).",
        .ucode = 1ULL << (7 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_WRITES",
        .udesc =
            "Counts Partial writes (UC or WT or WP and should be programmed on PMC1)",
        .ucode = 1ULL << (8 + 8),
        .grpid = 0,
    },
    {
        .uname = "UC_CODE_READS",
        .udesc = "Counts UC code reads (valid only for Outstanding response type)",
        .ucode = 1ULL << (9 + 8),
        .grpid = 0,
    },
    {
        .uname = "BUS_LOCKS",
        .udesc = "Counts Bus locks and split lock requests",
        .ucode = 1ULL << (10 + 8),
        .grpid = 0,
    },
    {
        .uname = "FULL_STREAMING_STORES",
        .udesc = "Counts Full streaming stores (WC and should be programmed on PMC1)",
        .ucode = 1ULL << (11 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_SOFTWARE",
        .udesc = "Counts Software prefetches",
        .ucode = 1ULL << (12 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L1_DATA_RD",
        .udesc = "Counts L1 data HW prefetches",
        .ucode = 1ULL << (13 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_STREAMING_STORES",
        .udesc = "Counts Partial streaming stores (WC and should be programmed on PMC1)",
        .ucode = 1ULL << (14 + 8),
        .grpid = 0,
    },
    {
        .uname = "STREAMING_STORES",
        .udesc = "Counts all streaming stores (WC and should be programmed on PMC1)",
        .ucode = (1ULL << 14 | 1ULL << 11) << 8,
        .uequiv = "PARTIAL_STREAMING_STORES:FULL_STREAMING_STORES",
        .grpid = 0,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Counts any request",
        .ucode = 1ULL << (15 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "ANY_DATA_RD",
        .udesc = "Counts Demand cacheable data and L1 prefetch data read requests",
        .ucode = (1ULL << 0 | 1ULL << 7 | 1ULL << 12 | 1ULL << 13) << 8,
        .uequiv = "DMND_DATA_RD:PARTIAL_READS:PF_SOFTWARE:PF_L1_DATA_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Counts Demand cacheable data write requests",
        .ucode = (1ULL << 1 | 1ULL << 5) << 8,
        .grpid = 0,
    },
    {
        .uname = "ANY_CODE_RD",
        .udesc = "Counts Demand code reads and prefetch code read requests",
        .ucode = (1ULL << 2 | 1ULL << 6) << 8,
        .uequiv = "DMND_CODE_RD:PF_L2_CODE_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_READ",
        .udesc = "Counts any Read request",
        .ucode = (1ULL << 0 | 1ULL << 1 | 1ULL << 2 | 1ULL << 5 | 1ULL << 6 | 1ULL << 7 |
                  1ULL << 9 | 1ULL << 12 | 1ULL << 13)
                 << 8,
        .uequiv = "DMND_DATA_RD:DMND_RFO:DMND_CODE_RD:PF_L2_RFO:PF_L2_CODE_RD:PARTIAL_"
                  "READS:UC_CODE_READS:PF_SOFTWARE:PF_L1_DATA_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_PF_L2",
        .udesc = "Counts any Prefetch requests",
        .ucode = (1ULL << 5 | 1ULL << 6) << 8,
        .uequiv = "PF_L2_RFO:PF_L2_CODE_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_RESPONSE",
        .udesc = "Accounts for any response",
        .ucode = (1ULL << 16) << 8,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_EXCL_GRP_GT,
        .grpid = 1,
    },
    {
        .uname = "DDR_NEAR",
        .udesc = "Accounts for data responses from DRAM Local.",
        .ucode = (1ULL << 31 | 1ULL << 23) << 8,
        .grpid = 1,
    },
    {
        .uname = "DDR_FAR",
        .udesc = "Accounts for data responses from DRAM Far.",
        .ucode = (1ULL << 31 | 1ULL << 24) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM_NEAR",
        .udesc = "Accounts for data responses from MCDRAM Local.",
        .ucode = (1ULL << 31 | 1ULL << 21) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM_FAR",
        .udesc = "Accounts for data responses from MCDRAM Far or Other tile L2 hit far.",
        .ucode = (1ULL << 32 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE_E_F",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Near-other tile's L2 in E/F state.",
        .ucode = (1ULL << 35 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE_M",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Near-other tile's L2 in M state.",
        .ucode = (1ULL << 36 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE_E_F",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Far(not in the same quadrant as the request)-other tile's L2 "
                 "in E/F state. Valid only for SNC4 cluster mode.",
        .ucode = (1ULL << 35 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE_M",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Far(not in the same quadrant as the request)-other tile's L2 "
                 "in M state.",
        .ucode = (1ULL << 36 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "NON_DRAM",
        .udesc = "accounts for responses from any NON_DRAM system address. This includes "
                 "MMIO transactions",
        .ucode = (1ULL << 37 | 1ULL << 17) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM",
        .udesc = "accounts for responses from MCDRAM (local and far)",
        .ucode = (1ULL << 32 | 1ULL << 31 | 1ULL << 22 | 1ULL << 21) << 8,
        .grpid = 1,
    },
    {
        .uname = "DDR",
        .udesc = "accounts for responses from DDR (local and far)",
        .ucode = (1ULL << 32 | 1ULL << 31 | 1ULL << 24 | 1ULL << 23) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE",
        .udesc = " accounts for responses from snoop request hit with data forwarded "
                 "from its Near-other tile L2 in E/F/M state",
        .ucode = (1ULL << 36 | 1ULL << 35 | 1ULL << 20 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE",
        .udesc = "accounts for responses from snoop request hit with data forwarded from "
                 "it Far(not in the same quadrant as the request)-other tile L2 in E/F/M "
                 "state. Valid only in SNC4 Cluster mode.",
        .ucode = (1ULL << 36 | 1ULL << 35 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "OUTSTANDING",
        .udesc = "outstanding, per weighted cycle, from the time of the request to when "
                 "any response is received. The oustanding response should be programmed "
                 "only on PMC0.",
        .ucode = (1ULL << 38) << 8,
        .uflags = INTEL_X86_GRP_DFL_NONE |
                  INTEL_X86_EXCL_GRP_BUT_0, /* can only be combined with request type bits
                                               (grpid = 0) */
        .grpid = 2,
    },
};

static const intel_x86_umask_t knl_offcore_response_1[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Counts demand cacheable data and L1 prefetch data reads",
        .ucode = 1ULL << (0 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Counts Demand cacheable data writes",
        .ucode = 1ULL << (1 + 8),
        .grpid = 0,
    },
    {
        .uname = "DMND_CODE_RD",
        .udesc = "Counts demand code reads and prefetch code reads",
        .ucode = 1ULL << (2 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L2_RFO",
        .udesc = "Counts L2 data RFO prefetches (includes PREFETCHW instruction)",
        .ucode = 1ULL << (5 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L2_CODE_RD",
        .udesc = "Request: number of code reads generated by L2 prefetchers",
        .ucode = 1ULL << (6 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_READS",
        .udesc = "Counts Partial reads (UC or WC and is valid only for Outstanding "
                 "response type).",
        .ucode = 1ULL << (7 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_WRITES",
        .udesc =
            "Counts Partial writes (UC or WT or WP and should be programmed on PMC1)",
        .ucode = 1ULL << (8 + 8),
        .grpid = 0,
    },
    {
        .uname = "UC_CODE_READS",
        .udesc = "Counts UC code reads (valid only for Outstanding response type)",
        .ucode = 1ULL << (9 + 8),
        .grpid = 0,
    },
    {
        .uname = "BUS_LOCKS",
        .udesc = "Counts Bus locks and split lock requests",
        .ucode = 1ULL << (10 + 8),
        .grpid = 0,
    },
    {
        .uname = "FULL_STREAMING_STORES",
        .udesc = "Counts Full streaming stores (WC and should be programmed on PMC1)",
        .ucode = 1ULL << (11 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_SOFTWARE",
        .udesc = "Counts Software prefetches",
        .ucode = 1ULL << (12 + 8),
        .grpid = 0,
    },
    {
        .uname = "PF_L1_DATA_RD",
        .udesc = "Counts L1 data HW prefetches",
        .ucode = 1ULL << (13 + 8),
        .grpid = 0,
    },
    {
        .uname = "PARTIAL_STREAMING_STORES",
        .udesc = "Counts Partial streaming stores (WC and should be programmed on PMC1)",
        .ucode = 1ULL << (14 + 8),
        .grpid = 0,
    },
    {
        .uname = "STREAMING_STORES",
        .udesc = "Counts all streaming stores (WC and should be programmed on PMC1)",
        .ucode = (1ULL << 14 | 1ULL << 11) << 8,
        .uequiv = "PARTIAL_STREAMING_STORES:FULL_STREAMING_STORES",
        .grpid = 0,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Counts any request",
        .ucode = 1ULL << (15 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "ANY_DATA_RD",
        .udesc = "Counts Demand cacheable data and L1 prefetch data read requests",
        .ucode = (1ULL << 0 | 1ULL << 7 | 1ULL << 12 | 1ULL << 13) << 8,
        .uequiv = "DMND_DATA_RD:PARTIAL_READS:PF_SOFTWARE:PF_L1_DATA_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Counts Demand cacheable data write requests",
        .ucode = (1ULL << 1 | 1ULL << 5) << 8,
        .grpid = 0,
    },
    {
        .uname = "ANY_CODE_RD",
        .udesc = "Counts Demand code reads and prefetch code read requests",
        .ucode = (1ULL << 2 | 1ULL << 6) << 8,
        .uequiv = "DMND_CODE_RD:PF_L2_CODE_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_READ",
        .udesc = "Counts any Read request",
        .ucode = (1ULL << 0 | 1ULL << 1 | 1ULL << 2 | 1ULL << 5 | 1ULL << 6 | 1ULL << 7 |
                  1ULL << 9 | 1ULL << 12 | 1ULL << 13)
                 << 8,
        .uequiv = "DMND_DATA_RD:DMND_RFO:DMND_CODE_RD:PF_L2_RFO:PF_L2_CODE_RD:PARTIAL_"
                  "READS:UC_CODE_READS:PF_SOFTWARE:PF_L1_DATA_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_PF_L2",
        .udesc = "Counts any Prefetch requests",
        .ucode = (1ULL << 5 | 1ULL << 6) << 8,
        .uequiv = "PF_L2_RFO:PF_L2_CODE_RD",
        .grpid = 0,
    },
    {
        .uname = "ANY_RESPONSE",
        .udesc = "Accounts for any response",
        .ucode = (1ULL << 16) << 8,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_EXCL_GRP_GT,
        .grpid = 1,
    },
    {
        .uname = "DDR_NEAR",
        .udesc = "Accounts for data responses from DRAM Local.",
        .ucode = (1ULL << 31 | 1ULL << 23) << 8,
        .grpid = 1,
    },
    {
        .uname = "DDR_FAR",
        .udesc = "Accounts for data responses from DRAM Far.",
        .ucode = (1ULL << 31 | 1ULL << 24) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM_NEAR",
        .udesc = "Accounts for data responses from MCDRAM Local.",
        .ucode = (1ULL << 31 | 1ULL << 21) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM_FAR",
        .udesc = "Accounts for data responses from MCDRAM Far or Other tile L2 hit far.",
        .ucode = (1ULL << 32 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE_E_F",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Near-other tile's L2 in E/F state.",
        .ucode = (1ULL << 35 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE_M",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Near-other tile's L2 in M state.",
        .ucode = (1ULL << 36 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE_E_F",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Far(not in the same quadrant as the request)-other tile's L2 "
                 "in E/F state. Valid only for SNC4 cluster mode.",
        .ucode = (1ULL << 35 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE_M",
        .udesc = "Accounts for responses from a snoop request hit with data forwarded "
                 "from its Far(not in the same quadrant as the request)-other tile's L2 "
                 "in M state.",
        .ucode = (1ULL << 36 | 1ULL << 22) << 8,
        .grpid = 1,
    },
    {
        .uname = "NON_DRAM",
        .udesc = "accounts for responses from any NON_DRAM system address. This includes "
                 "MMIO transactions",
        .ucode = (1ULL << 37 | 1ULL << 17) << 8,
        .grpid = 1,
    },
    {
        .uname = "MCDRAM",
        .udesc = "accounts for responses from MCDRAM (local and far)",
        .ucode = (1ULL << 32 | 1ULL << 31 | 1ULL << 22 | 1ULL << 21) << 8,
        .grpid = 1,
    },
    {
        .uname = "DDR",
        .udesc = "accounts for responses from DDR (local and far)",
        .ucode = (1ULL << 32 | 1ULL << 31 | 1ULL << 24 | 1ULL << 23) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_NEAR_TILE",
        .udesc = " accounts for responses from snoop request hit with data forwarded "
                 "from its Near-other tile L2 in E/F/M state",
        .ucode = (1ULL << 36 | 1ULL << 35 | 1ULL << 20 | 1ULL << 19) << 8,
        .grpid = 1,
    },
    {
        .uname = "L2_HIT_FAR_TILE",
        .udesc = "accounts for responses from snoop request hit with data forwarded from "
                 "it Far(not in the same quadrant as the request)-other tile L2 in E/F/M "
                 "state. Valid only in SNC4 Cluster mode.",
        .ucode = (1ULL << 36 | 1ULL << 35 | 1ULL << 22) << 8,
        .grpid = 1,
    },
};

static const intel_x86_umask_t knl_br_misp_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "All mispredicted branches (Precise Event)",
        .uequiv = "ANY",
        .ucode = 0x0000, /* architectural encoding */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "ANY",
        .udesc = "All mispredicted branches (Precise Event)",
        .ucode = 0x0000, /* architectural encoding */
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
    },
    {
        .uname = "JCC",
        .udesc = "Number of mispredicted conditional branch instructions retired "
                 "(Precise Event)",
        .ucode = 0x7e00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "NON_RETURN_IND",
        .udesc = "Number of mispredicted non-return branch instructions retired (Precise "
                 "Event)",
        .ucode = 0xeb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "RETURN",
        .udesc =
            "Number of mispredicted return branch instructions retired (Precise Event)",
        .ucode = 0xf700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "IND_CALL",
        .udesc = "Number of mispredicted indirect call branch instructions retired "
                 "(Precise Event)",
        .ucode = 0xfb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "TAKEN_JCC",
        .udesc = "Number of mispredicted taken conditional branch instructions retired "
                 "(Precise Event)",
        .ucode = 0xfe00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "CALL",
        .udesc =
            "Counts the number of mispredicted near CALL branch instructions retired.",
        .ucode = 0xf900,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "REL_CALL",
        .udesc = "Counts the number of mispredicted near relative CALL branch "
                 "instructions retired.",
        .ucode = 0xfd00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
    {
        .uname = "FAR_BRANCH",
        .udesc = "Counts the number of mispredicted far branch instructions retired.",
        .ucode = 0xbf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
    },
};

static const intel_x86_umask_t knl_no_alloc_cycles[] = {
    {
        .uname = "ROB_FULL",
        .udesc = "Counts the number of core cycles when no micro-ops are allocated and "
                 "the ROB is full",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "MISPREDICTS",
        .udesc = "Counts the number of core cycles when no micro-ops are allocated and "
                 "the alloc pipe is stalled waiting for a mispredicted branch to retire.",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "RAT_STALL",
        .udesc = "Counts the number of core cycles when no micro-ops are allocated and a "
                 "RATstall (caused by reservation station full) is asserted.",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NOT_DELIVERED",
        .udesc = "Counts the number of core cycles when no micro-ops are allocated, the "
                 "IQ is empty, and no other condition is blocking allocation.",
        .ucode = 0x9000,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ALL",
        .udesc = "Counts the total number of core cycles when no micro-ops are allocated "
                 "for any reason.",
        .ucode = 0x7f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ANY",
        .udesc = "Counts the total number of core cycles when no micro-ops are allocated "
                 "for any reason.",
        .uequiv = "ALL",
        .ucode = 0x7f00,
        .uflags = INTEL_X86_NCOMBO,
    },
};

static const intel_x86_umask_t knl_rs_full_stall[] = {
    {
        .uname = "MEC",
        .udesc = "Counts the number of core cycles when allocation pipeline is stalled "
                 "and is waiting for a free MEC reservation station entry.",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "ANY",
        .udesc = "Counts the total number of core cycles the Alloc pipeline is stalled "
                 "when any one of the reservation stations is full.",
        .ucode = 0x1f00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_cycles_div_busy[] = {
    {
        .uname = "ALL",
        .udesc = "Counts the number of core cycles when divider is busy.  Does not imply "
                 "a stall waiting for the divider.",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_ms_decoded[] = {
    {
        .uname = "ENTRY",
        .udesc = "Counts the number of times the MSROM starts a flow of uops.",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_umask_t knl_decode_restriction[] = {
    {
        .uname = "PREDECODE_WRONG",
        .udesc = "Number of times the prediction (from the predecode cache) for "
                 "instruction length is incorrect",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
};

static const intel_x86_entry_t intel_knl_pe[] = {
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Unhalted core cycles",
        .modmsk = INTEL_V3_ATTRS, /* any thread only supported in fixed counter */
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
        .desc = "Instructions retired (any thread modifier supported in fixed counter)",
        .modmsk = INTEL_V3_ATTRS, /* any thread only supported in fixed counter */
        .cntmsk = 0x100000003ull,
        .code = 0xc0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "This is an alias for INSTRUCTION_RETIRED (any thread modifier supported "
                "in fixed counter)",
        .modmsk = INTEL_V3_ATTRS, /* any thread only supported in fixed counter */
        .equiv = "INSTRUCTION_RETIRED",
        .cntmsk = 0x10003,
        .code = 0xc0,
    },
    {
        .name = "LLC_REFERENCES",
        .desc = "Last level of cache references",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LAST_LEVEL_CACHE_REFERENCES",
        .desc = "This is an alias for LLC_REFERENCES",
        .modmsk = INTEL_V2_ATTRS,
        .equiv = "LLC_REFERENCES",
        .cntmsk = 0x3,
        .code = 0x4f2e,
    },
    {
        .name = "LLC_MISSES",
        .desc = "Last level of cache misses",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "LAST_LEVEL_CACHE_MISSES",
        .desc = "This is an alias for LLC_MISSES",
        .modmsk = INTEL_V2_ATTRS,
        .equiv = "LLC_MISSES",
        .cntmsk = 0x3,
        .code = 0x412e,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Branch instructions retired",
        .modmsk = INTEL_V2_ATTRS,
        .equiv = "BR_INST_RETIRED:ANY",
        .cntmsk = 0x3,
        .code = 0xc4,
    },
    {
        .name = "MISPREDICTED_BRANCH_RETIRED",
        .desc = "Mispredicted branch instruction retired",
        .equiv = "BR_MISP_RETIRED:ANY",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
    },
    /* begin model specific events */
    {
        .name = "ICACHE",
        .desc = "Instruction fetches",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x80,
        .numasks = LIBPFM_ARRAY_SIZE(knl_icache),
        .ngrp = 1,
        .umasks = knl_icache,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Micro-ops retired",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc2,
        .numasks = LIBPFM_ARRAY_SIZE(knl_uops_retired),
        .ngrp = 1,
        .umasks = knl_uops_retired,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc0,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(knl_inst_retired),
        .ngrp = 1,
        .umasks = knl_inst_retired,
    },
    {
        .name = "CYCLES_DIV_BUSY",
        .desc = "Counts the number of core cycles when divider is busy.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcd,
        .numasks = LIBPFM_ARRAY_SIZE(knl_cycles_div_busy),
        .ngrp = 1,
        .umasks = knl_cycles_div_busy,
    },
    {
        .name = "RS_FULL_STALL",
        .desc = "Counts the number of core cycles when allocation pipeline is stalled.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xcb,
        .numasks = LIBPFM_ARRAY_SIZE(knl_rs_full_stall),
        .ngrp = 1,
        .umasks = knl_rs_full_stall,
    },
    {
        .name = "L2_REQUESTS",
        .desc = "L2 cache requests",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x2e,
        .numasks = LIBPFM_ARRAY_SIZE(knl_l2_rqsts),
        .ngrp = 1,
        .umasks = knl_l2_rqsts,
    },
    {
        .name = "MACHINE_CLEARS",
        .desc = "Counts the number of times that the machine clears.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc3,
        .numasks = LIBPFM_ARRAY_SIZE(knl_machine_clears),
        .ngrp = 1,
        .umasks = knl_machine_clears,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc4,
        .numasks = LIBPFM_ARRAY_SIZE(knl_br_inst_retired),
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .umasks = knl_br_inst_retired,
    },
    {
        .name = "BR_MISP_RETIRED",
        .desc = "Counts the number of mispredicted branch instructions retired.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xc5,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(knl_br_misp_retired),
        .ngrp = 1,
        .umasks = knl_br_misp_retired,
    },
    {
        .name = "MS_DECODED",
        .desc = "Number of times the MSROM starts a flow of uops.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe7,
        .numasks = LIBPFM_ARRAY_SIZE(knl_ms_decoded),
        .ngrp = 1,
        .umasks = knl_ms_decoded,
    },
    {
        .name = "FETCH_STALL",
        .desc = "Counts the number of core cycles the fetch stalls.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x86,
        .numasks = LIBPFM_ARRAY_SIZE(knl_fetch_stall),
        .ngrp = 1,
        .umasks = knl_fetch_stall,
    },
    {
        .name = "BACLEARS",
        .desc = "Branch address calculator",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xe6,
        .numasks = LIBPFM_ARRAY_SIZE(knl_baclears),
        .ngrp = 1,
        .umasks = knl_baclears,
    },
    {
        .name = "NO_ALLOC_CYCLES",
        .desc = "Front-end allocation",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0xca,
        .numasks = LIBPFM_ARRAY_SIZE(knl_no_alloc_cycles),
        .ngrp = 1,
        .umasks = knl_no_alloc_cycles,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Core cycles when core is not halted",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x3c,
        .numasks = LIBPFM_ARRAY_SIZE(knl_cpu_clk_unhalted),
        .ngrp = 1,
        .umasks = knl_cpu_clk_unhalted,
    },
    {
        .name = "MEM_UOPS_RETIRED",
        .desc = "Counts the number of load micro-ops retired.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x4,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(knl_mem_uops_retired),
        .ngrp = 1,
        .umasks = knl_mem_uops_retired,
    },
    {
        .name = "PAGE_WALKS",
        .desc = "Number of page-walks executed",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x5,
        .numasks = LIBPFM_ARRAY_SIZE(knl_page_walks),
        .ngrp = 1,
        .umasks = knl_page_walks,
    },
    {
        .name = "L2_REQUESTS_REJECT",
        .desc = "Counts the number of MEC requests from the L2Q that reference a cache "
                "line were rejected.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x30,
        .numasks = LIBPFM_ARRAY_SIZE(knl_l2_requests_reject),
        .ngrp = 1,
        .umasks = knl_l2_requests_reject,
    },
    {
        .name = "CORE_REJECT_L2Q",
        .desc = "Number of requests not accepted into the L2Q because of any L2 queue "
                "reject condition.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x31,
        .numasks = LIBPFM_ARRAY_SIZE(knl_core_reject),
        .ngrp = 1,
        .umasks = knl_core_reject,
    },
    {
        .name = "RECYCLEQ",
        .desc = "Counts the number of occurrences a retired load gets blocked.",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x3,
        .code = 0x03,
        .flags = INTEL_X86_PEBS,
        .numasks = LIBPFM_ARRAY_SIZE(knl_recycleq),
        .ngrp = 1,
        .umasks = knl_recycleq,
    },
    {
        .name = "OFFCORE_RESPONSE_0",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xf,
        .code = 0x01b7,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(knl_offcore_response_0),
        .ngrp = 3,
        .umasks = knl_offcore_response_0,
    },
    {
        .name = "OFFCORE_RESPONSE_1",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xf,
        .code = 0x02b7,
        .flags = INTEL_X86_NHM_OFFCORE,
        .numasks = LIBPFM_ARRAY_SIZE(knl_offcore_response_1),
        .ngrp = 2,
        .umasks = knl_offcore_response_1,
    },
};
