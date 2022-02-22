/*
 * @Author: vihowe
 * @Date: 2022-02-17 15:43:23
 * @LastEditTime: 2022-02-17 16:57:17
 * @FilePath: /Algorithm/leetcode/array.cc
 */
#include <vector>
#include <random>
#include <algorithm>

class Solution0 {
public:
  void moveZeroes(std::vector<int> &nums)
  {
    int n = nums.size();
    int k= n;
    for (int i = 0; i < k;)
    {
      if (nums[i] == 0)
      {
        // move nums[i+1,...] forward
        for (int j = i + 1; j < n; ++j)
        {
          nums[j-1] = nums[j];
        }
        nums[n-1] = 0;
        k--;
      }
      else
      {
        ++i;
      }
    }
  }

  void moveZeroes2(std::vector<int> &nums)
  {
    // partition的思想
    int n = nums.size();
    int ptr = 0;
    for (int i = 0; i < n; ++i)
    {
      if (nums[i])
      {
        std::swap(nums[ptr++], nums[i]);
      }
    }
  }

  void moveZeroes3(std::vector<int> &nums)
  {
    // 覆盖 + 补0
    int n = nums.size();
    int i = 0, j = 0;
    for (; i < n; ++i)
    {
      if (nums[i])
      {
        nums[j++] = nums[i];
      }
    }
    for (; j < n; ++j)
    {
      nums[j] = 0;
    }
  }
};

class Solution {
public:
  Solution(std::vector<int> &nums)
  {
    this->nums = nums;
  }

  std::vector<int> reset()
  {
    return nums;
  }

  std::vector<int> shuffle()
  {
    std::vector<int> rand_m(nums.begin(), nums.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rand_m.begin(), rand_m.end(), g);
    return rand_m;
  }

private:
  std::vector<int> nums;
};