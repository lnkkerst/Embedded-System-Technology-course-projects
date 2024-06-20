#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "stm32f1xx_hal_gpio.h"

void cpp_start_task_running_lights() {
  int status = 0;
  while (true) {
    for (int i = 0; i < 8; ++i) {
      status ^= (1 << i);
      HAL_GPIO_WritePin(GPIOF, ~(status << 6) & 0b0011111111000000,
                        GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOF, (status << 6), GPIO_PIN_RESET);
      osDelay(500);
    }
  }
}
