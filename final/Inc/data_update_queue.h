#pragma once

// 消息的来源
enum DATA_UPDATE_SOURCE {
  // 直流电机
  DC_MOTOR,

  // 舵机
  STEERING_ENGINE,

  // ADC 电阻
  ADC_POT,

  // ADC 热敏电阻
  ADC_TEMP
};

// 消息携带数据的类型
enum DATA_UPDATE_TYPE {
  // 浮点数
  FLOAT,

  // 整数
  INT
};

// 消息结构体
typedef struct {
  enum DATA_UPDATE_SOURCE source;
  enum DATA_UPDATE_TYPE type;

  union {
    float float_value;
    int int_value;
  } data;
} DataUpdateQueueItem;
