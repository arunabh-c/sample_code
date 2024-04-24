// C++ Program to implement unique_ptr 
#include <iostream> 
#include <memory> 
using namespace std; 
  
struct A { 
    void printA() { cout << "A struct...." << endl; } 
}; 
  
int main() 
{ 
    unique_ptr<A> p1(new A); 
    p1->printA(); 
  
    // displays address of the containing pointer 
    cout << p1.get() << endl; 
    return 0; 
}
