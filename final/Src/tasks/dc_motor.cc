#include <cmath>
#include <cstdlib>
#include <string>

#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "data_update_queue.h"
#include "gpio.h"
#include "lcd12864.hh"
#include "main.h"
#include "stm32f103xe.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "utils.hh"

/**
 * @brief 初始速度，为高电平占空比，最大为 1000
 */
int speed = 50;

/**
 * @brief 将速度发送给 lcd 显示模块
 */
void send_speed() {
  DataUpdateQueueItem msg;
  msg.source = DC_MOTOR;
  msg.data.int_value = speed;
  osMessageQueuePut(DataUpdateQueueHandle, &msg, 0, 0);
}

/**
 * @brief 修改高电平的占空比
 *
 * @param pwm 高电平的占空比
 */
void set_pwm(int pwm) {
  int pwm_abs = abs(pwm);
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pwm_abs);
}

/**
 * @brief 任务入口
 */
void cpp_start_task_dc_motor() {
  // 启动 PWM 输出
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  // 设置初始速度
  set_pwm(speed);
  send_speed();

  // 等待中断
  while (true) {
    osDelay(100);
  }
}

/**
 * @brief IKEY0 按键中断的处理函数，会由总外部中断处理函数分流后调用
 */
void dc_motor_btn_callback() {
  // 按钮防抖
  if (!btn_debounce(IKEY0_GPIO_Port, IKEY0_Pin)) {
    return;
  }
  // 增加速度，如达到最大，则从最小速度开始
  speed = (speed + 100) % 1000;
  // 设置速度
  set_pwm(speed);
  send_speed();
}
