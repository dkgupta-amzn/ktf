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
 * PMU: knc (Intel Knights Corners)
 */

static const intel_x86_entry_t intel_knc_pe[] = {
    {
        .name = "BANK_CONFLICTS",
        .desc = "Number of actual bank conflicts",
        .code = 0xa,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "BRANCHES",
        .desc =
            "Number of taken and not taken branches, including: conditional branches, "
            "jumps, calls, returns, software interrupts, and interrupt returns",
        .code = 0x12,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "BRANCHES_MISPREDICTED",
        .desc = "Number of branch mispredictions that occurred on BTB hits. BTB misses "
                "are not considered branch mispredicts because no prediction exists for "
                "them yet.",
        .code = 0x2b,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "CODE_CACHE_MISS",
        .desc = "Number of instruction reads that miss the internal code cache; whether "
                "the read is cacheable or noncacheable",
        .code = 0xe,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "CODE_PAGE_WALK",
        .desc = "Number of code page walks",
        .code = 0xd,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "CODE_READ",
        .desc =
            "Number of instruction reads; whether the read is cacheable or noncacheable",
        .code = 0xc,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Number of cycles during which the processor is not halted.",
        .code = 0x2a,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_CACHE_LINES_WRITTEN_BACK",
        .desc =
            "Number of dirty lines (all) that are written back, regardless of the cause",
        .code = 0x6,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_PAGE_WALK",
        .desc = "Number of data page walks",
        .code = 0x2,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_READ",
        .desc =
            "Number of successful memory data reads committed by the K-unit (L1). Cache "
            "accesses resulting from prefetch instructions are included for A0 stepping.",
        .code = 0x0,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_READ_MISS",
        .desc = "Number of memory read accesses that miss the internal data cache "
                "whether or not the access is cacheable or noncacheable. Cache accesses "
                "resulting from prefetch instructions are not included.",
        .code = 0x3,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_READ_MISS_OR_WRITE_MISS",
        .desc = "Number of memory read and/or write accesses that miss the internal data "
                "cache, whether or not the access is cacheable or noncacheable",
        .code = 0x29,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_READ_OR_WRITE",
        .desc = "Number of memory data reads and/or writes (internal data cache hit and "
                "miss combined). Read cache accesses resulting from prefetch "
                "instructions are included for A0 stepping.",
        .code = 0x28,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_WRITE",
        .desc = "Number of successful memory data writes committed by the K-unit (L1). "
                "Streaming stores (hit/miss L1), cacheable write partials, and UC "
                "promotions are all included.",
        .code = 0x1,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "DATA_WRITE_MISS",
        .desc =
            "Number of memory write accesses that miss the internal data cache whether "
            "or not the access is cacheable. Non-cacheable misses are not included.",
        .code = 0x4,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "EXEC_STAGE_CYCLES",
        .desc = "Number of E-stage cycles that were successfully completed. Includes "
                "cycles generated by multi-cycle E-stage instructions. For instructions "
                "destined for the FPU or VPU pipelines, this event only counts occupancy "
                "in the integer E-stage.",
        .code = 0x2e,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "FE_STALLED",
        .desc =
            "Number of cycles where the front-end could not advance. Any multi-cycle "
            "instructions which delay pipeline advance and apply backpressure to the "
            "front-end will be included, e.g. read-modify-write instructions. Includes "
            "cycles when the front-end did not have any instructions to issue.",
        .code = 0x2d,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "INSTRUCTIONS_EXECUTED",
        .desc = "Number of instructions executed (up to two per clock)",
        .code = 0x16,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "INSTRUCTIONS_EXECUTED_V_PIPE",
        .desc = "Number of instructions executed in the V_pipe. The event indicates the "
                "number of instructions that were paired.",
        .code = 0x17,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L1_DATA_HIT_INFLIGHT_PF1",
        .desc = "Number of data requests which hit an in-flight vprefetch0. The "
                "in-flight vprefetch0 was not necessarily issued from the same thread as "
                "the data request.",
        .code = 0x20,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L1_DATA_PF1",
        .desc = "Number of data vprefetch0 requests seen by the L1.",
        .code = 0x11,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L1_DATA_PF1_DROP",
        .desc = "Number of data vprefetch0 requests seen by the L1 which were dropped "
                "for any reason. A vprefetch0 can be dropped if the requested address "
                "matches another in-flight request or if it has a UC memtype.",
        .code = 0x1e,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L1_DATA_PF1_MISS",
        .desc = "Number of data vprefetch0 requests seen by the L1 which missed L1. Does "
                "not include vprefetch1 requests which are counted in L1_DATA_PF1_DROP.",
        .code = 0x1c,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L1_DATA_PF2",
        .desc = "Number of data vprefetch1 requests seen by the L1. This is not "
                "necessarily the same number as seen by the L2 because this count "
                "includes requests that are dropped by the core. A vprefetch1 can be "
                "dropped by the core if the requested address matches another in-flight "
                "request or if it has a UC memtype.",
        .code = 0x37,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_CODE_READ_MISS_CACHE_FILL",
        .desc = "Number of code read accesses that missed the L2 cache and were "
                "satisfied by another L2 cache. Can include promoted read misses that "
                "started as DATA accesses.",
        .code = 0x10f0,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_CODE_READ_MISS_MEM_FILL",
        .desc = "Number of code read accesses that missed the L2 cache and were "
                "satisfied by main memory. Can include promoted read misses that started "
                "as DATA accesses.",
        .code = 0x10f5,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_HIT_INFLIGHT_PF2",
        .desc = "Number of data requests which hit an in-flight vprefetch1. The "
                "in-flight vprefetch1 was not necessarily issued from the same thread as "
                "the data request.",
        .code = 0x10ff,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_PF1_MISS",
        .desc = "Number of data vprefetch0 requests seen by the L2 which missed L2.",
        .code = 0x38,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_PF2",
        .desc = "Number of data vprefetch1 requests seen by the L2. Only counts "
                "vprefetch1 hits on A0 stepping.",
        .code = 0x10fc,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_PF2_DROP",
        .desc = "Number of data vprefetch1 requests seen by the L2 which were dropped "
                "for any reason.",
        .code = 0x10fd,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_PF2_MISS",
        .desc = "Number of data vprefetch1 requests seen by the L2 which missed L2. Does "
                "not include vprefetch2 requests which are counted in L2_DATA_PF2_DROP.",
        .code = 0x10fe,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_READ_MISS_CACHE_FILL",
        .desc = "Number of data read accesses that missed the L2 cache and were "
                "satisfied by another L2 cache. Can include promoted read misses that "
                "started as CODE accesses.",
        .code = 0x10f1,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_READ_MISS_MEM_FILL",
        .desc = "Number of data read accesses that missed the L2 cache and were "
                "satisfied by main memory. Can include promoted read misses that started "
                "as CODE accesses.",
        .code = 0x10f6,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_WRITE_MISS_CACHE_FILL",
        .desc = "Number of data write (RFO) accesses that missed the L2 cache and were "
                "satisfied by another L2 cache.",
        .code = 0x10f2,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_DATA_WRITE_MISS_MEM_FILL",
        .desc = "Number of data write (RFO) accesses that missed the L2 cache and were "
                "satisfied by main memory.",
        .code = 0x10f7,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_READ_HIT_E",
        .desc = "L2 Read Hit E State, may include prefetches on A0 stepping.",
        .code = 0x10c8,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_READ_HIT_M",
        .desc = "L2 Read Hit M State",
        .code = 0x10c9,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_READ_HIT_S",
        .desc = "L2 Read Hit S State",
        .code = 0x10ca,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_READ_MISS",
        .desc = "L2 Read Misses. Prefetch and demand requests to the same address will "
                "produce double counting.",
        .code = 0x10cb,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_VICTIM_REQ_WITH_DATA",
        .desc = "L2 received a victim request and responded with data",
        .code = 0x10d7,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "L2_WRITE_HIT",
        .desc = "L2 Write HIT, may undercount on A0 stepping.",
        .code = 0x10cc,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "LONG_CODE_PAGE_WALK",
        .desc = "Number of long code page walks, i.e. page walks that also missed the L2 "
                "uTLB. Subset of DATA_CODE_WALK event",
        .code = 0x3b,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "LONG_DATA_PAGE_WALK",
        .desc = "Number of long data page walks, i.e. page walks that also missed the L2 "
                "uTLB. Subset of DATA_PAGE_WALK event",
        .code = 0x3a,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "MEMORY_ACCESSES_IN_BOTH_PIPES",
        .desc = "Number of data memory reads or writes that are paired in both pipes of "
                "the pipeline",
        .code = 0x9,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "MICROCODE_CYCLES",
        .desc = "The number of cycles microcode is executing. While microcode is "
                "executing, all other threads are stalled.",
        .code = 0x2c,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "PIPELINE_AGI_STALLS",
        .desc =
            "Number of address generation interlock (AGI) stalls. An AGI occurring in "
            "both the U- and V- pipelines in the same clock signals this event twice.",
        .code = 0x1f,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "PIPELINE_FLUSHES",
        .desc = "Number of pipeline flushes that occur. Pipeline flushes are caused by "
                "BTB misses on taken branches, mispredictions, exceptions, interrupts, "
                "and some segment descriptor loads.",
        .code = 0x15,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "PIPELINE_SG_AGI_STALLS",
        .desc = "Number of address generation interlock (AGI) stalls due to vscatter* "
                "and vgather* instructions.",
        .code = 0x21,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "SNP_HITM_BUNIT",
        .desc = "Snoop HITM in BUNIT",
        .code = 0x10e3,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "SNP_HITM_L2",
        .desc = "Snoop HITM in L2",
        .code = 0x10e7,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "SNP_HIT_L2",
        .desc = "Snoop HIT in L2",
        .code = 0x10e6,
        .cntmsk = 0x1,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_DATA_READ",
        .desc =
            "Number of read transactions that were issued. In general each read "
            "transaction will read 1 64B cacheline. If there are alignment issues, then "
            "reads against multiple cache lines will each be counted individually.",
        .code = 0x2000,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_DATA_READ_MISS",
        .desc = "VPU L1 data cache readmiss. Counts the number of occurrences.",
        .code = 0x2003,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_DATA_WRITE",
        .desc =
            "Number of write transactions that were issued. . In general each write "
            "transaction will write 1 64B cacheline. If there are alignment issues, then "
            "write against multiple cache lines will each be counted individually.",
        .code = 0x2001,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_DATA_WRITE_MISS",
        .desc = "VPU L1 data cache write miss. Counts the number of occurrences.",
        .code = 0x2004,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_ELEMENTS_ACTIVE",
        .desc = "Counts the cumulative number of elements active (via mask) for VPU "
                "instructions issued.",
        .code = 0x2018,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_INSTRUCTIONS_EXECUTED",
        .desc = "Counts the number of VPU instructions executed in both u- and v-pipes.",
        .code = 0x2016,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_INSTRUCTIONS_EXECUTED_V_PIPE",
        .desc = "Counts the number of VPU instructions that paired and executed in the "
                "v-pipe.",
        .code = 0x2017,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
    {
        .name = "VPU_STALL_REG",
        .desc = "VPU stall on Register Dependency. Counts the number of occurrences. "
                "Dependencies will include RAW, WAW, WAR.",
        .code = 0x2005,
        .cntmsk = 0x3,
        .modmsk = INTEL_V3_ATTRS,
    },
};
