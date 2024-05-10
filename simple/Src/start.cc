#include "cpp_start.h"
#include "labs.hh"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "types.hh"
#include "utils.hh"
#include <memory>
#include <vector>

int lab_id = 0;
std::shared_ptr<Lab> lab = nullptr;
std::vector<std::shared_ptr<Lab>> labs;

bool switch_lock = false;

void init_labs() {
  labs = {std::make_shared<Lab1>(), std::make_shared<Lab2>(),
          std::make_shared<Lab3>(), std::make_shared<Lab4>(),
          std::make_shared<Lab5>()};
}

void update_lab() {
  lab = labs[lab_id];
}

int cpp_start() {
  init_labs();

  update_lab();
  lab->init();
  while (true) {
    lab->run();
  }
}

void tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (lab != nullptr) {
    lab->tim_period_elapsed_callback(htim);
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
    if (lab_id >= labs.size()) {
      lab_id = 0;
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
