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
  u32 adc_values[10];
  auto hadc = hadc1;
  for (int i = 0; i < 10; ++i) {
    HAL_ADC_Start(&hadc);
    if (HAL_ADC_PollForConversion(&hadc, 1000000) == HAL_OK) {
      adc_values[i] = HAL_ADC_GetValue(&hadc);
    }
    HAL_ADC_Stop(&hadc);
    HAL_Delay(10);
  }
  std::sort(adc_values, adc_values + 10);
  int sum = 0;
  for (int i = 2; i < 8; ++i) {
    sum += adc_values[i];
  }
  write_number_to_led(sum / 6);
  printf("%d\r\n", sum / 6);
  HAL_Delay(100);
}

void Lab7::clean_effect() {
}
