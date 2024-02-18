// C Program to demonstrate the structure padding property 
#include <stdio.h> 
//#pragma pack(1)  
// Alignment requirements 
// (typical 32 bit machine) 
  
// char         1 byte 
// short int    2 bytes 
// int          4 bytes 
// double       8 bytes 

//the compiler introduces alignment requirements to every structure. It will be as that of the largest member of the structure.

// structure A 
typedef struct structa_tag { 
    char c; 
    short int s; 
} structa_t; 
//sizeof(structa_t) = 4//1(char) +  + 1(pad) + 2(short)//total size multiple of largest member (2)

// structure B 
typedef struct structb_tag { 
    short int s; 
    char c; 
    int i; 
} structb_t; 
//sizeof(structb_t) = 8//2(short) + 1(char) + 1(pad) + 4(int)//total size multiple of largest member (4)

  
// structure C 
typedef struct structc_tag { 
    char c; 
    double d; 
    int s; 
} structc_t; 
//sizeof(structc_t) = 24//1(char) + 7(pad) + 8(double) + 4(int) + 4(pad)//total size multiple of largest member (8)
  
// structure D 
typedef struct structd_tag { 
    double d; 
    int s; 
    char c; 
} structd_t; 
//sizeof(structd_t) = 16//8(double) + 4(int) + 1(char) + 3(pad)//total size multiple of largest member (8)
  
//The programmer should declare the structure members in their increasing/decreasing order of size.
int main() 
{ 
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t)); 
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t)); 
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t)); 
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t)); 
  
    return 0; 
}

/*What is Structure Packing?
Sometimes it is mandatory to avoid padded bytes among the members of the structure. For example, reading contents of ELF file header or BMP or JPEG file header. We need to define a structure similar to that of the header layout and map it. 
However, care should be exercised in accessing such members. Typically reading byte by byte is an option to avoid misaligned exceptions but there will be a hit on performance.

Most of the compilers provide nonstandard extensions to switch off the default padding like pragmas or command line switches. Consult the documentation of the respective compiler for more details.

In GCC, we can use the following code for structure packing:

#pragma pack(1)
or

struct name {
    ...
}__attribute__((packed));*/

//Reference: https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
