// C++ program to demonstrate working of Copy Elision
#include <iostream>
using namespace std;

class B {
public:
	B(const char* str = "\0") // default constructor
	{
		cout << "Constructor called" << endl;
	}

	B(const B& b) // copy constructor
	{
		cout << "Copy constructor called" << endl;
	}
};

int main()
{
	B ob = "copy me";
	return 0;
}

//o/p: Constructor called

/*
According to theory, when the object “ob” is being constructed, one argument constructor is used to convert 
“copy me” to a temporary object & that temporary object is copied to the object “ob”. So the statement

     B ob = "copy me"; // Also RVO form to represent
should be broken down by the compiler as:

     B ob = B("copy me"); // Also NRVO form to represent
However, most C++ compilers avoid such overheads of creating a temporary object & then copying it.

The modern compilers break down the statement
    B ob = "copy me"; //copy initialization
as
    B ob("copy me"); //direct initialization
and thus eliding call to copy constructor.

However, if we still want to ensure that the compiler doesn’t elide the call to copy constructor 
[disable the copy elision], we can compile the program using the “-fno-elide-constructors” option with C++ 

Output:

  GEEKSFORGEEKS:~$ g++ copy_elision.cpp -fno-elide-constructors
  GEEKSFORGEEKS:~$ ./a.out                    /\---This is a flag which calls copy constructor statement and
  Constructor called                               reduce compiler's optimiziblity
  Copy constructor called
*/

//Ref: https://www.geeksforgeeks.org/copy-elision-in-cpp/#
