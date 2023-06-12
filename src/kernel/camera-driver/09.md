## Hello world example of the camera driver 
1. module init 
2. module exit 

## Application programming Vs Module programming 
Application programming is sequential and kernel module programming is concurrent.
Application programming may not be event based. Kernel programming is mostly event based and on request basis.

Kernel programming has init and exit functions which is used to inform the kernel about the capabilities of the kernel module. Application has no such thing.

Error in kernel modules can crash the whole OS. Error in Application does not harm the os.

Application programming has different libraries which can be used to do many things. Kernel programming has no libraries.
