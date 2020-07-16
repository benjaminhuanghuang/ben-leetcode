/*
92. Reverse Linked List II

Level: Medium

https://leetcode.com/problems/reverse-linked-list-ii
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
  ListNode *reverseBetween(ListNode *head, int m, int n)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Find the m-1 th node
    for (int i = 0; i < m - 1; ++i)
      prev = prev->next;

    // curr points to node m
    ListNode *curr = prev->next;

    // Reverse from m to n
    for (int i = m; i < n; ++i)
    {
      ListNode *t = curr->next;
      curr->next = t->next;
      t->next = prev->next;
      prev->next = t;
    }
    return dummy.next;
  }
};