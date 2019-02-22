/*
 * oled_spi.c
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#include "oled_spi_.h"
#include "stdbool.h"

#if(SPI_TRANSMIT == 1)
#include "oled_spi_dma.h"
__IO bool isDMAClpt = false;
#endif

SPI_HandleTypeDef hspi2;

#ifndef OLED_HSPI
#define OLED_HSPI hspi2
#endif


static void SPI2_MspInit(SPI_HandleTypeDef* spiHandle);

void SPIInit(void){
	OLED_HSPI.Instance = SPI2;
	OLED_HSPI.Init.Mode = SPI_MODE_MASTER;
	OLED_HSPI.Init.Direction = SPI_DIRECTION_1LINE;
	OLED_HSPI.Init.DataSize = SPI_DATASIZE_8BIT;
	OLED_HSPI.Init.CLKPolarity = SPI_POLARITY_LOW;
	OLED_HSPI.Init.CLKPhase = SPI_PHASE_1EDGE;
	OLED_HSPI.Init.NSS = SPI_NSS_SOFT;
	OLED_HSPI.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	OLED_HSPI.Init.FirstBit = SPI_FIRSTBIT_MSB;
	OLED_HSPI.Init.TIMode = SPI_TIMODE_DISABLE;
	OLED_HSPI.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	OLED_HSPI.Init.CRCPolynomial = 7;
	SPI2_MspInit(&hspi2);	//MspInit()必须在HAL_SPI_Init()前调用
  if (HAL_SPI_Init(&OLED_HSPI) != HAL_OK){
//    _Error_Handler(__FILE__, __LINE__);
  }

  __HAL_SPI_ENABLE(&OLED_HSPI);
}
void SPIWrite(uint8_t chr){

#if(SPI_TRANSMIT == 0)
	HAL_SPI_Transmit(&hspi2, &chr, 1, 1000);
#elif(SPI_TRANSMIT == 1)
	isDMAClpt = false;
	HAL_SPI_Transmit_DMA(&hspi2, &chr, 1);
	while(!isDMAClpt);
#endif
}
void SPIWriteBuffer(uint8_t *buffer, uint16_t Size){
#if(SPI_TRANSMIT == 0)
	HAL_SPI_Transmit(&hspi2, buffer, Size, 1000);
#elif(SPI_TRANSMIT == 1)
	isDMAClpt = false;
	HAL_SPI_Transmit_DMA(&hspi2, buffer, Size);
	while(!isDMAClpt);
#endif
}

static void SPI2_MspInit(SPI_HandleTypeDef* spiHandle){
  GPIO_InitTypeDef GPIO_InitStruct;
  if(spiHandle->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspInit 0 */

  /* USER CODE END SPI2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_SPI2_CLK_ENABLE();

    /**SPI2 GPIO Configuration
    PB13     ------> SPI2_SCK
    PB15     ------> SPI2_MOSI
    */
    GPIO_InitStruct.Pin = SSD1306_MOSI_PIN|SSD1306_SCK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI2_MspInit 1 */
#if(SPI_TRANSMIT == 1)
    SPI2_DMAInit(spiHandle);
#endif
  /* USER CODE END SPI2_MspInit 1 */
  }
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi){
#if(SPI_TRANSMIT == 0)

#elif(SPI_TRANSMIT == 1)
	isDMAClpt = true;
#endif
}
