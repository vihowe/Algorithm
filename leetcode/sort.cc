/*
 * @Author: vihowe
 * @Date: 2022-02-16 19:37:10
 * @LastEditTime: 2022-02-16 22:56:27
 * @FilePath: /leetcode/sort.cc
 */
#include <vector>
#include <iostream>

class Solution {

public:

  int partition(std::vector<int> &nums, int left, int right)
  {
    int pivot = nums[left];
    while (left < right)
    {
      while (left < right && nums[right] >= pivot) right--;
      if (left < right)
      {
        nums[left] = nums[right];
      }
      while (left < right && nums[left] <= pivot) left++;
      if (left < right)
      {
        nums[right] = nums[left];
      }
    }
    nums[left] = pivot;
    return left;
  }

  void quickSort(std::vector<int> &nums, int left, int right)
  {
    if (left >= right)
    {
      return;
    }

    int pivotIdx = partition(nums, left, right);
    quickSort(nums, left, pivotIdx - 1);
    quickSort(nums, pivotIdx + 1, right);
  }

  void reverse(std::vector<int> &nums, int left, int right)
  {
    while (left < right)
    {
      int temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
      left++;
      right--;
    }
  }

  int count(std::vector<int> &nums, int left, int right, int target)
  {
    int cnt = 0;
    for (int i = left; i <= right; ++i)
    {
      if (nums[i] == target)
      {
        cnt++;
      }
    }
    return cnt;
  }

  void wiggleSort(std::vector<int> &nums)
  {
    int n = nums.size();
    quickSort(nums, 0, n - 1);

    int k = n / 2;
    if (nums[n-k] == nums[n-k-1])
    {
      int cnt1 = count(nums, 0, n - k - 1, nums[n-k]);
      int cnt2 = count(nums, n - k, n - 1, nums[n-k]);
      if (cnt1 + cnt2 >= (n+1) / 2)
      {
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
      }
    }

    for (int i = n - k; i < n; ++i)
    {
      int temp = nums[i];
      int j = i;
      for (; j > 2 * (i - n + k + 1) - 1; --j)
      {
        nums[j] = nums[j - 1];
      }
      nums[j] = temp;
    }
  }

  void threeWayPartition(std::vector<int> &nums)
  {
    using std::swap;
    int i = 0, j = 0, k = nums.size() - 1;
    int mid = 1;
    while(j < k){
      if(nums[j] > mid){
          swap(nums[j], nums[k]);
          --k;
      }
      else if(nums[j] < mid){
          swap(nums[j], nums[i]);
          ++i;
          ++j;
      }
      else{
          ++j;
      }
    }
  }
};

int main()
{
  std::vector<int> nums {2, 0, 2, 0, 1, 0};
  Solution s;
  // s.wiggleSort(nums);
  s.threeWayPartition(nums);
  for (auto i : nums)
  {
    std::cout << i << " ";
  }
}