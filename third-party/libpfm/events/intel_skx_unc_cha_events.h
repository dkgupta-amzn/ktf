/*
 * Copyright (c) 2017 Google LLC
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
 * PMU: skx_unc_cha
 */

#define CHA_FILT_MESIF(a, b, c, d)                                                       \
    {                                                                                    \
        .uname = "STATE_" #a, .udesc = #b " cacheline state",                            \
        .ufilters[0] = 1ULL << (17 + (c)), .grpid = d,                                   \
    }

#define CHA_FILT_MESIFS(d)                                                               \
    CHA_FILT_MESIF(LLC_I, LLC Invalid, 0, d), CHA_FILT_MESIF(SF_S, SF Shared, 1, d),     \
        CHA_FILT_MESIF(SF_E, SF Exclusive, 2, d), CHA_FILT_MESIF(SF_H, SF H, 3, d),      \
        CHA_FILT_MESIF(LLC_S, LLC Shared, 4, d),                                         \
        CHA_FILT_MESIF(LLC_E, LLC Exclusive, 5, d),                                      \
        CHA_FILT_MESIF(LLC_M, LLC Modified, 6, d),                                       \
        CHA_FILT_MESIF(LLC_F, LLC Forward, 7, d), {                                      \
        .uname = "STATE_CACHE_ANY", .udesc = "Any cache line state",                     \
        .ufilters[0] = 0x7fULL << 17, .grpid = d,                                        \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,                                      \
    }

#define CHA_FILT1(d)                                                                     \
    {                                                                                    \
        .uname = "FILT_REM",                                                             \
        .udesc = "Filter1 matches on remote node target",                                \
        .ufilters[1] = 0x1ULL << 0,                                                      \
        .uflags = INTEL_X86_DFL,                                                         \
        .grpid = d,                                                                      \
    },                                                                                   \
        {                                                                                \
            .uname = "FILT_LOC",                                                         \
            .udesc = "Filter1 matches on local node target",                             \
            .ufilters[1] = 0x1ULL << 1,                                                  \
            .uflags = INTEL_X86_DFL,                                                     \
            .grpid = d,                                                                  \
        },                                                                               \
        {                                                                                \
            .uname = "FILT_LOC_MEM",                                                     \
            .udesc = "Filter1 matches on near memory",                                   \
            .ufilters[1] = 0x1ULL << 4,                                                  \
            .uflags = INTEL_X86_DFL,                                                     \
            .grpid = d,                                                                  \
        },                                                                               \
    {                                                                                    \
        .uname = "FILT_REM_MEM", .udesc = "Filter1 matches on remote memory",            \
        .ufilters[1] = 0x1ULL << 5, .uflags = INTEL_X86_DFL, .grpid = d,                 \
    }

