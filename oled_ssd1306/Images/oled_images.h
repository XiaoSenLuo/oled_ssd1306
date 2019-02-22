/*
 * oled_images.h
 *
 *  Created on: 2019年2月16日
 *      Author: XIAOSENLUO
 */

#ifndef IMAGES_OLED_IMAGES_H_
#define IMAGES_OLED_IMAGES_H_

#include "stdint.h"

typedef struct _oledimages{
	const uint8_t width;
	const uint8_t height;
	const uint8_t* data;
}oledImage;


extern oledImage wifi_icon_16x16;
extern oledImage signal_icon_16x16;
extern oledImage battery_change_icon_8x16;
extern oledImage bluetoot_icon_16x16;
extern oledImage jlu_icon_48x48;


#endif /* IMAGES_OLED_IMAGES_H_ */
