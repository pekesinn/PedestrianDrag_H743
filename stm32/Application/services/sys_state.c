#include "sys_state.h"

static volatile sys_state_t g_state = SYS_BOOT;

void sys_state_init(void)
{
    g_state = SYS_BOOT;
}

void sys_state_tick(void)
{
    // Minimal boot->idle transition. Replace with real checks.
    if (g_state == SYS_BOOT) {
        g_state = SYS_IDLE;
    }
}

sys_state_t sys_state_get(void) { return g_state; }
void sys_state_set(sys_state_t s) { g_state = s; }
