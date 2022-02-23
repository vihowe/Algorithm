/*
 * @Author: vihowe
 * @Date: 2022-01-31 10:18:32
 * @LastEditTime: 2022-02-23 14:09:07
 * @FilePath: /Algorithm/leetcode/wordBreak.cc
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

class Solution{
public:

  std::unordered_set<std::string> wordSet;
  std::vector<int> memo;

  bool dfs(std::string s, int i) {
    int n = s.size();
    if (i == n) {
      return true;
    }
    // start from s[i] to find a word in dict
    for(int j = i; j < n; ++j) {
      std::string temp = s.substr(i, j - i + 1);
      if (wordSet.find(temp) != wordSet.end()) {
        if (memo[j+1] || dfs(s, j+1) == true) {
          memo[j+1] = true;
          return true;
        }
      }
    }
    return false;

  }
  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    for (auto word : wordDict) {
      wordSet.insert(word);
    }
    for (int i = 0; i < s.size(); ++i) {
      memo.push_back(false);
    }
    return dfs(s, 0);

  }


  bool wordBreak2(std::string s, std::vector<std::string>& wordDict) {
    auto dp = std::vector<bool> (s.size() + 1, false);
    auto ws = std::unordered_set<std::string> ();
    for (auto word : wordDict) {
      ws.insert(word);
    }
    dp[0] = true;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i + 1; j < s.size() + 1; j++) {
        if (dp[i] && (ws.find(s.substr(i, j - i)) != ws.end())) {
          dp[j] = true;
        }
      }
    }
    return dp[s.size()];
  }

  std::vector<std::string> ret;
  void dfs(std::string s, std::unordered_set<std::string> wordSet, 
           int start, std::vector<std::string> temp)
  {
    if (start == s.size())
    {
      std::string r_temp;
      for (int i = 0; i < temp.size(); ++i)
      {
        r_temp += temp[i];
        if (i < temp.size() - 1)
          r_temp += " ";
      }
      ret.push_back(r_temp);
      return;
    }

    for (int end = start; end < s.size(); ++end)
    {
      std::string sub = s.substr(start, end - start + 1);
      if (wordSet.find(sub) != wordSet.end())
      {
        temp.push_back(sub);
        dfs(s, wordSet, end + 1, temp);
        temp.pop_back();
      }
    }
    return;
  }
  
  std::vector<std::string> wordBreak4(std::string s, std::vector<std::string> wordDict)
  {
    auto wordSet = std::unordered_set<std::string> ();
    for (auto word : wordDict)
    {
      wordSet.insert(word);
    }
    std::vector<std::string> temp;    // store the intermediate result
    dfs(s, wordSet, 0, temp);
    return ret;
  }
};

int main()
{
  std::vector<std::string> wordDict {"cats", "dog", "sand", "and", "cat"};
  std::string s {"catsanddog"};

  Solution ss;
  std::vector<std::string> ret = ss.wordBreak4(s, wordDict);
  for (auto s : ret)
  {
    std::cout << s << std::endl;
  }
}