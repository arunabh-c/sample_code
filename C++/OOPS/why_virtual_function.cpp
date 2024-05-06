#include<bits/stdc++.h>

using namespace std;

class Animal
{
    public:
        //virtual void eat() { std::cout << "I'm eating generic food."; }
        void eat() { std::cout << "I'm eating generic food.\n"; }//not making it virtual causes line 27 to execute this statement
};

class Cat : public Animal
{
    public:
        void eat() { std::cout << "I'm eating a rat.\n"; }
};

// This can go at the top of the main.cpp file
void func(Animal *xyz) { xyz->eat(); }

int main()
{
    Animal *animal = new Animal;
    Cat *cat = new Cat;

    func(animal); // Outputs: "I'm eating generic food."
    func(cat);    // Outputs: "I'm eating generic food." if Animal::eat() not virtual
    return 0;
}

//Ref: https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
