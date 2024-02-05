#include <bits/stdc++.h>
using namespace std;

#define CHAR_BIT 8

int main() {
    
    int v = -5;
    
    //sign of a number
    int sign = v >> (sizeof(int) * CHAR_BIT - 1);
    //int sign = +1 | (v >> (sizeof(int) * CHAR_BIT - 1));  // if v < 0 then -1, else +1
    
    //if two integers have opposite signs
    int x, y;               // input values to compare signs
    bool f = ((x ^ y) < 0); // true iff x and y have opposite signs
    
    //the integer absolute value (abs) without branching
    unsigned int r;  // the result goes here 
    int const mask = v >> sizeof(int) * CHAR_BIT - 1;
    r = (v + mask) ^ mask;
    

    
    return 0;
}
