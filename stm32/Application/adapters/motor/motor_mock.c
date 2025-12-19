#include "motor_if.h"
#include "bsp/bsp_time.h"
#include "services/data_hub.h"
#include <string.h>

static MotorState g_ms;
static float g_target = 0.0f;

void motor_init(void)
{
    memset(&g_ms, 0, sizeof(g_ms));
    g_ms.enabled = false;
    g_ms.fault = false;
}

void motor_tick(void)
{
    g_ms.ts_ms = bsp_time_now_ms();

    // Simple first-order response
    float a = 0.1f;
    g_ms.actual_speed_mps = g_ms.actual_speed_mps + a * (g_target - g_ms.actual_speed_mps);
    g_ms.target_speed_mps = g_target;

    data_hub_set_motor(&g_ms);
}

bool motor_enable(bool en) { g_ms.enabled = en; return true; }
bool motor_estop(void) { g_ms.enabled = false; g_target = 0.0f; return true; }
bool motor_set_speed(float mps) { g_target = mps; return true; }

bool motor_get_state(MotorState* out) { *out = g_ms; return true; }
