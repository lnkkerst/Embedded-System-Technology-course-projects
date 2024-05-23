#include "labs/lab9.hh"
#include "adc.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"
#include <cstdio>

void Lab9::init() {
  count = 0;
  mode = 0;
  HAL_TIM_Base_Start_IT(&htim3);
  write_number_to_led(count);
}

void Lab9::run() {
  if (mode == 0) {
    write_number_to_led(count);
  } else {
    double ad_value = get_adc_by_average(&hadc2);
    double vol_value = ad_value * (3.3 / 4096);
    write_number_to_led(int(vol_value * 1000));
  }
}

void Lab9::clean_effect() {
  HAL_TIM_Base_Stop_IT(&htim3);
  write_number_to_led(0xffff);
}

void Lab9::tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == htim3.Instance) {
    ++count;
  }
}

void Lab9::wkup_btn_short_click_callback() {
  mode = !mode;
}
