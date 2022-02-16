/**
 * @file 64.cc
 * @author vihowe(vihowe@outlook.com)
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 * @version 0.1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  int minPathSum(std::vector<std::vector<int> >& grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int sum[200] = {0};

    for(int i = m-1; i >= 0; --i)
    {
      for(int j = n-1; j >= 0; --j)
      {
        int r = j < n-1 ? sum[j+1] : sum[j];
        int d = i < m-1 ? sum[j] : sum[j+1];
        sum[j] = grid[i][j] + std::min(r, d);
      }
    }
    return sum[0];
  }
};

int main(int argc, char* argv[])
{
  std::vector<std::vector<int> > grid;
  std::vector<int> a{1, 3, 1};
  std::vector<int> b{1, 5, 1};
  std::vector<int> c{4, 2, 1};
  grid.push_back(a);
  grid.push_back(b);
  grid.push_back(c);

  Solution solution;
  int res =  solution.minPathSum(grid);
  std::cout << res;

}