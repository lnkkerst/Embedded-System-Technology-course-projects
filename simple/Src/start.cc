#include "adc.h"
#include "cmsis_os2.h"
#include "cpp_start.h"
#include "labs.hh"
#include "labs/lab5.hh"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "types.hh"
#include "utils.hh"
#include <cstdio>
#include <memory>
#include <vector>

u32 lab_id = 0;
std::shared_ptr<Lab> lab = nullptr;
std::vector<std::shared_ptr<Lab>> lab_list;

bool switch_lock = false;
bool end_round = false;

void init_labs() {
  lab_list = {std::make_shared<Lab1>(), std::make_shared<Lab2>(),
              std::make_shared<Lab3>(), std::make_shared<Lab4>(),
              std::make_shared<Lab5>(), std::make_shared<Lab6>(),
              std::make_shared<Lab7>(), std::make_shared<Lab8>(),
              std::make_shared<Lab9>(), std::make_shared<Lab10>()};
}

void update_lab() {
  lab = lab_list[lab_id];
}

void cpp_start_clean() {
  lab_id = 0;
  lab = nullptr;
  lab_list.clear();
}

int cpp_start() {
  init_labs();

  update_lab();
  lab->init();
  while (true) {
    if (end_round) {
      cpp_start_clean();
      return 0;
    }
    lab->run();
  }
}

void cpp_start_lab11_task1() {
  int count = 0;
  while (true) {
    printf("Count: %d\r\n", count);
    count++;
    HAL_Delay(500);
  }
}

void cpp_start_lab11_task2() {
  while (true) {
    auto ad_value = get_adc_by_average(&hadc2);
    auto vol_value = ad_value * (3.3 / 4096);
    write_number_to_led(int(vol_value * 1000));
    osDelay(100);
  }
}

void tim_period_elapsed_callback(TIM_HandleTypeDef *htim) {
  if (end_round) {
    return;
  }
  if (lab != nullptr) {
    lab->tim_period_elapsed_callback(htim);
  }
}

extern "C" {
void HAL_GPIO_EXTI_Callback(uint16_t pin) {
  if (end_round) {
    return;
  }

  if (pin == BTN_WKUP_Pin) {
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
    if (lab_id >= lab_list.size()) {
      lab_id = 0;
      end_round = true;
    } else {
      update_lab();
      lab->init();

      switch_lock = false;
    }
  }
}
}
