#pragma once

#include "stm32f103xe.h"
#include <cstdint>

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED = GPIOF);

int btn_debounce(GPIO_TypeDef *GPIOx, uint16_t pin);

// clang-format off
__attribute__((optimize("O0")))
// clang-format on
void soft_delay(uint32_t count);
