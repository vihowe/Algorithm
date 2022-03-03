/*
 * @Author: vihowe
 * @Date: 2022-03-03 13:05:26
 * @LastEditTime: 2022-03-03 13:35:38
 * @FilePath: /Algorithm/leetcode/1297.cc
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution {
public:
  int maxFreq(std::string &s, int maxLetters, int minSize, int maxSize)
  {
    int n = s.size();
    std::unordered_map<std::string, int > mm;
    int ans = 0;
    for (int i = 0; i + minSize - 1 < n; ++i)
    {

      std::unordered_set<char> ss;
      int cnt_letters = 0;
      for (int j = i; j - i + 1 <= minSize; ++j)
      {
        if (!ss.count(s[j]))
        {
          cnt_letters++;
        }
        ss.insert(s[j]);
      }
      if (cnt_letters <= maxLetters)
      {
        mm[s.substr(i, minSize)]++;
        std::cout << s.substr(i, minSize) << std::endl;
      }
    }

    int max_cnt = 0;
    for (auto it = mm.begin(); it != mm.end(); ++it)
    {
      if (it->second > max_cnt)
      {
        max_cnt = it->second;
      }
    }
    return max_cnt;
  }
};

int main()
{
  std::string s = "abcde";
  Solution ss;
  ss.maxFreq(s, 2, 3, 3);

}