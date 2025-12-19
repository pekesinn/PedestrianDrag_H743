#include "safety.h"
static volatile bool g_estop = false;

void safety_init(void){ g_estop = false; }
bool safety_is_estop(void){ return g_estop; }
void safety_estop(void){ g_estop = true; }
