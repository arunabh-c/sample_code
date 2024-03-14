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

int main()
{
 char *ptr = "GeeksQuiz";
 printf("%c", *&*&*ptr);//G
 return 0;
}

void fun(int arr[])
{
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);//Machine Dependent
}
 
int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  fun(arr);
  return 0;
} 
In C, array parameters are always treated as pointers. So following two statements have the same meaning.
void fun(int arr[])
void fun(int *arr)
[] is used to make it clear that the function expects an array, it doesn’t change anything though. 
People use it only for readability so that the reader is clear about the intended parameter type. 
The bottom line is, sizeof should never be used for array parameters, a separate parameter for 
array size (or length) should be passed to fun(). So, in the given program, arr_size contains
ratio n of pointer size and integer size, this ration= is compiler dependent. 
#include void fun(int arr[], size_t arr_size) { int i; for (i = 0; i < arr_size; i++) printf(\"%d \", arr[i]); }
int main() { int i; int arr[] = {10, 20 ,30, 40}; // Use of sizeof is fine here 
size_t n = sizeof(arr)/sizeof(arr[0]); fun(arr, n); return 0; } [/sourcecode] Output: 10 20 30 40
Reference: https://www.geeksforgeeks.org/c-language-2-gq/pointers-gq/
*/
