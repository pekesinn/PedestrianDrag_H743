# TCP Protocol (Minimal Skeleton)

Frame layout:
- ProtoHdr (8 bytes) + payload

ProtoHdr:
- magic: 0x5044 ('PD')
- ver: 0x01
- flags: reserved
- msg_type: uint16
- payload_len: uint16

Message types (initial):
- HELLO (1): optional payload
- HEARTBEAT (2): no payload
- STATUS (3): StatusFrame payload (define in future)
- SET_PARAM (4): payload = ConfigSchema patch (define later)
- CMD_START (5): no payload
- CMD_STOP (6): no payload

Implementation notes:
- TCP is a stream; real implementation must handle sticky packets by buffering and parsing in a loop.
