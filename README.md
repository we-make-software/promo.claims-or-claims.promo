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

## [LESSON 11: INF]

In Lesson 11 of our Informatics (INF) course, we delve into the essential frameworks for Windows driver development: UMDF (User-Mode Driver Framework) and KMDF (Kernel-Mode Driver Framework). 

This lesson covers the basics of these frameworks, how they operate, and their importance in developing reliable and efficient drivers.
We'll explore key concepts such as user-mode and kernel-mode operations, driver models, and the advantages of using UMDF and KMDF. 

By the end of this lesson, you'll have a solid understanding of driver development fundamentals and be ready to apply these frameworks in real-world scenarios. Stay tuned for more exciting insights into the world of Informatics!

Sure, here is the corrected and clearer version of your text:

## [LESSON 11.1: INF(Version)]
A member asked me to make it easier to understand.

This [link](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk) is the easiest way to start creating KMDF and UMDF drivers.

First, we create two empty projects named "WMS Operating System Connection" as UMDF2 and "WMS System" as KMDF.

Delete the default content inside each INF file.

We are going to rewrite the content of these INF files so we understand them better.

When Windows begins an installation, it will look inside the INF file. First, it looks for the version information, so we need to include the [Version] section at the beginning of the INF file. 
After that, we need to provide some properties
 
 ## [LESSON 11.2: INF(Version.Signature)]
The first property is `Signature`. There are two options: `$Windows NT$` and `$Chicago$`.

By default, Windows uses `$Windows NT$`. 

I’m not sure why Microsoft chose this, but it has become the standard. 

Here’s what the INF file will look like with the `$Windows NT$` property:

```inf
[Version]
Signature = "$Windows NT$"
```





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
