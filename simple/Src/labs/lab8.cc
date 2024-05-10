#include "labs/lab8.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"
#include <cstdio>

void Lab8::init() {
  count = 0;
  timer_count = 0;
  mode = 0;
  HAL_TIM_Base_Start_IT(&htim3);
  write_number_to_led(count);
}

void Lab8::run() {
}

void Lab8::clean_effect() {
  HAL_TIM_Base_Stop_IT(&htim3);
  write_number_to_led(0xffff);
}

void Lab8::tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == htim3.Instance) {
    ++timer_count;
    if (timer_count % 2 == 0) {
      ++count;
      timer_count = 0;
      out();
    }
  }
}

void Lab8::out() {
  if (mode == 0) {
    write_number_to_led(count);
  } else {
    printf("%d\r\n", count);
  }
}

void Lab8::wkup_btn_short_click_callback() {
  mode = !mode;
  out();
}
