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

void f(int *p, int *q) 
{ 
  p = q; 
  *p = 2; 
} 
int i = 0, j = 1; 
int main() 
{ 
  f(&i, &j); 
  printf("%d %d", i, j); //0 2
  getchar(); 
  return 0; 
}

Consider this C code to swap two integers and these five statements after it:
void swap(int *px, int *py) 
{ 
   *px = *px - *py; 
   *py = *px + *py; 
   *px = *py - *px; 
}
S1: will generate a compilation error S2: may generate a segmentation fault at runtime depending 
on the arguments passed S3: correctly implements the swap procedure for all input pointers referring 
to integers stored in memory locations accessible to the process S4: implements the swap procedure 
correctly for some but not all valid input pointers S5: may add or subtract integers and pointers.

S2: May generate segmentation fault if value at pointers px or py is constant or px or py points 
to a memory location that is invalid S4: May not work for all inputs as arithmetic overflow can occur

int f(int x, int *py, int **ppz) 
{ 
  int y, z; 
  **ppz += 1;//c=5
   z  = **ppz;//z=5
  *py += 2; //c=7
   y = *py; //y=7
   x += 3;//x=7
   return x + y + z; 
} 
   
void main() 
{ 
   int c, *b, **a; 
   c = 4; 
   b = &c; 
   a = &b; 
   printf("%d ", f(c, b, a)); 
   return 0;
}

Predict the output of following program
#include<stdio.h>
int main()
{
    int a = 12;
    void *ptr = (int *)&a;
    printf("%d", *ptr);//compile error -> do this instead ->printf("%d", *(int *)ptr);
    getchar();
    return 0;
}

#define print(x) printf("%d ", x)
int x;
void Q(int z)
{
    z += x;//z=12
    print(z);//12
}
void P(int *y)
{
    int x = *y + 2;//x=7
    Q(x);
    *y = x - 1;//sx =6
    print(x);//7
}
main(void)
{
    x = 5;
    P(&x);
    print(x);//6
}
Ans: 12 7 6

//What does the following C-statement declare? [1 mark]
int ( * f) (int * ) ;
//A pointer to a function that takes an integer pointer as argument and returns an integer.

void f(char**);
int main()
{
    char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
    f(argv);
    return 0;
}
void f(char **p)
{
    char *t;
    t = (p += sizeof(int))[-1];
    printf("%sn", t);//gh
}

void swap(char *str1, char *str2) 
{ 
char *temp = str1; 
str1 = str2; 
str2 = temp; 
} //this swap will fail. Ref: https://www.geeksforgeeks.org/swap-strings-in-c/

//Right way to swap:
void swap2(char *str1, char *str2) 
{ 
char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char)); 
strcpy(temp, str1); 
strcpy(str1, str2); 
strcpy(str2, temp); 
free(temp); 
} 

int main() 
{ 
char *str1 = "geeks"; 
char *str2 = "forgeeks"; 
swap(str1, str2); 
printf("str1 is %s, str2 is %s", str1, str2); 
getchar(); 
return 0; 
} 


*/

//Reference: https://www.geeksforgeeks.org/c-language-2-gq/pointers-gq/
