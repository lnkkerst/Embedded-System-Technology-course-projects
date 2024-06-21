#include <cstdio>
#include <sstream>
#include <string>

#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "cpp_main.hh"
#include "data_update_queue.h"
#include "lcd12864.hh"
#include "main.h"
#include "stm32f1xx_hal_gpio.h"

int dc_motor_speed = 0;
int steering_engine_deg = 0;

void update_screen() {
  char msg[64];
  sprintf(msg, "DM: %d, SG: %d", dc_motor_speed, steering_engine_deg);
  lcd12864::send_string_multiline(msg);
}

void cpp_start_task_lcd() {
  lcd12864::init();
  update_screen();
  while (true) {
    osDelay(100);
    DataUpdateQueueItem msg;
    if (osMessageQueueGet(DataUpdateQueueHandle, &msg, 0, 0) != osOK) {
      continue;
    }
    if (msg.source == DC_MOTOR) {
      dc_motor_speed = msg.data.int_value;
    }
    if (msg.source == STEERING_ENGINE) {
      steering_engine_deg = msg.data.int_value;
    }
    update_screen();
  }
}
