Rules for Virtual Functions
The rules for the virtual functions in C++ are as follows:

1. Virtual functions cannot be static.

2. A virtual function can be a friend function of another class.

3. Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.

4. The prototype of virtual functions should be the same in the base as well as the derived class.

5. They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.

6. A class may have a virtual destructor but it cannot have a virtual constructor.

7. Compile time (early binding) VS runtime (late binding) behavior of Virtual Functions

```
// C++ program to illustrate
// concept of Virtual Functions

#include <iostream>
using namespace std;

class base {
public:
	virtual void print() { cout << "print base class\n"; }

	void show() { cout << "show base class\n"; }
};

class derived : public base {
public:
	void print() { cout << "print derived class\n"; }

	void show() { cout << "show derived class\n"; }
};

int main()
{
	base* bptr;
	derived d;
	bptr = &d;

	// Virtual function, binded at runtime
	bptr->print();

	// Non-virtual function, binded at compile time
	bptr->show();

	return 0;
}

print derived class
show base class
```

8. A pvt virtual function in derived class can be still called by base class pointer pointing to derived object. (base class is public parent of derived class) A virtual function can be private as C++ has access control, but not visibility control. As mentioned virtual functions can be overridden by the derived class but under all circumstances will only be called within the base class. Ref: https://www.geeksforgeeks.org/can-virtual-functions-be-private-in-c/#

```
// C++ program to demonstrate how a
// virtual function can be private
#include <iostream>

class base {
public:
	// default base constructor
	base() { std::cout << "base class constructor\n"; }

	// virtual base destructor
	// always use virtual base
	// destructors when you know you
	// will inherit this class
	virtual ~base()
	{
		std::cout << "base class destructor\n";
	}
	// public method in base class
	void show()
	{
		std::cout << "show() called on base class\n";
	}

	// public virtual function in base class,
	// contents of this function are printed when called
	// with base class object when called with base class
	// pointer contents of derived class are printed on
	// screen
	virtual void print()
	{
		std::cout << "print() called on base class\n";
	}
};

class derived : public base {
public:
	// default derived constructor
	derived()
		: base()
	{
		std::cout << "derived class constructor\n";
	}
	// virtual derived destructor
	// always use virtual destructors
	// when inheriting from a
	// base class
	virtual ~derived()
	{
		std::cout << "derived class destructor\n";
	}

private:
	// private virtual function in derived class overwrites
	// base class virtual method contents of this function
	// are printed when called with base class pointer or
	// when called with derived class object
	virtual void print()
	{
		std::cout << "print() called on derived class\n";
	}
};

int main()
{
	std::cout << "printing with base class pointer\n";

	// construct base class pointer with derived class
	// memory
	base* b_ptr = new derived();

	// call base class show()
	b_ptr->show();

	// call virtual print in base class but it is overridden
	// in derived class also note that print() is private
	// member in derived class, still the contents of
	// derived class are printed this code works because
	// base class defines a public interface and drived
	// class overrides it in its implementation
	b_ptr->print();

	delete b_ptr;
}
```

```
printing with base class pointer
base class constructor
derived class constructor
show() called on base class
print() called on derived class
derived class destructor
base class destructor
```
   
Reference: https://www.geeksforgeeks.org/virtual-function-cpp/
