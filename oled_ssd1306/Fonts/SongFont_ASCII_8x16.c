/*
 * SongFont_ASCII_8x16.c
 *
 *  Created on: 2019年2月15日
 *      Author: XIAOSENLUO
 */


#include "oled_fonts.h"

//宋体  ASCII字符
static const unsigned char _songfont_asciii_8x16[] = {
		/* ASCII 8x16点阵字库*/
		/*   [0x0020]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ![0x0021]    8x16 */
		0x00,0x00,0x00,0x00,0x1C,0x00,0x3F,0xB0,0x3F,0xB0,0x1C,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  "[0x0022]    8x16 */
		0x00,0x00,0x70,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x70,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  #[0x0023]    8x16 */
		0x04,0x40,0x1F,0xF0,0x1F,0xF0,0x04,0x40,0x1F,0xF0,0x1F,0xF0,0x04,0x40,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  $[0x0024]    8x16 */
		0x1C,0xC0,0x3E,0x60,0x22,0x20,0xE2,0x38,0xE2,0x38,0x33,0xE0,0x19,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  %[0x0025]    8x16 */
		0x0C,0x30,0x0C,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,0x06,0x30,0x0C,0x30,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  &[0x0026]    8x16 */
		0x01,0xE0,0x1B,0xF0,0x3E,0x10,0x27,0x10,0x3D,0xE0,0x1B,0xF0,0x02,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  '[0x0027]    8x16 */
		0x00,0x00,0x08,0x00,0x78,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ([0x0028]    8x16 */
		0x00,0x00,0x00,0x00,0x0F,0xC0,0x1F,0xE0,0x30,0x30,0x20,0x10,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  )[0x0029]    8x16 */
		0x00,0x00,0x00,0x00,0x20,0x10,0x30,0x30,0x1F,0xE0,0x0F,0xC0,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  *[0x002A]    8x16 */
		0x01,0x00,0x05,0x40,0x07,0xC0,0x03,0x80,0x03,0x80,0x07,0xC0,0x05,0x40,0x01,0x00,
		/* ASCII 8x16点阵字库*/
		/*  +[0x002B]    8x16 */
		0x00,0x00,0x01,0x00,0x01,0x00,0x07,0xC0,0x07,0xC0,0x01,0x00,0x01,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ,[0x002C]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x78,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  -[0x002D]    8x16 */
		0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  .[0x002E]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  /[0x002F]    8x16 */
		0x00,0x30,0x00,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,0x06,0x00,0x0C,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  0[0x0030]    8x16 */
		0x1F,0xE0,0x3F,0xF0,0x20,0x90,0x23,0x10,0x24,0x10,0x3F,0xF0,0x1F,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  1[0x0031]    8x16 */
		0x00,0x00,0x08,0x10,0x18,0x10,0x3F,0xF0,0x3F,0xF0,0x00,0x10,0x00,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  2[0x0032]    8x16 */
		0x10,0x70,0x30,0xF0,0x21,0x90,0x23,0x10,0x26,0x10,0x3C,0x30,0x18,0x30,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  3[0x0033]    8x16 */
		0x10,0x20,0x30,0x30,0x22,0x10,0x22,0x10,0x22,0x10,0x3F,0xF0,0x1D,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  4[0x0034]    8x16 */
		0x03,0x00,0x07,0x00,0x0D,0x00,0x19,0x10,0x3F,0xF0,0x3F,0xF0,0x01,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  5[0x0035]    8x16 */
		0x3E,0x20,0x3E,0x30,0x22,0x10,0x22,0x10,0x23,0x10,0x23,0xF0,0x21,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  6[0x0036]    8x16 */
		0x0F,0xE0,0x1F,0xF0,0x32,0x10,0x22,0x10,0x22,0x10,0x03,0xF0,0x01,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  7[0x0037]    8x16 */
		0x30,0x00,0x30,0x00,0x20,0xF0,0x21,0xF0,0x23,0x00,0x3E,0x00,0x3C,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  8[0x0038]    8x16 */
		0x1D,0xE0,0x3F,0xF0,0x22,0x10,0x22,0x10,0x22,0x10,0x3F,0xF0,0x1D,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  9[0x0039]    8x16 */
		0x1C,0x00,0x3E,0x10,0x22,0x10,0x22,0x10,0x22,0x30,0x3F,0xE0,0x1F,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  :[0x003A]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x60,0x0C,0x60,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ;[0x003B]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x10,0x0C,0x70,0x0C,0x60,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  <[0x003C]    8x16 */
		0x00,0x00,0x01,0x00,0x03,0x80,0x06,0xC0,0x0C,0x60,0x18,0x30,0x10,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  =[0x003D]    8x16 */
		0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  >[0x003E]    8x16 */
		0x00,0x00,0x10,0x10,0x18,0x30,0x0C,0x60,0x06,0xC0,0x03,0x80,0x01,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ?[0x003F]    8x16 */
		0x18,0x00,0x38,0x00,0x20,0x00,0x23,0xB0,0x27,0xB0,0x3C,0x00,0x18,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  @[0x0040]    8x16 */
		0x0F,0xE0,0x1F,0xF0,0x10,0x10,0x13,0xD0,0x13,0xD0,0x1F,0xD0,0x0F,0x80,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  A[0x0041]    8x16 */
		0x07,0xF0,0x0F,0xF0,0x19,0x00,0x31,0x00,0x19,0x00,0x0F,0xF0,0x07,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  B[0x0042]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x22,0x10,0x22,0x10,0x3F,0xF0,0x1D,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  C[0x0043]    8x16 */
		0x0F,0xC0,0x1F,0xE0,0x30,0x30,0x20,0x10,0x20,0x10,0x30,0x30,0x18,0x60,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  D[0x0044]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x20,0x10,0x30,0x30,0x1F,0xE0,0x0F,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  E[0x0045]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x22,0x10,0x27,0x10,0x30,0x30,0x38,0x70,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  F[0x0046]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x22,0x10,0x27,0x00,0x30,0x00,0x38,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  G[0x0047]    8x16 */
		0x0F,0xC0,0x1F,0xE0,0x30,0x30,0x21,0x10,0x21,0x10,0x31,0xE0,0x19,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  H[0x0048]    8x16 */
		0x3F,0xF0,0x3F,0xF0,0x02,0x00,0x02,0x00,0x02,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  I[0x0049]    8x16 */
		0x00,0x00,0x00,0x00,0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x20,0x10,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  J[0x004A]    8x16 */
		0x00,0xE0,0x00,0xF0,0x00,0x10,0x20,0x10,0x3F,0xF0,0x3F,0xE0,0x20,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  K[0x004B]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x0F,0x80,0x3C,0xF0,0x30,0x70,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  L[0x004C]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x20,0x10,0x00,0x10,0x00,0x30,0x00,0x70,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  M[0x004D]    8x16 */
		0x3F,0xF0,0x3F,0xF0,0x1C,0x00,0x0E,0x00,0x1C,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  N[0x004E]    8x16 */
		0x3F,0xF0,0x3F,0xF0,0x1C,0x00,0x0E,0x00,0x07,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  O[0x004F]    8x16 */
		0x0F,0xC0,0x1F,0xE0,0x30,0x30,0x20,0x10,0x30,0x30,0x1F,0xE0,0x0F,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  P[0x0050]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x22,0x10,0x22,0x00,0x3E,0x00,0x1C,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  Q[0x0051]    8x16 */
		0x1F,0xE0,0x3F,0xF0,0x20,0x10,0x20,0x70,0x20,0x3C,0x3F,0xFC,0x1F,0xE4,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  R[0x0052]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x22,0x00,0x23,0x00,0x3F,0xF0,0x1C,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  S[0x0053]    8x16 */
		0x18,0x60,0x3C,0x70,0x26,0x10,0x22,0x10,0x23,0x10,0x39,0xF0,0x18,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  T[0x0054]    8x16 */
		0x00,0x00,0x38,0x00,0x30,0x10,0x3F,0xF0,0x3F,0xF0,0x30,0x10,0x38,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  U[0x0055]    8x16 */
		0x3F,0xE0,0x3F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x3F,0xF0,0x3F,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  V[0x0056]    8x16 */
		0x3F,0x80,0x3F,0xC0,0x00,0x60,0x00,0x30,0x00,0x60,0x3F,0xC0,0x3F,0x80,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  W[0x0057]    8x16 */
		0x3F,0xC0,0x3F,0xF0,0x00,0x70,0x01,0xC0,0x00,0x70,0x3F,0xF0,0x3F,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  X[0x0058]    8x16 */
		0x30,0x30,0x3C,0xF0,0x0F,0xC0,0x03,0x00,0x0F,0xC0,0x3C,0xF0,0x30,0x30,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  Y[0x0059]    8x16 */
		0x00,0x00,0x3C,0x00,0x3E,0x10,0x03,0xF0,0x03,0xF0,0x3E,0x10,0x3C,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  Z[0x005A]    8x16 */
		0x38,0x70,0x30,0xF0,0x21,0x90,0x23,0x10,0x26,0x10,0x3C,0x30,0x38,0x70,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  [[0x005B]    8x16 */
		0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x20,0x10,0x20,0x10,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  \[0x005C]    8x16 */
		0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ][0x005D]    8x16 */
		0x00,0x00,0x00,0x00,0x20,0x10,0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ^[0x005E]    8x16 */
		0x10,0x00,0x30,0x00,0x60,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x10,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  _[0x005F]    8x16 */
		0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,
		/* ASCII 8x16点阵字库*/
		/*  `[0x0060]    8x16 */
		0x00,0x00,0x00,0x00,0xC0,0x00,0xE0,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  a[0x0061]    8x16 */
		0x00,0xE0,0x05,0xF0,0x05,0x10,0x05,0x10,0x07,0xE0,0x03,0xF0,0x00,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  b[0x0062]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xE0,0x04,0x10,0x06,0x10,0x03,0xF0,0x01,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  c[0x0063]    8x16 */
		0x03,0xE0,0x07,0xF0,0x04,0x10,0x04,0x10,0x04,0x10,0x06,0x30,0x02,0x20,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  d[0x0064]    8x16 */
		0x01,0xE0,0x03,0xF0,0x06,0x10,0x24,0x10,0x3F,0xE0,0x3F,0xF0,0x00,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  e[0x0065]    8x16 */
		0x03,0xE0,0x07,0xF0,0x05,0x10,0x05,0x10,0x05,0x10,0x07,0x30,0x03,0x20,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  f[0x0066]    8x16 */
		0x02,0x10,0x1F,0xF0,0x3F,0xF0,0x22,0x10,0x30,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  g[0x0067]    8x16 */
		0x03,0xE4,0x07,0xF6,0x04,0x12,0x04,0x12,0x03,0xFE,0x07,0xFC,0x04,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  h[0x0068]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x02,0x00,0x04,0x00,0x07,0xF0,0x03,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  i[0x0069]    8x16 */
		0x00,0x00,0x00,0x00,0x04,0x10,0x37,0xF0,0x37,0xF0,0x00,0x10,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  j[0x006A]    8x16 */
		0x00,0x00,0x00,0x0C,0x00,0x0E,0x00,0x02,0x04,0x02,0x37,0xFE,0x37,0xFC,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  k[0x006B]    8x16 */
		0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x01,0x80,0x03,0xC0,0x06,0x70,0x04,0x30,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  l[0x006C]    8x16 */
		0x00,0x00,0x00,0x00,0x20,0x10,0x3F,0xF0,0x3F,0xF0,0x00,0x10,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  m[0x006D]    8x16 */
		0x07,0xF0,0x07,0xF0,0x06,0x00,0x03,0xF0,0x06,0x00,0x07,0xF0,0x03,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  n[0x006E]    8x16 */
		0x04,0x00,0x07,0xF0,0x03,0xF0,0x04,0x00,0x04,0x00,0x07,0xF0,0x03,0xF0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  o[0x006F]    8x16 */
		0x03,0xE0,0x07,0xF0,0x04,0x10,0x04,0x10,0x04,0x10,0x07,0xF0,0x03,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  p[0x0070]    8x16 */
		0x04,0x02,0x07,0xFE,0x03,0xFE,0x04,0x12,0x04,0x10,0x07,0xF0,0x03,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  q[0x0071]    8x16 */
		0x03,0xE0,0x07,0xF0,0x04,0x10,0x04,0x12,0x03,0xFE,0x07,0xFE,0x04,0x02,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  r[0x0072]    8x16 */
		0x04,0x10,0x07,0xF0,0x03,0xF0,0x06,0x10,0x04,0x00,0x06,0x00,0x03,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  s[0x0073]    8x16 */
		0x02,0x20,0x07,0x30,0x05,0x90,0x04,0x90,0x04,0xD0,0x06,0x70,0x02,0x20,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  t[0x0074]    8x16 */
		0x04,0x00,0x04,0x00,0x1F,0xE0,0x3F,0xF0,0x04,0x10,0x04,0x30,0x00,0x20,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  u[0x0075]    8x16 */
		0x07,0xE0,0x07,0xF0,0x00,0x10,0x00,0x10,0x07,0xE0,0x07,0xF0,0x00,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  v[0x0076]    8x16 */
		0x00,0x00,0x07,0xC0,0x07,0xE0,0x00,0x30,0x00,0x30,0x07,0xE0,0x07,0xC0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  w[0x0077]    8x16 */
		0x07,0xE0,0x07,0xF0,0x00,0x30,0x00,0xE0,0x00,0x30,0x07,0xF0,0x07,0xE0,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  x[0x0078]    8x16 */
		0x04,0x10,0x06,0x30,0x03,0xE0,0x01,0xC0,0x03,0xE0,0x06,0x30,0x04,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  y[0x0079]    8x16 */
		0x07,0xE2,0x07,0xF2,0x00,0x12,0x00,0x12,0x00,0x16,0x07,0xFC,0x07,0xF8,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  z[0x007A]    8x16 */
		0x06,0x30,0x06,0x70,0x04,0xD0,0x05,0x90,0x07,0x10,0x06,0x30,0x04,0x30,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  {[0x007B]    8x16 */
		0x00,0x00,0x02,0x00,0x02,0x00,0x1F,0xE0,0x3D,0xF0,0x20,0x10,0x20,0x10,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  |[0x007C]    8x16 */
		0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xF0,0x3D,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  }[0x007D]    8x16 */
		0x00,0x00,0x20,0x10,0x20,0x10,0x3D,0xF0,0x1F,0xE0,0x02,0x00,0x02,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  ~[0x007E]    8x16 */
		0x10,0x00,0x30,0x00,0x20,0x00,0x30,0x00,0x10,0x00,0x30,0x00,0x20,0x00,0x00,0x00,
		/* ASCII 8x16点阵字库*/
		/*  [0x007F]    8x16 */
		0x01,0xE0,0x03,0xE0,0x06,0x20,0x0C,0x20,0x06,0x20,0x03,0xE0,0x01,0xE0,0x00,0x00,

};

oledFont SongFont_ASCII_8x16 = {.width = 8, .height = 16, .data = _songfont_asciii_8x16};





