# Tools and Techniques to Debug an Embedded Linux System

## Process of debugging 

1.  Understand the problem.
2.  Reproduce the problem.
3.  Identify the root cause.
4.  Apply the fix.
5.  Test it. If fixed, celebrate! If not, go back to step 1.

## Types of problems in Software
We can classify them into 5 major categories 

1.  Crash. - Fatal exceptions
2.  Lockup/Hang. - Race conditions, Deadlocks
4.  Logic/implementation. - Logical errors
5.  Resource leakage. - Memory leaks
6.  (Lack of) performance. - Program is not performing as expected.

## Tools & Techniques available for developers to solve these problems

1.  Our brain (aka knowledge).
2.  Post mortem analysis (logging analysis, memory dump analysis, etc).
3.  Tracing/profiling (specialized logging).
4.  Interactive debugging (eg: GDB).
5.  Debugging frameworks (eg: Valgrind).

## Post mortem analysis
This type of analysis is done using the information exported by the system i.e 
logs, memory dumps etc. 

### For Kernel Crashes 

#### Method1: addr2line

1.  Get the address from the memory dump. address of the `pc` (program counter)
    can be used to get the line where kernel crashed.
    ```sh
    [ 17.201436] PC is at storage_probe+0x60/0x1a0
    [ 17.205810] LR is at storage_probe+0x48/0x1a0
    [ 17.210175] pc : [<c06a21cc>] lr : [<c06a21b4>] psr: 60000013
    ```
1.  You need the `vmlinux` file which is in ELF format with debug info 
    ```
    file vmlinux
    vmlinux: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, BuildID[sha1]
    ca2de68ea4e39ca0f11e688a5e9ff0002a9b7733, with debug_info, not stripped
    ```

1.  Run the addr2line command with these inputs 
    ```sh
    addr2line -f -p -e vmlinux 0xc06a21cc
    ```
    This will give you the line number where the kernel crashed. 
    
    for eg: 
    
    storage_probe at /opt/labs/ex/linux/drivers/usb/storage/usb.c:1118

#### Method2: gdb list

1.  Get the function name + offset from the memory dump.
    ```sh
    [ 17.201436] PC is at storage_probe+0x60/0x1a0
    [ 17.205810] LR is at storage_probe+0x48/0x1a0
    [ 17.210175] pc : [<c06a21cc>] lr : [<c06a21b4>] psr: 60000013
    ```
    i.e `storage_probe+0x60`

1.  You need the `vmlinux` file which is in ELF format with debug info 
    ```
    file vmlinux
    vmlinux: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, BuildID[sha1]
    ca2de68ea4e39ca0f11e688a5e9ff0002a9b7733, with debug_info, not stripped
    ```

1.  Run gdb on the vmlinux file, inside gdb run the command 
    ```
    (gdb) list *(storage_probe+0x60)
    ```

    This will show you the line where the kernel crashed.

### For Userspace Crashes 

Use the core dump from the segfault to find the line at which the segfault
occurred.

1.  Set the system limits to unlimited
    ```sh
    # ulimit -c unlimited
    ```
2.  Run the program untill it crashes, the crash will generate a file called
    `core` which contains the core dump. 
3.  Run the gdb on the core file and the program with debug symbols
    ```
    gdb <program-here> -c core
    ```
4.  In gdb run the command `list` to go to the line where the program crashed.
    
    -   `p` to print the specific variables. 

## Tracing 

Tracing is a special form of logging, where data about the state and execution of
a program (or the kernel) is collected and stored for runtime (or later) analysis.

Using print() or printk() statements to log the state and variables is also a 
form of tracing. 

### For kernel crashes 
1.  for kernel tracing we need to configure the kernel tracing options
    ```
    zcat /proc/config.gz | grep TRACER=y
    CONFIG_NOP_TRACER=y
    CONFIG_HAVE_FUNCTION_TRACER=y
    CONFIG_HAVE_FUNCTION_GRAPH_TRACER=y
    CONFIG_CONTEXT_SWITCH_TRACER=y
    CONFIG_GENERIC_TRACER=y
    CONFIG_FUNCTION_TRACER=y
    CONFIG_FUNCTION_GRAPH_TRACER=y
    CONFIG_STACK_TRACER=y
    CONFIG_IRQSOFF_TRACER=y
    CONFIG_SCHED_TRACER=y
    CONFIG_HWLAT_TRACER=y
    CONFIG_OSNOISE_TRACER=y
    CONFIG_TIMERLAT_TRACER=y
    ```

1.  Mount the tracefs into the fs 
    ```sh
    mount -t tracefs tracefs /sys/kernel/tracing/
    ```
1.  Record the traces of the function getting executed
    ```
    trace-cmd record -p function_graph -F <module>/<sysfs trigger to a module>
    ```
