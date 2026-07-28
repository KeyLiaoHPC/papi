/*
 * HiSilicon TaiShan v200 (Kunpeng 920 V200) uncore PMU events
 *
 * Target: MIDR implementer 0x48, part 0xd02 (TaiShan v200).
 * Provenance: harvested from c920bn1 sysfs hisi_sccl* DDRC/HHA/L3C/SLLC
 * event aliases and cross-checked with perf list / perf stat.
 *
 * IMPORTANT: These encodings are NOT the hip08 / arm_kunpeng uncore
 * tables. On TaiShan v200, DDRC config 0x0 is "cycles", whereas hip08
 * libpfm used 0x0 for flux_wr. Reusing the Kunpeng uncore table on
 * v200 produces silently wrong counts.
 *
 * Topology on c920bn1: SCCL 1,3,9,11 with dual-channel DDRC names
 * (hisi_scclN_ddrcM_C), HHA 0-3, L3C 0-7, SLLC 0-3 per SCCL.
 */

static const arm_entry_t arm_tsv200_unc_ddrc_pe[] = {
	{ .name = "cycles", .code = 0x0, .desc = "DDRC cycles (sysfs alias on TaiShan v200)." },
	{ .name = "flux_wr", .code = 0x83, .desc = "DDRC write data flux." },
	{ .name = "flux_rd", .code = 0x84, .desc = "DDRC read data flux." },
};

static const arm_entry_t arm_tsv200_unc_hha_pe[] = {
	{ .name = "rx_ops_num", .code = 0x0, .desc = "Operations received by the HHA." },
	{ .name = "rx_outer", .code = 0x1, .desc = "Operations received from another socket." },
	{ .name = "rx_sccl", .code = 0x2, .desc = "Operations received from another SCCL." },
	{ .name = "hha_retry", .code = 0x2e, .desc = "HHA retry operations." },
	{ .name = "cycles", .code = 0x55, .desc = "HHA cycles." },
};

static const arm_entry_t arm_tsv200_unc_l3c_pe[] = {
	{ .name = "l3c_hit", .code = 0x48, .desc = "L3C hits." },
	{ .name = "cycles", .code = 0x7f, .desc = "L3C cycles." },
	{ .name = "l3c_ref", .code = 0xb8, .desc = "L3C references." },
	{ .name = "dat_access", .code = 0xb9, .desc = "L3C data accesses." },
};

static const arm_entry_t arm_tsv200_unc_sllc_pe[] = {
	{ .name = "cycles", .code = 0x9, .desc = "SLLC cycles." },
	{ .name = "rx_req", .code = 0x30, .desc = "SLLC receive requests." },
	{ .name = "rx_data", .code = 0x31, .desc = "SLLC receive data." },
	{ .name = "tx_req", .code = 0x34, .desc = "SLLC transmit requests." },
	{ .name = "tx_data", .code = 0x35, .desc = "SLLC transmit data." },
};
