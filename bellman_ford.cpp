#include<bits/stdc++.h>
using namespace std;

class bellman_ford {
  int nodes;
  //vector<int> lowest_cost;
  
  public:
  vector<vector<int>> ans;
  
  bellman_ford(int x)
  {
      nodes = x;
      
      for (int i=0;i<nodes;i++)
      {
          ans.push_back({});
      }
  };
  
  vector<vector<int>> iterate_nodes(vector<vector<int>> &graph)
  {
    vector<int> lowest_cost(nodes, INT_MAX);
    lowest_cost[0] = 0;
    ans[0] = {0};
    vector<int> temp_node_seq;
    
    bool change = true;
    int sum = 0;
    
    while (change == true)
    {    
        change = false;
        for (int i =0;i<graph.size();i++)
        {
            sum = lowest_cost[graph[i][0]] + graph[i][2];
            if (lowest_cost[graph[i][1]] > sum)
            {
                cout<<sum<<'\n';
                lowest_cost[graph[i][1]] = sum;

                temp_node_seq = ans[graph[i][0]];
                temp_node_seq.push_back(graph[i][1]);
                ans[graph[i][1]] = temp_node_seq;

                change = true;
            }
            sum = lowest_cost[graph[i][1]] + graph[i][2];
            if (lowest_cost[graph[i][0]] > sum)
            {
                lowest_cost[graph[i][0]] = sum;

                temp_node_seq = ans[graph[i][1]];
                temp_node_seq.push_back(graph[i][0]);
                ans[graph[i][0]] = temp_node_seq;

                change = true;
            }
        }
    }
    
    return ans;

  };
    
};



int main() {
	
	int n = 7;
	vector<vector<int>> y {{0,1,9},//A9B
	                       {0,2,2},//A2C
	                       {1,2,6},//B6C
	                       {1,3,3},//B3D
	                       {2,3,2},//C2D
	                       {1,4,1},//B1E
	                       {3,4,5},//D5E
	                       {3,5,6},//D6F
	                       {2,5,9},//C9F
	                       {4,5,3},//E3F
	                       {4,6,7},//E7G
	                       {5,6,4}};//F4G
	                       
	
	bellman_ford bf(n);
	
	vector<vector<int>> ans = bf.iterate_nodes(y);
	
	cout<<ans.size()<<'\n';
	for (int i =0;i<ans.size();i++)
	{
	    for (int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
	}
	
	return 0;
}
