
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
Hence fun() cannot modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ 
is received as a const parameter or a normal parameter. When we pass by reference 
or pointer, we can modify the value referred or pointed, so we can have two 
versions of a function, one which can modify the referred or pointed value,
other which can not.*/

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
