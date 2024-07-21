#pragma once
#include <Windows.h>
#include <wdf.h>
DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_UNLOAD EvtDriverUnload;