/*
 * @Author: vihowe
 * @Date: 2022-01-21 10:39:40
 * @LastEditTime: 2022-01-21 10:54:03
 * @FilePath: /leetcode/search2dMatrix.cc
 */
#include <iostream>
#include <vector>

// 从一个二维矩阵中搜索target
// 矩阵从左到右从上到下都是升序

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& nums, int target) {
    int m = nums.size();
    int n = nums[0].size();
    int i = 0, j = n - 1;
    while(i < m && j >= 0 ) {
      if(target < nums[i][j]) {
        j--;
      }
      else if (target > nums[i][j]) {
        i++;
      }
      else {
        return true;
      }
    }
    return false;
  }
}