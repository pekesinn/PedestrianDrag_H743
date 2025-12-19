#include "logger.h"
#include <stdarg.h>
#include <stdio.h>

void logger_init(void) {}

void logger_tick(void) {}

void logger_printf(const char* fmt, ...)
{
    // Placeholder: route to ITM/SWO/RTT/UART later
    char buf[256];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    (void)buf;
}
