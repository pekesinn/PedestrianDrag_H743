#pragma once
#include <stdint.h>
#include <stdbool.h>

#define CONFIG_VERSION (0x00010001u)

typedef struct {
    uint32_t version;
    uint32_t crc32;

    // Host TCP
    uint16_t host_tcp_port;

    // Control defaults
    float target_speed_mps;
    float target_accel_mps2;

    // Reserved for future expansion
    uint8_t reserved[64];
} ConfigSchema;

void config_schema_set_defaults(ConfigSchema* cfg);
