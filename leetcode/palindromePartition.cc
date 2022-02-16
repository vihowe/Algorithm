/*
 * @Author: vihowe
 * @Date: 2022-01-27 11:21:07
 * @LastEditTime: 2022-01-30 16:11:09
 * @FilePath: /leetcode/palindromePartition.cc
 */
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<bool>> f;
  std::vector<std::vector<std::string>> ret;
  std::vector<std::string> ans;

  bool isPalindrome(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
  
  void preprocess(std::string s) {
    int n = s.size();
    f.assign(n, std::vector<bool>(n, true));

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j + i < n; ++j) {
        int k = j + i;
        f[j][k] = s[j] == s[k] && f[j+1][k-1];
      }
    }

  }

  std::vector<std::vector<std::string>> dfs(std::string s, int i) {
    int n = s.size();
    if (i == n) {
      ret.push_back(ans);
    }
    for(int j = i; j < n; ++j) {
      // whether s[i-j] is a palindrome
      if (f[i][j]) {
        ans.push_back(s.substr(i, j - i + 1));
        dfs(s, j+1);
        ans.pop_back();
      }
    }
  }
  
  std::vector<std::vector<std::string>> partition(std::string s) {
    preprocess(s);
    dfs(s, 0);
    return ret;
  }
};

int main() {
  std::string s = "aab";
  Solution ss;
  std::vector<std::vector<std::string>> ret = ss.partition(s);
  for (auto item : ret) {
    std::cout << "[";
    for (auto i : item) {
      std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
  }
}