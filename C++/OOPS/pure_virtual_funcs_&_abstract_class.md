1. A class is abstract if it has at least one pure virtual function.

2. We can have pointers and references of abstract class type.

```#include <iostream>
using namespace std;
 
class Base {
public:
    // pure virtual function
    virtual void show() = 0;
};
 
class Derived : public Base {
public:
    // implementation of the pure virtual function
    void show() { cout << "In Derived \n"; }
};
 
int main(void)
{
    // creating a pointer of type
    // Base pointing to an object
    // of type Derived
    Base* bp = new Derived();
 
    // calling the show() function using the
    // pointer
    bp->show();
 
    return 0;
}
```

3. If we do not override the pure virtual function in the derived class, then the derived class also becomes an abstract class.

4. An abstract class can have constructors.

5. An abstract class in C++ can also be defined using struct keyword.

/*struct shapeClass
{
    virtual void Draw()=0;
}*/

Ref: https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
