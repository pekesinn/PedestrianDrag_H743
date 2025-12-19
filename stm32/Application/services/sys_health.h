#pragma once
#include <stdint.h>
#include "types/types_errors.h"

void sys_health_init(void);
void sys_health_tick(void);

void sys_health_on_host_heartbeat(void);
void sys_health_on_rtk_rx(uint32_t ts_ms);
void sys_health_on_range_rx(uint32_t ts_ms);

sys_error_code_t sys_health_get_error(void);
uint32_t sys_health_get_warning_bits(void);
