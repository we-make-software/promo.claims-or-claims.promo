# Welcome to we-make-software.com

Welcome to the we-make-software.com project repository on GitHub! This platform is dedicated to hosting open-source projects primarily developed in C. Our goal is to foster collaboration, showcase software development processes, and encourage learning among contributors.

## [LESSON 1: Understanding WDF Development](https://www.facebook.com/share/p/StRA3FKjebzdCWTd/)

## [LESSON 2: DRIVERENTRY](https://www.facebook.com/share/p/7x2f6caEv7hHCjbz/)

### [LESSON 2.1: GOODBYE PDRIVER_OBJECT](https://www.facebook.com/share/p/id8vmWV2dRH2Pdqx/)

### [LESSON 2.2: PUNICODE_STRING RegistryPath - Good Old Friend](https://www.facebook.com/share/p/iZcx8jyfi7KweDw9/)

### [LESSON 2.3: WdfDriverCreate](https://www.facebook.com/share/p/6y53Foae6VviLG8R/)

### [LESSON 2.4: extern "C" in UMDF](https://www.facebook.com/share/p/UsirSBFyokajNbrQ/)

## [LESSON 3: TRACING](https://www.facebook.com/share/p/tpfY4taE6JvVkYMb/)

## [LESSON 4: KMDF - EVT_WDF_DRIVER_DEVICE_ADD](https://www.facebook.com/share/p/h8A9rRCYshGzAAUT/)

## [LESSON 5: WDF_DRIVER_CONFIG](https://www.facebook.com/share/p/Z1vFkaFxHbfaU5Jk/)

### [LESSON 5.1: WDF_DRIVER_CONFIG_INIT](https://www.facebook.com/share/p/ikVcPXTz9W4FSnYM/)

### [LESSON 5.2: EVTDRIVERUNLOAD](https://www.facebook.com/share/p/jzWZFe8iRxCAJS6R/)

#### [LESSON 5.2.1: WDFDRIVER](https://www.facebook.com/share/p/9Vim2ke2YujJAztE/)

### [LESSON 5.3: DriverInitFlags](https://www.facebook.com/share/p/tMnD5FHGLC4N17fL/)

## [LESSON 6: WDF_OBJECT_ATTRIBUTES](https://www.facebook.com/share/p/xZwF8o3ZW9bgff3r/)

### [LESSON 6.1: EvtDriverContextCleanup](https://www.facebook.com/share/p/MZKBUADsBDUFgL2x/)

#### [LESSON 6.1.1: WDFOBJECT](https://www.facebook.com/share/p/2zTJzviUEZKuHJv6/)

### [LESSON 6.2: PFN_WDF_OBJECT_CONTEXT_DESTROY](https://www.facebook.com/share/p/5HoYmT44GXndxKxH/)

#### [LESSON 6.2.1: WDFOBJECT](https://www.facebook.com/share/p/BYX9cDFs3YKyXHBH/)

### [LESSON 7: WDFDRIVER](https://www.facebook.com/share/p/VEqZ95VSSMKV9cci/)

## [LESSON 8: NTSTATUS](https://www.facebook.com/share/p/QdcpQ5tQnoadQmsu/)

## [LESSON 9: UMDF Header](https://www.facebook.com/share/p/ZHwaNa7YXbrjyPh6/)

## [LESSON 10: KMDF Header](https://www.facebook.com/share/p/VtdFgpx6fThhhsKS/)

## [LESSON 11: INF](https://www.facebook.com/share/p/wW5vvWhAdDHzpu72/)

In Lesson 11 of our Informatics (INF) course, we delve into the essential frameworks for Windows driver development: UMDF (User-Mode Driver Framework) and KMDF (Kernel-Mode Driver Framework). 

This lesson covers the basics of these frameworks, how they operate, and their importance in developing reliable and efficient drivers.
We'll explore key concepts such as user-mode and kernel-mode operations, driver models, and the advantages of using UMDF and KMDF. 

By the end of this lesson, you'll have a solid understanding of driver development fundamentals and be ready to apply these frameworks in real-world scenarios. Stay tuned for more exciting insights into the world of Informatics!

Sure, here is the corrected and clearer version of your text:

## [LESSON 11.1: INF(Version)](https://www.facebook.com/share/p/6NkaJz3jWjJez81J/)
A member asked me to make it easier to understand.

