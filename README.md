# sample_code
implementation of some common algorithms for self-learning.

Some critical facts:

1. **Little endian** is basically reversing the byte order for a multi byte value. 1111 1111 1111 0100 is a 2 byte value where 1111 1111 is the first byte and 1111 0100 is the second byte. In little endian, the second byte (or least significant byte) is read in first so the final representation is 1111 0100 1111 1111. **Little endian means the lower significant bytes get the lower addresses**

2. The class member declared as **Protected** are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.

3. Compile Time polymorphism is achieved via function or operator overloading.

4. How does Function Overloading work?
Exact match:- (Function name and Parameter)
If a not exact match is found:–
               ->Char, Unsigned char, and short are promoted to an int.

               ->Float is promoted to double

If no match is found:
               ->C++ tries to find a match through the standard conversion.

ELSE ERROR 🙁 Ref: https://www.geeksforgeeks.org/function-overloading-c/

5. Function overloading not possible with different return types? 

During compilation, the function signature is checked. So, functions can be overloaded, if the signatures are not the same. The return type of a function has no effect on function overloading, therefore the same function signature with different return type will not be overloaded. 
Reference: https://www.geeksforgeeks.org/function-overloading-and-return-type-in-cpp/

6. Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration. For example, following program fails in compilation. 
#include<iostream>
class Test {
   static void fun(int i) {}
   void fun(int i) {}   
};
 
int main()
{
   Test t;
   getchar();
   return 0;
}//Ref: https://www.geeksforgeeks.org/function-overloading-in-c/

7. Parameter declarations that differ only in a pointer * versus an array [] are equivalent. That is, the array declaration is adjusted to become a pointer declaration. Only the second and subsequent array dimensions are significant in parameter types. For example, following two function declarations are equivalent. 
int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)

8.  Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent. 
void h(int ());
void h(int (*)()); // redeclaration of h(int() hence cant be overloaded

9. Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. That is, the const and volatile type-specifiers for each parameter type are ignored when determining which function is being declared, defined, or called. For example, following program fails in compilation with error “redefinition of `int f(int)’ “ Example: 
#include<iostream>
#include<stdio.h>
  
using namespace std;
  
int f ( int x) {
    return x+10;
}
 
int f ( const int x) {//bad function overload will error
    return x+10;
}
 
int main() {     
  getchar();
  return 0;
}

10. Two parameter declarations that differ only in their default arguments are equivalent. For example, following program fails in compilation with error “redefinition of `int f(int, int)’ “ 
#include<iostream>
#include<stdio.h>
  
using namespace std;
  
int f ( int x, int y) {
    return x+10;
}
 
int f ( int x, int y = 10) {
    return x+y;
}
 
int main() {     
  getchar();
  return 0;
}

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

19. more RAII + smart pointers:
https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1204/lectures/raii/raii.pdf

20. what are initializer lists and functions of const that dont actualyl return const inputs: https://www.geeksforgeeks.org/const-member-functions-c/#

21. Finish implementing multi-threaded test bounded enqueue dequeue, map of string vs function pointer, implement basic calculator.
