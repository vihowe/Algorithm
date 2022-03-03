/*
 * @Author: vihowe
 * @Date: 2022-03-03 13:54:53
 * @LastEditTime: 2022-03-03 14:06:14
 * @FilePath: /Algorithm/leetcode/795.cc
 */

#include <vector>

class Solution {
public:

  int atMost(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    int ans = 0, pre = 0;
    for (int i = 0; i < n; ++i)
    {
      if (nums[i] <= k)
      {
        pre++;
      }
      else
      {
        pre = 0;
      }
      ans += pre;
    }
    return ans;
  }
  int numSubarrayBoundedMax(std::vector<int> &nums, int left, int right)
  {
    // sum of prefix
    return atMost(nums, right) - atMost(nums, left-1);
  }
};
