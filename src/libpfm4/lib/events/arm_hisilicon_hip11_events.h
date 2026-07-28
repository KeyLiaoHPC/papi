/*
 * HiSilicon HIP11 (Kunpeng 920 72F8) core PMU events
 *
 * Target: MIDR implementer 0x48, part 0xd22 (HIP11).
 * Provenance: event names/codes primarily from c920fn2 sysfs
 *   /sys/bus/event_source/devices/armv8_pmuv3_0/events
 * cross-checked with perf list / perf stat on that host.
 *
 * Additional architected encodings needed for PAPI presets were
 * empirically validated with perf on c920fn2. Those extras are not
 * kernel-exported aliases; treat their microarchitectural meaning
 * as empirically supported only.
 *
 * Do NOT reuse this table for arm_kunpeng (0xd01) or arm_tsv200 (0xd02).
 */

static const arm_entry_t arm_hip11_pe[] = {
	{
		.name = "SW_INCR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x0,
		.desc = "Software increment (architected; empirically validated on c920fn2)."
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
		.desc = "Level 1 instruction TLB refill."
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
		.desc = "Level 1 data TLB refill."
	},
	{
		.name = "INST_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x8,
		.desc = "Instruction architecturally executed."
	},
	{
		.name = "EXC_TAKEN",
		.modmsk = ARMV8_ATTRS,
		.code = 0x9,
		.desc = "Exception taken."
	},
	{
		.name = "EXC_RETURN",
		.modmsk = ARMV8_ATTRS,
		.code = 0xa,
		.desc = "Instruction architecturally executed, exception return."
	},
	{
		.name = "CID_WRITE_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0xb,
		.desc = "Instruction architecturally executed, write to CONTEXTIDR."
	},
	{
		.name = "BR_RETURN_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0xe,
		.desc = "Instruction architecturally executed, procedure return."
	},
	{
		.name = "BR_MIS_PRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x10,
		.desc = "Mispredicted or not predicted branch speculatively executed."
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
		.desc = "Predictable branch speculatively executed."
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
		.desc = "Level 1 instruction cache access."
	},
	{
		.name = "L1D_CACHE_WB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x15,
		.desc = "Level 1 data cache write-back."
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
		.desc = "Level 2 data cache write-back."
	},
	{
		.name = "BUS_ACCESS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x19,
		.desc = "Bus access."
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
		.name = "TTBR_WRITE_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1c,
		.desc = "Instruction architecturally executed, write to TTBR."
	},
	{
		.name = "L1D_CACHE_ALLOCATE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x1f,
		.desc = "Level 1 data cache allocation without refill."
	},
	{
		.name = "BR_RETIRED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x21,
		.desc = "Instruction architecturally executed, branch."
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
		.desc = "Level 1 data TLB access."
	},
	{
		.name = "L1I_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x26,
		.desc = "Level 1 instruction TLB access."
	},
	{
		.name = "L2I_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x27,
		.desc = "Level 2 instruction cache access."
	},
	{
		.name = "L2I_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x28,
		.desc = "Level 2 instruction cache refill."
	},
	{
		.name = "L3D_CACHE_ALLOCATE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x29,
		.desc = "Level 3 data cache allocation without refill."
	},
	{
		.name = "L3D_CACHE_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2a,
		.desc = "Level 3 data cache refill."
	},
	{
		.name = "L3D_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2b,
		.desc = "Level 3 data cache access."
	},
	{
		.name = "L2D_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2d,
		.desc = "Level 2 data TLB refill."
	},
	{
		.name = "L2I_TLB_REFILL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2e,
		.desc = "Level 2 instruction TLB refill."
	},
	{
		.name = "L2D_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x2f,
		.desc = "Level 2 data TLB access."
	},
	{
		.name = "L2I_TLB",
		.modmsk = ARMV8_ATTRS,
		.code = 0x30,
		.desc = "Level 2 instruction TLB access."
	},
	{
		.name = "REMOTE_ACCESS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x31,
		.desc = "Access to another socket."
	},
	{
		.name = "LL_CACHE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x32,
		.desc = "Last level cache access."
	},
	{
		.name = "LL_CACHE_MISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x33,
		.desc = "Last level cache miss."
	},
	{
		.name = "DTLB_WALK",
		.modmsk = ARMV8_ATTRS,
		.code = 0x34,
		.desc = "Data TLB access with at least one translation table walk."
	},
	{
		.name = "ITLB_WALK",
		.modmsk = ARMV8_ATTRS,
		.code = 0x35,
		.desc = "Instruction TLB access with at least one translation table walk."
	},
	{
		.name = "LL_CACHE_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x36,
		.desc = "Last level cache access, read."
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
		.desc = "Access to another socket, read."
	},
	{
		.name = "L1D_CACHE_LMISS_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x39,
		.desc = "Level 1 data cache long-latency miss, read."
	},
	{
		.name = "STALL",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3c,
		.desc = "No operation issued."
	},
	{
		.name = "STALL_SLOT_BACKEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3d,
		.desc = "No operation sent for execution on a slot due to the backend."
	},
	{
		.name = "STALL_SLOT_FRONTEND",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3e,
		.desc = "No operation sent for execution on a slot due to the frontend."
	},
	{
		.name = "STALL_SLOT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x3f,
		.desc = "No operation sent for execution on a slot."
	},
	{
		.name = "L1D_CACHE_RD",
		.modmsk = ARMV8_ATTRS,
		.code = 0x40,
		.desc = "Level 1 data cache access, read (empirically validated on c920fn2)."
	},
	{
		.name = "L1D_CACHE_WR",
		.modmsk = ARMV8_ATTRS,
		.code = 0x41,
		.desc = "Level 1 data cache access, write (empirically validated on c920fn2)."
	},
	{
		.name = "LD_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x70,
		.desc = "Operation speculatively executed, load (empirically validated on c920fn2)."
	},
	{
		.name = "ST_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x71,
		.desc = "Operation speculatively executed, store (empirically validated on c920fn2)."
	},
	{
		.name = "ASE_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x74,
		.desc = "Operation speculatively executed, Advanced SIMD (empirically validated on c920fn2)."
	},
	{
		.name = "VFP_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x75,
		.desc = "Operation speculatively executed, floating-point (empirically validated on c920fn2)."
	},
	{
		.name = "ISB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7c,
		.desc = "Barrier speculatively executed, ISB (empirically validated on c920fn2)."
	},
	{
		.name = "DSB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7d,
		.desc = "Barrier speculatively executed, DSB (empirically validated on c920fn2)."
	},
	{
		.name = "DMB_SPEC",
		.modmsk = ARMV8_ATTRS,
		.code = 0x7e,
		.desc = "Barrier speculatively executed, DMB (empirically validated on c920fn2)."
	},
	{
		.name = "EXC_IRQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x86,
		.desc = "Exception taken, IRQ (empirically validated on c920fn2)."
	},
	{
		.name = "EXC_FIQ",
		.modmsk = ARMV8_ATTRS,
		.code = 0x87,
		.desc = "Exception taken, FIQ (empirically validated on c920fn2)."
	},
	{
		.name = "SAMPLE_POP",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4000,
		.desc = "Sample popped from the sample buffer."
	},
	{
		.name = "SAMPLE_FEED",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4001,
		.desc = "Sample taken into the sample buffer."
	},
	{
		.name = "SAMPLE_FILTRATE",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4002,
		.desc = "Sample filtered by sample filter."
	},
	{
		.name = "SAMPLE_COLLISION",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4003,
		.desc = "Sample collided with another."
	},
	{
		.name = "L1I_CACHE_LMISS",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4006,
		.desc = "Level 1 instruction cache long-latency miss."
	},
	{
		.name = "LDST_ALIGN_LAT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4020,
		.desc = "Load or store with alignment latency."
	},
	{
		.name = "LD_ALIGN_LAT",
		.modmsk = ARMV8_ATTRS,
		.code = 0x4021,
		.desc = "Load with alignment latency."
	},
};
