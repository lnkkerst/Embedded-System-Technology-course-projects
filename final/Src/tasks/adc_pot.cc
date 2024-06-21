#include "adc.h"
#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "data_update_queue.h"
#include "utils.hh"

/**
 * @brief 发送阻值到 LCD 模块
 *
 * @param value 阻值
 */
void send_adc(double value) {
  DataUpdateQueueItem msg;
  msg.source = ADC_POT;
  msg.data.float_value = value;
  osMessageQueuePut(DataUpdateQueueHandle, &msg, 0, 0);
}

/**
 * @brief 任务入口
 */
void cpp_start_task_adc_pot() {
  while (true) {
    double ad_value = get_adc_by_average(&hadc2);
    double vol_value = ad_value * (3.3 / 4096);
    double ohm_value = 10 * vol_value / (3.3 - vol_value);
    send_adc(ohm_value);
    osDelay(5000);
  }
}
