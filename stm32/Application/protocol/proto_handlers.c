#include "proto_handlers.h"
#include "services/sys_health.h"
#include "services/sys_state.h"

void proto_handle_msg(const ProtoHdr* hdr, const uint8_t* payload, size_t payload_len)
{
    (void)payload;
    (void)payload_len;

    switch (hdr->msg_type) {
    case MSG_HEARTBEAT:
        sys_health_on_host_heartbeat();
        break;
    case MSG_CMD_START:
        sys_state_set(SYS_RUNNING);
        break;
    case MSG_CMD_STOP:
        sys_state_set(SYS_STOPPING);
        break;
    default:
        break;
    }
}
