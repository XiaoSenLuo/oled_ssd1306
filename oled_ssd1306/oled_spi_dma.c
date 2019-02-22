/*
 * oled_spi_dma.c
 *
 *  Created on: 2019年2月15日
 *      Author: XIAOSENLUO
 */



#include "oled_spi_dma.h"



/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/
#if(SPI_TRANSMIT == 1)
/* USER CODE BEGIN 1 */
DMA_HandleTypeDef hdma_spi2_tx;
DMA_HandleTypeDef hdma_spi2_rx;

/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void SPI2_DMAInit(SPI_HandleTypeDef* spiHandle){
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  /* SPI1 DMA Init */
  /* SPI1_TX Init */
  hdma_spi2_tx.Instance = DMA1_Channel5;
  hdma_spi2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
  hdma_spi2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_spi2_tx.Init.MemInc = DMA_MINC_ENABLE;
  hdma_spi2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  hdma_spi2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
  hdma_spi2_tx.Init.Mode = DMA_NORMAL;
  hdma_spi2_tx.Init.Priority = DMA_PRIORITY_LOW;
  if (HAL_DMA_Init(&hdma_spi2_tx) != HAL_OK){
//    _Error_Handler(__FILE__, __LINE__);
  }
  __HAL_LINKDMA(spiHandle, hdmatx, hdma_spi2_tx);

  /* SPI1_RX Init */
  hdma_spi2_rx.Instance = DMA1_Channel4;
  hdma_spi2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
  hdma_spi2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_spi2_rx.Init.MemInc = DMA_MINC_ENABLE;
  hdma_spi2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  hdma_spi2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
  hdma_spi2_rx.Init.Mode = DMA_NORMAL;
  hdma_spi2_rx.Init.Priority = DMA_PRIORITY_LOW;
  if (HAL_DMA_Init(&hdma_spi2_rx) != HAL_OK){
//    _Error_Handler(__FILE__, __LINE__);
  }
  __HAL_LINKDMA(spiHandle, hdmarx, hdma_spi2_rx);
  /* DMA interrupt init */

  /* DMA1_Channel2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

//  /*	注册传输完成回调函数 	*/
//  HAL_DMA_RegisterCallback(&hdma_spi2_tx, HAL_DMA_XFER_CPLT_CB_ID, SPI_DMAXferCpltCallback);
//  HAL_DMA_RegisterCallback(&hdma_spi2_rx, HAL_DMA_XFER_CPLT_CB_ID, SPI_DMAXferCpltCallback);
//  /*	注册传输完成一半回调函数	*/
//  HAL_DMA_RegisterCallback(&hdma_spi2_tx, HAL_DMA_XFER_HALFCPLT_CB_ID, SPI_DMAXferHalfCpltCallback);
//  HAL_DMA_RegisterCallback(&hdma_spi2_rx, HAL_DMA_XFER_HALFCPLT_CB_ID, SPI_DMAXferHalfCpltCallback);
//  /*	注册传输错误回调函数	*/
//  HAL_DMA_RegisterCallback(&hdma_spi2_tx, HAL_DMA_XFER_ERROR_CB_ID, SPI_DMAXferErrorCallback);
//  HAL_DMA_RegisterCallback(&hdma_spi2_rx, HAL_DMA_XFER_ERROR_CB_ID, SPI_DMAXferErrorCallback);

}

/* USER CODE BEGIN 2 */
/**
* @brief This function handles DMA1 channel2 global interrupt.
*/
void DMA1_Channel4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_IRQn 0 */

  /* USER CODE END DMA1_Channel2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_spi2_rx);
  /* USER CODE BEGIN DMA1_Channel2_IRQn 1 */

  /* USER CODE END DMA1_Channel2_IRQn 1 */
}

/**
* @brief This function handles DMA1 channel3 global interrupt.
*/
void DMA1_Channel5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel3_IRQn 0 */

  /* USER CODE END DMA1_Channel3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_spi2_tx);
  /* USER CODE BEGIN DMA1_Channel3_IRQn 1 */

  /* USER CODE END DMA1_Channel3_IRQn 1 */
}

/*	回调函数定义	*/
void SPI_DMAXferCpltCallback(DMA_HandleTypeDef *hdma){
	if(hdma->Instance == DMA1_Channel5){

	}else if(hdma->Instance == DMA1_Channel4){

	}
}
void SPI_DMAXferHalfCpltCallback(DMA_HandleTypeDef *hdma){
	if(hdma->Instance == DMA1_Channel5){

	}else if(hdma->Instance == DMA1_Channel4){

	}
}
void SPI_DMAXferErrorCallback(DMA_HandleTypeDef *hdma){
	if(hdma->Instance == DMA1_Channel5){

	}else if(hdma->Instance == DMA1_Channel4){

	}
}
/* USER CODE END 2 */
#endif


