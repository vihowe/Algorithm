/*
 * @Author: vihowe
 * @Date: 2022-02-15 16:51:38
 * @LastEditTime: 2022-02-15 17:09:00
 * @FilePath: /leetcode/largestNumber.cc
 */
#include <vector>
#include <string>
#include <algorithm>


class Solution {
public:
  std::string largestNumber(std::vector<int> & nums) {
    std::vector<std::string> sNums;
    for (auto item : nums) {
      sNums.push_back(std::to_string(item));
    }

    std::sort(sNums.begin(), sNums.end(), [](std::string s1, std::string s2) {
      return s2 + s1 < s1 + s2;
    });

    std::string res;
    for (auto item : sNums) {
      res += item;
    }
    return res[0] == '0' ? "0" : res;
  }
};