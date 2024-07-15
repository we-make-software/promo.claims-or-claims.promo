#include <Windows.h>
#include <wdf.h>

VOID EvtDriverContextCleanup(_In_ WDFOBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
}
extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject,_In_ PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);

    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = EvtDriverContextCleanup;
    WDFDRIVER driver;
    WdfDriverCreate(DriverObject, RegistryPath, &attributes, &config, &driver);
    //DoTraceMessage(TRACE_LEVEL_INFORMATION, "Driver loaded successfully.");
    //DoTraceMessage(TRACE_LEVEL_ERROR, "This is an error message.");
    return STATUS_SUCCESS;
}
