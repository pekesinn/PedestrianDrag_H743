#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint8_t* rx_buf;
    size_t   rx_buf_size;
    volatile size_t rx_len;
} uart_dma_rx_t;

void bsp_uart_dma_idle_init(uart_dma_rx_t* ctx);
bool bsp_uart_dma_idle_fetch(uart_dma_rx_t* ctx, uint8_t* out, size_t out_cap, size_t* out_len);
