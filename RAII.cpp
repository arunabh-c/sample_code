#include <memory>
class widget
{
private:
    //int* data; //old way of defining pointer
    std::unique_ptr<int[]> data;
public:
    //widget(const int size) { data = new int[size]; } // acquire
    widget(const int size) { data = std::make_unique<int[]>(size); }
    //~widget() { delete[] data; } // release. explicit destructor not needed anymore as unique pointer destructs automatically
    void do_something() {}
};

void functionUsingWidget() {
    widget w(1000000);  // lifetime automatically tied to enclosing scope
                        // constructs w, including the w.data gadget member
    // ...
    w.do_something();
    // ...
} // automatic destruction and deallocation for w and w.data


/*
Modern C++ avoids using heap memory as much as possible by declaring objects on the stack. 
When a resource is too large for the stack, then it should be owned by an object. 
As the object gets initialized, it acquires the resource it owns. The object is then responsible 
for releasing the resource in its destructor. The owning object itself is declared on the stack. 
The principle that objects own resources is also known as "resource acquisition is initialization," or RAII.

Since C++11, there's a better way to write the previous example: by using a smart pointer from the standard library. 
The smart pointer handles the allocation and deletion of the memory it owns. Using a smart pointer eliminates the 
need for an explicit destructor in the widget class.

*/
