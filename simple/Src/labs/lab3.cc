#include "labs/lab3.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

void Lab3::init() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
}

void Lab3::run() {
  if (HAL_GPIO_ReadPin(BTN_WKUP_GPIO_Port, BTN_WKUP_Pin) != GPIO_PIN_RESET) {
    return;
  }
  ++count;
  HAL_GPIO_WritePin(LED0_GPIO_Port, ~count, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED0_GPIO_Port, count, GPIO_PIN_RESET);
  while (HAL_GPIO_ReadPin(BTN_WKUP_GPIO_Port, BTN_WKUP_Pin) == GPIO_PIN_RESET) {
    HAL_Delay(100);
  }
}

void Lab3::clean_effect() {
}
