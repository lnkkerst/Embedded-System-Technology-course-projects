#pragma once

#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

void cpp_main();

void cpp_start_task_traffic_lights();

void cpp_start_task_running_lights();
#ifdef __cplusplus
}
#endif