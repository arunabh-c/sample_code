struct s {
    char a;
    int b;
    double c;
    char d[10];
};

// declare s1 as a variable of type struct s
struct s s1;
 
// set a, b, and c to a value of their respective type
s1.a = 'H';
s1.b = 42;
s1.c = 3.14;
 
// set d to the string "Hello" by setting each character individually
s1.d[0] = 'H';

struct s s1 = {
    'H',
    42,
    3.14,
    "Hello"
};//C89 Standard allows us to initialize a structure variable like this

struct s s1 = {
    .a = 'H',
    .b = 42,
    .c = 3.14,
    .d = "Hello"
};//DESIGNATED INITIALIZERS C99 STANDARD

typedef struct Vector2D {
    float x;
    float y;
} Vector2D;

Vector2D vector;

//DYNAMIC ALLOCATION
struct Vector2D *vec;
vec = malloc(sizeof(struct Vector2D));
if (vec == NULL) {
    // handle allocation failure
}
memset(vec, 0, sizeof(struct Vector2D));
free(vec);

//NESTED STRUCTURES
typedef struct Vector2D {
    float x;
    float y;
} Vector2D;
typedef struct Sprite {
    char *name;
    Vector2D position;
    uint8_t *gfx_data;
} Sprite;

//SELF REFERENTIAL STRUCTURES
/*struct tree {
    struct tree left; //<==THIS WILL GIVE COMPILE ERROR, this would create an endless 
    //recursion and the structure would take up an infinite amount of memory.
    struct tree right;
    char str[32];
};*/

struct tree {
    struct tree *left;
    struct tree *right;
    char str[32];
};

//ELEMENT ORDER & ADDRESSING
struct abc {
    char a;
    int b;
    double c;
};
	
sizet_t offset_b = offsetof(struct abc, b);//might return 8

//PACKING
struct s {
    char a;
    int b;
    double c;
    char d[10];
} __attribute__((packed)); //this ensures no padding

//BITFIELDS
struct ScreenCharacter {
    unsigned int character : 7;//only use 7 bits
    unsigned int fgcolor : 11; // 2^11 => 2048 possible colors
    unsigned int bgcolor : 11; // 2^11 => 2048 possible colors
    unsigned int isBold : 1;
    unsigned int isItalic : 1;
    unsigned int isUnderline : 1;
};

/*struct ScreenCharacter ch;
printf("%p\n", &ch.fgcolor);//<= WONT COMPILE not possible to get the address of a bitfield member
*/

//ONLY bool, unsigned int, & int cane be used for bitfields in C99

//FLEXIBLE ARRAY MEMMBERS
struct DynamicString {
    int len;
    char str[];
};//size of the struct will then be as if the last member did not exist. C99

int n = 30;
DynamicString *str;
 
str = malloc(sizeof(struct DynamicString) + n * sizeof(char));
if (str == NULL) {
    fprintf(stderr, "ERROR: Failed to allocate memory\n");
    exit(1);
}
str->len = n;

//Ref: https://abstractexpr.com/2023/06/29/structures-in-c-from-basics-to-memory-alignment/

//Q1.
#include<stdio.h>
struct st
{
    int x;
    static int y;
};

