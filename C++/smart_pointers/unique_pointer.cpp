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

  /*will give compile time error 
    unique_ptr<A> p2 = p1; 
    p2->printA()*/

  // now address stored in p1 shpould get copied to p2 
    unique_ptr<A> p2 = move(p1); 
  
    p2->printA(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
    return 0; 
}
