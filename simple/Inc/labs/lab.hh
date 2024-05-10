#pragma once

#include "stm32f1xx_hal.h"

class Lab {
public:
  virtual void init() = 0;

  virtual void run() = 0;

  virtual void clean_effect() = 0;

  virtual void tim_period_elapsed_callback(TIM_HandleTypeDef *htim);
};
