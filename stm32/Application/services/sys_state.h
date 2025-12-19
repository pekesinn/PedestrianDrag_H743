#pragma once
#include <stdint.h>

typedef enum {
    SYS_BOOT = 0,
    SYS_IDLE = 1,
    SYS_ARMED = 2,
    SYS_RUNNING = 3,
    SYS_STOPPING = 4,
    SYS_FAULT = 5,
} sys_state_t;

void sys_state_init(void);
void sys_state_tick(void);

sys_state_t sys_state_get(void);
void sys_state_set(sys_state_t s);
