# Pedestrian Drag System - STM32H743 Software Scaffold (Keil5-friendly)

This repository is a **source-code scaffold** for an STM32H743 project using:
- FreeRTOS (tasks/queues/events skeleton)
- LwIP (TCP server adapter skeleton)
- UART (RTK/Range adapters skeleton)

It is designed to be **dropped into a CubeMX-generated Keil project**:
1. Generate the STM32H743 project with CubeMX (Keil MDK-ARM), enable FreeRTOS + LwIP + required UARTs.
2. Copy the `stm32/Application` and `stm32/Board` folders into your CubeMX project tree.
3. In Keil uVision, add these sources to groups and include paths (see `docs/keil_setup.md`).
4. In `Core/Src/main.c`, call `app_main_init()` before starting the scheduler.

Notes:
- This scaffold compiles only after you wire it into your CubeMX project and provide actual peripheral init (MX_*).
- The TCP protocol framing uses a length-prefixed header and is intended to evolve.

