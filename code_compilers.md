The compilation is the process of converting the source code of the C language into machine code

A compiler converts a C program into an executable. There are four phases for a C program to become an executable: 

1. Pre-processing
2. Compilation
3. Assembly
4. Linking

**1. Pre-processing**
This is the first phase through which source code is passed. This phase includes:

Removal of Comments
Expansion of Macros
Expansion of the included files.
Conditional compilation
The preprocessed output is stored in the filename.i. Let’s see what’s inside filename.i: using $vi filename.i

In the above output, the source file is filled with lots and lots of info, but in the end, our code is preserved. 

printf contains now a + b rather than add(a, b) that’s because macros have expanded.
Comments are stripped off.
#include<stdio.h> is missing instead we see lots of code. So header files have been expanded and included in our source file.

**2. Compiling**
The next step is to compile filename.i and produce an; intermediate compiled output file filename.s. This file is in assembly-level instructions.

**3. Assembling**
In this phase the filename.s is taken as input and turned into filename.o by the assembler. This file contains machine-level instructions. 
At this phase, only existing code is converted into machine language, and the function calls like printf() are not resolved.

**4. Linking**
This is the final phase in which all the linking of function calls with their definitions is done. Linker knows where all these functions are implemented.
Linker does some extra work also, it adds some extra code to our program which is required when the program starts and ends.
For example, there is a code that is required for setting up the environment like passing command line arguments.
This task can be easily verified by using $size filename.o and $size filename.
Through these commands, we know how the output file increases from an object file to an executable file.
This is because of the extra code that Linker adds to our program. 
