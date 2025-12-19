#include "sys_health.h"
#include "bsp/bsp_time.h"
#include "Board/board_limits.h"

static uint32_t g_last_hb_ms = 0;
static uint32_t g_last_rtk_ms = 0;
static uint32_t g_last_range_ms = 0;

static sys_error_code_t g_err = ERR_OK;
static uint32_t g_warn = 0;

void sys_health_init(void)
{
    uint32_t now = bsp_time_now_ms();
    g_last_hb_ms = now;
    g_last_rtk_ms = now;
    g_last_range_ms = now;
    g_err = ERR_OK;
    g_warn = 0;
}

void sys_health_on_host_heartbeat(void) { g_last_hb_ms = bsp_time_now_ms(); }
void sys_health_on_rtk_rx(uint32_t ts_ms) { (void)ts_ms; g_last_rtk_ms = bsp_time_now_ms(); }
void sys_health_on_range_rx(uint32_t ts_ms) { (void)ts_ms; g_last_range_ms = bsp_time_now_ms(); }

void sys_health_tick(void)
{
    uint32_t now = bsp_time_now_ms();

    g_err = ERR_OK;
    if ((now - g_last_hb_ms) > TIMEOUT_HOST_HEARTBEAT_MS) g_err = ERR_HOST_LINK_DOWN;
    else if ((now - g_last_rtk_ms) > TIMEOUT_RTK_MS) g_err = ERR_RTK_TIMEOUT;
    else if ((now - g_last_range_ms) > TIMEOUT_RANGE_MS) g_err = ERR_RANGE_TIMEOUT;

    // warnings can be accumulated here
    g_warn = 0;
}

sys_error_code_t sys_health_get_error(void) { return g_err; }
uint32_t sys_health_get_warning_bits(void) { return g_warn; }
