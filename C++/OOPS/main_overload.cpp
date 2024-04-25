#include <iostream> 
using namespace std; 
class Test 
{ 
public: 
    int main(int s) 
    { 
        cout << s << "\n"; 
        return 0; 
    } 
    int main(char *s) 
    { 
        cout << s << endl; 
        return 0; 
    } 
    int main(int s ,int m) //To overload main() function in C++, 
//it is necessary to use class and declare the main as member function. 
//Note that main is not reserved word in programming languages like C, C++, Java and C#.
//trying to overload main without a class will fail
    { 
        cout << s << " " << m; 
        return 0; 
    } 
}; 
int main() 
{ 
    Test obj; 
    obj.main(3); 
    obj.main("I love C++"); 
    obj.main(9, 6); 
    return 0; 
} 
