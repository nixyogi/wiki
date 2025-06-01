# Synchronization Methods

-   Kernel is asynchronous and unpredictable hence there is a chance of race conditions and deadlock.
-   Concurrency 
    1.  True concurrency - in Multi-core systems 2 threads are executed on different processors.
    2.  Pseudo-concurrency - One thread is interrupted once its time is over and another thread is given chance to execute.

## Types of Synchronization methods 

1.  Atomic Functions 
    -   Execute in single operation, 
    -   cannot be interrupted, 
    -   if 2 or more operations are requested then one must complete before other executes.
    -   Cannot sleep 
    -   Can be used in or out of process context. 
1.  Spinlocks
    -   Used to protect simultaneous access to same resource due to differing code paths.
    -   Used to execute multiple operations.
    -   If one operation is holding the log, and other operation attempts to access it then the code will spin ( wait ) untill the lock is available again. 
    -   Can be used in or out of process context. 
    -   In interrupt context interrupts should be disabled or blocked. 
    -   Can block but cannot go to sleep. 
1.  Mutexes 
    -   If we want the code to sleep when the resource is not available ( i.e call the scheduler and have it yeild the CPU to another process) we can use mutex. 
    -   We can use `mutex_lock()` only in process context and `mutex_unlock()` should not be used in interrupt context.
1.  Semaphores 
    -   If we want the code to sleep when the resource is not available ( i.e call the scheduler and have it yeild the CPU to another process) we can use semaphores. 
    -   We can use `down()` only in process context. `up()` can be used anytime.
1.  Completion
    -   These can be used in place of semaphores when there are many processors requesting a resource. 
1.  Seqlocks
1.  Read-Copy-Upddate (RCU)

## How to choose the right one ? 

It depends on these factors 
1.  Whether the contention is expected to be high or low. 
1.  Whether one is in or out of process context. 
1.  How many operations have to be performed while the lock is held
1.  Is sleeping permitted or not.
1.  How often the lock needs to be taken. 


## Mutex Vs Semaphore Vs Completion 

Operation | Mutex | Semaphore | Completion
--- | --- | --- | --- 
Structure | struct mutex | struct semaphore | struct completion
Init | mutex_init() | sema_init() | init_completion() 
Lock | mutex_lock() | down() | wait_for_completion()
Unlock | mutex_unlock() | up() | complete()