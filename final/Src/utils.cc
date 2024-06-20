#include "utils.hh"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(GPIO_LED, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIO_LED, number, GPIO_PIN_RESET);
  // send_number_to_uart(number);
}
