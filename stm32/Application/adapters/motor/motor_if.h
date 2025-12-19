#pragma once
#include <stdbool.h>
#include "types/types_frames.h"

void motor_init(void);
void motor_tick(void);

bool motor_enable(bool en);
bool motor_estop(void);
bool motor_set_speed(float mps);

bool motor_get_state(MotorState* out);
