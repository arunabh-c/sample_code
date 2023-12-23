/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(vector<int> &ip)
{
    if (ip.size() > 1)
    {
        size_t half = max(size_t(0),ip.size()/2);
        vector<int> half1(ip.begin(),ip.begin()+half);
        merge_sort(half1);

        vector<int> half2(ip.begin()+half,ip.end());
        merge_sort(half2);

        ip.clear();
        int i1 = 0, i2 = 0;
        
        while (i1 < half1.size() || i2 < half2.size())
        {
            if (i1 >= half1.size())
            {
                ip.push_back(half2[i2]);
                ++i2;
            }
            else if (i2 >= half2.size())
            {
                ip.push_back(half1[i1]);
                ++i1;
            }
            else
            {
                if (half1[i1] < half2[i2])
                {
                  ip.push_back(half1[i1]);
                  ++i1;
                }
                else
                {
                  ip.push_back(half2[i2]);
                  ++i2;
                }
            }
        }
    }
}

int main()
{
    vector<int> ip {9,8,7,6,5,4,4,3,2,1,0,-5};
    merge_sort(ip);
    
    cout<<"ip: ";
    for (auto x: ip)
    {
        cout << x<< ", ";
    }
    cout<<endl;
    cout<<"Hello World";

    return 0;
}
