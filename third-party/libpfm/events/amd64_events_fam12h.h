/*
 * Copyright (c) 2011 University of Tennessee
 * Contributed by Vince Weaver <vweaver1@utk.edu>
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
 * PMU: amd64_fam12h (AMD64 Fam12h)
 */

static const amd64_umask_t amd64_fam12h_dispatched_fpu[] = {
    {
        .uname = "OPS_ADD",
        .udesc = "Add pipe ops excluding load ops and SSE move ops",
        .ucode = 0x1,
    },
    {
        .uname = "OPS_MULTIPLY",
        .udesc = "Multiply pipe ops excluding load ops and SSE move ops",
        .ucode = 0x2,
    },
    {
        .uname = "OPS_STORE",
        .udesc = "Store pipe ops excluding load ops and SSE move ops",
        .ucode = 0x4,
    },
    {
        .uname = "OPS_ADD_PIPE_LOAD_OPS",
        .udesc = "Add pipe load ops and SSE move ops",
        .ucode = 0x8,
    },
    {
        .uname = "OPS_MULTIPLY_PIPE_LOAD_OPS",
        .udesc = "Multiply pipe load ops and SSE move ops",
        .ucode = 0x10,
    },
    {
        .uname = "OPS_STORE_PIPE_LOAD_OPS",
        .udesc = "Store pipe load ops and SSE move ops",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_retired_sse_operations[] = {
    {
        .uname = "SINGLE_ADD_SUB_OPS",
        .udesc = "Single precision add/subtract ops",
        .ucode = 0x1,
    },
    {
        .uname = "SINGLE_MUL_OPS",
        .udesc = "Single precision multiply ops",
        .ucode = 0x2,
    },
    {
        .uname = "SINGLE_DIV_OPS",
        .udesc = "Single precision divide/square root ops",
        .ucode = 0x4,
    },
    {
        .uname = "DOUBLE_ADD_SUB_OPS",
        .udesc = "Double precision add/subtract ops",
        .ucode = 0x8,
    },
    {
        .uname = "DOUBLE_MUL_OPS",
        .udesc = "Double precision multiply ops",
        .ucode = 0x10,
    },
    {
        .uname = "DOUBLE_DIV_OPS",
        .udesc = "Double precision divide/square root ops",
        .ucode = 0x20,
    },
    {
        .uname = "OP_TYPE",
        .udesc = "Op type: 0=uops. 1=FLOPS",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_retired_move_ops[] = {
    {
        .uname = "LOW_QW_MOVE_UOPS",
        .udesc = "Merging low quadword move uops",
        .ucode = 0x1,
    },
    {
        .uname = "HIGH_QW_MOVE_UOPS",
        .udesc = "Merging high quadword move uops",
        .ucode = 0x2,
    },
    {
        .uname = "ALL_OTHER_MERGING_MOVE_UOPS",
        .udesc = "All other merging move uops",
        .ucode = 0x4,
    },
    {
        .uname = "ALL_OTHER_MOVE_UOPS",
        .udesc = "All other move uops",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_retired_serializing_ops[] = {
    {
        .uname = "SSE_BOTTOM_EXECUTING_UOPS",
        .udesc = "SSE bottom-executing uops retired",
        .ucode = 0x1,
    },
    {
        .uname = "SSE_BOTTOM_SERIALIZING_UOPS",
        .udesc = "SSE bottom-serializing uops retired",
        .ucode = 0x2,
    },
    {
        .uname = "X87_BOTTOM_EXECUTING_UOPS",
        .udesc = "X87 bottom-executing uops retired",
        .ucode = 0x4,
    },
    {
        .uname = "X87_BOTTOM_SERIALIZING_UOPS",
        .udesc = "X87 bottom-serializing uops retired",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};
static const amd64_umask_t amd64_fam12h_fp_scheduler_cycles[] = {
    {
        .uname = "BOTTOM_EXECUTE_CYCLES",
        .udesc = "Number of cycles a bottom-execute uop is in the FP scheduler",
        .ucode = 0x1,
    },
    {
        .uname = "BOTTOM_SERIALIZING_CYCLES",
        .udesc = "Number of cycles a bottom-serializing uop is in the FP scheduler",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_segment_register_loads[] = {
    {
        .uname = "ES",
        .udesc = "ES",
        .ucode = 0x1,
    },
    {
        .uname = "CS",
        .udesc = "CS",
        .ucode = 0x2,
    },
    {
        .uname = "SS",
        .udesc = "SS",
        .ucode = 0x4,
    },
    {
        .uname = "DS",
        .udesc = "DS",
        .ucode = 0x8,
    },
    {
        .uname = "FS",
        .udesc = "FS",
        .ucode = 0x10,
    },
    {
        .uname = "GS",
        .udesc = "GS",
        .ucode = 0x20,
    },
    {
        .uname = "HS",
        .udesc = "HS",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_locked_ops[] = {
    {
        .uname = "EXECUTED",
        .udesc = "The number of locked instructions executed",
        .ucode = 0x1,
    },
    {
        .uname = "CYCLES_SPECULATIVE_PHASE",
        .udesc = "The number of cycles spent in speculative phase",
        .ucode = 0x2,
    },
    {
        .uname = "CYCLES_NON_SPECULATIVE_PHASE",
        .udesc = "The number of cycles spent in non-speculative phase (including cache "
                 "miss penalty)",
        .ucode = 0x4,
    },
    {
        .uname = "CYCLES_WAITING",
        .udesc = "The number of cycles waiting for a cache hit (cache miss penalty).",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_cancelled_store_to_load_forward_operations[] = {
    {
        .uname = "ADDRESS_MISMATCHES",
        .udesc = "Address mismatches (starting byte not the same).",
        .ucode = 0x1,
    },
    {
        .uname = "STORE_IS_SMALLER_THAN_LOAD",
        .udesc = "Store is smaller than load.",
        .ucode = 0x2,
    },
    {
        .uname = "MISALIGNED",
        .udesc = "Misaligned.",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_data_cache_refills[] = {
    {
        .uname = "SYSTEM",
        .udesc = "Refill from the Northbridge",
        .ucode = 0x1,
    },
    {
        .uname = "L2_SHARED",
        .udesc = "Shared-state line from L2",
        .ucode = 0x2,
    },
    {
        .uname = "L2_EXCLUSIVE",
        .udesc = "Exclusive-state line from L2",
        .ucode = 0x4,
    },
    {
        .uname = "L2_OWNED",
        .udesc = "Owned-state line from L2",
        .ucode = 0x8,
    },
    {
        .uname = "L2_MODIFIED",
        .udesc = "Modified-state line from L2",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_data_cache_refills_from_northbridge[] = {
    {
        .uname = "INVALID",
        .udesc = "Invalid",
        .ucode = 0x1,
    },
    {
        .uname = "SHARED",
        .udesc = "Shared",
        .ucode = 0x2,
    },
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive",
        .ucode = 0x4,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned",
        .ucode = 0x8,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_data_cache_lines_evicted[] = {
    {
        .uname = "INVALID",
        .udesc = "Invalid",
        .ucode = 0x1,
    },
    {
        .uname = "SHARED",
        .udesc = "Shared",
        .ucode = 0x2,
    },
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive",
        .ucode = 0x4,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned",
        .ucode = 0x8,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified",
        .ucode = 0x10,
    },
    {
        .uname = "BY_PREFETCHNTA",
        .udesc = "Cache line evicted was brought into the cache with by a PrefetchNTA "
                 "instruction.",
        .ucode = 0x20,
    },
    {
        .uname = "NOT_BY_PREFETCHNTA",
        .udesc = "Cache line evicted was not brought into the cache with by a "
                 "PrefetchNTA instruction.",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l1_dtlb_miss_and_l2_dtlb_hit[] = {
    {
        .uname = "L2_4K_TLB_HIT",
        .udesc = "L2 4K TLB hit",
        .ucode = 0x1,
    },
    {
        .uname = "L2_2M_TLB_HIT",
        .udesc = "L2 2M TLB hit",
        .ucode = 0x2,
    },
    {
        .uname = "L2_1G_TLB_HIT",
        .udesc = "L2 1G TLB hit",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l1_dtlb_and_l2_dtlb_miss[] = {
    {
        .uname = "4K_TLB_RELOAD",
        .udesc = "4K TLB reload",
        .ucode = 0x1,
    },
    {
        .uname = "2M_TLB_RELOAD",
        .udesc = "2M TLB reload",
        .ucode = 0x2,
    },
    {
        .uname = "1G_TLB_RELOAD",
        .udesc = "1G TLB reload",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_prefetch_instructions_dispatched[] = {
    {
        .uname = "LOAD",
        .udesc = "Load (Prefetch, PrefetchT0/T1/T2)",
        .ucode = 0x1,
    },
    {
        .uname = "STORE",
        .udesc = "Store (PrefetchW)",
        .ucode = 0x2,
    },
    {
        .uname = "NTA",
        .udesc = "NTA (PrefetchNTA)",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_dcache_misses_by_locked_instructions[] = {
    {
        .uname = "DATA_CACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
        .udesc = "Data cache misses by locked instructions",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x2,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l1_dtlb_hit[] = {
    {
        .uname = "L1_4K_TLB_HIT",
        .udesc = "L1 4K TLB hit",
        .ucode = 0x1,
    },
    {
        .uname = "L1_2M_TLB_HIT",
        .udesc = "L1 2M TLB hit",
        .ucode = 0x2,
    },
    {
        .uname = "L1_1G_TLB_HIT",
        .udesc = "L1 1G TLB hit",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_ineffective_sw_prefetches[] = {
    {
        .uname = "SW_PREFETCH_HIT_IN_L1",
        .udesc = "Software prefetch hit in the L1.",
        .ucode = 0x1,
    },
    {
        .uname = "SW_PREFETCH_HIT_IN_L2",
        .udesc = "Software prefetch hit in L2.",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x9,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_requests[] = {
    {
        .uname = "NON_CACHEABLE",
        .udesc = "Requests to non-cacheable (UC) memory",
        .ucode = 0x1,
    },
    {
        .uname = "WRITE_COMBINING",
        .udesc =
            "Requests to write-combining (WC) memory or WC buffer flushes to WB memory",
        .ucode = 0x2,
    },
    {
        .uname = "CACHE_DISABLED",
        .udesc = "Requests to cache-disabled (CD) memory",
        .ucode = 0x4,
    },
    {
        .uname = "STREAMING_STORE",
        .udesc = "Streaming store (SS) requests",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x87,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_data_prefetches[] = {
    {
        .uname = "CANCELLED",
        .udesc = "Cancelled prefetches",
        .ucode = 0x1,
    },
    {
        .uname = "ATTEMPTED",
        .udesc = "Prefetch attempts",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_northbridge_read_responses[] = {
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive",
        .ucode = 0x1,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified",
        .ucode = 0x2,
    },
    {
        .uname = "SHARED",
        .udesc = "Shared",
        .ucode = 0x4,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned",
        .ucode = 0x8,
    },
    {
        .uname = "DATA_ERROR",
        .udesc = "Data Error",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_octwords_written_to_system[] = {
    {
        .uname = "OCTWORD_WRITE_TRANSFER",
        .udesc = "Octword write transfer",
        .ucode = 0x1,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_requests_to_l2[] = {
    {
        .uname = "INSTRUCTIONS",
        .udesc = "IC fill",
        .ucode = 0x1,
    },
    {
        .uname = "DATA",
        .udesc = "DC fill",
        .ucode = 0x2,
    },
    {
        .uname = "TLB_WALK",
        .udesc = "TLB fill (page table walks)",
        .ucode = 0x4,
    },
    {
        .uname = "SNOOP",
        .udesc = "Tag snoop request",
        .ucode = 0x8,
    },
    {
        .uname = "CANCELLED",
        .udesc = "Cancelled request",
        .ucode = 0x10,
    },
    {
        .uname = "HW_PREFETCH_FROM_DC",
        .udesc = "Hardware prefetch from DC",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l2_cache_miss[] = {
    {
        .uname = "INSTRUCTIONS",
        .udesc = "IC fill",
        .ucode = 0x1,
    },
    {
        .uname = "DATA",
        .udesc = "DC fill (includes possible replays, whereas EventSelect 041h does not)",
        .ucode = 0x2,
    },
    {
        .uname = "TLB_WALK",
        .udesc = "TLB page table walk",
        .ucode = 0x4,
    },
    {
        .uname = "HW_PREFETCH_FROM_DC",
        .udesc = "Hardware prefetch from DC",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l2_fill_writeback[] = {
    {
        .uname = "L2_FILLS",
        .udesc =
            "L2 fills (victims from L1 caches, TLB page table walks and data prefetches)",
        .ucode = 0x1,
    },
    {
        .uname = "L2_WRITEBACKS",
        .udesc = "L2 Writebacks to system.",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_l1_itlb_miss_and_l2_itlb_miss[] = {
    {
        .uname = "4K_PAGE_FETCHES",
        .udesc = "Instruction fetches to a 4K page.",
        .ucode = 0x1,
    },
    {
        .uname = "2M_PAGE_FETCHES",
        .udesc = "Instruction fetches to a 2M page.",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_instruction_cache_lines_invalidated[] = {
    {
        .uname = "INVALIDATING_PROBE_NO_IN_FLIGHT",
        .udesc = "Invalidating probe that did not hit any in-flight instructions.",
        .ucode = 0x1,
    },
    {
        .uname = "INVALIDATING_PROBE_ONE_OR_MORE_IN_FLIGHT",
        .udesc = "Invalidating probe that hit one or more in-flight instructions.",
        .ucode = 0x2,
    },
    {
        .uname = "SMC_NO_INFLIGHT",
        .udesc = "SMC that did not hit any in-flight instructions.",
        .ucode = 0x4,
    },
    {
        .uname = "SMC_INFLIGHT",
        .udesc = "SMC that hit one or more in-flight instructions.",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_retired_mmx_and_fp_instructions[] = {
    {
        .uname = "X87",
        .udesc = "X87 instructions",
        .ucode = 0x1,
    },
    {
        .uname = "MMX_AND_3DNOW",
        .udesc = "MMX and 3DNow! instructions",
        .ucode = 0x2,
    },
    {
        .uname = "SSE_AND_SSE2",
        .udesc = "SSE and SSE2 instructions",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_interrupt_events[] = {
    {
        .uname = "FIXED_AND_LPA",
        .udesc = "Fixed and LPA",
        .ucode = 0x1,
    },
    {
        .uname = "LPA",
        .udesc = "LPA",
        .ucode = 0x2,
    },
    {
        .uname = "SMI",
        .udesc = "SMI",
        .ucode = 0x4,
    },
    {
        .uname = "NMI",
        .udesc = "NMI",
        .ucode = 0x8,
    },
    {
        .uname = "INIT",
        .udesc = "INIT",
        .ucode = 0x10,
    },
    {
        .uname = "STARTUP",
        .udesc = "STARTUP",
        .ucode = 0x20,
    },
    {
        .uname = "INT",
        .udesc = "INT",
        .ucode = 0x40,
    },
    {
        .uname = "EOI",
        .udesc = "EOI",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_sideband_signals[] = {
    {
        .uname = "STOPGRANT",
        .udesc = "STOPGRANT",
        .ucode = 0x2,
    },
    {
        .uname = "SHUTDOWN",
        .udesc = "SHUTDOWN",
        .ucode = 0x4,
    },
    {
        .uname = "WBINVD",
        .udesc = "WBINVD",
        .ucode = 0x8,
    },
    {
        .uname = "INVD",
        .udesc = "INVD",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1e,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_fpu_exceptions[] = {
    {
        .uname = "X87_RECLASS_MICROFAULTS",
        .udesc = "X87 reclass microfaults",
        .ucode = 0x1,
    },
    {
        .uname = "SSE_RETYPE_MICROFAULTS",
        .udesc = "SSE retype microfaults",
        .ucode = 0x2,
    },
    {
        .uname = "SSE_RECLASS_MICROFAULTS",
        .udesc = "SSE reclass microfaults",
        .ucode = 0x4,
    },
    {
        .uname = "SSE_AND_X87_MICROTRAPS",
        .udesc = "SSE and x87 microtraps",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_dram_accesses_page[] = {
    {
        .uname = "DCT0_HIT",
        .udesc = "DCT0 Page hit",
        .ucode = 0x1,
    },
    {
        .uname = "DCT0_MISS",
        .udesc = "DCT0 Page Miss",
        .ucode = 0x2,
    },
    {
        .uname = "DCT0_CONFLICT",
        .udesc = "DCT0 Page Conflict",
        .ucode = 0x4,
    },
    {
        .uname = "DCT1_PAGE_HIT",
        .udesc = "DCT1 Page hit",
        .ucode = 0x8,
    },
    {
        .uname = "DCT1_PAGE_MISS",
        .udesc = "DCT1 Page Miss",
        .ucode = 0x10,
    },
    {
        .uname = "DCT1_PAGE_CONFLICT",
        .udesc = "DCT1 Page Conflict",
        .ucode = 0x20,
    },
    {
        .uname = "WRITE_REQUEST",
        .udesc = "Write request.",
        .ucode = 0x40,
    },
    {
        .uname = "READ_REQUEST",
        .udesc = "Read request.",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_controller_page_table_events[] = {
    {
        .uname = "PAGE_TABLE_OVERFLOW",
        .udesc = "Page Table Overflow",
        .ucode = 0x1,
    },
    {
        .uname = "STALE_TABLE_ENTRY_HITS",
        .udesc = "Number of stale table entry hits. (hit on a page closed too soon).",
        .ucode = 0x2,
    },
    {
        .uname = "PAGE_TABLE_IDLE_CYCLE_LIMIT_INCREMENTED",
        .udesc = "Page table idle cycle limit incremented.",
        .ucode = 0x4,
    },
    {
        .uname = "PAGE_TABLE_IDLE_CYCLE_LIMIT_DECREMENTED",
        .udesc = "Page table idle cycle limit decremented.",
        .ucode = 0x8,
    },
    {
        .uname = "PAGE_TABLE_CLOSED_INACTIVITY",
        .udesc = "Page table is closed due to row inactivity.",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_controller_slot_misses[] = {
    {
        .uname = "DCT0_RBD",
        .udesc = "DCT0 RBD.",
        .ucode = 0x10,
    },
    {
        .uname = "DCT1_RBD",
        .udesc = "DCT1 RBD.",
        .ucode = 0x20,
    },
    {
        .uname = "DCT0_PREFETCH",
        .udesc = "DCT0 Prefetch.",
        .ucode = 0x40,
    },
    {
        .uname = "DCT1_PREFETCH",
        .udesc = "DCT1 Prefetch.",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf0,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_controller_turnarounds[] = {
    {
        .uname = "DCT0_READ_TO_WRITE",
        .udesc = "DCT0 read-to-write turnaround.",
        .ucode = 0x1,
    },
    {
        .uname = "DCT0_WRITE_TO_READ",
        .udesc = "DCT0 write-to-read turnaround",
        .ucode = 0x2,
    },
    {
        .uname = "DCT1_READ_TO_WRITE",
        .udesc = "DCT1 read-to-write turnaround.",
        .ucode = 0x8,
    },
    {
        .uname = "DCT1_WRITE_TO_READ",
        .udesc = "DCT1 write-to-read turnaround",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1b,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_rbd_queue[] = {
    {
        .uname = "COUNTER_REACHED",
        .udesc = "D18F2x[1,0]94[DcqBypassMax] counter reached.",
        .ucode = 0x4,
    },
    {
        .uname = "BANK_CLOSED",
        .udesc = "Bank is closed due to bank conflict with an outstanding request in the "
                 "RBD queue.",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xc,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_thermal_status[] = {
    {
        .uname = "MEMHOT_L_ASSERTIONS",
        .udesc = "MEMHOT_L assertions.",
        .ucode = 0x1,
    },
    {
        .uname = "HTC_TRANSITIONS",
        .udesc = "Number of times the HTC transitions from inactive to active.",
        .ucode = 0x4,
    },
    {
        .uname = "CLOCKS_HTC_P_STATE_INACTIVE",
        .udesc = "Number of clocks HTC P-state is inactive.",
        .ucode = 0x20,
    },
    {
        .uname = "CLOCKS_HTC_P_STATE_ACTIVE",
        .udesc = "Number of clocks HTC P-state is active",
        .ucode = 0x40,
    },
    {
        .uname = "PROCHOT_L_ASSERTIONS",
        .udesc = "PROCHOT_L asserted by an external source and the assertion causes a "
                 "P-state change.",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xe5,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_cpu_io_requests_to_memory_io[] = {
    {
        .uname = "I_O_TO_I_O",
        .udesc = "IO to IO",
        .ucode = 0x1,
    },
    {
        .uname = "I_O_TO_MEM",
        .udesc = "IO to Mem",
        .ucode = 0x2,
    },
    {
        .uname = "CPU_TO_I_O",
        .udesc = "CPU to IO",
        .ucode = 0x4,
    },
    {
        .uname = "CPU_TO_MEM",
        .udesc = "CPU to Mem",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x0f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_cache_block[] = {
    {
        .uname = "VICTIM_WRITEBACK",
        .udesc = "Victim Block (Writeback)",
        .ucode = 0x1,
    },
    {
        .uname = "DCACHE_LOAD_MISS",
        .udesc = "Read Block (Dcache load miss refill)",
        .ucode = 0x4,
    },
    {
        .uname = "SHARED_ICACHE_REFILL",
        .udesc = "Read Block Shared (Icache refill)",
        .ucode = 0x8,
    },
    {
        .uname = "READ_BLOCK_MODIFIED",
        .udesc = "Read Block Modified (Dcache store miss refill)",
        .ucode = 0x10,
    },
    {
        .uname = "READ_TO_DIRTY",
        .udesc = "Change-to-Dirty (first store to clean block already in cache)",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3d,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_sized_commands[] = {
    {
        .uname = "NON_POSTED_WRITE_BYTE",
        .udesc =
            "Non-Posted SzWr Byte (1-32 bytes) Legacy or mapped IO, typically 1-4 bytes",
        .ucode = 0x1,
    },
    {
        .uname = "NON_POSTED_WRITE_DWORD",
        .udesc =
            "Non-Posted SzWr DW (1-16 dwords) Legacy or mapped IO, typically 1 DWORD",
        .ucode = 0x2,
    },
    {
        .uname = "POSTED_WRITE_BYTE",
        .udesc = "Posted SzWr Byte (1-32 bytes) Subcache-line DMA writes, size varies; "
                 "also flushes of partially-filled Write Combining buffer",
        .ucode = 0x4,
    },
    {
        .uname = "POSTED_WRITE_DWORD",
        .udesc = "Posted SzWr DW (1-16 dwords) Block-oriented DMA writes, often "
                 "cache-line sized; also processor Write Combining buffer flushes",
        .ucode = 0x8,
    },
    {
        .uname = "READ_BYTE_4_BYTES",
        .udesc = "SzRd Byte (4 bytes) Legacy or mapped IO",
        .ucode = 0x10,
    },
    {
        .uname = "READ_DWORD_1_16_DWORDS",
        .udesc =
            "SzRd DW (1-16 dwords) Block-oriented DMA reads, typically cache-line size",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_probe[] = {
    {
        .uname = "MISS",
        .udesc = "Probe miss",
        .ucode = 0x1,
    },
    {
        .uname = "HIT_CLEAN",
        .udesc = "Probe hit clean",
        .ucode = 0x2,
    },
    {
        .uname = "HIT_DIRTY_NO_MEMORY_CANCEL",
        .udesc = "Probe hit dirty without memory cancel (probed by Sized Write or "
                 "Change2Dirty)",
        .ucode = 0x4,
    },
    {
        .uname = "HIT_DIRTY_WITH_MEMORY_CANCEL",
        .udesc = "Probe hit dirty with memory cancel (probed by DMA read or cache refill "
                 "request)",
        .ucode = 0x8,
    },
    {
        .uname = "UPSTREAM_HIGH_PRIORITY_READS",
        .udesc = "Upstream high priority reads.",
        .ucode = 0x10,
    },
    {
        .uname = "UPSTREAM_LOW_PRIORITY_READS",
        .udesc = "Upstream low priority reads.",
        .ucode = 0x20,
    },
    {
        .uname = "UPSTREAM_LOW_PRIORITY_WRITES",
        .udesc = "Upstream low priority writes.",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xbf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_dev[] = {
    {
        .uname = "DEV_HIT",
        .udesc = "DEV hit",
        .ucode = 0x10,
    },
    {
        .uname = "DEV_MISS",
        .udesc = "DEV miss",
        .ucode = 0x20,
    },
    {
        .uname = "DEV_ERROR",
        .udesc = "DEV error",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x70,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_memory_controller_requests[] = {
    {
        .uname = "32_BYTES_WRITES",
        .udesc = "32 Bytes Sized Writes",
        .ucode = 0x8,
    },
    {
        .uname = "64_BYTES_WRITES",
        .udesc = "64 Bytes Sized Writes",
        .ucode = 0x10,
    },
    {
        .uname = "32_BYTES_READS",
        .udesc = "32 Bytes Sized Reads",
        .ucode = 0x20,
    },
    {
        .uname = "64_BYTES_READS",
        .udesc = "64 Byte Sized Reads",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x78,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam12h_page_size_mismatches[] = {
    {
        .uname = "GUEST_LARGER",
        .udesc = "Guest page size is larger than the host page size.",
        .ucode = 0x1,
    },
    {
        .uname = "MTRR_MISMATCH",
        .udesc = "MTRR mismatch.",
        .ucode = 0x2,
    },
    {
        .uname = "HOST_LARGER",
        .udesc = "Host page size is larger than the guest page size.",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};
static const amd64_umask_t amd64_fam12h_retired_x87_ops[] = {
    {
        .uname = "ADD_SUB_OPS",
        .udesc = "Add/subtract ops",
        .ucode = 0x1,
    },
    {
        .uname = "MUL_OPS",
        .udesc = "Multiply ops",
        .ucode = 0x2,
    },
    {
        .uname = "DIV_OPS",
        .udesc = "Divide ops",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_entry_t amd64_fam12h_pe[] = {
    {
        .name = "DISPATCHED_FPU",
        .desc = "Dispatched FPU Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_dispatched_fpu),
        .ngrp = 1,
        .umasks = amd64_fam12h_dispatched_fpu,
    },
    {
        .name = "CYCLES_NO_FPU_OPS_RETIRED",
        .desc = "Cycles in which the FPU is Empty",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1,
    },
    {
        .name = "DISPATCHED_FPU_OPS_FAST_FLAG",
        .desc = "Dispatched Fast Flag FPU Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x2,
    },
    {
        .name = "RETIRED_SSE_OPERATIONS",
        .desc = "Retired SSE Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x3,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_retired_sse_operations),
        .ngrp = 1,
        .umasks = amd64_fam12h_retired_sse_operations,
    },
    {
        .name = "RETIRED_MOVE_OPS",
        .desc = "Retired Move Ops",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_retired_move_ops),
        .ngrp = 1,
        .umasks = amd64_fam12h_retired_move_ops,
    },
    {
        .name = "RETIRED_SERIALIZING_OPS",
        .desc = "Retired Serializing Ops",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x5,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_retired_serializing_ops),
        .ngrp = 1,
        .umasks = amd64_fam12h_retired_serializing_ops,
    },
    {
        .name = "FP_SCHEDULER_CYCLES",
        .desc = "Number of Cycles that a Serializing uop is in the FP Scheduler",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x6,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_fp_scheduler_cycles),
        .ngrp = 1,
        .umasks = amd64_fam12h_fp_scheduler_cycles,
    },
    {
        .name = "SEGMENT_REGISTER_LOADS",
        .desc = "Segment Register Loads",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x20,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_segment_register_loads),
        .ngrp = 1,
        .umasks = amd64_fam12h_segment_register_loads,
    },
    {
        .name = "PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE",
        .desc = "Pipeline Restart Due to Self-Modifying Code",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x21,
    },
    {
        .name = "PIPELINE_RESTART_DUE_TO_PROBE_HIT",
        .desc = "Pipeline Restart Due to Probe Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x22,
    },
    {
        .name = "LS_BUFFER_2_FULL_CYCLES",
        .desc = "LS Buffer 2 Full",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x23,
    },
    {
        .name = "LOCKED_OPS",
        .desc = "Locked Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_locked_ops),
        .ngrp = 1,
        .umasks = amd64_fam12h_locked_ops,
    },
    {
        .name = "RETIRED_CLFLUSH_INSTRUCTIONS",
        .desc = "Retired CLFLUSH Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x26,
    },
    {
        .name = "RETIRED_CPUID_INSTRUCTIONS",
        .desc = "Retired CPUID Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x27,
    },
    {
        .name = "CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS",
        .desc = "Cancelled Store to Load Forward Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x2a,
        .numasks =
            LIBPFM_ARRAY_SIZE(amd64_fam12h_cancelled_store_to_load_forward_operations),
        .ngrp = 1,
        .umasks = amd64_fam12h_cancelled_store_to_load_forward_operations,
    },
    {
        .name = "SMIS_RECEIVED",
        .desc = "SMIs Received",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x2b,
    },
    {
        .name = "DATA_CACHE_ACCESSES",
        .desc = "Data Cache Accesses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x40,
    },
    {
        .name = "DATA_CACHE_MISSES",
        .desc = "Data Cache Misses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x41,
    },
    {
        .name = "DATA_CACHE_REFILLS",
        .desc = "Data Cache Refills from L2 or Northbridge",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x42,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_data_cache_refills),
        .ngrp = 1,
        .umasks = amd64_fam12h_data_cache_refills,
    },
    {
        .name = "DATA_CACHE_REFILLS_FROM_SYSTEM",
        .desc = "Data Cache Refills from the Northbridge",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x43,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_data_cache_refills_from_northbridge),
        .ngrp = 1,
        .umasks = amd64_fam12h_data_cache_refills_from_northbridge,
    },
    {
        .name = "DATA_CACHE_LINES_EVICTED",
        .desc = "Data Cache Lines Evicted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x44,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_data_cache_lines_evicted),
        .ngrp = 1,
        .umasks = amd64_fam12h_data_cache_lines_evicted,
    },
    {
        .name = "L1_DTLB_MISS_AND_L2_DTLB_HIT",
        .desc = "L1 DTLB Miss and L2 DTLB Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x45,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l1_dtlb_miss_and_l2_dtlb_hit),
        .ngrp = 1,
        .umasks = amd64_fam12h_l1_dtlb_miss_and_l2_dtlb_hit,
    },
    {
        .name = "L1_DTLB_AND_L2_DTLB_MISS",
        .desc = "L1 DTLB and L2 DTLB Miss",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x46,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l1_dtlb_and_l2_dtlb_miss),
        .ngrp = 1,
        .umasks = amd64_fam12h_l1_dtlb_and_l2_dtlb_miss,
    },
    {
        .name = "MISALIGNED_ACCESSES",
        .desc = "Misaligned Accesses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x47,
    },
    {
        .name = "MICROARCHITECTURAL_LATE_CANCEL_OF_AN_ACCESS",
        .desc = "Microarchitectural Late Cancel of an Access",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x48,
    },
    {
        .name = "MICROARCHITECTURAL_EARLY_CANCEL_OF_AN_ACCESS",
        .desc = "Microarchitectural Early Cancel of an Access",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x49,
    },
    {
        .name = "PREFETCH_INSTRUCTIONS_DISPATCHED",
        .desc = "Prefetch Instructions Dispatched",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4b,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_prefetch_instructions_dispatched),
        .ngrp = 1,
        .umasks = amd64_fam12h_prefetch_instructions_dispatched,
    },
    {
        .name = "DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
        .desc = "DCACHE Misses by Locked Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4c,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_dcache_misses_by_locked_instructions),
        .ngrp = 1,
        .umasks = amd64_fam12h_dcache_misses_by_locked_instructions,
    },
    {
        .name = "L1_DTLB_HIT",
        .desc = "L1 DTLB Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4d,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l1_dtlb_hit),
        .ngrp = 1,
        .umasks = amd64_fam12h_l1_dtlb_hit,
    },
    {
        .name = "INEFFECTIVE_SW_PREFETCHES",
        .desc = "Ineffective Software Prefetches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x52,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_ineffective_sw_prefetches),
        .ngrp = 1,
        .umasks = amd64_fam12h_ineffective_sw_prefetches,
    },
    {
        .name = "GLOBAL_TLB_FLUSHES",
        .desc = "Global TLB Flushes",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x54,
    },
    {
        .name = "MEMORY_REQUESTS",
        .desc = "Memory Requests by Type",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x65,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_requests),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_requests,
    },
    {
        .name = "DATA_PREFETCHES",
        .desc = "Data Prefetcher",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x67,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_data_prefetches),
        .ngrp = 1,
        .umasks = amd64_fam12h_data_prefetches,
    },
    {
        .name = "NORTHBRIDGE_READ_RESPONSES",
        .desc = "Northbridge Read Responses by Coherency State",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x6c,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_northbridge_read_responses),
        .ngrp = 1,
        .umasks = amd64_fam12h_northbridge_read_responses,
    },
    {
        .name = "OCTWORDS_WRITTEN_TO_SYSTEM",
        .desc = "Octwords Written to System",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x6d,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_octwords_written_to_system),
        .ngrp = 1,
        .umasks = amd64_fam12h_octwords_written_to_system,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "CPU Clocks not Halted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x76,
    },
    {
        .name = "REQUESTS_TO_L2",
        .desc = "Requests to L2 Cache",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x7d,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_requests_to_l2),
        .ngrp = 1,
        .umasks = amd64_fam12h_requests_to_l2,
    },
    {
        .name = "L2_CACHE_MISS",
        .desc = "L2 Cache Misses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x7e,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l2_cache_miss),
        .ngrp = 1,
        .umasks = amd64_fam12h_l2_cache_miss,
    },
    {
        .name = "L2_FILL_WRITEBACK",
        .desc = "L2 Fill/Writeback",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x7f,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l2_fill_writeback),
        .ngrp = 1,
        .umasks = amd64_fam12h_l2_fill_writeback,
    },
    {
        .name = "PAGE_SIZE_MISMATCHES",
        .desc = "Page Size Mismatches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x165,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_page_size_mismatches),
        .ngrp = 1,
        .umasks = amd64_fam12h_page_size_mismatches,
    },
    {
        .name = "INSTRUCTION_CACHE_FETCHES",
        .desc = "Instruction Cache Fetches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x80,
    },
    {
        .name = "INSTRUCTION_CACHE_MISSES",
        .desc = "Instruction Cache Misses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x81,
    },
    {
        .name = "INSTRUCTION_CACHE_REFILLS_FROM_L2",
        .desc = "Instruction Cache Refills from L2",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x82,
    },
    {
        .name = "INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM",
        .desc = "Instruction Cache Refills from System",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x83,
    },
    {
        .name = "L1_ITLB_MISS_AND_L2_ITLB_HIT",
        .desc = "L1 ITLB Miss and L2 ITLB Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x84,
    },
    {
        .name = "L1_ITLB_MISS_AND_L2_ITLB_MISS",
        .desc = "L1 ITLB Miss and L2 ITLB Miss",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x85,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_l1_itlb_miss_and_l2_itlb_miss),
        .ngrp = 1,
        .umasks = amd64_fam12h_l1_itlb_miss_and_l2_itlb_miss,
    },
    {
        .name = "PIPELINE_RESTART_DUE_TO_INSTRUCTION_STREAM_PROBE",
        .desc = "Pipeline Restart Due to Instruction Stream Probe",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x86,
    },
    {
        .name = "INSTRUCTION_FETCH_STALL",
        .desc = "Instruction Fetch Stall",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x87,
    },
    {
        .name = "RETURN_STACK_HITS",
        .desc = "Return Stack Hits",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x88,
    },
    {
        .name = "RETURN_STACK_OVERFLOWS",
        .desc = "Return Stack Overflows",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x89,
    },
    {
        .name = "INSTRUCTION_CACHE_VICTIMS",
        .desc = "Instruction Cache Victims",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x8b,
    },
    {
        .name = "INSTRUCTION_CACHE_LINES_INVALIDATED",
        .desc = "Instruction Cache Lines Invalidated",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x8c,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_instruction_cache_lines_invalidated),
        .ngrp = 1,
        .umasks = amd64_fam12h_instruction_cache_lines_invalidated,
    },
    {
        .name = "ITLB_RELOADS",
        .desc = "ITLB Reloads",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x99,
    },
    {
        .name = "ITLB_RELOADS_ABORTED",
        .desc = "ITLB Reloads Aborted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x9a,
    },
    {
        .name = "RETIRED_INSTRUCTIONS",
        .desc = "Retired Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc0,
    },
    {
        .name = "RETIRED_UOPS",
        .desc = "Retired uops",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc1,
    },
    {
        .name = "RETIRED_BRANCH_INSTRUCTIONS",
        .desc = "Retired Branch Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc2,
    },
    {
        .name = "RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS",
        .desc = "Retired Mispredicted Branch Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc3,
    },
    {
        .name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS",
        .desc = "Retired Taken Branch Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc4,
    },
    {
        .name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED",
        .desc = "Retired Taken Branch Instructions Mispredicted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc5,
    },
    {
        .name = "RETIRED_FAR_CONTROL_TRANSFERS",
        .desc = "Retired Far Control Transfers",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc6,
    },
    {
        .name = "RETIRED_BRANCH_RESYNCS",
        .desc = "Retired Branch Resyncs",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc7,
    },
    {
        .name = "RETIRED_NEAR_RETURNS",
        .desc = "Retired Near Returns",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc8,
    },
    {
        .name = "RETIRED_NEAR_RETURNS_MISPREDICTED",
        .desc = "Retired Near Returns Mispredicted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xc9,
    },
    {
        .name = "RETIRED_INDIRECT_BRANCHES_MISPREDICTED",
        .desc = "Retired Indirect Branches Mispredicted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xca,
    },
    {
        .name = "RETIRED_MMX_AND_FP_INSTRUCTIONS",
        .desc = "Retired MMX/FP Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xcb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_retired_mmx_and_fp_instructions),
        .ngrp = 1,
        .umasks = amd64_fam12h_retired_mmx_and_fp_instructions,
    },
    {
        .name = "INTERRUPTS_MASKED_CYCLES",
        .desc = "Interrupts-Masked Cycles",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xcd,
    },
    {
        .name = "INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING",
        .desc = "Interrupts-Masked Cycles with Interrupt Pending",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xce,
    },
    {
        .name = "INTERRUPTS_TAKEN",
        .desc = "Interrupts Taken",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xcf,
    },
    {
        .name = "DECODER_EMPTY",
        .desc = "Decoder Empty",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd0,
    },
    {
        .name = "DISPATCH_STALLS",
        .desc = "Dispatch Stalls",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd1,
    },
    {
        .name = "DISPATCH_STALL_FOR_BRANCH_ABORT",
        .desc = "Dispatch Stall for Branch Abort to Retire",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd2,
    },
    {
        .name = "DISPATCH_STALL_FOR_SERIALIZATION",
        .desc = "Dispatch Stall for Serialization",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd3,
    },
    {
        .name = "DISPATCH_STALL_FOR_SEGMENT_LOAD",
        .desc = "Dispatch Stall for Segment Load",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd4,
    },
    {
        .name = "DISPATCH_STALL_FOR_REORDER_BUFFER_FULL",
        .desc = "Dispatch Stall for Reorder Buffer Full",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd5,
    },
    {
        .name = "DISPATCH_STALL_FOR_RESERVATION_STATION_FULL",
        .desc = "Dispatch Stall for Reservation Station Full",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd6,
    },
    {
        .name = "DISPATCH_STALL_FOR_FPU_FULL",
        .desc = "Dispatch Stall for FPU Full",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd7,
    },
    {
        .name = "DISPATCH_STALL_FOR_LS_FULL",
        .desc = "Dispatch Stall for LS Full",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd8,
    },
    {
        .name = "DISPATCH_STALL_WAITING_FOR_ALL_QUIET",
        .desc = "Dispatch Stall Waiting for All Quiet",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xd9,
    },
    {
        .name = "DISPATCH_STALL_FOR_FAR_TRANSFER_OR_RSYNC",
        .desc = "Dispatch Stall for Far Transfer or Resync to Retire",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xda,
    },
    {
        .name = "FPU_EXCEPTIONS",
        .desc = "FPU Exceptions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xdb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_fpu_exceptions),
        .ngrp = 1,
        .umasks = amd64_fam12h_fpu_exceptions,
    },
    {
        .name = "DR0_BREAKPOINT_MATCHES",
        .desc = "DR0 Breakpoint Matches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xdc,
    },
    {
        .name = "DR1_BREAKPOINT_MATCHES",
        .desc = "DR1 Breakpoint Matches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xdd,
    },
    {
        .name = "DR2_BREAKPOINT_MATCHES",
        .desc = "DR2 Breakpoint Matches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xde,
    },
    {
        .name = "DR3_BREAKPOINT_MATCHES",
        .desc = "DR3 Breakpoint Matches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xdf,
    },
    {
        .name = "RETIRED_X87_OPS",
        .desc = "Retired x87 Floating Point Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1c0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_retired_x87_ops),
        .ngrp = 1,
        .umasks = amd64_fam12h_retired_x87_ops,
    },
    {
        .name = "LFENCE_INST_RETIRED",
        .desc = "LFENCE Instructions Retired",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1d3,
    },
    {
        .name = "SFENCE_INST_RETIRED",
        .desc = "SFENCE Instructions Retired",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1d4,
    },
    {
        .name = "MFENCE_INST_RETIRED",
        .desc = "MFENCE Instructions Retired",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1d5,
    },
    {
        .name = "DRAM_ACCESSES_PAGE",
        .desc = "DRAM Accesses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_dram_accesses_page),
        .ngrp = 1,
        .umasks = amd64_fam12h_dram_accesses_page,
    },
    {
        .name = "MEMORY_CONTROLLER_0_PAGE",
        .desc = "DRAM Controller 0 Page Table Events",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe1,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_controller_page_table_events),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_controller_page_table_events,
    },
    {
        .name = "MEMORY_CONTROLLER_SLOT_MISSES",
        .desc = "Memory Controller DRAM Command Slots Missed",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe2,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_controller_slot_misses),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_controller_slot_misses,
    },
    {
        .name = "MEMORY_CONTROLLER_TURNAROUNDS",
        .desc = "Memory Controller Turnarounds",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe3,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_controller_turnarounds),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_controller_turnarounds,
    },
    {
        .name = "MEMORY_CONTROLLER_RBD_QUEUE",
        .desc = "Memory Controller RBD Queue Events",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe4,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_rbd_queue),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_rbd_queue,
    },
    {
        .name = "MEMORY_CONTROLLER_1_PAGE",
        .desc = "DRAM Controller 1 Page Table Events",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe5,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_controller_page_table_events),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_controller_page_table_events,
    },
    {
        .name = "THERMAL_STATUS",
        .desc = "Thermal Status",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe8,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_thermal_status),
        .ngrp = 1,
        .umasks = amd64_fam12h_thermal_status,
    },
    {
        .name = "CPU_IO_REQUESTS_TO_MEMORY_IO",
        .desc = "CPU/IO Requests to Memory/IO",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xe9,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_cpu_io_requests_to_memory_io),
        .ngrp = 1,
        .umasks = amd64_fam12h_cpu_io_requests_to_memory_io,
    },
    {
        .name = "CACHE_BLOCK",
        .desc = "Cache Block Commands",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xea,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_cache_block),
        .ngrp = 1,
        .umasks = amd64_fam12h_cache_block,
    },
    {
        .name = "SIZED_COMMANDS",
        .desc = "Sized Commands",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xeb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_sized_commands),
        .ngrp = 1,
        .umasks = amd64_fam12h_sized_commands,
    },
    {
        .name = "PROBE",
        .desc = "Probe Responses and Upstream Requests",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xec,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_probe),
        .ngrp = 1,
        .umasks = amd64_fam12h_probe,
    },
    {
        .name = "DEV",
        .desc = "DEV Events",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xee,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_dev),
        .ngrp = 1,
        .umasks = amd64_fam12h_dev,
    },
    {
        .name = "MEMORY_CONTROLLER_REQUESTS",
        .desc = "Memory Controller Requests",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1f0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_memory_controller_requests),
        .ngrp = 1,
        .umasks = amd64_fam12h_memory_controller_requests,
    },
    {
        .name = "SIDEBAND_SIGNALS",
        .desc = "Sideband Signals and Special Cycles",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1e9,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_sideband_signals),
        .ngrp = 1,
        .umasks = amd64_fam12h_sideband_signals,
    },
    {
        .name = "INTERRUPT_EVENTS",
        .desc = "Interrupt Events",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1ea,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam12h_interrupt_events),
        .ngrp = 1,
        .umasks = amd64_fam12h_interrupt_events,
    },
};
