#include <cmath>
#include <cstdint>

#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "gpio.h"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"

uint8_t degs[] = {0, 45, 90, 135, 180};
uint8_t deg = 90;
int step = 9;

void set_deg(uint8_t deg) {
  TIM3->CCR1 = deg / 9 + 5;
}

void cpp_start_task_steering_engine() {
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  set_deg(deg);
  while (true) {
    osDelay(1000);
  }
}

void steering_engine_btn_callback() {
  if (!btn_debounce(IKEY1_GPIO_Port, IKEY1_Pin)) {
    return;
  }
  deg += step;
  if (deg >= 150 || deg <= 30) {
    step = -step;
  }
  set_deg(deg);
}
