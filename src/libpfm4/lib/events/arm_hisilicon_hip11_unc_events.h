/*
 * HiSilicon HIP11 (Kunpeng 920 72F8) uncore PMU events
 *
 * Target: MIDR implementer 0x48, part 0xd22 (HIP11).
 * Provenance: harvested from c920fn2 sysfs hisi_sccl* DDRC/HHA/UC
 * event aliases and cross-checked with perf list / perf stat.
 *
 * Topology on c920fn2: SCCL 0,1,8,9 with dual-channel DDRC names
 * (hisi_scclN_ddrcM_C), HHA 0-3, and UC 0-3_0-3 per SCCL.
 * There is no L3C/SLLC PMU on this platform; use UC instead.
 */

static const arm_entry_t arm_hip11_unc_ddrc_pe[] = {
	{ .name = "cycles", .code = 0x0, .desc = "DDRC cycles." },
	{ .name = "flux_wr", .code = 0x83, .desc = "DDRC write data flux." },
	{ .name = "flux_rd", .code = 0x84, .desc = "DDRC read data flux." },
};

static const arm_entry_t arm_hip11_unc_hha_pe[] = {
	{ .name = "rx_ops_num", .code = 0x0, .desc = "Operations received by the HHA." },
	{ .name = "rx_outer", .code = 0x1, .desc = "Operations received from another socket." },
	{ .name = "rx_sccl", .code = 0x2, .desc = "Operations received from another SCCL." },
	{ .name = "hha_retry", .code = 0x2e, .desc = "HHA retry operations." },
	{ .name = "cycles", .code = 0x55, .desc = "HHA cycles." },
};

static const arm_entry_t arm_hip11_unc_uc_pe[] = {
	{ .name = "sq_time", .code = 0x0, .desc = "UC store queue time." },
	{ .name = "pq_time", .code = 0x1, .desc = "UC pending queue time." },
	{ .name = "hbm_time", .code = 0x2, .desc = "UC HBM time." },
	{ .name = "iq_comp_time_cring", .code = 0x3, .desc = "UC IQ completion time on C-ring." },
	{ .name = "iq_comp_time_uring", .code = 0x5, .desc = "UC IQ completion time on U-ring." },
	{ .name = "cpu_rd", .code = 0x10, .desc = "UC CPU read requests." },
	{ .name = "cpu_rd64", .code = 0x17, .desc = "UC CPU 64B read requests." },
	{ .name = "cpu_rs64", .code = 0x19, .desc = "UC CPU 64B read-shared requests." },
	{ .name = "cpu_mru", .code = 0x1c, .desc = "UC CPU most-recently-used requests." },
	{ .name = "cycles", .code = 0x95, .desc = "UC cycles." },
	{ .name = "spipe_hit", .code = 0xb3, .desc = "UC S-pipe hits." },
	{ .name = "hpipe_hit", .code = 0xdb, .desc = "UC H-pipe hits." },
	{ .name = "cring_rxdat_cnt", .code = 0xfa, .desc = "UC C-ring receive data count." },
	{ .name = "cring_txdat_cnt", .code = 0xfb, .desc = "UC C-ring transmit data count." },
	{ .name = "uring_rxdat_cnt", .code = 0xfc, .desc = "UC U-ring receive data count." },
	{ .name = "uring_txdat_cnt", .code = 0xfd, .desc = "UC U-ring transmit data count." },
};
