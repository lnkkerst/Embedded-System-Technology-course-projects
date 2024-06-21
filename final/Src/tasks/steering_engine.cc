#include <cmath>
#include <cstdint>

#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "data_update_queue.h"
#include "gpio.h"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"

/**
 * @brief 预先定义一些角度，以备不时之需
 */
uint8_t degs[] = {0, 45, 90, 135, 180};

/**
 * @brief 初始角度
 */
uint8_t deg = 90;

/**
 * @brief 每次调整的角度的增量
 */
int step = 9;

/**
 * @brief 将角度发送给 LCD 显示模块
 */
void send_deg() {
  DataUpdateQueueItem msg;
  msg.source = STEERING_ENGINE;
  msg.data.int_value = deg;
  osMessageQueuePut(DataUpdateQueueHandle, &msg, 0, 0);
}

/**
 * @brief 把角度转换为对应的 CCR1 值并设置
 *
 * @param deg 角度值，范围 0~180
 */
void set_deg(uint8_t deg) {
  TIM3->CCR1 = deg / 9 + 5;
}

/**
 * @brief 任务入口
 */
void cpp_start_task_steering_engine() {
  // 启动 PWM 输出
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  // 设置初始角度
  set_deg(deg);
  // 更新 LCD 显示内容
  send_deg();
  // 等待中断
  while (true) {
    osDelay(1000);
  }
}

/**
 * @brief IKEY1 按键中断的处理函数，会由总外部中断处理函数分流后调用
 */
void steering_engine_btn_callback() {
  // 按键防抖
  if (!btn_debounce(IKEY1_GPIO_Port, IKEY1_Pin)) {
    return;
  }
  // 调整角度
  deg += step;
  // 到达边界后反向
  if (deg >= 150 || deg <= 30) {
    step = -step;
  }
  // 设置角度
  set_deg(deg);
  send_deg();
}
