#include <algorithm>
#include <cstdint>
#include <vector>

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "types.hh"
#include "utils.hh"

void write_number_to_led(int number, GPIO_TypeDef *GPIO_LED) {
  HAL_GPIO_WritePin(GPIO_LED, ~number, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIO_LED, number, GPIO_PIN_RESET);
  // send_number_to_uart(number);
}

void soft_delay(uint32_t count) {
  while (count--) {
  }
}

int btn_debounce(GPIO_TypeDef *GPIOx, uint16_t pin) {
  soft_delay(65535);
  if (HAL_GPIO_ReadPin(GPIOx, pin) != GPIO_PIN_RESET) {
    return false;
  }
  return true;
}

/**
 * @brief 采集 ADC 数据
 *
 * @param hadc ADC 端口
 * @param count 采集多少次
 * @param pick 取中间多少个数据
 * @return 采集到的平均值
 */
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
