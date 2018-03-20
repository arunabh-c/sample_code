#include <iostream>
#include <algorithm>
#include <vector>

// 0 1 0 0 1 1 0
// 1 1 0 0 1 1 0
// 0 0 1 0 0 1 0
// 0 0 0 X 0 0 0
// 0 1 1 0 0 0 0
// 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0
 
// Let 0 = free space, and 1 = occupied space. 
// X is the position of our car.
// Write an algorithm that prints the size of each object it encounters.


struct coord{
  std::vector <int> x;
  std::vector <int> y;
  int count;
};

bool check_for_edges (int x, int y, int N)//Check if coordinate within grid boundary
{
  (x<N && y<N && x>-1 && y> -1)? (return true): (return false);
}

coord check_neighbors(coord ans, std::vector<std::vector<int>> &Grid)
{  
  
  int max_x = Grid[0].size();
  int x = ans.x[ans.x.size()-1];
  int y = ans.y[ans.y.size()-1];
  for (int i = -1;i<2;i++)
  {
    for (int j = -1;j<2;j++)
    {
      if (check_for_edges(x+i,y+j,max_x) && (i != 0 || j != 0) && Grid[x+i][y+j] ==1)
      {
        ans.x.push_back(x+i);//insert x in list of visited coords
        ans.y.push_back(y+j);//insert x in list of visited coords
        ans.count++;//increment size counter
        Grid[x+i][y+j] = -7;//Mark point as covered
        return ans;
        break;
      }
    }
  }
  
  ans.x.pop_back();//reached dead end time to trace back path
  ans.y.pop_back();
  return ans;
}

int find_blob_size(int x, int y, std::vector<std::vector<int>> &Grid)
{
  coord new_obj;
  new_obj.x = {x};
  
  std::vector<int> starter = new_obj.x;
  new_obj.y = {y};
  new_obj.count = 0;
  bool start_flag = true;

  while (new_obj.x != starter || start_flag == true)//keep measuring blob size until dont return to start point
  {
    start_flag = false;
    new_obj = check_neighbors(new_obj, Grid);
  }
  
  return new_obj.count;
}

int main ()
{


  std::vector <std::vector <int>> A = {{0, 1, 0, 0, 1, 1, 0},
                                       {1, 1, 0, 0, 1, 1, 0},
                                       {0, 0, 1, 0, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 0, 0},
                                       {0, 1, 1, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0}};

  int x = 3;
  int y = 3;
  
  int ans = 0;
  ans = find_blob_size(x, y, A);
  
  std::cout<<ans<<'\n';
      
  return 0;
}
