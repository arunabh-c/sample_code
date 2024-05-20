The bulk of the printf code itself is concerned with interpreting the format string, converting the arguments to strings to be written, 
and writing those strings to the output file. Much of this work will be done through subroutines that printf calls, such as subroutines
to convert numbers (objects like int or float) to numerals (strings of characters that represent the numbers). All of the work of 
interpreting the format string, converting the arguments, and preparing strings to be written can be done in C

At some point, when printf has a string to print, it will call a routine to write the string to stdout. This may be fwrite or some 
similar subroutine. Usually, streams are buffered. So, when printf calls fwrite, fwrite checks how full its buffer is. If the new string
from printf fits into the buffer, fwrite merely adds the string to the buffer and returns. If the buffer is full, then fwrite calls 
another routine to actually write the buffer contents to a file. 

In the case of a write to standard output, the work is sent to a “device driver”, which is a name for software that handles the work
for a “device”. Originally, devices were pieces of hardware connected to the system. A device driver would copy the data to be 
written to a special place in memory and issue a command to the device (using special instructions) to read that data from memory
and send it to wherever the device sends it (a terminal, a disk drive, whatever).

Today, many “devices” are software that implement virtual devices. The standard output of a user process is likely some sort of 
pseudo-terminal. Since that pseudo-terminal has no actual hardware terminal, it has to handle write requests by asking other software to help.

When the pseudo-terminal is part of a terminal window on a graphic display, there is some software that implements the terminal window. 
That software accepts text being written to standard output, decides where in the window it should be placed, and calls other software to 
convert the characters into changes in pixels in the window.

Ref: https://stackoverflow.com/questions/13657890/what-goes-behind-printf-in-c
