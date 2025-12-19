#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif

// Compile-time packed attribute
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
  #define PACKED __packed
#elif defined(__GNUC__)
  #define PACKED __attribute__((packed))
#else
  #define PACKED
#endif

