#include "app_main.h"

#include "os/os_tasks.h"
#include "services/sys_state.h"
#include "services/sys_health.h"
#include "services/data_hub.h"
#include "services/logger.h"
#include "config/config_store.h"

void app_main_init(void)
{
    // Order matters: config -> services -> adapters -> tasks
    config_store_init();
    sys_state_init();
    sys_health_init();
    data_hub_init();
    logger_init();

    // Create OS objects and tasks
    os_tasks_init();
}
