//constexpr is a feature added in C++ 11. The main idea is a performance improvement of programs by doing computations at compile time rather than run time.

// C++ program to demonstrate constexpr function for product
// of two numbers. By specifying constexpr, we suggest
// compiler to evaluate value at compile time
#include <iostream>

constexpr int product(int x, int y) { return (x * y); }

const double PI = 3.14159265359;
constexpr double ConvertDegreeToRadian(const double& dDegree)
{
    return (dDegree * (PI / 180));
}

constexpr long int fib(int n) 
{ 
    return (n <= 1) ? n : fib(n-1) + fib(n-2); 
} 

// A class with constexpr 
// constructor and function 
class Rectangle 
{ 
    int _h, _w; 
public: 
    // A constexpr constructor 
    constexpr Rectangle(int h, int w) : _h(h), _w(w) {} 
    
    constexpr int getArea() const { return _h * _w; } 
}; 

int main()
{
    constexpr int x = product(10, 20);
    std::cout << x;

    auto dAngleInRadian = ConvertDegreeToRadian(90.0);
    cout << "Angle in radian: " << dAngleInRadian;

  constexpr long int res = fib(30); 
    std::cout << res; 
  /*When the above program is run on GCC, it takes 0.003 seconds
  Change,
  constexpr long int res = fib(30);  
  To,
  long int res = fib(30);
   After making the above change, the time taken by the program becomes higher by 0.017 seconds.
   because the result of constexpr is not used in a const expression*/

  // Below object is initialized at compile time 
    constexpr Rectangle obj(10, 20); 
    std::cout << obj.getArea(); 

  /*A constructor that is declared with a constexpr specifier is a constexpr constructor 
  also constexpr can be used in the making of constructors and objects. A constexpr constructor is implicitly inline.
Restrictions on constructors that can use constexpr:
> No virtual base class
> Each parameter should be literal
> It is not a try block function*/
    return 0;
}
/*
1. In C++ 11, a constexpr function should contain only one return statement. 

2. C++ 14 allows more than one statement.

3. constexpr function should refer only to constant global variables.

4. constexpr function can call only other constexpr functions not simple functions.

5. The function should not be of a void type.

6. In C++11, prefix increment (++v) was not allowed in constexpr function but this restriction has been removed in C++14.*/


/*constexpr vs const 
They serve different purposes. constexpr is mainly for optimization while const is for practically const objects like the value of Pi. 
Both of them can be applied to member methods. Member methods are made const to make sure that there are no accidental changes in the method. 
On the other hand, the idea of using constexpr is to compute expressions at compile time so that time can be saved when the code is run. 
const can only be used with non-static member functions whereas constexpr can be used with member and non-member functions, even with constructors
but with condition that argument and return type must be of literal types. */

//Ref: https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/#
