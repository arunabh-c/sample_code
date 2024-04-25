#include <iostream>
using namespace std;


class Complex{
  public:
  int real, comp;
  Complex(int x, int y) : real(x),comp(y){}
  
  Complex operator+ (const Complex& c2)
  {
      Complex c(0,0);
      c.real = real + c2.real;
      c.comp = comp + c2.comp;
      return c;
  }

  void princ()
  {
      cout<<"Real is: "<<real<<", imaginary is: "<<comp<<endl;
  }
};

int main ()
{
   Complex c1(5,6), c2(3,4);
   
   Complex c3 = c1 + c2;
    
   c3.princ();
   
   return 0;
    
}
