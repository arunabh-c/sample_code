Instead of waiting patiently for the lock to become available, a thread using a 
spinlock behaves more like an eager person who keeps checking the lock repeatedly. 
They don’t want to miss their chance to enter the room, so they continuously ask, 
“Is the lock available yet?” Doing this in a loop is called **“busy waiting/spin-waiting”**.
The idea behind this approach is to save time by avoiding the overhead of blocking 
or pausing the thread.

Imagine if multiple threads are all spinning and asking about the lock continuously. 
The threads keep checking the lock even when it’s not available, wasting a lot of time
and CPU cycles. It’s like a group of people who know a door won’t open but who keep 
knocking on it anyway. Spinlocks, therefore, work best when the critical section, 
or the portion of the code they protect, is anticipated to be held for a brief period
of time, yet they can be effective in some circumstances.

**Critical Section:** A critical section refers to a part of the code that must be executed
atomically to maintain data consistency. It is the region of code protected by a spinlock 
to ensure exclusive access.

Reference: https://www.geeksforgeeks.org/what-is-spinlock-in-operating-system/

That's why on a single core machine a spinlock is simply a "disable interrupts" or "raise IRQL" 
which prevents thread scheduling completely.

Besides, kernel objects are not available in every state of the kernel, such as in an interrupt 
handler or when paging is not available etc.

Spinlocks don't cause preemption but wait in a loop ("spin") till the other core releases the lock. 
This prevents the thread from losing its quantum and continue as soon as the lock gets released. 
The simple mechanism of spinlocks allows a kernel to utilize it in almost any state.

Spinlocks are only useful in places where anticipated waiting time is shorter than a quantum 
(read: milliseconds) and preemption doesn't make much sense (e.g. kernel objects aren't available).

The period of time for which a process is allowed to run in a preemptive multitasking system is 
generally called the **time slice or quantum**.

In computing, preemption is the act of temporarily interrupting an executing task, with the intention
of resuming it at a later time. This interrupt is done by an external scheduler with no assistance or 
cooperation from the task
Ref: https://stackoverflow.com/questions/1957398/what-exactly-are-spin-locks
Ref: https://en.wikipedia.org/wiki/Preemption_(computing)#Time_slice

A hybrid spinlock behaves like a normal spinlock at first, but to avoid wasting too much CPU time, 
it may have a back-off strategy. It will usually not put the thread to sleep (since you don't want 
that to happen when using a spinlock), but it may decide to stop the thread (either immediately or 
after a certain amount of time; this is called "yielding") and allow another thread to run, thus 
increasing chances that the spinlock is unlocked (you still have the costs of a thread switch but 
not the costs of putting a thread to sleep and waking it up again).

Ref: https://stackoverflow.com/questions/5869825/when-should-one-use-a-spinlock-instead-of-mutex

What are the advantages of spinlocks?
Answers:
Spinlocks have low overhead compared to other synchronization primitives like mutexes or semaphores. 
They avoid the overhead of putting a thread to sleep and waking it up, which can be costly. They 
are also easy to implement in environments without support for more complex synchronization mechanisms.

Ref: https://www.geeksforgeeks.org/difference-between-spinlock-and-semaphore/
