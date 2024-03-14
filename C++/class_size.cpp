#include <bits/stdc++.h>
using namespace std;

class Base {
private:
    static int i;
    int a;//4//4
    char b;//1->4//8
};//8 bytes

class Derived1 : public Base {//8
private:
    int c;//4//12
    char d;//1->4//16
};//16 bytes

class Derived2 : public Base {
private:
    char d;//1->3//8
    int c;//4//12
};//12 bytes

class Derived3 : virtual public Base {//8//16

private:
    char d;//1->4//20
    int c;//4//24
};

class A {
};

int main()
{
    Base b;
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;
    printf("Size of class Base: %lu\n", sizeof(Base));
    printf("Size of object b: %lu\n", sizeof(b));
    printf("Size of class Derived1: %lu\n", sizeof(Derived1));
    printf("Size of object d1: %lu\n", sizeof(d1));
    printf("Size of class Derived2: %lu\n", sizeof(Derived2));
    printf("Size of object d2: %lu\n", sizeof(d2));
    printf("Size of class Derived3: %lu\n", sizeof(Derived3));
    printf("Size of object d3: %lu\n", sizeof(d3));
    printf("Size of class A: %lu\n", sizeof(A));
    return 0;
}

//Reference: nhttps://www.includehelp.com/cpp-tutorial/size-of-a-class-in-cpp-padding-alignment-in-class-size-of-derived-class.aspx
