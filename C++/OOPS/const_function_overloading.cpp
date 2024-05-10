
#include<iostream> 
using namespace std; 
 
void fun(const int i) // PROGRAM 1 (Fails in compilation) 
{ 
    cout << "fun(const int) called "; 
} 
void fun(int i) // PROGRAM 1 (Fails in compilation) 
{ 
    cout << "fun(int ) called " ; 
} 

/*the parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main(). 
Hence fun() cannot modify the 'i' in main() either ways. hence they appear as same 
and hence colliding functions const and non const parameter overloading only possible
if passing by reference*/

void fun(char *a) 
{ 
cout << "non-const fun() " << a; 
} 
 
void fun(const char *a) 
{ 
cout << "const fun() " << a; 
} 


void fun(const int &i) 
{ 
    cout << "fun(const int &) called "; 
} 
void fun(int &i) 
{ 
    cout << "fun(int &) called " ; 
} 

int main() 
{ 
    const int i = 10; 
    fun(i); 

    const char *ptr = "GeeksforGeeks"; 
    fun(ptr); 

    const int i = 10; 
    fun(i); 
  
    return 0; 
} 
//ref: https://www.geeksforgeeks.org/function-overloading-and-const-functions/
