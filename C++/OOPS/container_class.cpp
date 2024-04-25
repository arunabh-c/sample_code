// C++ program to illustrate the 
// concept of containership 
#include <iostream> 
using namespace std; 
  
class first { 
public: 
    void showf() 
    { 
        cout << "Hello from first class\n"; 
    } 
}; 
  
// Container class 
class second { 
  
    // Create object of the first-class 
    first f; 
  
public: 
    // Define Constructor 
    second() 
    { 
        // Call function of first-class 
        f.showf(); 
    } 
}; 
  
// Driver Code 
int main() 
{ 
    // Create object of second class 
    second s; 
} 
