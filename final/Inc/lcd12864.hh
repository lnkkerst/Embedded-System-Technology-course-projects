#pragma once

#include <string>

#include "types.hh"

namespace lcd12864 {

enum class SEND_DATA_MODE {
  CMD,
  DATA
};

void send_byte(u8 byte);

void send_data(SEND_DATA_MODE mode, u8 data);

void send_data(u8 data);

void send_cmd(u8 cmd);

void init();

void set_cursor(u8 row, u8 col);

void send_string(const std::string &&str);

void send_string_multiline(const std::string &&str);

void clear_screen();

} // namespace lcd12864
