#include "control_loop.h"
#include "services/sys_state.h"
#include "services/sys_health.h"
#include "services/data_hub.h"
#include "adapters/motor/motor_if.h"
#include "config/config_store.h"

void control_loop_init(void)
{
    motor_init();
}

void control_loop_tick(void)
{
    // Always tick motor (mock or real)
    motor_tick();

    // Minimal behavior: when running, set target speed from config
    const ConfigSchema* cfg = config_store_get();
    sys_state_t s = sys_state_get();

    if (s == SYS_RUNNING) {
        motor_enable(true);
        motor_set_speed(cfg->target_speed_mps);
    } else if (s == SYS_STOPPING) {
        motor_set_speed(0.0f);
        motor_enable(false);
        sys_state_set(SYS_IDLE);
    } else {
        // idle/armed/boot
    }
}
