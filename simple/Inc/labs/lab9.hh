#pragma once

#include "labs/lab.hh"
#include "stm32f1xx_hal_tim.h"

class Lab9 : public Lab {
private:
  int count = 0;
  int mode = 0;

public:
  void init() override;
  void run() override;
  void clean_effect() override;
  void tim_period_elapsed_callback(TIM_HandleTypeDef *htim) override;
  void wkup_btn_short_click_callback() override;
};
