/*
 * oled_spi.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef OLED_SPI__H_
#define OLED_SPI__H_

#include "oled_includes_.h"

#define SSD1306_RST_PORT				GPIOA
#define SSD1306_RST_PIN					GPIO_PIN_8
#define SSD1306_DC_PORT					GPIOB
#define SSD1306_DC_PIN					GPIO_PIN_14
#define SSD1306_CS_PORT					GPIOB
#define SSD1306_CS_PIN					GPIO_PIN_12
#define SSD1306_MOSI_PORT				GPIOB
#define SSD1306_MOSI_PIN				GPIO_PIN_15
#define SSD1306_SCK_PORT				GPIOB
#define SSD1306_SCK_PIN					GPIO_PIN_13

#define SSD1306_SELETE()				HAL_GPIO_WritePin(SSD1306_CS_PORT, SSD1306_CS_PIN, GPIO_PIN_RESET)
#define SSD1306_NOSELETE()			HAL_GPIO_WritePin(SSD1306_CS_PORT, SSD1306_CS_PIN, GPIO_PIN_SET)
#define SSD1306_MODE_COMMAND()	HAL_GPIO_WritePin(SSD1306_DC_PORT, SSD1306_DC_PIN, GPIO_PIN_RESET)
#define SSD1306_MODE_DATA()			HAL_GPIO_WritePin(SSD1306_DC_PORT, SSD1306_DC_PIN, GPIO_PIN_SET)

#define SSD1306_RST_SET()				HAL_GPIO_WritePin(SSD1306_RST_PORT, SSD1306_RST_PIN, GPIO_PIN_SET)
#define SSD1306_RST_RESET()			HAL_GPIO_WritePin(SSD1306_RST_PORT, SSD1306_RST_PIN, GPIO_PIN_RESET)


void SPIInit(void);
void SPIWrite(uint8_t chr);
void SPIWriteBuffer(uint8_t* buffer, uint16_t Size);

#endif /* NEW_OLED_SPI__H_ */
