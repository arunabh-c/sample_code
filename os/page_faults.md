A page fault occurs when a program attempts to access data or code that is in its address space, but is not currently located in the system RAM.

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

# Terminologies
**1. Page Hit** When the CPU attempts to obtain a needed page from main memory and the page exists in main memory (RAM).

**2. Page Miss** If the needed page has not existed in the main memory (RAM).

**3. Page Fault Time** The time it takes to get a page from secondary memory and recover it from the main memory after loading the required page.

**4. Page Fault Rate** The rate at which threads locate page faults in memory. The page fault rate is measured per second.

**5. Hard Page Fault** If a required page exists in the hard disk's page file.

**6. Soft Page Fault** If a required page is not located on the hard disk but is found somewhere else in memory.

**7. Minor Page Fault** If a process needs data and that data exists in memory but is being allotted to another process at the same moment.