#define CHA_FILT_OPC_IRQ(n, d, r, shift)                                                 \
    {                                                                                    \
        .uname = "OPC" #n "_RFO",                                                        \
        .udesc = "IRQ Opcode: Demand data RFO (line to be cache in E state)",            \
        .ufilters[1] = 0x200ULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    },                                                                                   \
        {                                                                                \
            .uname = "OPC" #n "_CRD",                                                    \
            .udesc = "IRQ Opcode: Demand code read",                                     \
            .ufilters[1] = 0x201ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_DRD",                                                    \
            .udesc =                                                                     \
                "IRQ Opcode: Demand data read (line to be cached in S or E states)",     \
            .ufilters[1] = 0x202ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_PRD",                                                    \
            .udesc = "IRQ Opcode: Partial reads 0-32 bytes uncacheable (IIO can be up "  \
                     "to 64 bytes)",                                                     \
            .ufilters[1] = 0x207ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WCILF",                                                  \
            .udesc = "IRQ Opcode: Full cacheline streaming store",                       \
            .ufilters[1] = 0x20cULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WCIL",                                                   \
            .udesc = "IRQ Opcode: Partial streaming store",                              \
            .ufilters[1] = 0x20dULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_UCRDF",                                                  \
            .udesc = "IRQ Opcode: Uncacheable Reads full cacheline",                     \
            .ufilters[1] = 0x20dULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WIL",                                                    \
            .udesc = "IRQ Opcode: Write Invalidate Line (Partial)",                      \
            .ufilters[1] = 0x20fULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_PUSH_HINT",                                           \
            .udesc = "IRQ Opcode: TBD",                                                  \
            .ufilters[1] = 0x243ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_MTOI",                                                \
            .udesc = "IRQ Opcode: Request writeback modified invalidate line, evict "    \
                     "fill M-state line from core",                                      \
            .ufilters[1] = 0x244ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_MTOE",                                                \
            .udesc = "IRQ Opcode: Request writeback modified set to exclusive (combine " \
                     "with any OPCODE umask)",                                           \
            .ufilters[1] = 0x245ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_EFTOI",                                               \
            .udesc = "IRQ Opcode: Request clean E or F state lines writeback, "          \
                     "ownership gone when writeback completes",                          \
            .ufilters[1] = 0x246ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_EFTOE",                                               \
            .udesc = "IRQ Opcode: Request clean E or F state lines writeback, core may " \
                     "retain ownership when writeback completes",                        \
            .ufilters[1] = 0x247ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_ITOM",                                                   \
            .udesc = "IRQ Opcode: Request invalidate line. Request exclusive ownership " \
                     "of the line",                                                      \
            .ufilters[1] = 0x248ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_LLC_PF_RFO",                                             \
            .udesc =                                                                     \
                "IRQ Opcode: LLC prefetch RFO, uncore first looks up the line in LLC. "  \
                "For a hit, the LRU is updated. For a miss, the RFO is initiated",       \
            .ufilters[1] = 0x258ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_LLC_PF_CODE",                                            \
            .udesc =                                                                     \
                "IRQ Opcode: LLC prefetch code, uncore first looks up the line in LLC. " \
                "For a hit, the LRU is updated. For a miss, the CRd is initiated",       \
            .ufilters[1] = 0x259ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_LLC_PF_DATA",                                            \
            .udesc =                                                                     \
                "IRQ Opcode: LLC prefetch data, uncore first looks up the line in LLC. " \
                "For a hit, the LRU is updated. For a miss, the DRd is initiated",       \
            .ufilters[1] = 0x25aULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_INT_LOG",                                                \
            .udesc = "IRQ Opcode: Interrupts logically addressed",                       \
            .ufilters[1] = 0x279ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_INT_PHY",                                                \
            .udesc = "IRQ Opcode: Interrupts physically addressed",                      \
            .ufilters[1] = 0x27aULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_PRI_UP",                                                 \
            .udesc = "IRQ Opcode: Interrupt priority update",                            \
            .ufilters[1] = 0x27bULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_SPLIT_LOCK",                                             \
            .udesc = "IRQ Opcode: Request to start split lock sequence",                 \
            .ufilters[1] = 0x27eULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
    {                                                                                    \
        .uname = "OPC" #n "_LOCK",                                                       \
        .udesc = "IRQ Opcode: Request to start IDI lock sequence",                       \
        .ufilters[1] = 0x27fULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    }

#define CHA_FILT_OPC_IPQ(n, d, r, shift)                                                 \
    {                                                                                    \
        .uname = "OPC" #n "_SNP_CUR",                                                    \
        .udesc = "IPQ Opcode: Snoop request to get uncacheable 'sanpshot' of data",      \
        .ufilters[1] = 0x180ULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    },                                                                                   \
        {                                                                                \
            .uname = "OPC" #n "_SNP_CODE",                                               \
            .udesc = "IPQ Opcode: Snoop request to get cacheline intended to be cached " \
                     "in S-state",                                                       \
            .ufilters[1] = 0x181ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_SNP_DATA",                                               \
            .udesc = "IPQ Opcode: Snoop request to get cacheline intended to be cached " \
                     "in E or S-state",                                                  \
            .ufilters[1] = 0x182ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_SNP_DATA_MIG",                                           \
            .udesc = "IPQ Opcode: Snoop request to get cacheline intended to be cached " \
                     "in M, E or S-state",                                               \
            .ufilters[1] = 0x183ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_SNP_INV_OWN",                                            \
            .udesc =                                                                     \
                "IPQ Opcode: Snoop invalidate own. To get cacheline in M or E-state",    \
            .ufilters[1] = 0x184ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
    {                                                                                    \
        .uname = "OPC" #n "_SNP_INV",                                                    \
        .udesc = "IPQ Opcode: Snoop invalidate. To get cacheline intended to be cached " \
                 "in E-state",                                                           \
        .ufilters[1] = 0x185ULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    }

#define CHA_FILT_OPC_PRQ(n, d, r, shift)                                                 \
    {                                                                                    \
        .uname = "OPC" #n "_RD_CUR",                                                     \
        .udesc = "PRQ Opcode: Read current. Request cacheline in I-state. Used to "      \
                 "obtain a coherent snapshot of an uncached line",                       \
        .ufilters[1] = 0x080ULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    },                                                                                   \
        {                                                                                \
            .uname = "OPC" #n "_RD_CODE",                                                \
            .udesc = "PRQ Opcode: Read code. Request cacheline in S-state",              \
            .ufilters[1] = 0x081ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_DATA",                                                \
            .udesc = "PRQ Opcode: Read data. Request cacheline in E or S-state",         \
            .ufilters[1] = 0x082ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_DATA_MIG",                                            \
            .udesc = "PRQ Opcode: Read data migratory. Request cacheline in E or "       \
                     "S-state, except peer cache can forward cacheline in M-state "      \
                     "without any writeback to memory",                                  \
            .ufilters[1] = 0x083ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_INV_OWN",                                             \
            .udesc =                                                                     \
                "PRQ Opcode: Read invalidate own. Invalidate cacheline in M or E-state", \
            .ufilters[1] = 0x084ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_INV_XTOI",                                            \
            .udesc = "PRQ Opcode: Read invalidate X to I-state",                         \
            .ufilters[1] = 0x085ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_PUSH_HINT",                                           \
            .udesc = "PRQ Opcode: Read push hint",                                       \
            .ufilters[1] = 0x086ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_INV_ITOE",                                            \
            .udesc = "PRQ Opcode: Read invalidate I to E-state",                         \
            .ufilters[1] = 0x087ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_RD_INV",                                                 \
            .udesc = "PRQ Opcode: Read invalidate. Request cacheline in E-state from "   \
                     "home agent",                                                       \
            .ufilters[1] = 0x08cULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
    {                                                                                    \
        .uname = "OPC" #n "_RD_INV_ITOM",                                                \
        .udesc = "PRQ Opcode: Read invalidate I to M-state",                             \
        .ufilters[1] = 0x08fULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    }

#define CHA_FILT_OPC_WBQ(n, d, r, shift)                                                 \
    {                                                                                    \
        .uname = "OPC" #n "_WB_MTOS",                                                    \
        .udesc = "Writeback M to S-state. Write full cacheline in M-state to memory "    \
                 "and transition it to S-state",                                         \
        .ufilters[1] = 0x001ULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    },                                                                                   \
        {                                                                                \
            .uname = "OPC" #n "_NON_SNP_WR",                                             \
            .udesc = "Non snoop write. Write cacheline to memory",                       \
            .ufilters[1] = 0x003ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_MTOI_PARTIAL",                                        \
            .udesc = "Writeback M to I-state. Write full cacheline in M-state to "       \
                     "memory according to byte-enable mask and transition to I-state",   \
            .ufilters[1] = 0x004ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_MTOE_PARTIAL",                                        \
            .udesc = "Writeback M to E-state. Write full cacheline in M-state to "       \
                     "memory according to byte-enable mask and transition to E-state",   \
            .ufilters[1] = 0x006ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_NON_SNP_WR_PARTIAL",                                     \
            .udesc = "Non snoop write. Write cacheline to memory according to "          \
                     "byte-enable mask",                                                 \
            .ufilters[1] = 0x007ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_PUSH_MTOI",                                           \
            .udesc = "Writeback push M to I-state. Push cacheline in M-stat to the "     \
                     "home agent. Agent may push data to local cache in M-state or "     \
                     "write to memory. Transition to I-state",                           \
            .ufilters[1] = 0x008ULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_WB_FLUSH",                                               \
            .udesc = "Writeback flush. Hint for flushing writes to memory. No data is "  \
                     "sent with the request",                                            \
            .ufilters[1] = 0x00bULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
        {                                                                                \
            .uname = "OPC" #n "_EVICT_CLEAN",                                            \
            .udesc = "Evict clean. Notification to home node that a cacheline in "       \
                     "E-state was invalidated",                                          \
            .ufilters[1] = 0x00cULL << shift,                                            \
            .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,     \
            .grpid = (d & 0xff) | ((r & 0xff) << 8),                                     \
        },                                                                               \
    {                                                                                    \
        .uname = "OPC" #n "_NON_SNP_RD",                                                 \
        .udesc = "Non snoop read. Request a read-only cacheline from memory",            \
        .ufilters[1] = 0x00dULL << shift,                                                \
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_GRP_DFL_NONE | INTEL_X86_GRP_REQ,         \
        .grpid = (d & 0xff) | ((r & 0xff) << 8),                                         \
    }

static intel_x86_umask_t skx_unc_c_ag0_ad_crd_acquired[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 AD Credits Acquired -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag0_ad_crd_occupancy[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 AD Credits Occupancy -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag0_bl_crd_acquired[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 BL Credits Acquired -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag0_bl_crd_occupancy[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent0 BL Credits Occupancy -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag1_ad_crd_acquired[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent1 AD Credits Acquired -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag1_ad_crd_occupancy[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent1 AD Credits Occupancy -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag1_bl_crd_occupancy[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent1 BL Credits Occupancy -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_ag1_bl_credits_acquired[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "CMS Agent1 BL Credits Acquired -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_bypass_cha_imc[] = {
    {
        .uname = "INTERMEDIATE",
        .ucode = 0x200,
        .udesc = "CHA to iMC Bypass -- Intermediate bypass Taken",
    },
    {
        .uname = "NOT_TAKEN",
        .ucode = 0x400,
        .udesc = "CHA to iMC Bypass -- Not Taken",
    },
    {
        .uname = "TAKEN",
        .ucode = 0x100,
        .udesc = "CHA to iMC Bypass -- Taken",
    },
};

static intel_x86_umask_t skx_unc_c_core_pma[] = {
    {
        .uname = "C1_STATE",
        .ucode = 0x100,
        .udesc = "Core PMA Events -- C1  State",
    },
    {
        .uname = "C1_TRANSITION",
        .ucode = 0x200,
        .udesc = "Core PMA Events -- C1 Transition",
    },
    {
        .uname = "C6_STATE",
        .ucode = 0x400,
        .udesc = "Core PMA Events -- C6 State",
    },
    {
        .uname = "C6_TRANSITION",
        .ucode = 0x800,
        .udesc = "Core PMA Events -- C6 Transition",
    },
    {
        .uname = "GV",
        .ucode = 0x1000,
        .udesc = "Core PMA Events -- GV",
    },
};

static intel_x86_umask_t skx_unc_c_core_snp[] = {
    {
        .uname = "ANY_GTONE",
        .ucode = 0xe200,
        .udesc = "Core Cross Snoops Issued -- Any Cycle with Multiple Snoops",
    },
    {
        .uname = "ANY_ONE",
        .ucode = 0xe100,
        .udesc = "Core Cross Snoops Issued -- Any Single Snoop",
    },
    {
        .uname = "ANY_REMOTE",
        .ucode = 0xe400,
        .udesc = "Core Cross Snoops Issued -- Any Snoop to Remote Node",
    },
    {
        .uname = "CORE_GTONE",
        .ucode = 0x4200,
        .udesc = "Core Cross Snoops Issued -- Multiple Core Requests",
    },
    {
        .uname = "CORE_ONE",
        .ucode = 0x4100,
        .udesc = "Core Cross Snoops Issued -- Single Core Requests",
    },
    {
        .uname = "CORE_REMOTE",
        .ucode = 0x4400,
        .udesc = "Core Cross Snoops Issued -- Core Request to Remote Node",
    },
    {
        .uname = "EVICT_GTONE",
        .ucode = 0x8200,
        .udesc = "Core Cross Snoops Issued -- Multiple Eviction",
    },
    {
        .uname = "EVICT_ONE",
        .ucode = 0x8100,
        .udesc = "Core Cross Snoops Issued -- Single Eviction",
    },
    {
        .uname = "EVICT_REMOTE",
        .ucode = 0x8400,
        .udesc = "Core Cross Snoops Issued -- Eviction to Remote Node",
    },
    {
        .uname = "EXT_GTONE",
        .ucode = 0x2200,
        .udesc = "Core Cross Snoops Issued -- Multiple External Snoops",
    },
    {
        .uname = "EXT_ONE",
        .ucode = 0x2100,
        .udesc = "Core Cross Snoops Issued -- Single External Snoops",
    },
    {
        .uname = "EXT_REMOTE",
        .ucode = 0x2400,
        .udesc = "Core Cross Snoops Issued -- External Snoop to Remote Node",
    },
};

static intel_x86_umask_t skx_unc_c_dir_lookup[] = {
    {
        .uname = "NO_SNP",
        .ucode = 0x200,
        .udesc = "Directory Lookups -- Snoop Not Needed",
    },
    {
        .uname = "SNP",
        .ucode = 0x100,
        .udesc = "Directory Lookups -- Snoop Needed",
    },
};

static intel_x86_umask_t skx_unc_c_dir_update[] = {
    {
        .uname = "HA",
        .ucode = 0x100,
        .udesc = "Directory Updates -- from HA pipe",
    },
    {
        .uname = "TOR",
        .ucode = 0x200,
        .udesc = "Directory Updates -- from TOR pipe",
    },
};

static intel_x86_umask_t skx_unc_c_egress_ordering[] = {
    {
        .uname = "IV_SNOOPGO_DN",
        .ucode = 0x400,
        .udesc = "Egress Blocking due to Ordering requirements -- Down",
    },
    {
        .uname = "IV_SNOOPGO_UP",
        .ucode = 0x100,
        .udesc = "Egress Blocking due to Ordering requirements -- Up",
    },
};

static intel_x86_umask_t skx_unc_c_fast_asserted[] = {
    {
        .uname = "HORZ",
        .ucode = 0x200,
        .udesc = "FaST wire asserted -- Horizontal",
    },
    {
        .uname = "VERT",
        .ucode = 0x100,
        .udesc = "FaST wire asserted -- Vertical",
    },
};

static intel_x86_umask_t skx_unc_c_hitme_hit[] = {
    {
        .uname = "EX_RDS",
        .ucode = 0x100,
        .udesc = "Counts Number of Hits in HitMe Cache -- Exclusive hit and op is "
                 "RdCode, RdData, RdDataMigratory, RdCur, RdInv*, Inv*",
    },
    {
        .uname = "SHARED_OWNREQ",
        .ucode = 0x400,
        .udesc = "Counts Number of Hits in HitMe Cache -- Shared hit and op is RdInvOwn, "
                 "RdInv, Inv*",
    },
    {
        .uname = "WBMTOE",
        .ucode = 0x800,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is WbMtoE",
    },
    {
        .uname = "WBMTOI_OR_S",
        .ucode = 0x1000,
        .udesc = "Counts Number of Hits in HitMe Cache -- op is WbMtoI, WbPushMtoI, "
                 "WbFlush, or WbMtoS",
    },
};

static intel_x86_umask_t skx_unc_c_hitme_lookup[] = {
    {
        .uname = "READ",
        .ucode = 0x100,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is RdCode, "
                 "RdData, RdDataMigratory, RdCur, RdInvOwn, RdInv, Inv*",
    },
    {
        .uname = "WRITE",
        .ucode = 0x200,
        .udesc = "Counts Number of times HitMe Cache is accessed -- op is WbMtoE, "
                 "WbMtoI, WbPushMtoI, WbFlush, or WbMtoS",
    },
};

static intel_x86_umask_t skx_unc_c_hitme_miss[] = {
    {
        .uname = "NOTSHARED_RDINVOWN",
        .ucode = 0x4000,
        .udesc = "Counts Number of Misses in HitMe Cache -- No SF/LLC HitS/F and op is "
                 "RdInvOwn",
    },
    {
        .uname = "READ_OR_INV",
        .ucode = 0x8000,
        .udesc = "Counts Number of Misses in HitMe Cache -- op is RdCode, RdData, "
                 "RdDataMigratory, RdCur, RdInv, Inv*",
    },
    {
        .uname = "SHARED_RDINVOWN",
        .ucode = 0x2000,
        .udesc =
            "Counts Number of Misses in HitMe Cache -- SF/LLC HitS/F and op is RdInvOwn",
    },
};

static intel_x86_umask_t skx_unc_c_hitme_update[] = {
    {
        .uname = "DEALLOCATE",
        .ucode = 0x1000,
        .udesc = "Counts the number of Allocate/Update to HitMe Cache -- Deallocate "
                 "HtiME Reads without RspFwdI*",
    },
    {
        .uname = "DEALLOCATE_RSPFWDI_LOC",
        .ucode = 0x100,
        .udesc = "Counts the number of Allocate/Update to HitMe Cache -- op is RspIFwd "
                 "or RspIFwdWb for a local request",
    },
    {
        .uname = "RDINVOWN",
        .ucode = 0x800,
        .udesc = "Counts the number of Allocate/Update to HitMe Cache -- Update HitMe "
                 "Cache on RdInvOwn even if not RspFwdI*",
    },
    {
        .uname = "RSPFWDI_REM",
        .ucode = 0x200,
        .udesc = "Counts the number of Allocate/Update to HitMe Cache -- op is RspIFwd "
                 "or RspIFwdWb for a remote request",
    },
    {
        .uname = "SHARED",
        .ucode = 0x400,
        .udesc = "Counts the number of Allocate/Update to HitMe Cache -- Update HitMe "
                 "Cache to SHARed",
    },
};

static intel_x86_umask_t skx_unc_c_horz_ring_ad_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal AD Ring In Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal AD Ring In Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal AD Ring In Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal AD Ring In Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_horz_ring_ak_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal AK Ring In Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal AK Ring In Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal AK Ring In Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal AK Ring In Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_horz_ring_bl_in_use[] = {
    {
        .uname = "LEFT_EVEN",
        .ucode = 0x100,
        .udesc = "Horizontal BL Ring in Use -- Left and Even",
    },
    {
        .uname = "LEFT_ODD",
        .ucode = 0x200,
        .udesc = "Horizontal BL Ring in Use -- Left and Odd",
    },
    {
        .uname = "RIGHT_EVEN",
        .ucode = 0x400,
        .udesc = "Horizontal BL Ring in Use -- Right and Even",
    },
    {
        .uname = "RIGHT_ODD",
        .ucode = 0x800,
        .udesc = "Horizontal BL Ring in Use -- Right and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_horz_ring_iv_in_use[] = {
    {
        .uname = "LEFT",
        .ucode = 0x100,
        .udesc = "Horizontal IV Ring in Use -- Left",
    },
    {
        .uname = "RIGHT",
        .ucode = 0x400,
        .udesc = "Horizontal IV Ring in Use -- Right",
    },
};

static intel_x86_umask_t skx_unc_c_imc_reads_count[] = {
    {
        .uname = "NORMAL",
        .ucode = 0x100,
        .udesc = "HA to iMC Reads Issued -- Normal",
    },
    {
        .uname = "PRIORITY",
        .ucode = 0x200,
        .udesc = "HA to iMC Reads Issued -- ISOCH",
    },
};

static intel_x86_umask_t skx_unc_c_imc_writes_count[] = {
    {
        .uname = "FULL",
        .ucode = 0x100,
        .udesc = "Writes Issued to the iMC by the HA -- Full Line Non-ISOCH",
    },
    {
        .uname = "FULL_MIG",
        .ucode = 0x1000,
        .udesc = "Writes Issued to the iMC by the HA -- Full Line MIG",
    },
    {
        .uname = "FULL_PRIORITY",
        .ucode = 0x400,
        .udesc = "Writes Issued to the iMC by the HA -- ISOCH Full Line",
    },
    {
        .uname = "PARTIAL",
        .ucode = 0x200,
        .udesc = "Writes Issued to the iMC by the HA -- Partial Non-ISOCH",
    },
    {
        .uname = "PARTIAL_MIG",
        .ucode = 0x2000,
        .udesc = "Writes Issued to the iMC by the HA -- Partial MIG",
    },
    {
        .uname = "PARTIAL_PRIORITY",
        .ucode = 0x800,
        .udesc = "Writes Issued to the iMC by the HA -- ISOCH Partial",
    },
};

static intel_x86_umask_t skx_unc_c_iodc_alloc[] = {
    {
        .uname = "INVITOM",
        .ucode = 0x100,
        .udesc = "Counts Number of times IODC entry allocation is attempted -- Number of "
                 "IODC allocations",
    },
    {
        .uname = "IODCFULL",
        .ucode = 0x200,
        .udesc = "Counts Number of times IODC entry allocation is attempted -- Number of "
                 "IODC allocations dropped due to IODC Full",
    },
    {
        .uname = "OSBGATED",
        .ucode = 0x400,
        .udesc = "Counts Number of times IODC entry allocation is attempted -- Number of "
                 "IDOC allocation dropped due to OSB gate",
    },
};

static intel_x86_umask_t skx_unc_c_iodc_dealloc[] = {
    {
        .uname = "ALL",
        .ucode = 0x1000,
        .udesc =
            "Counts number of IODC deallocations -- IODC deallocated due to any reason",
    },
    {
        .uname = "SNPOUT",
        .ucode = 0x800,
        .udesc = "Counts number of IODC deallocations -- IODC deallocated due to "
                 "conflicting transaction",
    },
    {
        .uname = "WBMTOE",
        .ucode = 0x100,
        .udesc = "Counts number of IODC deallocations -- IODC deallocated due to WbMtoE",
    },
    {
        .uname = "WBMTOI",
        .ucode = 0x200,
        .udesc = "Counts number of IODC deallocations -- IODC deallocated due to WbMtoI",
    },
    {
        .uname = "WBPUSHMTOI",
        .ucode = 0x400,
        .udesc =
            "Counts number of IODC deallocations -- IODC deallocated due to WbPushMtoI",
    },
};

static intel_x86_umask_t skx_unc_c_llc_lookup[] = {
    {
        .uname = "ANY",
        .ucode = 0x1100,
        .udesc = "Cache and Snoop Filter Lookups -- Any Request",
        .grpid = 0,
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "DATA_READ",
        .ucode = 0x300,
        .udesc = "Cache and Snoop Filter Lookups -- Data Read Request",
        .grpid = 0,
    },
    {
        .uname = "LOCAL",
        .ucode = 0x3100,
        .udesc = "Cache and Snoop Filter Lookups -- Local",
        .grpid = 0,
    },
    {
        .uname = "REMOTE",
        .ucode = 0x9100,
        .udesc = "Cache and Snoop Filter Lookups -- Remote",
        .grpid = 0,
    },
    {
        .uname = "REMOTE_SNOOP",
        .ucode = 0x900,
        .udesc = "Cache and Snoop Filter Lookups -- External Snoop Request",
        .grpid = 0,
    },
    {
        .uname = "WRITE",
        .ucode = 0x500,
        .udesc = "Cache and Snoop Filter Lookups -- Write Requests",
        .grpid = 0,
    },
    CHA_FILT_MESIFS(1),
};

static intel_x86_umask_t skx_unc_c_llc_victims[] = {
    {
        .uname = "LOCAL_ALL",
        .ucode = 0x2f00,
        .udesc = "Lines Victimized -- Local - All Lines",
    },
    {
        .uname = "LOCAL_E",
        .ucode = 0x2200,
        .udesc = "Lines Victimized -- Local - Lines in E State",
    },
    {
        .uname = "LOCAL_F",
        .ucode = 0x2800,
        .udesc = "Lines Victimized -- Local - Lines in F State",
    },
    {
        .uname = "LOCAL_M",
        .ucode = 0x2100,
        .udesc = "Lines Victimized -- Local - Lines in M State",
    },
    {
        .uname = "LOCAL_S",
        .ucode = 0x2400,
        .udesc = "Lines Victimized -- Local - Lines in S State",
    },
    {
        .uname = "REMOTE_ALL",
        .ucode = 0x8f00,
        .udesc = "Lines Victimized -- Remote - All Lines",
    },
    {
        .uname = "REMOTE_E",
        .ucode = 0x8200,
        .udesc = "Lines Victimized -- Remote - Lines in E State",
    },
    {
        .uname = "REMOTE_F",
        .ucode = 0x8800,
        .udesc = "Lines Victimized -- Remote - Lines in F State",
    },
    {
        .uname = "REMOTE_M",
        .ucode = 0x8100,
        .udesc = "Lines Victimized -- Remote - Lines in M State",
    },
    {
        .uname = "REMOTE_S",
        .ucode = 0x8400,
        .udesc = "Lines Victimized -- Remote - Lines in S State",
    },
    {
        .uname = "TOTAL_E",
        .ucode = 0xa200,
        .udesc = "Lines Victimized -- Lines in E State",
    },
    {
        .uname = "TOTAL_F",
        .ucode = 0xa800,
        .udesc = "Lines Victimized -- Lines in F State",
    },
    {
        .uname = "TOTAL_M",
        .ucode = 0xa100,
        .udesc = "Lines Victimized -- Lines in M State",
    },
    {
        .uname = "TOTAL_S",
        .ucode = 0xa400,
        .udesc = "Lines Victimized -- Lines in S State",
    },
};

static intel_x86_umask_t skx_unc_c_misc[] = {
    {
        .uname = "CV0_PREF_MISS",
        .ucode = 0x2000,
        .udesc = "Cbo Misc -- CV0 Prefetch Miss",
    },
    {
        .uname = "CV0_PREF_VIC",
        .ucode = 0x1000,
        .udesc = "Cbo Misc -- CV0 Prefetch Victim",
    },
    {
        .uname = "RFO_HIT_S",
        .ucode = 0x800,
        .udesc = "Cbo Misc -- RFO HitS",
    },
    {
        .uname = "RSPI_WAS_FSE",
        .ucode = 0x100,
        .udesc = "Cbo Misc -- Silent Snoop Eviction",
    },
    {
        .uname = "WC_ALIASING",
        .ucode = 0x200,
        .udesc = "Cbo Misc -- Write Combining Aliasing",
    },
};

static intel_x86_umask_t skx_unc_c_read_no_credits[] = {
    {
        .uname = "EDC0_SMI2",
        .ucode = 0x400,
        .udesc = "CHA iMC CHNx READ Credits Empty -- EDC0_SMI2",
    },
    {
        .uname = "EDC1_SMI3",
        .ucode = 0x800,
        .udesc = "CHA iMC CHNx READ Credits Empty -- EDC1_SMI3",
    },
    {
        .uname = "EDC2_SMI4",
        .ucode = 0x1000,
        .udesc = "CHA iMC CHNx READ Credits Empty -- EDC2_SMI4",
    },
    {
        .uname = "EDC3_SMI5",
        .ucode = 0x2000,
        .udesc = "CHA iMC CHNx READ Credits Empty -- EDC3_SMI5",
    },
    {
        .uname = "MC0_SMI0",
        .ucode = 0x100,
        .udesc = "CHA iMC CHNx READ Credits Empty -- MC0_SMI0",
    },
    {
        .uname = "MC1_SMI1",
        .ucode = 0x200,
        .udesc = "CHA iMC CHNx READ Credits Empty -- MC1_SMI1",
    },
};

static intel_x86_umask_t skx_unc_c_requests[] = {
    {
        .uname = "INVITOE_LOCAL",
        .ucode = 0x1000,
        .udesc = "Read and Write Requests -- InvalItoE Local",
    },
    {
        .uname = "INVITOE_REMOTE",
        .ucode = 0x2000,
        .udesc = "Read and Write Requests -- InvalItoE Remote",
    },
    {
        .uname = "READS",
        .ucode = 0x300,
        .udesc = "Read and Write Requests -- Reads",
        .uflags = INTEL_X86_DFL,
    },
    {
        .uname = "READS_LOCAL",
        .ucode = 0x100,
        .udesc = "Read and Write Requests -- Reads Local",
    },
    {
        .uname = "READS_REMOTE",
        .ucode = 0x200,
        .udesc = "Read and Write Requests -- Reads Remote",
    },
    {
        .uname = "WRITES",
        .ucode = 0xc00,
        .udesc = "Read and Write Requests -- Writes",
    },
    {
        .uname = "WRITES_LOCAL",
        .ucode = 0x400,
        .udesc = "Read and Write Requests -- Writes Local",
    },
    {
        .uname = "WRITES_REMOTE",
        .ucode = 0x800,
        .udesc = "Read and Write Requests -- Writes Remote",
    },
};

static intel_x86_umask_t skx_unc_c_ring_bounces_horz[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Messages that bounced on the Horizontal Ring. -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Messages that bounced on the Horizontal Ring. -- AK",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Messages that bounced on the Horizontal Ring. -- BL",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Messages that bounced on the Horizontal Ring. -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_ring_bounces_vert[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Messages that bounced on the Vertical Ring. -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc =
            "Messages that bounced on the Vertical Ring. -- Acknowledgements to core",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Messages that bounced on the Vertical Ring. -- Data Responses to core",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc =
            "Messages that bounced on the Vertical Ring. -- Snoops of processors cachee.",
    },
};

static intel_x86_umask_t skx_unc_c_ring_sink_starved_horz[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Sink Starvation on Horizontal Ring -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Sink Starvation on Horizontal Ring -- AK",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Sink Starvation on Horizontal Ring -- Acknowledgements to Agent 1",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Sink Starvation on Horizontal Ring -- BL",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Sink Starvation on Horizontal Ring -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_ring_sink_starved_vert[] = {
    {
        .uname = "AD",
        .ucode = 0x100,
        .udesc = "Sink Starvation on Vertical Ring -- AD",
    },
    {
        .uname = "AK",
        .ucode = 0x200,
        .udesc = "Sink Starvation on Vertical Ring -- Acknowledgements to core",
    },
    {
        .uname = "BL",
        .ucode = 0x400,
        .udesc = "Sink Starvation on Vertical Ring -- Data Responses to core",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Sink Starvation on Vertical Ring -- Snoops of processors cachee.",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_inserts[] = {
    {
        .uname = "IPQ",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Allocations -- IPQ",
    },
    {
        .uname = "IRQ",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Allocations -- IRQ",
    },
    {
        .uname = "IRQ_REJ",
        .ucode = 0x200,
        .udesc = "Ingress (from CMS) Allocations -- IRQ Rejected",
    },
    {
        .uname = "PRQ",
        .ucode = 0x1000,
        .udesc = "Ingress (from CMS) Allocations -- PRQ",
    },
    {
        .uname = "PRQ_REJ",
        .ucode = 0x2000,
        .udesc = "Ingress (from CMS) Allocations -- PRQ",
    },
    {
        .uname = "RRQ",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Allocations -- RRQ",
    },
    {
        .uname = "WBQ",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Allocations -- WBQ",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ipq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "Ingress Probe Queue Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "Ingress Probe Queue Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "Ingress Probe Queue Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "Ingress Probe Queue Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "Ingress Probe Queue Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "Ingress Probe Queue Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "Ingress Probe Queue Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "Ingress Probe Queue Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ipq1_reject[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "Ingress Probe Queue Rejects -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "Ingress Probe Queue Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "Ingress Probe Queue Rejects -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc = "Ingress Probe Queue Rejects -- Merging these two together to make room "
                 "for ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "Ingress Probe Queue Rejects -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "Ingress Probe Queue Rejects -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "Ingress Probe Queue Rejects -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "Ingress Probe Queue Rejects -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_irq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_irq1_reject[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Merging these two together "
                 "to make room for ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ismq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "ISMQ Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "ISMQ Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "ISMQ Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "ISMQ Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "ISMQ Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "ISMQ Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "ISMQ Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "ISMQ Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ismq0_retry[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "ISMQ Retries -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "ISMQ Retries -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "ISMQ Retries -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "ISMQ Retries -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "ISMQ Retries -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "ISMQ Retries -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "ISMQ Retries -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "ISMQ Retries -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ismq1_reject[] = {
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "ISMQ Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "ISMQ Rejects -- HA",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_ismq1_retry[] = {
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "ISMQ Retries -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "ISMQ Retries -- HA",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_occupancy[] = {
    {
        .uname = "IPQ",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Occupancy -- IPQ",
    },
    {
        .uname = "IRQ",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Occupancy -- IRQ",
    },
    {
        .uname = "RRQ",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Occupancy -- RRQ",
    },
    {
        .uname = "WBQ",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Occupancy -- WBQ",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_other0_retry[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "Other Retries -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "Other Retries -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "Other Retries -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "Other Retries -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "Other Retries -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "Other Retries -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "Other Retries -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "Other Retries -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_other1_retry[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "Other Retries -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "Other Retries -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "Other Retries -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc =
            "Other Retries -- Merging these two together to make room for ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "Other Retries -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "Other Retries -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "Other Retries -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "Other Retries -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_prq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_prq1_reject[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- LLC OR SF Way",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "Ingress (from CMS) Request Queue Rejects -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_req_q0_retry[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "Request Queue Retries -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "Request Queue Retries -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "Request Queue Retries -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "Request Queue Retries -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "Request Queue Retries -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "Request Queue Retries -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "Request Queue Retries -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "Request Queue Retries -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_req_q1_retry[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "Request Queue Retries -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "Request Queue Retries -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "Request Queue Retries -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc = "Request Queue Retries -- Merging these two together to make room for "
                 "ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "Request Queue Retries -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "Request Queue Retries -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "Request Queue Retries -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "Request Queue Retries -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_rrq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "RRQ Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "RRQ Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "RRQ Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "RRQ Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "RRQ Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "RRQ Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "RRQ Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "RRQ Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_rrq1_reject[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "RRQ Rejects -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "RRQ Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "RRQ Rejects -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc =
            "RRQ Rejects -- Merging these two together to make room for ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "RRQ Rejects -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "RRQ Rejects -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "RRQ Rejects -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "RRQ Rejects -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_wbq0_reject[] = {
    {
        .uname = "AD_REQ_VN0",
        .ucode = 0x100,
        .udesc = "WBQ Rejects -- AD REQ on VN0",
    },
    {
        .uname = "AD_RSP_VN0",
        .ucode = 0x200,
        .udesc = "WBQ Rejects -- AD RSP on VN0",
    },
    {
        .uname = "AK_NON_UPI",
        .ucode = 0x4000,
        .udesc = "WBQ Rejects -- Non UPI AK Request",
    },
    {
        .uname = "BL_NCB_VN0",
        .ucode = 0x1000,
        .udesc = "WBQ Rejects -- BL NCB on VN0",
    },
    {
        .uname = "BL_NCS_VN0",
        .ucode = 0x2000,
        .udesc = "WBQ Rejects -- BL NCS on VN0",
    },
    {
        .uname = "BL_RSP_VN0",
        .ucode = 0x400,
        .udesc = "WBQ Rejects -- BL RSP on VN0",
    },
    {
        .uname = "BL_WB_VN0",
        .ucode = 0x800,
        .udesc = "WBQ Rejects -- BL WB on VN0",
    },
    {
        .uname = "IV_NON_UPI",
        .ucode = 0x8000,
        .udesc = "WBQ Rejects -- Non UPI IV Request",
    },
};

static intel_x86_umask_t skx_unc_c_rxc_wbq1_reject[] = {
    {
        .uname = "ALLOW_SNP",
        .ucode = 0x4000,
        .udesc = "WBQ Rejects -- Allow Snoop",
    },
    {
        .uname = "ANY0",
        .ucode = 0x100,
        .udesc = "WBQ Rejects -- ANY0",
    },
    {
        .uname = "HA",
        .ucode = 0x200,
        .udesc = "WBQ Rejects -- HA",
    },
    {
        .uname = "LLC_OR_SF_WAY",
        .ucode = 0x2000,
        .udesc =
            "WBQ Rejects -- Merging these two together to make room for ANY_REJECT_*0",
    },
    {
        .uname = "LLC_VICTIM",
        .ucode = 0x400,
        .udesc = "WBQ Rejects -- LLC Victim",
    },
    {
        .uname = "PA_MATCH",
        .ucode = 0x8000,
        .udesc = "WBQ Rejects -- PhyAddr Match",
    },
    {
        .uname = "SF_VICTIM",
        .ucode = 0x800,
        .udesc = "WBQ Rejects -- SF Victim",
    },
    {
        .uname = "VICTIM",
        .ucode = 0x1000,
        .udesc = "WBQ Rejects -- Victim",
    },
};

static intel_x86_umask_t skx_unc_c_rxr_busy_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Injection Starvation -- AD - Credit",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Injection Starvation -- BL - Credit",
    },
};

static intel_x86_umask_t skx_unc_c_rxr_bypass[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Bypass -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Bypass -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Bypass -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Bypass -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Bypass -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Bypass -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_rxr_crd_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Injection Starvation -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Injection Starvation -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Injection Starvation -- BL - Credit",
    },
    {
        .uname = "IFV",
        .ucode = 0x8000,
        .udesc = "Transgress Injection Starvation -- IFV - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Injection Starvation -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_rxr_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Allocations -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Allocations -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Allocations -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Allocations -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Allocations -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Allocations -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_rxr_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Transgress Ingress Occupancy -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Transgress Ingress Occupancy -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Transgress Ingress Occupancy -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Transgress Ingress Occupancy -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Transgress Ingress Occupancy -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Transgress Ingress Occupancy -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_sf_eviction[] = {
    {
        .uname = "E_STATE",
        .ucode = 0x200,
        .udesc = "Snoop Filter Eviction -- E state",
    },
    {
        .uname = "M_STATE",
        .ucode = 0x100,
        .udesc = "Snoop Filter Eviction -- M state",
    },
    {
        .uname = "S_STATE",
        .ucode = 0x400,
        .udesc = "Snoop Filter Eviction -- S state",
    },
};

static intel_x86_umask_t skx_unc_c_snoops_sent[] = {
    {
        .uname = "ALL",
        .ucode = 0x100,
        .udesc = "Snoops Sent -- All",
    },
    {
        .uname = "BCST_LOCAL",
        .ucode = 0x1000,
        .udesc = "Snoops Sent -- Broadcast snoop for Local Requests",
    },
    {
        .uname = "BCST_REMOTE",
        .ucode = 0x2000,
        .udesc = "Snoops Sent -- Broadcast snoops for Remote Requests",
    },
    {
        .uname = "DIRECT_LOCAL",
        .ucode = 0x4000,
        .udesc = "Snoops Sent -- Directed snoops for Local Requests",
    },
    {
        .uname = "DIRECT_REMOTE",
        .ucode = 0x8000,
        .udesc = "Snoops Sent -- Directed snoops for Remote Requests",
    },
    {
        .uname = "LOCAL",
        .ucode = 0x400,
        .udesc = "Snoops Sent -- Broadcast or directed Snoops sent for Local Requests",
    },
    {
        .uname = "REMOTE",
        .ucode = 0x800,
        .udesc = "Snoops Sent -- Broadcast or directed Snoops sent for Remote Requests",
    },
};

static intel_x86_umask_t skx_unc_c_snoop_resp[] = {
    {
        .uname = "RSPCNFLCTS",
        .ucode = 0x4000,
        .udesc = "Snoop Responses Received -- RSPCNFLCT*",
    },
    {
        .uname = "RSPFWD",
        .ucode = 0x8000,
        .udesc = "Snoop Responses Received -- RspFwd",
    },
    {
        .uname = "RSPI",
        .ucode = 0x100,
        .udesc = "Snoop Responses Received -- RspI",
    },
    {
        .uname = "RSPIFWD",
        .ucode = 0x400,
        .udesc = "Snoop Responses Received -- RspIFwd",
    },
    {
        .uname = "RSPS",
        .ucode = 0x200,
        .udesc = "Snoop Responses Received -- RspS",
    },
    {
        .uname = "RSPSFWD",
        .ucode = 0x800,
        .udesc = "Snoop Responses Received -- RspSFwd",
    },
    {
        .uname = "RSP_FWD_WB",
        .ucode = 0x2000,
        .udesc = "Snoop Responses Received -- Rsp*Fwd*WB",
    },
    {
        .uname = "RSP_WBWB",
        .ucode = 0x1000,
        .udesc = "Snoop Responses Received -- Rsp*WB",
    },
};

static intel_x86_umask_t skx_unc_c_snoop_resp_local[] = {
    {
        .uname = "RSPFWD",
        .ucode = 0x8000,
        .udesc = "Snoop Responses Received Local -- RspFwd",
    },
    {
        .uname = "RSPI",
        .ucode = 0x100,
        .udesc = "Snoop Responses Received Local -- RspI",
    },
    {
        .uname = "RSPIFWD",
        .ucode = 0x400,
        .udesc = "Snoop Responses Received Local -- RspIFwd",
    },
    {
        .uname = "RSPS",
        .ucode = 0x200,
        .udesc = "Snoop Responses Received Local -- RspS",
    },
    {
        .uname = "RSPSFWD",
        .ucode = 0x800,
        .udesc = "Snoop Responses Received Local -- RspSFwd",
    },
    {
        .uname = "RSP_FWD_WB",
        .ucode = 0x2000,
        .udesc = "Snoop Responses Received Local -- Rsp*FWD*WB",
    },
    {
        .uname = "RSP_WB",
        .ucode = 0x1000,
        .udesc = "Snoop Responses Received Local -- Rsp*WB",
    },
};

static intel_x86_umask_t skx_unc_c_stall_no_txr_horz_crd_ad_ag0[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No AD Agent0 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_stall_no_txr_horz_crd_ad_ag1[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No AD Agent1 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_stall_no_txr_horz_crd_bl_ag0[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No BL Agent0 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_stall_no_txr_horz_crd_bl_ag1[] = {
    {
        .uname = "TGR0",
        .ucode = 0x100,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 0",
    },
    {
        .uname = "TGR1",
        .ucode = 0x200,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 1",
    },
    {
        .uname = "TGR2",
        .ucode = 0x400,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 2",
    },
    {
        .uname = "TGR3",
        .ucode = 0x800,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 3",
    },
    {
        .uname = "TGR4",
        .ucode = 0x1000,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 4",
    },
    {
        .uname = "TGR5",
        .ucode = 0x2000,
        .udesc = "Stall on No BL Agent1 Transgress Credits -- For Transgress 5",
    },
};

static intel_x86_umask_t skx_unc_c_tor_inserts[] = {
    {
        .uname = "ALL_HIT",
        .ucode = 0x1500,
        .udesc = "TOR Inserts -- Hits from Local",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "ALL_IO_IA",
        .ucode = 0x3500,
        .udesc = "TOR Inserts -- All from Local iA and IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "ALL_MISS",
        .ucode = 0x2500,
        .udesc = "TOR Inserts -- Misses from Local",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "EVICT",
        .ucode = 0x200,
        .udesc = "TOR Inserts -- SF/LLC Evictions",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "HIT",
        .ucode = 0x1000,
        .udesc = "TOR Inserts -- Hit (Not a Miss)",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA",
        .ucode = 0x3100,
        .udesc = "TOR Inserts -- All from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA_HIT",
        .ucode = 0x1100,
        .udesc = "TOR Inserts -- Hits from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA_MISS",
        .ucode = 0x2100,
        .udesc = "TOR Inserts -- Misses from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO",
        .ucode = 0x3400,
        .udesc = "TOR Inserts -- All from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO_HIT",
        .ucode = 0x1400,
        .udesc = "TOR Inserts -- Hits from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO_MISS",
        .ucode = 0x2400,
        .udesc = "TOR Inserts -- Misses from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "MISS",
        .ucode = 0x2000,
        .udesc = "TOR Inserts -- Miss",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IPQ",
        .ucode = 0x800,
        .udesc = "TOR Inserts -- IPQ",
        .grpid = 1,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IRQ",
        .ucode = 0x100,
        .udesc = "TOR Inserts -- IRQ",
        .grpid = 2,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "PRQ",
        .ucode = 0x400,
        .udesc = "TOR Inserts -- PRQ",
        .grpid = 3,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    CHA_FILT_OPC_IPQ(0, 4, 1, 9),
    CHA_FILT_OPC_IPQ(1, 5, 1, 19),
    CHA_FILT_OPC_IRQ(0, 4, 2, 9),
    CHA_FILT_OPC_IRQ(1, 5, 2, 19),
    CHA_FILT_OPC_PRQ(0, 4, 3, 9),
    CHA_FILT_OPC_PRQ(1, 5, 3, 19),

    // CHA_FILT_OPC_WBQ(0, 1, 9),
    // CHA_FILT_OPC_WBQ(1, 2, 19),
};

static intel_x86_umask_t skx_unc_c_tor_occupancy[] = {
    {
        .uname = "ALL",
        .ucode = 0x3700,
        .udesc = "TOR Occupancy -- All from Local",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "ALL_HIT",
        .ucode = 0x1700,
        .udesc = "TOR Occupancy -- Hits from Local",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "ALL_MISS",
        .ucode = 0x2700,
        .udesc = "TOR Occupancy -- Misses from Local",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "EVICT",
        .ucode = 0x200,
        .udesc = "TOR Occupancy -- SF/LLC Evictions",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "HIT",
        .ucode = 0x1000,
        .udesc = "TOR Occupancy -- Hit (Not a Miss)",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA",
        .ucode = 0x3100,
        .udesc = "TOR Occupancy -- All from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA_HIT",
        .ucode = 0x1100,
        .udesc = "TOR Occupancy -- Hits from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IA_MISS",
        .ucode = 0x2100,
        .udesc = "TOR Occupancy -- Misses from Local iA",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO",
        .ucode = 0x3400,
        .udesc = "TOR Occupancy -- All from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO_HIT",
        .ucode = 0x1400,
        .udesc = "TOR Occupancy -- Hits from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IO_MISS",
        .ucode = 0x2400,
        .udesc = "TOR Occupancy -- Misses from Local IO",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "MISS",
        .ucode = 0x2000,
        .udesc = "TOR Occupancy -- Miss",
        .grpid = 0,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IPQ",
        .ucode = 0x800,
        .udesc = "TOR Occupancy -- IPQ",
        .grpid = 1,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "IRQ",
        .ucode = 0x100,
        .udesc = "TOR Occupancy -- IRQ",
        .grpid = 2,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    {
        .uname = "PRQ",
        .ucode = 0x400,
        .udesc = "TOR Occupancy -- PRQ",
        .grpid = 3,
        .uflags = INTEL_X86_GRP_DFL_NONE,
    },
    CHA_FILT_OPC_IPQ(0, 4, 1, 9),
    CHA_FILT_OPC_IPQ(1, 5, 1, 19),
    CHA_FILT_OPC_IRQ(0, 4, 2, 9),
    CHA_FILT_OPC_IRQ(1, 5, 2, 19),
    CHA_FILT_OPC_PRQ(0, 4, 3, 9),
    CHA_FILT_OPC_PRQ(1, 5, 3, 19),

    // CHA_FILT_OPC_WBQ(0, 1, 9),
    // CHA_FILT_OPC_WBQ(1, 2, 19),
};

static intel_x86_umask_t skx_unc_c_txr_horz_ads_used[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal ADS Used -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal ADS Used -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal ADS Used -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal ADS Used -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal ADS Used -- BL - Credit",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_bypass[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Bypass Used -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Bypass Used -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Bypass Used -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Bypass Used -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Bypass Used -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Bypass Used -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_cycles_full[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Cycles CMS Horizontal Egress Queue is Full -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_cycles_ne[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "Cycles CMS Horizontal Egress Queue is Not Empty -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_inserts[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Inserts -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Egress Inserts -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Inserts -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Inserts -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress Inserts -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Inserts -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_nack[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress NACKs -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x2000,
        .udesc = "CMS Horizontal Egress NACKs -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress NACKs -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress NACKs -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress NACKs -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress NACKs -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_occupancy[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Occupancy -- AD - Bounce",
    },
    {
        .uname = "AD_CRD",
        .ucode = 0x1000,
        .udesc = "CMS Horizontal Egress Occupancy -- AD - Credit",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Occupancy -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Occupancy -- BL - Bounce",
    },
    {
        .uname = "BL_CRD",
        .ucode = 0x4000,
        .udesc = "CMS Horizontal Egress Occupancy -- BL - Credit",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Occupancy -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_horz_starved[] = {
    {
        .uname = "AD_BNC",
        .ucode = 0x100,
        .udesc = "CMS Horizontal Egress Injection Starvation -- AD - Bounce",
    },
    {
        .uname = "AK_BNC",
        .ucode = 0x200,
        .udesc = "CMS Horizontal Egress Injection Starvation -- AK - Bounce",
    },
    {
        .uname = "BL_BNC",
        .ucode = 0x400,
        .udesc = "CMS Horizontal Egress Injection Starvation -- BL - Bounce",
    },
    {
        .uname = "IV_BNC",
        .ucode = 0x800,
        .udesc = "CMS Horizontal Egress Injection Starvation -- IV - Bounce",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_ads_used[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 1",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_bypass[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical ADS Used -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical ADS Used -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical ADS Used -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical ADS Used -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_cycles_full[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Cycles CMS Vertical Egress Queue Is Full -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_cycles_ne[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "Cycles CMS Vertical Egress Queue Is Not Empty -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_inserts[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vert Egress Allocations -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vert Egress Allocations -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vert Egress Allocations -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vert Egress Allocations -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vert Egress Allocations -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vert Egress Allocations -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vert Egress Allocations -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_nack[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical Egress NACKs -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical Egress NACKs -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical Egress NACKs -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical Egress NACKs -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical Egress NACKs -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical Egress NACKs -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical Egress NACKs -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_occupancy[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vert Egress Occupancy -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vert Egress Occupancy -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vert Egress Occupancy -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vert Egress Occupancy -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vert Egress Occupancy -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vert Egress Occupancy -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vert Egress Occupancy -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_txr_vert_starved[] = {
    {
        .uname = "AD_AG0",
        .ucode = 0x100,
        .udesc = "CMS Vertical Egress Injection Starvation -- AD - Agent 0",
    },
    {
        .uname = "AD_AG1",
        .ucode = 0x1000,
        .udesc = "CMS Vertical Egress Injection Starvation -- AD - Agent 1",
    },
    {
        .uname = "AK_AG0",
        .ucode = 0x200,
        .udesc = "CMS Vertical Egress Injection Starvation -- AK - Agent 0",
    },
    {
        .uname = "AK_AG1",
        .ucode = 0x2000,
        .udesc = "CMS Vertical Egress Injection Starvation -- AK - Agent 1",
    },
    {
        .uname = "BL_AG0",
        .ucode = 0x400,
        .udesc = "CMS Vertical Egress Injection Starvation -- BL - Agent 0",
    },
    {
        .uname = "BL_AG1",
        .ucode = 0x4000,
        .udesc = "CMS Vertical Egress Injection Starvation -- BL - Agent 1",
    },
    {
        .uname = "IV",
        .ucode = 0x800,
        .udesc = "CMS Vertical Egress Injection Starvation -- IV",
    },
};

static intel_x86_umask_t skx_unc_c_vert_ring_ad_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical AD Ring In Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical AD Ring In Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical AD Ring In Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical AD Ring In Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_vert_ring_ak_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical AK Ring In Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical AK Ring In Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical AK Ring In Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical AK Ring In Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_vert_ring_bl_in_use[] = {
    {
        .uname = "DN_EVEN",
        .ucode = 0x400,
        .udesc = "Vertical BL Ring in Use -- Down and Even",
    },
    {
        .uname = "DN_ODD",
        .ucode = 0x800,
        .udesc = "Vertical BL Ring in Use -- Down and Odd",
    },
    {
        .uname = "UP_EVEN",
        .ucode = 0x100,
        .udesc = "Vertical BL Ring in Use -- Up and Even",
    },
    {
        .uname = "UP_ODD",
        .ucode = 0x200,
        .udesc = "Vertical BL Ring in Use -- Up and Odd",
    },
};

static intel_x86_umask_t skx_unc_c_vert_ring_iv_in_use[] = {
    {
        .uname = "DN",
        .ucode = 0x400,
        .udesc = "Vertical IV Ring in Use -- Down",
    },
    {
        .uname = "UP",
        .ucode = 0x100,
        .udesc = "Vertical IV Ring in Use -- Up",
    },
};

static intel_x86_umask_t skx_unc_c_wb_push_mtoi[] = {
    {
        .uname = "LLC",
        .ucode = 0x100,
        .udesc = "WbPushMtoI -- Pushed to LLC",
    },
    {
        .uname = "MEM",
        .ucode = 0x200,
        .udesc = "WbPushMtoI -- Pushed to Memory",
    },
};

static intel_x86_umask_t skx_unc_c_write_no_credits[] = {
    {
        .uname = "EDC0_SMI2",
        .ucode = 0x400,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- EDC0_SMI2",
    },
    {
        .uname = "EDC1_SMI3",
        .ucode = 0x800,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- EDC1_SMI3",
    },
    {
        .uname = "EDC2_SMI4",
        .ucode = 0x1000,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- EDC2_SMI4",
    },
    {
        .uname = "EDC3_SMI5",
        .ucode = 0x2000,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- EDC3_SMI5",
    },
    {
        .uname = "MC0_SMI0",
        .ucode = 0x100,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- MC0_SMI0",
    },
    {
        .uname = "MC1_SMI1",
        .ucode = 0x200,
        .udesc = "CHA iMC CHNx WRITE Credits Empty -- MC1_SMI1",
    },
};

static intel_x86_umask_t skx_unc_c_xsnp_resp[] = {
    {
        .uname = "ANY_RSPI_FWDFE",
        .ucode = 0xe400,
        .udesc = "Core Cross Snoop Responses -- Any RspIFwdFE",
    },
    {
        .uname = "ANY_RSPS_FWDFE",
        .ucode = 0xe200,
        .udesc = "Core Cross Snoop Responses -- Any RspSFwdFE",
    },
    {
        .uname = "ANY_RSPS_FWDM",
        .ucode = 0xe800,
        .udesc = "Core Cross Snoop Responses -- Any RspSFwdM",
    },
    {
        .uname = "ANY_RSP_HITFSE",
        .ucode = 0xe100,
        .udesc = "Core Cross Snoop Responses -- Any RspHitFSE",
    },
    {
        .uname = "CORE_RSPI_FWDFE",
        .ucode = 0x4400,
        .udesc = "Core Cross Snoop Responses -- Core RspIFwdFE",
    },
    {
        .uname = "CORE_RSPI_FWDM",
        .ucode = 0x5000,
        .udesc = "Core Cross Snoop Responses -- Core RspIFwdM",
    },
    {
        .uname = "CORE_RSPS_FWDFE",
        .ucode = 0x4200,
        .udesc = "Core Cross Snoop Responses -- Core RspSFwdFE",
    },
    {
        .uname = "CORE_RSPS_FWDM",
        .ucode = 0x4800,
        .udesc = "Core Cross Snoop Responses -- Core RspSFwdM",
    },
    {
        .uname = "CORE_RSP_HITFSE",
        .ucode = 0x4100,
        .udesc = "Core Cross Snoop Responses -- Core RspHitFSE",
    },
    {
        .uname = "EVICT_RSPI_FWDFE",
        .ucode = 0x8400,
        .udesc = "Core Cross Snoop Responses -- Evict RspIFwdFE",
    },
    {
        .uname = "EVICT_RSPI_FWDM",
        .ucode = 0x9000,
        .udesc = "Core Cross Snoop Responses -- Evict RspIFwdM",
    },
    {
        .uname = "EVICT_RSPS_FWDFE",
        .ucode = 0x8200,
        .udesc = "Core Cross Snoop Responses -- Evict RspSFwdFE",
    },
    {
        .uname = "EVICT_RSPS_FWDM",
        .ucode = 0x8800,
        .udesc = "Core Cross Snoop Responses -- Evict RspSFwdM",
    },
    {
        .uname = "EVICT_RSP_HITFSE",
        .ucode = 0x8100,
        .udesc = "Core Cross Snoop Responses -- Evict RspHitFSE",
    },
    {
        .uname = "EXT_RSPI_FWDFE",
        .ucode = 0x2400,
        .udesc = "Core Cross Snoop Responses -- External RspIFwdFE",
    },
    {
        .uname = "EXT_RSPI_FWDM",
        .ucode = 0x3000,
        .udesc = "Core Cross Snoop Responses -- External RspIFwdM",
    },
    {
        .uname = "EXT_RSPS_FWDFE",
        .ucode = 0x2200,
        .udesc = "Core Cross Snoop Responses -- External RspSFwdFE",
    },
    {
        .uname = "EXT_RSPS_FWDM",
        .ucode = 0x2800,
        .udesc = "Core Cross Snoop Responses -- External RspSFwdM",
    },
    {
        .uname = "EXT_RSP_HITFSE",
        .ucode = 0x2100,
        .udesc = "Core Cross Snoop Responses -- External RspHitFSE",
    },
};

static intel_x86_entry_t intel_skx_unc_c_pe[] = {
    {
        .name = "UNC_C_AG0_AD_CRD_ACQUIRED",
        .code = 0x80,
        .desc =
            "Number of CMS Agent 0 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag0_ad_crd_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag0_ad_crd_acquired),
    },
    {
        .name = "UNC_C_AG0_AD_CRD_OCCUPANCY",
        .code = 0x82,
        .desc =
            "Number of CMS Agent 0 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag0_ad_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag0_ad_crd_occupancy),
    },
    {
        .name = "UNC_C_AG0_BL_CRD_ACQUIRED",
        .code = 0x88,
        .desc =
            "Number of CMS Agent 0 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag0_bl_crd_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag0_bl_crd_acquired),
    },
    {
        .name = "UNC_C_AG0_BL_CRD_OCCUPANCY",
        .code = 0x8a,
        .desc =
            "Number of CMS Agent 0 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag0_bl_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag0_bl_crd_occupancy),
    },
    {
        .name = "UNC_C_AG1_AD_CRD_ACQUIRED",
        .code = 0x84,
        .desc =
            "Number of CMS Agent 1 AD credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag1_ad_crd_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag1_ad_crd_acquired),
    },
    {
        .name = "UNC_C_AG1_AD_CRD_OCCUPANCY",
        .code = 0x86,
        .desc =
            "Number of CMS Agent 1 AD credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag1_ad_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag1_ad_crd_occupancy),
    },
    {
        .name = "UNC_C_AG1_BL_CRD_OCCUPANCY",
        .code = 0x8e,
        .desc =
            "Number of CMS Agent 1 BL credits in use in a given cycle, per transgress",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag1_bl_crd_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag1_bl_crd_occupancy),
    },
    {
        .name = "UNC_C_AG1_BL_CREDITS_ACQUIRED",
        .code = 0x8c,
        .desc =
            "Number of CMS Agent 1 BL credits acquired in a given cycle, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ag1_bl_credits_acquired,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ag1_bl_credits_acquired),
    },
    {
        .name = "UNC_C_BYPASS_CHA_IMC",
        .code = 0x57,
        .desc = "Counts the number of times when the CHA was able to bypass HA pipe on "
                "the way to iMC.  This is a latency optimization for situations when "
                "there is light loadings on the memory subsystem.  This can be filtered "
                "by when the bypass was taken and when it was not.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_bypass_cha_imc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_bypass_cha_imc),
    },
    {
        .name = "UNC_C_CLOCKTICKS",
        .code = 0x0,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_C_CMS_CLOCKTICKS",
        .code = 0xc0,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_C_CORE_PMA",
        .code = 0x17,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_core_pma,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_core_pma),
    },
    {
        .name = "UNC_C_CORE_SNP",
        .code = 0x33,
        .desc =
            "Counts the number of transactions that trigger a configurable number of "
            "cross snoops.  Cores are snooped if the transaction looks up the cache and "
            "determines that it is necessary based on the operation type and what "
            "CoreValid bits are set.  For example, if 2 CV bits are set on a data read, "
            "the cores must have the data in S state so it is not necessary to snoop "
            "them.  However, if only 1 CV bit is set the core my have modified the data. "
            " If the transaction was an RFO, it would need to invalidate the lines.  "
            "This event can be filtered based on who triggered the initial snoop(s).",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_core_snp,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_core_snp),
    },
    {
        .name = "UNC_C_COUNTER0_OCCUPANCY",
        .code = 0x1f,
        .desc = "Since occupancy counts can only be captured in the Cbos 0 counter, this "
                "event allows a user to capture occupancy related information by "
                "filtering the Cb0 occupancy count captured in Counter 0.   The "
                "filtering available is found in the control register - threshold, "
                "invert and edge detect.   E.g. setting threshold to 1 can effectively "
                "monitor how many cycles the monitored queue has an entryy.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_C_DIR_LOOKUP",
        .code = 0x53,
        .desc = "Counts the number of transactions that looked up the Home Agent "
                "directory.  Can be filtered by requests that had to snoop and those "
                "that did not have to.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_dir_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_dir_lookup),
    },
    {
        .name = "UNC_C_DIR_UPDATE",
        .code = 0x54,
        .desc = "Counts the number of directory updates that were required.  These "
                "result in writes to the memory controller.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_dir_update,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_dir_update),
    },
    {
        .name = "UNC_C_EGRESS_ORDERING",
        .code = 0xae,
        .desc = "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO "
                "Ordering requirements",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_egress_ordering,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_egress_ordering),
    },
    {
        .name = "UNC_C_FAST_ASSERTED",
        .code = 0xa5,
        .desc = "Counts the number of cycles either the local or incoming distress "
                "signals are asserted.  Incoming distress includes up, dn and across.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_fast_asserted,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_fast_asserted),
    },
    {
        .name = "UNC_C_HITME_HIT",
        .code = 0x5f,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_hitme_hit,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_hitme_hit),
    },
    {
        .name = "UNC_C_HITME_LOOKUP",
        .code = 0x5e,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_hitme_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_hitme_lookup),
    },
    {
        .name = "UNC_C_HITME_MISS",
        .code = 0x60,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_hitme_miss,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_hitme_miss),
    },
    {
        .name = "UNC_C_HITME_UPDATE",
        .code = 0x61,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_hitme_update,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_hitme_update),
    },
    {
        .name = "UNC_C_HORZ_RING_AD_IN_USE",
        .code = 0xa7,
        .desc = "Counts the number of cycles that the Horizontal AD ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.  We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_horz_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_horz_ring_ad_in_use),
    },
    {
        .name = "UNC_C_HORZ_RING_AK_IN_USE",
        .code = 0xa9,
        .desc = "Counts the number of cycles that the Horizontal AK ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_horz_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_horz_ring_ak_in_use),
    },
    {
        .name = "UNC_C_HORZ_RING_BL_IN_USE",
        .code = 0xab,
        .desc = "Counts the number of cycles that the Horizontal BL ring is being used "
                "at this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from  the ring stop.We really have two rings -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_horz_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_horz_ring_bl_in_use),
    },
    {
        .name = "UNC_C_HORZ_RING_IV_IN_USE",
        .code = 0xad,
        .desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at "
            "this ring stop.  This includes when packets are passing by and when packets "
            "are being sunk, but does not include when packets are being sent from the "
            "ring stop.  There is only 1 IV ring.  Therefore, if one wants to monitor "
            "the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the "
            "Odd ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_horz_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_horz_ring_iv_in_use),
    },
    {
        .name = "UNC_C_IMC_READS_COUNT",
        .code = 0x59,
        .desc = "Count of the number of reads issued to any of the memory controller "
                "channels.  This can be filtered by the priority of the reads.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_imc_reads_count,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_imc_reads_count),
    },
    {
        .name = "UNC_C_IMC_WRITES_COUNT",
        .code = 0x5b,
        .desc = "Counts the total number of writes issued from the HA into the memory "
                "controller.  This counts for all four channels.  It can be filtered by "
                "full/partial and ISOCH/non-ISOCH.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_imc_writes_count,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_imc_writes_count),
    },
    {
        .name = "UNC_C_IODC_ALLOC",
        .code = 0x62,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_iodc_alloc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_iodc_alloc),
    },
    {
        .name = "UNC_C_IODC_DEALLOC",
        .code = 0x63,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_iodc_dealloc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_iodc_dealloc),
    },
    {
        .name = "UNC_C_LLC_LOOKUP",
        .code = 0x34,
        .desc = "Counts the number of times the LLC was accessed - this includes code, "
                "data, prefetches and hints coming from L2.  This has numerous filters "
                "available.  Note the non-standard filtering equation.  This event will "
                "count requests that lookup the cache multiple times with multiple "
                "increments.  One must ALWAYS set umask bit 0 and select a state or "
                "states to match.  Otherwise, the event will count nothing.   "
                "CHAFilter0[24:21,17] bits correspond to [FMESI] state.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 2,
        .umasks = skx_unc_c_llc_lookup,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_llc_lookup),
    },
    {
        .name = "UNC_C_LLC_VICTIMS",
        .code = 0x37,
        .desc = "Counts the number of lines that were victimized on a fill.  This can be "
                "filtered by the state that the line was in.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_llc_victims,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_llc_victims),
    },
    {
        .name = "UNC_C_MISC",
        .code = 0x39,
        .desc = "Miscellaneous events in the CHA.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_misc,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_misc),
    },
    {
        .name = "UNC_C_OSB",
        .code = 0x55,
        .desc = "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB "
                "snoops to be broadcast. Does not count all the snoops generated by OSB.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_C_READ_NO_CREDITS",
        .code = 0x58,
        .desc = "Counts the number of times when there are no credits available for "
                "sending reads from the CHA into the iMC.  In order to send reads into "
                "the memory controller, the HA must first acquire a credit for the iMCs "
                "AD Ingress queuee.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_read_no_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_read_no_credits),
    },
    {
        .name = "UNC_C_REQUESTS",
        .code = 0x50,
        .desc = "Counts the total number of read requests made into the Home Agent. "
                "Reads include all read opcodes (including RFO).  Writes include all "
                "writes (streaming, evictions, HitM, etc).",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_requests,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_requests),
    },
    {
        .name = "UNC_C_RING_BOUNCES_HORZ",
        .code = 0xa1,
        .desc = "Number of cycles incoming messages from the Horizontal ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ring_bounces_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ring_bounces_horz),
    },
    {
        .name = "UNC_C_RING_BOUNCES_VERT",
        .code = 0xa0,
        .desc = "Number of cycles incoming messages from the Vertical ring that were "
                "bounced, by ring type.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ring_bounces_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ring_bounces_vert),
    },
    {
        .name = "UNC_C_RING_SINK_STARVED_HORZ",
        .code = 0xa3,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ring_sink_starved_horz,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ring_sink_starved_horz),
    },
    {
        .name = "UNC_C_RING_SINK_STARVED_VERT",
        .code = 0xa2,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_ring_sink_starved_vert,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_ring_sink_starved_vert),
    },
    {
        .name = "UNC_C_RING_SRC_THRTL",
        .code = 0xa4,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_C_RXC_INSERTS",
        .code = 0x13,
        .desc =
            "Counts number of allocations per cycle into the specified Ingress queue.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_inserts),
    },
    {
        .name = "UNC_C_RXC_IPQ0_REJECT",
        .code = 0x22,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ipq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ipq0_reject),
    },
    {
        .name = "UNC_C_RXC_IPQ1_REJECT",
        .code = 0x23,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ipq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ipq1_reject),
    },
    {
        .name = "UNC_C_RXC_IRQ0_REJECT",
        .code = 0x18,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_irq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_irq0_reject),
    },
    {
        .name = "UNC_C_RXC_IRQ1_REJECT",
        .code = 0x19,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_irq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_irq1_reject),
    },
    {
        .name = "UNC_C_RXC_ISMQ0_REJECT",
        .code = 0x24,
        .desc = "Number of times a transaction flowing through the ISMQ had to retry.  "
                "Transaction pass through the ISMQ as responses for requests that "
                "already exist in the Cbo.  Some examples include: when data is returned "
                "or when snoop responses come back from the cores.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ismq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ismq0_reject),
    },
    {
        .name = "UNC_C_RXC_ISMQ0_RETRY",
        .code = 0x2c,
        .desc = "Number of times a transaction flowing through the ISMQ had to retry.  "
                "Transaction pass through the ISMQ as responses for requests that "
                "already exist in the Cbo.  Some examples include: when data is returned "
                "or when snoop responses come back from the cores.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ismq0_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ismq0_retry),
    },
    {
        .name = "UNC_C_RXC_ISMQ1_REJECT",
        .code = 0x25,
        .desc = "Number of times a transaction flowing through the ISMQ had to retry.  "
                "Transaction pass through the ISMQ as responses for requests that "
                "already exist in the Cbo.  Some examples include: when data is returned "
                "or when snoop responses come back from the cores.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ismq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ismq1_reject),
    },
    {
        .name = "UNC_C_RXC_ISMQ1_RETRY",
        .code = 0x2d,
        .desc = "Number of times a transaction flowing through the ISMQ had to retry.  "
                "Transaction pass through the ISMQ as responses for requests that "
                "already exist in the Cbo.  Some examples include: when data is returned "
                "or when snoop responses come back from the cores.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_ismq1_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_ismq1_retry),
    },
    {
        .name = "UNC_C_RXC_OCCUPANCY",
        .code = 0x11,
        .desc = "Counts number of entries in the specified Ingress queue in each cycle.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0x1,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_occupancy),
    },
    {
        .name = "UNC_C_RXC_OTHER0_RETRY",
        .code = 0x2e,
        .desc = "Retry Queue Inserts of Transactions that were already in another Retry "
                "Q (sub-events encode the reason for the next reject)",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_other0_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_other0_retry),
    },
    {
        .name = "UNC_C_RXC_OTHER1_RETRY",
        .code = 0x2f,
        .desc = "Retry Queue Inserts of Transactions that were already in another Retry "
                "Q (sub-events encode the reason for the next reject)",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_other1_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_other1_retry),
    },
    {
        .name = "UNC_C_RXC_PRQ0_REJECT",
        .code = 0x20,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_prq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_prq0_reject),
    },
    {
        .name = "UNC_C_RXC_PRQ1_REJECT",
        .code = 0x21,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_prq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_prq1_reject),
    },
    {
        .name = "UNC_C_RXC_REQ_Q0_RETRY",
        .code = 0x2a,
        .desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMSMQ)",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_req_q0_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_req_q0_retry),
    },
    {
        .name = "UNC_C_RXC_REQ_Q1_RETRY",
        .code = 0x2b,
        .desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMSMQ)",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_req_q1_retry,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_req_q1_retry),
    },
    {
        .name = "UNC_C_RXC_RRQ0_REJECT",
        .code = 0x26,
        .desc = "Number of times a transaction flowing through the RRQ (Remote Response "
                "Queue) had to retry.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_rrq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_rrq0_reject),
    },
    {
        .name = "UNC_C_RXC_RRQ1_REJECT",
        .code = 0x27,
        .desc = "Number of times a transaction flowing through the RRQ (Remote Response "
                "Queue) had to retry.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_rrq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_rrq1_reject),
    },
    {
        .name = "UNC_C_RXC_WBQ0_REJECT",
        .code = 0x28,
        .desc = "Number of times a transaction flowing through the WBQ (Writeback Queue) "
                "had to retry.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_wbq0_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_wbq0_reject),
    },
    {
        .name = "UNC_C_RXC_WBQ1_REJECT",
        .code = 0x29,
        .desc = "Number of times a transaction flowing through the WBQ (Writeback Queue) "
                "had to retry.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxc_wbq1_reject,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxc_wbq1_reject),
    },
    {
        .name = "UNC_C_RXR_BUSY_STARVED",
        .code = 0xb4,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, because a message from the "
                "other queue has higher priority",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxr_busy_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxr_busy_starved),
    },
    {
        .name = "UNC_C_RXR_BYPASS",
        .code = 0xb2,
        .desc = "Number of packets bypassing the CMS Ingress",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxr_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxr_bypass),
    },
    {
        .name = "UNC_C_RXR_CRD_STARVED",
        .code = 0xb3,
        .desc = "Counts cycles under injection starvation mode.  This starvation is "
                "triggered when the CMS Ingress cannot send a transaction onto the mesh "
                "for a long period of time.  In this case, the Ingress is unable to "
                "forward to the Egress due to a lack of credit.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxr_crd_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxr_crd_starved),
    },
    {
        .name = "UNC_C_RXR_INSERTS",
        .code = 0xb1,
        .desc = "Number of allocations into the CMS Ingress  The Ingress is used to "
                "queue up requests received from the mesh",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxr_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxr_inserts),
    },
    {
        .name = "UNC_C_RXR_OCCUPANCY",
        .code = 0xb0,
        .desc = "Occupancy event for the Ingress buffers in the CMS  The Ingress is used "
                "to queue up requests received from the mesh",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_rxr_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_rxr_occupancy),
    },
    {
        .name = "UNC_C_SF_EVICTION",
        .code = 0x3d,
        .desc = "TBD",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_sf_eviction,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_sf_eviction),
    },
    {
        .name = "UNC_C_SNOOPS_SENT",
        .code = 0x51,
        .desc = "Counts the number of snoops issued by the HA.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_snoops_sent,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_snoops_sent),
    },
    {
        .name = "UNC_C_SNOOP_RESP",
        .code = 0x5c,
        .desc = "Counts the total number of RspI snoop responses received.  Whenever a "
                "snoops are issued, one or more snoop responses will be returned "
                "depending on the topology of the system.   In systems larger than 2s, "
                "when multiple snoops are returned this will count all the snoops that "
                "are received.  For example, if 3 snoops were issued and returned RspI, "
                "RspS, and RspSFwd; then each of these sub-events would increment by 1.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_snoop_resp,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_snoop_resp),
    },
    {
        .name = "UNC_C_SNOOP_RESP_LOCAL",
        .code = 0x5d,
        .desc = "Number of snoop responses received for a Local  request",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_snoop_resp_local,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_snoop_resp_local),
    },
    {
        .name = "UNC_C_STALL_NO_TXR_HORZ_CRD_AD_AG0",
        .code = 0xd0,
        .desc = "Number of cycles the AD Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_stall_no_txr_horz_crd_ad_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_stall_no_txr_horz_crd_ad_ag0),
    },
    {
        .name = "UNC_C_STALL_NO_TXR_HORZ_CRD_AD_AG1",
        .code = 0xd2,
        .desc = "Number of cycles the AD Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_stall_no_txr_horz_crd_ad_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_stall_no_txr_horz_crd_ad_ag1),
    },
    {
        .name = "UNC_C_STALL_NO_TXR_HORZ_CRD_BL_AG0",
        .code = 0xd4,
        .desc = "Number of cycles the BL Agent 0 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_stall_no_txr_horz_crd_bl_ag0,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_stall_no_txr_horz_crd_bl_ag0),
    },
    {
        .name = "UNC_C_STALL_NO_TXR_HORZ_CRD_BL_AG1",
        .code = 0xd6,
        .desc = "Number of cycles the BL Agent 1 Egress Buffer is stalled waiting for a "
                "TGR credit to become available, per transgress.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_stall_no_txr_horz_crd_bl_ag1,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_stall_no_txr_horz_crd_bl_ag1),
    },
    {
        .name = "UNC_C_TOR_INSERTS",
        .code = 0x35,
        .desc = "Counts the number of entries successfuly inserted into the TOR that "
                "match qualifications specified by the subevent.",
        .modmsk = SKX_UNC_CHA_FILT1_ATTRS,
        .cntmsk = 0xf,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .ngrp = 6,
        .umasks = skx_unc_c_tor_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_tor_inserts),
    },
    {
        .name = "UNC_C_TOR_OCCUPANCY",
        .code = 0x36,
        .desc = "For each cycle, this event accumulates the number of valid entries in "
                "the TOR that match qualifications specified by the subevent.   T",
        .modmsk = SKX_UNC_CHA_FILT1_ATTRS,
        .cntmsk = 0x1,
        .flags = INTEL_X86_NO_AUTOENCODE,
        .ngrp = 6,
        .umasks = skx_unc_c_tor_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_tor_occupancy),
    },
    {
        .name = "UNC_C_TXR_HORZ_ADS_USED",
        .code = 0x9d,
        .desc = "Number of packets using the Horizontal Anti-Deadlock Slot, broken down "
                "by ring type and CMS Agent.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_ads_used),
    },
    {
        .name = "UNC_C_TXR_HORZ_BYPASS",
        .code = 0x9f,
        .desc = "Number of packets bypassing the Horizontal Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_bypass),
    },
    {
        .name = "UNC_C_TXR_HORZ_CYCLES_FULL",
        .code = 0x96,
        .desc =
            "Cycles the Transgress buffers in the Common Mesh Stop are Full.  The egress "
            "is used to queue up requests destined for the Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_cycles_full),
    },
    {
        .name = "UNC_C_TXR_HORZ_CYCLES_NE",
        .code = 0x97,
        .desc = "Cycles the Transgress buffers in the Common Mesh Stop are Not-Empty.  "
                "The egress is used to queue up requests destined for the Horizontal "
                "Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_cycles_ne),
    },
    {
        .name = "UNC_C_TXR_HORZ_INSERTS",
        .code = 0x95,
        .desc = "Number of allocations into the Transgress buffers in the Common Mesh "
                "Stop  The egress is used to queue up requests destined for the "
                "Horizontal Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_inserts),
    },
    {
        .name = "UNC_C_TXR_HORZ_NACK",
        .code = 0x99,
        .desc = "Counts number of Egress packets NACKed on to the Horizontal Rinng",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_nack),
    },
    {
        .name = "UNC_C_TXR_HORZ_OCCUPANCY",
        .code = 0x94,
        .desc = "Occupancy event for the Transgress buffers in the Common Mesh Stop  The "
                "egress is used to queue up requests destined for the Horizontal Ring on "
                "the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_occupancy),
    },
    {
        .name = "UNC_C_TXR_HORZ_STARVED",
        .code = 0x9b,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Transgress buffer cannot send a transaction onto the Horizontal ring "
                "for a long period of time.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_horz_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_horz_starved),
    },
    {
        .name = "UNC_C_TXR_VERT_ADS_USED",
        .code = 0x9c,
        .desc = "Number of packets using the Vertical Anti-Deadlock Slot, broken down by "
                "ring type and CMS Agent.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_ads_used,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_ads_used),
    },
    {
        .name = "UNC_C_TXR_VERT_BYPASS",
        .code = 0x9e,
        .desc = "Number of packets bypassing the Vertical Egress, broken down by ring "
                "type and CMS Agent.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_bypass),
    },
    {
        .name = "UNC_C_TXR_VERT_CYCLES_FULL",
        .code = 0x92,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Full.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_cycles_full,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_cycles_full),
    },
    {
        .name = "UNC_C_TXR_VERT_CYCLES_NE",
        .code = 0x93,
        .desc =
            "Number of cycles the Common Mesh Stop Egress was Not Empty.  The Egress is "
            "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_cycles_ne,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_cycles_ne),
    },
    {
        .name = "UNC_C_TXR_VERT_INSERTS",
        .code = 0x91,
        .desc = "Number of allocations into the Common Mesh Stop Egress.  The Egress is "
                "used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_inserts),
    },
    {
        .name = "UNC_C_TXR_VERT_NACK",
        .code = 0x98,
        .desc = "Counts number of Egress packets NACKed on to the Vertical Rinng",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_nack,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_nack),
    },
    {
        .name = "UNC_C_TXR_VERT_OCCUPANCY",
        .code = 0x90,
        .desc =
            "Occupancy event for the Egress buffers in the Common Mesh Stop  The egress "
            "is used to queue up requests destined for the Vertical Ring on the Mesh.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_occupancy),
    },
    {
        .name = "UNC_C_TXR_VERT_STARVED",
        .code = 0x9a,
        .desc = "Counts injection starvation.  This starvation is triggered when the CMS "
                "Egress cannot send a transaction onto the Vertical ring for a long "
                "period of time.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_txr_vert_starved,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_txr_vert_starved),
    },
    {
        .name = "UNC_C_VERT_RING_AD_IN_USE",
        .code = 0xa6,
        .desc = "Counts the number of cycles that the Vertical AD ring is being used at "
                "this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.  We really have two rings  -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_vert_ring_ad_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_vert_ring_ad_in_use),
    },
    {
        .name = "UNC_C_VERT_RING_AK_IN_USE",
        .code = 0xa8,
        .desc = "Counts the number of cycles that the Vertical AK ring is being used at "
                "this ring stop.  This includes when packets are passing by and when "
                "packets are being sunk, but does not include when packets are being "
                "sent from the ring stop.We really have two rings in -- a clockwise ring "
                "and a counter-clockwise ring.  On the left side of the ring, the UP "
                "direction is on the clockwise ring and DN is on the counter-clockwise "
                "ring.  On the right side of the ring, this is reversed.  The first half "
                "of the CBos are on the left side of the ring, and the 2nd half are on "
                "the right side of the ring.  In other words (for example), in a 4c "
                "part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are "
                "on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_vert_ring_ak_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_vert_ring_ak_in_use),
    },
    {
        .name = "UNC_C_VERT_RING_BL_IN_USE",
        .code = 0xaa,
        .desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this "
            "ring stop.  This includes when packets are passing by and when packets are "
            "being sunk, but does not include when packets are being sent from  the ring "
            "stop.We really have two rings -- a clockwise ring and a counter-clockwise "
            "ring.  On the left side of the ring, the UP direction is on the clockwise "
            "ring and DN is on the counter-clockwise ring.  On the right side of the "
            "ring, this is reversed.  The first half of the CBos are on the left side of "
            "the ring, and the 2nd half are on the right side of the ring.  In other "
            "words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo "
            "2 UP AD because they are on opposite sides of the rhe ring.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_vert_ring_bl_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_vert_ring_bl_in_use),
    },
    {
        .name = "UNC_C_VERT_RING_IV_IN_USE",
        .code = 0xac,
        .desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this "
            "ring stop.  This includes when packets are passing by and when packets are "
            "being sunk, but does not include when packets are being sent from the ring "
            "stop.  There is only 1 IV ring.  Therefore, if one wants to monitor the "
            "Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd "
            "ring, they should select both UP_ODD and DN_ DN_ODD.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_vert_ring_iv_in_use,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_vert_ring_iv_in_use),
    },
    {
        .name = "UNC_C_WB_PUSH_MTOI",
        .code = 0x56,
        .desc = "Counts the number of times when the CHA was received WbPushMtoI",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_wb_push_mtoi,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_wb_push_mtoi),
    },
    {
        .name = "UNC_C_WRITE_NO_CREDITS",
        .code = 0x5a,
        .desc = "Counts the number of times when there are no credits available for "
                "sending WRITEs from the CHA into the iMC.  In order to send WRITEs into "
                "the memory controller, the HA must first acquire a credit for the iMCs "
                "BL Ingress queuee.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_write_no_credits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_write_no_credits),
    },
    {
        .name = "UNC_C_XSNP_RESP",
        .code = 0x32,
        .desc = "Counts the number of core cross snoops.  Cores are snooped if the "
                "transaction looks up the cache and determines that it is necessary "
                "based on the operation type. This event can be filtered based on who "
                "triggered the initial snoop(s):  from Evictions, Core  or External "
                "(i.e. from a remote node) Requests.  And the event can be filtered "
                "based on the responses:  RspX_Fwd/HitY where Y is the state prior to "
                "the snoop response and X is the state following.",
        .modmsk = SKX_UNC_CHA_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_c_xsnp_resp,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_c_xsnp_resp),
    },
};
