#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &ip)
{
    if (ip.size() > 1)
    {
        size_t half = ip.size()/2, i1 = 0, i2 = 0;
        vector<int> half1(ip.begin(),ip.begin()+half), half2(ip.begin()+half,ip.end());
        merge_sort(half1);//recursively call on smaller halves; half1 is sorted here
        merge_sort(half2);//half2 is sorted here

        ip.clear();//ip vector cleared here

        while (i1 < half1.size() || i2 < half2.size())
        {   //half1 complete keep pushing rest of half2
            if (i1 >= half1.size()) ip.emplace_back(half2[i2++]);
            //half2 complete keep pushing rest of half1
            else if (i2 >= half2.size()) ip.emplace_back(half1[i1++]);
            //default case
            //increment i1 and i2 to keep pushing elements from half1 & half2 into ip
            else half1[i1] < half2[i2] ? ip.emplace_back(half1[i1++]) : ip.emplace_back(half2[i2++]);
        }
    }
}

int main()
{
    vector<int> ip {1,9,8,7,6,5,4,4,3,2,1,0,-5,3};
    merge_sort(ip);

    cout<<"ip: ";
    for (auto x: ip)
    {
        cout << x<< ", ";
    }
    cout<<endl;
    return 0;
}
