/*
 * @Author: vihowe
 * @Date: 2022-02-18 17:40:10
 * @LastEditTime: 2022-02-18 17:46:39
 * @FilePath: /Algorithm/leetcode/minStack.cc
 */
#include <stack>
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
      if (s.empty())
      {
        s.push(val);
        min_s.push(val);
      }
      else
      {
        int cur_m = min_s.top();
        s.push(val);
        min_s.push(val < cur_m ? val : cur_m);
      }
    }
    
    void pop() {
      if (!s.empty())
      {
        s.pop();
        min_s.pop();
      }
    }
    
    int top() {
      if (!s.empty())
      {
        return s.top();
      }
      return -1;
    }
    
    int getMin() {
      if (!s.empty())
      {
        return min_s.top();
      }
      else
      {
        return -1;
      }
    }

private:
  std::stack<int> s;
  std::stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */