# Char device driver 
Character device driver is similar to the file in linux.  
Character device driver is made to read and write a stream of char data to/from the Hardware device.

The char device contains 3 fundamental kernel data structures.
1. inode
2. file
3. file_operations

### inode
`inode` data structure represents the file internally inside the kernel.

### file 
`file` data structure represents an `opened file` inside the kernel, it is somewhat similar to the file_descriptor that we use in userspace programs.

### file_operations 
`file_operations` data structure contains pointers to the methods(functions) which implement a particular file operation.

for example: open(), close(), read(), write().
