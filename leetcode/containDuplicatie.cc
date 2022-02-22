/*
 * @Author: vihowe
 * @Date: 2022-02-17 13:43:16
 * @LastEditTime: 2022-02-17 15:05:34
 * @FilePath: /Algorithm/leetcode/containDuplicatie.cc
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
  }

  /**
   * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
   * 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
   * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
   */
  int findDuplicate(std::vector<int> &nums)
  {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
      int mid = left + (right - left) >> 1;
      int cnt = 0;
      for (auto item : nums)
      {
        if (item <= mid)
          cnt++;
      }
      if (cnt <= mid)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }
  }

  int findDuplicate2(std::vector<int> &nums)
  {
    int n = nums.size();
    int bitMax = 31;
    int ans = 0;
    while (!(n-1) >> bitMax)  bitMax--;

    for (int bit = 0; bit <= bitMax; bit++)
    {
      int x = 0, y = 0;
      for (int i = 0; i < n; ++i)
      {
        if (nums[i] & (1 << bit))
          x++;
      }
      for (int i = 1; i < n; ++i)
      {
        if (i & (1 << bit))
          y++;
      }
      if (x > y)
        ans |= (1 << bit);
    }
    return ans;
  }
};