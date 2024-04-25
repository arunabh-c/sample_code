Rules for Virtual Functions
The rules for the virtual functions in C++ are as follows:

Virtual functions cannot be static.
A virtual function can be a friend function of another class.
Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
The prototype of virtual functions should be the same in the base as well as the derived class.
They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
A class may have a virtual destructor but it cannot have a virtual constructor.

Reference: https://www.geeksforgeeks.org/virtual-function-cpp/
