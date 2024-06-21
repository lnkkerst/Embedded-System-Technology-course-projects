#include "cmsis_os2.h"
#include "cpp_main.hh"

void start_task_traffic_lights(void *args) {
  return cpp_start_task_traffic_lights();
}

void start_task_running_lights(void *args) {
  return cpp_start_task_running_lights();
}

void start_task_dc_motor(void *args) {
  return cpp_start_task_dc_motor();
}

void start_task_steering_engine(void *args) {
  return cpp_start_task_steering_engine();
}

void start_task_lcd(void *args) {
  return cpp_start_task_lcd();
}

void start_task_adc_pot(void *args) {
  return cpp_start_task_adc_pot();
}

void start_task_adc_temp(void *args) {
  return cpp_start_task_adc_temp();
}
