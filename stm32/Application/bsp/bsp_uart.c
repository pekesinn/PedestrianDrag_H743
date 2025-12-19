#include "bsp_uart.h"
#include <string.h>

void bsp_uart_dma_idle_init(uart_dma_rx_t* ctx)
{
    ctx->rx_len = 0;
}

// This is a placeholder fetch. Real implementation should:
 // - use UART DMA circular buffer
 // - update rx_len in UART IDLE interrupt callback
bool bsp_uart_dma_idle_fetch(uart_dma_rx_t* ctx, uint8_t* out, size_t out_cap, size_t* out_len)
{
    if (ctx->rx_len == 0) {
        *out_len = 0;
        return false;
    }
    size_t n = ctx->rx_len;
    if (n > out_cap) n = out_cap;
    memcpy(out, ctx->rx_buf, n);
    ctx->rx_len = 0;
    *out_len = n;
    return true;
}
