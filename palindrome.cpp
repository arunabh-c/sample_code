#include <iostream>
using namespace std;

bool check_palindrome(string x)
{
    for (int i =0;i<int(x.size()/2.0);i++)
    {
        if (x[i] != x[x.size()-1-i])
        {
            return false;
        }
    }
    
    return true;
}

int main() {

    string A = "ABBA";
    bool ans;
    ans = check_palindrome(A);
    if (ans)
        cout<<"True"<<'\n';
    else
        cout<<"False"<<'\n';
    
	return 0;
}
