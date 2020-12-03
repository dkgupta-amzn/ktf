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
 * FILE AUTOMATICALLY GENERATED from download.01.org/perfmon/GLM/Goldmont_core_V6.json
 * PMU: glm (Intel Goldmont)
 */
static const intel_x86_umask_t glm_icache[] = {
    {
        .uname = "HIT",
        .udesc = "References per ICache line that are available in the ICache (hit). "
                 "This event counts differently than Intel processors based on "
                 "Silvermont microarchitecture",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "MISSES",
        .udesc = "References per ICache line that are not available in the ICache "
                 "(miss). This event counts differently than Intel processors based on "
                 "Silvermont microarchitecture",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ACCESSES",
        .udesc = "References per ICache line. This event counts differently than Intel "
                 "processors based on Silvermont microarchitecture",
        .ucode = 0x0300,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_l2_reject_xq[] = {
    {
        .uname = "ALL",
        .udesc = "Requests rejected by the XQ",
        .ucode = 0x0000,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_hw_interrupts[] = {
    {
        .uname = "RECEIVED",
        .udesc = "Hardware interrupts received",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "PENDING_AND_MASKED",
        .udesc = "Cycles pending interrupts are masked",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_br_misp_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Retired mispredicted branch instructions (Precise Event)",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "JCC",
        .udesc = "Retired mispredicted conditional branch instructions (Precise Event)",
        .ucode = 0x7e00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "TAKEN_JCC",
        .udesc = "Retired mispredicted conditional branch instructions that were taken "
                 "(Precise Event)",
        .ucode = 0xfe00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "IND_CALL",
        .udesc = "Retired mispredicted near indirect call instructions (Precise Event)",
        .ucode = 0xfb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "RETURN",
        .udesc = "Retired mispredicted near return instructions (Precise Event)",
        .ucode = 0xf700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "NON_RETURN_IND",
        .udesc = "Retired mispredicted instructions of near indirect Jmp or near "
                 "indirect call (Precise Event)",
        .ucode = 0xeb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_decode_restriction[] = {
    {
        .uname = "PREDECODE_WRONG",
        .udesc = "Decode restrictions due to predicting wrong instruction length",
        .ucode = 0x0100,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_misalign_mem_ref[] = {
    {
        .uname = "LOAD_PAGE_SPLIT",
        .udesc = "Load uops that split a page (Precise Event)",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "STORE_PAGE_SPLIT",
        .udesc = "Store uops that split a page (Precise Event)",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_inst_retired[] = {
    {
        .uname = "ANY_P",
        .udesc =
            "Counts the number of instructions that retire execution. For instructions "
            "that consist of multiple uops, this event counts the retirement of the last "
            "uop of the instruction. The event continues counting during hardware "
            "interrupts, traps, and inside interrupt handlers.  This is an architectural "
            "performance event.  This event uses a (_P)rogrammable general purpose "
            "performance counter. *This event is Precise Event capable:  The EventingRIP "
            "field in the PEBS record is precise to the address of the instruction which "
            "caused the event.  Note: Because PEBS records can be collected only on "
            "IA32_PMC0, only one event can use the PEBS facility at a time.",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_issue_slots_not_consumed[] = {
    {
        .uname = "RESOURCE_FULL",
        .udesc =
            "Unfilled issue slots per cycle because of a full resource in the backend",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "RECOVERY",
        .udesc = "Unfilled issue slots per cycle to recover",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ANY",
        .udesc = "Unfilled issue slots per cycle",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_itlb[] = {
    {
        .uname = "MISS",
        .udesc = "ITLB misses",
        .ucode = 0x0400,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_longest_lat_cache[] = {
    {
        .uname = "REFERENCE",
        .udesc = "L2 cache requests",
        .ucode = 0x4f00,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "MISS",
        .udesc = "L2 cache request misses",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_mem_load_uops_retired[] = {
    {
        .uname = "L1_HIT",
        .udesc = "Load uops retired that hit L1 data cache (Precise Event)",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "L1_MISS",
        .udesc = "Load uops retired that missed L1 data cache (Precise Event)",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Load uops retired that hit L2 (Precise Event)",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "L2_MISS",
        .udesc = "Load uops retired that missed L2 (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "HITM",
        .udesc = "Memory uop retired where cross core or cross module HITM occurred "
                 "(Precise Event)",
        .ucode = 0x2000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "WCB_HIT",
        .udesc = "Loads retired that hit WCB (Precise Event)",
        .ucode = 0x4000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DRAM_HIT",
        .udesc = "Loads retired that came from DRAM (Precise Event)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_ld_blocks[] = {
    {
        .uname = "ALL_BLOCK",
        .udesc = "Loads blocked (Precise Event)",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "UTLB_MISS",
        .udesc = "Loads blocked because address in not in the UTLB (Precise Event)",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "STORE_FORWARD",
        .udesc = "Loads blocked due to store forward restriction (Precise Event)",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DATA_UNKNOWN",
        .udesc = "Loads blocked due to store data not ready (Precise Event)",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "4K_ALIAS",
        .udesc = "Loads blocked because address has 4k partial address false dependence "
                 "(Precise Event)",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_dl1[] = {
    {
        .uname = "DIRTY_EVICTION",
        .udesc = "L1 Cache evictions for dirty data",
        .ucode = 0x0100,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_cycles_div_busy[] = {
    {
        .uname = "ALL",
        .udesc = "Cycles a divider is busy",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "IDIV",
        .udesc = "Cycles the integer divide unit is busy",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "FPDIV",
        .udesc = "Cycles the FP divide unit is busy",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_ms_decoded[] = {
    {
        .uname = "MS_ENTRY",
        .udesc = "MS decode starts",
        .ucode = 0x0100,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_uops_retired[] = {
    {
        .uname = "ANY",
        .udesc = "Uops retired (Precise Event)",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "MS",
        .udesc = "MS uops retired (Precise Event)",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_offcore_response_0[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Request: number of demand and DCU prefetch data reads of full and "
                 "partial cachelines as well as demand data page table entry cacheline "
                 "reads. Does not count L2 data read prefetches or instruction fetches",
        .ucode = 1ULL << (0 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Request: number of demand and DCU prefetch reads for ownership (RFO) "
                 "requests generated by a write to data cacheline. Does not count L2 RFO "
                 "prefetches",
        .ucode = 1ULL << (1 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "DMND_CODE_RD",
        .udesc = "Request: number of demand and DCU prefetch instruction cacheline "
                 "reads. Does not count L2 code read prefetches",
        .ucode = 1ULL << (2 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "WB",
        .udesc = "Request: number of writebacks (modified to exclusive) transactions",
        .ucode = 1ULL << (3 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_DATA_RD",
        .udesc = "Request: number of data cacheline reads generated by L2 prefetcher",
        .ucode = 1ULL << (4 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_RFO",
        .udesc = "Request: number of RFO requests generated by L2 prefetcher",
        .ucode = 1ULL << (5 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_READS",
        .udesc = "Request: number of partil reads",
        .ucode = 1ULL << (7 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_WRITES",
        .udesc = "Request: number of partial writes",
        .ucode = 1ULL << (8 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "UC_CODE_READS",
        .udesc = "Request: number of uncached code reads",
        .ucode = 1ULL << (9 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "BUS_LOCKS",
        .udesc = "Request: number of bus lock and split lock requests",
        .ucode = 1ULL << (10 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "FULL_STRM_ST",
        .udesc = "Request: number of streaming store requests for full cacheline",
        .ucode = 1ULL << (11 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "SW_PF",
        .udesc = "Request: number of cacheline requests due to software prefetch",
        .ucode = 1ULL << (12 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_L1_DATA_RD",
        .udesc =
            "Request: number of data cacheline reads generated by L1 data prefetcher",
        .ucode = 1ULL << (13 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_STRM_ST",
        .udesc = "Request: number of streaming store requests for partial cacheline",
        .ucode = 1ULL << (14 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "STRM_ST",
        .udesc =
            "Request: number of streaming store requests for partial or full cacheline",
        .ucode = (1ULL << (14 + 8)) | (1ULL << (11 + 8)),
        .uequiv = "FULL_STRM_ST:PARTIAL_STRM_ST",
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Request: combination of all request umasks",
        .ucode = 1ULL << (15 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "ANY_PF_DATA_RD",
        .udesc = "Request: number of prefetch data reads",
        .ucode = (1ULL << (4 + 8)) | (1ULL << (12 + 8)) | (1ULL << (13 + 8)),
        .grpid = 0,
        .ucntmsk = 0xffull,
        .uequiv = "PF_DATA_RD:SW_PF:PF_L1_DATA_RD",
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Request: number of RFO",
        .ucode = (1ULL << (1 + 8)) | (1ULL << (5 + 8)),
        .grpid = 0,
        .ucntmsk = 0xffull,
        .uequiv = "DMND_RFO:PF_RFO",
    },
    {
        .uname = "ANY_RESPONSE",
        .udesc = "Response: any response type",
        .ucode = 1ULL << (16 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_EXCL_GRP_GT,
        .grpid = 1,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Supplier: counts L2 hits",
        .ucode = 1ULL << (18 + 8),
        .grpid = 1,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_MISS_OR_NO_SNOOP_NEEDED",
        .udesc = "Snoop: counts number true misses to this processor module for which a "
                 "snoop request missed the other processor module or no snoop was needed",
        .ucode = 1ULL << (33 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_HIT_OTHER_CORE_NO_FWD",
        .udesc = "Snoop: counts number of times a snoop request hits the other processor "
                 "module but no data forwarding is needed",
        .ucode = 1ULL << (34 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_HITM_OTHER_CORE",
        .udesc =
            "Snoop: counts number of times a snoop request hits in the other processor "
            "module or other core's L1 where a modified copy (M-state) is found",
        .ucode = 1ULL << (36 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_NON_DRAM",
        .udesc = "Snoop:  counts number of times target was a non-DRAM system address. "
                 "This includes MMIO transactions",
        .ucode = 1ULL << (37 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_ANY",
        .udesc = "Snoop: any snoop reason",
        .ucode = 0x1bULL << (33 + 8),
        .uflags = INTEL_X86_DFL,
        .uequiv = "L2_MISS_SNP_MISS_OR_NO_SNOOP_NEEDED:L2_MISS_HIT_OTHER_CORE_NO_FWD:L2_"
                  "MISS_HITM_OTHER_CORE:L2_MISS_SNP_NON_DRAM",
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "OUTSTANDING",
        .udesc =
            "Outstanding request:  counts weighted cycles of outstanding offcore "
            "requests of the request type specified in the bits 15:0 of offcore_response "
            "from the time the XQ receives the request and any response received. Bits "
            "37:16 must be set to 0. This is only available for offcore_response_0",
        .ucode = 1ULL << (38 + 8),
        .uflags = INTEL_X86_GRP_DFL_NONE |
                  INTEL_X86_EXCL_GRP_BUT_0, /* can only be combined with request type bits
                                               (grpid = 0) */
        .grpid = 3,
        .ucntmsk = 0xffull,
    },
};

static const intel_x86_umask_t glm_offcore_response_1[] = {
    {
        .uname = "DMND_DATA_RD",
        .udesc = "Request: number of demand and DCU prefetch data reads of full and "
                 "partial cachelines as well as demand data page table entry cacheline "
                 "reads. Does not count L2 data read prefetches or instruction fetches",
        .ucode = 1ULL << (0 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "DMND_RFO",
        .udesc = "Request: number of demand and DCU prefetch reads for ownership (RFO) "
                 "requests generated by a write to data cacheline. Does not count L2 RFO "
                 "prefetches",
        .ucode = 1ULL << (1 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "DMND_CODE_RD",
        .udesc = "Request: number of demand and DCU prefetch instruction cacheline "
                 "reads. Does not count L2 code read prefetches",
        .ucode = 1ULL << (2 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "WB",
        .udesc = "Request: number of writebacks (modified to exclusive) transactions",
        .ucode = 1ULL << (3 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_DATA_RD",
        .udesc = "Request: number of data cacheline reads generated by L2 prefetcher",
        .ucode = 1ULL << (4 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_RFO",
        .udesc = "Request: number of RFO requests generated by L2 prefetcher",
        .ucode = 1ULL << (5 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_READS",
        .udesc = "Request: number of partil reads",
        .ucode = 1ULL << (7 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_WRITES",
        .udesc = "Request: number of partial writes",
        .ucode = 1ULL << (8 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "UC_CODE_READS",
        .udesc = "Request: number of uncached code reads",
        .ucode = 1ULL << (9 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "BUS_LOCKS",
        .udesc = "Request: number of bus lock and split lock requests",
        .ucode = 1ULL << (10 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "FULL_STRM_ST",
        .udesc = "Request: number of streaming store requests for full cacheline",
        .ucode = 1ULL << (11 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "SW_PF",
        .udesc = "Request: number of cacheline requests due to software prefetch",
        .ucode = 1ULL << (12 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PF_L1_DATA_RD",
        .udesc =
            "Request: number of data cacheline reads generated by L1 data prefetcher",
        .ucode = 1ULL << (13 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "PARTIAL_STRM_ST",
        .udesc = "Request: number of streaming store requests for partial cacheline",
        .ucode = 1ULL << (14 + 8),
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "STRM_ST",
        .udesc =
            "Request: number of streaming store requests for partial or full cacheline",
        .ucode = (1ULL << (14 + 8)) | (1ULL << (11 + 8)),
        .uequiv = "FULL_STRM_ST:PARTIAL_STRM_ST",
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "ANY_REQUEST",
        .udesc = "Request: combination of all request umasks",
        .ucode = 1ULL << (15 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "ANY_PF_DATA_RD",
        .udesc = "Request: number of prefetch data reads",
        .ucode = (1ULL << (4 + 8)) | (1ULL << (12 + 8)) | (1ULL << (13 + 8)),
        .grpid = 0,
        .ucntmsk = 0xffull,
        .uequiv = "PF_DATA_RD:SW_PF:PF_L1_DATA_RD",
    },
    {
        .uname = "ANY_RFO",
        .udesc = "Request: number of RFO",
        .ucode = (1ULL << (1 + 8)) | (1ULL << (5 + 8)),
        .grpid = 0,
        .ucntmsk = 0xffull,
        .uequiv = "DMND_RFO:PF_RFO",
    },
    {
        .uname = "ANY_RESPONSE",
        .udesc = "Response: any response type",
        .ucode = 1ULL << (16 + 8),
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL | INTEL_X86_EXCL_GRP_GT,
        .grpid = 1,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_HIT",
        .udesc = "Supplier: counts L2 hits",
        .ucode = 1ULL << (18 + 8),
        .grpid = 1,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_MISS_OR_NO_SNOOP_NEEDED",
        .udesc = "Snoop: counts number true misses to this processor module for which a "
                 "snoop request missed the other processor module or no snoop was needed",
        .ucode = 1ULL << (33 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_HIT_OTHER_CORE_NO_FWD",
        .udesc = "Snoop: counts number of times a snoop request hits the other processor "
                 "module but no data forwarding is needed",
        .ucode = 1ULL << (34 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_HITM_OTHER_CORE",
        .udesc =
            "Snoop: counts number of times a snoop request hits in the other processor "
            "module or other core's L1 where a modified copy (M-state) is found",
        .ucode = 1ULL << (36 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_NON_DRAM",
        .udesc = "Snoop:  counts number of times target was a non-DRAM system address. "
                 "This includes MMIO transactions",
        .ucode = 1ULL << (37 + 8),
        .grpid = 2,
        .ucntmsk = 0xffull,
    },
    {
        .uname = "L2_MISS_SNP_ANY",
        .udesc = "Snoop: any snoop reason",
        .ucode = 0xfULL << (33 + 8),
        .uflags = INTEL_X86_DFL,
        .grpid = 2,
        .ucntmsk = 0xffull,
        .uequiv = "L2_MISS_SNP_MISS_OR_NO_SNOOP_NEEDED:L2_MISS_HIT_OTHER_CORE_NO_FWD:L2_"
                  "MISS_HITM_OTHER_CORE:L2_MISS_SNP_NON_DRAM",
    },
};

static const intel_x86_umask_t glm_machine_clears[] = {
    {
        .uname = "SMC",
        .udesc = "Self-Modifying Code detected",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "MEMORY_ORDERING",
        .udesc = "Machine cleas due to memory ordering issue",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "FP_ASSIST",
        .udesc = "Machine clears due to FP assists",
        .ucode = 0x0400,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DISAMBIGUATION",
        .udesc = "Machine clears due to memory disambiguation",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ALL",
        .udesc = "All machine clears",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_br_inst_retired[] = {
    {
        .uname = "ALL_BRANCHES",
        .udesc = "Retired branch instructions (Precise Event)",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ALL_TAKEN_BRANCHES",
        .udesc = "Retired branch instructions (Precise Event)",
        .ucode = 0x8000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "JCC",
        .udesc = "Retired conditional branch instructions (Precise Event)",
        .ucode = 0x7e00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "TAKEN_JCC",
        .udesc =
            "Retired conditional branch instructions that were taken (Precise Event)",
        .ucode = 0xfe00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "CALL",
        .udesc = "Retired near call instructions (Precise Event)",
        .ucode = 0xf900,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "REL_CALL",
        .udesc = "Retired near relative call instructions (Precise Event)",
        .ucode = 0xfd00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "IND_CALL",
        .udesc = "Retired near indirect call instructions (Precise Event)",
        .ucode = 0xfb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "RETURN",
        .udesc = "Retired near return instructions (Precise Event)",
        .ucode = 0xf700,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "NON_RETURN_IND",
        .udesc = "Retired instructions of near indirect Jmp or call (Precise Event)",
        .ucode = 0xeb00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "FAR_BRANCH",
        .udesc = "Retired far branch instructions (Precise Event)",
        .ucode = 0xbf00,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_fetch_stall[] = {
    {
        .uname = "ICACHE_FILL_PENDING_CYCLES",
        .udesc = "Cycles where code-fetch is stalled and an ICache miss is outstanding.  "
                 "This is not the same as an ICache Miss",
        .ucode = 0x0200,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_uops_not_delivered[] = {
    {
        .uname = "ANY",
        .udesc = "Uops requested but not-delivered to the back-end per cycle",
        .ucode = 0x0000,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_mem_uops_retired[] = {
    {
        .uname = "ALL_LOADS",
        .udesc = "Load uops retired (Precise Event)",
        .ucode = 0x8100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ALL_STORES",
        .udesc = "Store uops retired (Precise Event)",
        .ucode = 0x8200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "ALL",
        .udesc = "Memory uops retired (Precise Event)",
        .ucode = 0x8300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DTLB_MISS_LOADS",
        .udesc = "Load uops retired that missed the DTLB (Precise Event)",
        .ucode = 0x1100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DTLB_MISS_STORES",
        .udesc = "Store uops retired that missed the DTLB (Precise Event)",
        .ucode = 0x1200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "DTLB_MISS",
        .udesc = "Memory uops retired that missed the DTLB (Precise Event)",
        .ucode = 0x1300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "LOCK_LOADS",
        .udesc = "Locked load uops retired (Precise Event)",
        .ucode = 0x2100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "SPLIT_LOADS",
        .udesc = "Load uops retired that split a cache-line (Precise Event)",
        .ucode = 0x4100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "SPLIT_STORES",
        .udesc = "Stores uops retired that split a cache-line (Precise Event)",
        .ucode = 0x4200,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "SPLIT",
        .udesc = "Memory uops retired that split a cache-line (Precise Event)",
        .ucode = 0x4300,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_PEBS,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_uops_issued[] = {
    {
        .uname = "ANY",
        .udesc = "Uops issued to the back end per cycle",
        .ucode = 0x0000,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_core_reject_l2q[] = {
    {
        .uname = "ALL",
        .udesc = "Requests rejected by the L2Q ",
        .ucode = 0x0000,
        .uflags = INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_page_walks[] = {
    {
        .uname = "D_SIDE_CYCLES",
        .udesc = "Duration of D-side page-walks in cycles",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "I_SIDE_CYCLES",
        .udesc = "Duration of I-side pagewalks in cycles",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "CYCLES",
        .udesc = "Duration of page-walks in cycles",
        .ucode = 0x0300,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_baclears[] = {
    {
        .uname = "ALL",
        .udesc = "BACLEARs asserted for any branch type",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "RETURN",
        .udesc = "BACLEARs asserted for return branch",
        .ucode = 0x0800,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "COND",
        .udesc = "BACLEARs asserted for conditional branch",
        .ucode = 0x1000,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_umask_t glm_cpu_clk_unhalted[] = {
    {
        .uname = "CORE",
        .udesc = "Core cycles when core is not halted  (Fixed event)",
        .ucode = 0x0200,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0x200000000ull,
    },
    {
        .uname = "REF_TSC",
        .udesc = "Reference cycles when core is not halted  (Fixed event)",
        .ucode = 0x0300,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0x400000000ull,
    },
    {
        .uname = "CORE_P",
        .udesc = "Core cycles when core is not halted",
        .ucode = 0x0000,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
    {
        .uname = "REF",
        .udesc = "Reference cycles when core is not halted",
        .ucode = 0x0100,
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
        .ucntmsk = 0xfull,
    },
};

static const intel_x86_entry_t intel_glm_pe[] = {
    {
        .name = "ICACHE",
        .desc = "References per ICache line that are available in the ICache (hit). This "
                "event counts differently than Intel processors based on Silvermont "
                "microarchitecture",
        .code = 0x80,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_icache),
        .umasks = glm_icache,
    },
    {
        .name = "L2_REJECT_XQ",
        .desc = "Requests rejected by the XQ",
        .code = 0x30,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_l2_reject_xq),
        .umasks = glm_l2_reject_xq,
    },
    {
        .name = "HW_INTERRUPTS",
        .desc = "Hardware interrupts received",
        .code = 0xcb,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_hw_interrupts),
        .umasks = glm_hw_interrupts,
    },
    {
        .name = "BR_MISP_RETIRED",
        .desc = "Retired mispredicted branch instructions (Precise Event)",
        .code = 0xc5,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_br_misp_retired),
        .umasks = glm_br_misp_retired,
    },
    {
        .name = "DECODE_RESTRICTION",
        .desc = "Decode restrictions due to predicting wrong instruction length",
        .code = 0xe9,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_decode_restriction),
        .umasks = glm_decode_restriction,
    },
    {
        .name = "MISALIGN_MEM_REF",
        .desc = "Load uops that split a page (Precise Event)",
        .code = 0x13,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_misalign_mem_ref),
        .umasks = glm_misalign_mem_ref,
    },
    {
        .name = "INST_RETIRED",
        .desc = "Instructions retired (Precise Event)",
        .code = 0xc0,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x10000000full,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_inst_retired),
        .umasks = glm_inst_retired,
    },
    {
        .name = "INSTRUCTION_RETIRED",
        .desc = "Number of instructions retired",
        .code = 0xc0,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x100000ffull,
        .ngrp = 0,
    },
    {
        .name = "ISSUE_SLOTS_NOT_CONSUMED",
        .desc =
            "Unfilled issue slots per cycle because of a full resource in the backend",
        .code = 0xca,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_issue_slots_not_consumed),
        .umasks = glm_issue_slots_not_consumed,
    },
    {
        .name = "ITLB",
        .desc = "ITLB misses",
        .code = 0x81,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_itlb),
        .umasks = glm_itlb,
    },
    {
        .name = "LONGEST_LAT_CACHE",
        .desc = "L2 cache requests",
        .code = 0x2e,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_longest_lat_cache),
        .umasks = glm_longest_lat_cache,
    },
    {
        .name = "MEM_LOAD_UOPS_RETIRED",
        .desc = "Load uops retired that hit L1 data cache (Precise Event)",
        .code = 0xd1,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_mem_load_uops_retired),
        .umasks = glm_mem_load_uops_retired,
    },
    {
        .name = "LD_BLOCKS",
        .desc = "Loads blocked (Precise Event)",
        .code = 0x03,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_ld_blocks),
        .umasks = glm_ld_blocks,
    },
    {
        .name = "DL1",
        .desc = "L1 Cache evictions for dirty data",
        .code = 0x51,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_dl1),
        .umasks = glm_dl1,
    },
    {
        .name = "CYCLES_DIV_BUSY",
        .desc = "Cycles a divider is busy",
        .code = 0xcd,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_cycles_div_busy),
        .umasks = glm_cycles_div_busy,
    },
    {
        .name = "MS_DECODED",
        .desc = "MS decode starts",
        .code = 0xe7,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_ms_decoded),
        .umasks = glm_ms_decoded,
    },
    {
        .name = "UOPS_RETIRED",
        .desc = "Uops retired (Precise Event)",
        .code = 0xc2,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_uops_retired),
        .umasks = glm_uops_retired,
    },
    {
        .name = "OFFCORE_RESPONSE_1",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .code = 0x2b7,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xffull,
        .flags = INTEL_X86_NHM_OFFCORE,
        .ngrp = 3,
        .numasks = LIBPFM_ARRAY_SIZE(glm_offcore_response_1),
        .umasks = glm_offcore_response_1,
    },
    {
        .name = "MACHINE_CLEARS",
        .desc = "Self-Modifying Code detected",
        .code = 0xc3,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_machine_clears),
        .umasks = glm_machine_clears,
    },
    {
        .name = "BR_INST_RETIRED",
        .desc = "Retired branch instructions (Precise Event)",
        .code = 0xc4,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_br_inst_retired),
        .umasks = glm_br_inst_retired,
    },
    {
        .name = "FETCH_STALL",
        .desc = "Cycles where code-fetch is stalled and an ICache miss is outstanding.  "
                "This is not the same as an ICache Miss",
        .code = 0x86,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_fetch_stall),
        .umasks = glm_fetch_stall,
    },
    {
        .name = "UOPS_NOT_DELIVERED",
        .desc = "Uops requested but not-delivered to the back-end per cycle",
        .code = 0x9c,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_uops_not_delivered),
        .umasks = glm_uops_not_delivered,
    },
    {
        .name = "MISPREDICTED_BRANCH_RETIRED",
        .desc = "Number of mispredicted branch instructions retired",
        .code = 0xc5,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xffull,
        .equiv = "BR_MISP_RETIRED:ALL_BRANCHES",
        .ngrp = 0,
    },
    {
        .name = "INSTRUCTIONS_RETIRED",
        .desc = "Number of instructions retired",
        .code = 0xc0,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x100000ffull,
        .equiv = "INSTRUCTION_RETIRED",
        .ngrp = 0,
    },
    {
        .name = "MEM_UOPS_RETIRED",
        .desc = "Load uops retired (Precise Event)",
        .code = 0xd0,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .flags = INTEL_X86_PEBS,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_mem_uops_retired),
        .umasks = glm_mem_uops_retired,
    },
    {
        .name = "UOPS_ISSUED",
        .desc = "Uops issued to the back end per cycle",
        .code = 0x0e,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_uops_issued),
        .umasks = glm_uops_issued,
    },
    {
        .name = "OFFCORE_RESPONSE_0",
        .desc = "Offcore response event (must provide at least one request type and "
                "either any_response or any combination of supplier + snoop)",
        .code = 0x1b7,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xffull,
        .flags = INTEL_X86_NHM_OFFCORE,
        .ngrp = 4,
        .numasks = LIBPFM_ARRAY_SIZE(glm_offcore_response_0),
        .umasks = glm_offcore_response_0,
    },
    {
        .name = "UNHALTED_REFERENCE_CYCLES",
        .desc = "Unhalted reference cycles. Ticks at constant reference frequency",
        .code = 0x0300,
        .modmsk = INTEL_FIXED2_ATTRS,
        .cntmsk = 0x40000000ull,
        .flags = INTEL_X86_FIXED,
        .ngrp = 0,
    },
    {
        .name = "BRANCH_INSTRUCTIONS_RETIRED",
        .desc = "Number of branch instructions retired",
        .code = 0xc4,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xffull,
        .equiv = "BR_INST_RETIRED:ALL_BRANCHES",
        .ngrp = 0,
    },
    {
        .name = "CORE_REJECT_L2Q",
        .desc = "Requests rejected by the L2Q ",
        .code = 0x31,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_core_reject_l2q),
        .umasks = glm_core_reject_l2q,
    },
    {
        .name = "PAGE_WALKS",
        .desc = "Duration of D-side page-walks in cycles",
        .code = 0x05,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_page_walks),
        .umasks = glm_page_walks,
    },
    {
        .name = "BACLEARS",
        .desc = "BACLEARs asserted for any branch type",
        .code = 0xe6,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0xfull,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_baclears),
        .umasks = glm_baclears,
    },
    {
        .name = "CPU_CLK_UNHALTED",
        .desc = "Core cycles when core is not halted  (Fixed event)",
        .code = 0x00,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x60000000full,
        .ngrp = 1,
        .numasks = LIBPFM_ARRAY_SIZE(glm_cpu_clk_unhalted),
        .umasks = glm_cpu_clk_unhalted,
    },
    {
        .name = "UNHALTED_CORE_CYCLES",
        .desc = "Core clock cycles whenever the clock signal on the specific core is "
                "running (not halted)",
        .code = 0x3c,
        .modmsk = INTEL_V2_ATTRS,
        .cntmsk = 0x20000000ull,
        .ngrp = 0,
    },
};
