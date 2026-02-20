/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : FMC.h
  * Description        : This file provides code for the configuration
  *                      of the FMC peripheral.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FMC_H
#define __FMC_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN Private defines */

#define SDRAM_TIMEOUT (0x0000FFFFUL)

typedef GPIO 		FMC_GPIO;
typedef FMC_GPIO 	FMC_ADDRESS;
typedef FMC_GPIO 	FMC_DATA;
typedef FMC_GPIO 	FMC_BE;
typedef FMC_GPIO 	FMC_BANK;
typedef FMC_GPIO 	FMC_CMD;

// ADDRESS PINS
#define FMC_A0 		((FMC_ADDRESS) 	{GPIO_PIN_0, GPIOF})
#define FMC_A1 		((FMC_ADDRESS) 	{GPIO_PIN_1, GPIOF})
#define FMC_A2 		((FMC_ADDRESS) 	{GPIO_PIN_2, GPIOF})
#define FMC_A3 		((FMC_ADDRESS) 	{GPIO_PIN_3, GPIOF})
#define FMC_A4 		((FMC_ADDRESS) 	{GPIO_PIN_4, GPIOF})
#define FMC_A5 		((FMC_ADDRESS) 	{GPIO_PIN_5, GPIOF})
#define FMC_A6 		((FMC_ADDRESS) 	{GPIO_PIN_12, GPIOF})
#define FMC_A7 		((FMC_ADDRESS)	{GPIO_PIN_13, GPIOF})
#define FMC_A8 		((FMC_ADDRESS) 	{GPIO_PIN_14, GPIOF})
#define FMC_A9 		((FMC_ADDRESS) 	{GPIO_PIN_15, GPIOF})
#define FMC_A10		((FMC_ADDRESS) 	{GPIO_PIN_0, GPIOG})
#define FMC_A11		((FMC_ADDRESS) 	{GPIO_PIN_1, GPIOG})

// DATA PINS
#define FMC_D0		((FMC_DATA) 	{GPIO_PIN_14, GPIOD})
#define FMC_D1		((FMC_DATA) 	{GPIO_PIN_15, GPIOD})
#define FMC_D2		((FMC_DATA) 	{GPIO_PIN_0, GPIOD})
#define FMC_D3		((FMC_DATA) 	{GPIO_PIN_1, GPIOD})
#define FMC_D4 		((FMC_DATA) 	{GPIO_PIN_7, GPIOE})
#define FMC_D5 		((FMC_DATA) 	{GPIO_PIN_8, GPIOE})
#define FMC_D6 		((FMC_DATA) 	{GPIO_PIN_9, GPIOE})
#define FMC_D7 		((FMC_DATA) 	{GPIO_PIN_10, GPIOE})
#define FMC_D8 		((FMC_DATA) 	{GPIO_PIN_11, GPIOE})
#define FMC_D9 		((FMC_DATA) 	{GPIO_PIN_12, GPIOE})
#define FMC_D10		((FMC_DATA) 	{GPIO_PIN_13, GPIOE})
#define FMC_D11		((FMC_DATA) 	{GPIO_PIN_14, GPIOE})
#define FMC_D12		((FMC_DATA) 	{GPIO_PIN_15, GPIOE})
#define FMC_D13		((FMC_DATA) 	{GPIO_PIN_8, GPIOD})
#define FMC_D14		((FMC_DATA) 	{GPIO_PIN_9, GPIOD})
#define FMC_D15		((FMC_DATA) 	{GPIO_PIN_10, GPIOD})

// BYTE ENABLE PINS
#define FMC_NBL0	((FMC_BE) 		{GPIO_PIN_0, GPIOE})
#define FMC_NBL1	((FMC_BE) 		{GPIO_PIN_1, GPIOE})

// BANK SELECT PINS
#define FMC_BA0		((FMC_BANK) 	{GPIO_PIN_4, GPIOG})
#define FMC_BA1		((FMC_BANK) 	{GPIO_PIN_5, GPIOG})

// COMMAND PINS
#define FMC_SDCLK	((FMC_CMD) 		{GPIO_PIN_8, GPIOG})
#define FMC_SDNCAS 	((FMC_CMD) 		{GPIO_PIN_15, GPIOG})
#define FMC_SDNE0 	((FMC_CMD) 		{GPIO_PIN_2, GPIOC})
#define FMC_SDCKE0 	((FMC_CMD) 		{GPIO_PIN_3, GPIOC})
#define FMC_SDNWE 	((FMC_CMD) 		{GPIO_PIN_5, GPIOH})
#define FMC_SDNRAS	((FMC_CMD) 		{GPIO_PIN_11, GPIOF})

// #define FMC_ 		((GPIO) {GPIO_PIN_x, GPIOx})
#define SYSCLK_HZ					(180000000) // Hz // Needs to be set manually because the HAL_RCC_GetSysClockFreq() is unreliable
#define SDRAM_CLK_HZ 				(SYSCLK_HZ / 2)
#define SDRAM_CLK_MHZ				(SDRAM_CLK_HZ / 1000000)
#define SDRAM_CLK_PERIOD_NS 		(1000000000UL / (SDRAM_CLK_HZ / 1000)) // LOSES SOME RESOLUTION, BUT ITS NEEDED TO FIT WITHIN 32-BITS
#define NS_TO_SDRAM_CLK_CYCLES(NS) 	((NS * 1000) / (SDRAM_CLK_PERIOD_NS) + 1)

// All of these can be found in the datasheet of the Ram chip
#define tRCD 							( 15 )
#define tRP 							( 15 )
#define tWR 							( 22 ) // only specifies two clock cycles
#define tRC 							( 63 )
#define tRAS 							( 42 )
#define tXSR 							( 70 )
#define tMRD 							( 22 ) // only specifies two clock cycles

