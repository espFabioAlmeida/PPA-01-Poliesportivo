/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_COM_Pin GPIO_PIN_0
#define LED_COM_GPIO_Port GPIOA
#define OUT1_Pin GPIO_PIN_4
#define OUT1_GPIO_Port GPIOA
#define OUT2_Pin GPIO_PIN_5
#define OUT2_GPIO_Port GPIOA
#define OUT3_Pin GPIO_PIN_6
#define OUT3_GPIO_Port GPIOA
#define OUT4_Pin GPIO_PIN_7
#define OUT4_GPIO_Port GPIOA
#define OUT5_Pin GPIO_PIN_4
#define OUT5_GPIO_Port GPIOC
#define OUT6_Pin GPIO_PIN_5
#define OUT6_GPIO_Port GPIOC
#define OUT7_Pin GPIO_PIN_0
#define OUT7_GPIO_Port GPIOB
#define LED_CLOCK_Pin GPIO_PIN_1
#define LED_CLOCK_GPIO_Port GPIOB
#define LED_EQUIPEA_Pin GPIO_PIN_2
#define LED_EQUIPEA_GPIO_Port GPIOB
#define LED_EQUIPEB_Pin GPIO_PIN_10
#define LED_EQUIPEB_GPIO_Port GPIOB
#define OUT_PNP_Pin GPIO_PIN_11
#define OUT_PNP_GPIO_Port GPIOB
#define DISPLAY3_ST_Pin GPIO_PIN_12
#define DISPLAY3_ST_GPIO_Port GPIOB
#define DISPLAY3_ENABLE_Pin GPIO_PIN_13
#define DISPLAY3_ENABLE_GPIO_Port GPIOB
#define DISPLAY3_DATA_Pin GPIO_PIN_14
#define DISPLAY3_DATA_GPIO_Port GPIOB
#define DISPLAY3_CLOCK_Pin GPIO_PIN_15
#define DISPLAY3_CLOCK_GPIO_Port GPIOB
#define DISPLAY2_ST_Pin GPIO_PIN_6
#define DISPLAY2_ST_GPIO_Port GPIOC
#define DISPLAY2_ENABLE_Pin GPIO_PIN_7
#define DISPLAY2_ENABLE_GPIO_Port GPIOC
#define DISPLAY2_DATA_Pin GPIO_PIN_8
#define DISPLAY2_DATA_GPIO_Port GPIOC
#define DISPLAY2_CLOCK_Pin GPIO_PIN_9
#define DISPLAY2_CLOCK_GPIO_Port GPIOC
#define DISPLAY1_ST_Pin GPIO_PIN_8
#define DISPLAY1_ST_GPIO_Port GPIOA
#define DISPLAY1_ENABLE_Pin GPIO_PIN_9
#define DISPLAY1_ENABLE_GPIO_Port GPIOA
#define DISPLAY1_DATA_Pin GPIO_PIN_10
#define DISPLAY1_DATA_GPIO_Port GPIOA
#define DISPLAY1_CLOCK_Pin GPIO_PIN_11
#define DISPLAY1_CLOCK_GPIO_Port GPIOA
#define LED_CPU_Pin GPIO_PIN_12
#define LED_CPU_GPIO_Port GPIOA
#define IN1_Pin GPIO_PIN_15
#define IN1_GPIO_Port GPIOA
#define IN2_Pin GPIO_PIN_10
#define IN2_GPIO_Port GPIOC
#define IN3_Pin GPIO_PIN_11
#define IN3_GPIO_Port GPIOC
#define IN4_Pin GPIO_PIN_12
#define IN4_GPIO_Port GPIOC
#define IN5_Pin GPIO_PIN_2
#define IN5_GPIO_Port GPIOD
#define SIRENE_Pin GPIO_PIN_4
#define SIRENE_GPIO_Port GPIOB
#define RELE_Pin GPIO_PIN_5
#define RELE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
