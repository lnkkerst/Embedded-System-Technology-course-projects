#pragma once

#include "stm32f103xe.h"

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED = GPIOF);
