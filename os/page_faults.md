A Page Fault is an exception that occurs by the Memory Management Unit (MMU) when a program attempts to access data or code that is in its address space, but is not currently located in the system RAM.

# Sequence of Events:

1. The computer hardware **traps to the kernel** and program counter (PC) is saved on the stack. Current instruction **state information is saved in CPU registers**.
2. An assembly program is started to **save the general registers and other volatile information** to keep the OS from destroying it.
3. Operating system finds that a **page fault has occurred and tries to find out which virtual page** is needed. Some times hardware register contains this required information. If not, the operating system must retrieve PC, fetch instruction and find out what it was doing when the fault occurred.
4. Once virtual address caused page fault is known, **system checks to see if address is valid and checks if there is no protection access problem.**
5. If the virtual address is valid, the system **checks to see if a page frame is free**. If no frames are free, the **page replacement algorithm is run** to remove a page.
6. If **frame selected is dirty**, **page is scheduled for transfer to disk**, context switch takes place, fault process is suspended and another process is made to **run until disk transfer** is completed.
7. As soon as **page frame is clean**, operating system **looks up disk address where needed page is, schedules disk operation** to bring it in.
8. When disk interrupt indicates **page has arrived, page tables are updated** to reflect its position, and frame marked as being in normal state.
9. **Faulting instruction is backed up to state it had** when it began and PC is reset. Faulting is scheduled, **operating system returns to routine** that called it.
10. Assembly Routine **reloads register and other state information, returns to user space** to continue execution.

Reference: https://www.geeksforgeeks.org/page-fault-handling-in-operating-system/

# Terminologies
**1. Page Hit** When the CPU attempts to obtain a needed page from main memory and the page exists in main memory (RAM).

**2. Page Miss** If the needed page has not existed in the main memory (RAM).

**3. Page Fault Time** The time it takes to get a page from secondary memory and recover it from the main memory after loading the required page.

**4. Page Fault Rate** The rate at which threads locate page faults in memory. The page fault rate is measured per second.

**5. Hard Page Fault** If a required page exists in the hard disk's page file. A major page fault is a mechanism used by the operating system to increase the amount of available program memory on demand. The operating system will delay loading certain parts of the program from disk until the program tries to use it and generates a page fault.

**6. Soft Page Fault** If a required page is not located on the hard disk but is found somewhere else in memory. The page is not marked as being loaded into memory in the memory management unit. Also called Minor Page Fault. The page fault handler in the operating system only needs to make the entry of the page in the memory management unit point to the page in the memory and indicate that the page has been loaded into the memory.

Reference: https://www.javatpoint.com/page-fault-handling-in-operating-system
https://www.minitool.com/lib/page-fault.html

**7. Invalid Page Fault** is when the kernel's page-fault handler decides that the process doesn't even logically have that virtual address mapped. e.g. a NULL pointer deref - virtual address 0 isn't mapped in the HW page tables (thus a #PF x86 hardware exception), and when the kernel checks how to correct the situation and retry the faulting instruction, it finds there's no fix. (On Linux, the kernel delivers a SIGSEGV signal (segfault) or kills the process if no handler.)

Reference: https://stackoverflow.com/questions/5684365/what-causes-page-faults

**8. Cache Faults** The system file cache uses Virtual Memory Manager functions to manage application file data.  The system file cache maps open files into a portion of the system virtual address range and uses the process working set memory management mechanisms to keep the most active portions of current files resident in physical memory.  Cache faults are a type of page fault that occur when a program references a section of an open file that is not currently resident in physical memory.  Cache faults are resolved by reading the appropriate file data from disk

When investigating page fault issues, it is important to understand whether the page faults are hard faults or soft faults.  The page fault counters in Performance Monitor do not distinguish between hard and soft faults, so you have to do a little bit of work to determine the number of hard faults.  To track paging, you should use the following counters: Memory\ Page Faults /sec, Memory\ Cache Faults /sec and Memory\ Page Reads /sec.  The first two counters track the working sets and the file system cache.  The Page Reads counter allows you to track hard page faults.  **If you have a high rate of page faults combined with a high rate of page reads (which also show up in the Disk counters) then you may have an issue where you have insufficient RAM given the high rate of hard faults.**

https://techcommunity.microsoft.com/t5/ask-the-performance-team/the-basics-of-page-faults/ba-p/373120



