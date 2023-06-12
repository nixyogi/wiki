# Kernel and its components 
Linux kernel can be divided into these components 
1. Process Management - Process communication, scheduling etc..
2. Memory Management - Allocation of memory and virtual addresses and conversion of virtual addresses into physical addresses
3. Filesystems - Linux depens upon filesystems for operations because everything is a file in Linux.
4. Device Control -  Almost every system operation (system call) maps to a physical device.(with the exception on some devices like memory, processor etc.) We need some code to manage all of these devices, this particular code is called as device driver.
5. Networking - Routing, packet collection, identification and dispatching is done inside the kernel.

# Device Driver 
Software Code which maps operating system operations to physical device operations.

### Classes of devices and modules 
The 3 classes are:
1. `char device` - devices which can be represented as a stream of bytes.
2. `block device` - devices which can host an entire filesystem and can transfer one or more blocks at one time (512 bytes).
3. `network device` - device which is able to exchange data with other devices

### Role of a device driver:
Any computer program can be divided into 2 parts 
1) Mechanism - Actual implementation of a particular task
2) Policy - How such tasks can be used to create different applications

The Role of the device driver is to provide Mechanism for hardware.
OR
Expose all functionality provided by the Hardware to the user.
