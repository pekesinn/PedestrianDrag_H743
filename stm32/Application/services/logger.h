#pragma once
#include <stdint.h>

void logger_init(void);
void logger_tick(void);

// Simple logging API (stub). Replace with RTT/UART/host streaming as needed.
void logger_printf(const char* fmt, ...);
