/*
 * @Author: vihowe
 * @Date: 2022-01-26 18:19:39
 * @LastEditTime: 2022-01-27 11:14:31
 * @FilePath: /leetcode/isPalindrome.cc
 */

#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
  bool isPalindrome(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while(i < j && !isalnum(s[i])) {
        ++i;
      }
      while(i < j && !isalnum(s[j])) {
        --j;
      }
      if (i < j) {
        s[i] = tolower(s[i]);
        s[j] = tolower(s[j]);
        if (s[i] != s[j]) {
          return false;
        }
        ++i;
        --j;
      }
   }
    return true;
  }
};

int main() {
  std::string s = "A man, a plan, a canal: Panama";
  Solution ss;
  std::cout << ss.isPalindrome(s);
}