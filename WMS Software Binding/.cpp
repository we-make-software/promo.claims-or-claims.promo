#include <Windows.h>
#include <wdf.h>

VOID EvtCleanupCallback(_In_ WDFOBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
}
VOID EvtDriverUnload(_In_ WDFDRIVER Driver) {

}
extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject,_In_ PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);
    config.EvtDriverUnload = EvtDriverUnload;
    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = EvtCleanupCallback;
    WDFDRIVER driver;
    WdfDriverCreate(DriverObject, RegistryPath, &attributes, &config, &driver);
    //DoTraceMessage(TRACE_LEVEL_INFORMATION, "Driver loaded successfully.");
    //DoTraceMessage(TRACE_LEVEL_ERROR, "This is an error message.");
    return STATUS_SUCCESS;
}
