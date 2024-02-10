# Process Scheduler
Process scheduling is the activity of the process manager that handles the removal of the running process from the CPU and the selection of another process based on a particular strategy. 
Process scheduling is an essential part of a Multiprogramming operating system. Such operating systems allow more than one process to be loaded into the executable memory at a time and the loaded process shares the CPU using time multiplexing.

# Categories of Scheduling
## Non-preemptive: Process’s resource cannot be taken before the process has finished running. When a running process finishes and transitions to a waiting state, resources are switched.
## Preemptive: OS assigns resources to a process for a predetermined period. The process switches from running state to ready state or from waiting for state to ready state during resource allocation. 
This switching happens because the CPU may give other processes priority and substitute the currently active process for the higher priority process.

# Types of Process Schedulers
## Long Term or Job Scheduler
Brings the new process to the ‘Ready State’. It controls the Degree of Multi-programming, i.e., the number of processes present in a ready state at any point in time. It is important that the long-term scheduler make a careful selection of both I/O and CPU-bound processes. 
I/O-bound tasks are which use much of their time in input and output operations while CPU-bound processes are which spend their time on the CPU. The job scheduler increases efficiency by maintaining a balance between the two. They operate at a high level and are typically used in batch-processing systems.

## Short-Term or CPU Scheduler
Responsible for selecting one process from the ready state for scheduling it on the running state. Note: Short-term scheduler only selects the process to schedule it doesn’t load the process on running.  Here is when all the scheduling algorithms are used. The CPU scheduler is responsible for ensuring no starvation due to high burst time processes.

## Dispatcher
The dispatcher is responsible for loading the process selected by the Short-term scheduler on the CPU (Ready to Running State) Context switching is done by the dispatcher only. A dispatcher does the following: 

> Switching context.
> Switching to user mode.
> Jumping to the proper location in the newly loaded program.

# Other types of Process Schedulers

# Context Switching

# 
