/*
 * pfmlib_arm_armv8_hip11_unc.c : HiSilicon HIP11 uncore PMUs
 *
 * Target: MIDR implementer 0x48, part 0xd22 (HIP11 / Kunpeng 920 72F8).
 * Topology and event encodings taken from c920fn2 sysfs/perf:
 *   hisi_sccl{0,1,8,9}_{ddrc*,hha*,uc*}
 *
 * Do NOT reuse TaiShan v200 (0xd02) uncore instance lists (different
 * SCCL IDs and L3C/SLLC vs UC).
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#include "pfmlib_priv.h"
#include "pfmlib_arm_priv.h"
#include "pfmlib_arm_armv8_unc_priv.h"

#include "events/arm_hisilicon_hip11_unc_events.h"

static int
pfm_arm_detect_hisilicon_hip11(void *this)
{
	/* HiSilicon HIP11 / Kunpeng 920 72F8 */
	arm_cpuid_t attr = { .impl = 0x48, .arch = 8, .part = 0xd22 };

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
pfm_hip11_unc_get_event_encoding(void *this, pfmlib_event_desc_t *e)
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
#define DEFINE_HIP11_DDRC(n, m, c) \
pfmlib_pmu_t arm_hisilicon_hip11_sccl##n##_ddrc##m##_##c##_support = { \
	.desc           = "Hisilicon HIP11 SCCL"#n" DDRC"#m"_"#c, \
	.name           = "hisi_sccl"#n"_ddrc"#m"_"#c, \
	.perf_name      = "hisi_sccl"#n"_ddrc"#m"_"#c, \
	.pmu            = PFM_PMU_ARM_HIP11_UNC_SCCL##n##_DDRC##m##_##c, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_hip11_unc_ddrc_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_hip11_unc_ddrc_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_hip11, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_hip11_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_hip11_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

#define DEFINE_HIP11_HHA(n, m) \
pfmlib_pmu_t arm_hisilicon_hip11_sccl##n##_hha##m##_support = { \
	.desc           = "Hisilicon HIP11 SCCL"#n" HHA"#m, \
	.name           = "hisi_sccl"#n"_hha"#m, \
	.perf_name      = "hisi_sccl"#n"_hha"#m, \
	.pmu            = PFM_PMU_ARM_HIP11_UNC_SCCL##n##_HHA##m, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_hip11_unc_hha_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_hip11_unc_hha_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_hip11, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_hip11_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_hip11_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

/* Dual-channel UC: sysfs name hisi_scclN_ucM_C */
#define DEFINE_HIP11_UC(n, m, c) \
pfmlib_pmu_t arm_hisilicon_hip11_sccl##n##_uc##m##_##c##_support = { \
	.desc           = "Hisilicon HIP11 SCCL"#n" UC"#m"_"#c, \
	.name           = "hisi_sccl"#n"_uc"#m"_"#c, \
	.perf_name      = "hisi_sccl"#n"_uc"#m"_"#c, \
	.pmu            = PFM_PMU_ARM_HIP11_UNC_SCCL##n##_UC##m##_##c, \
	.pme_count      = LIBPFM_ARRAY_SIZE(arm_hip11_unc_uc_pe), \
	.type           = PFM_PMU_TYPE_UNCORE, \
	.pe             = arm_hip11_unc_uc_pe, \
	.pmu_detect     = pfm_arm_detect_hisilicon_hip11, \
	.max_encoding   = 1, \
	.num_cntrs      = 4, \
	.get_event_encoding[PFM_OS_NONE] = pfm_hip11_unc_get_event_encoding, \
	PFMLIB_ENCODE_PERF(pfm_hip11_unc_get_perf_encoding), \
	.get_event_first = pfm_arm_get_event_first, \
	.get_event_next  = pfm_arm_get_event_next, \
	.event_is_valid = pfm_arm_event_is_valid, \
	.validate_table = pfm_arm_validate_table, \
	.get_event_info = pfm_arm_get_event_info, \
	.get_event_attr_info = pfm_arm_get_event_attr_info, \
	PFMLIB_VALID_PERF_PATTRS(pfm_arm_perf_validate_pattrs), \
	.get_event_nattrs = pfm_arm_get_event_nattrs, \
};

