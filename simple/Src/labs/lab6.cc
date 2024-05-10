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
  u32 temp_values[10];
  auto hadc = hadc1;
  for (int i = 0; i < 10; ++i) {
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, 10);
    auto ad_value = HAL_ADC_GetValue(&hadc);
    auto vol_value = ad_value * (3.3 / 4096);
    double temp = (1.43 - vol_value) / 0.0043 + 25;
    temp_values[i] = ad_value;
    HAL_ADC_Stop(&hadc);
    HAL_Delay(10);
  }
  std::sort(temp_values, temp_values + 10);
  double sum = 0;
  for (int i = 2; i < 8; ++i) {
    sum += temp_values[i];
  }
  double avg = sum / 6;
  write_number_to_led((int)avg);
  printf("%d", (int)avg);
  HAL_Delay(100);
}

void Lab6::clean_effect() {
}
