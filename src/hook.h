#include "includes.h"

/*
  @description hook function for driver communication
  @param hook_func: Function to hook
  @param debugEAC: Debug EAC
  @param debugBE: Debug BE
*/
BOOL WINAPI hook_function(void* hook_func, BOOL debugEAC, BOOL debugBE);

// handle hook
void hook_handler();
