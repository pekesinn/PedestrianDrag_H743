#pragma once
#include <stdint.h>
#include "types/types_common.h"

#define PROTO_MAGIC (0x5044u) // 'P''D'
#define PROTO_VER   (0x01u)

typedef enum : uint16_t {
    MSG_HELLO      = 1,
    MSG_HEARTBEAT  = 2,
    MSG_STATUS     = 3,
    MSG_SET_PARAM  = 4,
    MSG_CMD_START  = 5,
    MSG_CMD_STOP   = 6,
} MsgType;

typedef struct PACKED {
    uint16_t magic;
    uint8_t  ver;
    uint8_t  flags;
    uint16_t msg_type;
    uint16_t payload_len;
} ProtoHdr;
