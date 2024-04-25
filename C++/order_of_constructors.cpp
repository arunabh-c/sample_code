#include<iostream>
using namespace std;
 
class A
{
public:
  A()  { cout << "A's constructor called" << endl; }
  ~A()  { cout << "A's destructor called" << endl; }
};
 
class B
{
public:
  B()  { cout << "B's constructor called" << endl; }
  ~B()  { cout << "B's destructor called" << endl; }
};
 
class C: public B, public A  // Note the order
{
public:
  C()  { cout << "C's constructor called" << endl; }
  ~C()  { cout << "C's destructor called" << endl; }
};
 
int main()
{
    C c;
    return 0;
}

/*B's constructor called
A's constructor called
C's constructor called
C's destructor called
A's destructor called
B's destructor called
*/
