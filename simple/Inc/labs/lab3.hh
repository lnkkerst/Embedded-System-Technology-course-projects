#pragma once

#include "labs/lab.hh"

class Lab3 : public Lab {
private:
  int count = 0;

public:
  void init() override;
  void run() override;
  void clean_effect() override;
};
