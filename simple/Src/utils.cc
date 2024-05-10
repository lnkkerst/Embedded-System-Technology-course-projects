#include "utils.hh"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_uart.h"
#include "usart.h"

void soft_delay(u32 count) {
  while (count--) {
  }
}

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(LED0_GPIO_Port, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED0_GPIO_Port, number, GPIO_PIN_RESET);
  send_number_to_uart(number);
}

void send_number_to_uart(int number) {
  HAL_UART_Transmit(&huart1, (uint8_t *)&number, 2, 0xffff);
}
