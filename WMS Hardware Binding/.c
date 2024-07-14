#include <ntddk.h>
#include <wdf.h>
#define WPP_CONTROL_GUIDS \
    WPP_DEFINE_CONTROL_GUID(ServiceDriverTraceGuid, (3633d7e5, a77e, 4469, 9f1b, 816bfba66a5e), \
        WPP_DEFINE_BIT(TRACE_LEVEL_ERROR) \
        WPP_DEFINE_BIT(TRACE_LEVEL_WARNING) \
        WPP_DEFINE_BIT(TRACE_LEVEL_INFORMATION) \
        WPP_DEFINE_BIT(TRACE_LEVEL_VERBOSE))

#define WPP_FLAG_LEVEL_LOGGER(flag, level) \
    WPP_LEVEL_LOGGER(flag)

#define WPP_FLAG_LEVEL_ENABLED(flag, level) \
    (WPP_LEVEL_ENABLED(flag) && WPP_CONTROL(WPP_BIT_ ## flag).Level >= level)
#include ".tmh"

NTSTATUS EvtWdfDriverDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit) {

    return STATUS_SUCCESS;
}
VOID EvtDriverCleanup(_In_ WDFOBJECT DriverObject) {
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
}
DRIVER_INITIALIZE DriverEntry;
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, EvtWdfDriverDeviceAdd);
    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = EvtDriverCleanup;
    WDFDRIVER driver;
    WdfDriverCreate(DriverObject, RegistryPath, &attributes, &config, &driver);
    WPP_INIT_TRACING(DriverObject, RegistryPath);
    return STATUS_SUCCESS;
}
