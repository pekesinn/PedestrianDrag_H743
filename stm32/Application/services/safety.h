#pragma once
#include <stdbool.h>

void safety_init(void);

// Returns whether a global safety stop is active
bool safety_is_estop(void);

// Trigger a global emergency stop
void safety_estop(void);
