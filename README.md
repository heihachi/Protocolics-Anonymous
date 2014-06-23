Protocolics Anonymous
=====================

## About

This is a application to connect to a server (you compile and control) and send encrypted messages.

Supported Encryption:

- [ ] ClearText (not really encryption)
- [ ] PGP
- [ ] RSA

May add support for other chat networks using Third-Party Software.

## Appication Credits

Name:

* Ashynyuu

Programming:

* Heihachi

Idea: 

* Heihachi

Install Libraries
=================

## Building and Installing ACE on Win32 with MinGW/ MSYS

### Requires network card

Building and installing ACE on MinGW (using codeblocks) uses a mix of a UNIX building process and Win32 configuration files.
Also, as MinGW uses GNU g++, you may want to take a look at the Compiling ACE with GNU g++ section.

You will need the MinGW build tools and libraries, downloable from http://www.mingw.org.
For our build we require the packages MinGW and MSYS.

1. Install the MinGW tools (including the MinGW Development toolkit) into a common directory, say c:/mingw.

2. Install the MSYS tools into a common directory, say c:/msys.

3. Open a MSYS shell. Set your PATH environment variable so your MinGW's bin directory is first:
```bash
% export PATH=/c/mingw/bin:$PATH
```
4. Add an ACE_ROOT environment variable pointing to the root of your ACE wrappers source tree:
```bash
% export ACE_ROOT=/c/work/mingw/ACE_wrappers
```
	* From now on, we will refer to the root directory of the ACE source tree as $ACE_ROOT.

5. Create a file called config.h in the $ACE_ROOT/ace directory that contains:
```C++
#include "ace/config-win32.h"
```
6. Create a file called platform_macros.GNU in the $ACE_ROOT/include/makeinclude directory containing:
```c++
include $(ACE_ROOT)/include/makeinclude/platform_mingw32.GNU
```

	* In the above text, don't replace $(ACE_ROOT) with the actual directory, GNU make will take the value from the environment variable you defined previously.

	* If you lack Winsock 2, add the line

```
winsock2 = 0
```
	before the previous one.

### Optional

If you want to install ACE (using "make install") and want all the .pc files generated, set the installation prefix in platform_macros.GNU.
```
INSTALL_PREFIX=/c/ACE
```
The Following will be installed.

1. Headers -> $INSTALL_PREFIX/include

2. Documentation/Build system files -> $INSTALL_PREFIX/share

3. Libraries -> $INSTALL_PREFIX/lib

With INSTALL_PREFIX set, RPATH will be enabled. To disable RPATH (for example, if $INSTALL_PREFIX/$INSTALL_LIB is already a system-known location for shared libraries), set the make macro install_rpath to 0 by adding install_rpath=0 to platform_macros.GNU.

In the MSYS shell, change to the $ACE_ROOT/ace directory and run make:
```bash
% cd $ACE_ROOT/ace
% make
```

This should create libACE.dll (the Win32 shared library) and libACE.dll.a (the Win32 import library for the DLL). Note that the name for the ACE DLL follows the MinGW convention, which itself resembles UNIX.

If you want static libs also, you may run:
```
% make static_libs_only=1
```

Run make install:
```
% make install
```

This should create ACE.pc to use with pkg-config.

The same rules for Win32 search of DLLs apply for MinGW. If you want to run some ACE programs from the MSYS shell, you may need to add the directory for libACE.dll to your PATH:
```
% export PATH=/c/work/mingw/ACE_wrappers/ace:$PATH
```

Credits to [ACE Library Build and Install Page](http://www.dre.vanderbilt.edu/~schmidt/DOC_ROOT/ACE/ACE-INSTALL.html#mingw)