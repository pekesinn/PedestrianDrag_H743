#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void os_tasks_init(void);

// If you are using CMSIS-RTOS2, you may call this from main instead of vTaskStartScheduler.
void os_tasks_start(void);

#ifdef __cplusplus
}
#endif
