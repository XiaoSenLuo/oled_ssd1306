/*
 * oled_ssd1306.c
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#include "oled_ssd1306.h"
#include "oled_spi_.h"
#include "string.h"
#include "math.h"

#define HEIGHT 									SSD1306_LCDHEIGHT
#define WIDTH										SSD1306_LCDWIDTH

#define SSD1306_Delay(time)												HAL_Delay((time))
#define SSD1306_Swap(a,b)													(((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#ifndef SSD1306_Min
#define SSD1306_Min(a,b) 													(((a) < (b)) ? (a) : (b))
#endif
#define SSD1306_Write(chr)												SPIWrite((chr))
#define SSD1306_WriteBuffer(buffer, Size)					SPIWriteBuffer((buffer), (Size))


static void drawFastVLineInternal(int16_t x, int16_t y, int16_t h, uint8_t color);
static void drawFastHLineInternal(int16_t x, int16_t __y, int16_t __w, uint8_t color);
static void ssd1306_reset(void);
static void ssd1306_pinInit(void);
static void ssd1306_data(uint8_t* dataBuffer, uint16_t Size);


int16_t
  _width = WIDTH,         ///< Display width as modified by current rotation
  _height = HEIGHT,        ///< Display height as modified by current rotation
  cursorX = 0,       ///< x location to start print()ing text
  cursorY = 0;       ///< y location to start print()ing text
uint8_t
  rotation = 0;       ///< Display rotation (0 thru 3)
bool
	_cp437 = false,
  wrap = true;           ///< If set, 'wrap' text at right edge of display

static volatile uint8_t vccState;
volatile bool isChange = false;
uint8_t ssd1306_buffer[SSD1306_LCDWIDTH * ((SSD1306_LCDHEIGHT + 7) / 8)];

/************************************** static function **************************************************************/

