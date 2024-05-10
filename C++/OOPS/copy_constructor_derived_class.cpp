// C++ Program to Declare a copy constrcutor in a derived
// class

#include <iostream>
using namespace std;

// Base class
class Base {
protected:
    string name;
    int id;

public:
    // constructor to initialize data members
    Base(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    // Copy constructor of base class
    Base(const Base& other)
    {
        this->name = other.name;
        this->id = other.id;
        cout << "Base class copy constructor called."
             << endl;
    }
};

// Derived class
class Derived : public Base {
protected:
    // Data member of the derived class
    int id2;

public:
    // Constructor of derived class to initialize data
    // members
    Derived(string name, int id, int id2)
        : Base(name, id)
    {
        this->id2 = id2;
    }

    // Copy constructor of derived class
    Derived(const Derived& obj)
        : Base(obj)
    { // call  the copy constructor of base class
        // explicitly copy other data members in the derived
        // class
        this->id2 = obj.id2;
        cout << "Derived class copy constructor called."
             << endl;
    }

    // Function to print details of the derived class
    void print()
    {
        cout << "Name: " << this->name
             << " Id: " << this->id << " Id2: " << this->id2
             << endl;
    }
};

int main()
{
    cout << "Original Object: ";
    Derived obj1("John", 100, 200);
    obj1.print();
    Derived obj2 = obj1; // Copying obj1 to obj2
    cout << "Copied Object: ";
    obj2.print();

    return 0;
}
//Ref: https://www.geeksforgeeks.org/how-to-declare-a-copy-constructor-in-a-derived-class-in-cpp/
