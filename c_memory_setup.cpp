#include <stdio.h>
 
int global; /* Uninitialized variable stored in bss*/
int globals = 10; /* initialized global variable stored in DS*/
 
int main(void)
{
  static int i; /* Uninitialized static variable stored in bss */
  static int j = 100; /* Initialized static variable stored in DS*/
  return 0;
}
