#include "hook.h"

BOOL WINAPI hook_function(void* hook_func, BOOL debugEAC, BOOL debugBE)
{
   PVOID* function = reinterpret_cast<PVOID*>(get_system_module_export("\\SystemRoot\\System32\\drivers\\dxgkrnl.sys",
																		"NtDxgkGetTrackedWorkloadStatistics"));
  
   unsigned char func[] = {   0x54, 0x48, 0x89, 0xCC, 0x59, 0x48, 0x8B, 
                              0x44, 0x24, 0x05, 0x48, 0x89, 0xE0, 0x5C, 0xC3 
                          }; 
  
   unsigned char shell_code_begin[] = { 0x68 };
   unsigned char shell_code_end[] = { 0xC3 };
  
   RtlSecureZeroMemory(&func, sizeof(func));
   memcpy((PVOID)((ULONG_PTR)func), &shell_code_begin, sizeof(shell_code_begin));
   uintptr_t hook_address = reinterpret_cast<uintptr_t>(hook_func);
   memcpy((PVOID)((ULONG_PTR)func + sizeof(shell_code_begin)), &hook_address, sizeof(void*));
   memcpy((PVOID)((ULONG_PTR)func + sizeof(shell_code_begin) + sizeof(void*)), &shell_code_end, sizeof(shell_code_end));

   write_to_protected_memory(function, &func, sizeof(func));
  
   return TRUE;
}

NTSTATUS hook_handler(PVOID params)
{
    INSTRUCTIONS* instructions = (INSTRUCTIONS*)params;
  
    switch(instructions->opcode)
    {
      case 1: // write mem
        
      case 2: // read mem
         
      case 3: // draw rect
        
      case 4: // draw rect filled
      
      case 5: // draw text
        
      case 6: // draw line
      
      case 7: // write no-op
        
      default:
        break;
    }
  
    return STATUS_SUCCESS;
}
