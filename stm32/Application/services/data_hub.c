#include "data_hub.h"
#include "FreeRTOS.h"
#include "task.h"
#include <string.h>

static RTKFrame g_rtk;
static RangeFrame g_range;
static MotorState g_motor;
static bool g_has_rtk = false;
static bool g_has_range = false;
static bool g_has_motor = false;

void data_hub_init(void)
{
    memset(&g_rtk, 0, sizeof(g_rtk));
    memset(&g_range, 0, sizeof(g_range));
    memset(&g_motor, 0, sizeof(g_motor));
    g_has_rtk = g_has_range = g_has_motor = false;
}

static void lock(void)   { taskENTER_CRITICAL(); }
static void unlock(void) { taskEXIT_CRITICAL(); }

void data_hub_set_rtk(const RTKFrame* f){ lock(); g_rtk = *f; g_has_rtk = true; unlock(); }
void data_hub_set_range(const RangeFrame* f){ lock(); g_range = *f; g_has_range = true; unlock(); }
void data_hub_set_motor(const MotorState* s){ lock(); g_motor = *s; g_has_motor = true; unlock(); }

bool data_hub_get_rtk(RTKFrame* out){ lock(); bool ok=g_has_rtk; if(ok)*out=g_rtk; unlock(); return ok; }
bool data_hub_get_range(RangeFrame* out){ lock(); bool ok=g_has_range; if(ok)*out=g_range; unlock(); return ok; }
bool data_hub_get_motor(MotorState* out){ lock(); bool ok=g_has_motor; if(ok)*out=g_motor; unlock(); return ok; }
