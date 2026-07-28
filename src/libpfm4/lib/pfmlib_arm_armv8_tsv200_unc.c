/*
 * pfmlib_arm_armv8_tsv200_unc.c : HiSilicon TaiShan v200 uncore PMUs
 *
 * Target: MIDR implementer 0x48, part 0xd02 (TaiShan v200 / Kunpeng 920 V200).
 * Topology and event encodings taken from c920bn1 sysfs/perf:
 *   hisi_sccl{1,3,9,11}_{ddrc*,hha*,l3c*,sllc*}
 *
 * Do NOT use the Kunpeng (0xd01 / hip08) uncore tables here. On v200,
 * DDRC config 0x0 means cycles, not flux_wr.
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#include "pfmlib_priv.h"
#include "pfmlib_arm_priv.h"
#include "pfmlib_arm_armv8_unc_priv.h"

#include "events/arm_hisilicon_tsv200_unc_events.h"

static int
pfm_arm_detect_hisilicon_tsv200(void *this)
{
	/* HiSilicon TaiShan v200 / Kunpeng 920 V200 */
	arm_cpuid_t attr = { .impl = 0x48, .arch = 8, .part = 0xd02 };

	return pfm_arm_detect(&attr, NULL);
}

static void
display_com(void *this, pfmlib_event_desc_t *e, void *val)
{
	const arm_entry_t *pe = this_pe(this);
	kunpeng_unc_data_t *reg = val;

	__pfm_vbprintf("[UNC=0x%"PRIx64"] %s\n",
			reg->val,
			pe[e->event].name);
}

static void
display_reg(void *this, pfmlib_event_desc_t *e, kunpeng_unc_data_t reg)
{
	pfmlib_pmu_t *pmu = this;

	if (pmu->display_reg)
		pmu->display_reg(this, e, &reg);
	else
		display_com(this, e, &reg);
}

int
pfm_tsv200_unc_get_event_encoding(void *this, pfmlib_event_desc_t *e)
{
	const arm_entry_t *event_list = this_pe(this);
	kunpeng_unc_data_t reg;

	reg.val = event_list[e->event].code;
	e->codes[0] = reg.val;
	e->count = 1;
	evt_strcat(e->fstr, "%s", event_list[e->event].name);
	display_reg(this, e, reg);
	return PFM_SUCCESS;
}

/* Dual-channel DDRC: sysfs name hisi_scclN_ddrcM_C */
#define DEFINE_TSV200_DDRC(n, m, c) \
pfmlib_pmu_t arm_hisilicon_tsv200_sccl##n##_ddrc##m##_##c##_support = { \
	.desc           = "Hisilicon TaiShan v200 SCCL"#n" DDRC"#m"_"#c, \
	.name           = "hisi_sccl"#n"_ddrc"#m"_"#c, \
	.perf_name      = "hisi_sccl"#n"_ddrc"#m"_"#c, \
	.pmu            = PFM_PMU_ARM_TSV200_UNC_SCCL##n##_DDRC##m##_##c, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_tsv200_unc_ddrc_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_tsv200_unc_ddrc_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_tsv200, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_tsv200_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_tsv200_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

#define DEFINE_TSV200_HHA(n, m) \
pfmlib_pmu_t arm_hisilicon_tsv200_sccl##n##_hha##m##_support = { \
	.desc           = "Hisilicon TaiShan v200 SCCL"#n" HHA"#m, \
	.name           = "hisi_sccl"#n"_hha"#m, \
	.perf_name      = "hisi_sccl"#n"_hha"#m, \
	.pmu            = PFM_PMU_ARM_TSV200_UNC_SCCL##n##_HHA##m, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_tsv200_unc_hha_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_tsv200_unc_hha_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_tsv200, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_tsv200_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_tsv200_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

#define DEFINE_TSV200_L3C(n, m) \
pfmlib_pmu_t arm_hisilicon_tsv200_sccl##n##_l3c##m##_support = { \
	.desc           = "Hisilicon TaiShan v200 SCCL"#n" L3C"#m, \
	.name           = "hisi_sccl"#n"_l3c"#m, \
	.perf_name      = "hisi_sccl"#n"_l3c"#m, \
	.pmu            = PFM_PMU_ARM_TSV200_UNC_SCCL##n##_L3C##m, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_tsv200_unc_l3c_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_tsv200_unc_l3c_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_tsv200, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_tsv200_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_tsv200_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

#define DEFINE_TSV200_SLLC(n, m) \
pfmlib_pmu_t arm_hisilicon_tsv200_sccl##n##_sllc##m##_support = { \
	.desc           = "Hisilicon TaiShan v200 SCCL"#n" SLLC"#m, \
	.name           = "hisi_sccl"#n"_sllc"#m, \
	.perf_name      = "hisi_sccl"#n"_sllc"#m, \
	.pmu            = PFM_PMU_ARM_TSV200_UNC_SCCL##n##_SLLC##m, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_tsv200_unc_sllc_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_tsv200_unc_sllc_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_tsv200, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_tsv200_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_tsv200_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

