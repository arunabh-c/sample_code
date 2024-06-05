// Write a templated function called |Init| that is templated over two types |T| and
// |U|, where the later is a template parameter pack. Leave the body of this
// function empty. This function returns nothing and as arguments it takes in a
// unique pointer to |T| and an ravlue reference to |U|.

#include 



using namespace std;


template <typename> T
template <typename> U
void Init(unique_pointer<T> up, &&U)
{
  
}


std::enable_if 
// Then write a speciliazed template for this function, where it is only
// compiled when T is not constructible from U.

#define IC is_constructible<T, U>::value

#if
