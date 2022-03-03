/*
 * @Author: vihowe
 * @Date: 2022-02-28 21:51:45
 * @LastEditTime: 2022-02-28 22:06:45
 * @FilePath: /Algorithm/leetcode/dp.cc
 */
#include <string>
#include <vector>


class Solution {
  bool dp[1010][1010];
public:

  std::string longestPalindrome(std::string s)
  {
    int n = s.size();
    // 如果不用静态二维数组
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    if (n == 0)
    {
      return "";
    }
    int maxLen = 1;
    std::string ans = s.substr(0, 1);

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (j <= i)
        {
          dp[i][j] = true;
        }
        else
        {
          dp[i][j] = false;
        }
      }
    }

    for (int intv = 1; intv < n; ++intv)
    {
      for (int i = 0; i < n - intv; ++i)
      {
        int j = i + intv;
        if (s[i] == s[j] && dp[i+1][j-1])
        {
          dp[i][j] = true;
          if (j - i + 1 > maxLen)
          {
            maxLen = j - i + 1;
            ans = s.substr(i, j - i + 1);
          }
        }
      }
    }
    return ans;
  }
};