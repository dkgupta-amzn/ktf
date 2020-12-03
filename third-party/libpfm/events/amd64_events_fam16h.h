/*
 * Copyright (c) 2017 by Vince Weaver <vincent.weaver@maine.edu>
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
 * PMU: amd64_fam16h (AMD64 Fam16h)
 */

/* Dispatched FPU 0x0 */
static const amd64_umask_t amd64_fam16h_dispatched_fpu[] = {
    {
        .uname = "PIPE0",
        .udesc = "Pipe0 dispatches",
        .ucode = 0x1,
    },
    {
        .uname = "PIPE1",
        .udesc = "Pipe1 dispatches",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Retired SSE/AVX 0x03 */
static const amd64_umask_t amd64_fam16h_retired_sse_operations[] = {
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
        .ucode = 0x10,
    },
    {
        .uname = "DOUBLE_MUL_OPS",
        .udesc = "Double precision multiply ops",
        .ucode = 0x20,
    },
    {
        .uname = "DOUBLE_DIV_OPS",
        .udesc = "Double precision divide/square root ops",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Retired serializing ops 0x05 */
static const amd64_umask_t amd64_fam16h_retired_serializing_ops[] = {
    {
        .uname = "SSE_BOTTOM_EXECUTING_UOPS",
        .udesc = "SSE bottom-executing uops retired",
        .ucode = 0x1,
    },
    {
        .uname = "SSE_CONTROL_RENAMING_UOPS",
        .udesc = "SSE control-renaming uops retired",
        .ucode = 0x2,
    },
    {
        .uname = "X87_BOTTOM_EXECUTING_UOPS",
        .udesc = "X87 bottom-executing uops retired",
        .ucode = 0x4,
    },
    {
        .uname = "X87_CONTROL_RENAMING_UOPS",
        .udesc = "X87 control-renaming uops retired",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Retired x87 ops 0x11 */
static const amd64_umask_t amd64_fam16h_retired_x87_ops[] = {
    {
        .uname = "ADD_AND_SUB",
        .udesc = "Add and subtract",
        .ucode = 0x1,
    },
    {
        .uname = "MULTIPLY",
        .udesc = "Multiply",
        .ucode = 0x2,
    },
    {
        .uname = "DIVIDE_AND_FSQRT",
        .udesc = "Divide and fsqrt",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Segment Register Loads 0x20 */
static const amd64_umask_t amd64_fam16h_segment_register_loads[] = {
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

/* Pipeline Restart 0x21 */
static const amd64_umask_t amd64_fam16h_pipeline_restart[] = {
    {
        .uname = "INVALIDATING_PROBES",
        .udesc = "Evictions caused by invalidating probes",
        .ucode = 0x1,
    },
    {
        .uname = "FILLS",
        .udesc = "Evictions caused by fills",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Locked Operations 0x24 */
static const amd64_umask_t amd64_fam16h_locked_ops[] = {
    {
        .uname = "EXECUTED",
        .udesc = "The number of locked instructions executed",
        .ucode = 0x1,
    },
    {
        .uname = "CYCLES_TO_ACQUIRE",
        .udesc = "The number of cycles to acquire bus lock",
        .ucode = 0x2,
    },
    {
        .uname = "CYCLES_TO_UNLOCK",
        .udesc = "The number of cycles to unlock cache line",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* LS Dispatch 0x29 */
static const amd64_umask_t amd64_fam16h_ls_dispatch[] = {
    {
        .uname = "LOADS",
        .udesc = "The number of loads",
        .ucode = 0x1,
    },
    {
        .uname = "STORES",
        .udesc = "The number of stores",
        .ucode = 0x2,
    },
    {
        .uname = "LOAD_OP_STORES",
        .udesc = "The number of load-op-stores",
        .ucode = 0x4,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Cancells Store to Load 0x2a */
static const amd64_umask_t amd64_fam16h_cancelled_store_to_load_forward_operations[] = {
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

/* Data cache refills 0x42 */
static const amd64_umask_t amd64_fam16h_data_cache_refills[] = {
    {
        .uname = "NON_CACHABLE",
        .udesc = "Non-cachable",
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

/* Cache refills from northbridge 0x43 */
static const amd64_umask_t amd64_fam16h_data_cache_refills_from_system[] = {
    {
        .uname = "NON_CACHABLE",
        .udesc = "non-cachable",
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

/* Data cache lines evicted 0x44 */
static const amd64_umask_t amd64_fam16h_data_cache_lines_evicted[] = {
    {
        .uname = "EVICTED",
        .udesc = "Evicted from probe",
        .ucode = 0x1,
    },
    {
        .uname = "SHARED",
        .udesc = "Shared eviction",
        .ucode = 0x2,
    },
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive eviction",
        .ucode = 0x4,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned eviction",
        .ucode = 0x8,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified eviction",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x1f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* DTLB Miss 0x46 */
static const amd64_umask_t amd64_fam16h_dtlb_miss[] = {
    {
        .uname = "STORES_L1TLB",
        .udesc = "Stores that miss L1TLB",
        .ucode = 0x1,
    },
    {
        .uname = "LOADS_L1TLB",
        .udesc = "Loads that miss L1TLB",
        .ucode = 0x2,
    },
    {
        .uname = "STORES_L2TLB",
        .udesc = "Stores that miss L2TLB",
        .ucode = 0x4,
    },
    {
        .uname = "LOADS_L2TLB",
        .udesc = "Loads that miss L2TLB",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Misaligned accesses 0x47 */
static const amd64_umask_t amd64_fam16h_misaligned_accesses[] = {
    {
        .uname = "MISALIGN_16B",
        .udesc = "Misaligns that cross 16 Byte boundary",
        .ucode = 0x1,
    },
    {
        .uname = "MISALIGN_4KB",
        .udesc = "Misaligns that cross a 4kB boundary",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Prefetch Instruction Dispatched 0x4b */
static const amd64_umask_t amd64_fam16h_prefetch_instructions_dispatched[] = {
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

/* L1 DTLB Hit 0x4d */
static const amd64_umask_t amd64_fam16h_l1_dtlb_hit[] = {
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
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Ineffective SW Prefetch 0x52 */
static const amd64_umask_t amd64_fam16h_ineffective_sw_prefetches[] = {
    {
        .uname = "SW_PREFETCH_DATA_CACHE",
        .udesc = "Software prefetch hit in data cache",
        .ucode = 0x1,
    },
    {
        .uname = "SW_PREFETCH_PENDING_FILL",
        .udesc = "Software prefetch hit a pending fill",
        .ucode = 0x2,
    },
    {
        .uname = "SW_PREFETCH_MAB",
        .udesc = "Software prefetches that don't get a MAB",
        .ucode = 0x4,
    },
    {
        .uname = "SW_PREFETCH_HIT_L2",
        .udesc = "Software prefetches that hit in L2",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Uncachable Memory 0x61 */
static const amd64_umask_t amd64_fam16h_uncachable_memory[] = {
    {
        .uname = "READ_BYTE",
        .udesc = "Read byte",
        .ucode = 0x1,
    },
    {
        .uname = "READ_DOUBLEWORD",
        .udesc = "Read doubleword",
        .ucode = 0x2,
    },
    {
        .uname = "WRITE_BYTE",
        .udesc = "Write byte",
        .ucode = 0x10,
    },
    {
        .uname = "WRITE_DOUBLEWORD",
        .udesc = "Write doubleword",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x33,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Read Block Operations 0x62 */
static const amd64_umask_t amd64_fam16h_read_block[] = {
    {
        .uname = "READ_BLOCK",
        .udesc = "Read block",
        .ucode = 0x1,
    },
    {
        .uname = "RDBLKMOD",
        .udesc = "RdBlkMod",
        .ucode = 0x2,
    },
    {
        .uname = "READ_BLOCK_SHARED",
        .udesc = "Read block shared",
        .ucode = 0x4,
    },
    {
        .uname = "READ_BLOCK_SPEC",
        .udesc = "Read block speculative",
        .ucode = 0x10,
    },
    {
        .uname = "READ_BLOCK_SPEC_MOD",
        .udesc = "Read block speculative modified",
        .ucode = 0x20,
    },
    {
        .uname = "READ_BLOCK_SPEC_SHARED",
        .udesc = "Read block speculative shared",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x77,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Change to Dirty 0x63 */
static const amd64_umask_t amd64_fam16h_change_dirty[] = {
    {
        .uname = "CHANGE_DIRTY",
        .udesc = "Change to dirty",
        .ucode = 0x10,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x10,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Memory Requests 0x65 */
static const amd64_umask_t amd64_fam16h_memory_requests[] = {
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
        .uname = "STREAMING_STORE",
        .udesc = "Streaming store (SS) requests",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x83,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Data Cache Prefetches 0x67 */
static const amd64_umask_t amd64_fam16h_data_prefetches[] = {
    {
        .uname = "ATTEMPTED",
        .udesc = "Prefetch attempts",
        .ucode = 0x2,
    },
    {
        .uname = "MAB",
        .udesc = "Hits on MAB",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xa,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* MAB Requests 0x68 and 0x69 */
static const amd64_umask_t amd64_fam16h_mab_requests[] = {
    {
        .uname = "DC_MISS0",
        .udesc = "Data cache miss buffer 0",
        .ucode = 0x1,
    },
    {
        .uname = "DC_MISS1",
        .udesc = "Data cache miss buffer 1",
        .ucode = 0x2,
    },
    {
        .uname = "DC_MISS2",
        .udesc = "Data cache miss buffer 2",
        .ucode = 0x4,
    },
    {
        .uname = "DC_MISS3",
        .udesc = "Data cache miss buffer 3",
        .ucode = 0x8,
    },
    {
        .uname = "DC_MISS4",
        .udesc = "Data cache miss buffer 4",
        .ucode = 0x10,
    },
    {
        .uname = "DC_MISS5",
        .udesc = "Data cache miss buffer 5",
        .ucode = 0x20,
    },
    {
        .uname = "DC_MISS6",
        .udesc = "Data cache miss buffer 6",
        .ucode = 0x40,
    },
    {
        .uname = "DC_MISS7",
        .udesc = "Data cache miss buffer 7",
        .ucode = 0x80,
    },
    {
        .uname = "IC_MISS0",
        .udesc = "Instruction cache miss buffer 0",
        .ucode = 0x100,
    },
    {
        .uname = "IC_MISS1",
        .udesc = "Instruction cache miss buffer 1",
        .ucode = 0x200,
    },
    {
        .uname = "DC_ANY",
        .udesc = "Any data cache miss buffer",
        .ucode = 0x800,
    },
    {
        .uname = "IC_ANY",
        .udesc = "Any instruction cache miss buffer",
        .ucode = 0x1000,
    },
};

/* System Response by Coherence 0x6c */
static const amd64_umask_t amd64_fam16h_system_responses[] = {
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
        .uname = "CHANGE_DIRTY",
        .udesc = "Change to dirty success",
        .ucode = 0x20,
    },
    {
        .uname = "UNCACHEABLE",
        .udesc = "Uncacheable",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Data written to system 0x6d */
static const amd64_umask_t amd64_fam16h_data_written_to_system[] = {
    {
        .uname = "DATA_LINE_EVICTIONS",
        .udesc = "Data line evictions",
        .ucode = 0x1,
    },
    {
        .uname = "INSTRUCTION_ATTRIBUTE_EVICTIONS",
        .udesc = "Instruction attribute evictions",
        .ucode = 0x2,
    },
    {
        .uname = "BYTE_ENABLE_MASK_UNCACHEABLE",
        .udesc = "Byte enable mask for uncacheabe or I/O store",
        .ucode = 0x4,
    },
    {
        .uname = "DATA_FOR_UNCACHEABLE",
        .udesc = "Data for uncacheabe or I/O store",
        .ucode = 0x8,
    },
    {
        .uname = "BYTE_ENABLE_MASK_WRITE_COMBINE",
        .udesc = "Byte enable mask for write combine context flush",
        .ucode = 0x10,
    },
    {
        .uname = "DATA_FOR_WRITE_COMBINE",
        .udesc = "Data for write combine contet flush",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* cache cross invalidate 0x75 */
static const amd64_umask_t amd64_fam16h_cache_cross_invalidates[] = {
    {
        .uname = "DC_INVALIDATES_IC",
        .udesc = "Modification of instructions of data too close to code",
        .ucode = 0x1,
    },
    {
        .uname = "DC_INVALIDATES_DC",
        .udesc = "CD or WBINVD",
        .ucode = 0x2,
    },
    {
        .uname = "IC_INVALIDATES_IC",
        .udesc = "aliasing",
        .ucode = 0x4,
    },
    {
        .uname = "IC_INVALIDATES_DC_DIRTY",
        .udesc = "Exection of modified instruction or data too close to code",
        .ucode = 0x8,
    },
    {
        .uname = "IC_HITS_DC_CLEAN_LINE",
        .udesc = "Reading code",
        .ucode = 0x10,
    },
    {
        .uname = "DC_PROBE_REJECTED_EARLY",
        .udesc = "DC probe rejected early",
        .ucode = 0x20,
    },
    {
        .uname = "DC_PROBE_REJECTED_LATE",
        .udesc = "DC probe rejected late",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x7f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* PDC Miss 0x162 */
static const amd64_umask_t amd64_fam16h_pdc_miss[] = {
    {
        .uname = "HOST_PDE_LEVEL",
        .udesc = "Host: PDE level",
        .ucode = 0x1,
    },
    {
        .uname = "HOST_PDPE_LEVEL",
        .udesc = "Host: PDPE level",
        .ucode = 0x2,
    },
    {
        .uname = "HOST_PML4E_LEVEL",
        .udesc = "Host: PML4E level",
        .ucode = 0x4,
    },
    {
        .uname = "GUEST_PDE_LEVEL",
        .udesc = "Guest: PDE level",
        .ucode = 0x10,
    },
    {
        .uname = "GUEST_PDPE_LEVEL",
        .udesc = "Guest: PDPE level",
        .ucode = 0x20,
    },
    {
        .uname = "GUEST_PML4E_LEVEL",
        .udesc = "Guest: PML4E level",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x77,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* ITLB Miss 0x85 */
static const amd64_umask_t amd64_fam16h_itlb_miss[] = {
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

/* Instruction Cache Lines Invalidated 0x8c */
static const amd64_umask_t amd64_fam16h_instruction_cache_lines_invalidated[] = {
    {
        .uname = "IC_INVALIDATE_LS_PROBE",
        .udesc = "Instruction cache invalidate due to LS probe",
        .ucode = 0x1,
    },
    {
        .uname = "IC_INVALIDATE_BU_PROBE",
        .udesc = "Instruction cache invalidate due to BU probe",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Retired indirect branch info (0x19a) */
static const amd64_umask_t amd64_fam16h_retired_branch_info[] = {
    {
        .uname = "RETIRED",
        .udesc = "Retired indirect branch instruction.",
        .ucode = 0x1,
    },
    {
        .uname = "MISPREDICTED",
        .udesc = "Retired mispredicted near unconditional jump.",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* Retired MMX/FP instructions 0xcb */
static const amd64_umask_t amd64_fam16h_retired_mmx_and_fp_instructions[] = {
    {
        .uname = "X87",
        .udesc = "X87 instructions",
        .ucode = 0x1,
    },
    {
        .uname = "SSE",
        .udesc = "SSE, SSE2, SSE3, MNI instructions",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

/* FPU exceptions 0xdb */
static const amd64_umask_t amd64_fam16h_fpu_exceptions[] = {
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

static const amd64_entry_t amd64_fam16h_pe[] = {
    {
        .name = "DISPATCHED_FPU",
        .desc = "Dispatched FPU Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_dispatched_fpu),
        .ngrp = 1,
        .umasks = amd64_fam16h_dispatched_fpu,
    },
    {
        .name = "FP_SCHEDULER_EMPTY",
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
        .name = "RETIRED_SSE_AVX_OPERATIONS",
        .desc = "Retired SSE/AVX Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x3,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_retired_sse_operations),
        .ngrp = 1,
        .umasks = amd64_fam16h_retired_sse_operations,
    },
    {
        .name = "RETIRED_SERIALIZING_OPS",
        .desc = "Retired Serializing Ops",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x5,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_retired_serializing_ops),
        .ngrp = 1,
        .umasks = amd64_fam16h_retired_serializing_ops,
    },
    {
        .name = "RETIRED_X87_OPERATIONS",
        .desc = "Retired x87 operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x11,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_retired_x87_ops),
        .ngrp = 1,
        .umasks = amd64_fam16h_retired_x87_ops,
    },
    {
        .name = "SEGMENT_REGISTER_LOADS",
        .desc = "Segment Register Loads",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x20,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_segment_register_loads),
        .ngrp = 1,
        .umasks = amd64_fam16h_segment_register_loads,
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
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_pipeline_restart),
        .ngrp = 1,
        .umasks = amd64_fam16h_pipeline_restart,
    },
    {
        .name = "LOCKED_OPS",
        .desc = "Locked Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x24,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_locked_ops),
        .ngrp = 1,
        .umasks = amd64_fam16h_locked_ops,
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
        .name = "LS_DISPATCH",
        .desc = "Transactions dispatched to load-store unit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x29,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_ls_dispatch),
        .ngrp = 1,
        .umasks = amd64_fam16h_ls_dispatch,
    },
    {
        .name = "CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS",
        .desc = "Cancelled Store to Load Forward Operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x2a,
        .numasks =
            LIBPFM_ARRAY_SIZE(amd64_fam16h_cancelled_store_to_load_forward_operations),
        .ngrp = 1,
        .umasks = amd64_fam16h_cancelled_store_to_load_forward_operations,
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
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_data_cache_refills),
        .ngrp = 1,
        .umasks = amd64_fam16h_data_cache_refills,
    },
    {
        .name = "DATA_CACHE_REFILLS_FROM_NORTHBRIDGE",
        .desc = "Data Cache Refills from the Northbridge",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x43,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_data_cache_refills_from_system),
        .ngrp = 1,
        .umasks = amd64_fam16h_data_cache_refills_from_system,
    },
    {
        .name = "DATA_CACHE_LINES_EVICTED",
        .desc = "Data Cache Lines Evicted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x44,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_data_cache_lines_evicted),
        .ngrp = 1,
        .umasks = amd64_fam16h_data_cache_lines_evicted,
    },
    {
        .name = "L1_DTLB_MISS_AND_L2_DTLB_HIT",
        .desc = "L1 DTLB Miss and L2 DTLB Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x45,
    },
    {
        .name = "DTLB_MISS",
        .desc = "L1 DTLB and L2 DTLB Miss",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x46,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_dtlb_miss),
        .ngrp = 1,
        .umasks = amd64_fam16h_dtlb_miss,
    },
    {
        .name = "MISALIGNED_ACCESSES",
        .desc = "Misaligned Accesses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x47,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_misaligned_accesses),
        .ngrp = 1,
        .umasks = amd64_fam16h_misaligned_accesses,
    },
    {
        .name = "PREFETCH_INSTRUCTIONS_DISPATCHED",
        .desc = "Prefetch Instructions Dispatched",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4b,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_prefetch_instructions_dispatched),
        .ngrp = 1,
        .umasks = amd64_fam16h_prefetch_instructions_dispatched,
    },
    {
        .name = "DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
        .desc = "DCACHE Misses by Locked Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4c,
    },
    {
        .name = "L1_DTLB_HIT",
        .desc = "L1 DTLB Hit",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x4d,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_l1_dtlb_hit),
        .ngrp = 1,
        .umasks = amd64_fam16h_l1_dtlb_hit,
    },
    {
        .name = "INEFFECTIVE_SW_PREFETCHES",
        .desc = "Ineffective Software Prefetches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x52,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_ineffective_sw_prefetches),
        .ngrp = 1,
        .umasks = amd64_fam16h_ineffective_sw_prefetches,
    },
    {
        .name = "GLOBAL_TLB_FLUSHES",
        .desc = "Global TLB Flushes",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x54,
    },
    /* fam30h only */
    {
        .name = "COMMAND_RELATED_UNCACHABLE",
        .desc = "Commands realted to uncachable memory and I/O",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x61,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_uncachable_memory),
        .ngrp = 1,
        .umasks = amd64_fam16h_uncachable_memory,
    },
    {
        .name = "COMMAND_RELATED_READ_BLOCK",
        .desc = "Commands realted to read block operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x62,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_read_block),
        .ngrp = 1,
        .umasks = amd64_fam16h_read_block,
    },
    {
        .name = "COMMAND_RELATED_DIRTY",
        .desc = "Commands realted to change dirty operations",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x63,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_change_dirty),
        .ngrp = 1,
        .umasks = amd64_fam16h_change_dirty,
    },
    {
        .name = "MEMORY_REQUESTS",
        .desc = "Memory Requests by Type",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x65,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_memory_requests),
        .ngrp = 1,
        .umasks = amd64_fam16h_memory_requests,
    },
    {
        .name = "DATA_PREFETCHES",
        .desc = "Data Prefetches",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x67,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_data_prefetches),
        .ngrp = 1,
        .umasks = amd64_fam16h_data_prefetches,
    },
    {
        .name = "MAB_REQUESTS",
        .desc = "Miss address buffer requests",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x68,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_mab_requests),
        .ngrp = 1,
        .umasks = amd64_fam16h_mab_requests,
    },
    {
        .name = "MAB_WAIT_CYCLES",
        .desc = "Miss address buffer wait cycles",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x69,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_mab_requests),
        .ngrp = 1,
        .umasks = amd64_fam16h_mab_requests,
    },
    {
        .name = "SYSTEM_RESPONSES",
        .desc = "L2I Responses by Coherency State",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x6c,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_system_responses),
        .ngrp = 1,
        .umasks = amd64_fam16h_system_responses,
    },
    {
        .name = "DATA_WRITTEN_TO_SYSTEM",
        .desc = "16-byte transfers written to system",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x6d,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_data_written_to_system),
        .ngrp = 1,
        .umasks = amd64_fam16h_data_written_to_system,
    },
    {
        .name = "CACHE_CROSS_INVALIDATES",
        .desc = "Internal probes causing cache lines to be invalidated",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x75,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_cache_cross_invalidates),
        .ngrp = 1,
        .umasks = amd64_fam16h_cache_cross_invalidates,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "CPU Clocks not Halted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x76,
    },
    {
        .name = "PDC_MISS",
        .desc = "Number of PDC misses",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x162,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_pdc_miss),
        .ngrp = 1,
        .umasks = amd64_fam16h_pdc_miss,
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
        .name = "ITLB_MISS",
        .desc = "Instruction fetches that miss in 4k and 2M ITLB",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x85,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_itlb_miss),
        .ngrp = 1,
        .umasks = amd64_fam16h_itlb_miss,
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
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_instruction_cache_lines_invalidated),
        .ngrp = 1,
        .umasks = amd64_fam16h_instruction_cache_lines_invalidated,
    },
    {
        .name = "ITLB_RELOADS",
        .desc = "ITLB Reloads",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x99,
    },
    {
        .name = "ITLB_RELOADS_ABORTED",
        .desc = "ITLB reloads aborted",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x9a,
    },
    {
        .name = "RETIRED_INDIRECT_BRANCH_INFO",
        .desc = "Retired indirect branch info",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x19a,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_retired_branch_info),
        .ngrp = 1,
        .umasks = amd64_fam16h_retired_branch_info,
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
        .name = "RETIRED_MISPREDICTED_TAKEN",
        .desc = "Retired mispredicted taken branches due to target mismatch",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xca,
    },
    {
        .name = "RETIRED_MMX_AND_FP_INSTRUCTIONS",
        .desc = "Retired MMX/FP Instructions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xcb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_retired_mmx_and_fp_instructions),
        .ngrp = 1,
        .umasks = amd64_fam16h_retired_mmx_and_fp_instructions,
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
        .name = "FPU_EXCEPTIONS",
        .desc = "FPU Exceptions",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0xdb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam16h_fpu_exceptions),
        .ngrp = 1,
        .umasks = amd64_fam16h_fpu_exceptions,
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
        .name = "TAGGED_IBS_OPS",
        .desc = "Ops tagged by IBS",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1cf,
    },
    {
        .name = "TAGGED_IBS_OPS_RETIRED",
        .desc = "Ops tagged by IBS that retired",
        .modmsk = AMD64_FAM10H_ATTRS,
        .code = 0x1d0,
    },
};
