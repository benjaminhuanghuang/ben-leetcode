/*
430. Flatten a Multilevel Doubly Linked List

Level: Medium

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

// Definition for a Node.
class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution
{
public:
  Node *flatten(Node *head)
  {
    if (head == nullptr)
    {
      return head;
    }

    Node *cur = head;
    while (cur)
    {
      if (cur->child == nullptr)
      {
        cur = cur->next;
        continue;
      }

      Node *child = cur->child;
      Node *childTail = child;
      while (childTail->next != nullptr)
      {
        childTail = childTail->next;
      }

      cur->child = nullptr;
      child->prev = cur;
      childTail->next = cur->next;
      if (cur->next)
      {
        cur->next->prev = childTail;
      }
      cur->next = child;
      cur = cur->next;
    }

    return head;
  }
};