This [link](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk) is the easiest way to start creating KMDF and UMDF drivers.

First, we create two empty projects named "WMS Operating System Connection" as UMDF2 and "WMS System" as KMDF.

Delete the default content inside each INF file.

We are going to rewrite the content of these INF files so we understand them better.

When Windows begins an installation, it will look inside the INF file. First, it looks for the version information, so we need to include the [Version] section at the beginning of the INF file. 
After that, we need to provide some properties
 
 ## [LESSON 11.2: INF(Version.Signature)](https://www.facebook.com/share/p/5gRiXj37pLVxJ77A/)
The first property is `Signature`. There are two options: `$Windows NT$` and `$Chicago$`.

By default, Windows uses `$Windows NT$`. 

I’m not sure why Microsoft chose this, but it has become the standard. 

Here’s what the INF file will look like with the `$Windows NT$` property: 

```inf
[Version]
Signature = "$Windows NT$"
```


## [LESSON 11.3: INF (Version.Class & Version.ClassGuid)](https://www.facebook.com/share/p/VLABxftCVSUa1GJ7/)

In Windows, we have `Class` and `ClassGuid`. I don’t know why Windows has made these two properties, but it seems like they want you to confirm what you're making.

The values can be different depending on what you want to create. Use this link to find the appropriate values: [System-Defined Device Setup Classes Available to Vendors](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors).

For example, I’m going to use the `System` class:

```inf
Class = System
ClassGuid = {4d36e97d-e325-11ce-bfc1-08002be10318}
```

To open Device Manager, you can use the following command: `devmgmt.msc` in the Run dialog (press **Windows + R** to open the Run command). When you open Device Manager, you can see most of the devices listed there.


##  [LESSON 11.3: INF (Version.Provider)](https://www.facebook.com/share/p/ziRdbMtMjq5sVE8B/)

The `Provider` property is required because it tells Windows who the provider of the driver is.

In this case, I just set the provider to "we-make-software.com":

```inf
Provider = "we-make-software.com"
```
##  [LESSON 11.4: INF (Version.CatalogFile)](https://www.facebook.com/share/p/ANy9Vuw7qhVzYFMP/)
What is a CatalogFile?

A `CatalogFile` in an INF file specifies a digitally signed catalog file containing cryptographic hashes of all files in the driver package. It ensures the integrity and authenticity of the driver package by verifying that files have not been tampered with.

Why Use CatalogFile in INF?

- **Security**: Prevents installation of tampered or malicious drivers.
- **Trust**: Confirms the driver comes from a legitimate source.
- **Compliance**: Often required for WHQL certification.

 Example:

```inf
[Version]
Signature = "$Windows NT$"
Class = System
ClassGuid = {4d36e97d-e325-11ce-bfc1-08002be10318}
Provider = "we-make-software.com"
CatalogFile = mydriver.cat
```

Architecture-Specific Catalog Files

The `CatalogFile` directive can be specified for different architectures to ensure compatibility and proper verification across various system types. This is the default way to ensure the driver is verified on all supported platforms. The directives look like this:

```inf
CatalogFile.nt=unique-filename.cat
CatalogFile.ntx86=unique-filename.cat
CatalogFile.ntia64=unique-filename.cat
CatalogFile.ntamd64=unique-filename.cat
CatalogFile.ntarm=unique-filename.cat
CatalogFile.ntarm64=unique-filename.cat
```

These directives allow different catalog files to be specified for different system architectures, ensuring the driver package is correctly verified on all supported platforms.

For more detailed information, refer to the [INF Version Section](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-version-section) page on the Microsoft documentation website.

##  [LESSON 11.5: INF (Version.DriverVer)](https://www.facebook.com/share/p/vu1KwdVRRfRS4RVW/)

What is DriverVer?

The `DriverVer` directive in an INF file specifies the driver version and the date of the driver package. This information helps Windows determine the version of the driver and whether it is newer than an existing driver installed on the system.

Why Use DriverVer in INF?

- **Version Control**: Helps in managing different versions of the driver.
- **Installation Decisions**: Windows uses the `DriverVer` date and version number to decide if the driver being installed is newer than the existing one.
- **Compliance**: Ensures that driver packages meet the requirements for proper versioning and updates.

