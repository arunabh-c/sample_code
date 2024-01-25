#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &ip, int x)
{
    size_t l = 0, r = ip.size()-1;
    while (l <= r)
    {
       int mid = (r+l)/2;
       if (ip[mid] == x) return mid;
       else if (x > ip[mid]) l = mid+1;
       else r = mid-1;
    }
    return -1;
}

int main() {
    vector<int> arr {0,1,3,4,5,6,7};
    std::cout << binary_search(arr,5);
    return 0;
}
