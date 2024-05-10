
#include "labs/lab4.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"

void Lab4::init() {
  count = 0;
  HAL_TIM_Base_Start_IT(&htim3);
  write_number_to_led(count);
}

void Lab4::run() {
  write_number_to_led(count);
}

void Lab4::clean_effect() {
  HAL_TIM_Base_Stop_IT(&htim3);
  write_number_to_led(0xffff);
}

void Lab4::tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == htim3.Instance) {
    ++count;
    write_number_to_led(count);
  }
}
