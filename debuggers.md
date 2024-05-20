
**Hardware breakpoints** are sometimes available as a built-in debugging features with some chips. 
Typically these work by having dedicated register into which the breakpoint address may be stored. 
If the PC (shorthand for program counter) ever matches a value in a breakpoint registers, 
the CPU raises an exception and reports it to GDB.

**Software breakpoints** require GDB to do somewhat more work. The basic theory is that GDB will replace
a program instruction with a trap, illegal divide, or some other instruction that will cause an exception, 
and then when it’s encountered, GDB will take the exception and stop the program. When the user says to
continue, GDB will restore the original instruction, single-step, re-insert the trap, and continue on.

Since it literally overwrites the program being tested, the program area must be writable, so this 
technique won’t work on programs in ROM.

it is important, that:

> Compiler includes enough information in the executable (that is not in the code itself but in special 
sections in same file), so that debugger can relate source that user wants to debug with machine code. 
One typical thing debugger needs to know to be able to set breakpoints (unless you specify addresses directly), 
is where (at which address) program functions and lines of source code start (within machine code).

> Code is not optimized by compiler in any way, that makes it impossible to relate source and machine code.
Typically you will want debug code that was not optimized or code where only carefully selected optimizations
were performed.

To stop a process, we use the monolithic ptrace syscall.

The ptrace() system call provides a means by which one process (the “tracer”) may observe and control 
the execution of another process (the “tracee”), and examine and change the tracee’s memory and registers. 
It is primarily used to implement breakpoint debugging and system call tracing.

– ptrace man page

Though ptrace provides means to affect many aspects of a process’ execution, memory, and register state, 
the only operations we’ll need for now are PTRACE_ATTACH and PTRACE_DETACH.

PTRACE_ATTACH establishes the tracer(debugger)-tracee(target process) relationship and does a few useful 
things for us, some being:

Stops the target process. Note – ptrace(PTRACE_ATTACH, ...) must be called on all target threads; it 
stops only the single thread provided to the command. The main process thread is stopped first.
Allows the debugger to read from process memory/registers.
PTRACE_DETACH simply reverses these effects and allows the target process to continue executing. 
Debuggers call ptrace(PTRACE_DETACH, ...) after they finish their operations.

**Unwind**

The rip (register instruction pointer) specifically indicates the currently executing function. Remember, 
we want the entire callstack for each thread, not just the currently executing function. Raw register 
values are also of little use to an end-user; people know their functions’ names, not their functions’
locations in memory. We’ll need to translate these instruction addresses to their associated symbols.

This is where debugging information finally makes its entrance. It’s used to translate raw addresses and
memory values to program elements familiar to the programmer, such as function names.

To unwind a callstack, we want to know which function called the currently executing function, and which
function called the caller, and so on, up until we hit the thread’s starting function. We use the return
address for this. It’ll be within the range of instruction addresses for the calling function

Unwinding is thus summarized as:

> Use a thread’s current instruction address to find the frame description in the debug information.

> Use that description to find the calling frame’s next instruction address and current stack pointer.

> Use this caller’s information to repeat this process until we reach a stopping point.


The flow condensed:

1 Use ptrace to attach to and stop a process

2 Extract the thread list using libthread_db or procfs

3 Use ptrace to extract the current register set of each thread

4 Use the debugging information in the executable file to unwind each thread’s callstack from the initial rip to the thread’s starting function

5 Use the debugging information to retrieve variable state

Instruction Address:
https://www.ibm.com/docs/en/zvm/7.3?topic=at-instruction-address

Ref: https://sourceware.org/gdb/wiki/Internals/Breakpoint%20Handling.

https://stackoverflow.com/questions/14598524/how-does-a-breakpoint-in-debugger-work

https://engineering.backtrace.io/2016-08-11-debugger-internals/

https://www.ibm.com/docs/en/zvm/7.3?topic=at-instruction-address
