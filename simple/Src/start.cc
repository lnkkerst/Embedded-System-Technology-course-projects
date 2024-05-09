#include "cpp_start.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

int cpp_start() {
  while (1) {
    for (int i = 0; i < 16; ++i) {
      HAL_GPIO_TogglePin(GPIOF, (1 << i));
      HAL_Delay(100);
    }
  }
}
