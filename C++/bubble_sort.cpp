#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &x)//time complexity O(n^2) Space complexity: O(1) 
{
  for (uint i = 0; i < x.size()-1; ++i){
      bool unsorted = false;
      for (uint j = 0;j<x.size()-i-1; ++j){
          if (x[j] > x[j+1])
          {
              swap(x[j],x[j+1]);
              unsorted = true;
          }
      }
      if (!unsorted) break;
  }
}

int main() {
    vector<int> x = {3,1,4,3,2,1,0,9,3,4,5,-1};
    bubble_sort(x);   
    for (auto y : x)
    {
        cout<<y<<", ";
    }
    return 0;
}
