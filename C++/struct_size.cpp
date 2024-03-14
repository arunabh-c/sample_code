#include <stdio.h>

struct A {
    int a;//4->8//8//next pointer needs to be 8 byte alligned
    int* b;//8//16
    char c;//1->8//24
    char* d;//8//32
};

struct B {
    int* b;//8//8
    char c;//1//9
    int a;//4->7//16
    char* d;//8//24
};

int main()
{
    struct A a;
    printf("Size of struct A: %lu\n", sizeof(struct A));
    printf("Size of object a: %lu\n", sizeof(a));
    
    struct B b;
    printf("Size of struct B: %lu\n", sizeof(struct B));
    printf("Size of object b: %lu\n", sizeof(b));
    return 0;
}
