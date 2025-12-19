#include "host_tcp_server.h"

#include "protocol/proto_framing.h"
#include "protocol/proto_handlers.h"
#include "services/logger.h"
#include "services/sys_state.h"
#include "services/sys_health.h"
#include "services/data_hub.h"
#include "config/config_store.h"
#include "types/types_frames.h"
#include <string.h>

// NOTE: This file is a **stub**. Real implementation should use LwIP RAW API.
// Provide hooks for:
 // - accept callback
 // - recv callback (append to ring buffer, parse frames in loop)
 // - sent callback
 // - error/close handling

static uint8_t g_txbuf[256];

void host_tcp_server_init(void)
{
    // TODO: initialize LwIP TCP PCB, bind, listen
    logger_printf("host_tcp_server_init()\n");
}

void host_tcp_server_poll(void)
{
    // TODO: drive periodic status send if connected
    // Minimal demonstration: no-op
}

bool host_tcp_send(const uint8_t* data, size_t len)
{
    (void)data; (void)len;
    // TODO: tcp_write + tcp_output
    return false;
}
