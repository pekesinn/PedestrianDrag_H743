#pragma once

// Hardware revision tracking. Update as your board spins.
typedef enum {
    HW_REV_A = 0,
    HW_REV_B = 1,
} hw_rev_t;

#ifndef HW_REV_CURRENT
#define HW_REV_CURRENT HW_REV_A
#endif
