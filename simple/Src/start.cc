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

int lab_id = 7;
std::shared_ptr<Lab> lab = nullptr;
std::vector<std::shared_ptr<Lab>> labs;

bool switch_lock = false;

void init_labs() {
  labs = {std::make_shared<Lab1>(), std::make_shared<Lab2>(),
          std::make_shared<Lab3>(), std::make_shared<Lab4>(),
          std::make_shared<Lab5>(), std::make_shared<Lab6>(),
          std::make_shared<Lab7>(), std::make_shared<Lab8>()};
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
  if (pin == BTN_WKUP_Pin || true) {
    soft_delay(65535);
    if (HAL_GPIO_ReadPin(BTN_WKUP_GPIO_Port, BTN_WKUP_Pin) != GPIO_PIN_RESET) {
      return;
    }

    int duration = 0;

    while (HAL_GPIO_ReadPin(BTN_WKUP_GPIO_Port, BTN_WKUP_Pin) ==
           GPIO_PIN_RESET) {
      ++duration;
      if (duration >= 50) {
        write_number_to_led(0xffff);
      }
      soft_delay(65535);
    }

    if (duration < 50) {
      if (lab != nullptr) {
        lab->wkup_btn_short_click_callback();
      }
      return;
    }

    if (switch_lock) {
      return;
    }

    switch_lock = true;

    write_number_to_led(0);

    lab->clean_effect();
    ++lab_id;
    if (lab_id >= labs.size()) {
      lab_id = 0;
    }
    update_lab();
    lab->init();

    switch_lock = false;
  }
}
}
