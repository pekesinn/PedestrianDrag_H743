# Keil5 Setup Notes

## Suggested uVision Groups
- BSP_Cube: Core/Src (CubeMX-generated)
- HAL_Drivers: Drivers/STM32H7xx_HAL_Driver/Src
- CMSIS: Drivers/CMSIS
- FreeRTOS: Middlewares/Third_Party/FreeRTOS
- LwIP: Middlewares/Third_Party/LwIP
- App_Core: stm32/Application/app_main.*, os/*, services/*, types/*
- App_Protocol: stm32/Application/protocol/*
- App_Adapters: stm32/Application/adapters/*
- App_Control: stm32/Application/control/*
- App_BSP: stm32/Application/bsp/*
- Board: stm32/Board/*

## Include Paths (add to Options for Target -> C/C++ -> Include Paths)
- stm32/Application
- stm32/Application/types
- stm32/Application/os
- stm32/Application/services
- stm32/Application/protocol
- stm32/Application/adapters
- stm32/Application/control
- stm32/Application/bsp
- stm32/Board

(Plus your CubeMX-generated Core/Drivers/Middlewares include paths.)

## main.c Hook
In `Core/Src/main.c`, after CubeMX init calls (MX_*), add:

```c
#include "app_main.h"
...
app_main_init();
os_tasks_start(); // creates tasks/queues; then starts scheduler
```

If CubeMX already calls `osKernelStart()` (CMSIS-RTOS2), adapt `os_tasks_start()` accordingly.
