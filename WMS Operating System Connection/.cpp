#include ".h"
VOID EvtDriverUnload(_In_ WDFDRIVER Driver){
    
}
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);
    config.EvtDriverUnload = EvtDriverUnload;

    NTSTATUS status;



    status = WdfDriverCreate(DriverObject,
        RegistryPath,
        WDF_NO_OBJECT_ATTRIBUTES,
        &config,
        WDF_NO_HANDLE);
    if (!NT_SUCCESS(status))
    {
        KdPrint(("WdfDriverCreate failed with status 0x%x\n", status));
    }

    return status;
}