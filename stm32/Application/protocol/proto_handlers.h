#pragma once
#include <stdint.h>
#include <stddef.h>
#include "protocol/proto_defs.h"

void proto_handle_msg(const ProtoHdr* hdr, const uint8_t* payload, size_t payload_len);
