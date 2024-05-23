#include "labs/lab6.hh"
#include "adc.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "types.hh"
#include "utils.hh"
#include <algorithm>
#include <cstdio>

void Lab6::init() {
}

void Lab6::run() {
  auto ad_value = get_adc_by_average(&hadc2);
  double vol_value = ad_value * (3.3 / 4096);
  printf("AD Voltage: %.6f\r\n", vol_value);
  HAL_Delay(100);
}

void Lab6::clean_effect() {
}
