#include <Windows.h>
#include <wdf.h>
#define WPP_CONTROL_GUIDS \
    WPP_DEFINE_CONTROL_GUID(ServiceDriverTraceGuid, (e7dca253, d060, 4592, 8a67, f3654454367f), \
        WPP_DEFINE_BIT(TRACE_LEVEL_ERROR) \
        WPP_DEFINE_BIT(TRACE_LEVEL_WARNING) \
        WPP_DEFINE_BIT(TRACE_LEVEL_INFORMATION) \
        WPP_DEFINE_BIT(TRACE_LEVEL_VERBOSE))

#define WPP_FLAG_LEVEL_LOGGER(flag, level) \
    WPP_LEVEL_LOGGER(flag)

#define WPP_FLAG_LEVEL_ENABLED(flag, level) \
    (WPP_LEVEL_ENABLED(flag) && WPP_CONTROL(WPP_BIT_ ## flag).Level >= level)
#include ".tmh"
VOID EvtDriverContextCleanup(_In_ WDFOBJECT DriverObject) {
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
}
NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);

    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = EvtDriverContextCleanup;
    WDFDRIVER driver;
    WdfDriverCreate(DriverObject, RegistryPath, &attributes, &config, &driver);
    WPP_INIT_TRACING(RegistryPath->Buffer);
    DoTraceMessage(TRACE_LEVEL_INFORMATION, "Driver loaded successfully.");
    DoTraceMessage(TRACE_LEVEL_ERROR, "This is an error message.");
    return STATUS_SUCCESS;
}
