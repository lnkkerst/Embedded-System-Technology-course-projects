#include "cpp_main.hh"
#include "gpio.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "utils.hh"

void cpp_main() {
}

extern "C" {
void HAL_GPIO_EXTI_Callback(uint16_t pin) {
  if (pin == IKEY0_Pin) {
    dc_motor_btn_callback();
  }
}
}
