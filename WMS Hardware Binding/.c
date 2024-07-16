#include <ntddk.h>
#include <wdf.h>
NTSTATUS EvtWdfDriverDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit) {
    UNREFERENCED_PARAMETER(Driver);
    UNREFERENCED_PARAMETER(DeviceInit);

    return STATUS_SUCCESS;
}
VOID EvtDestroyCallback(_In_ WDFOBJECT Object) {
    UNREFERENCED_PARAMETER(Object);
}

VOID EvtCleanupCallback(_In_ WDFOBJECT Object) {
    UNREFERENCED_PARAMETER(Object);
}
VOID EvtDriverUnload(_In_ WDFDRIVER Driver) {
    UNREFERENCED_PARAMETER(Driver);
}
DRIVER_INITIALIZE DriverEntry;
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, EvtWdfDriverDeviceAdd);
    config.EvtDriverUnload = EvtDriverUnload;

    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = EvtCleanupCallback;
    attributes.EvtDestroyCallback = EvtDestroyCallback;
    WDFDRIVER driver;
    WdfDriverCreate(DriverObject, RegistryPath, &attributes, &config, &driver);
    return STATUS_SUCCESS;
}