1.  Generate the report of the tracing 
    ```
    trace-cmd report > trace.log
    ```

1.  Examine the trace.log to see the traces of the function. 

**Note**: This is dynamic tracing i.e the tracing is enabled at runtime as long 
as the kernel is compiled with the correct configuration. 

### For userspace crashes

#### Method 1: strace 

Using strace we can trace all the system calls the program is running to debug
the program.

Run a userspace program with strace 
```
# strace <program>
```


#### Method 2: Uprobe 

This is used to trace the functions in the program. 

1.  Kernel needs to be configured with the below options 
    ```
    zcat /proc/config.gz | grep CONFIG_UPROBE
    CONFIG_UPROBES=y
    CONFIG_UPROBE_EVENTS=y
    ```
1.  Add the tracepoints to all the functions 
    ```sh
    # for f in `perf probe -F -x <program>`; \
        do perf probe -q -x <program> $f; done
    ```

1.  List the tracepoints to know the tracepoint names
    ```
    # perf probe -l | tee
    ```

1.  Run the application and capture the tracepoints. 
    ```
    # perf record -e <tracepoint_name>:* -aR -- <program> <args>
    ```

1.  Run the command to parse the trace
    ```
    perf script | tee
    ```

## Interactive Debugging 

An interactive debugging tool allows us to interact with the application at runtime.
It can execute the code step-by-step, set breakpoints,
display information (variables, stack, etc), list function call history (backtrace), etc.

GDB is the go to tool for Interactive debugging. 

### For kernel space 

**Note**: If running on embedded, you need a gdbserver running on the target device
and a gdb client on the host device. 

1.  Enable KGDB in the kernel 
    ```
    # zcat /proc/config.gz | grep ^CONFIG_KGDB
    CONFIG_KGDB=y
    CONFIG_KGDB_HONOUR_BLOCKLIST=y
    CONFIG_KGDB_SERIAL_CONSOLE=y
    ```
    KGDB has registered serial console as the port for communication. But we 
    can use kgdb/agent-proxy to forward text console over IP. 

    Details on how to connect can be found here - https://kernel.googlesource.com/pub/scm/utils/kernel/kgdb/agent-proxy/+/refs/heads/master/README.TXT

1.  On target machine, Put the kernel in debugging mode 

    ```sh
    # Enable the serial port for kgdb communication
    # echo ttymxc0 > /sys/module/kgdboc/parameters/kgdboc
    # Put the kernel in debug mode
    # echo g > /proc/sysrq-trigger
    ```

1.  On host machine, run gdb with the kernel ELF 
    ```
     gdb vmlinux -tui
    ```
    -   `-tui` option opens the TUI which shows the code and line number in gdb

1.  In gdb prompt, run the command to connect to the target machine
    ```
    (gdb) target remote localhost:5551
    ```

1.  This will connect and open up the gdb for debugging, now you can set breakpoints
    get backtraces using gdb commands. 


### For userspace crashes

**Note**: If running on embedded, you need a gdbserver running on the target device
and a gdb client on the host device. 

1.  Start the gdbserver, on target device
    ```
    gdbserver :1234 <program>
    ```

2.  On the host device, run gdb with the program in ELF format 
    ```
    gdb <program> -tui
    ```

3.  In gdb prompt, connect to the target device 
    ```
    (gdb) target remote <IP>:1234
    ```

4.  Now we can set breakpoints and see the backtrace of the program running 
    on the target machine.

## Debugging frameworks

Collection of tools when used to debug linux systems are called debugging frameworks. 

Kernel has several debugging frameworks to identify memory leaks,
lockups, etc (see the "Kernel Hacking" configuration menu)

In user space, there is Valgrind for debugging memory leaks, race conditions 
and profiling etc.

### For kernel crashes 

1.  Enable the detections in the kernel configuration 
    ```
    # zcat /proc/config.gz | grep "CONFIG_SOFTLOCKUP_DETECTOR\|CONFIG_DETECT_HUNG_TASK"
    CONFIG_SOFTLOCKUP_DETECTOR=y
    CONFIG_DETECT_HUNG_TASK=y
    ```
1.  Once enabled, when something hangs for 30s or more, kernel will throw an 
    oops. 

1.  After this we can use the steps in post mortem analysis to debug. 

### For userspace crashes

We use valgring to check for memory leaks, profiling , etc

For eg: 
```
valgrind --leak-check=full <program>
```
This will check for leaks etc.. 


## Which tool to use while debugging ? 

This depends on what type of problem you are debugging.

![summary2](assets/which-tool-best-for-debugging.png)

#### References

Ref: https://www.youtube.com/watch?v=Paf-1I7ZUTo 
