#include "labs/lab1.hh"
#include "main.h"
#include "stm32f1xx_hal_gpio.h"
#include "utils.hh"

void Lab1::init() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
}

void Lab1::run() {
  ++current_led;
  if (current_led >= TOTAL_LED) {
    current_led = 0;
  }
  HAL_GPIO_TogglePin(LED0_GPIO_Port, 1 << current_led);
  soft_delay(655350);
}

void Lab1::clean_effect() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
}
