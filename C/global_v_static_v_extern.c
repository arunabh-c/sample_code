//You should not define global variables in header files. You should define them in .c source file.

//If global variable is to be visible within only one .c file, you should declare it static.

//If global variable is to be used across multiple .c files, you should not declare it static. 
//Instead you should declare it extern in header file included by all .c files that need it.

//If you do not specify a storage class (that is, the extern or static keywords), 
//then by default global variables have external linkage. From the C99 standard:

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

//Reference: https://stackoverflow.com/questions/4239834/global-variables-in-c-are-static-or-not
//https://stackoverflow.com/questions/1856599/when-to-use-static-keyword-before-global-variables
