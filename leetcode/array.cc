/*
 * @Author: vihowe
 * @Date: 2022-02-17 15:43:23
 * @LastEditTime: 2022-03-01 14:58:47
 * @FilePath: /Algorithm/leetcode/array.cc
 */
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <unordered_map>

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

  int minSubArrayLen(int target, std::vector<int> &nums)
  {
    int n = nums.size();
    int ans = n + 1;
    int l = 0, r = 0;
    int sum = 0;
    while (r < n)
    {
      sum += nums[r];
      while (sum >= target)
      {
        ans = std::min(ans, r - l + 1);
        sum -= nums[l];
        l++;
      }
    }
    return ans == n + 1 ? 0 : ans;
  }


  bool haveRepeat(std::unordered_map<char, int> &mm)
  {
    auto map_it = mm.begin();
    while (map_it != mm.end())
    {
      if (map_it->second > 1)
      {
        return true;
      }
      map_it++;
    }
    return false;
  }

  int lengthOfLongestSubstring(std::string s)
  {
    std::unordered_map<char, int> mm;
    int n = s.size();
    int ans = 0;
    int l = 0, r = 0;
    while (r < n)
    {
      mm[s[r]] += 1;
      while (mm[s[r]] > 1)
      {
        mm[s[l++]] -= 1;
      }
      ans = std::max(ans, r - l + 1);
      r++;
    }
    return ans;
  }

  bool isDone(const std::unordered_map<char, int> &mm)
  {
    auto map_it = mm.begin();
    while (map_it != mm.end())
    {
      if (map_it->second > 0)
      {
        return false;
      }
      map_it++;
    }
    return true;
  }

  std::string minWindow(std::string s, std::string t)
  {
    // 返回s中覆盖t全部字符的最小字串
    int n_s = s.size();
    int n_t = t.size();
    if (n_s < n_t)
    {
      return "";
    }
    std::unordered_map<char, int> mm;
    for (auto c : t)
    {
      mm[c]++;
    }
    int l = 0, r = 0, ans_l = 0, ans_r = 0, ans_min = n_s + 1;
    while (r < n_s)
    {
      mm[s[r]]--;
      while (isDone(mm))
      {
        if (r - l + 1 < ans_min)
        {
          ans_min = r - l + 1;
          ans_l = l;
          ans_r = r;
        }
        mm[s[l++]]++;
      }
      r++;
    }
    return ans_min == n_s + 1 ? "" : s.substr(ans_l, ans_r - ans_l + 1);
  }
  

  void nextPermutation(std::vector<int> &nums)
  {
    int n = nums.size();
    int i, j , k;
    i = j = k = n - 1;
    while (j > 0)
    {
      i = j - 1;
      if (nums[j] > nums[i])
      {
        break;
      }
      j--;
    }
    while (k >= j)
    {
      if (nums[k] > nums[i])
      {
        std::swap(nums[k], nums[i]);
        break;
      }
      k--;
    }
    std::reverse(nums.begin()+j, nums.end());
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

int main()
{
  std::vector<int> nums {3, 2, 1};
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";
  Solution0 ss;
  // ss.lengthOfLongestSubstring(s);
  auto ans = ss.minWindow(s, t);
  std::cout << ans;


}