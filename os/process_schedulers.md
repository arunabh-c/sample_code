# Process Scheduler
Process scheduling is the activity of the process manager that handles the removal of the running process from the CPU and the selection of another process based on a particular strategy. 
Process scheduling is an essential part of a Multiprogramming operating system. Such operating systems allow more than one process to be loaded into the executable memory at a time and the loaded process shares the CPU using time multiplexing.

# Types of Process Schedulers
## Long Term or Job Scheduler
Brings the new process to the ‘Ready State’. It controls the Degree of Multi-programming, i.e., the number of processes present in a ready state at any point in time. It is important that the long-term scheduler make a careful selection of both I/O and CPU-bound processes. 
I/O-bound tasks are which use much of their time in input and output operations while CPU-bound processes are which spend their time on the CPU. The job scheduler increases efficiency by maintaining a balance between the two. They operate at a high level and are typically used in batch-processing systems.

## Short-Term or CPU Scheduler
Responsible for selecting one process from the ready state for scheduling it on the running state. Note: Short-term scheduler only selects the process to schedule it doesn’t load the process on running.  Here is when all the scheduling algorithms are used. The CPU scheduler is responsible for ensuring no starvation due to high burst time processes.

    ### Dispatcher
    Responsible for loading the process selected by the Short-term scheduler on the CPU (Ready to Running State) Context switching is done by the dispatcher only. A dispatcher does the following: 
    1. Switching context.
    2. Switching to user mode.
    3. Jumping to the proper location in the newly loaded program.

## Medium-Term Scheduler
Responsible for suspending and resuming the process. It mainly does swapping (moving processes from main memory to disk and vice versa). Swapping may be necessary to improve the process mix or because a change in memory requirements has overcommitted available memory, requiring memory to be freed up. It is helpful in maintaining a perfect balance between the I/O bound and the CPU bound. It reduces the degree of multiprogramming.

## Comparison
| Long Term Scheduler	| Short term schedular	| Medium Term Scheduler |
| --- | --- | --- | 
| It is a job scheduler	| It is a CPU scheduler	| It is a process-swapping scheduler |
| Generally, Speed is lesser than short term scheduler	| Speed is the fastest among all of them	| Speed lies in between both short and long-term schedulers |
| It controls the degree of multiprogramming	| It gives less control over how much multiprogramming is done | It reduces the degree of multiprogramming |
| It is barely present or nonexistent in the time-sharing system	| It is a minimal time-sharing system	| It is a component of systems for time sharing |
| It can re-enter the process into memory, allowing for the continuation of execution | It selects those processes which are ready to execute	| It can re-introduce the process into memory and execution can be continued |

# Other types of Process Schedulers
## I/O schedulers: 
I/O schedulers are in charge of managing the execution of I/O operations such as reading and writing to discs or networks. They can use various algorithms to determine the order in which I/O operations are executed, such as FCFS (First-Come, First-Served) or RR (Round Robin).
## Real-time schedulers: 
In real-time systems, real-time schedulers ensure that critical tasks are completed within a specified time frame. They can prioritize and schedule tasks using various algorithms such as EDF (Earliest Deadline First) or RM (Rate Monotonic).

# Context Switching
For a process execution to be continued from the same point at a later time, context switching is a mechanism to store and restore the state or context of a CPU in the Process Control block. A context switcher makes it possible for multiple processes to share a single CPU using this method. A multitasking operating system must include context switching among its features.

The state of the currently running process is saved into the process control block when the scheduler switches the CPU from executing one process to another. The state used to set the computer, registers, etc. for the process that will run next is then loaded from its own PCB. After that, the second can start processing.

Reference: https://www.geeksforgeeks.org/process-schedulers-in-operating-system/

# Process Control Block & Process Table
While creating a process, the operating system performs several operations. To identify the processes, it assigns a **process identification number (PID)** to each process. As the operating system supports multi-programming, it needs to keep track of all the processes. For this task, the process control block (PCB) is used to track the process’s execution status. Each block of memory contains information about the process state, program counter, stack pointer, status of opened files, scheduling algorithms, etc.

All this information is required and must be saved when the process is switched from one state to another. When the process makes a transition from one state to another, the operating system must update information in the process’s PCB. A process control block (PCB) contains information about the process, i.e. registers, quantum, priority, etc. The process table is an array of PCBs, that means logically contains a PCB for all of the current processes in the system.

![Proces Control Block](process-table.jpg)

