#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> blob_x;//store j indices of 1's
vector<int> blob_y;//store i indices of 1's


bool new_blob(int row, int column, vector<vector<int>> X)
{
    
    for (int i = -1;i<2;i++)
    {
        for (int j =-1;j<2;j++)
        {
            if ((i != 0 || j != 0) && X[max(0,row+i)][max(0,column+j)] == 1)//
            {
                for (int k =0;k<blob_x.size();k++)
                {
                    if (blob_x[k] == max(0,column+j) && blob_y[k] == max(0,row+i))
                    {
                        return false;//neighboring pixel from same blob already logged
                    }
                }
            }
        }
    }
    return true;
}

int count_blobs(vector<vector<int>> &X)
{
    int blob_ctr = 0;
    
    for (int i=0;i<X.size();i++)
    {
        for (int j=0;j<X[i].size();j++)
        {
            if (X[i][j] == 1)
            {
                if (new_blob(i,j,X))
                {
                    blob_ctr++;
                }
                blob_x.push_back(j);
                blob_y.push_back(i);
            }
        }
    }
    
    return blob_ctr;
}

int main() {

    vector <vector <int>> A {{0, 1, 0, 0, 1, 1, 0}, //3 blobs
                             {1, 1, 0, 0, 1, 1, 0},
                             {0, 0, 1, 0, 0, 1, 0},
                             {0, 0, 0, 0, 0, 0, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0}};
                             
    int ans = 0;
    ans = count_blobs(A);
	cout <<ans<<'\n';
	
	return 0;
}
