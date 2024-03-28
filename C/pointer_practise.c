/*
1. (Q4)
#include <stdio.h>
 
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %lu ", sizeof(arri));//12; int is 4 bytes x 3
    printf("sizeof ptri = %lu ", sizeof(ptri));//8; ptr size is 8 bytes
 
    printf("sizeof arrc[] = %lu ", sizeof(arrc));//3; char is 1 bytes x 3
    printf("sizeof ptrc = %lu ", sizeof(ptrc));//8
 
    return 0;
}

2.
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

3.
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

4.
int main()
{
 char *ptr = "GeeksQuiz";
 printf("%c", *&*&*ptr);//G
 return 0;
}

5.
void fun(int arr[])
{
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[0]); //this will fail cos int arr[] is simply int *arr and sizeof(arr) could simply give size of the pointer
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

void fun(int arr[], size_t arr_size) 
{ 
  int i; 
  for (i = 0; i < arr_size; i++) 
  printf(\"%d \", arr[i]); 
}

int main() 
{ int i; 
  int arr[] = {10, 20 ,30, 40}; // Use of sizeof is fine here 
  size_t n = sizeof(arr)/sizeof(arr[0]); fun(arr, n); 
  return 0; 
 }

6.
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

7.
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


8.
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

9.
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

10.
//What does the following C-statement declare? [1 mark]
int ( * f) (int * ) ;
//A pointer to a function that takes an integer pointer as argument and returns an integer.

11.
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

12.
void swap(char *str1, char *str2) 
{ 
char *temp = str1; 
str1 = str2; 
str2 = temp; 
} //this swap will fail.The function just changes local pointer variables
// and the changes are not reflected outside the function. 
// Ref: https://www.geeksforgeeks.org/swap-strings-in-c/

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

13.
In the below statement, ptr1 and ptr2 are uninitialized pointers to int i.e. they are pointing to some random address that may or may not be valid address.
int* ptr1, ptr2;//False, ptr2 is int not pointer.

int main()
{
 int var;
 void *ptr = &var;
 *ptr = 5;
 printf("var=%d and *ptr=%d",var,*ptr);     
 return 0;//compile error cos void ptr cant just be dereferenced like that
}

14.
# define swapl (a, b) tmp = a; a = b; b = tmp
void swap2 ( int a, int b)
{
        int tmp;
        tmp = a; a = b; b = tmp;
 }
void swap3 (int*a, int*b)
{
        int tmp;
        tmp = *a; *a = *b; *b = tmp;
}
int main ()
{
        int num1 = 5, num2 = 4, tmp;
        if (num1 < num2) {swap1 (num1, num2);}
        if (num1 < num2) {swap2 (num1 + 1, num2);}
        if (num1 >= num2) {swap3 (&num1, &num2);}
        printf ("%d, %d", num1, num2);//4 5
        //if (num1 > = num2) {swap3 (&num1, &num2);}" statement is true, so call by reference will be performed
}

15.
int main()
{
    int array[5][5];
    printf("%d",( (array == *array) && (*array == array[0]) ));//1
    //Given is a 2d array array[5][5].
    //Suppose base address of array is 2000
    //array = 2000
    //*array = 2000
    //array[0] = 2000
    //So expression is something like 2000==2000 && 2000==2000 i.e. 1&&1 will return 1.
    return 0;
}

16.
int main()
{
   int a = 300; //00000001 00101100    
   char *b = (char *)&a;
   *++b = 2;//00000010 00101100
   printf("%d ",a);//556 (512 + 44)
   return 0;
}

17.
int main()
{
    int array[] = {3, 5, 1, 4, 6, 2};
    int done = 0;
    int i;

    while (done == 0)
    {
        done  = 1;
        for (i = 0; i <= 4; i++)
        {
            if (array[i] < array[i+1])
            {
                swap(&array[i], &array[i+1]);
                done = 0;
            }
            //5 3 1 4 6 2
            //5 3 4 6 2 1
        }
        for (i = 5; i >= 1; i--)
        {
            if (array[i] > array[i-1])
            {
                swap(&array[i], &array[i-1]);
                done = 0;
            }
        }
        //6 5 3 4 2 1
    }

    printf("%d", array[3]);//3
}

//Faster access to non-local variables is achieved using an array of pointers to activation records, called an activation tree

//‘ptrdata’ is a pointer to a data type. The expression *ptrdata++ is evaluated as (in C++) : *(ptrdata++). ++ (unary operator) 
//have high precedence than * (unary operator). So ++ will be evaluated first then * will be in action.

//Activation Records are required to keep the information of subroutine calls. The languages which allow subroutine calls create 
//an activation record whenever a subroutine call is made. Assembler maintains a location counter to assign storage addresses to 
//each instruction of our program. Reference counter tracks for each object, counts the number of references made by it and when 
//the count reaches zero, the object becomes inaccessible and gets destroyed. A linking loader generally performs the reallocation
//of code

18.
//The following ‘C’ statement : int * f [ ] ( ); declares: 	Array of functions returning pointers to integers

//References cannot be null, whereas pointers can; every reference refers to some object, although it may or may not be valid. 
//A reference can never be re-assigned once it is established. So, option (A) is correct.

//int (*f())[ ]; declares a function returning a pointer to an array of integers.

19.
main()
{
char g[] = "geeksforgeeks";
printf("%s", g + g[6] - g[8]);//geeks
}
*/

//Reference: https://www.geeksforgeeks.org/c-language-2-gq/pointers-gq/
