#include "utils.hh"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_uart.h"
#include "usart.h"
#include <algorithm>
#include <cstdio>
#include <vector>

void soft_delay(u32 count) {
  while (count--) {
  }
}

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(LED0_GPIO_Port, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED0_GPIO_Port, number, GPIO_PIN_RESET);
  // send_number_to_uart(number);
}

void send_number_to_uart(int number) {
  printf("Get integer: %d\r\n", number);
}

double get_adc_by_average(ADC_HandleTypeDef *hadc, int count, int pick) {
  std::vector<u32> ad_values(count);
  for (int i = 0; i < count; ++i) {
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, 10);
    u32 ad_value = HAL_ADC_GetValue(hadc);
    ad_values[i] = ad_value;
    HAL_ADC_Stop(hadc);
    HAL_Delay(10);
  }
  std::sort(ad_values.begin(), ad_values.end());
  double sum = 0;
  for (int i = (count - pick) >> 1, j = 0; j < pick; ++i, ++j) {
    sum += ad_values[i];
  }
  double average = sum / pick;
  return average;
}
