#include "utils.hh"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <cstdint>

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(GPIO_LED, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIO_LED, number, GPIO_PIN_RESET);
  // send_number_to_uart(number);
}

void soft_delay(uint32_t count) {
  while (count--) {
  }
}

int btn_debounce(GPIO_TypeDef *GPIOx, uint16_t pin) {
  soft_delay(65535);
  if (HAL_GPIO_ReadPin(GPIOx, pin) != GPIO_PIN_RESET) {
    return false;
  }
  return true;
}
