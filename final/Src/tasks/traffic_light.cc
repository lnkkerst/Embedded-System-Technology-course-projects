
#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "utils.hh"

void cpp_start_task_traffic_lights() {
  int status[][2] = {
      {0b100001, 5000},
      {0b010010, 1000},
      {0b001100, 5000},
      {0b010010, 1000},
  };
  while (true) {
    for (int i = 0; i < 4; ++i) {
      HAL_GPIO_WritePin(GPIOF, ~status[i][0] & 0b0000000000111111,
                        GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOF, status[i][0], GPIO_PIN_RESET);
      osDelay(status[i][1]);
    }
  }
}
