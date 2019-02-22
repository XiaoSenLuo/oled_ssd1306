/*
 * signal_icon_16x16.c
 *
 *  Created on: 2019年2月16日
 *      Author: XIAOSENLUO
 */

#include "oled_images.h"

static const uint8_t _signal_icon_16x16[] = {
		0X00,0X00,0X00,0X00,0X18,0X18,0X30,0X1C,0X36,0X6C,0X6C,0X36,0X6D,0XB6,0X6D,0XB6,
		0X26,0X64,0X37,0XCC,0X19,0X98,0X01,0X80,0X01,0X80,0X01,0X80,0X00,0X00,0X00,0X00,
};


oledImage signal_icon_16x16 = {.width = 16, .height = 16, .data = _signal_icon_16x16};
