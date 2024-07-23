#include ".h"

VOID EvtDriverUnload(_In_ WDFDRIVER Driver){
    UNREFERENCED_PARAMETER(Driver);
    DbgPrint("EvtDriverUnload");
}
 NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    WDFDRIVER _WDFDriver;
    {
        WDF_DRIVER_CONFIG config;
        WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);

        // Set the unload event callback.
        config.EvtDriverUnload = EvtDriverUnload;

        // Create the WDF driver object.
        WdfDriverCreate(DriverObject,
            RegistryPath,
            WDF_NO_OBJECT_ATTRIBUTES,
            &config,
            &_WDFDriver);
    }
    DbgPrint("DriverEntry");
    // Additional setup using _WDFDriver can be done here...

    return STATUS_SUCCESS;
}