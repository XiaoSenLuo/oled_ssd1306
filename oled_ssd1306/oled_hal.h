/*
 * oled_hal.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef NEW_OLED_HAL_H_
#define NEW_OLED_HAL_H_


#include "Fonts/oled_fonts.h"
#include "stdbool.h"
#include "oled_ssd1306.h"
#include "Images/oled_images.h"

int16_t oled_getHeight(void);
int16_t oled_getWidth(void);

uint8_t oled_getRotation(void);

// get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
int16_t oled_getCursorX(void);
int16_t oled_getCursorY(void);

void oled_setRotation(uint8_t r);

void oled_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
void oled_drawCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
void oled_drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint8_t color);
void oled_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
void oled_drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint8_t color);
void oled_drawChar(int16_t x, int16_t y, char c, uint8_t color, uint16_t bg, uint8_t size);
void oled_drawText(int16_t x, int16_t y, char* text);

void oled_displayHex8(int16_t x, int16_t y, uint8_t hex8);
void oled_displayHex16(int16_t x, int16_t y, uint8_t hex16);
void oled_displayHex32(int16_t x, int16_t y, uint8_t hex32);

void oled_displayInt(int16_t x, int16_t y, int num);

void oled_displayFloat(int16_t x, int16_t y, float _float);

void oled_fillCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
void oled_fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint8_t color);
void oled_fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
void oled_fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint8_t color);
void oled_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);


void oled_drawBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color);
void oled_drawBitmapFromRAM(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint8_t color);
void oled_drawXBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color);
//void oled_drawGrayscaleBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h);
//void oled_drawGrayscaleBitmapFromRAM(int16_t x, int16_t y, uint8_t *bitmap,int16_t w, int16_t h);
//void oled_drawGrayscaleBitmap(int16_t x, int16_t y,const uint8_t bitmap[], const uint8_t mask[], int16_t w, int16_t h);
//void oled_drawGrayscaleBitmap(int16_t x, int16_t y,uint8_t *bitmap, uint8_t *mask, int16_t w, int16_t h);

void oled_setTextSize(uint8_t s);
void oled_setTextColor(uint8_t color, uint8_t bg);

//void oled_setFont(const GFXfont *f);
void oled_setUserFont(oledFont* _userfont);
uint8_t oled_getUserFontW(void);
uint8_t oled_getUserFontH(void);
//void oled_getTextBounds(const char *string, int16_t x, int16_t y,int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);





#endif /* NEW_OLED_HAL_H_ */
