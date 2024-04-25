// A program with virtual destructor
#include <iostream>
 
using namespace std;
 
class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    virtual ~base()//if this isnt made virtual then only base class destructor called and derived class destructor not called leading to undefined behavior
    { cout << "Destructing base\n"; }     
};
 
class derived : public base {
  public:
    derived()     
    { cout << "Constructing derived\n"; }
    ~derived()
    { cout << "Destructing derived\n"; }
};
 
int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
}

//Reference: https://www.geeksforgeeks.org/virtual-destructor/
