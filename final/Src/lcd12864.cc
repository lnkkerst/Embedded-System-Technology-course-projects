#include <string>

#include "cmsis_os2.h"
#include "lcd12864.hh"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

namespace lcd12864 {

void send_byte(u8 byte) {
  HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
  for (i8 i = 7; i >= 0; --i) {
    HAL_GPIO_WritePin(LCD_SID_GPIO_Port, LCD_SID_Pin,
                      ((byte >> i) & 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port, LCD_SCLK_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port, LCD_SCLK_Pin, GPIO_PIN_SET);
  }
  HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
}

void send_data(SEND_DATA_MODE mode, u8 data) {
  if (mode == SEND_DATA_MODE::CMD) {
    send_byte(0xf8);
  } else {
    send_byte(0xfa);
  }
  send_byte(data & 0xf0);
  send_byte((data << 4) & 0xf0);
  osDelay(10);
}

void send_data(u8 data) {
  return send_data(SEND_DATA_MODE::DATA, data);
}

void send_cmd(u8 cmd) {
  return send_data(SEND_DATA_MODE::CMD, cmd);
}

void init() {
  send_cmd(0x30);
  send_cmd(0x06);
  send_cmd(0x0c);
  send_cmd(0x01);
  send_cmd(0x80);
}

void set_cursor(u8 row, u8 col) {
  static const u8 rows[] = {0x80, 0x90, 0x88, 0x98};
  u8 addr = rows[row - 1];
  addr += col - 1;

  send_cmd(addr);
}

void send_string(const std::string &&str) {
  for (auto c : str) {
    send_data(c);
  }
}

void send_string_multiline(const std::string &&str) {
  clear_screen();
  set_cursor(1, 1);
  u8 row = 1;
  for (auto c : str) {
    if (c == '\n') {
      ++row;
      set_cursor(row, 1);
    } else {
      send_data(c);
    }
  }
}

void clear_screen() {
  send_cmd(0x01);
}

} // namespace lcd12864
