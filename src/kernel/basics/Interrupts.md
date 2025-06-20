## Interrupts 

-   An interrupt is a signal to the processor that an event has occurred which needs to be dealt with. 
-   Interrupts alter the sequence of instructions followed by the processor. 
-   When an interrupt arrives, the kernel must suspend the current thread and deal with the interrupt, by calling a **serivce routine (ISR) or handler**. 
-   Once the ISR is run the kernel can resume the thread. 

There are 2 different kinds of interrupts 
1.  Synchronous : Also called Exceptions, generated by CPU due to runtime errors in program. This causes a signal to be sent to one or more processes. 
    1.  Processor detected exceptions: Faults, Traps, Aborts 
    2.  Programmed exceptions: Requested by a process through instructions. 
2.  Asynchronous 
    1.  Maskable interrupts: These can be disabled by flags. 
    2.  Non-Maskable interrupts: These cannot be disabled and usually occur on critical hardware failure.

-   On ARM there is IRQ (Interrupt ReQuest) and FIQ(Fast IRQ) lines. IRQ line is sent through Generic Interrupt Controller (GIC)
-   The GIC performs the critical tasks of interrupt management, prioritization, and routing. 
-   Interrupts can be Level triggered and Edge triggered.  
-   On Multi-core systems (SMP) by default interrupts may be serviced on any available CPU. Affinities can be assigned to a particular CPU. 


## Top and Bottom Halves