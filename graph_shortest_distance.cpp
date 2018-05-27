#include <iostream>
#include<vector>
#include<bits/stdc++.h> //INT_MAX

vector<int> graph_shortest_distance_list(int arr[V][V], int x, int y)
{
    int temp_node_seq[V] = {0};
    int completed[V] = {0};
    
    int min_sum = 0;
    
    int i = 0;
    bool change_flag = true;
    
    while (i < V || change_flag == true)
    {
        //cout<<i<<'\n';
        if (arr[x][i] != 0 && completed[i] == 0)
        {
            completed[i] = 1;
            int path_length = arr[x][i];
            for (int j =0;j<=V;j++)
            {
                if (arr[i][j] != 0 && j!=x)
                {
                    if (arr[x][j] == 0)
                    {
                        arr[x][j] = path_length + arr[i][j];
                        temp_node_seq[j] = i;
                    }
                    else if (arr[x][j] > (path_length + arr[i][j]))
                    {
                        arr[x][j] = path_length + arr[i][j];
                        temp_node_seq[j] = i;
                        change_flag = true;
                        completed[j] = 0;
                    }
                }
            }
        }
        ++i;
        if (i == V && change_flag == true)
        {
            i = 0;
            change_flag = false;
        }

    }

    int ctr = V-1;
    vector<int> final_seq;
    int prev_item = y;
    while (prev_item !=0)
    {
        //cout<<prev_item<<'\n';
        final_seq.insert(final_seq.begin(),prev_item);
        prev_item = temp_node_seq[prev_item];
        --ctr;
    }
    
    //pointer = final_seq;
    return final_seq;//pointer;//arr[0];
}
int main(){
        
    vector<int> ans;
    ans = graph_shortest_distance_list(graph,start,stop);
    
    cout<<"ans"<<'\n';
    for (int i = 0;i<ans.size();i++)
    {
        if (ans[i] !=0)        
        {
            cout<<ans[i]<<'\n';
        }
    }
    
    return 0;
    }
