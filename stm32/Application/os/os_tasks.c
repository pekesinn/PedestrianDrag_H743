#include "os_tasks.h"

#include "FreeRTOS.h"
#include "task.h"

#include "services/sys_state.h"
#include "services/sys_health.h"
#include "adapters/host_tcp/host_tcp_server.h"
#include "adapters/rtk_uart/rtk_uart.h"
#include "adapters/range_uart/range_uart.h"
#include "control/control_loop.h"
#include "services/logger.h"

// Task handles (optional)
static TaskHandle_t hTaskSys = NULL;
static TaskHandle_t hTaskHost = NULL;
static TaskHandle_t hTaskRTK = NULL;
static TaskHandle_t hTaskRange = NULL;
static TaskHandle_t hTaskCtrl = NULL;
static TaskHandle_t hTaskLog = NULL;

static void TaskSys(void* arg);
static void TaskHost(void* arg);
static void TaskRTK(void* arg);
static void TaskRange(void* arg);
static void TaskCtrl(void* arg);
static void TaskLog(void* arg);

void os_tasks_init(void)
{
    // Create tasks. Tune stack sizes based on real usage.
    xTaskCreate(TaskSys,   "sys",   512, NULL, tskIDLE_PRIORITY + 3, &hTaskSys);
    xTaskCreate(TaskHost,  "host",  768, NULL, tskIDLE_PRIORITY + 3, &hTaskHost);
    xTaskCreate(TaskRTK,   "rtk",   512, NULL, tskIDLE_PRIORITY + 2, &hTaskRTK);
    xTaskCreate(TaskRange, "range", 512, NULL, tskIDLE_PRIORITY + 2, &hTaskRange);
    xTaskCreate(TaskCtrl,  "ctrl",  768, NULL, tskIDLE_PRIORITY + 4, &hTaskCtrl);
    xTaskCreate(TaskLog,   "log",   768, NULL, tskIDLE_PRIORITY + 1, &hTaskLog);
}

void os_tasks_start(void)
{
    vTaskStartScheduler();
    // Should never return
    for (;;) {}
}

static void TaskSys(void* arg)
{
    (void)arg;
    const TickType_t period = pdMS_TO_TICKS(10);
    TickType_t last = xTaskGetTickCount();

    for (;;) {
        sys_state_tick();
        sys_health_tick();
        vTaskDelayUntil(&last, period);
    }
}

static void TaskHost(void* arg)
{
    (void)arg;
    host_tcp_server_init();
    for (;;) {
        host_tcp_server_poll(); // event-driven in real impl; poll stub here
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

static void TaskRTK(void* arg)
{
    (void)arg;
    rtk_uart_init();
    for (;;) {
        rtk_uart_poll();
        vTaskDelay(pdMS_TO_TICKS(2));
    }
}

static void TaskRange(void* arg)
{
    (void)arg;
    range_uart_init();
    for (;;) {
        range_uart_poll();
        vTaskDelay(pdMS_TO_TICKS(2));
    }
}

static void TaskCtrl(void* arg)
{
    (void)arg;
    control_loop_init();
    const TickType_t period = pdMS_TO_TICKS(2);
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        control_loop_tick();
        vTaskDelayUntil(&last, period);
    }
}

static void TaskLog(void* arg)
{
    (void)arg;
    for (;;) {
        logger_tick();
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}
