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
#include "data_update_queue.h"
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
/* Definitions for default_task */
osThreadId_t default_taskHandle;
const osThreadAttr_t default_task_attributes = {
    .name = "default_task",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow,
};
/* Definitions for running_lights */
osThreadId_t running_lightsHandle;
const osThreadAttr_t running_lights_attributes = {
    .name = "running_lights",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow2,
};
/* Definitions for traffic_lights */
osThreadId_t traffic_lightsHandle;
const osThreadAttr_t traffic_lights_attributes = {
    .name = "traffic_lights",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow2,
};
/* Definitions for dc_motor */
osThreadId_t dc_motorHandle;
const osThreadAttr_t dc_motor_attributes = {
    .name = "dc_motor",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow3,
};
/* Definitions for steering_engine */
osThreadId_t steering_engineHandle;
const osThreadAttr_t steering_engine_attributes = {
    .name = "steering_engine",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow5,
};
/* Definitions for lcd12864 */
osThreadId_t lcd12864Handle;
const osThreadAttr_t lcd12864_attributes = {
    .name = "lcd12864",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityLow6,
};
/* Definitions for DataUpdateQueue */
osMessageQueueId_t DataUpdateQueueHandle;
const osMessageQueueAttr_t DataUpdateQueue_attributes = {.name =
                                                             "DataUpdateQueue"};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void start_task_default_task(void *argument);
void start_task_running_lights(void *argument);
void start_task_traffic_lights(void *argument);
void start_task_dc_motor(void *argument);
extern void start_task_steering_engine(void *argument);
extern void start_task_lcd(void *argument);

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

  /* Create the queue(s) */
  /* creation of DataUpdateQueue */
  DataUpdateQueueHandle = osMessageQueueNew(16, sizeof(DataUpdateQueueItem),
                                            &DataUpdateQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of default_task */
  default_taskHandle =
      osThreadNew(start_task_default_task, NULL, &default_task_attributes);

  /* creation of running_lights */
  running_lightsHandle =
      osThreadNew(start_task_running_lights, NULL, &running_lights_attributes);

  /* creation of traffic_lights */
  traffic_lightsHandle =
      osThreadNew(start_task_traffic_lights, NULL, &traffic_lights_attributes);

  /* creation of dc_motor */
  dc_motorHandle = osThreadNew(start_task_dc_motor, NULL, &dc_motor_attributes);

  /* creation of steering_engine */
  steering_engineHandle = osThreadNew(start_task_steering_engine, NULL,
                                      &steering_engine_attributes);

  /* creation of lcd12864 */
  lcd12864Handle = osThreadNew(start_task_lcd, NULL, &lcd12864_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_start_task_default_task */
/**
 * @brief  Function implementing the default_task thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_task_default_task */
void start_task_default_task(void *argument) {
  /* USER CODE BEGIN start_task_default_task */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END start_task_default_task */
}

/* USER CODE BEGIN Header_start_task_running_lights */
/**
 * @brief Function implementing the running_lights thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_task_running_lights */
__weak void start_task_running_lights(void *argument) {
  /* USER CODE BEGIN start_task_running_lights */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END start_task_running_lights */
}

/* USER CODE BEGIN Header_start_task_traffic_lights */
/**
 * @brief  Function implementing the traffic_lights thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_task_traffic_lights */
__weak void start_task_traffic_lights(void *argument) {
  /* USER CODE BEGIN start_task_traffic_lights */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END start_task_traffic_lights */
}

/* USER CODE BEGIN Header_start_task_dc_motor */
/**
 * @brief Function implementing the dc_motor thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_start_task_dc_motor */
__weak void start_task_dc_motor(void *argument) {
  /* USER CODE BEGIN start_task_dc_motor */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END start_task_dc_motor */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
