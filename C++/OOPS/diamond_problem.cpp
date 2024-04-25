//solution to diamond problem and the things to omit to bring it back
//diamond problem : grandparent constructor called twice since both parents inherit it.
#include<iostream>
using namespace std;
class Person {
public:
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
    Person()     { cout << "Person::Person() called" << endl;   }
};
 
class Faculty : virtual public Person {//if you remove virtual diamond problem return
public:
    Faculty(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
};
 
class Student : virtual public Person {//if you remove virtual diamond problem return
public:
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
};
 
class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x), Person(x)   {//if you remove Person(x) then only default non parameterized constructor of Person is called
        cout<<"TA::TA(int ) called"<< endl;
    }
};
 
int main()  {
    TA ta1(30);
}

//Ref: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
