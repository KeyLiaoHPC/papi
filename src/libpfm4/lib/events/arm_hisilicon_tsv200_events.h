/*
 * HiSilicon TaiShan v200 (Kunpeng 920 V200) core PMU events
 *
 * Target: MIDR implementer 0x48, part 0xd02 (TaiShan v200).
 * Provenance: event names/codes primarily from c920bn1 sysfs
 *   /sys/bus/event_source/devices/armv8_pmuv3_0/events
 * cross-checked with perf list / perf stat on that host.
 *
 * Additional implementation-defined encodings were taken from the
 * existing HiSilicon Kunpeng (part 0xd01 / hip08) core table and
 * empirically validated with perf on c920bn1. Those extras are not
 * kernel-exported aliases; treat their microarchitectural meaning
 * as empirically supported only.
 *
 * Do NOT reuse this table for TaiShan v110 / arm_kunpeng (0xd01).
 */

static const arm_entry_t arm_tsv200_pe[] = {
	{
		.name = "SW_INCR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x0,
		.desc = "Instruction architecturally executed, Condition code check pass, software increment"
	},
	{
		.name = "INST_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8,
		.desc = "Instruction architecturally executed"
	},
	{
		.name = "EXC_TAKEN",
		.modmsk = ARMV8_ATTRS,
		.code = 0x9,
		.desc = "Exception taken"
	},
	{
		.name = "EXC_RETURN",
		.modmsk = ARMV8_ATTRS,
		.code = 0xa,
		.desc = "Instruction architecturally executed, Condition code check pass, exception return"
	},
	{
		.name = "CID_WRITE_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0xb,
		.desc = "Instruction architecturally executed, Condition code check pass, write to CONTEXTIDR"
	},
	{
		.name = "BR_RETURN_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0xe,
		.desc = "Instruction architecturally executed, Condition code check pass, procedure return"
	},
	{
		.name = "TTBR_WRITE_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1c,
		.desc = "Instruction architecturally executed, Condition code check pass, write to TTBR"
	},
	{
		.name = "BR_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x21,
		.desc = "Instruction architecturally executed, branch"
	},
	{
		.name = "SVE_INST_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8002,
		.desc = "This event counts architecturally executed SVE instructions."
	},
	{
		.name = "L1I_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1,
		.desc = "Level 1 instruction cache refill."
	},
	{
		.name = "L1I_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2,
		.desc = "Attributable Level 1 instruction TLB refill."
	},
	{
		.name = "L1D_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3,
		.desc = "Level 1 data cache refill."
	},
	{
		.name = "L1D_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4,
		.desc = "Level 1 data cache access."
	},
	{
		.name = "L1D_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x5,
		.desc = "Attributable Level 1 data TLB refill."
	},
	{
		.name = "BR_MIS_PRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x10,
		.desc = "Mispredicted or not predicted branch. Speculatively executed."
	},
	{
		.name = "CPU_CYCLES",
		.modmsk = ARMV8_ATTRS,
		.code = 0x11,
		.desc = "Cycle."
	},
	{
		.name = "BR_PRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x12,
		.desc = "Predictable branch. Speculatively executed."
	},
	{
		.name = "MEM_ACCESS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x13,
		.desc = "Data memory access."
	},
	{
		.name = "L1I_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x14,
		.desc = "Attributable Level 1 instruction cache access."
	},
	{
		.name = "L1D_CACHE_WB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x15,
		.desc = "Attributable Level 1 data cache write-back."
	},
	{
		.name = "L2D_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x16,
		.desc = "Level 2 data cache access."
	},
	{
		.name = "L2D_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x17,
		.desc = "Level 2 data cache refill."
	},
	{
		.name = "L2D_CACHE_WB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x18,
		.desc = "Attributable Level 2 data cache write-back."
	},
	{
		.name = "BUS_ACCESS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x19,
		.desc = "Attributable Bus access."
	},
	{
		.name = "MEMORY_ERROR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1a,
		.desc = "Local memory error."
	},
	{
		.name = "INST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1b,
		.desc = "Operation speculatively executed."
	},
	{
		.name = "BUS_CYCLES",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1d,
		.desc = "Bus cycle."
	},
	{
		.name = "BR_MIS_PRED_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x22,
		.desc = "Instruction architecturally executed, mispredicted branch."
	},
	{
		.name = "STALL_FRONTEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x23,
		.desc = "No operation issued due to the frontend."
	},
	{
		.name = "STALL_BACKEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x24,
		.desc = "No operation issued due to the backend."
	},
	{
		.name = "L1D_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x25,
		.desc = "Attributable Level 1 data or unified TLB access."
	},
	{
		.name = "L1I_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x26,
		.desc = "Attributable Level 1 instruction TLB access."
	},
	{
		.name = "L2I_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x27,
		.desc = "Attributable Level 2 instruction cache access."
	},
	{
		.name = "L2I_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x28,
		.desc = "Attributable Level 2 instruction cache refill."
	},
	{
		.name = "L2D_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2d,
		.desc = "Attributable Level 2 data TLB refill."
	},
	{
		.name = "L2I_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2e,
		.desc = "Attributable Level 2 instruction TLB refill."
	},
	{
		.name = "L2D_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2f,
		.desc = "Attributable Level 2 data or unified TLB access."
	},
	{
		.name = "L2I_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x30,
		.desc = "Attributable Level 2 instruction TLB access."
	},
	{
		.name = "REMOTE_ACCESS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x31,
		.desc = "Access to another socket in a multi-socket system."
	},
	{
		.name = "LL_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x32,
		.desc = "Last Level cache access."
	},
	{
		.name = "LL_CACHE_MISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x33,
		.desc = "Last Level cache miss."
	},
	{
		.name = "DTLB_WALK",
		.modmsk = ARMV8_ATTRS,
		.code = 0x34,
		.desc = "Access to data TLB causes a translation table walk."
	},
	{
		.name = "ITLB_WALK",
		.modmsk = ARMV8_ATTRS,
		.code = 0x35,
		.desc = "Access to instruction TLB that causes a translation table walk."
	},
	{
		.name = "LL_CACHE_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x36,
		.desc = "Attributable Last level cache memory read."
	},
	{
		.name = "LL_CACHE_MISS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x37,
		.desc = "Last level cache miss, read."
	},
	{
		.name = "REMOTE_ACCESS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x38,
		.desc = "Access to another socket in a multi-socket system, read."
	},
	{
		.name = "SAMPLE_POP",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4000,
		.desc = "Sample Population."
	},
	{
		.name = "SAMPLE_FEED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4001,
		.desc = "Sample Taken."
	},
	{
		.name = "SAMPLE_FILTRATE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4002,
		.desc = "Sample taken and not removed by filtering."
	},
	{
		.name = "SAMPLE_COLLISION",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4003,
		.desc = "Sample collided with a previous sample."
	},
	{
		.name = "L1D_CACHE_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x40,
		.desc = "Attributable Level 1 data cache access, read."
	},
	{
		.name = "L1D_CACHE_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x41,
		.desc = "Attributable Level 1 data cache access, write."
	},
	{
		.name = "L1D_CACHE_REFILL_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x42,
		.desc = "Attributable Level 1 data cache refill, read."
	},
	{
		.name = "L1D_CACHE_REFILL_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x43,
		.desc = "Attributable Level 1 data cache refill, write."
	},
	{
		.name = "L1D_CACHE_WB_VICTIM",
		.modmsk = ARMV8_ATTRS,
		.code = 0x46,
		.desc = "Attributable Level 1 data cache Write-Back, victim."
	},
	{
		.name = "L1D_CACHE_WB_CLEAN",
		.modmsk = ARMV8_ATTRS,
		.code = 0x47,
		.desc = "Level 1 data cache Write-Back, cleaning and coherency."
	},
	{
		.name = "L1D_CACHE_INVAL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x48,
		.desc = "Attributable Level 1 data cache invalidate."
	},
	{
		.name = "L1D_TLB_REFILL_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4c,
		.desc = "Attributable Level 1 data TLB refill, read."
	},
	{
		.name = "L1D_TLB_REFILL_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4d,
		.desc = "Attributable Level 1 data TLB refill, write."
	},
	{
		.name = "L1D_TLB_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4e,
		.desc = "Attributable Level 1 data or unified TLB access, read."
	},
	{
		.name = "L1D_TLB_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4f,
		.desc = "Attributable Level 1 data or unified TLB access, write."
	},
	{
		.name = "L2D_CACHE_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x50,
		.desc = "Attributable Level 2 data cache access, read."
	},
	{
		.name = "L2D_CACHE_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x51,
		.desc = "Attributable Level 2 data cache access, write."
	},
	{
		.name = "L2D_CACHE_REFILL_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x52,
		.desc = "Attributable Level 2 data cache refill, read."
	},
	{
		.name = "L2D_CACHE_REFILL_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x53,
		.desc = "Attributable Level 2 data cache refill, write."
	},
	{
		.name = "L2D_CACHE_WB_VICTIM",
		.modmsk = ARMV8_ATTRS,
		.code = 0x56,
		.desc = "Attributable Level 2 data cache Write-Back, victim."
	},
	{
		.name = "L2D_CACHE_WB_CLEAN",
		.modmsk = ARMV8_ATTRS,
		.code = 0x57,
		.desc = "Level 2 data cache Write-Back, cleaning and coherency."
	},
	{
		.name = "L2D_CACHE_INVAL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x58,
		.desc = "Attributable Level 2 data cache invalidate."
	},
	{
		.name = "BUS_ACCESS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x60,
		.desc = "Bus access, read."
	},
	{
		.name = "BUS_ACCESS_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x61,
		.desc = "Bus access, write."
	},
	{
		.name = "BUS_ACCESS_SHARED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x62,
		.desc = "Bus access, Normal, Cacheable, Shareable."
	},
	{
		.name = "BUS_ACCESS_NOT_SHARED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x63,
		.desc = "Bus access, not Normal, Cacheable, Shareable."
	},
	{
		.name = "BUS_ACCESS_NORMAL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x64,
		.desc = "Bus access, normal."
	},
	{
		.name = "BUS_ACCESS_PERIPH",
		.modmsk = ARMV8_ATTRS,
		.code = 0x65,
		.desc = "Bus access, peripheral."
	},
	{
		.name = "MEM_ACCESS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x66,
		.desc = "Data memory access, read."
	},
	{
		.name = "MEM_ACCESS_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x67,
		.desc = "Data memory access, write."
	},
	{
		.name = "UNALIGNED_LD_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x68,
		.desc = "Unaligned access, read."
	},
	{
		.name = "UNALIGNED_ST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x69,
		.desc = "Unaligned access, write."
	},
	{
		.name = "UNALIGNED_LDST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6a,
		.desc = "Unaligned access."
	},
	{
		.name = "LDREX_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6c,
		.desc = "Exclusive operation speculatively executed, Load-Exclusive."
	},
	{
		.name = "STREX_PASS_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6d,
		.desc = "Exclusive operation speculatively executed, Store-Exclusive pass."
	},
	{
		.name = "STREX_FAIL_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6e,
		.desc = "Exclusive operation speculatively executed, Store-Exclusive fail."
	},
	{
		.name = "STREX_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6f,
		.desc = "Exclusive operation speculatively executed, Store-Exclusive."
	},
	{
		.name = "LD_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x70,
		.desc = "Operation speculatively executed, load."
	},
	{
		.name = "ST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x71,
		.desc = "Operation speculatively executed, store."
	},
	{
		.name = "LDST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x72,
		.desc = "Operation speculatively executed, load or store."
	},
	{
		.name = "DP_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x73,
		.desc = "Operation speculatively executed, integer data processing."
	},
	{
		.name = "ASE_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x74,
		.desc = "Operation speculatively executed, Advanced SIMD."
	},
	{
		.name = "VFP_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x75,
		.desc = "Operation speculatively executed, floating-point."
	},
	{
		.name = "PC_WRITE_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x76,
		.desc = "Operation speculatively executed, software change of the PC."
	},
	{
		.name = "CRYPTO_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x77,
		.desc = "Operation speculatively executed, Cryptographic instruction."
	},
	{
		.name = "BR_IMMED_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x78,
		.desc = "Branch speculatively executed, immediate branch."
	},
	{
		.name = "BR_RETURN_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x79,
		.desc = "Branch speculatively executed, procedure return."
	},
	{
		.name = "BR_INDIRECT_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7a,
		.desc = "Branch speculatively executed, indirect branch."
	},
	{
		.name = "ISB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7c,
		.desc = "Barrier speculatively executed, ISB."
	},
	{
		.name = "DSB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7d,
		.desc = "Barrier speculatively executed, DSB."
	},
	{
		.name = "DMB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7e,
		.desc = "Barrier speculatively executed, DMB."
	},
	{
		.name = "EXC_UNDEF",
		.modmsk = ARMV8_ATTRS,
		.code = 0x81,
		.desc = "Exception taken, other synchronous."
	},
	{
		.name = "EXC_SVC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x82,
		.desc = "Exception taken, Supervisor Call."
	},
	{
		.name = "EXC_PABORT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x83,
		.desc = "Exception taken, Instruction Abort."
	},
	{
		.name = "EXC_DABORT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x84,
		.desc = "Exception taken, Data Abort or SError."
	},
	{
		.name = "EXC_IRQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x86,
		.desc = "Exception taken, IRQ."
	},
	{
		.name = "EXC_FIQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x87,
		.desc = "Exception taken, FIQ."
	},
	{
		.name = "EXC_SMC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x88,
		.desc = "Exception taken, Secure Monitor Call."
	},
	{
		.name = "EXC_HVC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8a,
		.desc = "Exception taken, Hypervisor Call."
	},
	{
		.name = "EXC_TRAP_PABORT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8b,
		.desc = "Exception taken, Instruction Abort not Taken locally."
	},
	{
		.name = "EXC_TRAP_DABORT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8c,
		.desc = "Exception taken, Data Abort or SError not Taken locally."
	},
	{
		.name = "EXC_TRAP_OTHER",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8d,
		.desc = "Exception taken, other traps not Taken locally."
	},
	{
		.name = "EXC_TRAP_IRQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8e,
		.desc = "Exception taken, IRQ not Taken locally."
	},
	{
		.name = "EXC_TRAP_FIQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8f,
		.desc = "Exception taken, FIQ not Taken locally."
	},
	{
		.name = "RC_LD_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x90,
		.desc = "Release consistency operation speculatively executed, Load-Acquire."
	},
	{
		.name = "RC_ST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x91,
		.desc = "Release consistency operation speculatively executed, Store-Release."
	},
	{
		.name = "L1I_CACHE_PRF",
		.modmsk = ARMV8_ATTRS,
		.code = 0x102e,
		.desc = "Level 1 instruction cache prefetch access count."
	},
	{
		.name = "L1I_CACHE_PRF_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x102f,
		.desc = "Level 1 instruction cache miss due to prefetch access count"
	},
	{
		.name = "IQ_IS_EMPTY",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1043,
		.desc = "Instruction queue is empty"
	},
	{
		.name = "IF_IS_STALL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1044,
		.desc = "Instruction fetch stall cycles"
	},
	{
		.name = "FETCH_BUBBLE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2014,
		.desc = "Instructions can receive, but not send"
	},
	{
		.name = "PRF_REQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6013,
		.desc = "Prefetch request from LSU"
	},
	{
		.name = "HIT_ON_PRF",
		.modmsk = ARMV8_ATTRS,
		.code = 0x6014,
		.desc = "Hit on prefetched data"
	},
	{
		.name = "EXE_STALL_CYCLE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7001,
		.desc = "Cycles of that the number of issuing micro operations are less than 4"
	},
	{
		.name = "MEM_STALL_ANYLOAD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7004,
		.desc = "No any micro operation is issued and meanwhile any load operation is not resolved"
	},
	{
		.name = "MEM_STALL_L1MISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7006,
		.desc = "No any micro operation is issued and meanwhile there is any load operation missing L1 cache and pending data refill"
	},
	{
		.name = "MEM_STALL_L2MISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7007,
		.desc = "No any micro operation is issued and meanwhile there is any load operation missing both L1 and L2 cache and pending data refill from L3 cache"
	},
	{
		.name = "L3D_CACHE_ALLOCATE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x29,
		.desc = "Level 3 data cache allocate"
	},
	{
		.name = "L3D_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2a,
		.desc = "Level 3 data cache refill"
	},
	{
		.name = "L3D_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2b,
		.desc = "Level 3 data cache access"
	},
	{
		.name = "L1D_CACHE_LMISS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x39,
		.desc = "Level 1 data cache long-latency miss, read"
	},
	{
		.name = "OP_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3b,
		.desc = "Operation speculatively executed"
	},
	{
		.name = "STALL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3c,
		.desc = "No operation issued"
	},
	{
		.name = "STALL_SLOT_BACKEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3d,
		.desc = "No operation sent for execution on a slot due to the backend"
	},
	{
		.name = "STALL_SLOT_FRONTEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3e,
		.desc = "No operation sent for execution on a slot due to the frontend"
	},
	{
		.name = "STALL_SLOT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3f,
		.desc = "No operation sent for execution on a slot"
	},
	{
		.name = "L1I_CACHE_LMISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4006,
		.desc = "Level 1 instruction cache long-latency miss"
	},
	{
		.name = "LDST_ALIGN_LAT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4020,
		.desc = "Load or store with alignment latency"
	},
	{
		.name = "LD_ALIGN_LAT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4021,
		.desc = "Load with alignment latency"
	},
	{
		.name = "ST_ALIGN_LAT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4022,
		.desc = "Store with alignment latency"
	},
};
