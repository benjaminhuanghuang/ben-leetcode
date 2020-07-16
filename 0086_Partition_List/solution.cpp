/*
86. Partition List

Level: Medium

https://leetcode.com/problems/partition-list
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
public:
  ListNode *partition(ListNode *head, int x)
  {
    if (head == nullptr)
      return head;

    ListNode bigger(0);
    ListNode less(0);
    ListNode *pb = &bigger;
    ListNode *pl = &less;
    while (head)
    {
      // 
      ListNode *&h = (head->val < x) ? pl : pb;
      // h ->next = head;
      // h = h->next;
      h = h->next = head;

      head = head->next;
    }
    pb->next = nullptr; // important, to avoid loop
    pl->next = bigger.next;
    return less.next;
  }
};