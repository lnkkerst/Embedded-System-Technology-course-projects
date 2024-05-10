#include "labs/lab2.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

void Lab2::init() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
  current_led = -1;
}

void Lab2::run() {
  ++current_led;
  if (current_led >= TOTAL_LED) {
    current_led = 0;
  }
  HAL_GPIO_TogglePin(LED0_GPIO_Port, 1 << current_led);
  HAL_Delay(1000);
}

void Lab2::clean_effect() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
}