DEFINE_HIP11_DDRC(0, 0, 0);
DEFINE_HIP11_DDRC(0, 0, 1);
DEFINE_HIP11_DDRC(0, 1, 0);
DEFINE_HIP11_DDRC(0, 1, 1);
DEFINE_HIP11_DDRC(0, 2, 0);
DEFINE_HIP11_DDRC(0, 2, 1);
DEFINE_HIP11_DDRC(0, 3, 0);
DEFINE_HIP11_DDRC(0, 3, 1);
DEFINE_HIP11_DDRC(1, 0, 0);
DEFINE_HIP11_DDRC(1, 0, 1);
DEFINE_HIP11_DDRC(1, 1, 0);
DEFINE_HIP11_DDRC(1, 1, 1);
DEFINE_HIP11_DDRC(1, 2, 0);
DEFINE_HIP11_DDRC(1, 2, 1);
DEFINE_HIP11_DDRC(1, 3, 0);
DEFINE_HIP11_DDRC(1, 3, 1);
DEFINE_HIP11_DDRC(8, 0, 0);
DEFINE_HIP11_DDRC(8, 0, 1);
DEFINE_HIP11_DDRC(8, 1, 0);
DEFINE_HIP11_DDRC(8, 1, 1);
DEFINE_HIP11_DDRC(8, 2, 0);
DEFINE_HIP11_DDRC(8, 2, 1);
DEFINE_HIP11_DDRC(8, 3, 0);
DEFINE_HIP11_DDRC(8, 3, 1);
DEFINE_HIP11_DDRC(9, 0, 0);
DEFINE_HIP11_DDRC(9, 0, 1);
DEFINE_HIP11_DDRC(9, 1, 0);
DEFINE_HIP11_DDRC(9, 1, 1);
DEFINE_HIP11_DDRC(9, 2, 0);
DEFINE_HIP11_DDRC(9, 2, 1);
DEFINE_HIP11_DDRC(9, 3, 0);
DEFINE_HIP11_DDRC(9, 3, 1);
DEFINE_HIP11_HHA(0, 0);
DEFINE_HIP11_HHA(0, 1);
DEFINE_HIP11_HHA(0, 2);
DEFINE_HIP11_HHA(0, 3);
DEFINE_HIP11_HHA(1, 0);
DEFINE_HIP11_HHA(1, 1);
DEFINE_HIP11_HHA(1, 2);
DEFINE_HIP11_HHA(1, 3);
DEFINE_HIP11_HHA(8, 0);
DEFINE_HIP11_HHA(8, 1);
DEFINE_HIP11_HHA(8, 2);
DEFINE_HIP11_HHA(8, 3);
DEFINE_HIP11_HHA(9, 0);
DEFINE_HIP11_HHA(9, 1);
DEFINE_HIP11_HHA(9, 2);
DEFINE_HIP11_HHA(9, 3);
DEFINE_HIP11_UC(0, 0, 0);
DEFINE_HIP11_UC(0, 0, 1);
DEFINE_HIP11_UC(0, 0, 2);
DEFINE_HIP11_UC(0, 0, 3);
DEFINE_HIP11_UC(0, 1, 0);
DEFINE_HIP11_UC(0, 1, 1);
DEFINE_HIP11_UC(0, 1, 2);
DEFINE_HIP11_UC(0, 1, 3);
DEFINE_HIP11_UC(0, 2, 0);
DEFINE_HIP11_UC(0, 2, 1);
DEFINE_HIP11_UC(0, 2, 2);
DEFINE_HIP11_UC(0, 2, 3);
DEFINE_HIP11_UC(0, 3, 0);
DEFINE_HIP11_UC(0, 3, 1);
DEFINE_HIP11_UC(0, 3, 2);
DEFINE_HIP11_UC(0, 3, 3);
DEFINE_HIP11_UC(1, 0, 0);
DEFINE_HIP11_UC(1, 0, 1);
DEFINE_HIP11_UC(1, 0, 2);
DEFINE_HIP11_UC(1, 0, 3);
DEFINE_HIP11_UC(1, 1, 0);
DEFINE_HIP11_UC(1, 1, 1);
DEFINE_HIP11_UC(1, 1, 2);
DEFINE_HIP11_UC(1, 1, 3);
DEFINE_HIP11_UC(1, 2, 0);
DEFINE_HIP11_UC(1, 2, 1);
DEFINE_HIP11_UC(1, 2, 2);
DEFINE_HIP11_UC(1, 2, 3);
DEFINE_HIP11_UC(1, 3, 0);
DEFINE_HIP11_UC(1, 3, 1);
DEFINE_HIP11_UC(1, 3, 2);
DEFINE_HIP11_UC(1, 3, 3);
DEFINE_HIP11_UC(8, 0, 0);
DEFINE_HIP11_UC(8, 0, 1);
DEFINE_HIP11_UC(8, 0, 2);
DEFINE_HIP11_UC(8, 0, 3);
DEFINE_HIP11_UC(8, 1, 0);
DEFINE_HIP11_UC(8, 1, 1);
DEFINE_HIP11_UC(8, 1, 2);
DEFINE_HIP11_UC(8, 1, 3);
DEFINE_HIP11_UC(8, 2, 0);
DEFINE_HIP11_UC(8, 2, 1);
DEFINE_HIP11_UC(8, 2, 2);
DEFINE_HIP11_UC(8, 2, 3);
DEFINE_HIP11_UC(8, 3, 0);
DEFINE_HIP11_UC(8, 3, 1);
DEFINE_HIP11_UC(8, 3, 2);
DEFINE_HIP11_UC(8, 3, 3);
DEFINE_HIP11_UC(9, 0, 0);
DEFINE_HIP11_UC(9, 0, 1);
DEFINE_HIP11_UC(9, 0, 2);
DEFINE_HIP11_UC(9, 0, 3);
DEFINE_HIP11_UC(9, 1, 0);
DEFINE_HIP11_UC(9, 1, 1);
DEFINE_HIP11_UC(9, 1, 2);
DEFINE_HIP11_UC(9, 1, 3);
DEFINE_HIP11_UC(9, 2, 0);
DEFINE_HIP11_UC(9, 2, 1);
DEFINE_HIP11_UC(9, 2, 2);
DEFINE_HIP11_UC(9, 2, 3);
DEFINE_HIP11_UC(9, 3, 0);
DEFINE_HIP11_UC(9, 3, 1);
DEFINE_HIP11_UC(9, 3, 2);
DEFINE_HIP11_UC(9, 3, 3);
