#include <iostream>
using namespace std;

class A {

virtual void SomeFunction();//8//24
private: 
        float iMem1;//4//data members added first?
        const int iMem2;//4//8 
        static int iMem3; 
        char iMem4;//1->8//16
};

class B1 { 
        char c;//1->4 
        int int1;//4//8
        int int2;//4//12 
        int i;//4//16 
        long l;//8//24
        short s;//2->8//32
};

class B2 {//largest data member first to save space
        long l;//8
        int int1;//4//12 
        int int2;//4//16
        int i;//4//20
        short s;//2//22
        char c;//1->2//24
};

class C1: public A {//derived class contains size of parent class + its own members
virtual void SomeOtherFunction();//vtable pointer already allocated in class A size calc so no additional 8 bytes
int iMem;//4//24 looks like class A padding dropped to house iMem
};

class C2: public A {//derived class contains size of parent class + its own members
//looks like vtable pointer size retained despite no virtual function
int iMem;//4//24 looks like class A padding dropped to house iMem
};

class D1: public virtual A {//8//32// 8 bytes virtual base pointer
int iMem;//4->8//40//looks like class A padding not dropped to house iMem
};

class D2: public virtual A {
int iMem;
};

class E: public D1, public D2 { 
};

int main()
{

    cout<<"sizeof(void*): "<<sizeof(void*)<<endl;//8
    cout<<"sizeof(A): "<<sizeof(A)<<endl;//24
    cout<<"sizeof(B1): "<<sizeof(B1)<<endl;//32
    cout<<"sizeof(B2): "<<sizeof(B2)<<endl;//24
    cout<<"sizeof(C1): "<<sizeof(C1)<<endl;//24
    cout<<"sizeof(C2): "<<sizeof(C2)<<endl;//24
    cout<<"sizeof(D1): "<<sizeof(D1)<<endl;//40
    cout<<"sizeof(D2): "<<sizeof(D2)<<endl;//40
    cout<<"sizeof(E): "<<sizeof(E)<<endl;//56
    return 0;
}
