#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int
func1 (int x, string str)
{
  cout << "func1: " << x << str<<endl;
  return x;
}

int
func2 (int x, string str)
{
  cout << "func2: " << x <<str<< endl;
  return x;
}

typedef int (*func) (int, string);//MAKE TYPEDEF

map < string, func > sm;

int main ()
{
  sm["1"] = &func1;
  sm["2"] = &func2;

  cout << (*sm["1"]) (5," heh") << endl;//DEREFERENCE 
  //INSIDE BRACKETS THEN INPUT ARGUMENT
  cout << (*sm["2"]) (6, " bla")<< endl;

  return 0;
}
