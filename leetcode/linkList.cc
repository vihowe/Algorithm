/*
 * @Author: vihowe
 * @Date: 2022-02-17 15:11:02
 * @LastEditTime: 2022-02-22 16:27:08
 * @FilePath: /Algorithm/leetcode/linkList.cc
 */

#include <unordered_set>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head)
  {
    if (!head)
      return false;
    ListNode *slow = head, *fast = head;
    while(fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        return true;
    }
    return false;
  }

  bool hasCycle2(ListNode *head)
  {
    std::unordered_set<ListNode*> seen;
    while (!head)
    {
      if (seen.count(head))
      {
        return true;
      }
      seen.insert(head);
      head = head->next;
    }
    return false;
  }


  void swap(ListNode *a, ListNode *b)
  {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }

  ListNode* sortList(ListNode *head)
  {
    int n = 0;
    ListNode *temp;
    while (temp)
    {
      n++;
      temp = temp->next;
    }

    for (int i = 1; i < n; ++i)
    {
      ListNode *cur = head;
      while (cur->next)
      {
        if (cur->val > cur->next->val)
        {
          swap(cur, cur->next);
        }
        cur = cur->next;
      }
    }
    return head;
  }

  ListNode* sortList2(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = nullptr;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(temp);
    ListNode *ret = new ListNode(0);
    ListNode *h = ret;
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        h->next = l1;
        l1 = l1->next;
      }
      else
      {
        h->next = l2;
        l2 = l2->next;
      }
      h = h->next;
    }
    
    if (l1)
    {
      h->next = l1;
    }
    if (l2)
    {
      h->next = l2;
    }
    return ret->next;
  }


  ListNode* sortList3(ListNode *head)
  {
    if (!head)
    {
      return  nullptr;
    }

    int n = 0;
    ListNode *temp = head;
    while (temp)
    {
      n++;
      temp = temp->next;
    }

    ListNode *ret = new ListNode(0);
    ret->next = head;

    int interval = 1;
    while (interval < n)
    {
      ListNode *pre = ret, *h = ret->next;

      while (h)
      {
        ListNode *h1 = h;
        int i = interval;
        while (h && i)
        {
          h = h->next;
          i--;
        }
        if (i)
        {
          break;  // h2 not exists
        }
        ListNode *h2 = h;
        i = interval;
        while (h && i)
        {
          h = h->next;
          i--;
        }
        int c1 = interval, c2 = interval - i;

        while (c1 && c2)
        {
          if (h1->val < h2->val)
          {
            pre->next = h1;
            h1 = h1->next;
            c1--;
          }
          else
          {
            pre->next = h2;
            h2 = h2->next;
            c2--;
          }
          pre = pre->next;
        }
        pre->next = c1 ? h1 : h2;
        while (c1 > 0 || c2 > 0)
        {
          pre = pre->next;
          c1--;
          c2--;
        }
        // pre->next = h;
      }
      interval *= 2;
    }
    return ret->next;
  }
};

int main()
{
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  Solution s;
  head = s.sortList3(head);
  while (head)
  {
    std::cout << head->val << " ";
    head = head->next;
  }
  


}

