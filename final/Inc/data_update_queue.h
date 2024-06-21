#pragma once

enum DATA_UPDATE_SOURCE {
  DC_MOTOR,
  STEERING_ENGINE,
  ADC_POT,
  ADC_TEMP
};

enum DATA_UPDATE_TYPE {
  FLOAT,
  INT
};

typedef struct {
  enum DATA_UPDATE_SOURCE source;
  enum DATA_UPDATE_TYPE type;

  union {
    float float_value;
    int int_value;
  } data;
} DataUpdateQueueItem;
