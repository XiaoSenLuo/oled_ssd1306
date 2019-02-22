/*
 * oled_fonts.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef NEW_OLED_FONTS_H_
#define NEW_OLED_FONTS_H_

#include "stdint.h"

//typedef struct{
//	uint16_t bitmapOffset;     ///< Pointer into GFXfont->bitmap
//	uint8_t  width;            ///< Bitmap dimensions in pixels
//  uint8_t  height;           ///< Bitmap dimensions in pixels
//	uint8_t  xAdvance;         ///< Distance to advance cursor (x axis)
//	int8_t   xOffset;          ///< X dist from cursor pos to UL corner
//  int8_t   yOffset;          ///< Y dist from cursor pos to UL corner
//}GFXglyph;
//
///// Data stored for FONT AS A WHOLE
//typedef struct{
//	uint8_t  *bitmap;      ///< Glyph bitmaps, concatenated
//	GFXglyph *glyph;       ///< Glyph array
//	uint8_t   first;       ///< ASCII extents (first char)
//  uint8_t   last;        ///< ASCII extents (last char)
//	uint8_t   yAdvance;    ///< Newline distance (y axis)
//}GFXfont;

typedef struct _oled_font{
	const uint8_t width;
	const uint8_t height;
	const uint8_t* data;
}oledFont;


extern oledFont SongFont_ASCII_5x8;
extern oledFont SongFont_ASCII_16x16;
extern oledFont SongFont_ASCII_8x16;

#endif /* NEW_OLED_FONTS_H_ */
