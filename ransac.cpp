#include <iostream>
#include <vector>
#include <math.h>       /* sqrt */
/*#include <algorithm>

using namespace std;

struct line{
  float m = 0;  
  float b = 0;  
};

float distance(int x, int y, line s)
{
    float ans;
    
    ans = abs(s.m*(float(x)) + s.b - (float(y))) / sqrt(1 + pow(s.m,2.0));
    return ans;
}

line slope(int x2, int y2, int x1, int y1)
{
    line ans;
    
    if (x2 != x1)
    {
        ans.m = (float(y2)-float(y1))/(float(x2)-float(x1));
    }
    else
    {
        ans.m = 999999.0;
    }

    ans.b = float(y2) - ans.m*x2;

    return ans;
}

line ransac(vector<int> &X, vector<int> &Y)
{
    int iter = 20;
    //float threshold = 0.5;
    float thresh_dist = 0.1;
    line ans;
    line temp_line;
    int rnd_idx = 0;
    int max_count = 0;
    int temp_count = 0;
    
    float temp_dist = 0;
    //int max_x = *max_element(X.begin(), X.end());
    //int max_y = *max_element(Y.begin(), Y.end());
    
    for (int i=0;i<iter;i++)
    {
      rnd_idx = (rand() % X.size())-1;
      int x1 = X[rnd_idx];
      int y1 = Y[rnd_idx];

      rnd_idx = (rand() % X.size())-1;
      int x2 = X[rnd_idx];
      int y2 = Y[rnd_idx];
      
      temp_line = slope(x2,y2,x1,y1);
      temp_count = 0;
      
      for (int j=0;j<X.size();j++)
      {
          temp_dist = distance(X[j],Y[j],temp_line);
          if (temp_dist < thresh_dist)
          {
            temp_count++;  
          }
      }
      
      //cout<<i<<'\n';
      //cout<<temp_count<<'\n';
      
      if (temp_count > max_count)
      {
          max_count = temp_count;
          ans = temp_line;
          //cout<<i<<'\n';
          cout<<max_count<<'\n';
      }
    }
    
    return ans;
    
}

int main() {

    vector<int> x = {2,3,2,4,3,2,5,2,2,5,1};
    vector<int> y = {5,4,3,6,7,5,6,4,5,2,6};
    
    line ans;
    ans = ransac(x,y);
    
    cout<<ans.m<<" "<<ans.b;
	return 0;
}