static void drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint8_t color){
  // do nothing if we're off the left or right side of the screen
  if(x < 0 || x >= WIDTH) { return; }

  // make sure we don't try to draw below 0
  if(__y < 0) {
    // __y is negative, this will subtract enough from __h to account for __y being 0
    __h += __y;
    __y = 0;

  }

  // make sure we don't go past the height of the display
  if( (__y + __h) > HEIGHT) {
    __h = (HEIGHT - __y);
  }

  // if our height is now negative, punt
  if(__h <= 0) {
    return;
  }

  // this display doesn't need ints for coordinates, use local byte registers for faster juggling
  register uint8_t y = __y;
  register uint8_t h = __h;


  // set up the pointer for fast movement through the buffer
  register uint8_t *pBuf = ssd1306_buffer;
  // adjust the buffer pointer for the current row
  pBuf += ((y/8) * SSD1306_LCDWIDTH);
  // and offset x columns in
  pBuf += x;

  // do the first partial byte, if necessary - this requires some masking
  register uint8_t mod = (y&7);
  if(mod) {
    // mask off the high n bits we want to set
    mod = 8-mod;

    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    // register uint8_t mask = ~(0xFF >> (mod));
    static uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
    register uint8_t mask = premask[mod];

    // adjust the mask if we're not going to reach the end of this byte
    if( h < mod) {
      mask &= (0XFF >> (mod-h));
    }

  switch (color)
    {
    case WHITE:   *pBuf |=  mask;  break;
    case BLACK:   *pBuf &= ~mask;  break;
    case INVERSE: *pBuf ^=  mask;  break;
    }

    // fast exit if we're done here!
    if(h<mod) { return; }

    h -= mod;

    pBuf += SSD1306_LCDWIDTH;
  }


  // write solid bytes while we can - effectively doing 8 rows at a time
  if(h >= 8) {
    if (color == INVERSE)  {          // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
      do  {
      *pBuf=~(*pBuf);

        // adjust the buffer forward 8 rows worth of data
        pBuf += SSD1306_LCDWIDTH;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        h -= 8;
      } while(h >= 8);
      }
    else {
      // store a local value to work with
      register uint8_t val = (color == WHITE) ? 255 : 0;

      do  {
        // write our value in
      *pBuf = val;

        // adjust the buffer forward 8 rows worth of data
        pBuf += SSD1306_LCDWIDTH;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        h -= 8;
      } while(h >= 8);
      }
    }

  // now do the final partial byte, if necessary
  if(h) {
    mod = h & 7;
    // this time we want to mask the low bits of the byte, vs the high bits we did above
    // register uint8_t mask = (1 << mod) - 1;
    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    static uint8_t postmask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
    register uint8_t mask = postmask[mod];
    switch (color)
    {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
    }
  }

}
static void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint8_t color){
  if((y >= 0) && (y < HEIGHT)){ // Y coord in bounds?
    if(x < 0){ // Clip left
      w += x;
      x  = 0;
    }
    if((x + w) > WIDTH){ // Clip right
      w = (WIDTH - x);
    }

    if(w > 0){ // Proceed only if width is positive
    	register uint8_t *pBuf = ssd1306_buffer;
      // adjust the buffer pointer for the current row
      pBuf += ((y/8) * SSD1306_LCDWIDTH);
      // and offset x columns in
      pBuf += x;
      register  uint8_t mask = 1 << (y&7);
      switch(color){
       case WHITE:               while(w--) { *pBuf++ |= mask; }; break;
       case BLACK: mask = ~mask; while(w--) { *pBuf++ &= mask; }; break;
       case INVERSE:             while(w--) { *pBuf++ ^= mask; }; break;
      }
    }
  }
}
static void ssd1306_reset(void){
	SSD1306_RST_SET();
	SSD1306_Delay(1);
	SSD1306_RST_RESET();
	SSD1306_Delay(10);
	SSD1306_RST_SET();
}
static void ssd1306_pinInit(void){
	GPIO_InitTypeDef GPIO_InitStruct;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*	RST	*/
	GPIO_InitStruct.Pin = SSD1306_RST_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(SSD1306_RST_PORT, &GPIO_InitStruct);
	/*	DC	*/
	GPIO_InitStruct.Pin = SSD1306_DC_PIN;
	HAL_GPIO_Init(SSD1306_DC_PORT, &GPIO_InitStruct);
	/*	CS	*/
	GPIO_InitStruct.Pin = SSD1306_CS_PIN;
	HAL_GPIO_Init(SSD1306_CS_PORT, &GPIO_InitStruct);
}

static void ssd1306_data(uint8_t* dataBuffer, uint16_t Size){
	SSD1306_MODE_DATA();
	SSD1306_SELETE();
	SSD1306_WriteBuffer(dataBuffer, Size);
	SSD1306_NOSELETE();
}

/************************************** static function **************************************************************/

/************************************** public function **************************************************************/
void ssd1306_Init(uint8_t _vccState){
	ssd1306_pinInit();
	SPIInit();
	ssd1306_clearScreen();

	vccState = _vccState;
	vccState = SSD1306_SWITCHCAPVCC;
	/*	RESET SSD1306 MCU	*/
	ssd1306_reset();
	/*	Init sequence	*/
#if defined SSD1306_128_32
 // Init sequence for 128x32 OLED module
 ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
 ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
 ssd1306_command(0x80);                                  // the suggested ratio 0x80
 ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
 ssd1306_command(0x1F);
 ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
 ssd1306_command(0x0);                                   // no offset
 ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
 ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
 if (_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x10); }
 else
   { ssd1306_command(0x14); }
 ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
 ssd1306_command(0x00);                                  // 0x0 act like ks0108
 ssd1306_command(SSD1306_SEGREMAP | 0x1);
 ssd1306_command(SSD1306_COMSCANDEC);
 ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
 ssd1306_command(0x02);
 ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
 ssd1306_command(0x8F);
 ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
 if (_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x22); }
 else
   { ssd1306_command(0xF1); }
 ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
 ssd1306_command(0x40);
 ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
 ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
