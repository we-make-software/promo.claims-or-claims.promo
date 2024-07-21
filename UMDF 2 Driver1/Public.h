/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    driver and application

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_UMDF2Driver1,
    0x32e89162,0xbdde,0x4741,0x95,0x18,0x58,0xac,0x46,0xf9,0x1c,0xc7);
// {32e89162-bdde-4741-9518-58ac46f91cc7}
