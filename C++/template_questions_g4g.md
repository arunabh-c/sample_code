1) Template is a feature of C++ that allows us to write one code for different data types.

2) We can write one function that can be used for all data types including user defined types. Like sort(), max(), min(), ..etc.

3) We can write one class or struct that can be used for all data types including user defined types. Like Linked List, Stack, Queue ..etc.

4) Template is an example of compile time polymorphism.

-----------********************-----------------------

#include <iostream>
using namespace std;

template <typename T>
void fun(const T&x)
{
    static int count = 0;
    cout << \"x = \" << x << \" count = \" << count << endl;
    ++count;
    return;
}

int main()
{
    fun<int> (1); 
    cout << endl;//x = 1 count = 0
    fun<int>(1); 
    cout << endl;//x = 1 count = 1
    fun<double>(1.1);
    cout << endl;//x = 1.1 count = 0
    return 0;
}
/*Compiler creates a new instance of a template function for every data type. 
So compiler creates two functions in the above example, one for int and other 
for double. Every instance has its own copy of static variable. The int instance 
of function is called twice, so count is incremented for the second call.*/

-----------********************-----------------------

#include <iostream>
using namespace std;

template <typename T>
T max(T x, T y)
{
    return (x > y)? x : y;
}
int main()
{
    cout << max(3, 7) << std::endl;
    cout << max(3.0, 7.0) << std::endl;
    cout << max(3, 7.0) << std::endl;
    return 0;
}
/*The first and second call to max function is a valid call as both the arguments passed are of same 
ata type (i.e int and float respectively). But the third call to max function has arguments of different 
data type and hence it will generate Compiler Error in last cout statement as call to max is ambiguous.*/

-----------********************-----------------------
#include <iostream>
using namespace std;

template <class T>
class Test
{
private:
    T val;
public:
    static int count;
    Test()  {   count++;   }
};

template<class T>
int Test<T>::count = 0;

int main()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count   << endl;//2
    cout << Test<double>::count << endl;//1
    return 0;
}
/*There are two classes created by the template: Test and Test. 
Since count is a static member, every class has its own copy of it. 
Also, count gets incremented in constructor*/

-----------********************-----------------------

#include <iostream>
using namespace std;

template <class T, int max>
int arrMin(T arr[], int n)
{
   int m = max;
   for (int i = 0; i < n; i++)
      if (arr[i] < m)
         m = arr[i];

   return m;
}

int main()
{
   int arr1[]  = {10, 20, 15, 12};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);

   char arr2[] = {1, 2, 3};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);

   cout << arrMin<int, 10000>(arr1, n1) << endl;//10
   cout << arrMin<char, 256>(arr2, n2);//1
   return 0;
}

/*We can pass non-type arguments to templates. Non-type parameters are mainly used for 
specifying max or min values or any other constant value for a particular instance of 
template. The important thing to note about non-type parameters is, they must be const. 
Compiler must know the value of non-type parameters at compile time. Because compiler 
needs to create functions/classes for a specified non-type value at compile time. 
Following is another example of non-type parameters.

#include <iostream>
using namespace std;

template < class T, int N >
 T fun (T arr[], int size)
{
    if (size > N)
      cout << "Not possible";
    T max = arr[0];
   for (int i = 1; i < size; i++)
      if (max < arr[i])
          max = arr[i];
   return max;
}

int main ()
{
    int arr[] = {12, 3, 14};
    cout << fun  (arr, 3);
}*/


-----------********************-----------------------

#include <iostream>
using namespace std;

template <int i>
void fun()
{
   i = 20;
   cout << i;
}

int main()
{
   fun<10>();
   return 0;
}

/*Compiler error in line "i = 20;" Non-type parameters must be const, so they cannot be modified.*/

-----------********************-----------------------
#include <iostream>
using namespace std;

template <class T>
T max (T &a, T &b)
{
    return (a > b)? a : b;
}

template <>
int max <int> (int &a, int &b)
{
    cout << \"Called \";
    return (a > b)? a : b;
}

int main ()
{
    int a = 10, b = 20;
    cout << max <int> (a, b);
}

/*Above program is an example of template specialization. Sometime we want a different behaviour 
of a function/class template for a particular data type. For this, we can create a specialized 
version for that particular data type.*/

-----------********************-----------------------

#include <iostream>
using namespace std;
 
template<int n> struct funStruct
{
    static const int val = 2*funStruct<n-1>::val;
};
 
template<> struct funStruct<0>
{
    static const int val = 1 ;
};
 
int main()
{
    cout << funStruct<10>::val << endl;
    return 0;
}

/*This is an example of template metaprogramming. The program mainly calculates 2^10.*/

-----------********************-----------------------

Which of the following provides the best description of an entity type?
A template for a group of things with the same set of characteristics that may exist in the real world

-----------********************-----------------------

When we write overloaded function we must code the function for each usage. Correct
When we write function template we code the function only once. Correct
It is difficult to debug macros Correct
Templates are more efficient than macros Correct

Reference: https://www.geeksforgeeks.org/quizzes/c-plus-plus-gq/templates-gq/?page=2
