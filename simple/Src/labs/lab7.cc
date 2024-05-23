#include "labs/lab7.hh"
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

void Lab7::init() {
}

void Lab7::run() {
  auto ad_value = get_adc_by_average(&hadc1);
  double vol_value = ad_value * (3.3 / 4096);
  double temperature = (1.43 - vol_value) / 0.0043 + 25;
  printf("Temperature: %.6f\r\n", temperature);
  HAL_Delay(100);
}

void Lab7::clean_effect() {
}