#endif

#if defined SSD1306_128_64
 // Init sequence for 128x64 OLED module
 ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
 ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
 ssd1306_command(0x80);                                  // the suggested ratio 0x80
 ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
 ssd1306_command(0x3F);
 ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
 ssd1306_command(0x0);                                   // no offset
 ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
 ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
 if(_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x10); }
 else
   { ssd1306_command(0x14); }
 ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
 ssd1306_command(0x00);                                  // 0x0 act like ks0108
 ssd1306_command(SSD1306_SEGREMAP | 0x1);
 ssd1306_command(SSD1306_COMSCANDEC);
 ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
 ssd1306_command(0x12);
 ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
 if (_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x9F); }
 else
   { ssd1306_command(0xCF); }
 ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
 if (_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x22); }
 else
   { ssd1306_command(0xF1); }
 ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
 ssd1306_command(0x40);
 ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
 ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
#endif

#if defined SSD1306_96_16
 // Init sequence for 96x16 OLED module
 ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
 ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
 ssd1306_command(0x80);                                  // the suggested ratio 0x80
 ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
 ssd1306_command(0x0F);
 ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
 ssd1306_command(0x00);                                   // no offset
 ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
 ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
 if(_vccState == SSD1306_EXTERNALVCC){
	 ssd1306_command(0x10);
 }
 else{
	 ssd1306_command(0x14);
 }
 ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
 ssd1306_command(0x00);                                  // 0x0 act like ks0108
 ssd1306_command(SSD1306_SEGREMAP | 0x1);
 ssd1306_command(SSD1306_COMSCANDEC);
 ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
 ssd1306_command(0x2);	//ada x12
 ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
 if(_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x10); }
 else
   { ssd1306_command(0xAF); }
 ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
 if (_vccState == SSD1306_EXTERNALVCC)
   { ssd1306_command(0x22); }
 else
   { ssd1306_command(0xF1); }
 ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
 ssd1306_command(0x40);
 ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
 ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
#endif

  ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel

  ssd1306_clearScreen();
}
void ssd1306_updateScreen(void){
  ssd1306_command(SSD1306_COLUMNADDR);
  ssd1306_command(0);   // Column start address (0 = reset)
  ssd1306_command(SSD1306_LCDWIDTH-1); // Column end address (127 = reset)

  ssd1306_command(SSD1306_PAGEADDR);
  ssd1306_command(0); // Page start address (0 = reset)
  #if SSD1306_LCDHEIGHT == 64
    ssd1306_command(7); // Page end address
  #endif
  #if SSD1306_LCDHEIGHT == 32
    ssd1306_command(3); // Page end address
  #endif
  #if SSD1306_LCDHEIGHT == 16
    ssd1306_command(1); // Page end address
  #endif
  SSD1306_MODE_DATA();
  SSD1306_SELETE();
  SSD1306_WriteBuffer(ssd1306_buffer, (WIDTH * ((HEIGHT + 7) / 8)));
  SSD1306_NOSELETE();

}
/* @param:startcol:range:0~127, and startcol <= stopcol;
 *				stopcol:range:0~127
 * 				startpage:range:0~7, and startpage <= stoppage;
 * 				stoppage:range:0~7;
 * */
