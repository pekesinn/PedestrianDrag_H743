#pragma once
#include <stdbool.h>
#include "config_schema.h"

void config_store_init(void);

// Get a pointer to active config (RAM)
const ConfigSchema* config_store_get(void);

// Persist config to flash (stub for now)
bool config_store_save(const ConfigSchema* cfg);

// Load config from flash (stub for now)
bool config_store_load(ConfigSchema* out);
