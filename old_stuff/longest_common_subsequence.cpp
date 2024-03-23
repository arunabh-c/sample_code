#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_common_subsequence(vector<char> X, vector<char> Y)
{
    vector <char> A = X;
    A.pop_back();
    vector <char> B = Y;
    B.pop_back();
    
    if (X.size() > 0 && Y.size() > 0)
    {
        if (X[X.size()-1] == Y[Y.size()-1])
        {
            return 1 + longest_common_subsequence(A,B);
        }
        else
        {
            return max(longest_common_subsequence(X,B),longest_common_subsequence(A,Y));
        }
    }
    else
        return 0;
}


int main() {
	vector<char> A {'A','G','G','T','A','B'};//{'A','B','C','D','G','H'}
	vector<char> B  {'G','X','T','X','A','Y','B'};//{'A','E','D','F','H','R'}
	
	int x = longest_common_subsequence(A,B);
	cout<<x<<'\n';
	
	return 0;
}