1. **Pointer**: It is a stack pointer that is required to be saved when the process is switched from one state to another to retain the current position of the process.
2. **Process state**: It stores the respective state of the process.
3. **Process number**: Every process is assigned a unique id known as process ID or PID which stores the process identifier.
4. **Program counter**: It stores the counter,: which contains the address of the next instruction that is to be executed for the process.
5. **Register**: These are the CPU registers which include the accumulator, base, registers, and general-purpose registers.
6. **Memory limits**: This field contains the information about memory management system used by the operating system. This may include page tables, segment tables, etc.
7. **Open files list** : This information includes the list of files opened for a process.

## Additional Aspects
1. **Interrupt handling**: The PCB also contains information about the interrupts that a process may have generated and how they were handled by the operating system.
2. **Real-time systems**: Real-time operating systems may require additional information in the PCB, such as deadlines and priorities, to ensure that time-critical processes are executed in a timely manner.
3. **Virtual memory management**: The PCB may contain information about a process’s virtual memory management, such as page tables and page fault handling.
4. **Inter-process communication**: The PCB can be used to facilitate inter-process communication by storing information about shared resources and communication channels between processes.
5. **Fault tolerance**: Some operating systems may use multiple copies of the PCB to provide fault tolerance in case of hardware failures or software errors.

## Advantages
1. **Efficient process management**: The process table and PCB provide an efficient way to manage processes in an operating system. The process table contains all the information about each process, while the PCB contains the current state of the process, such as the program counter and CPU registers.
2. **Resource management**: The process table and PCB allow the operating system to manage system resources, such as memory and CPU time, efficiently. By keeping track of each process’s resource usage, the operating system can ensure that all processes have access to the resources they need.
3. **Process synchronization**: The process table and PCB can be used to synchronize processes in an operating system. The PCB contains information about each process’s synchronization state, such as its waiting status and the resources it is waiting for.
4. **Process scheduling**: The process table and PCB can be used to schedule processes for execution. By keeping track of each process’s state and resource usage, the operating system can determine which processes should be executed next.

## Disadvantages
1. **Overhead**: The process table and PCB can introduce overhead and reduce system performance. The operating system must maintain the process table and PCB for each process, which can consume system resources.
2. **Complexity**: The process table and PCB can increase system complexity and make it more challenging to develop and maintain operating systems. The need to manage and synchronize multiple processes can make it more difficult to design and implement system features and ensure system stability.
3. **Scalability**: The process table and PCB may not scale well for large-scale systems with many processes. As the number of processes increases, the process table and PCB can become larger and more difficult to manage efficiently.
4. **Security**: The process table and PCB can introduce security risks if they are not implemented correctly. Malicious programs can potentially access or modify the process table and PCB to gain unauthorized access to system resources or cause system instability.
5. **Miscellaneous accounting and status data**: This field includes information about the amount of CPU used, time constraints, jobs or process number, etc. The process control block stores the register content also known as execution content of the processor when it was blocked from running. This execution content architecture enables the operating system to restore a process’s execution context when the process returns to the running state. When the process makes a transition from one state to another, the operating system updates its information in the process’s PCB. The operating system maintains pointers to each process’s PCB in a process table so that it can access the PCB quickly.

Reference: https://www.geeksforgeeks.org/process-table-and-process-control-block-pcb/

# CPU Scheduling Algorithms
## Objectives of Process Scheduling Algorithm:
1. Utilization of CPU at maximum level.  **Keep CPU as busy as possible.**
2. **Allocation of CPU should be fair.**
3. **Throughput should be Maximum**. i.e. Number of processes that complete their execution per time unit should be maximized.
4. **Minimum turnaround time**, i.e. time taken by a process to finish execution should be the least.
5. There should be a **minimum waiting time** and the process should not starve in the ready queue.
6. **Minimum response time**. It means that the time when a process produces the first response should be as less as possible.

## CPU Scheduling Terms:
1. **Arrival Time**: Time at which the process arrives in the ready queue.
2. **Completion Time**: Time at which process completes its execution.
3. **Burst Time**: Time required by a process for CPU execution.
4. **Turn Around Time**: Time Difference between completion time and arrival time.
Turn Around Time = Completion Time  –  Arrival Time
5. **Waiting Time(W.T)**: Time Difference between turn around time and burst time.
Waiting Time = Turn Around Time  –  Burst Time

## Categories of Scheduling
## Non-preemptive: 
Process’s resource cannot be taken before the process has finished running. When a running process finishes and transitions to a waiting state, resources are switched.
## Preemptive: 
OS assigns resources to a process for a predetermined period. The process switches from running state to ready state or from waiting for state to ready state during resource allocation. 
This switching happens because the CPU may give other processes priority and substitute the currently active process for the higher priority process.

![CPU Schdeuling Algos](UntitledDiagram12.jpg)

**1. First Come First Serve (FCFS)**

Reference: https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/#
