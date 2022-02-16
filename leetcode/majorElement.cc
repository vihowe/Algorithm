/*
 * @Author: vihowe
 * @Date: 2022-01-21 09:04:55
 * @LastEditTime: 2022-01-21 10:39:02
 * @FilePath: /leetcode/majorElement.cc
 */
#include <iostream>
#include <vector>


// 给定一个大小为n的数组，找到其中的多数元素，多数元素是指在数组中出现次数大于
// floor(n/2)的元素，假设数组非空，并且给定的数组元素总是存在多数元素。

// 1. 排序后取出，O(nlogn)
// 2. hash, O(n), O(n)
// 3.
class Solution {
public:
  int majorElement(std::vector<int>& nums) {
    quickSort(nums, 0, nums.size()-1);
    return nums[nums.size()/2];
  }
  
  int majorityElement(std::vector<int>& nums) {
    int candidate = -1;
    int cnt = 0;
    for (int num : nums) {
      if (num == candidate) {
        cnt++;
      }
      else if(--cnt < 0) {
        candidate = num;
        cnt = 1;
      }
    }
    return candidate;
  }

  void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = a;
  }

  int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    while(left < right) {
      while(left < right && nums[right] > pivot) {
        right--;
      }
      if (left < right) {
        nums[left] = nums[right];
        left++;
      }
      while(left < right && nums[left] < pivot) {
        left++;
      }
      if (left < right) {
        nums[right] = nums[left];
        right--;
      }
    }
    nums[left] = pivot;
    return left;
  }

  void quickSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int pivotIdx = partition(nums, left, right);
    quickSort(nums, left, pivot-1);
    quickSort(nums, pivot+1, right);
  }
};