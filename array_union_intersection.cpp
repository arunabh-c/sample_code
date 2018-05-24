#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intersection (vector<int> &X, vector<int> &Y, vector<int> &answer)
{
    int X_idx = 0;
    //int Y_idx = 0;
    //int n = min(X.size(), Y.size());
    for (int i =0;i<Y.size();i++)
    {
        for (int j =X_idx;j<X.size();j++)
        {
            if (Y[i] == X[j])
            {
                answer.push_back(Y[i]);
                X_idx = j+1;
            }
        }
        
    }
}

void unions (vector<int> &X, vector<int> &Y, vector<int> &answer)
{
    int X_idx = 0;
    answer = X;
    
    for (int i =0;i<Y.size();i++)
    {
        for (int j =X_idx;j<answer.size()-1;j++)
        {
            if (Y[i] > answer[j] and Y[i] < answer[j+1])
            {
                answer.insert(answer.begin()+j+1,Y[i]);
                X_idx = j+1;
            }
            else if (Y[i] < answer[0])
            {
                answer.insert(answer.begin(),Y[i]);
                X_idx = j+1;
            }
            else if (Y[i] > answer[answer.size()-1])
            {
                answer.insert(answer.begin()+answer.size(),Y[i]);
                X_idx = j+1;
            }
        }
        
    }
}

int main() {

    vector<int> A = {2,5,6};
    vector<int> B = {4,6,8,10};
	
	vector <int> ans = {};
	
	unions(A,B,ans);
	
    for (int j =0;j<ans.size();j++)
        {
            cout<<ans[j]<<" ";
        }

	return 0;
}
