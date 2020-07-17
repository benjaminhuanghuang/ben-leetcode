/*
143. Reorder List

Level: Medium

https://leetcode.com/problems/reorder-list
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{

private:
  ListNode *reverseList(ListNode *head)
  {
    if (!head)
    {
      return head;
    }
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  ListNode *mergeList(ListNode *l1, ListNode *l2)
  {
    ListNode dummyNode(0);
    ListNode *dummy = &dummyNode;

    bool use1 = true;
    while (l1 && l2)
    {
      if (use1)
      {
        dummy->next = l1;
        l1 = l1->next;
      }
      else
      {
        dummy->next = l2;
        l2 = l2->next;
      }
      dummy = dummy->next;
      use1 = !use1;
    }
    if (l1)
    {
      dummy->next = l1;
    }
    if (l2)
    {
      dummy->next = l2;
    }
    return dummyNode.next;
  }

public:
  void reorderList(ListNode *head)
  {
    if (!head || !head->next)
    {
      return;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *head2 = slow->next;
    slow->next = nullptr;

    head2 = reverseList(head2);

    mergeList(head, head2);
  }
};