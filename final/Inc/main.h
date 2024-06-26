/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define SE_PWM_Pin GPIO_PIN_6
#define SE_PWM_GPIO_Port GPIOA
#define IKEY0_Pin GPIO_PIN_0
#define IKEY0_GPIO_Port GPIOG
#define IKEY0_EXTI_IRQn EXTI0_IRQn
#define IKEY1_Pin GPIO_PIN_1
#define IKEY1_GPIO_Port GPIOG
#define IKEY1_EXTI_IRQn EXTI1_IRQn
#define IKEY2_Pin GPIO_PIN_2
#define IKEY2_GPIO_Port GPIOG
#define IKEY2_EXTI_IRQn EXTI2_IRQn
#define IKEY3_Pin GPIO_PIN_3
#define IKEY3_GPIO_Port GPIOG
#define IKEY3_EXTI_IRQn EXTI3_IRQn
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOG
#define LCD_SID_Pin GPIO_PIN_5
#define LCD_SID_GPIO_Port GPIOG
#define LCD_SCLK_Pin GPIO_PIN_6
#define LCD_SCLK_GPIO_Port GPIOG
#define DM_PWMA_Pin GPIO_PIN_15
#define DM_PWMA_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
