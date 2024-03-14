/*
#include <stdio.h>
 
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %d ", sizeof(arri));//12
    printf("sizeof ptri = %d ", sizeof(ptri));//4
 
    printf("sizeof arrc[] = %d ", sizeof(arrc));//3
    printf("sizeof ptrc = %d ", sizeof(ptrc));//4
 
    return 0;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("Number of elements between two pointer are: %d.", 
                                (ptr2 - ptr1));//5
    printf("Number of bytes between two pointers are: %d",  
                              (char*)ptr2 - (char*) ptr1);//4*5
    return 0;
}

int main() 
{ 
   int a; 
   char *x; 
   x = (char *) &a; 
   a = 512; 
   x[0] = 1; 
   x[1] = 2; 
   printf("%d\n",a);//513 in LE   
   return 0; 
    let integers be stored using 16 bits. In a little endian machine, when we do x[0] = 1 and x[1] = 2, 
    the number a is changed to 00000001 00000010 which is representation of 513 in a little endian machine.
}

Reference: https://www.geeksforgeeks.org/c-language-2-gq/pointers-gq/
*/
