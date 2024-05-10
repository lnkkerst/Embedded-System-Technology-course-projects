#include "labs/lab5.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"
#include <stdio.h>

void Lab5::init() {
  count = 0;
  HAL_TIM_Base_Start_IT(&htim3);
  write_number_to_led(count);
}

void Lab5::run() {
  write_number_to_led(count);
}

void Lab5::clean_effect() {
  HAL_TIM_Base_Stop_IT(&htim3);
  write_number_to_led(0xffff);
}

void Lab5::tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == htim3.Instance) {
    ++count;
    printf("%d \r\n", count);
  }
}
