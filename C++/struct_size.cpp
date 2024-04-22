#include <stdio.h>

struct A {
    int a;//4->8//8//next pointer needs to be 8 byte alligned
    int* b;//8//16
    char c;//1->8//24
    char* d;//8//32
};

struct B {
    int* b;//8//8
    char c;//1->4//12
    int a;//4//16
    char* d;//8//24
};

struct C {
    int* b;//8//8
    char* d;//8//16
    int a;//4//20
    char c;//1->4//24
};

int main()
{
    /*struct A aa;
    printf("Size of struct A: %lu\n", sizeof(struct A));
    printf("Size of object a: %lu\n", sizeof(aa));
    
    printf("address of A.a: %p\n",&aa.a);
    printf("address of A.b: %p\n",&aa.b);
    printf("address of A.c: %p\n",&aa.c);
    printf("address of A.d: %p\n",&aa.d);*/
    
    struct B bb;
    printf("Size of struct B: %lu\n", sizeof(struct B));
    printf("Size of object b: %lu\n", sizeof(bb));

    printf("address of BB.b: %p\n",&bb.b);
    printf("address of BB.c: %p\n",&bb.c);
    printf("address of BB.a: %p\n",&bb.a);
    printf("address of BB.d: %p\n",&bb.d);

    struct C cc;
    printf("Size of struct C: %lu\n", sizeof(struct C));
    printf("Size of object cc: %lu\n", sizeof(cc));

    return 0;

}
