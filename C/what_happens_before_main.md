**_start function**

This function initializes the program runtime and invokes the program’s main function.

The linker controls the program’s entry point.

The _start function is often written in assembly. Many implementations store the _start function in a file called crt0.s. 
Compilers typically ship with pre-compiled crt0.o object files for each supported architecture.

At a high level, the _start function handles:

1. Early low-level initialization, such as:

   a. Configuring processor registers

   b. Initializing external memory

   c. Enabling caches

   d. Configuring the MMU
   
2. Stack initialization, making sure that the stack is properly aligned per the ABI requirements

3. Frame pointer initialization

4. Initialization of the C/C++ runtime

5. Initialization of other scaffolding required by the system

6. Jumping to main

7. Exiting the program with the return code from main

**Runtime Setup**

C/C++ runtime setup is a universal requirement for program startup. At a high level, our runtime setup must accomplish the following:

1. Relocate any relocatable sections (if not handled by the loader or linker)

2. Initializing global and static memory (uninitialized set to 0 @ .bss), C++ global objects must be constructed before calling main.
The linker places these constructors into the .init, .init_array, or .ctors section of the image. Some compilers also allow C and C++
functions to be marked as a constructor using a compiler attribute (e.g., __attribute__((constuctor))). The constructors are stored
in a list by the linker. The runtime initialization process iterates through the list and calls each constructor.

3. Prepare the argc and argv variables for invoking main (even if it’s just setting these to 0/NULL)

Some other steps:

4. Heap initialization

5. Initialize stdio (i.e., stdin, stdout, stderr)

6. Initialize exception support (if using C++)

7. Register destructors and other cleanup functions that will run when exiting the program (using atexit and __cxa_atexit)

8. Prepare environment variables

Because _start invokes main, it also handles its return. When control returns from main to _start, the next function to run is exit. 
The exit function calls all functions registered with atexitand __cxa_atexit during the startup process. Then exit calls the global 
destructors (those placed in the .fini, .fini_array, or .dtors sections). Finally, exit terminates the program with the return value
provided by main.

**3 ways to get to _start**

**Baremetal: Reset Vector:**

> When power is applied to the processor, the processor will copy the program from flash and store it in RAM

> Once the program is loaded into memory, the processor jumps to the reset interrupt vector address.
(reset interrupt handler initializes the system after power-on or reset.)

> The reset handler typically performs an initial configuration of the processor registers and critical hardware
components (such as external RAM, caches, or MMU). Once this initial configuration is complete, the reset handler jumps to _start.

**Bootloader Launches Application**

> Many systems use a bootloader or hypervisor, which runs before loading and executing the main application. Bootloaders perform a wide 
range of activities, including initializing system hardware, decryption, decompression, checking that a firmware image is valid before
loading it, selecting a firmware image to boot, or determining whether to enter firmware update mode. Bootloader complexity depends 
on the system’s requirements.

**OS Calls an exec function**

When you launch a program, your shell or GUI invokes a program loader. The loader is responsible for copying the application image 
from the hard drive into memory and configuring the environment that the program will run in. On Linux or OS X, the loader is a function
in the exec() family, typically execve() or execvp().

Loaders will often perform the following actions:

> Check permissions

> Allocate space for the program’s stack

> Allocate space for the program’s heap

> Initialize registers (e.g., stack pointer)

> Push argc, argv, and envp onto the program stack

> Map virtual address spaces

> Dynamic linking

> Relocations

> Call pre-initialization functions

Once the loader has configured the program environment, it calls the program’s _start function.

Ref: https://embeddedartistry.com/blog/2019/04/08/a-general-overview-of-what-happens-before-main/
