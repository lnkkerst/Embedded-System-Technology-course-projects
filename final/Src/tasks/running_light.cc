#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "stm32f1xx_hal_gpio.h"

void cpp_start_task_running_lights() {
  // 储存小灯的状态
  int status = 0;
  while (true) {
    for (int i = 0; i < 8; ++i) {
      // 按位反转小灯状态
      status ^= (1 << i);

      // 先关闭相关 LED
      HAL_GPIO_WritePin(GPIOF, ~(status << 6) & 0b0011111111000000,
                        GPIO_PIN_SET);
      // 再打开需要的 LED
      HAL_GPIO_WritePin(GPIOF, (status << 6), GPIO_PIN_RESET);

      // 延时 500 ticks (1tick = 1ms)
      osDelay(500);
    }
  }
}
