# x86_64 kernel

This is a kernel build with C and x86_64 assembley. This project made with docker. In Windows better to use cmd.

## How to build environment

You need to have docker installed.

Command:

- Any: docker build buildenv -t myos-buildenv

Or run:

- Windows: builddocker_win.bat
- Linux/MacOS: builddocker.bat

## How run docker

You need to have build environment complete.

Command:

- Windows(PowerShell): docker run --rm -it -v "${pwd}:/root/env" myos-buildenv
- Windows(CMD): docker run --rm -it -v "%cd%":/root/env myos-buildenv
- Linux/MacOS: docker run --rm -it -v "$(pwd)":/root/env myos-buildenv

Or run:

- Windows: rundocker_win.bat
- Linux/MacOS: rundocker.bat

## How to build iso

You need to enter build environment first.

Command:

- Build environment: make

## How to run iso

You need to have qemu installed.

Command:

- Any: qemu-system-x86_64 -cdrom dist/kernel.iso

Or run:

- Windows: rqemu_win.bat
- Linux/MacOS: rqemu.sh