/*
 * @Author: vihowe
 * @Date: 2022-02-16 19:37:10
 * @LastEditTime: 2022-02-19 18:41:04
 * @FilePath: /Algorithm/leetcode/sort.cc
 */
#include <vector>
#include <iostream>
#include <queue>

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

  int partition2(std::vector<int> &nums, int left, int right)
  {
    int pivot = nums[left];
    while (left < right)
    {
      while (left < right && nums[right] <= pivot)  right--;
      if (left < right)
      {
        nums[left] = nums[right];
      }

      while (left < right && nums[left] >= pivot) left++;
      if (left < right)
      {
        nums[right] = nums[left];
      }
    }
    nums[left] = pivot;
    return left;
  }

  void kthBiggestHelper(std::vector<int> &nums, int k, int left, int right)
  {
    if (left >= right)
      return;
    int pivotIdx = partition2(nums, left, right);
    kthBiggestHelper(nums, k, left, pivotIdx - 1);
    kthBiggestHelper(nums, k, pivotIdx + 1, right);
 
  }

  int kthBiggest(std::vector<int> &nums, int k)
  {
    kthBiggestHelper(nums, k, 0, nums.size() - 1);
    return nums[k-1];
  }

  /************************heap sort*******************************/
  void adjustHeap(std::vector<int> &nums, int i, int n)
  {
    for (int k = 2 * i + 1; k < n; k = 2 * k + 1)
    {
      if (k + 1 < n && nums[k+1] > nums[k])
      {
        k++;
      }
      if (nums[k] > nums[i])
      {
        std::swap(nums[k], nums[i]);
        i = k;
      }
    }
  }

  int findKthLargest(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
      adjustHeap(nums, i, n);
    }
    for (int i = 0; i < k; ++i)
    {
      std::swap(nums[0], nums[n-1-i]);
      adjustHeap(nums, 0, n - 1 - i);
    }
    return nums[n - k];
  }
  void heapSort(std::vector<int> &nums)
  {
    int n = nums.size();
    // construct the heap
    // start from the first non-leaf node
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
      adjustHeap(nums, i, n);
    }
    for (int i = n - 1; i > 0; --i)
    {
      std::swap(nums[0], nums[i]);
      adjustHeap(nums, 0, i);
    }
  }
};


class MedianFinder {
  std::priority_queue<int, std::vector<int>, std::less<int>> queMin;
  std::priority_queue<int, std::vector<int>, std::greater<int>> queMax;
  
public:
  MedianFinder() {}

  void addNum(int num)
  {
    if (queMin.empty() || num <= queMin.top())
    {
      queMin.push(num);
      if (queMin.size() > queMax.size() + 1)
      {
        queMax.push(queMin.top());
        queMin.pop();
      }
    }
    else
    {
      queMax.push(num);
      if (queMax.size() > queMin.size())
      {
        queMin.push(queMax.top());
        queMax.pop();
      }
    }
  }

  double findMedian()
  {
    if (queMin.size() > queMax.size())
    {
      return queMin.top();
    }
    return (queMin.top() + queMax.top()) / 2;
  }

};

int main()
{
  std::vector<int> nums {3,2,3,1,2,4,5,5,6};
  Solution s;
  // s.wiggleSort(nums);
  s.heapSort(nums);
  // std::cout << s.kthBiggest(nums, 4) << std::endl;
  for (auto i : nums)
  {
    std::cout << i << " ";
  }
}