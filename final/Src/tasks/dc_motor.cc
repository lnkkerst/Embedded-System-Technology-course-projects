#include <cmath>

#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "gpio.h"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"

int speed = 50;

void set_pwm(int moto) {
  int pwm_abs = abs(moto);
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pwm_abs);
}

void cpp_start_task_dc_motor() {
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  set_pwm(speed);
  while (true) {
    osDelay(100);
  }
}

void dc_motor_btn_callback() {
  if (!btn_debounce(IKEY0_GPIO_Port, IKEY0_Pin)) {
    return;
  }
  speed = (speed + 100) % 1000;
  set_pwm(speed);
}
