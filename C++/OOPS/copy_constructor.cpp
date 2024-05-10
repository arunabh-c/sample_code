#include <iostream>
#include <string.h>
using namespace std;
class student {
    int rno;
    char name[50];
    double fee;
 
public:
    student(int, char[], double);
    student(student& t) // copy constructor
    {
        rno = t.rno;//member-wise copy
        strcpy(name, t.name);
        fee = t.fee;
    }
    void display();
};
 
student::student(int no, char n[], double f)
{
    rno = no;
    strcpy(name, n);
    fee = f;
}
 
void student::display()
{
    cout << endl << rno << "\t" << name << "\t" << fee;
}
 
int main()
{
    student s(1001, "Manjeet", 10000);
    s.display();
 
    student manjeet(s); // copy constructor called
    manjeet.display();
 
    return 0;
}

/*
1. If you pass the object by value in the !!!copy constructor!!!, 
it would result in a !!!recursive call!!! to the copy constructor itself. 
This happens because passing by value involves making a copy, 
and making a copy involves calling the copy constructor, 
leading to an infinite loop. Using a reference avoids this 
recursion. So we use reference of Objects to avoid infinite calls.*/

/** Return Value Optimization Or Copy Elision **/
/*the compiler prevents the making of extra copies which results in saving space and 
better the program complexity(both time and space); Hence making the code more optimized*/

// C++ program to demonstrate
// the working of copy elision

class GFG {
public:
	void print() { cout << " GFG!"; }
};

int main()
{
	GFG G;
	for (int i = 0; i <= 2; i++) {
		G.print();
		cout << "\n";//compiler could print GFG 1x,2x or 3x
	}
	return 0;
}

/*We need to define our own copy constructor only if an object has pointers or 
any runtime allocation of the resource like a file handle, a network connection, etc.*/

/*Deep copy is possible only with a user-defined copy constructor. In a user-defined copy constructor, 
we make sure that pointers (or references) of copied objects point to new memory locations.  */

/*The main difference between Copy Constructor and Assignment Operator is that the Copy constructor 
makes a new memory storage every time it is called while the assignment operator does not make new memory storage.*/

//example of custom copy constructor to perform deep copy

// C++ program to demonstrate the
// Working of Copy constructor
#include <cstring>

class String {
private:
	char* s;
	int size;

public:
	String(const char* str = NULL); // constructor
	~String() { delete[] s; } // destructor
	String(const String&); // copy constructor
	void print()
	{
		cout << s << endl;
	} // Function to print string
	void change(const char*); // Function to change
};

// In this the pointer returns the CHAR ARRAY
// in the same sequence of string object but
// with an additional null pointer '\0'
String::String(const char* str)
{
	size = strlen(str);
	s = new char[size + 1];
	strcpy(s, str);
}

void String::change(const char* str)
{
	delete[] s;
	size = strlen(str);
	s = new char[size + 1];
	strcpy(s, str);
}

String::String(const String& old_str)
{
	size = old_str.size;
	s = new char[size + 1];
	strcpy(s, old_str.s);
}

int main()
{
	String str1("GeeksQuiz");
	String str2 = str1;

	str1.print(); // GeeksQuiz
	str2.print(); //GeeksQuiz

	str2.change("GeeksforGeeks");

	str1.print(); // GeeksQuiz
	str2.print(); // GeeksforGeeks
	return 0;
}

//Yes, a copy constructor can be made private. When we make a copy constructor private in a class, 
// objects of that class become non-copyable. This is particularly useful when our class has pointers
// or dynamically allocated resources. so that users get compiler errors rather than surprises at runtime.

//Why argument to a copy constructor should be const? One reason for passing const reference is, that we 
// should use const in C++ wherever possible so that objects are not accidentally modified. This is one 
// good reason for passing reference as const.

class Test
{
/* Class data members */
public:
Test(Test &t) { /* Copy data members from t*/}
Test()     { /* Initialize data members */ }
};
 
Test fun()
{
    cout << "fun() Called\n";
    Test t;
    return t;
}
 
int main()
{
    Test t1;
    Test t2 = fun();
    return 0;
}

//if we dont make copy constructor argument constant then in line 170, compiler creates a temporary object which
//is copied to t2. The reason for compiler error is that compiler-created temporary objects cannot be bound to 
// non-const references and the original program tries to do that.


// Copy Constructor
Geeks Obj1(Obj);
or
Geeks Obj1 = Obj;

// Default assignment operator
Geeks Obj2;
Obj2 = Obj1;

//In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.

