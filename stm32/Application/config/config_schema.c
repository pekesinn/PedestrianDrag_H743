#include "config_schema.h"
#include <string.h>

void config_schema_set_defaults(ConfigSchema* cfg)
{
    memset(cfg, 0, sizeof(*cfg));
    cfg->version = CONFIG_VERSION;
    cfg->host_tcp_port = 5000;
    cfg->target_speed_mps = 2.0f;
    cfg->target_accel_mps2 = 1.0f;
}