// Specific names from the FMC
#define ROW_TO_COLUMN_DELAY_NS 			( tRCD )
#define ROW_PRECHARGE_DELAY_NS 			( tRP  )
#define RECOVERY_DELAY_NS 				( tWR  )
#define ROW_CYCLE_DELAY_NS 				( tRC  )
#define SELF_REFRESH_TIME_NS 			( tRAS )
#define EXIT_SELF_REFRESH_DELAY_NS 		( tXSR )
#define LOAD_MODE_REGISTER_TO_ACTIVE_NS ( tMRD )

// Converted to Clock_Cycles
#define ROW_TO_COLUMN_DELAY 			( NS_TO_SDRAM_CLK_CYCLES( tRCD ) ) //(tRCD * 1000 + SDRAM_CLK_PERIOD_US) / (SDRAM_CLK_PERIOD_US)
#define ROW_PRECHARGE_DELAY 			( NS_TO_SDRAM_CLK_CYCLES( tRP  ) )
#define RECOVERY_DELAY 					( NS_TO_SDRAM_CLK_CYCLES( tWR  ) )
#define ROW_CYCLE_DELAY 				( NS_TO_SDRAM_CLK_CYCLES( tRC  ) )
#define SELF_REFRESH_TIME 				( NS_TO_SDRAM_CLK_CYCLES( tRAS ) )
#define EXIT_SELF_REFRESH_DELAY 		( NS_TO_SDRAM_CLK_CYCLES( tXSR ) )
#define LOAD_MODE_REGISTER_TO_ACTIVE 	( NS_TO_SDRAM_CLK_CYCLES( tMRD ) )

// Mode Register Definition
// // These can only be guaranteed to work with ISSI IS42S16400-series SDRAM
// // Burst Length
// // // Bit Definitions
#define LOAD_MODE_BURST_LENGTH_MASK		(0x007)
#define LOAD_MODE_BURST_LENGTH_POSITION	(0)
// // // Valid Burst Length Commands
#define LOAD_MODE_BURST_LENGTH_1		(0b000 << LOAD_MODE_BURST_LENGTH_POSITION)
#define LOAD_MODE_BURST_LENGTH_2		(0b001 << LOAD_MODE_BURST_LENGTH_POSITION)
#define LOAD_MODE_BURST_LENGTH_4		(0b010 << LOAD_MODE_BURST_LENGTH_POSITION)
#define LOAD_MODE_BURST_LENGTH_8		(0b011 << LOAD_MODE_BURST_LENGTH_POSITION)
#define LOAD_MODE_BURST_LENGTH_PAGE		(0b111 << LOAD_MODE_BURST_LENGTH_POSITION) // Only Works with

// // Burst Type
// // // Bit Definitions
#define LOAD_MODE_BURST_TYPE_MASK			(0x008)
#define LOAD_MODE_BURST_TYPE_POSITION		(3)
// // // Valid Burst Type Commands
#define LOAD_MODE_BURST_TYPE_SEQUENTIAL		(0x000)
#define LOAD_MODE_BURST_TYPE_INTERLEAVE 	(LOAD_MODE_BURST_TYPE_MASK)

// // Latency Mode (CAS LATENCY)
// // // Bit Definitions
#define LOAD_MODE_LATENCY_MODE_MASK			(0x070)
#define LOAD_MODE_LATENCY_MODE_POSITION		(4)
// // // Valid Latency Mode Commands
#define LOAD_MODE_LATENCY_MODE_2			(0b010 << LOAD_MODE_LATENCY_MODE_POSITION)
#define LOAD_MODE_LATENCY_MODE_3			(0b011 << LOAD_MODE_LATENCY_MODE_POSITION)

// //  Operating Mode
// // // Bit Definitions
#define LOAD_MODE_OPERATING_MODE_MASK		(0x180)
#define LOAD_MODE_OPERATING_MODE_POSITION	(7)
// // // Valid Operating Mode Commands
#define LOAD_MODE_OPERATING_MODE_STANDARD	(0b00 << LOAD_MODE_OPERATING_MODE_POSITION)

// // Write Burst Mode
// // // Bit Definitions
#define LOAD_MODE_WRITE_BURST_MODE_MASK			(0x200)
#define LOAD_MODE_WRITE_BURST_MODE_POSITION		(9)
// // // Valid Write Burst Mode Commands
#define LOAD_MODE_WRITE_BURST_MODE_PROGRAMMED	(0)
#define LOAD_MODE_WRITE_BURST_MODE_SINGLE		(LOAD_MODE_WRITE_BURST_MODE_MASK)

// // RESERVED

// Refresh Count
#define ROW_COUNT						(4096)		// Rows
#define REFRESH_TIME					(64)		// ms
#define REFRESH_TIME_PER_ROW			(REFRESH_TIME * 1000 / ROW_COUNT) // us
#define SDRAM_CLK_PER_REFRESH			((REFRESH_TIME_PER_ROW * SDRAM_CLK_MHZ) - 20) // Take 20 for a little cushioning (recommended by reference manual)

#define	RAM_SIZE_BITS					(0x4000000) // 64 Mb
#define RAM_SIZE_BYTES					(RAM_SIZE_BITS / 8) // 8 MB
#define STARTING_ADDR					((volatile uint32_t*)0xC000000)
// ROUNDS UP ONE CLOCK CYCLE AND WILL ALWAYS GIVE AT LEAST

typedef struct {
	void* addr;
	uint32_t size;
} fmc;
/* USER CODE END Private defines */

void MX_FMC_Init(void);
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram);
void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__FMC_H */

/**
  * @}
  */

/**
  * @}
  */
