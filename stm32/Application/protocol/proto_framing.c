#include "proto_framing.h"
#include <string.h>

bool proto_build(uint16_t msg_type, const void* payload, uint16_t payload_len,
                 uint8_t* out, size_t out_cap, size_t* out_len)
{
    size_t need = sizeof(ProtoHdr) + payload_len;
    if (need > out_cap) return false;

    ProtoHdr hdr;
    hdr.magic = PROTO_MAGIC;
    hdr.ver = PROTO_VER;
    hdr.flags = 0;
    hdr.msg_type = msg_type;
    hdr.payload_len = payload_len;

    memcpy(out, &hdr, sizeof(hdr));
    if (payload_len && payload) {
        memcpy(out + sizeof(hdr), payload, payload_len);
    }
    *out_len = need;
    return true;
}

bool proto_try_parse(const uint8_t* in, size_t in_len,
                     ProtoHdr* out_hdr, const uint8_t** out_payload)
{
    if (in_len < sizeof(ProtoHdr)) return false;
    ProtoHdr hdr;
    memcpy(&hdr, in, sizeof(hdr));
    if (hdr.magic != PROTO_MAGIC || hdr.ver != PROTO_VER) return false;
    if (in_len < (sizeof(ProtoHdr) + hdr.payload_len)) return false;

    *out_hdr = hdr;
    *out_payload = in + sizeof(ProtoHdr);
    return true;
}
