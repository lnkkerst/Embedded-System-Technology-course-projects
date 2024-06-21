#include "adc.h"
#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "data_update_queue.h"
#include "utils.hh"

/**
 * @brief 发送电压到 LCD 模块，因为我不会计算温度 :(
 *
 * @param value 电压
 */
void send_adc_temp(double value) {
  DataUpdateQueueItem msg;
  msg.source = ADC_TEMP;
  msg.data.float_value = value;
  osMessageQueuePut(DataUpdateQueueHandle, &msg, 0, 0);
}

/**
 * @brief 任务入口
 */
void cpp_start_task_adc_temp() {
  while (true) {
    double ad_value = get_adc_by_average(&hadc1);
    double vol_value = ad_value * (3.3 / 4096);
    send_adc_temp(vol_value);
    osDelay(5000);
  }
}
