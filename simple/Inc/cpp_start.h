#pragma once

#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

int cpp_start();

void tim_period_elapsed_callback(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif
