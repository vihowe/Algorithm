/*
 * @Author: vihowe
 * @Date: 2022-02-14 19:16:22
 * @LastEditTime: 2022-02-14 20:46:43
 * @FilePath: /leetcode/rotateVector.cc
 */
#include <vector>
#include <algorithm>

class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> newNums(n);
    for (int i = 0; i < n; ++i) {
      newNums[(i + k) % n] = nums[i];
    }
    nums.assign(newNums.begin(), newNums.end());

  }

  void rotating(std::vector<int>& nums, int i, int j) {
    while(i < j) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
      i++;
      j--;
    }
  }
  void rotate2(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    rotating(nums, 0, n - k - 1);
    rotating(nums, n - k, n - 1);
    rotating(nums, 0, n - 1);
  }

  void rotate3(std::vector<int> &nums, int k) {
    int n = nums.size();
    int cnt = 0;
    int start = 0;
    while (cnt < n) {
        int prev = nums[start];
        int cur = start;
        do {
          int next = (cur + k) % n;
          std::swap(prev, nums[next]);   // store nums[cur] in prev
          cur = next;
        } while(cur != start);
        start++;
      }
    }
};