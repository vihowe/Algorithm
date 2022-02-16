/*
 * @Author: vihowe
 * @Date: 2022-02-14 16:48:38
 * @LastEditTime: 2022-02-14 17:20:05
 * @FilePath: /leetcode/maxProduct.cc
 */
#include <vector>
#include <algorithm>

/**
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字）
 * 并返回该子数组所对应的乘积。
 */
class Solution {
public:
  int maxProduct(std::vector<int>& nums) {
    std::vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); ++i) {
      maxF[i] = std::max(maxF[i-1] * nums[i], std::max(nums[i], minF[i-1] * nums[i]));
      minF[i] = std::min(maxF[i-1] * nums[i], std::min(nums[i], minF[i-1] * nums[i]));
    }
    int ret = maxF[0];
    for (auto item : maxF) {
      if (item > ret) {
        ret = item;
      }
    }
    return ret;
  }
};