Example:

Here is how the `DriverVer` directive looks in an INF file:

```inf
[Version]
Signature = "$Windows NT$"
Class = System
ClassGuid = {4d36e97d-e325-11ce-bfc1-08002be10318}
Provider = "we-make-software.com"
CatalogFile = mydriver.cat
DriverVer=31/12/2030,1.0.0.0
```

In this example:
- `07/01/2023` is the date when the driver was created or last updated.
- `1.0.0.0` is the version number of the driver.

Importance of DriverVer:

1. **Update Management**: Ensures that the latest driver version is installed, which can include important updates and fixes.
2. **Compatibility**: Helps in maintaining compatibility with various versions of Windows by specifying exact versioning.
3. **Troubleshooting**: Assists in troubleshooting by providing clear version information.

Further Reading:

For more detailed information about the `DriverVer` directive and how it is used in INF files, refer to the [INF Version Section](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-version-section) page on the Microsoft documentation website.


##  [LESSON 11.6: INF (Version.PnpLockDown)](https://www.facebook.com/share/p/AZmDveoQyGGTcMHg/)
What is PnpLockDown?

The `PnpLockDown` directive in an INF file is used to enhance the security of Plug and Play (PnP) device installations by restricting the installation and updating of certain drivers to only those that have been signed by a trusted certificate. This ensures that only verified and trusted drivers can be installed, reducing the risk of malicious or unstable drivers being used on the system.

Why Use PnpLockDown in INF?

- **Security**: Ensures that only drivers signed by a trusted certificate are installed, protecting the system from potentially harmful drivers.
- **Control**: Gives administrators the ability to lock down the installation process, ensuring compliance with organizational policies.
- **Integrity**: Maintains the integrity of the system by preventing unauthorized or unverified drivers from being installed or updated.

Example:

Here is an example of how the `PnpLockDown` directive might be used in an INF file:

```inf
[Version]
Signature = "$Windows NT$"
Class = System
ClassGuid = {4d36e97d-e325-11ce-bfc1-08002be10318}
Provider = "we-make-software.com"
CatalogFile = mydriver.cat
DriverVer = 07/01/2023,1.0.0.0
PnpLockDown = 1
```

In this example:
- `PnpLockDown = 1` enables the lockdown feature, ensuring that only signed drivers from a trusted source can be installed.

Importance of PnpLockDown:

1. **Enhanced Security**: By locking down the PnP process, it minimizes the risk of installing unsigned or malicious drivers.
2. **Compliance**: Helps organizations adhere to security policies by enforcing strict driver installation rules.
3. **System Integrity**: Prevents unauthorized changes to the driver setup, maintaining the system’s stability and reliability.

Further Reading:

For more detailed information about the `PnpLockDown` directive and how it is used in INF files, refer to the [INF Version Section](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-version-section) page on the Microsoft documentation website.


## Overview

we-make-software.com provides a platform for developers to collaborate on open-source projects in the C programming language. Whether you're new to programming or an experienced developer, this repository welcomes all contributions that align with our goal of promoting software development excellence.


## WMS Operating System Connection

"WMS Operating System Connection" is a UMDF2 (User-Mode Driver Framework version 2) project designed to interface with the operating system. 
The project is developed under the acronym "WMS," which stands for "We Make Software." 
This driver operates in user mode, providing enhanced system stability and security by isolating driver operations from the kernel mode.

## WMS System

"WMS System" is a Kernel-Mode Driver Framework (KMDF) project designed to provide efficient and reliable communication with the Windows Operating System. 
This driver operates in kernel mode, enabling it to perform high-performance and low-level operations.

### Features

- **Collaboration:** Engage with fellow developers on C-based open-source projects.
- **Learning:** Explore best practices and techniques in C programming.

## License

This project is licensed under the MIT License. See the details below for licensing terms and conditions:

### MIT License

MIT License

Copyright (c) 2024 we-make-software.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Community

Join our community on [Facebook](https://www.facebook.com/groups/promoclaimsorclaimspromo/) to engage in discussions, share ideas, and collaborate on C projects.

## Contact

For questions or suggestions about the project, feel free to contact us through our [Facebook group](https://www.facebook.com/groups/promoclaimsorclaimspromo/).

Thank you for your interest in we-make-software.com! Happy coding!
