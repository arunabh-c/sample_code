//You should not define global variables in header files. You should define them in .c source file.

//If global variable is to be visible within only one .c file, you should declare it static.

//If global variable is to be used across multiple .c files, you should not declare it static. Instead you should declare it extern in header file included by all .c files that need it.

//Example:

//example.h
extern int global_foo;

//foo.c
#include "example.h"

int global_foo = 0;
static int local_foo = 0;

int foo_function()
{
   /* sees: global_foo and local_foo
      cannot see: local_bar  */
   return 0;
}

//bar.c
#include "example.h"

static int local_bar = 0;
static int local_foo = 0;

int bar_function()
{
    /* sees: global_foo, local_bar */
    /* sees also local_foo, but it's not the same local_foo as in foo.c
       it's another variable which happen to have the same name.
       this function cannot access local_foo defined in foo.c
    */
    return 0;
}
