   
#include <stdlib.h>
#include <stdio.h>

char *getString()
{
   char *str = "Nice test for strings";//The above program works because string constants are stored in Data Section (not in Stack Section). So, when getString returns *str is not lost.
   //char str[] = "Will I be printed?";//The above program doesn’t work because array variables are stored in Stack Section. So, when getString returns values at str are deleted and str becomes dangling pointer.   
   return str;
}
 
int getint()
{
   int x = 5;
   return x;
}
 
int main()
{
   printf("%s\n", getString());
   printf("%p", main);
   
   printf("\new_c_question\by");
   printf("\rgeeksforgeeks");
   return 0;
}
