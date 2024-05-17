The bottom half is used to process data, letting the top half to deal with new incoming interrupts. 
Interrupts are enabled when a bottom half runs. The interrupt can be disabled if necessary, 
but generally, this should be avoided as this goes against the basic purpose of having a 
bottom half – processing data while listening to new interrupts. The bottom half runs in 
the future, at a more convenient time, with all interrupts enabled.

Using the network card:

> When network cards receive packets from the network, the network cards immediately issue an interrupt.
This optimizes network throughput and latency and avoids timeouts.

> The kernel responds by executing the network card’s registered interrupt.

> The interrupt runs, acknowledges the hardware, copies the new networking packets into the main memory,
and readies the network card for more packets. These jobs are important, time-critical, and hardware-specific work.

> The kernel generally needs to quickly copy the networking packet into the main memory because the network
data buffer on the networking card is fixed and minuscule in size, particularly compared to the main memory.
Delays in copying the packets can result in a buffer overrun, with incoming packets overwhelming the
networking card’s buffer and thus packets being dropped.

> After the networking data is safely in the main memory, the interrupt’s job is done, and it can return
control of the system to whatever code was interrupted when the interrupt was generated.

> The rest of the processing and handling of the packets occurs later, in the bottom half.

**Static Bottom Halfs**: SoftIrq that need to be defined during compile time

**Dynamic Bottom Halfs**: Tasklets & Workque 

**The 4 Bottom Half Mechanisms**

**Workqueue**

Workqueues are utilized to defer and schedule tasks that require asynchronous execution in the background. 
Whenever a slow, non-critical task needs to be executed to prevent delays in the main execution path, 
we defer the task and enqueue it on a Workqueue.

So, this will run in the process context and the work queue can sleep.

Code deferred to a work queue has all the usual benefits of process context.
Most importantly, work queues are schedulable and can therefore sleep.
Normally, it is easy to decide between using workqueue and softirq/tasklet:

> If the deferred work needs to sleep, then workqueue is used.

> If the deferred work needs not sleep, then softirq or tasklet are used.

A workqueue contains a linked list of tasks to be run at a deferred time. Tasks in workqueue:

• run in process context, therefore can sleep, and without inteferring with tasks running in any other queues.

• but still cannot transfer data to and from user space, as this is not a real user context to access.

syntax:

Static Method:
```
DECLARE_WORK(name, void (*func)(void *))
```

Dynamic Method:
```
INIT_WORK(work,work_fn)
```

**Threaded IRQ**

Threaded IRQ is a bottom half technique that is used to delegate the long running task from top half. One advantage that you 
get from using threaded IRQ is that we don't need to schedule the task manually, the core will do automatically this work for us. 
As you will see in the program in the code section of the article, that we don't use any schedule_work() or schedule_delayed_work()
functions. This method will improve the efficiency of handling the interrupts as it will execute top half very fast and hand over 
the execution of the task to threaded IRQ function.

Few advantages that we get in Threaded IRQ is

> We will be able to use Locks in the Threaded IRQ as the execution happens on the bottom half 

> We can allocate the memory in Threaded IRQ

> We can preempt the threaded IRQ task by others threads

> We can use sleep in threaded IRQ

Syntax:
```
int request_threaded_irq( unsigned int irq,
                          irq_handler_t handler,
                          irq_handler_t thread_fn,
                          unsigned long irqflags,
                          const char *devname,
                          void *dev_id
                        );
```

**Softirq**

Softirq is also known as a software interrupt request.The softirq is rarely used as we have tasklets already. 
Most of the stuff, we can do using the tasklets. Tasklets also built on softirq.
Softirqs were originally designed as a vector of 32 softirq entries supporting a variety of software interrupt behaviors. 
Today, only nine vectors are used for softirqs, one being the TASKLET_SOFTIRQ (see ./include/linux/interrupt.h). 
And although softirqs still exist in the kernel, tasklets and work queues are recommended instead of allocating new softirq vectors.

**Tasklets**

Tasklets are used to queue up work to be done at a later time. Tasklets can be run in parallel, but the same tasklet cannot 
be run on multiple CPUs at the same time. Also, each tasklet will run only on the CPU that schedules it, to optimize cache 
usage. Since the thread that queued up the tasklet must complete before it can run the tasklet, race conditions are 
naturally avoided. However, this arrangement can be suboptimal, as other potentially idle CPUs cannot be used to run the tasklet. 
Therefore workqueues can and should be used instead, and workqueues were already discussed here.

In short, a tasklet in linux is something like a very small thread that has neither stack nor context of its own. Such “threads” work quickly and completely.

> Tasklets are atomic, so we cannot use sleep() and such synchronization primitives as mutexes, semaphores, etc. from them. But we can use spinlock.

> A tasklet only runs on the same core (CPU) that schedules it.

> Different tasklets can be running in parallel. But at the same time, a tasklet cannot be called concurrently with itself, as it runs on one CPU only.

> Tasklets are executed by the principle of non-preemptive scheduling, one by one, in turn. We can schedule them with two different priorities: normal and high.

Syntax: 

```
struct tasklet_struct
{
    struct tasklet_struct *next;  
    unsigned long state;         
    atomic_t count;               
    void (*func)(unsigned long); 
    unsigned long data;           
};
```

**ThreadedIRQ vs Tasklet**

A threaded irq runs in its own separate thread, and it can do anything any "normal" kernel thread can do. 
It can do things that potentially block, like acquiring locks or allocating memory, it can be preempted by other threads, it can sleep.

A softirq/tasklet doesn't have its own context, but rather there are situations where the kernel checks whether any outstanding softirq's 
are waiting and runs them. Typically this is done after hard irq (top half) processing, or just before returning from a syscall 
(any random syscall by any random process, doesn't necessarily have anything to do with the interrupt in question). 
Softirq's also run in an atomic context, they are not allowed to do anything that might block.

The downside of the softirq approach is that it can cause potentially unbounded latency, as the softirq processing runs at essentially 
"infinite" priority. Though there is a mechanism where the kernel detects if it spends too much time processing softirq's, then it 
stops and instead wakes a "ksoftirqd" thread to handle them, and that thread is then subject to scheduling just like any other 
thread in the system.

For an example, if you use your computer for some audio applications. You want your audio application to not cause stutter, 
so you run it at realtime priority level. Now, as it happens on your PC you also run a webserver serving the latest cat pictures 
to the internet. For some reason the latest picture becomes very popular, and your PC becomes overloaded with requests. 
And it can happen that the system spends so much time handling network I/O that your audio application misses its deadline and 
you hear an annoying pop or stutter when it runs out of buffer. If, instead, network I/O were to be handled by a threaded irq, 
the scheduler could decide that as important serving cat pictures is, that audio application has even higher priority and it gets to run.

The downside of threaded irq is that needing a separate thread for it means more context switch overhead.

Ref: https://embetronicx.com/tutorials/linux/device-drivers/workqueue-in-linux-kernel/
https://www.cs.otago.ac.nz/cosc440/labs/lab08.pdf
https://developer.ibm.com/tutorials/l-tasklets/
https://www.linkedin.com/pulse/kernel-driver-series-5-bottom-half-techniques-threaded-gutti-cdfoc/
https://embetronicx.com/tutorials/linux/device-drivers/threaded-irq-in-linux-kernel/
https://stackoverflow.com/questions/68616407/what-is-the-difference-between-threaded-interrupt-handler-and-tasklet
