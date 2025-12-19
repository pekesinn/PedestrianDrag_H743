#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "proto_defs.h"

// Build a frame into out buffer: [ProtoHdr][payload]
bool proto_build(uint16_t msg_type, const void* payload, uint16_t payload_len,
                 uint8_t* out, size_t out_cap, size_t* out_len);

// Try parse a frame from rx buffer (single frame). For real TCP, add ring-buffer and parse loop.
bool proto_try_parse(const uint8_t* in, size_t in_len,
                     ProtoHdr* out_hdr, const uint8_t** out_payload);
