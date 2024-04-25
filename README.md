# sample_code
implementation of some common algorithms for self-learning.

Some critical facts:

1. **Little endian** is basically reversing the byte order for a multi byte value. 1111 1111 1111 0100 is a 2 byte value where 1111 1111 is the first byte and 1111 0100 is the second byte. In little endian, the second byte (or least significant byte) is read in first so the final representation is 1111 0100 1111 1111. **Little endian means the lower significant bytes get the lower addresses**
2. The class member declared as **Protected** are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
3. Compile Time polymorphism is achieved via function or operator overloading.

To do:

1. smart pointers
2. mem move, mem copy
3. named return value optimisation
4. function pointers
5. c pointers
6. move semantics
11. concurrency in C
12. uC boot up procedure
13. how does gdb debugger work, how does it attach to image and provide breakpoint: https://sourceware.org/gdb/wiki/Internals
14. Kernel programming: https://sysprog21.github.io/lkmpg/#functions-available-to-modules , 
15. Device Drivers : https://www.nxp.com/docs/en/reference-manual/Linux%20Device%20Drivers.pdf , https://www.apriorit.com/dev-blog/195-simple-driver-for-linux-os
16. Spin Lock
17. Advanced Thread Management strategies/design principles

https://github.com/methylDragon/coding-notes/blob/master/C%2B%2B%2F07%20C%2B%2B%20-%20Threading%20and%20Concurrency.md

https://www.bogotobogo.com/cplusplus/files/CplusplusConcurrencyInAction_PracticalMultithreading.pdf

https://www.srcmake.com/home/cpp-advanced-multithreading

https://www.modernescpp.com/index.php/concurrency-patterns/

18. Activation Records
