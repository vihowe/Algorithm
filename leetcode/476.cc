/*
 * @Author: vihowe
 * @Date: 2022-03-03 11:59:36
 * @LastEditTime: 2022-03-03 12:51:48
 * @FilePath: /Algorithm/leetcode/476.cc
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>


class Solution {
public:
  int findSubstringInWraproundString(std::string p)
  {
    int n = p.size();
    if (n == 0)
    {
      return 0;
    }

    std::unordered_map<char, int> mm;
    mm[p[0]] = 1;
    int pre = 1;
    for (int i = 1; i < p.size(); ++i)
    {
      if (p[i] - p[i-1] == 1 || p[i] - p[i-1] == -25)
      {
        pre++;
      }
      else 
      {
        pre = 1;
      }
      mm[p[i]] = std::max(mm[p[i]], pre);
    }
    int ans = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
      ans += it->second;
    }
    return ans;
  }
};


int main(int argc, char* argv[])
{
  Solution sol;
  std::string p = "aabb";
  auto ret = sol.findSubstringInWraproundString(p);
  std::cout << ret;
}