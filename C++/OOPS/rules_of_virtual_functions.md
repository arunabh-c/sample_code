Rules for Virtual Functions
The rules for the virtual functions in C++ are as follows:

1. Virtual functions cannot be static.

2. A virtual function can be a friend function of another class.

3. Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.

4. The prototype of virtual functions should be the same in the base as well as the derived class.

5. They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.

6. A class may have a virtual destructor but it cannot have a virtual constructor.

7. A pvt virtual function in derived class can be still called by base class pointer pointing to derived object. (base class is public parent of derived class) A virtual function can be private as C++ has access control, but not visibility control. As mentioned virtual functions can be overridden by the derived class but under all circumstances will only be called within the base class. Ref: https://www.geeksforgeeks.org/can-virtual-functions-be-private-in-c/#
   
Reference: https://www.geeksforgeeks.org/virtual-function-cpp/
