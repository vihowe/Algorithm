/*
 * @Author: vihowe
 * @Date: 2022-02-17 15:11:02
 * @LastEditTime: 2022-02-23 10:19:44
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

    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
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

  ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int n1 = 0, n2 = 0;
    ListNode *temp = headA;
    while(temp)
    {
      n1++;
      temp = temp->next;
    }
    temp = headB;
    while(temp)
    {
      n2++;
      temp = temp->next;
    }

    int d = abs(n1 - n2);
    if (n1 > n2)
    {
      while (d)
      {
        headA = headA->next;
        d--;
      }
    }
    else
    {
      while (d)
      {
        headB = headB->next;
        d--;
      }
    }
    while (headA && headB)
    {
      if (headA == headB)
      {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;

  }

  ListNode* reverseList(ListNode* head)
  {
    ListNode *pre = nullptr, *cur = head, *next = nullptr;
    while (cur)
    {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

  ListNode* reverseList2(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }
    ListNode *newHead = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }


  ListNode* front;

  bool checkRrecurrsive(ListNode* curr)
  {
    if (curr)
    {
      if (!checkRrecurrsive(curr->next))
      {
        return false;
      }
      if (front->val != curr->val)
      {
        return false;
      }
      front = front->next;
      return true;
    }
    return true;
  }
  bool isPalindrome(ListNode *head)
  {
    front = head;
    return checkRrecurrsive(head);
  }

  bool isPalindrome2(ListNode *head)
  {
    if (!head || !head->next)
    {
      return true;
    }
    ListNode *slow = head, *fast = head;
    ListNode *pre = head, *prepre = nullptr;
    while (fast && fast->next)
    {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
      pre->next = prepre;
      prepre = pre;
    }
    if (fast)
    {
      slow = slow->next;
    }
    while (pre && slow)
    {
      if (pre->val != slow->val)
      {
        return false;
      }
      pre = pre->next;
      slow = slow->next;
    }
  }

  void deleteNode(ListNode *node)
  {
    // can not access the head node, so we need to find the previous node
    // just to delete the value of node
    node->val = node->next->val;
    node->next = node->next->next;
  }

  ListNode* oddEvenList(ListNode *head)
  {
    if (!head || !head->next || !head->next->next)
    {
      return head;
    }
    int n = 0;
    ListNode *temp = head;
    while (temp)
    {
      n++;
      temp = temp->next;
    }
    int k = (n - 1) / 2;
    for (int i = 1; i <= k; ++i)
    {
      ListNode *start = head, *pre = nullptr;
      int j = i;
      while(j--)
      {
        pre = start;
        start = start->next;
      }

      int round = k - i + 1;
      while (round--)
      {
        // swap (start, start->next)
        temp = start->next;
        start->next = start->next->next;
        pre->next = temp;
        temp->next = start;
        pre = start;
        start = start->next;
      }
    }
    return head;
  }

  ListNode* oddEvenList2(ListNode *head)
  {
    if (!head || !head->next || !head->next->next)
    {
      return head;
    }
    ListNode *odd = head, *evenHead = head->next, *even = head->next;
    while(even && even->next)
    {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenHead;
    return head;
  }
};

int main()
{
  ListNode *head = new ListNode(2);
  head->next = new ListNode(1);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(5);
  head->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(7);


  Solution s;
  head = s.oddEvenList(head);
  while (head)
  {
    std::cout << head->val << " ";
    head = head->next;
  }
  


}

