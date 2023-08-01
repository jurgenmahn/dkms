/*
 * Copyright 2022 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_LINK_DP_CAPABILITY_H__
#define __DC_LINK_DP_CAPABILITY_H__

#include "link.h"

bool detect_dp_sink_caps(struct dc_link *link);

void detect_edp_sink_caps(struct dc_link *link);

struct dc_link_settings dp_get_max_link_cap(struct dc_link *link);


enum dc_status dp_retrieve_lttpr_cap(struct dc_link *link);

/* Convert PHY repeater count read from DPCD uint8_t. */
uint8_t dp_parse_lttpr_repeater_count(uint8_t lttpr_repeater_count);

bool dp_is_lttpr_present(struct dc_link *link);

bool is_dp_active_dongle(const struct dc_link *link);

bool is_dp_branch_device(const struct dc_link *link);

void dpcd_write_cable_id_to_dprx(struct dc_link *link);

/* Initialize output parameter lt_settings. */
void dp_decide_training_settings(
	struct dc_link *link,
	const struct dc_link_settings *link_setting,
	struct link_training_settings *lt_settings);


#ifdef CONFIG_DRM_AMD_DC_DSC_SUPPORT
bool decide_edp_link_settings_with_dsc(struct dc_link *link,
		struct dc_link_settings *link_setting,
		uint32_t req_bw,
		enum dc_link_rate max_link_rate);
#endif

void dpcd_set_source_specific_data(struct dc_link *link);

/*query dpcd for version and mst cap addresses*/
bool read_is_mst_supported(struct dc_link *link);

bool decide_fallback_link_setting(
		struct dc_link *link,
		struct dc_link_settings *max,
		struct dc_link_settings *cur,
		enum link_training_result training_result);

bool dp_verify_link_cap_with_retries(
	struct dc_link *link,
	struct dc_link_settings *known_limit_link_setting,
	int attempts);

#endif /* __DC_LINK_DP_CAPABILITY_H__ */
