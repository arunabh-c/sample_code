#include <stdio.h>
#include <string.h>

int
main ()
{
  char c[12] = "Hello World";
  //char *c = "Hello World";modifying string literal doesn't work because it 
  //is an anonymous array that is typically stored in ROM by compiler

  int s = strlen (c);
  for (int i = 0; i < s / 2; ++i)
	{
	  char x = c[s - i - 1];
	  c[s - i - 1] = c[i];
	  c[i] = x;
	}
  printf ("%s\n", c);

  return 0;
}
