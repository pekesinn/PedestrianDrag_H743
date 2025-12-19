#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void host_tcp_server_init(void);
void host_tcp_server_poll(void);

// send status/log
bool host_tcp_send(const uint8_t* data, size_t len);
