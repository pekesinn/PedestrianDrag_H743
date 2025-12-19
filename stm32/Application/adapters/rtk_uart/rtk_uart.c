#include "rtk_uart.h"
#include "bsp/bsp_uart.h"
#include "bsp/bsp_time.h"
#include "services/data_hub.h"
#include "services/sys_health.h"
#include <string.h>

static uint8_t s_rxbuf[512];
static uart_dma_rx_t s_uart = {
    .rx_buf = s_rxbuf,
    .rx_buf_size = sizeof(s_rxbuf),
    .rx_len = 0
};

void rtk_uart_init(void)
{
    // TODO: start UART DMA reception + enable IDLE interrupt in HAL callbacks
    bsp_uart_dma_idle_init(&s_uart);
}

void rtk_uart_poll(void)
{
    uint8_t tmp[512];
    size_t n = 0;
    if (!bsp_uart_dma_idle_fetch(&s_uart, tmp, sizeof(tmp), &n)) return;

    // TODO: replace stub parser with actual RTK protocol
    RTKFrame f = {0};
    f.ts_ms = bsp_time_now_ms();
    // placeholder values
    f.lat_deg = 0.0;
    f.lon_deg = 0.0;
    f.heading_deg = 0.0f;
    f.speed_mps = 0.0f;
    f.fix_type = 0;
    f.sat_num = 0;

    data_hub_set_rtk(&f);
    sys_health_on_rtk_rx(f.ts_ms);

    (void)tmp; (void)n;
}
