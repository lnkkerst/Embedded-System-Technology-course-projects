#pragma once

#include <string>

#include "types.hh"

namespace lcd12864 {

// 向 LCD 发送的数据的类型，指令或者数据
enum class SEND_DATA_MODE {
  CMD,
  DATA
};

/**
 * @brief 向 LCD 发送一个字节的内容
 *
 * @param byte 要发送的字节
 */
void send_byte(u8 byte);

/**
 * @brief 向 LCD 发送数据，需要指定类型
 *
 * @param mode 发送的类型
 * @param data 发送的内容
 */
void send_data(SEND_DATA_MODE mode, u8 data);

/**
 * @brief 发送数据
 *
 * @param data 数据内容
 */
void send_data(u8 data);

/**
 * @brief 发送指令
 *
 * @param cmd 指令内容
 */
void send_cmd(u8 cmd);

/**
 * @brief 初始化 LCD
 */
void init();

/**
 * @brief 设置光标的位置
 *
 * @param row 行位置
 * @param col 列位置
 */
void set_cursor(u8 row, u8 col);

/**
 * @brief 发送单行字符串，会在光标后追加
 *
 * @param str 要发送的字符串
 */
void send_string(const std::string &&str);

/**
 * @brief 发送多行字符串，会清空屏幕并从头开始写入
 *
 * @param str 要发送的字符串
 */
void send_string_multiline(const std::string &&str);

/**
 * @brief 清空显示屏
 */
void clear_screen();

} // namespace lcd12864
