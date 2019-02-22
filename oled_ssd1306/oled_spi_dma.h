/*
 * oled_spi_dma.h
 *
 *  Created on: 2019年2月15日
 *      Author: XIAOSENLUO
 */

#ifndef OLED_SPI_DMA_H_
#define OLED_SPI_DMA_H_


#include "oled_includes_.h"

#if(SPI_TRANSMIT == 1)

void SPI2_DMAInit(SPI_HandleTypeDef* spiHandle);


void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel5_IRQHandler(void);

/* USER CODE BEGIN Prototypes */
void SPI_DMAXferCpltCallback(DMA_HandleTypeDef *hdma);
void SPI_DMAXferHalfCpltCallback(DMA_HandleTypeDef *hdma);
void SPI_DMAXferErrorCallback(DMA_HandleTypeDef *hdma);

#endif

#endif /* OLED_SPI_DMA_H_ */
