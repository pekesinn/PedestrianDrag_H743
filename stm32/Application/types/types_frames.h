#pragma once
#include "types_common.h"
#include "types_errors.h"

typedef struct {
    uint32_t ts_ms;
    double lat_deg;
    double lon_deg;
    float  heading_deg;
    float  speed_mps;
    uint8_t fix_type;
    uint8_t sat_num;
} RTKFrame;

typedef struct {
    uint32_t ts_ms;
    float distance_m;
    float rel_speed_mps;
    uint8_t quality;
} RangeFrame;

typedef struct {
    uint32_t ts_ms;
    bool enabled;
    float target_speed_mps;
    float actual_speed_mps;
    bool fault;
} MotorState;

typedef struct {
    uint32_t ts_ms;
    uint32_t run_id;

    uint8_t  sys_state;        // see sys_state.h
    uint8_t  trigger_state;    // see trigger.h
    uint16_t reserved;

    sys_error_code_t error_code;
    uint32_t warning_bits;

    // counters
    uint32_t hb_rx_count;
    uint32_t cmd_rx_count;

    // live values
    float ttc_s;
    float dummy_distance_m;
    float dummy_speed_mps;

    MotorState motor;
} StatusFrame;

