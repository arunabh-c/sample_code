#include<iostream> 
using namespace std; 
  
class Test 
{ 
    int *ptr; 
public: 
    Test (int i = 0)      { ptr = new int(i); } 
    void setValue (int i) { *ptr = i; } 
    void print()          { cout << *ptr << endl; } 
    Test & operator = (const Test &t); 
}; 
  
Test & Test::operator = (const Test &t)  // overloaded assignment operator to create deep copy
{ 
   // Check for self assignment 
   if(this != &t) 
     *ptr = *(t.ptr); 
  
   return *this; 
} 
  
int main() 
{ 
    Test t1(5); 
    Test t2; 
    t2 = t1; 
    t1.setValue(10); 
    t2.print(); //5
    return 0; 
} 

/*While overloading assignment operator, we must check for self assignment (line 17). Otherwise assigning an object to itself 
may lead to unexpected results (See this). Self assignment check is not necessary for the above ‘Test’ class, because 
‘ptr’ always points to one integer and we may reuse the same memory. But in general, it is a recommended practice 
to do self-assignment check.*/

//Ref: https://www.geeksforgeeks.org/assignment-operator-overloading-in-c/

