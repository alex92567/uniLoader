/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Trijal Saha <97483939+Trijal08@users.noreply.github.com>
 * Copyright (c) 2026, Oleksii Onchul <oleksiionchul@gmail.com>
 */

#ifndef ZUMAPRO_H_	/* Include guard */
#define ZUMAPRO_H_

#define DECON_F_BASE		0x19470000
#define HW_SW_TRIG_CONTROL	0x30

/*
 * General specifications for each Pixel 9 series device target
 */

#ifdef CONFIG_GOOGLE_COMET
#define FRAMEBUFFER_WIDTH 2076
#define FRAMEBUFFER_HEIGHT 2152

#define BOARD_NAME "google-comet"
#endif

#ifdef CONFIG_GOOGLE_CAIMAN
#define FRAMEBUFFER_WIDTH 1280
#define FRAMEBUFFER_HEIGHT 2856

#define BOARD_NAME "google-caiman"
#endif

#ifdef CONFIG_GOOGLE_KOMODO
#define FRAMEBUFFER_WIDTH 1344
#define FRAMEBUFFER_HEIGHT 2992

#define BOARD_NAME "google-komodo"
#endif

#ifdef CONFIG_GOOGLE_TOKAY
#define FRAMEBUFFER_WIDTH 1080
#define FRAMEBUFFER_HEIGHT 2424

#define BOARD_NAME "google-tokay"
#endif

#ifdef CONFIG_GOOGLE_TEGU
#define FRAMEBUFFER_WIDTH 1080
#define FRAMEBUFFER_HEIGHT 2424

#define BOARD_NAME "google-tegu"
#endif

#endif // ZUMAPRO_H_