void ssd1306_updataArea(uint8_t startcol, uint8_t stopcol, uint8_t startpage, uint8_t stoppage){
	ssd1306_command(SSD1306_COLUMNADDR);
	ssd1306_command(startcol);
	ssd1306_command(stopcol);

	ssd1306_command(SSD1306_PAGEADDR);
	ssd1306_command(startpage);
	ssd1306_command(stoppage);

  SSD1306_MODE_DATA();
  SSD1306_SELETE();
  for(uint8_t j = startpage; j <= stoppage; j++){
  	for(uint8_t i = startcol; i <= stopcol; i++){
  		SSD1306_Write(ssd1306_buffer[i+j*128]);
  	}
  }
  SSD1306_NOSELETE();
}
void ssd1306_clearScreen(void){
	memset(ssd1306_buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}
void ssd1306_invertDisplay(bool _invert){
	ssd1306_command((_invert ? SSD1306_INVERTDISPLAY : SSD1306_NORMALDISPLAY));
}
void ssd1306_dimDisplay(bool _dim){
  uint8_t contrast;
  if(_dim) {
    contrast = 0; // Dimmed display
  } else {
    contrast = ((vccState == SSD1306_EXTERNALVCC) ? 0x9F : 0xCF);
  }
  // the range of contrast to too small to be really useful
  // it is useful to dim the display
  ssd1306_command(SSD1306_SETCONTRAST);
  ssd1306_command(contrast);
}
void ssd1306_drawPixel(int16_t x, int16_t y, uint8_t color){
  if((x >= 0) && (x < SSD1306_LCDWIDTH) && (y >= 0) && (y < SSD1306_LCDHEIGHT)){
    // Pixel is in-bounds. Rotate coordinates if needed.
    switch(rotation) {
     case 1:
      SSD1306_Swap(x, y);
      x = SSD1306_LCDWIDTH - x - 1;
      break;
     case 2:
      x = SSD1306_LCDWIDTH  - x - 1;
      y = SSD1306_LCDHEIGHT - y - 1;
      break;
     case 3:
      SSD1306_Swap(x, y);
      y = SSD1306_LCDHEIGHT - y - 1;
      break;
    }
    switch(color) {
     case WHITE:   ssd1306_buffer[x + (y/8)*SSD1306_LCDWIDTH] |=  (1 << (y&7)); break;
     case BLACK:   ssd1306_buffer[x + (y/8)*SSD1306_LCDWIDTH] &= ~(1 << (y&7)); break;
     case INVERSE: ssd1306_buffer[x + (y/8)*SSD1306_LCDWIDTH] ^=  (1 << (y&7)); break;
    }
  }
}
void ssd1306_drawFastHLine(int16_t x, int16_t y, int16_t w, uint8_t color){
  bool bSwap = false;
  switch(rotation){
  	case 0: break;
   case 1:
    // 90 degree rotation, swap x & y for rotation, then invert x
    bSwap = true;
    SSD1306_Swap(x, y);
    x = WIDTH - x - 1;
    break;
   case 2:
    // 180 degree rotation, invert x and y, then shift y around for height.
    x  = WIDTH  - x - 1;
    y  = HEIGHT - y - 1;
    x -= (w-1);
    break;
   case 3:
    // 270 degree rotation, swap x & y for rotation,
    // then invert y and adjust y for w (not to become h)
    bSwap = true;
    SSD1306_Swap(x, y);
    y  = HEIGHT - y - 1;
    y -= (w-1);
    break;
  }
  if(bSwap) drawFastVLineInternal(x, y, w, color);
  else      drawFastHLineInternal(x, y, w, color);
}
void ssd1306_drawFastVLine(int16_t x, int16_t y, int16_t h, uint8_t color){
  bool bSwap = false;
  switch(rotation){
  	case 0: break;
   case 1:
    // 90 degree rotation, swap x & y for rotation,
    // then invert x and adjust x for h (now to become w)
    bSwap = true;
    SSD1306_Swap(x, y);
    x  = WIDTH - x - 1;
    x -= (h-1);
    break;
   case 2:
    // 180 degree rotation, invert x and y, then shift y around for height.
    x = WIDTH  - x - 1;
    y = HEIGHT - y - 1;
    y -= (h-1);
    break;
   case 3:
    // 270 degree rotation, swap x & y for rotation, then invert y
    bSwap = true;
    SSD1306_Swap(x, y);
    y = HEIGHT - y - 1;
    break;
  }

  if(bSwap) drawFastHLineInternal(x, y, h, color);
  else      drawFastVLineInternal(x, y, h, color);
}

void ssd1306_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color){
  if(x0 == x1){
      if(y0 > y1) SSD1306_Swap(y0, y1);
      ssd1306_drawFastVLine(x0, y0, y1 - y0 + 1, color);
  } else if(y0 == y1){
      if(x0 > x1) SSD1306_Swap(x0, x1);
      ssd1306_drawFastHLine(x0, y0, x1 - x0 + 1, color);
  } else {
    bool steep = abs((int)y1 - (int)y0) > abs((int)x1 - (int)x0) ? true : false;
    if (steep) {
    	SSD1306_Swap(x0, y0);
    	SSD1306_Swap(x1, y1);
    }

    if (x0 > x1) {
    	SSD1306_Swap(x0, x1);
    	SSD1306_Swap(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            ssd1306_drawPixel(y0, x0, color);
        } else {
            ssd1306_drawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
  }
}

void ssd1306_fillScreen(uint8_t color){
  for(int16_t i = 0; i < SSD1306_LCDWIDTH; i++){
      ssd1306_drawFastVLine(i, 0, SSD1306_LCDHEIGHT, color);
  }
}
/*!
    @brief  Activate a right-handed scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/
/*	To scroll the whole display, run: ssd1306_startScrollRight(0x00, 0x0F)	*/
void ssd1306_startScrollRight(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X0F);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
/*!
    @brief  Activate a left-handed scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/
/*	To scroll the whole display, run: ssd1306_startScrollLeft(0x00, 0x0F)	*/
void ssd1306_startScrollLeft(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(7);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
/*!
    @brief  Activate a diagonal scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/
void ssd1306_startScrollDiagRight(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
/*!
    @brief  Activate alternate diagonal scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/
void ssd1306_startScrollDiagLeft(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
void ssd1306_stopScroll(void){
	ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
}
void ssd1306_command(uint8_t com){
	SSD1306_SELETE();
	SSD1306_MODE_COMMAND();
	SSD1306_Write(com);
	SSD1306_NOSELETE();
}
bool ssd1306_getPixel(int16_t x, int16_t y){
  if((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)) {
    // Pixel is in-bounds. Rotate coordinates if needed.
    switch(rotation) {
     case 1:
      SSD1306_Swap(x, y);
      x = WIDTH - x - 1;
      break;
     case 2:
      x = WIDTH  - x - 1;
      y = HEIGHT - y - 1;
      break;
     case 3:
      SSD1306_Swap(x, y);
      y = HEIGHT - y - 1;
      break;
    }
    cursorX = x;
    cursorY = y;
    return (ssd1306_buffer[x + (y / 8) * WIDTH] & (1 << (y & 7)));
  }
  return false; // Pixel out of bounds
}
uint8_t* ssd1306_getBuffer(void){
	return ssd1306_buffer;
}

int16_t ssd1306_getHeight(void){
	return _height;
}

int16_t ssd1306_getWidth(void){
	return _width;
}

void ssd1306_setRotation(uint8_t r){
  rotation = (r & 3);
  switch(rotation){
    case 0:
    case 2:
      _width  = WIDTH;
      _height = HEIGHT;
      break;
    case 1:
    case 3:
      _width  = HEIGHT;
       _height = WIDTH;
      break;
  }
}

uint8_t ssd1306_getRotation(void){
	return rotation;
}

void ssd1306_setCursor(int16_t x, int16_t y){
	cursorX = x;
	cursorY = y;
}
// get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
int16_t ssd1306_getCursorX(void){
	return cursorX;
}
int16_t ssd1306_getCursorY(void){
	return cursorY;
}

void ssd1306_setTextWrap(bool w){
	wrap = w;
}

void ssd1306_cp437(bool x){
	_cp437 = x;
}


/************************************** public function **************************************************************/















