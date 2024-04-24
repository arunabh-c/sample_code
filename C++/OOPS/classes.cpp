#include <iostream>

using namespace std;

class Base 
{
    public:
    int a = 0;
protected:
    int y;
 
private:
    int z;
};

class Base1 {

public:
int b1 = 0;

};

class Derived : private Base, private Base1 //makes public & protected members of Base private in the derived class

{// int z in Base class not accessible; int y is protected
    public:
int b = 4;
void print_op();
};

void Derived::print_op()//defining function outside class
{
    cout<<Derived::a<<endl;
}

int main()
{
  Derived geeks;

  cout<<geeks.b<<endl;
  
  geeks.print_op();

    return 0;
}


Reference: https://www.geeksforgeeks.org/difference-between-base-class-and-derived-class-in-c/
