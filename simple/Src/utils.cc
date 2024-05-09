#include "utils.hh"

void soft_delay(u32 count) {
  while (count--) {
  }
}

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(LED0_GPIO_Port, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED0_GPIO_Port, number, GPIO_PIN_RESET);
}
