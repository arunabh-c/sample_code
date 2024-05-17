#include <stdio.h>
#include <stdbool.h>

bool
my_strcmp (char *a, char *b)
{
  while (*a != '\0')
	if (*a++ != *b++)
	  return false;
  if (*b != '\0')
	return false;
  return true;
}

int
main ()
{
  char *a = "Hahaa";
  char *b = "Haha";
  printf ("%d\n", my_strcmp (a, b));
  b = "Hahaa";
  printf ("%d\n", my_strcmp (a, b));
  return 0;
}
