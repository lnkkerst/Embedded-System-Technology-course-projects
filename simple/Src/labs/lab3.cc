#include "labs/lab3.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "utils.hh"

void Lab3::init() {
  HAL_GPIO_WritePin(LED0_GPIO_Port, 0xffff, GPIO_PIN_SET);
  count = 0;
}

void Lab3::run() {
  write_number_to_led(count);
}

void Lab3::clean_effect() {
}

void Lab3::wkup_btn_short_click_callback() {
  ++count;
}
