#pragma once

#include "labs/lab.hh"

class Lab2 : public Lab {
private:
  int current_led = -1;
  static const int TOTAL_LED = 16;

public:
  void init() override;
  void run() override;
  void clean_effect() override;
};
