# How to use syzkaller 

Syzkaller is an unsupervised kernel fuzzer that uses both structured fuzzing &
coverage-guided fuzzing techniques to apply fuzzing to kernel syscalls.

## How it works
![manager]()

Manager controls the test system, spwans vm's with fuzzers inside them
which generate small programs which invoke syscalls. 

VM's communication using RPC and log the coverage achieved and trace information
which is stored in the database. 

## Describing syscalls 

Syzkaller has a separate language for Describing syscalls. 

For example: the open() syscall below  

```cpp
int open(const char *pathname, int flags, mode_t mode);
```
is described in syzkaller as: 

```sh
open(file ptr[in, filename], flags flags[open_flags], mode flags[open_mode]) fd
```

-   `file ptr[in, filename]`: the first argument, called file, is an input pointer 
    containing a filename string.
-   `flags flags[open_flags]`: the flags argument is any of the flags defined at 
    open_flags array open_flags = O_WRONLY, O_RDWR, O_APPEND, ...
-   `mode flags[open_mode]`: mode argument is any of the flags defined at 
    open_mode array open_mode = S_IRUSR, S_IWUSR, S_IXUSR, ...
-   `fd`: the return value will be stored here, to be later used on other 
    syscalls.

    for example: 
    ```
    read(fd fd, buf buffer[out], count len[buf])
    write(fd fd, buf buffer[in], count len[buf])
    ```

If instead of fd (file descriptior) we want to fuzz integer values from 0 to 500
then we use syntax `int64[0:500]`

syzkaller provides generic descrption for `ioctl()`
```
ioctl(fd fd, cmd intptr, arg buffer[in])
```
and also provides specific ones like 
```
ioctl$DRM_IOCTL_VERSION(fd fd_dri, cmd const[DRM_IOCTL_VERSION], arg ptr[in, drm_version])
ioctl$VIDIOC_QUERYCAP(fd fd_video, cmd const[VIDIOC_QUERYCAP], arg ptr[out, v4l2_capability])
```

See the refernce below for more. 

Ref: https://github.com/google/syzkaller/blob/master/docs/syscall_descriptions_syntax.md

## Setting up syzkaller 

Follow the steps given here to setup syzkaller - https://github.com/google/syzkaller/blob/master/docs/linux/setup.md

Tips for running syzkaller
1.  Use different defconfigs 
2.  Limit the syscalls to 3-4 chosen, by adding the below in config.config
    ```
    "enable_syscalls": [ "ptrace", "getpid" ],
    ```
    
## 
