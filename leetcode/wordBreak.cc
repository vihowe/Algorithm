/*
 * @Author: vihowe
 * @Date: 2022-01-31 10:18:32
 * @LastEditTime: 2022-02-14 16:47:22
 * @FilePath: /leetcode/wordBreak.cc
 */
#include <string>
#include <vector>
#include <unordered_set>

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


  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
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
};