#include <iostream>
#include <vector>

 std::vector<std::vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                                        {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                                        {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                                        {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                                        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

struct node_pair_set {
    std::vector<int> path = {};
    int dist = 9999;
} init_node_pair_set;

void find_shortest_routes(int start_node, int dist, std::vector<node_pair_set> &X, std::vector<int> &last_path)
{
    for (int i =0;i<graph.size();i++)
    {
        int temp_dist = 0;
        std::vector<int> temp_path = last_path;
        if (graph[start_node][i] != 0)
        {
            temp_dist = dist + graph[start_node][i];
            if (temp_dist < X[i].dist)
            {
                //std::cout<<"test"<<std::endl;
                X[i].dist = temp_dist;
                temp_path.push_back(start_node);
                X[i].path = temp_path;
                find_shortest_routes(i, temp_dist, X, temp_path);
            }
        }
    }
    return;
}

int main() {
                                           
    std::vector<node_pair_set> node_routes(graph.size(),init_node_pair_set);
    
    int start_node = 1;
    int stop_node = 4;
    std::vector<int> path = {};
    find_shortest_routes(start_node, 0, node_routes, path);
    
    std::cout<<"Distance: "<<node_routes[stop_node].dist<<std::endl;;
    std::cout<<std::endl<<"Path: ";
    for (int i =0;i<node_routes[stop_node].path.size();i++)
    {
        std::cout<<node_routes[stop_node].path[i]<<",";
    }
    return 0;
}
