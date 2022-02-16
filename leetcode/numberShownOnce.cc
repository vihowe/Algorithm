/*
 * @Author: vihowe
 * @Date: 2022-01-21 08:49:30
 * @LastEditTime: 2022-01-21 09:02:06
 * @FilePath: /leetcode/numberShownOnce.cc
 */
#include <iostream>
#include <vector>

// 只有一个数字出现一次，其他数字都出现两次，找出仅出现一次的数字
// 通过异或位运算，出现两次的数字各位经过异或都消除了
class Solution {
public:
  int singleNumber(std::vector<int>& nums) {
    int ret = 0;
    for (int num : nums) {
      ret = ret ^ num;
    }
    return ret;
  }
};

int main() {
  std::vector<int> nums {1, 1, 2, 2, 3, 3, 4, 4, 5};
  Solution s;
  int ret = s.singleNumber(nums);
  std::cout << ret << std::endl;
}