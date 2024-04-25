// C++ program demonstrating ambiguity in Multipath
// Inheritance

#include <iostream>
using namespace std;


class Base1 {
  
  public:
  virtual void func1()
  {
      cout<<" Base1 func1"<<endl;
  }
  
  void func2()
  {
      cout<<"Base1 func2"<<endl;
  }
    
};

class Derived : public Base1{

  public:
  void func1()
  {
      cout<<" Derived func1"<<endl;
  }
  
  void func2()
  {
      cout<<"Derived func2"<<endl;
  }
    
    
};

int main ()
{
    Derived d;
    Base1* b1 = &d;//new Derived();
    b1->func1();//goes for derived func1 as base is a virtual func
    b1->func2();//goes for base1 func2 as its not virtual void
    b1->Base1::func1();//syntax to force the exact function
}
