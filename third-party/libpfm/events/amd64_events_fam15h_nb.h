/*
 * Copyright (c) 2013 Google, Inc
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
 * PMU: amd64_fam15h_nb_nb (AMD64 Fam15h Interlagos NorthBridge)
 *
 * Based on libpfm patch by Robert Richter <robert.richter@amd.com>:
 * Family 15h Microarchitecture performance monitor events
 *
 * History:
 *
 * Nov 30 2013 -- Stephane Eranian , eranian@gmail.com:
 * Split core and Northbridge events as PMU is distinct
 *
 * Apr 29 2011 -- Robert Richter, robert.richter@amd.com:
 * Source: BKDG for AMD Family 15h Models 00h-0Fh Processors,
 * 42301, Rev 1.15, April 18, 2011
 *
 * Dec 09 2010 -- Robert Richter, robert.richter@amd.com:
 * Source: BIOS and Kernel Developer's Guide for the AMD Family 15h
 * Processors, Rev 0.90, May 18, 2010
 */

#define CORE_SELECT(b)                                                                   \
    {                                                                                    \
        .uname = "CORE_0",                                                               \
        .udesc = "Measure on Core0",                                                     \
        .ucode = 0 << 4,                                                                 \
        .grpid = b,                                                                      \
        .uflags = AMD64_FL_NCOMBO,                                                       \
    },                                                                                   \
        {                                                                                \
            .uname = "CORE_1",                                                           \
            .udesc = "Measure on Core1",                                                 \
            .ucode = 1 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_2",                                                           \
            .udesc = "Measure on Core2",                                                 \
            .ucode = 2 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_3",                                                           \
            .udesc = "Measure on Core3",                                                 \
            .ucode = 3 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_4",                                                           \
            .udesc = "Measure on Core4",                                                 \
            .ucode = 4 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_5",                                                           \
            .udesc = "Measure on Core5",                                                 \
            .ucode = 5 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_6",                                                           \
            .udesc = "Measure on Core6",                                                 \
            .ucode = 6 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
        {                                                                                \
            .uname = "CORE_7",                                                           \
            .udesc = "Measure on Core7",                                                 \
            .ucode = 7 << 4,                                                             \
            .grpid = b,                                                                  \
            .uflags = AMD64_FL_NCOMBO,                                                   \
        },                                                                               \
    {                                                                                    \
        .uname = "ANY_CORE", .udesc = "Measure on any core", .ucode = 0xf << 4,          \
        .grpid = b, .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,                            \
    }

static const amd64_umask_t amd64_fam15h_nb_dram_accesses[] = {
    {
        .uname = "DCT0_PAGE_HIT",
        .udesc = "DCT0 Page hit",
        .ucode = 0x1,
    },
    {
        .uname = "DCT0_PAGE_MISS",
        .udesc = "DCT0 Page Miss",
        .ucode = 0x2,
    },
    {
        .uname = "DCT0_PAGE_CONFLICT",
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
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_dram_controller_page_table_overflows[] = {
    {
        .uname = "DCT0_PAGE_TABLE_OVERFLOW",
        .udesc = "DCT0 Page Table Overflow",
        .ucode = 0x1,
    },
    {
        .uname = "DCT1_PAGE_TABLE_OVERFLOW",
        .udesc = "DCT1 Page Table Overflow",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_memory_controller_dram_command_slots_missed[] =
    {
        {
            .uname = "DCT0_COMMAND_SLOTS_MISSED",
            .udesc = "DCT0 Command Slots Missed (in MemClks)",
            .ucode = 0x1,
        },
        {
            .uname = "DCT1_COMMAND_SLOTS_MISSED",
            .udesc = "DCT1 Command Slots Missed (in MemClks)",
            .ucode = 0x2,
        },
        {
            .uname = "ALL",
            .udesc = "All sub-events selected",
            .ucode = 0x3,
            .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        },
};

static const amd64_umask_t amd64_fam15h_nb_memory_controller_turnarounds[] = {
    {
        .uname = "DCT0_DIMM_TURNAROUND",
        .udesc = "DCT0 DIMM (chip select) turnaround",
        .ucode = 0x1,
    },
    {
        .uname = "DCT0_READ_WRITE_TURNAROUND",
        .udesc = "DCT0 Read to write turnaround",
        .ucode = 0x2,
    },
    {
        .uname = "DCT0_WRITE_READ_TURNAROUND",
        .udesc = "DCT0 Write to read turnaround",
        .ucode = 0x4,
    },
    {
        .uname = "DCT1_DIMM_TURNAROUND",
        .udesc = "DCT1 DIMM (chip select) turnaround",
        .ucode = 0x8,
    },
    {
        .uname = "DCT1_READ_WRITE_TURNAROUND",
        .udesc = "DCT1 Read to write turnaround",
        .ucode = 0x10,
    },
    {
        .uname = "DCT1_WRITE_READ_TURNAROUND",
        .udesc = "DCT1 Write to read turnaround",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_memory_controller_bypass_counter_saturation[] =
    {
        {
            .uname = "MEMORY_CONTROLLER_HIGH_PRIORITY_BYPASS",
            .udesc = "Memory controller high priority bypass",
            .ucode = 0x1,
        },
        {
            .uname = "MEMORY_CONTROLLER_MEDIUM_PRIORITY_BYPASS",
            .udesc = "Memory controller medium priority bypass",
            .ucode = 0x2,
        },
        {
            .uname = "DCT0_DCQ_BYPASS",
            .udesc = "DCT0 DCQ bypass",
            .ucode = 0x4,
        },
        {
            .uname = "DCT1_DCQ_BYPASS",
            .udesc = "DCT1 DCQ bypass",
            .ucode = 0x8,
        },
        {
            .uname = "ALL",
            .udesc = "All sub-events selected",
            .ucode = 0xf,
            .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        },
};

static const amd64_umask_t amd64_fam15h_nb_thermal_status[] = {
    {
        .uname = "NUM_HTC_TRIP_POINT_CROSSED",
        .udesc = "Number of times the HTC trip point is crossed",
        .ucode = 0x4,
    },
    {
        .uname = "NUM_CLOCKS_HTC_PSTATE_INACTIVE",
        .udesc = "Number of clocks HTC P-state is inactive",
        .ucode = 0x20,
    },
    {
        .uname = "NUM_CLOCKS_HTC_PSTATE_ACTIVE",
        .udesc = "Number of clocks HTC P-state is active",
        .ucode = 0x40,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x64,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_cpu_io_requests_to_memory_io[] = {
    {
        .uname = "REMOTE_IO_TO_LOCAL_IO",
        .udesc = "Remote IO to Local IO",
        .ucode = 0x61,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "REMOTE_CPU_TO_LOCAL_IO",
        .udesc = "Remote CPU to Local IO",
        .ucode = 0x64,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_IO_TO_REMOTE_IO",
        .udesc = "Local IO to Remote IO",
        .ucode = 0x91,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_IO_TO_REMOTE_MEM",
        .udesc = "Local IO to Remote Mem",
        .ucode = 0x92,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_CPU_TO_REMOTE_IO",
        .udesc = "Local CPU to Remote IO",
        .ucode = 0x94,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_CPU_TO_REMOTE_MEM",
        .udesc = "Local CPU to Remote Mem",
        .ucode = 0x98,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_IO_TO_LOCAL_IO",
        .udesc = "Local IO to Local IO",
        .ucode = 0xa1,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_IO_TO_LOCAL_MEM",
        .udesc = "Local IO to Local Mem",
        .ucode = 0xa2,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_CPU_TO_LOCAL_IO",
        .udesc = "Local CPU to Local IO",
        .ucode = 0xa4,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "LOCAL_CPU_TO_LOCAL_MEM",
        .udesc = "Local CPU to Local Mem",
        .ucode = 0xa8,
        .uflags = AMD64_FL_NCOMBO,
    },
};

static const amd64_umask_t amd64_fam15h_nb_cache_block_commands[] = {
    {
        .uname = "VICTIM_BLOCK",
        .udesc = "Victim Block (Writeback)",
        .ucode = 0x1,
    },
    {
        .uname = "READ_BLOCK",
        .udesc = "Read Block (Dcache load miss refill)",
        .ucode = 0x4,
    },
    {
        .uname = "READ_BLOCK_SHARED",
        .udesc = "Read Block Shared (Icache refill)",
        .ucode = 0x8,
    },
    {
        .uname = "READ_BLOCK_MODIFIED",
        .udesc = "Read Block Modified (Dcache store miss refill)",
        .ucode = 0x10,
    },
    {
        .uname = "CHANGE_TO_DIRTY",
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

static const amd64_umask_t amd64_fam15h_nb_sized_commands[] = {
    {
        .uname = "NON-POSTED_SZWR_BYTE",
        .udesc = "Non-Posted SzWr Byte (1-32 bytes). Typical Usage: Legacy or mapped IO, "
                 "typically 1-4 bytes.",
        .ucode = 0x1,
    },
    {
        .uname = "NON-POSTED_SZWR_DW",
        .udesc = "Non-Posted SzWr DW (1-16 dwords). Typical Usage: Legacy or mapped IO, "
                 "typically 1",
        .ucode = 0x2,
    },
    {
        .uname = "POSTED_SZWR_BYTE",
        .udesc = "Posted SzWr Byte (1-32 bytes). Typical Usage: Subcache-line DMA "
                 "writes, size varies; also",
        .ucode = 0x4,
    },
    {
        .uname = "POSTED_SZWR_DW",
        .udesc = "Posted SzWr DW (1-16 dwords). Typical Usage: Block-oriented DMA "
                 "writes, often cache-line",
        .ucode = 0x8,
    },
    {
        .uname = "SZRD_BYTE",
        .udesc = "SzRd Byte (4 bytes). Typical Usage: Legacy or mapped IO.",
        .ucode = 0x10,
    },
    {
        .uname = "SZRD_DW",
        .udesc = "SzRd DW (1-16 dwords). Typical Usage: Block-oriented DMA reads, "
                 "typically cache-line size.",
        .ucode = 0x20,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_probe_responses_and_upstream_requests[] = {
    {
        .uname = "PROBE_MISS",
        .udesc = "Probe miss",
        .ucode = 0x1,
    },
    {
        .uname = "PROBE_HIT_CLEAN",
        .udesc = "Probe hit clean",
        .ucode = 0x2,
    },
    {
        .uname = "PROBE_HIT_DIRTY_WITHOUT_MEMORY_CANCEL",
        .udesc = "Probe hit dirty without memory cancel (probed by Sized Write or "
                 "Change2Dirty)",
        .ucode = 0x4,
    },
    {
        .uname = "PROBE_HIT_DIRTY_WITH_MEMORY_CANCEL",
        .udesc = "Probe hit dirty with memory cancel (probed by DMA read or cache refill "
                 "request)",
        .ucode = 0x8,
    },
    {
        .uname = "UPSTREAM_DISPLAY_REFRESH_ISOC_READS",
        .udesc = "Upstream display refresh/ISOC reads",
        .ucode = 0x10,
    },
    {
        .uname = "UPSTREAM_NON-DISPLAY_REFRESH_READS",
        .udesc = "Upstream non-display refresh reads",
        .ucode = 0x20,
    },
    {
        .uname = "UPSTREAM_ISOC_WRITES",
        .udesc = "Upstream ISOC writes",
        .ucode = 0x40,
    },
    {
        .uname = "UPSTREAM_NON-ISOC_WRITES",
        .udesc = "Upstream non-ISOC writes",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_gart_events[] = {
    {
        .uname = "GART_APERTURE_HIT_ON_ACCESS_FROM_CPU",
        .udesc = "GART aperture hit on access from CPU",
        .ucode = 0x1,
    },
    {
        .uname = "GART_APERTURE_HIT_ON_ACCESS_FROM_IO",
        .udesc = "GART aperture hit on access from IO",
        .ucode = 0x2,
    },
    {
        .uname = "GART_MISS",
        .udesc = "GART miss",
        .ucode = 0x4,
    },
    {
        .uname = "GART_REQUEST_HIT_TABLE_WALK_IN_PROGRESS",
        .udesc = "GART Request hit table walk in progress",
        .ucode = 0x8,
    },
    {
        .uname = "GART_MULTIPLE_TABLE_WALK_IN_PROGRESS",
        .udesc = "GART multiple table walk in progress",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x8f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_link_transmit_bandwidth[] = {
    {
        .uname = "COMMAND_DW_SENT",
        .udesc = "Command DW sent",
        .ucode = 0x1,
        .grpid = 0,
    },
    {
        .uname = "DATA_DW_SENT",
        .udesc = "Data DW sent",
        .ucode = 0x2,
        .grpid = 0,
    },
    {
        .uname = "BUFFER_RELEASE_DW_SENT",
        .udesc = "Buffer release DW sent",
        .ucode = 0x4,
        .grpid = 0,
    },
    {
        .uname = "NOP_DW_SENT",
        .udesc = "NOP DW sent (idle)",
        .ucode = 0x8,
        .grpid = 0,
    },
    {
        .uname = "ADDRESS_DW_SENT",
        .udesc = "Address (including extensions) DW sent",
        .ucode = 0x10,
        .grpid = 0,
    },
    {
        .uname = "PER_PACKET_CRC_SENT",
        .udesc = "Per packet CRC sent",
        .ucode = 0x20,
        .grpid = 0,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3f,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        .grpid = 0,
    },
    {
        .uname = "SUBLINK_1",
        .udesc = "When links are unganged, enable this umask to select sublink 1",
        .ucode = 0x80,
        .grpid = 1,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "SUBLINK_0",
        .udesc = "When links are unganged, enable this umask to select sublink 0 "
                 "(default when links ganged)",
        .ucode = 0x00,
        .grpid = 1,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },

};

static const amd64_umask_t amd64_fam15h_nb_cpu_to_dram_requests_to_target_node[] = {
    {
        .uname = "LOCAL_TO_NODE_0",
        .udesc = "From Local node to Node 0",
        .ucode = 0x1,
    },
    {
        .uname = "LOCAL_TO_NODE_1",
        .udesc = "From Local node to Node 1",
        .ucode = 0x2,
    },
    {
        .uname = "LOCAL_TO_NODE_2",
        .udesc = "From Local node to Node 2",
        .ucode = 0x4,
    },
    {
        .uname = "LOCAL_TO_NODE_3",
        .udesc = "From Local node to Node 3",
        .ucode = 0x8,
    },
    {
        .uname = "LOCAL_TO_NODE_4",
        .udesc = "From Local node to Node 4",
        .ucode = 0x10,
    },
    {
        .uname = "LOCAL_TO_NODE_5",
        .udesc = "From Local node to Node 5",
        .ucode = 0x20,
    },
    {
        .uname = "LOCAL_TO_NODE_6",
        .udesc = "From Local node to Node 6",
        .ucode = 0x40,
    },
    {
        .uname = "LOCAL_TO_NODE_7",
        .udesc = "From Local node to Node 7",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_io_to_dram_requests_to_target_node[] = {
    {
        .uname = "LOCAL_TO_NODE_0",
        .udesc = "From Local node to Node 0",
        .ucode = 0x1,
    },
    {
        .uname = "LOCAL_TO_NODE_1",
        .udesc = "From Local node to Node 1",
        .ucode = 0x2,
    },
    {
        .uname = "LOCAL_TO_NODE_2",
        .udesc = "From Local node to Node 2",
        .ucode = 0x4,
    },
    {
        .uname = "LOCAL_TO_NODE_3",
        .udesc = "From Local node to Node 3",
        .ucode = 0x8,
    },
    {
        .uname = "LOCAL_TO_NODE_4",
        .udesc = "From Local node to Node 4",
        .ucode = 0x10,
    },
    {
        .uname = "LOCAL_TO_NODE_5",
        .udesc = "From Local node to Node 5",
        .ucode = 0x20,
    },
    {
        .uname = "LOCAL_TO_NODE_6",
        .udesc = "From Local node to Node 6",
        .ucode = 0x40,
    },
    {
        .uname = "LOCAL_TO_NODE_7",
        .udesc = "From Local node to Node 7",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t
    amd64_fam15h_nb_cpu_read_command_requests_to_target_node_0_3[] = {
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_0",
            .udesc = "Read block From Local node to Node 0",
            .ucode = 0x11,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_0",
            .udesc = "Read block shared From Local node to Node 0",
            .ucode = 0x12,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_0",
            .udesc = "Read block modified From Local node to Node 0",
            .ucode = 0x14,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_0",
            .udesc = "Change-to-Dirty From Local node to Node 0",
            .ucode = 0x18,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_1",
            .udesc = "Read block From Local node to Node 1",
            .ucode = 0x21,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_1",
            .udesc = "Read block shared From Local node to Node 1",
            .ucode = 0x22,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_1",
            .udesc = "Read block modified From Local node to Node 1",
            .ucode = 0x24,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_1",
            .udesc = "Change-to-Dirty From Local node to Node 1",
            .ucode = 0x28,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_2",
            .udesc = "Read block From Local node to Node 2",
            .ucode = 0x41,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_2",
            .udesc = "Read block shared From Local node to Node 2",
            .ucode = 0x42,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_2",
            .udesc = "Read block modified From Local node to Node 2",
            .ucode = 0x44,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_2",
            .udesc = "Change-to-Dirty From Local node to Node 2",
            .ucode = 0x48,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_3",
            .udesc = "Read block From Local node to Node 3",
            .ucode = 0x81,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_3",
            .udesc = "Read block shared From Local node to Node 3",
            .ucode = 0x82,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_3",
            .udesc = "Read block modified From Local node to Node 3",
            .ucode = 0x84,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_3",
            .udesc = "Change-to-Dirty From Local node to Node 3",
            .ucode = 0x88,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "ALL",
            .udesc = "All sub-events selected",
            .ucode = 0xff,
            .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        },
};

static const amd64_umask_t
    amd64_fam15h_nb_cpu_read_command_requests_to_target_node_4_7[] = {
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_4",
            .udesc = "Read block From Local node to Node 4",
            .ucode = 0x11,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_4",
            .udesc = "Read block shared From Local node to Node 4",
            .ucode = 0x12,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_4",
            .udesc = "Read block modified From Local node to Node 4",
            .ucode = 0x14,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_4",
            .udesc = "Change-to-Dirty From Local node to Node 4",
            .ucode = 0x18,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_5",
            .udesc = "Read block From Local node to Node 5",
            .ucode = 0x21,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_5",
            .udesc = "Read block shared From Local node to Node 5",
            .ucode = 0x22,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_5",
            .udesc = "Read block modified From Local node to Node 5",
            .ucode = 0x24,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_5",
            .udesc = "Change-to-Dirty From Local node to Node 5",
            .ucode = 0x28,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_6",
            .udesc = "Read block From Local node to Node 6",
            .ucode = 0x41,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_6",
            .udesc = "Read block shared From Local node to Node 6",
            .ucode = 0x42,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_6",
            .udesc = "Read block modified From Local node to Node 6",
            .ucode = 0x44,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_6",
            .udesc = "Change-to-Dirty From Local node to Node 6",
            .ucode = 0x48,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_LOCAL_TO_NODE_7",
            .udesc = "Read block From Local node to Node 7",
            .ucode = 0x81,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_SHARED_LOCAL_TO_NODE_7",
            .udesc = "Read block shared From Local node to Node 7",
            .ucode = 0x82,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "READ_BLOCK_MODIFIED_LOCAL_TO_NODE_7",
            .udesc = "Read block modified From Local node to Node 7",
            .ucode = 0x84,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "CHANGE_TO_DIRTY_LOCAL_TO_NODE_7",
            .udesc = "Change-to-Dirty From Local node to Node 7",
            .ucode = 0x88,
            .uflags = AMD64_FL_NCOMBO,
        },
        {
            .uname = "ALL",
            .udesc = "All sub-events selected",
            .ucode = 0xff,
            .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        },
};

static const amd64_umask_t amd64_fam15h_nb_cpu_command_requests_to_target_node[] = {
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_0",
        .udesc = "Read Sized From Local node to Node 0",
        .ucode = 0x11,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_0",
        .udesc = "Write Sized From Local node to Node 0",
        .ucode = 0x12,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_0",
        .udesc = "Victim Block From Local node to Node 0",
        .ucode = 0x14,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_1",
        .udesc = "Read Sized From Local node to Node 1",
        .ucode = 0x21,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_1",
        .udesc = "Write Sized From Local node to Node 1",
        .ucode = 0x22,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_1",
        .udesc = "Victim Block From Local node to Node 1",
        .ucode = 0x24,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_2",
        .udesc = "Read Sized From Local node to Node 2",
        .ucode = 0x41,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_2",
        .udesc = "Write Sized From Local node to Node 2",
        .ucode = 0x42,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_2",
        .udesc = "Victim Block From Local node to Node 2",
        .ucode = 0x44,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_3",
        .udesc = "Read Sized From Local node to Node 3",
        .ucode = 0x81,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_3",
        .udesc = "Write Sized From Local node to Node 3",
        .ucode = 0x82,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_3",
        .udesc = "Victim Block From Local node to Node 3",
        .ucode = 0x84,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_4",
        .udesc = "Read Sized From Local node to Node 4",
        .ucode = 0x19,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_4",
        .udesc = "Write Sized From Local node to Node 4",
        .ucode = 0x1a,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_4",
        .udesc = "Victim Block From Local node to Node 4",
        .ucode = 0x1c,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_5",
        .udesc = "Read Sized From Local node to Node 5",
        .ucode = 0x29,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_5",
        .udesc = "Write Sized From Local node to Node 5",
        .ucode = 0x2a,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_5",
        .udesc = "Victim Block From Local node to Node 5",
        .ucode = 0x2c,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_6",
        .udesc = "Read Sized From Local node to Node 6",
        .ucode = 0x49,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_6",
        .udesc = "Write Sized From Local node to Node 6",
        .ucode = 0x4a,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_6",
        .udesc = "Victim Block From Local node to Node 6",
        .ucode = 0x4c,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "READ_SIZED_LOCAL_TO_NODE_7",
        .udesc = "Read Sized From Local node to Node 7",
        .ucode = 0x89,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "WRITE_SIZED_LOCAL_TO_NODE_7",
        .udesc = "Write Sized From Local node to Node 7",
        .ucode = 0x8a,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "VICTIM_BLOCK_LOCAL_TO_NODE_7",
        .udesc = "Victim Block From Local node to Node 7",
        .ucode = 0x8c,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "ALL_LOCAL_TO_NODE_0_3",
        .udesc = "All From Local node to Node 0-3",
        .ucode = 0xf7,
        .uflags = AMD64_FL_NCOMBO,
    },
    {
        .uname = "ALL_LOCAL_TO_NODE_4_7",
        .udesc = "All From Local node to Node 4-7",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_request_cache_status_0[] = {
    {
        .uname = "PROBE_HIT_S",
        .udesc = "Probe Hit S",
        .ucode = 0x1,
    },
    {
        .uname = "PROBE_HIT_E",
        .udesc = "Probe Hit E",
        .ucode = 0x2,
    },
    {
        .uname = "PROBE_HIT_MUW_OR_O",
        .udesc = "Probe Hit MuW or O",
        .ucode = 0x4,
    },
    {
        .uname = "PROBE_HIT_M",
        .udesc = "Probe Hit M",
        .ucode = 0x8,
    },
    {
        .uname = "PROBE_MISS",
        .udesc = "Probe Miss",
        .ucode = 0x10,
    },
    {
        .uname = "DIRECTED_PROBE",
        .udesc = "Directed Probe",
        .ucode = 0x20,
    },
    {
        .uname = "TRACK_CACHE_STAT_FOR_RDBLK",
        .udesc = "Track Cache Stat for RdBlk",
        .ucode = 0x40,
    },
    {
        .uname = "TRACK_CACHE_STAT_FOR_RDBLKS",
        .udesc = "Track Cache Stat for RdBlkS",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_request_cache_status_1[] = {
    {
        .uname = "PROBE_HIT_S",
        .udesc = "Probe Hit S",
        .ucode = 0x1,
    },
    {
        .uname = "PROBE_HIT_E",
        .udesc = "Probe Hit E",
        .ucode = 0x2,
    },
    {
        .uname = "PROBE_HIT_MUW_OR_O",
        .udesc = "Probe Hit MuW or O",
        .ucode = 0x4,
    },
    {
        .uname = "PROBE_HIT_M",
        .udesc = "Probe Hit M",
        .ucode = 0x8,
    },
    {
        .uname = "PROBE_MISS",
        .udesc = "Probe Miss",
        .ucode = 0x10,
    },
    {
        .uname = "DIRECTED_PROBE",
        .udesc = "Directed Probe",
        .ucode = 0x20,
    },
    {
        .uname = "TRACK_CACHE_STAT_FOR_CHGTODIRTY",
        .udesc = "Track Cache Stat for ChgToDirty",
        .ucode = 0x40,
    },
    {
        .uname = "TRACK_CACHE_STAT_FOR_RDBLKM",
        .udesc = "Track Cache Stat for RdBlkM",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_memory_controller_requests[] = {
    {
        .uname = "WRITE_REQUESTS_TO_DCT",
        .udesc = "Write requests sent to the DCT",
        .ucode = 0x1,
    },
    {
        .uname = "READ_REQUESTS_TO_DCT",
        .udesc = "Read requests (including prefetch requests) sent to the DCT",
        .ucode = 0x2,
    },
    {
        .uname = "PREFETCH_REQUESTS_TO_DCT",
        .udesc = "Prefetch requests sent to the DCT",
        .ucode = 0x4,
    },
    {
        .uname = "32_BYTES_SIZED_WRITES",
        .udesc = "32 Bytes Sized Writes",
        .ucode = 0x8,
    },
    {
        .uname = "64_BYTES_SIZED_WRITES",
        .udesc = "64 Bytes Sized Writes",
        .ucode = 0x10,
    },
    {
        .uname = "32_BYTES_SIZED_READS",
        .udesc = "32 Bytes Sized Reads",
        .ucode = 0x20,
    },
    {
        .uname = "64_BYTE_SIZED_READS",
        .udesc = "64 Byte Sized Reads",
        .ucode = 0x40,
    },
    {
        .uname = "READ_REQUESTS_TO_DCT_WHILE_WRITES_PENDING",
        .udesc =
            "Read requests sent to the DCT while writes requests are pending in the DCT",
        .ucode = 0x80,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_read_request_to_l3_cache[] = {
    {
        .uname = "READ_BLOCK_EXCLUSIVE",
        .udesc = "Read Block Exclusive (Data cache read)",
        .ucode = 0x1,
        .grpid = 0,
    },
    {
        .uname = "READ_BLOCK_SHARED",
        .udesc = "Read Block Shared (Instruction cache read)",
        .ucode = 0x2,
        .grpid = 0,
    },
    {
        .uname = "READ_BLOCK_MODIFY",
        .udesc = "Read Block Modify",
        .ucode = 0x4,
        .grpid = 0,
    },
    {
        .uname = "PREFETCH",
        .udesc = "Count prefetches only",
        .ucode = 0x8,
        .grpid = 0,
    },
    {
        .uname = "READ_BLOCK_ANY",
        .udesc = "Count any read request",
        .ucode = 0x7,
        .grpid = 0,
        .uflags = AMD64_FL_DFL | AMD64_FL_NCOMBO,
    },
    CORE_SELECT(1),
};

static const amd64_umask_t amd64_fam15h_nb_l3_fills_caused_by_l2_evictions[] = {
    {
        .uname = "SHARED",
        .udesc = "Shared",
        .ucode = 0x1,
        .grpid = 0,
    },
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive",
        .ucode = 0x2,
        .grpid = 0,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned",
        .ucode = 0x4,
        .grpid = 0,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified",
        .ucode = 0x8,
        .grpid = 0,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xff,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
        .grpid = 0,
    },
    CORE_SELECT(1),
};

static const amd64_umask_t amd64_fam15h_nb_l3_evictions[] = {
    {
        .uname = "SHARED",
        .udesc = "Shared",
        .ucode = 0x1,
    },
    {
        .uname = "EXCLUSIVE",
        .udesc = "Exclusive",
        .ucode = 0x2,
    },
    {
        .uname = "OWNED",
        .udesc = "Owned",
        .ucode = 0x4,
    },
    {
        .uname = "MODIFIED",
        .udesc = "Modified",
        .ucode = 0x8,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0xf,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_umask_t amd64_fam15h_nb_l3_latency[] = {
    {
        .uname = "L3_REQUEST_CYCLE",
        .udesc = "L3 Request cycle count.",
        .ucode = 0x1,
    },
    {
        .uname = "L3_REQUEST",
        .udesc = "L3 request count.",
        .ucode = 0x2,
    },
    {
        .uname = "ALL",
        .udesc = "All sub-events selected",
        .ucode = 0x3,
        .uflags = AMD64_FL_NCOMBO | AMD64_FL_DFL,
    },
};

static const amd64_entry_t amd64_fam15h_nb_pe[] = {
    {
        .name = "DRAM_ACCESSES",
        .desc = "DRAM Accesses",
        .code = 0xe0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_dram_accesses),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_dram_accesses,
    },
    {
        .name = "DRAM_CONTROLLER_PAGE_TABLE_OVERFLOWS",
        .desc = "DRAM Controller Page Table Overflows",
        .code = 0xe1,
        .numasks =
            LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_dram_controller_page_table_overflows),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_dram_controller_page_table_overflows,
    },
    {
        .name = "MEMORY_CONTROLLER_DRAM_COMMAND_SLOTS_MISSED",
        .desc = "Memory Controller DRAM Command Slots Missed",
        .code = 0xe2,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_memory_controller_dram_command_slots_missed),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_memory_controller_dram_command_slots_missed,
    },
    {
        .name = "MEMORY_CONTROLLER_TURNAROUNDS",
        .desc = "Memory Controller Turnarounds",
        .code = 0xe3,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_memory_controller_turnarounds),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_memory_controller_turnarounds,
    },
    {
        .name = "MEMORY_CONTROLLER_BYPASS_COUNTER_SATURATION",
        .desc = "Memory Controller Bypass Counter Saturation",
        .code = 0xe4,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_memory_controller_bypass_counter_saturation),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_memory_controller_bypass_counter_saturation,
    },
    {
        .name = "THERMAL_STATUS",
        .desc = "Thermal Status",
        .code = 0xe8,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_thermal_status),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_thermal_status,
    },
    {
        .name = "CPU_IO_REQUESTS_TO_MEMORY_IO",
        .desc = "CPU/IO Requests to Memory/IO",
        .code = 0xe9,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_cpu_io_requests_to_memory_io),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_io_requests_to_memory_io,
    },
    {
        .name = "CACHE_BLOCK_COMMANDS",
        .desc = "Cache Block Commands",
        .code = 0xea,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_cache_block_commands),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cache_block_commands,
    },
    {
        .name = "SIZED_COMMANDS",
        .desc = "Sized Commands",
        .code = 0xeb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_sized_commands),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_sized_commands,
    },
    {
        .name = "PROBE_RESPONSES_AND_UPSTREAM_REQUESTS",
        .desc = "Probe Responses and Upstream Requests",
        .code = 0xec,
        .numasks =
            LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_probe_responses_and_upstream_requests),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_probe_responses_and_upstream_requests,
    },
    {
        .name = "GART_EVENTS",
        .desc = "GART Events",
        .code = 0xee,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_gart_events),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_gart_events,
    },
    {
        .name = "LINK_TRANSMIT_BANDWIDTH_LINK_0",
        .desc = "Link Transmit Bandwidth Link 0",
        .code = 0xf6,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_link_transmit_bandwidth),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_link_transmit_bandwidth,
    },
    {
        .name = "LINK_TRANSMIT_BANDWIDTH_LINK_1",
        .desc = "Link Transmit Bandwidth Link 1",
        .code = 0xf7,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_link_transmit_bandwidth),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_link_transmit_bandwidth,
    },
    {
        .name = "LINK_TRANSMIT_BANDWIDTH_LINK_2",
        .desc = "Link Transmit Bandwidth Link 2",
        .code = 0xf8,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_link_transmit_bandwidth),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_link_transmit_bandwidth,
    },
    {
        .name = "LINK_TRANSMIT_BANDWIDTH_LINK_3",
        .desc = "Link Transmit Bandwidth Link 3",
        .code = 0x1f9,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_link_transmit_bandwidth),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_link_transmit_bandwidth,
    },
    {
        .name = "CPU_TO_DRAM_REQUESTS_TO_TARGET_NODE",
        .desc = "CPU to DRAM Requests to Target Node",
        .code = 0x1e0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_cpu_to_dram_requests_to_target_node),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_to_dram_requests_to_target_node,
    },
    {
        .name = "IO_TO_DRAM_REQUESTS_TO_TARGET_NODE",
        .desc = "IO to DRAM Requests to Target Node",
        .code = 0x1e1,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_io_to_dram_requests_to_target_node),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_io_to_dram_requests_to_target_node,
    },
    {
        .name = "CPU_READ_COMMAND_LATENCY_TO_TARGET_NODE_0_3",
        .desc = "CPU Read Command Latency to Target Node 0-3",
        .code = 0x1e2,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_cpu_read_command_requests_to_target_node_0_3),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_read_command_requests_to_target_node_0_3,
    },
    {
        .name = "CPU_READ_COMMAND_REQUESTS_TO_TARGET_NODE_0_3",
        .desc = "CPU Read Command Requests to Target Node 0-3",
        .code = 0x1e3,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_cpu_read_command_requests_to_target_node_0_3),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_read_command_requests_to_target_node_0_3,
    },
    {
        .name = "CPU_READ_COMMAND_LATENCY_TO_TARGET_NODE_4_7",
        .desc = "CPU Read Command Latency to Target Node 4-7",
        .code = 0x1e4,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_cpu_read_command_requests_to_target_node_4_7),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_read_command_requests_to_target_node_4_7,
    },
    {
        .name = "CPU_READ_COMMAND_REQUESTS_TO_TARGET_NODE_4_7",
        .desc = "CPU Read Command Requests to Target Node 4-7",
        .code = 0x1e5,
        .numasks = LIBPFM_ARRAY_SIZE(
            amd64_fam15h_nb_cpu_read_command_requests_to_target_node_4_7),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_read_command_requests_to_target_node_4_7,
    },
    {
        .name = "CPU_COMMAND_LATENCY_TO_TARGET_NODE",
        .desc = "CPU Command Latency to Target Node",
        .code = 0x1e6,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_cpu_command_requests_to_target_node),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_command_requests_to_target_node,
    },
    {
        .name = "CPU_REQUESTS_TO_TARGET_NODE",
        .desc = "CPU Requests to Target Node",
        .code = 0x1e7,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_cpu_command_requests_to_target_node),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_cpu_command_requests_to_target_node,
    },
    {
        .name = "REQUEST_CACHE_STATUS_0",
        .desc = "Request Cache Status 0",
        .code = 0x1ea,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_request_cache_status_0),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_request_cache_status_0,
    },
    {
        .name = "REQUEST_CACHE_STATUS_1",
        .desc = "Request Cache Status 1",
        .code = 0x1eb,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_request_cache_status_1),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_request_cache_status_1,
    },
    {
        .name = "MEMORY_CONTROLLER_REQUESTS",
        .desc = "Memory Controller Requests",
        .code = 0x1f0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_memory_controller_requests),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_memory_controller_requests,
    },
    {
        .name = "READ_REQUEST_TO_L3_CACHE",
        .desc = "Read Request to L3 Cache",
        .code = 0x4e0,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_read_request_to_l3_cache),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_read_request_to_l3_cache,
    },
    {
        .name = "L3_CACHE_MISSES",
        .desc = "L3 Cache Misses",
        .code = 0x4e1,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_read_request_to_l3_cache),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_read_request_to_l3_cache,
    },
    {
        .name = "L3_FILLS_CAUSED_BY_L2_EVICTIONS",
        .desc = "L3 Fills caused by L2 Evictions",
        .code = 0x4e2,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_l3_fills_caused_by_l2_evictions),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_l3_fills_caused_by_l2_evictions,
    },
    {
        .name = "L3_EVICTIONS",
        .desc = "L3 Evictions",
        .code = 0x4e3,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_l3_evictions),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_l3_evictions,
    },
    {
        .name = "NON_CANCELED_L3_READ_REQUESTS",
        .desc = "Non-canceled L3 Read Requests",
        .code = 0x4ed,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_read_request_to_l3_cache),
        .ngrp = 2,
        .umasks = amd64_fam15h_nb_read_request_to_l3_cache,
    },
    {
        .name = "L3_LATENCY",
        .desc = "L3 Latency",
        .code = 0x4ef,
        .numasks = LIBPFM_ARRAY_SIZE(amd64_fam15h_nb_l3_latency),
        .ngrp = 1,
        .umasks = amd64_fam15h_nb_l3_latency,
    },
};
