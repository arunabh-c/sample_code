# Process Scheduler
Process scheduling is the activity of the process manager that handles the removal of the running process from the CPU and the selection of another process based on a particular strategy. 
Process scheduling is an essential part of a Multiprogramming operating system. Such operating systems allow more than one process to be loaded into the executable memory at a time and the loaded process shares the CPU using time multiplexing.

# Categories of Scheduling
## Non-preemptive: 
Process’s resource cannot be taken before the process has finished running. When a running process finishes and transitions to a waiting state, resources are switched.
## Preemptive: 
OS assigns resources to a process for a predetermined period. The process switches from running state to ready state or from waiting for state to ready state during resource allocation. 
This switching happens because the CPU may give other processes priority and substitute the currently active process for the higher priority process.

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

# Context Switching

# 
