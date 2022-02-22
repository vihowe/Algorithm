/*
 * @Author: vihowe
 * @Date: 2022-02-22 11:04:33
 * @LastEditTime: 2022-02-22 12:06:29
 * @FilePath: /Algorithm/leetcode/copyRandomList.cc
 */
#include <map>
#include <set>
class Node
{
public:
  int val;
  Node *next;
  Node *random;
  Node (int _val) : val(_val), next(nullptr), random(nullptr) { };
};

class Solution
{

public:
  Node* copyRandomList(Node *head)
  {
    if (!head)
      return nullptr;

    std::map<Node*, Node*> m;

    Node *cur = head;
    while(cur)
    {
      Node *newCur = new Node(cur->val);
      m[cur] = newCur;
      cur = cur->next;
    }

    cur = head;
    while(cur)
    {
      m[cur]->next = m[cur->next];
      m[cur]->random = m[cur->random];
      cur = cur->next;
    }
    return m[head];
  }

  Node* copyRandomList2(Node *head)
  {
    if (!head)
    {
      return nullptr;
    }

    for (Node *cur = head; cur; cur = cur->next->next)
    {
      Node *newNode = new Node(cur->val);
      newNode->next = cur->next;
      cur->next = newNode;
    }

    for (Node *cur = head; cur; cur = cur->next->next)
    {
      cur->next->random = cur->random ? cur->random->next : nullptr;
    }

    Node *newHead = head->next;
    for (Node *cur = head; cur; cur = cur->next)
    {
      Node* newCur = cur->next;
      cur->next = cur->next->next;
      newCur->next = newCur->next ? newCur->next->next : nullptr;
    }
    return newHead;
  }

  
  std::map<Node*, Node*> mm;
  Node* copyRandomList3(Node *head)
  {
    if (!head)
    {
      return nullptr;
    }
    if (mm.count(head))
    {
      return mm[head];
    }
    else
    {
      Node *newNode = new Node(head->val);
      mm[head] = newNode;
      newNode->next = copyRandomList3(head->next);
      newNode->random= copyRandomList3(head->random);
    }
  }

  
};