/*
 * battery_100_icon_8x16.c
 *
 *  Created on: 2019年2月16日
 *      Author: XIAOSENLUO
 */

#include "oled_images.h"


static const uint8_t _battery_change_icon_8x16[] = {
		0X1C,0X3C,0X38,0X38,0X70,0X7E,0X7E,0X0C,0X0C,0X08,0X18,0X10,0X10,0X00,0X20,0X00
};


oledImage battery_change_icon_8x16 = {.width = 8, .height = 16, .data = _battery_change_icon_8x16};

