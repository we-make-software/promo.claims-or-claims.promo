#include <ntddk.h>
#include <wdf.h>
NTSTATUS EvtDriverDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit) {
    WDFDEVICE device;
    UNREFERENCED_PARAMETER(Driver);
    DbgPrint("WDF Driver Device Add\n");
    return WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &device);
}
VOID EvtDriverUnload(_In_ WDFDRIVER Driver) {
    UNREFERENCED_PARAMETER(Driver);
    DbgPrint("Upgrade to WDF DriverUnload\n");
}
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    DbgPrint("WMSHardwareBinding Driver Loaded\n");
    WDF_DRIVER_CONFIG_INIT(&config, EvtDriverDeviceAdd); 
    config.EvtDriverUnload = EvtDriverUnload; 
    return  WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);;
}