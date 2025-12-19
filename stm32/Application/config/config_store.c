#include "config_store.h"
#include "config_crc.h"
#include <string.h>

static ConfigSchema g_cfg;

void config_store_init(void)
{
    ConfigSchema tmp;
    if (config_store_load(&tmp)) {
        g_cfg = tmp;
        return;
    }
    config_schema_set_defaults(&g_cfg);
    // Save defaults on first boot if desired:
    // config_store_save(&g_cfg);
}

const ConfigSchema* config_store_get(void)
{
    return &g_cfg;
}

bool config_store_save(const ConfigSchema* cfg)
{
    // TODO: implement Flash write via bsp_flash
    (void)cfg;
    return false;
}

bool config_store_load(ConfigSchema* out)
{
    // TODO: implement Flash read via bsp_flash
    (void)out;
    return false;
}
