#include "includes.h"

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT pDriverObject, _In_ PUNICODE_STRING pRegistryPath)
{
    UNREFERENCED_PARAMETER(pDriverObject);
    UNREFERENCED_PARAMETER(pRegistryPath);
    if(!hook_function(&hook_handler, NULL, NULL))
  
    return STATUS_SUCCESS;
}
