#include "cpp_start.h"
#include "labs.hh"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_gpio.h"
#include "types.hh"
#include "utils.hh"
#include <memory>

int lab_id = 1;
std::shared_ptr<Lab> lab;
int tot_labs = 3;

bool switch_lock = false;

void update_lab() {
  if (lab_id == 1) {
    lab = std::make_shared<Lab1>();
  } else if (lab_id == 2) {
    lab = std::make_shared<Lab2>();
  } else {
    lab = std::make_shared<Lab3>();
  }
}

int cpp_start() {
  update_lab();
  lab->init();
  while (true) {
    lab->run();
  }
}

extern "C" {
void HAL_GPIO_EXTI_Callback(uint16_t pin) {
  if (pin == BTN0_Pin) {
    soft_delay(65535);
    if (HAL_GPIO_ReadPin(BTN0_GPIO_Port, BTN0_Pin) != GPIO_PIN_RESET) {
      return;
    }

    if (switch_lock) {
      return;
    }

    switch_lock = true;

    lab->clean_effect();
    ++lab_id;
    if (lab_id > tot_labs) {
      lab_id = 1;
    }
    update_lab();
    lab->init();
    while (HAL_GPIO_ReadPin(BTN0_GPIO_Port, BTN0_Pin) == GPIO_PIN_RESET) {
      soft_delay(65535);
    }
    switch_lock = false;
  }
}
}
