#pragma once

class Lab {
public:
  virtual void init() = 0;

  virtual void run() = 0;

  virtual void clean_effect() = 0;
};
