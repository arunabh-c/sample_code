#include <bits/stdc++.h>
using namespace std;

#define CHAR_BIT 8

//Reverse Bits
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = (n >> 16 | n << 16);
        ans = ((ans & 0xff00ff00) >> 8 | (ans & 0x00ff00ff) << 8);
        ans = ((ans & 0xf0f0f0f0) >> 4 | (ans & 0x0f0f0f0f) << 4);
        ans = ((ans & 0xcccccccc) >> 2 | (ans & 0x33333333) << 2);
        ans = ((ans & 0xaaaaaaaa) >> 1 | (ans & 0x55555555) << 1);
        return ans;
    }

/*uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int power = 31;
        while (power >= 0)
        {
           ans += (n & 1) << power;
           n >>= 1;
           --power;
        }
        return ans;
    }*/

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
