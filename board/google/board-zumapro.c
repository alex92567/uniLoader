/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Trijal Saha <97483939+Trijal08@users.noreply.github.com>
 * Copyright (c) 2026, Oleksii Onchul <oleksiionchul@gmail.com>
 */
#include <board.h>
#include <util.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

#include <soc/zumapro.h>

// Early initialization
int zumapro_init(void)
{
	/* Allow framebuffer to be written to */
    *(int*) (DECON_F_BASE + HW_SW_TRIG_CONTROL) = 0x3061;
	return 0;
}

static struct video_info zumapro_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = FRAMEBUFFER_WIDTH,
	.height = FRAMEBUFFER_HEIGHT,
	.stride = 4,
	.scale = 2,
	.address = (void *)0xfac00000
};

static const struct device zumapro_devices[] = {
	{ "simplefb", &zumapro_fb, "fb" }
};

struct board_data board_ops = {
	.name = BOARD_NAME,
	.ops = {
		.early_init = zumapro_init
	},
	.devices = zumapro_devices,
	.num_devices = ARRAY_SIZE(zumapro_devices),
	.quirks = 0
};
