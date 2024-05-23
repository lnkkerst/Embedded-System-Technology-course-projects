#include "labs/lab10.hh"
#include "adc.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"
#include <cstdio>

void Lab10::init() {
  count = 0;
  mode = 0;
  HAL_TIM_Base_Start_IT(&htim3);
  write_number_to_led(count);
}

void Lab10::run() {
  if (mode == 0) {
  } else {
    double ad_value = get_adc_by_average(&hadc2);
    double vol_value = ad_value * (3.3 / 4096);
    printf("Voltage: %.6lf\r\n", vol_value);
  }
}

void Lab10::clean_effect() {
  HAL_TIM_Base_Stop_IT(&htim3);
  write_number_to_led(0xffff);
}

void Lab10::tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == htim3.Instance) {
    ++count;
    if (mode == 0) {
      printf("Count: %d\r\n", count);
    }
  }
}

void Lab10::wkup_btn_short_click_callback() {
  mode = !mode;
}
