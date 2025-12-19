#pragma once
#include <stdbool.h>
#include "types/types_frames.h"

void data_hub_init(void);

// Latest-sample cache API (simple and practical early on)
void data_hub_set_rtk(const RTKFrame* f);
void data_hub_set_range(const RangeFrame* f);
void data_hub_set_motor(const MotorState* s);

bool data_hub_get_rtk(RTKFrame* out);
bool data_hub_get_range(RangeFrame* out);
bool data_hub_get_motor(MotorState* out);
