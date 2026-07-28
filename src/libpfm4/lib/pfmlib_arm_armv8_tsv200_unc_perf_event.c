/*
 * TaiShan v200 uncore perf_event encoding
 *
 * Uses sysfs PMU type from perf_name (exact c920bn1 device name).
 * Same config-field model as Kunpeng uncore, different event tables.
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#include "pfmlib_priv.h"
#include "pfmlib_perf_event_priv.h"
#include "pfmlib_arm_priv.h"
#include "pfmlib_arm_armv8_unc_priv.h"

static int
find_pmu_type_by_name(const char *name)
{
	char filename[PATH_MAX];
	FILE *fp;
	int ret, type;

	if (!name)
		return PFM_ERR_NOTSUPP;

	sprintf(filename, "/sys/bus/event_source/devices/%s/type", name);

	fp = fopen(filename, "r");
	if (!fp)
		return PFM_ERR_NOTSUPP;

	ret = fscanf(fp, "%d", &type);
	if (ret != 1)
		type = PFM_ERR_NOTSUPP;

	fclose(fp);

	return type;
}

int
pfm_tsv200_unc_get_perf_encoding(void *this, pfmlib_event_desc_t *e)
{
	pfmlib_pmu_t *pmu = this;
	struct perf_event_attr *attr = e->os_data;
	kunpeng_unc_data_t reg;
	int ret;

	if (!pmu->get_event_encoding[PFM_OS_NONE])
		return PFM_ERR_NOTSUPP;

	ret = pmu->get_event_encoding[PFM_OS_NONE](this, e);
	if (ret != PFM_SUCCESS)
		return ret;

	ret = find_pmu_type_by_name(pmu->perf_name);
	if (ret < 0)
		return ret;

	attr->type = ret;
	reg.val = e->codes[0];
	attr->config = reg.val;

	attr->exclude_hv = 0;
	attr->exclude_kernel = 0;
	attr->exclude_user = 0;

	return PFM_SUCCESS;
}
