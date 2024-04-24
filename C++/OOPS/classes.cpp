#include <iostream>

using namespace std;

class Base 
{
    public:
    int a = 0;
};

class Derived : private Base //makes public & protected members of Base private in the derived class

{
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
