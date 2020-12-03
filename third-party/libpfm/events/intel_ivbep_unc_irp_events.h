/*
 * Copyright (c) 2014 Google Inc. All rights reserved
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
 * PMU: ivbep_unc_irp (Intel IvyBridge-EP IRP uncore)
 */

static const intel_x86_umask_t ivbep_unc_i_address_match[] = {
    {
        .uname = "STALL_COUNT",
        .udesc = "Number of time when it is not possible to merge two conflicting "
                 "requests, a stall event occurs",
        .ucode = 0x100,
    },
    {
        .uname = "MERGE_COUNT",
        .udesc = "Number of times when two requests to the same address from the same "
                 "source are received back to back, it is possible to merge them",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t ivbep_unc_i_cache_ack_pending_occupancy[] = {
    {
        .uname = "ANY",
        .udesc = "Any source",
        .ucode = 0x100,
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "SOURCE",
        .udesc = "Track all requests from any source port",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t ivbep_unc_i_tickles[] = {
    {
        .uname = "LOST_OWNERSHIP",
        .udesc = "Number of request that lost ownership as a result of a tickle",
        .ucode = 0x100,
    },
    {
        .uname = "TOP_OF_QUEUE",
        .udesc = "Number of cases when a tickle was received but the request was at the "
                 "head of the queue in the switch. In this case data is returned rather "
                 "than releasing ownership",
        .ucode = 0x200,
    },
};

static const intel_x86_umask_t ivbep_unc_i_transactions[] = {
    {
        .uname = "READS",
        .udesc = "Number of read requests (not including read prefetches)",
        .ucode = 0x100,
    },
    {
        .uname = "WRITES",
        .udesc = "Number of write requests. Each write should have a prefetch, so there "
                 "is no need to explicitly track these requests",
        .ucode = 0x200,
    },
    {
        .uname = "RD_PREFETCHES",
        .udesc = "Number of read prefetches",
        .ucode = 0x400,
    },
};

static const intel_x86_entry_t intel_ivbep_unc_i_pe[] = {
    {
        .name = "UNC_I_CLOCKTICKS",
        .desc = "Number of uclks in domain",
        .code = 0x0,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {.name = "UNC_I_ADDRESS_MATCH",
     .desc = "Address match conflict count",
     .code = 0x17,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_IRP_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_address_match),
     .umasks = ivbep_unc_i_address_match},
    {.name = "UNC_I_CACHE_ACK_PENDING_OCCUPANCY",
     .desc = "Write ACK pending occupancy",
     .code = 0x14,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_IRP_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_cache_ack_pending_occupancy),
     .umasks = ivbep_unc_i_cache_ack_pending_occupancy},
    {
        .name = "UNC_I_CACHE_OWN_OCCUPANCY",
        .desc = "Outstanding write ownership occupancy",
        .code = 0x13,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_cache_ack_pending_occupancy),
        .umasks = ivbep_unc_i_cache_ack_pending_occupancy /* shared */
    },
    {
        .name = "UNC_I_CACHE_READ_OCCUPANCY",
        .desc = "Outstanding read occupancy",
        .code = 0x10,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_cache_ack_pending_occupancy),
        .umasks = ivbep_unc_i_cache_ack_pending_occupancy /* shared */
    },
    {
        .name = "UNC_I_CACHE_TOTAL_OCCUPANCY",
        .desc = "Total write cache occupancy",
        .code = 0x12,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_cache_ack_pending_occupancy),
        .umasks = ivbep_unc_i_cache_ack_pending_occupancy /* shared */
    },
    {
        .name = "UNC_I_CACHE_WRITE_OCCUPANCY",
        .desc = "Outstanding write occupancy",
        .code = 0x11,
        .cntmsk = 0x3,
        .ngrp = 1,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
        .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_cache_ack_pending_occupancy),
        .umasks = ivbep_unc_i_cache_ack_pending_occupancy /* shared */
    },
    {
        .name = "UNC_I_RXR_AK_CYCLES_FULL",
        .desc = "TBD",
        .code = 0xb,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_AK_INSERTS",
        .desc = "Egress cycles full",
        .code = 0xa,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_AK_OCCUPANCY",
        .desc = "TBD",
        .code = 0x0c,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x4,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_INSERTS",
        .desc = "BL Ingress occupancy DRS",
        .code = 0x1,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_DRS_OCCUPANCY",
        .desc = "TBD",
        .code = 0x7,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x5,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_INSERTS",
        .desc = "BL Ingress occupancy NCB",
        .code = 0x2,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCB_OCCUPANCY",
        .desc = "TBD",
        .code = 0x8,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_CYCLES_FULL",
        .desc = "TBD",
        .code = 0x6,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_INSERTS",
        .desc = "BL Ingress Occupancy NCS",
        .code = 0x3,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_RXR_BL_NCS_OCCUPANCY",
        .desc = "TBD",
        .code = 0x9,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {.name = "UNC_I_TICKLES",
     .desc = "Tickle count",
     .code = 0x16,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_IRP_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_tickles),
     .umasks = ivbep_unc_i_tickles},
    {.name = "UNC_I_TRANSACTIONS",
     .desc = "Inbound transaction count",
     .code = 0x15,
     .cntmsk = 0x3,
     .ngrp = 1,
     .modmsk = SNBEP_UNC_IRP_ATTRS,
     .numasks = LIBPFM_ARRAY_SIZE(ivbep_unc_i_transactions),
     .umasks = ivbep_unc_i_transactions},
    {
        .name = "UNC_I_TXR_AD_STALL_CREDIT_CYCLES",
        .desc = "No AD Egress credit stalls",
        .code = 0x18,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_BL_STALL_CREDIT_CYCLES",
        .desc = "No BL Egress credit stalls",
        .code = 0x19,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_DATA_INSERTS_NCB",
        .desc = "Outbound read requests",
        .code = 0xe,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_DATA_INSERTS_NCS",
        .desc = "Outbound read requests",
        .code = 0xf,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_TXR_REQUEST_OCCUPANCY",
        .desc = "Outbound request queue occupancy",
        .code = 0xd,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
    {
        .name = "UNC_I_WRITE_ORDERING_STALL_CYCLES",
        .desc = "Write ordering stalls",
        .code = 0x1a,
        .cntmsk = 0x3,
        .modmsk = SNBEP_UNC_IRP_ATTRS,
    },
};
