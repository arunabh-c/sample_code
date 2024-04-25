#include<iostream>
using namespace std;
 
class Base {
public:
    virtual int fun(int i) { cout << "Base::fun(int i) called"; }
};
 
class Derived: public Base {
private:
    int fun(int x)   { cout << "Derived::fun(int x) called"; }
};
 
int main()
{
    Base *ptr = new Derived;
    ptr->fun(10);// Derived::fun(int x) called 
    return 0;
}

/* fun() is public in base class. Access specifiers are checked at compile time and fun() is public in base class. 
At run time, only the function corresponding to the pointed object is called and access specifier is not checked. 
So a private function of derived class is being called through a pointer of base class. */

Reference: https://www.geeksforgeeks.org/what-happens-when-more-restrictive-access-is-given-in-a-derived-class-method-in-c/