DEFINE_TSV200_DDRC(1, 0, 0);
DEFINE_TSV200_DDRC(1, 0, 1);
DEFINE_TSV200_DDRC(1, 2, 0);
DEFINE_TSV200_DDRC(1, 2, 1);
DEFINE_TSV200_DDRC(1, 3, 0);
DEFINE_TSV200_DDRC(1, 3, 1);
DEFINE_TSV200_DDRC(1, 5, 0);
DEFINE_TSV200_DDRC(1, 5, 1);
DEFINE_TSV200_DDRC(3, 0, 0);
DEFINE_TSV200_DDRC(3, 0, 1);
DEFINE_TSV200_DDRC(3, 2, 0);
DEFINE_TSV200_DDRC(3, 2, 1);
DEFINE_TSV200_DDRC(3, 3, 0);
DEFINE_TSV200_DDRC(3, 3, 1);
DEFINE_TSV200_DDRC(3, 5, 0);
DEFINE_TSV200_DDRC(3, 5, 1);
DEFINE_TSV200_DDRC(9, 0, 0);
DEFINE_TSV200_DDRC(9, 0, 1);
DEFINE_TSV200_DDRC(9, 2, 0);
DEFINE_TSV200_DDRC(9, 2, 1);
DEFINE_TSV200_DDRC(9, 3, 0);
DEFINE_TSV200_DDRC(9, 3, 1);
DEFINE_TSV200_DDRC(9, 5, 0);
DEFINE_TSV200_DDRC(9, 5, 1);
DEFINE_TSV200_DDRC(11, 0, 0);
DEFINE_TSV200_DDRC(11, 0, 1);
DEFINE_TSV200_DDRC(11, 2, 0);
DEFINE_TSV200_DDRC(11, 2, 1);
DEFINE_TSV200_DDRC(11, 3, 0);
DEFINE_TSV200_DDRC(11, 3, 1);
DEFINE_TSV200_DDRC(11, 5, 0);
DEFINE_TSV200_DDRC(11, 5, 1);
DEFINE_TSV200_HHA(1, 0);
DEFINE_TSV200_HHA(1, 1);
DEFINE_TSV200_HHA(1, 2);
DEFINE_TSV200_HHA(1, 3);
DEFINE_TSV200_HHA(3, 0);
DEFINE_TSV200_HHA(3, 1);
DEFINE_TSV200_HHA(3, 2);
DEFINE_TSV200_HHA(3, 3);
DEFINE_TSV200_HHA(9, 0);
DEFINE_TSV200_HHA(9, 1);
DEFINE_TSV200_HHA(9, 2);
DEFINE_TSV200_HHA(9, 3);
DEFINE_TSV200_HHA(11, 0);
DEFINE_TSV200_HHA(11, 1);
DEFINE_TSV200_HHA(11, 2);
DEFINE_TSV200_HHA(11, 3);
DEFINE_TSV200_L3C(1, 0);
DEFINE_TSV200_L3C(1, 1);
DEFINE_TSV200_L3C(1, 2);
DEFINE_TSV200_L3C(1, 3);
DEFINE_TSV200_L3C(1, 4);
DEFINE_TSV200_L3C(1, 5);
DEFINE_TSV200_L3C(1, 6);
DEFINE_TSV200_L3C(1, 7);
DEFINE_TSV200_L3C(3, 0);
DEFINE_TSV200_L3C(3, 1);
DEFINE_TSV200_L3C(3, 2);
DEFINE_TSV200_L3C(3, 3);
DEFINE_TSV200_L3C(3, 4);
DEFINE_TSV200_L3C(3, 5);
DEFINE_TSV200_L3C(3, 6);
DEFINE_TSV200_L3C(3, 7);
DEFINE_TSV200_L3C(9, 0);
DEFINE_TSV200_L3C(9, 1);
DEFINE_TSV200_L3C(9, 2);
DEFINE_TSV200_L3C(9, 3);
DEFINE_TSV200_L3C(9, 4);
DEFINE_TSV200_L3C(9, 5);
DEFINE_TSV200_L3C(9, 6);
DEFINE_TSV200_L3C(9, 7);
DEFINE_TSV200_L3C(11, 0);
DEFINE_TSV200_L3C(11, 1);
DEFINE_TSV200_L3C(11, 2);
DEFINE_TSV200_L3C(11, 3);
DEFINE_TSV200_L3C(11, 4);
DEFINE_TSV200_L3C(11, 5);
DEFINE_TSV200_L3C(11, 6);
DEFINE_TSV200_L3C(11, 7);
DEFINE_TSV200_SLLC(1, 0);
DEFINE_TSV200_SLLC(1, 1);
DEFINE_TSV200_SLLC(1, 2);
DEFINE_TSV200_SLLC(1, 3);
DEFINE_TSV200_SLLC(3, 0);
DEFINE_TSV200_SLLC(3, 1);
DEFINE_TSV200_SLLC(3, 2);
DEFINE_TSV200_SLLC(3, 3);
DEFINE_TSV200_SLLC(9, 0);
DEFINE_TSV200_SLLC(9, 1);
DEFINE_TSV200_SLLC(9, 2);
DEFINE_TSV200_SLLC(9, 3);
DEFINE_TSV200_SLLC(11, 0);
DEFINE_TSV200_SLLC(11, 1);
DEFINE_TSV200_SLLC(11, 2);
DEFINE_TSV200_SLLC(11, 3);