int main()
{
    printf(\"%d\", sizeof(struct st));
    return 0;
}
//In C, struct and union types cannot have static members. In C++, struct types are 
//allowed to have static members, but union cannot have static members in C++ also.

//Q2.
union test
{
    int x;
    char arr[8];
    int y;
};

int main()
{
    printf(\"%d\", sizeof(union test));//size is 8 largest member
    return 0;
}

//Q3.
union test
{
    int x;
    char arr[4];
    int y;
};

int main()
{
    union test t;
    t.x = 0;
    t.arr[1] = \'G\';
    printf(\"%s\", t.arr);
    return 0;
}

//Since x and arr[4] share the same memory, when we set x = 0, 
//all characters of arr are set as 0. O is ASCII value of \'\\0\'. 
//When we do "t.arr[1] = \'G\'", arr[] becomes "\\0G\\0\\0". 
//When we print a string using "%s", the printf function starts 
//from the first character and keeps printing till it finds a \\0.
//Since the first character itself is \\0, nothing is printed.

//Q4.
# include <iostream>
# include <string.h>
using namespace std;

struct Test
{
  char str[20];
};

int main()
{
  struct Test st1, st2;
  strcpy(st1.str, \"GeeksQuiz\");
  st2 = st1;
  st1.str[0] = \'S\';
  cout << st2.str;//GeeksQuiz
  return 0;
}

//Array members are deeply copied when a struct variable is 
//assigned to another one.

//Q5.
//Anyone of the followings can be used to declare a node for a 
//singly linked list. If we use the first declaration, “struct
//node * nodePtr;” would be used to declare pointer to a node.
//If we use the second declaration, “NODEPTR nodePtr;” can be 
// used to declare pointer to a node.

/* First declaration */
struct node {
int data;
struct node * nextPtr;
};

/* Second declaration */
typedef struct node{
int data;
NODEPTR nextPtr;
} * NODEPTR

//The typedef usage is incorrect. Basically, we can’t use yet 
//to be typedef-ed data type inside while applying typedef itself.
//Here, NODEPTR is yet to be defined (i.e. typedef-ed) and we 
//are using NODEPTR inside the struct itself.

//Q6.
/* First declaration */
typedef struct node
{
 int data;
 struct node *nextPtr;
}* NODEPTR;

/* Second declaration */
struct node
{
 int data;
 struct node * nextPtr;
};
typedef struct node * NODEPTR;

//Yes. Both are equivalent. Either of the above declarations can 
//be used for “NODEPTR nodePtr;”. In fact, first one is the compact
//form of second one.

//Q7.
//In the following program snippet, both s1 and s2 would be 
//variables of structure type defined as below and there won\'t be any compilation issue.
typedef struct Student
{
 int rollno;
 int total;
} Student;

Student s1;
struct Student s2;
//At first, it may seem that having same ‘struct tag name’ and ‘typedef name’ 
//would cause issue here. But it’s perfectly fine for both of them having same name. 
//s1 is defined using typedef name Student while s2 is defined using struct tag name Student.

//Q8.
#include \"stdio.h\"

int main()
{
 struct {int a[2];} arr[] = {{1},{2}};

 printf(\"%d %d %d %d\",arr[0].a[0],arr[0].a[1],arr[1].a[0],arr[1].a[1]);//1 0 2 0

 return 0;
}
//Here, struct type definition and definition of arr using that struct type has been 
//done in the same line. This is okay as per C standard. Even initialization is 
//also correct. The point to note is that array size of arr[] would be 2 i.e. 
//2 elements of this array of this struct type. This is decided due to the way 
//it was initialized above. Here, arr[0].a[0] would be 1 and arr[1].a[0] would be 2. 
//The remaining elements of the array would be ZERO.

//Q9.
#include \"stdio.h\"

int main()
{
 struct {int a[2], b;} arr[] = {[0].a = {1}, [1].a = {2}, [0].b = 1, [1].b = 2};

 printf(\"%d %d %d and\",arr[0].a[0],arr[0].a[1],arr[0].b);// 1 0 1
 printf(\"%d %d %d\\n\",arr[1].a[0],arr[1].a[1],arr[1].b);//2 0 2

 return 0;
}

//Q10.
#include <stdio.h>

int main()
{
    struct {
        int i;
        char c;
    } myVar = {.i = 100, .c = 'A'};
    
    printf("%d %c", myVar.i, myVar.c);//100 A
    
    return 0;
}

//Q11.
struct addr {
     char city[10];
     char street[30];
     int pin ;
};

struct {
char name[30];
int gender;
struct addr locate;
} person , *kd = &person ;
//Then *(kd -> name +2) can be used instead of
//*(kd -> name +2) = *((*kd).name + 2 ) 

//Q12.
struct {int a[2];} arr[] = {1,2};

//Since size of array arr isn’t given explicitly, it would be decided based on 
//the initialization here. Without any curly braces, arr is initialized 
//sequentially i.e. arr[0].a[0] would be 1 and arr[0].a[1] would be 2. 
//There’s no further initialization so size of arr would be 1.

//Q13.
#include‹stdio.h›
int main()
{
    struct site
    {
        char name[] = \"GeeksQuiz\";//compile error
        int no_of_pages = 200;
    };
    struct site *ptr;
    printf(\"%d \", ptr->no_of_pages);
    printf(\"%s\", ptr->name);
    getchar();
    return 0;
}

//When we declare a structure or union, we actually declare a new data 
//type suitable for our purpose. So we cannot initialize values as it is 
//not a variable declaration but a data type declaration.

//Ref: https://www.geeksforgeeks.org/quizzes/structure-union-gq/?page=1
