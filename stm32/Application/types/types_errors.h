#pragma once
#include <stdint.h>

typedef enum {
    ERR_OK = 0,
    ERR_HOST_LINK_DOWN = 1,
    ERR_RTK_TIMEOUT = 2,
    ERR_RANGE_TIMEOUT = 3,
    ERR_MOTOR_FAULT = 4,
    ERR_CONFIG_INVALID = 5,
} sys_error_code_t;

// Warning bits (bitmask)
enum {
    WARN_RTK_WEAK = (1u << 0),
    WARN_RANGE_WEAK = (1u << 1),
    WARN_NEAR_LIMIT = (1u << 2),
};
