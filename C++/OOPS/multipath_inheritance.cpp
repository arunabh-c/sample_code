// C++ program demonstrating ambiguity in Multipath
// Inheritance
 
#include <iostream>
using namespace std;
 
class ClassA {
public:
    int a;
};
 
class ClassB : virtual public ClassA {
public:
    int b;
};
 
class ClassC : virtual public ClassA {
public:
    int c;
};
 
class ClassD : public ClassB, public ClassC {
public:
    int d;
};
 
int main()
{
    ClassD obj;
 
    obj.a = 10;                  // Statement 1, Error if virtual not used for class B & C
    obj.a = 100;                 // Statement 2, Error if virtual not used for class B & C
 
    //obj.ClassB::a = 10; // Statement 3 // if not virtual used for class B & C, then this is the way out 
    //obj.ClassC::a = 100; // Statement 4 //  // if not virtual used for class B & C, then this is the way out
 
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
 
    //cout << " a from ClassB  : " << obj.ClassB::a;
    //cout << "\n a from ClassC  : " << obj.ClassC::a;
 
    cout << "\n a : " << obj.a;
    cout << "\n b : " << obj.b;
    cout << "\n c : " << obj.c;
    cout << "\n d : " << obj.d << '\n';
}

//Reference: https://www.geeksforgeeks.org/inheritance-in-c/
