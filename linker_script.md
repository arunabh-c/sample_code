**Linker and Locator Introduction**
As we have seen in the last tutorial on the bare metal embedded system build process using GNU tools, the linker role is to combine multiple object files and produce a single executable file. But in embedded systems, the linking process involves two steps: one is the linker and the second step is the locator. The role of the locator is to assign specific address locations to the object file according to the memory map of the microcontroller. After performing address allocation, the locator produces an executable file that we can install on the target embedded device. 

**Role of Locator**
As shown in the figure below, the linker combines the multiple object files and produces a single relocatable object file. The relocatable file is an input of the locator stage. The locator maps the application code and data into proper addresses with the help of a linker file. 



**Linker Script File**
In the last section, we have discussed that the main role of a linker script file is to assign addresses and memory sections to application code and data according to the microcontroller memory map and format of execuatable file.

**Linker Script Functions**
Followings are the functions of the linker script file:

It defines the process how different sections of the combined object file should be placed in target device memory to create a executable file
Locator assigns specific absolute addresses to the different sections of the program file such as data and code and absoulte addresses are assigned according to the target embedded device flash and RAM memory
Defines the size of different sections of memory such as code memory, data memory, stack size, etc
If you are using GNU toolchain, the extension of linker script file is .ld and linker scripts are written using GNU linker script language. We will see the exmple of linker script file of TM4C123GH6PM microcontroller later in this tutorial.

while building embedded application using GCC toolchain, you can provide linker script file with -T option followed by a linker script file name.

**Linker Script Commands**
Followings are the six main commands of a linker script file:

**ENTRY
MEMORY
SECTIONS
KEEP
ALIGN
AT>**
Now lets discuss each command one by one and see its funtion.

**ENTRY Commad**
This command defines the entry point address in the ELF file. As we have seen in the last tutorial on the microcontroller booting process that the entry point of a microcontroller is a “Reset_Handler”. Therefore, this command contains the address of the Reset_Handler. With the help of this command, microcontroller determines where to start execution after microcontroller resets.

The syntax of this command is :

ENTRY(Reset_Handler)
MEMORY Command
This command is used to specify different types of memory available in a target embedded device. We also mention starting address and size of each memory type available. For example, in TM4C123G microcontrollers has code memory and flash memory.

The locator defines the memory regions to each section of memory according to the information provided by Memory command. Here in this example script, the memory command defines the starting address and size of flash and RAM memory of TM4C123G microcontroller.

TM4C123GH6PM microcontroller has 256k bytes of flash memory and 32k bytes of RAM memory. Here, we define the available code and data memory size available with the help of memory command.

```
MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K /* FLASH size 256KB */
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 32K/* RAM size 32KB */

}
```

Here, FLASH and RAM are the labels used to define regions of memory. Inside the curly braces are the attributes assign to these memory regions. Flash memory is a read-only memory region. Hence, we write an attribute (rx). On the other hand, RAM memory is both readable and writeable. Hence, we use an attribute (rwx).

For more information on MEMORY command visit this link.

```
SECTIONS Command
SECTIONS command is used to create compiled memory sections of the program in output EFL file ( executable and linkable file). Complied memory sections include .text, .data, .bss, and stack sections, etc. In other words, this command informs the location and linker to place these sections at proper addresses in flash and RAM memory.

This is a SECTION command body of the linker script file. Inside the section command, there are definitions of different sections and these sections define the placement of code, initialized, uninitialized data in the code, and data memory.

SECTIONS
{

    /* 
     * initial stack pointer pointing to top of stack,starts from higher addresses
     * i.e ORIGIN(RAM) + LENGTH(RAM)-1 in this case 0x20007FFF to lower addesses i.e
     * those lesser than 0x20007FFF to 0x2000000,which is the origina address of RAM,
     * until it comes in contact with .bss or .data in which case a buffer overflow occurs
    */
    PROVIDE( _stack_ptr = ORIGIN(RAM) + LENGTH(RAM));

    /* constants  and other code stored in FLASH */
    .text :
    {
        _text = .;               /* beginning of .text segment,also called code memory */
        KEEP(*(.vector_table)) /* vector table defined in startup.c to be included */
        *(.text*)                   /* other code */
        *(.rodata*)                /* constants go here */
        _etext = .;             /* end of .text segment */
    } > FLASH

    /* data, initialized variables, to be copied to RAM upon <RESET> by startup.c */
    .data : 
    {
        _data = .;          /* beginning of .data segment */
        *(.data*)           /* data goes here */
        _edata = .;         /* end of .data segment */
    } > RAM AT >FLASH   /* .data segment starts directly after the .text section in FLASH */

    /* uninitialized data which is initialized to 0 upon <RESET> by startup.c */
    .bss :
    {
        _bss = .;       /* beginning of .bss segment */
        *(.bss*)        /* .bss content goes here */
        *(COMMON)       
        _ebss = .;      /* end of .bss segment */
    } > RAM


}
```

SECTIONS command and defintions of different sections directs the linker scripts to place these memory section in flash memory according to the specified order locations as shown in figure.

Memory sections mapping linker script file arm cortex m4.

Ref: https://microcontrollerslab.com/bare-metal-embedded-systems-linker-script-file/
Ref: https://blog.thea.codes/the-most-thoroughly-commented-linker-script/
Ref: https://medium.com/@xsumirx/gnu-linker-script-and-memory-relocation-for-embedded-devices-5d3d16d1f0
.data and .bss section are copied to RAM memory of ARM Cortex M4 microcontroller during the boot process of a microcontroller.
