/*
 * @Author: vihowe
 * @Date: 2022-02-23 19:12:58
 * @LastEditTime: 2022-02-26 09:51:45
 * @FilePath: /Algorithm/leetcode/maxSlidingWindow.cc
 */
#include <vector>
#include <queue>
#include <iostream>

class Solution {
private:
  std::vector<int> heap;
public:

  void adjustHeap(int i)
  {
    int n = heap.size();
    for (int k = 2 * i + 1; k < n; k = 2 * k + 1)
    {
      if (k + 1 < n && heap[k+1] > heap[k])
      {
        k++;
      }
      if (heap[k] > heap[i])
      {
        std::swap(heap[k], heap[i]);
        i = k;
      }
      else
        break;
    }
  }

  void insert(int val)
  {
    heap.push_back(val);
    int n = heap.size();
    for (int i = (n - 2) / 2; i >= 0; i = i ? (i - 1) / 2 : -1)
    {
      adjustHeap(i);
    }
  }

  void del(int val)
  {
    std::vector<int>::size_type i = 0;
    for (; i < heap.size(); ++i)
    {
      if (heap[i] == val)
        break;
    }
    std::swap(heap[i], heap[heap.size()-1]);
    heap.pop_back();
    adjustHeap(i);
  }

  int pop()
  {
    std::swap(heap[0], heap[heap.size()-1]);
    int ans = heap.back();
    heap.pop_back();
    adjustHeap(0);
    return ans;
  }

  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
  {
    std::vector<int> ans;
    int n = nums.size();
    int i = 0;
    for (; i < k && i < n; ++i)
    {
      insert(nums[i]);
    }
    ans.push_back(heap[0]);
    while (i < n) // slide window
    {
      del(nums[i-k]);
      insert(nums[i]);
      ans.push_back(heap[0]);
      i++;
    }
    return ans;
  }
};

int main()
{
  std::vector<int> nums {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};
  int k = 7;
  Solution s;
  auto ans = s.maxSlidingWindow(nums, 7);
  for (auto i : ans)
  {
    std::cout << i << " ";
  }
}