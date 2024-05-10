#pragma once

#include "main.h"
#include "stm32f103xe.h"
#include "types.hh"

// clang-format off
__attribute__((optimize("O0")))
// clang-format on
void soft_delay(u32 count);

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED = LED0_GPIO_Port);

void send_number_to_uart(int number);
