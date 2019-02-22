/*
 * wifi_icon_16x16.c
 *
 *  Created on: 2019年2月16日
 *      Author: XIAOSENLUO
 */

#include "oled_images.h"

static const uint8_t _wifi_icon_16x16[] = {
		0X00,0X00,0X00,0X00,0X07,0XE0,0X3F,0XFC,0X70,0X0E,0XE0,0X07,0X47,0XE2,0X1E,0X78,
		0X18,0X18,0X03,0XC0,0X07,0XE0,0X00,0X00,0X01,0X80,0X01,0X80,0X00,0X00,0X00,0X00,
};

oledImage wifi_icon_16x16 = {.width = 16, .height = 16, .data = _wifi_icon_16x16};
