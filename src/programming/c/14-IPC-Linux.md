## Process
-   Process is a fundamental unit of execution. 
-   An exe file running can be said as a process.
-   `fork()` is used to create a new child process from the parent process.
-   Each process has independent execution spaces and states.

## Threads
-   Threads are segments of a process.

## `fork()`
-   `fork()` is system call for creating more processes. 
-   When `fork()` is called, parent process makes a copy of itself which is the child process. i.e After `fork()` both parent and child process are running the same code.
-   The return value of the `fork()` is `0` in child process but a +ve integer in parent process. 
-   Using the return value we can make the child and parent process execute different codes.


## IPC 
Inter-process communication is mechanisms to used to communicate, share resources, exchange information between processes.

## Types of IPC in Linux 

1.  Signals - A signal is a notice to a process that an event has occurred
1.  Anonymous Pipes - They offer a one-way data transmission route between processes using `pipe()`
1.  FIFO / Named Pipes - Un-releated process can communicate using a unique named file as a channel for data exchange. uses `mkfifo()`
1.  Message Queues - It allows processes to exchange data in the form of messages to complete their tasks
1.  Shared Memory - Shared memory enables sharing of memory resources across multiple processes. It allows for the rapid and efficient exchange of massive volumes of data between processes.
1.  Semaphores - Semaphores are used for process synchronization and mutual exclusion using atomic opertations such as wait and signal.
1.  FUTEX Locks - Fast Userspace Mutex 
1.  Unix Domain Sockets - Used to communicate between process via sockets