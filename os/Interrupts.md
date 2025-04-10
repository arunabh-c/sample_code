The interrupt is a signal emitted by hardware or software when a process or an event needs immediate attention. It alerts the processor to a high-priority process requiring interruption of the current working process. In I/O devices one of the bus control lines is dedicated for this purpose and is called the Interrupt Service Routine (ISR). 

When a device raises an interrupt at let’s say process i, the processor first completes the execution of instruction i. Then it loads the Program Counter (PC) with the address of the first instruction of the ISR. Before loading the Program Counter with the address, the address of the interrupted instruction is moved to a temporary location. Therefore, after handling the interrupt the processor can continue with process i+1. 

While the processor is handling the interrupts, it **must inform the device that its request has been recognized so that it stops sending the interrupt request signal**. Also, **saving the registers so that the interrupted process can be restored in the future**, increases the **delay between the time an interrupt is received and the start of the execution of the ISR. This is called Interrupt Latency**. 
 
 **Hardware Interrupt** : Hardware Interrupt is caused by some hardware device such as request to start an I/O, a hardware failure or something similar. Hardware interrupts were introduced as a way to avoid wasting the processor’s valuable time in polling loops, waiting for external events. 

For example, when an I/O operation is completed such as reading some data into the computer from a tape drive.

1. An interrupt generated by a mouse when a button is clicked
2. An interrupt generated by a network card when data is received
3. An interrupt generated by a disk drive when a read or write operation is completed

All the external devices are connected to a single Interrupt Request Line and the Interrupt Request Line is used for the interrupts.
The hardware interrupts are further categorized into two types:

**Maskable Interrupts**: Hardware interrupts that can be ignored or disabled are called maskable interrupts.
**Non-Maskable interrupts**: Hardware interrupts that can’t be ignored or disabled are called non-maskable interrupts.

**Software Interrupt** : Software Interrupt is invoked by the use of INT instruction. This event immediately stops execution of the program and passes execution over to the INT handler. The INT handler is usually a part of the operating system and determines the action to be taken. It occurs when an application program terminates or requests certain services from the operating system. 

For example, output to the screen, execute file etc. 

1. A system call to read or write data to a file
2. A division by zero exception
3. A page fault exception

| SR.NO.	| Hardware Interrupt	| Software Interrupt|
| --- | --- | --- |
1	| Hardware interrupt is an interrupt generated from an external device or hardware.	| Software interrupt is the interrupt that is generated by any internal system of the computer.
2	| It do not increment the program counter.	| It increment the program counter.
3	| Hardware interrupt can be invoked with some external device such as request to start an I/O or occurrence of a hardware failure.	| Software interrupt can be invoked with the help of INT instruction.
4	| It has lowest priority than software interrupts	| It has highest priority among all interrupts.
5	| Hardware interrupt is triggered by external hardware and is considered one of the ways to communicate with the outside peripherals, hardware.	| Software interrupt is triggered by software and considered one of the ways to communicate with kernel or to trigger system calls, especially during error or exception handling.
6	| It is an asynchronous event.	| It is synchronous event.
7	| Hardware interrupts can be classified into two types they are: 1. Maskable Interrupt. 2. Non Maskable Interrupt.	| Software interrupts can be classified into two types they are: 1. Normal Interrupts. 2. Exception
8	| Keystroke depressions and mouse movements are examples of hardware interrupt.	| All system calls are examples of software interrupts

So following steps are involved while handling the interrupts:

The First step involved in handling the interrupt is to check the priority of the interrupt.
If the priority is low compared to the current process under execution, then the interrupt is saved in the memory.
If the priority is high compared to the current process under execution, CPU saves the context of the current process.
CPU loads the new process which invoked the interrupt and executes that.
On completion of the requested service, CPU loads the process that was under execution prior to the interrupt and resumes the execution from where the execution was interrupted.

Reference: https://www.geeksforgeeks.org/difference-between-hardware-interrupt-and-software-interrupt/#
Reference: https://www.scaler.com/topics/operating-system/interrupts-in-os/


