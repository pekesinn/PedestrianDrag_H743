#include "bsp_time.h"
#include "FreeRTOS.h"
#include "task.h"

uint32_t bsp_time_now_ms(void)
{
    // Uses FreeRTOS tick; ensure configTICK_RATE_HZ is set.
    return (uint32_t)(xTaskGetTickCount() * (1000u / configTICK_RATE_HZ));
}
