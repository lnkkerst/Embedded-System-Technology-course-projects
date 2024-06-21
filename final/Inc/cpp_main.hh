#pragma once

#include "cmsis_os2.h"
#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

extern osMessageQueueId_t DataUpdateQueueHandle;

void cpp_main();

void cpp_start_task_traffic_lights();

void cpp_start_task_running_lights();

void cpp_start_task_dc_motor();

void cpp_start_task_steering_engine();

void cpp_start_task_lcd();

void cpp_start_task_adc_pot();

void cpp_start_task_adc_temp();

#ifdef __cplusplus
}
#endif

void dc_motor_btn_callback();

void steering_engine_btn_callback();
