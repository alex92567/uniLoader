/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Oleksii Onchul <oleksiionchul@gmail.com>
 */

#include <board.h>
#include <string.h>
#include <util.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

#define ZUMAPRO_DECON_F_BASE		0x19470000
#define ZUMAPRO_HW_SW_TRIG_CONTROL	0x30
#define CAIMITO_FRAMEBUFFER_BASE		0xfac00000

#if defined(CONFIG_GOOGLE_CAIMAN)
#define CAIMITO_BOARD_NAME		"google-caiman"
#define CAIMITO_FRAMEBUFFER_WIDTH	1280
#define CAIMITO_FRAMEBUFFER_HEIGHT	2856
#elif defined(CONFIG_GOOGLE_COMET)
#define CAIMITO_BOARD_NAME		"google-comet"
#define CAIMITO_FRAMEBUFFER_WIDTH	2076
#define CAIMITO_FRAMEBUFFER_HEIGHT	2152
#elif defined(CONFIG_GOOGLE_KOMODO)
#define CAIMITO_BOARD_NAME		"google-komodo"
#define CAIMITO_FRAMEBUFFER_WIDTH	1344
#define CAIMITO_FRAMEBUFFER_HEIGHT	2992
#elif defined(CONFIG_GOOGLE_TEGU)
#define CAIMITO_BOARD_NAME		"google-tegu"
#define CAIMITO_FRAMEBUFFER_WIDTH	1080
#define CAIMITO_FRAMEBUFFER_HEIGHT	2424
#elif defined(CONFIG_GOOGLE_TOKAY)
#define CAIMITO_BOARD_NAME		"google-tokay"
#define CAIMITO_FRAMEBUFFER_WIDTH	1080
#define CAIMITO_FRAMEBUFFER_HEIGHT	2424
#endif

static int caimito_early_init(void)
{
	/* Allow framebuffer writes. */
	writel(0x3061, (void *)(ZUMAPRO_DECON_F_BASE +
				 ZUMAPRO_HW_SW_TRIG_CONTROL));

	return 0;
}

static struct video_info caimito_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = CAIMITO_FRAMEBUFFER_WIDTH,
	.height = CAIMITO_FRAMEBUFFER_HEIGHT,
	.stride = 4,
	.scale = 2,
	.address = (void *)CAIMITO_FRAMEBUFFER_BASE,
};

static const struct device caimito_devices[] = {
	{ "simplefb", &caimito_fb, "fb" },
};

struct board_data board_ops = {
	.name = CAIMITO_BOARD_NAME,
	.ops = {
		.early_init = caimito_early_init,
	},
	.devices = caimito_devices,
	.num_devices = ARRAY_SIZE(caimito_devices),
	.quirks = 0,
};
