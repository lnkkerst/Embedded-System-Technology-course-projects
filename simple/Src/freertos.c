/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "main.h"
#include "task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cpp_start.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for lab11_task1 */
osThreadId_t lab11_task1Handle;
const osThreadAttr_t lab11_task1_attributes = {
    .name = "lab11_task1",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow,
};
/* Definitions for lab11_task2 */
osThreadId_t lab11_task2Handle;
const osThreadAttr_t lab11_task2_attributes = {
    .name = "lab11_task2",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow1,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void start_lab11_task1(void *argument);
void start_lab11_task2(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of lab11_task1 */
  lab11_task1Handle =
      osThreadNew(start_lab11_task1, NULL, &lab11_task1_attributes);

  /* creation of lab11_task2 */
  lab11_task2Handle =
      osThreadNew(start_lab11_task2, NULL, &lab11_task2_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_start_lab11_task1 */
/**
 * @brief Function implementing the lab11_task1 thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_lab11_task1 */
void start_lab11_task1(void *argument) {
  /* USER CODE BEGIN start_lab11_task1 */
  cpp_start_lab11_task1();
  /* USER CODE END start_lab11_task1 */
}

/* USER CODE BEGIN Header_start_lab11_task2 */
/**
 * @brief  Function implementing the lab11_task2 thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_lab11_task2 */
void start_lab11_task2(void *argument) {
  /* USER CODE BEGIN start_lab11_task2 */
  cpp_start_lab11_task2();
  /* USER CODE END start_lab11_task2 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
