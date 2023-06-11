# Event Tracing 

Tracepoints are point in code that act as hooks to call a function that 
we can provide at runtime. 

Event tracing is tracepints which target certain events. 

Tracepoints can be turned on or off during runtime. This allows us to 
debug events in the kernel. 


## How to enable Event tracing 

### Method 1: using 'set_event' interface

1.  To see all the events available for Tracing 
    ```sh
    # cat sys/kernel/tracing/available_events
    ````

1.  To enable a particular event trace 
    ```sh 
    # echo module_load >> /sys/kernel/tracing/set_event
    ```

1.  To disable a particular event trace
    ```sh
    # echo '!sched_wakeup' >> /sys/kernel/tracing/set_event
    ```

### Method 2: using 'enable' toggle

1.  To enable an event trace 
    ```sh 
    # echo 1 > /sys/kernel/tracing/events/sched/sched_wakeup/enable
    ```

2.  To disable an event trace 
    ```sh 
    # echo 0 > /sys/kernel/tracing/events/sched/sched_wakeup/enable
    ```

## How to see trace 

To see the trace run the command `cat /sys/kernel/tracing/trace`

For example: 
I have enabled 2 event traces `module_load` and `module_remove`. `hello_world` 
module was loaded and unloaded twice to test. 

The trace output is 
```sh 
root@syzkaller:~# cat /sys/kernel/tracing/trace
# tracer: nop
#
# entries-in-buffer/entries-written: 8/8   #P:2
#
root@syzkaller:~# watch cat /sys/kernel/tracing/trace
root@syzkaller:~# cat /sys/kernel/tracing/trace
# tracer: nop
#
# entries-in-buffer/entries-written: 13/13   #P:2
#
#                                _-----=> irqs-off/BH-disabled
#                               / _----=> need-resched
#                              | / _---=> hardirq/softirq
#                              || / _--=> preempt-depth
#                              ||| / _-=> migrate-disable
#                              |||| /     delay
#           TASK-PID     CPU#  |||||  TIMESTAMP  FUNCTION
#              | |         |   |||||     |         |
          insmod-250     [000] d....   581.000597: console: module hello_world: .gnu.linkonce.this_module section size must match the kernel's built struct module size at run time
         kauditd-24      [001] d....   581.000635: console: audit: type=1400 audit(1686476508.542:6): avc:  denied  { module_load } for  pid=250 comm="insmod" path="/root/hello-world.ko" dev="sda" ino=16056 scontext=system_u:system_r:kernel_t:s0 tcontext=system_u:object_r:unlabeled_t:s0 tclass=system permissive=1
          insmod-258     [000] d....   651.462871: console: hello_world: loading out-of-tree module taints kernel.
          insmod-258     [000] .....   651.466741: module_load: hello_world O
          insmod-258     [000] d....   651.466766: console: Hello world
          insmod-258     [000] ...1.   651.467500: module_put: hello_world call_site=do_init_module refcnt=1
           rmmod-262     [001] d....   669.718308: console: Bye world
           rmmod-262     [001] .....   669.718828: module_free: hello_world
          insmod-305     [000] .....   893.023502: module_load: hello_world O
          insmod-305     [000] d....   893.023520: console: Hello world
          insmod-305     [000] ...1.   893.023876: module_put: hello_world call_site=do_init_module refcnt=1
           rmmod-331     [001] d....   909.192664: console: Bye world
           rmmod-331     [001] .....   909.193745: module_free: hello_world
```

![event-tracing-output](assets/event-tracing-output.png)
