#include "range_uart.h"
#include "bsp/bsp_uart.h"
#include "bsp/bsp_time.h"
#include "services/data_hub.h"
#include "services/sys_health.h"
#include <string.h>

static uint8_t s_rxbuf[256];
static uart_dma_rx_t s_uart = {
    .rx_buf = s_rxbuf,
    .rx_buf_size = sizeof(s_rxbuf),
    .rx_len = 0
};

void range_uart_init(void)
{
    // TODO: start UART DMA reception + enable IDLE interrupt in HAL callbacks
    bsp_uart_dma_idle_init(&s_uart);
}

void range_uart_poll(void)
{
    uint8_t tmp[256];
    size_t n = 0;
    if (!bsp_uart_dma_idle_fetch(&s_uart, tmp, sizeof(tmp), &n)) return;

    RangeFrame f = {0};
    f.ts_ms = bsp_time_now_ms();
    f.distance_m = 0.0f;
    f.rel_speed_mps = 0.0f;
    f.quality = 0;

    data_hub_set_range(&f);
    sys_health_on_range_rx(f.ts_ms);

    (void)tmp; (void)n;
}
