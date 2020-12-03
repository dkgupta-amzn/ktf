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
 * PMU: skx_unc_upi
 */

static intel_x86_umask_t skx_unc_upi_direct_attempts[] = {
    {
        .uname = "D2C",
        .ucode = 0x100,
        .udesc = "Direct packet attempts -- Direct 2 Core",
    },
    {
        .uname = "D2U",
        .ucode = 0x200,
        .udesc = "Direct packet attempts -- Direct 2 UPI",
    },
};

static intel_x86_umask_t skx_unc_upi_flowq_no_vna_crd[] = {
    {
        .uname = "AD_VNA_EQ0",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "AD_VNA_EQ1",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "AD_VNA_EQ2",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "AK_VNA_EQ0",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
    {
        .uname = "AK_VNA_EQ1",
        .ucode = 0x2000,
        .udesc = "TBD",
    },
    {
        .uname = "AK_VNA_EQ2",
        .ucode = 0x4000,
        .udesc = "TBD",
    },
    {
        .uname = "AK_VNA_EQ3",
        .ucode = 0x8000,
        .udesc = "TBD",
    },
    {
        .uname = "BL_VNA_EQ0",
        .ucode = 0x800,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_m3_byp_blocked[] = {
    {
        .uname = "BGF_CRD",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_AD_VNA_LE2",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_AK_VNA_LE3",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_BL_VNA_EQ0",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "GV_BLOCK",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_m3_rxq_blocked[] = {
    {
        .uname = "BGF_CRD",
        .ucode = 0x2000,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_AD_VNA_BTW_2_THRESH",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_AD_VNA_LE2",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_AK_VNA_LE3",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_BL_VNA_BTW_0_THRESH",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "FLOWQ_BL_VNA_EQ0",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "GV_BLOCK",
        .ucode = 0x4000,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_req_slot2_from_m3[] = {
    {
        .uname = "ACK",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "VN0",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "VN1",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "VNA",
        .ucode = 0x100,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_basic_hdr_match[] = {
    {
        .uname = "NCB",
        .ucode = 0xe00,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_NCWR",
        .ucode = 0x0e00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - NCWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_WCWR",
        .ucode = 0x1e00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - WCWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_NCMSGB",
        .ucode = 0x8e00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - WCWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_INTLOGICAL",
        .ucode = 0x9e00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - WCWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_INTPHYSICAL",
        .ucode = 0xae00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - INTPHYSICAL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_INTPRIOUPD",
        .ucode = 0xbe00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - INTPRIOUPD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_NCWRPTL",
        .ucode = 0xce00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - NCWRPTL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCB_OPC_NCP2PB",
        .ucode = 0xfe00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Bypass - NCP2PB",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS",
        .ucode = 0xf00,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Standard",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCRD",
        .ucode = 0x0f00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Standard - NCRD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_INTACK",
        .ucode = 0x1f00,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Standard - INTACK",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCRDPTL",
        .ucode = 0x4f00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Standard - NCRDPTL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCCFGRD",
        .ucode = 0x5f00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc = "NCS - NCCFGRD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCLTRD",
        .ucode = 0x6f00 | 1ULL << 32,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Standard - NCLTRD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_IORD",
        .ucode = 0x7f00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Standard - IORD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_MSGS",
        .ucode = 0x8f00,
        .ufilters[0] = 1ULL,
        .udesc = "NCS - MSGS",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_CFGWR",
        .ucode = 0x9f00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Standard - CFGWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_LTWR",
        .ucode = 0xaf00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Non-Coherent Standard - LTWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCIOWR",
        .ucode = 0xbf00,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Standard - NCIOWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "NCS_OPC_NCP2PS",
        .ucode = 0xff00,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Non-Coherent Standard - NCP2PS",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "REQ",
        .ucode = 0x800,
        .udesc = "Matches on Receive path of a UPI Port -- Request",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 0,
    },
    {
        .uname = "REQ_OPC_INVITOE",
        .ucode = 0x7800,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Request Opcode - ITOE",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "REQ_OPC_RDINV",
        .ucode = 0xc800,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Request Opcode - ReadInv",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSPCNFLT",
        .ucode = 0xaa00,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Conflict",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSPI",
        .ucode = 0x2a00,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Invalid",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA",
        .ucode = 0xc00,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_M",
        .ucode = 0x0c00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - DATA_M",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_E",
        .ucode = 0x1c00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - DATA_E",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_SI",
        .ucode = 0x2c00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - DATA_SI",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_M_CMPO",
        .ucode = 0x4c00,
        .ufilters[0] = 1ULL,
        .udesc = "RSP4 - DATA_M_CMPO",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_E_CMPO",
        .ucode = 0x5c00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - DATA_E_CMPO",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DATA_SI_CMPO",
        .ucode = 0x6c00,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Response - Data - DATA_SI_CMPO",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_RSPFWDIWB",
        .ucode = 0xac00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - RSPFWDIWB",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_RSPFWDSWB",
        .ucode = 0xbc00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - RSPFWDIWB",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_RSPIWB",
        .ucode = 0xcc00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - RSPIWB",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_RSPSWB",
        .ucode = 0xdc00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - RSPSWB",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_DATA_OPC_DEBUG_DATA",
        .ucode = 0xfc00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - Data - DEBUGDATA",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA",
        .ucode = 0xa00,
        .udesc = "Matches on Receive path of a UPI Port -- Response - No Data",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA_OPC_FWDS",
        .ucode = 0x6a00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - No Data - FWDS",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA_OPC_MIRCMPU",
        .ucode = 0x8a00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - No Data - MIRCMPU",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA_OPC_CNFLT",
        .ucode = 0xaa00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - No Data - CNFLT",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA_OPC_FWDCNFLTO",
        .ucode = 0xda00,
        .ufilters[0] = 1ULL,
        .udesc =
            "Matches on Receive path of a UPI Port -- Response - No Data - FWDCNFLTO",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "RSP_NODATA_OPC_CMPO",
        .ucode = 0xca00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Response - No Data - CMPO",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP",
        .ucode = 0x900,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FCUR",
        .ucode = 0x8900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FCUR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FCODE",
        .ucode = 0x9900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FCODE",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FDATA",
        .ucode = 0xa900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FDATA",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FDATAMIG",
        .ucode = 0xb900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FDATAMIG",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FINVOWN",
        .ucode = 0xc900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FDATA",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "SNP_OPC_FINV",
        .ucode = 0xd900,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Snoop Opcode - FINV",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB",
        .ucode = 0xd00,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_WBMTOI",
        .ucode = 0x0d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - MTOI",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_WBMTOS",
        .ucode = 0x1d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - MTOS",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_WBMTOE",
        .ucode = 0x2d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - MTOE",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_NONSNPWR",
        .ucode = 0x3d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - NONSNPWR",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_MTOIPTL",
        .ucode = 0x4d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - MTOIPTL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_MTOEPTL",
        .ucode = 0x6d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - MTOEPTL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_NONSNPWRTL",
        .ucode = 0x6d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - NONSNPWRTL",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_PUSHMTOI",
        .ucode = 0x8d00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - PUSHMTOI",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_FLUSH",
        .ucode = 0xbd00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - FLUSH",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_EVCTCLN",
        .ucode = 0xcd00,
        .ufilters[0] = 1ULL,
        .udesc = "Matches on Receive path of a UPI Port -- Writeback - EVCTCLN",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "WB_OPC_NONSNPRD",
        .ucode = 0xdd00,
        .ufilters[0] = 1ULL,
        .udesc = "WB - NONSNPRD",
        .uflags = INTEL_X86_NCOMBO,
        .grpid = 0,
    },
    {
        .uname = "FILT_NONE",
        .ucode = 0x0000,
        .udesc = "No extra filter",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
        .grpid = 1,
    },
    {
        .uname = "FILT_LOCAL",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 1,
        .udesc = "Filter packets targeting this socket",
        .grpid = 1,
    },
    {
        .uname = "FILT_REMOTE",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 2,
        .udesc = "Filter packets targeting another socket",
        .grpid = 1,
    },
    {
        .uname = "FILT_DATA",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 3,
        .udesc = "Filter on Data packets (mutually exclusive with FILT_NON_DATA)",
        .grpid = 1,
    },
    {
        .uname = "FILT_NON_DATA",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 4,
        .udesc = "Filter on non-Data packets (mutually exclusive with FILT_DATA)",
        .grpid = 1,
    },
    {
        .uname = "FILT_DUAL_SLOT",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 5,
        .udesc = "Filter on dual-slot packets (mutually exclusive with FILT_SINGLE_SLOT)",
        .grpid = 1,
    },
    {
        .uname = "FILT_SINGLE_SLOT",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 6,
        .udesc = "Filter on single-slot packets (mutually exclusive with FILT_DUAL_SLOT)",
        .grpid = 1,
    },
    {
        .uname = "FILT_ISOCH",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 7,
        .udesc = "Filter on isochronous  packets",
        .grpid = 1,
    },
    {
        .uname = "FILT_SLOT0",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 19,
        .udesc = "Filter on slot0 packets",
        .grpid = 1,
    },
    {
        .uname = "FILT_SLOT1",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 20,
        .udesc = "Filter on slot1 packets",
        .grpid = 1,
    },
    {
        .uname = "FILT_SLOT2",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 21,
        .udesc = "Filter on slot2 packets",
        .grpid = 1,
    },
    {
        .uname = "FILT_LLCRD_NON_ZERO",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 22,
        .udesc = "Filter on LLCRD nonzero (only applies to slot2 with opcode match)",
        .grpid = 1,
    },
    {
        .uname = "FILT_IMPL_NULL",
        .ucode = 0x0000,
        .ufilters[0] = 1ULL << 23,
        .udesc = "Filter on implied NULL (only applies to slot2 with opcode match)",
        .grpid = 1,
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_bypassed[] = {
    {
        .uname = "SLOT0",
        .ucode = 0x100,
        .udesc = "RxQ Flit Buffer Bypassed -- Slot 0",
    },
    {
        .uname = "SLOT1",
        .ucode = 0x200,
        .udesc = "RxQ Flit Buffer Bypassed -- Slot 1",
    },
    {
        .uname = "SLOT2",
        .ucode = 0x400,
        .udesc = "RxQ Flit Buffer Bypassed -- Slot 2",
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_flits[] = {
    {
        .uname = "ALL_DATA",
        .ucode = 0xf00,
        .udesc = "Valid Flits Received -- All Data",
        .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
    },
    {
        .uname = "ALL_NULL",
        .ucode = 0x2700,
        .udesc = "Valid Flits Received -- All Null Slots",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "DATA",
        .ucode = 0x800,
        .udesc = "Valid Flits Received -- Data",
    },
    {
        .uname = "IDLE",
        .ucode = 0x4700,
        .udesc = "Valid Flits Received -- Idle",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LLCRD",
        .ucode = 0x1000,
        .udesc = "Valid Flits Received -- LLCRD Not Empty",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "LLCTRL",
        .ucode = 0x4000,
        .udesc = "Valid Flits Received -- LLCTRL",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NON_DATA",
        .ucode = 0x9700,
        .udesc = "Valid Flits Received -- All Non Data",
        .uflags = INTEL_X86_NCOMBO,
    },
    {
        .uname = "NULL",
        .ucode = 0x2000,
        .udesc = "Valid Flits Received -- Slot NULL or LLCRD Empty",
    },
    {
        .uname = "PROTHDR",
        .ucode = 0x8000,
        .udesc = "Valid Flits Received -- Protocol Header",
    },
    {
        .uname = "SLOT0",
        .ucode = 0x100,
        .udesc = "Valid Flits Received -- Slot 0",
    },
    {
        .uname = "SLOT1",
        .ucode = 0x200,
        .udesc = "Valid Flits Received -- Slot 1",
    },
    {
        .uname = "SLOT2",
        .ucode = 0x400,
        .udesc = "Valid Flits Received -- Slot 2",
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_inserts[] = {
    {
        .uname = "SLOT0",
        .ucode = 0x100,
        .udesc = "RxQ Flit Buffer Allocations -- Slot 0",
    },
    {
        .uname = "SLOT1",
        .ucode = 0x200,
        .udesc = "RxQ Flit Buffer Allocations -- Slot 1",
    },
    {
        .uname = "SLOT2",
        .ucode = 0x400,
        .udesc = "RxQ Flit Buffer Allocations -- Slot 2",
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_occupancy[] = {
    {
        .uname = "SLOT0",
        .ucode = 0x100,
        .udesc = "RxQ Occupancy - All Packets -- Slot 0",
    },
    {
        .uname = "SLOT1",
        .ucode = 0x200,
        .udesc = "RxQ Occupancy - All Packets -- Slot 1",
    },
    {
        .uname = "SLOT2",
        .ucode = 0x400,
        .udesc = "RxQ Occupancy - All Packets -- Slot 2",
    },
};

static intel_x86_umask_t skx_unc_upi_rxl_slot_bypass[] = {
    {
        .uname = "S0_RXQ1",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "S0_RXQ2",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "S1_RXQ0",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "S1_RXQ2",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "S2_RXQ0",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
    {
        .uname = "S2_RXQ1",
        .ucode = 0x2000,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_txl0p_clk_active[] = {
    {
        .uname = "CFG_CTL",
        .ucode = 0x100,
        .udesc = "TBD",
    },
    {
        .uname = "DFX",
        .ucode = 0x4000,
        .udesc = "TBD",
    },
    {
        .uname = "RETRY",
        .ucode = 0x2000,
        .udesc = "TBD",
    },
    {
        .uname = "RXQ",
        .ucode = 0x200,
        .udesc = "TBD",
    },
    {
        .uname = "RXQ_BYPASS",
        .ucode = 0x400,
        .udesc = "TBD",
    },
    {
        .uname = "RXQ_CRED",
        .ucode = 0x800,
        .udesc = "TBD",
    },
    {
        .uname = "SPARE",
        .ucode = 0x8000,
        .udesc = "TBD",
    },
    {
        .uname = "TXQ",
        .ucode = 0x1000,
        .udesc = "TBD",
    },
};

static intel_x86_umask_t skx_unc_upi_txl_flits[] = {
    {
        .uname = "ALL_DATA",
        .ucode = 0xf00,
        .udesc = "Valid Flits Sent -- All Data",
    },
    {
        .uname = "ALL_NULL",
        .ucode = 0x2700,
        .udesc = "Valid Flits Sent -- All Null Slots",
    },
    {
        .uname = "DATA",
        .ucode = 0x800,
        .udesc = "Valid Flits Sent -- Data",
    },
    {
        .uname = "IDLE",
        .ucode = 0x4700,
        .udesc = "Valid Flits Sent -- Idle",
    },
    {
        .uname = "LLCRD",
        .ucode = 0x1000,
        .udesc = "Valid Flits Sent -- LLCRD Not Empty",
    },
    {
        .uname = "LLCTRL",
        .ucode = 0x4000,
        .udesc = "Valid Flits Sent -- LLCTRL",
    },
    {
        .uname = "NON_DATA",
        .ucode = 0x9700,
        .udesc = "Valid Flits Sent -- All Non Data",
    },
    {
        .uname = "NULL",
        .ucode = 0x2000,
        .udesc = "Valid Flits Sent -- Slot NULL or LLCRD Empty",
    },
    {
        .uname = "PROTHDR",
        .ucode = 0x8000,
        .udesc = "Valid Flits Sent -- Protocol Header",
    },
    {
        .uname = "SLOT0",
        .ucode = 0x100,
        .udesc = "Valid Flits Sent -- Slot 0",
    },
    {
        .uname = "SLOT1",
        .ucode = 0x200,
        .udesc = "Valid Flits Sent -- Slot 1",
    },
    {
        .uname = "SLOT2",
        .ucode = 0x400,
        .udesc = "Valid Flits Sent -- Slot 2",
    },
};

static intel_x86_entry_t intel_skx_unc_upi_pe[] = {
    {
        .name = "UNC_UPI_CLOCKTICKS",
        .code = 0x1,
        .desc = "Counts the number of clocks in the UPI LL.  This clock runs at 1/8th "
                "the GT/s speed of the UPI link.  For example, a 8GT/s link will have "
                "qfclk or 1GHz.  Current products do not support dynamic link speeds, so "
                "this frequency is fixexed.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_DIRECT_ATTEMPTS",
        .code = 0x12,
        .desc =
            "Counts the number of Data Response(DRS) packets UPI attempted to send "
            "directly to the core or to a different UPI link.    Note:  This only counts "
            "attempts on valid candidates such as DRS packets destined for CHAs.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_direct_attempts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_direct_attempts),
    },
    {
        .name = "UNC_UPI_FLOWQ_NO_VNA_CRD",
        .code = 0x18,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_flowq_no_vna_crd,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_flowq_no_vna_crd),
    },
    {
        .name = "UNC_UPI_L1_POWER_CYCLES",
        .code = 0x21,
        .desc = "Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that "
                "totally shuts down a UPI link.  Use edge detect to count the number of "
                "instances when the UPI link entered L1.  Link power states are per link "
                "and per direction, so for example the Tx direction could be in one "
                "state while Rx was in another. Because L1 totally shuts down the link, "
                "it takes a good amount of time to exit this mode.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_M3_BYP_BLOCKED",
        .code = 0x14,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_m3_byp_blocked,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_m3_byp_blocked),
    },
    {
        .name = "UNC_UPI_M3_CRD_RETURN_BLOCKED",
        .code = 0x16,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_M3_RXQ_BLOCKED",
        .code = 0x15,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_m3_rxq_blocked,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_m3_rxq_blocked),
    },
    {
        .name = "UNC_UPI_PHY_INIT_CYCLES",
        .code = 0x20,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_POWER_L1_NACK",
        .code = 0x23,
        .desc =
            "Counts the number of times a link sends/receives a LinkReqNAck.  When the "
            "UPI links would like to change power state, the Tx side initiates a request "
            "to the Rx side requesting to change states.  This requests can either be "
            "accepted or denied.  If the Rx side replies with an Ack, the power mode "
            "will change.  If it replies with NAck, no change will take place.  This can "
            "be filtered based on Rx and Tx.  An Rx LinkReqNAck refers to receiving an "
            "NAck (meaning this agents Tx originally requested the power change).  A Tx "
            "LinkReqNAck refers to sending this command (meaning the peer agents Tx "
            "originally requested the power change and this agent accepted itit).",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_POWER_L1_REQ",
        .code = 0x22,
        .desc =
            "Counts the number of times a link sends/receives a LinkReqAck.  When the "
            "UPI links would like to change power state, the Tx side initiates a request "
            "to the Rx side requesting to change states.  This requests can either be "
            "accepted or denied.  If the Rx side replies with an Ack, the power mode "
            "will change.  If it replies with NAck, no change will take place.  This can "
            "be filtered based on Rx and Tx.  An Rx LinkReqAck refers to receiving an "
            "Ack (meaning this agents Tx originally requested the power change).  A Tx "
            "LinkReqAck refers to sending this command (meaning the peer agents Tx "
            "originally requested the power change and this agent accepted itit).",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_REQ_SLOT2_FROM_M3",
        .code = 0x46,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_req_slot2_from_m3,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_req_slot2_from_m3),
    },
    {
        .name = "UNC_UPI_RXL0P_POWER_CYCLES",
        .code = 0x25,
        .desc =
            "Number of UPI qfclk cycles spent in L0p power mode.  L0p is a mode where we "
            "disable 60% of the UPI lanes, decreasing our bandwidth in order to save "
            "power.  It increases snoop and data transfer latencies and decreases "
            "overall bandwidth.  This mode can be very useful in NUMA optimized "
            "workloads that largely only utilize UPI for snoops and their responses.  "
            "Use edge detect to count the number of instances when the UPI link entered "
            "L0p.  Link power states are per link and per direction, so for example the "
            "Tx direction could be in one state while Rx was in another.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_RXL0_POWER_CYCLES",
        .code = 0x24,
        .desc = "Number of UPI qfclk cycles spent in L0 power mode in the Link Layer.  "
                "L0 is the default mode which provides the highest performance with the "
                "most power.  Use edge detect to count the number of instances that the "
                "link entered L0.  Link power states are per link and per direction, so "
                "for example the Tx direction could be in one state while Rx was in "
                "another.  The phy layer  sometimes leaves L0 for training, which will "
                "not be captured by this event.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_RXL_BASIC_HDR_MATCH",
        .code = 0x5,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_OPC_ATTRS,
        .flags = INTEL_X86_FILT_UMASK |
                 INTEL_X86_FORCE_FILT0, /* filter may be encoded in umask, filter encoding
                                           must be passed even if 0 */
        .cntmsk = 0xf,
        .ngrp = 2,
        .umasks = skx_unc_upi_rxl_basic_hdr_match,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_basic_hdr_match),
    },
    {
        .name = "UNC_UPI_RXL_BYPASSED",
        .code = 0x31,
        .desc = "Counts the number of times that an incoming flit was able to bypass the "
                "flit buffer and pass directly and into the Egress.  This is a latency "
                "optimization, and should generally be the common case.  If this value "
                "is less than the number of flits transfered, it implies that there was "
                "queueing getting onto the ring, and thus the transactions saw higher "
                "latency.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_rxl_bypassed,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_bypassed),
    },
    {
        .name = "UNC_UPI_RXL_CREDITS_CONSUMED_VN0",
        .code = 0x39,
        .desc = "Counts the number of times that an RxQ VN0 credit was consumed (i.e. "
                "message uses a VN0 credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_RXL_CREDITS_CONSUMED_VN1",
        .code = 0x3a,
        .desc = "Counts the number of times that an RxQ VN1 credit was consumed (i.e. "
                "message uses a VN1 credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_RXL_CREDITS_CONSUMED_VNA",
        .code = 0x38,
        .desc = "Counts the number of times that an RxQ VNA credit was consumed (i.e. "
                "message uses a VNA credit for the Rx Buffer).  This includes packets "
                "that went through the RxQ and those that were bypasssed.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_RXL_FLITS",
        .code = 0x3,
        .desc = "Shows legal flit time (hides impact of L0p and L0c).",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_rxl_flits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_flits),
    },
    {
        .name = "UNC_UPI_RXL_INSERTS",
        .code = 0x30,
        .desc =
            "Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is "
            "transmitted across UPI, it will bypass the RxQ and pass directly to the "
            "ring interface.  If things back up getting transmitted onto the ring, "
            "however, it may need to allocate into this buffer, thus increasing the "
            "latency.  This event can be used in conjunction with the Flit Buffer "
            "Occupancy event in order to calculate the average flit buffer lifetime.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_rxl_inserts,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_inserts),
    },
    {
        .name = "UNC_UPI_RXL_OCCUPANCY",
        .code = 0x32,
        .desc =
            "Accumulates the number of elements in the UPI RxQ in each cycle.  "
            "Generally, when data is transmitted across UPI, it will bypass the RxQ and "
            "pass directly to the ring interface.  If things back up getting transmitted "
            "onto the ring, however, it may need to allocate into this buffer, thus "
            "increasing the latency.  This event can be used in conjunction with the "
            "Flit Buffer Not Empty event to calculate average occupancy, or with the "
            "Flit Buffer Allocations event to track average lifetime.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_rxl_occupancy,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_occupancy),
    },
    {
        .name = "UNC_UPI_RXL_SLOT_BYPASS",
        .code = 0x33,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_rxl_slot_bypass,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_slot_bypass),
    },
    {
        .name = "UNC_UPI_TXL0P_CLK_ACTIVE",
        .code = 0x2a,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_txl0p_clk_active,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_txl0p_clk_active),
    },
    {
        .name = "UNC_UPI_TXL0P_POWER_CYCLES",
        .code = 0x27,
        .desc =
            "Number of UPI qfclk cycles spent in L0p power mode.  L0p is a mode where we "
            "disable 60% of the UPI lanes, decreasing our bandwidth in order to save "
            "power.  It increases snoop and data transfer latencies and decreases "
            "overall bandwidth.  This mode can be very useful in NUMA optimized "
            "workloads that largely only utilize UPI for snoops and their responses.  "
            "Use edge detect to count the number of instances when the UPI link entered "
            "L0p.  Link power states are per link and per direction, so for example the "
            "Tx direction could be in one state while Rx was in another.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL0P_POWER_CYCLES_LL_ENTER",
        .code = 0x28,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL0P_POWER_CYCLES_M3_EXIT",
        .code = 0x29,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL0_POWER_CYCLES",
        .code = 0x26,
        .desc = "Number of UPI qfclk cycles spent in L0 power mode in the Link Layer.  "
                "L0 is the default mode which provides the highest performance with the "
                "most power.  Use edge detect to count the number of instances that the "
                "link entered L0.  Link power states are per link and per direction, so "
                "for example the Tx direction could be in one state while Rx was in "
                "another.  The phy layer  sometimes leaves L0 for training, which will "
                "not be captured by this event.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL_BASIC_HDR_MATCH",
        .code = 0x4,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_OPC_ATTRS,
        .flags = INTEL_X86_FILT_UMASK |
                 INTEL_X86_FORCE_FILT0, /* filter may be encoded in umask, filter encoding
                                           must be passed even if 0 */
        .cntmsk = 0xf,
        .ngrp = 2,
        .umasks = skx_unc_upi_rxl_basic_hdr_match, /* shared */
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_rxl_basic_hdr_match),
    },
    {
        .name = "UNC_UPI_TXL_BYPASSED",
        .code = 0x41,
        .desc = "Counts the number of times that an incoming flit was able to bypass the "
                "Tx flit buffer and pass directly out the UPI Link. Generally, when data "
                "is transmitted across UPI, it will bypass the TxQ and pass directly to "
                "the link.  However, the TxQ will be used with L0p and when LLR occurs, "
                "increasing latency to transfer out to the link.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL_FLITS",
        .code = 0x2,
        .desc = "Shows legal flit time (hides impact of L0p and L0c).",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
        .ngrp = 1,
        .umasks = skx_unc_upi_txl_flits,
        .numasks = LIBPFM_ARRAY_SIZE(skx_unc_upi_txl_flits),
    },
    {
        .name = "UNC_UPI_TXL_INSERTS",
        .code = 0x40,
        .desc = "Number of allocations into the UPI Tx Flit Buffer.  Generally, when "
                "data is transmitted across UPI, it will bypass the TxQ and pass "
                "directly to the link.  However, the TxQ will be used with L0p and when "
                "LLR occurs, increasing latency to transfer out to the link.  This event "
                "can be used in conjunction with the Flit Buffer Occupancy event in "
                "order to calculate the average flit buffer lifetime.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_TXL_OCCUPANCY",
        .code = 0x42,
        .desc = "Accumulates the number of flits in the TxQ.  Generally, when data is "
                "transmitted across UPI, it will bypass the TxQ and pass directly to the "
                "link.  However, the TxQ will be used with L0p and when LLR occurs, "
                "increasing latency to transfer out to the link. This can be used with "
                "the cycles not empty event to track average occupancy, or the "
                "allocations event to track average lifetime in the TxQ.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_VNA_CREDIT_RETURN_BLOCKED_VN01",
        .code = 0x45,
        .desc = "TBD",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
    {
        .name = "UNC_UPI_VNA_CREDIT_RETURN_OCCUPANCY",
        .code = 0x44,
        .desc = "Number of VNA credits in the Rx side that are waitng to be returned "
                "back across the link.",
        .modmsk = SKX_UNC_UPI_ATTRS,
        .cntmsk = 0xf,
    },
};
