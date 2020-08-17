/*
1171. Remove Zero Sum Consecutive Nodes from Linked List

Level: Medium

https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
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

/*
  Solution: HashTable

    Similar to target sum = 0, use a hashtable to store the first ListNode* that 
    has a given prefix sum. 
    Whenever the same prefix sum occurs,  sskip all the elements between the first 
    occurrence and current one, e.g. first_sum_x.next = curr_sum_x.next

    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution
{
public:
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode dummy(0);
    dummy.next = head;
    unordered_map<int, ListNode *> m;
    m[0] = &dummy;
    int sum = 0;
    while (head)
    {
      sum += head->val;
      m[sum] = head;
      head = head->next;
    }
    head = &dummy;
    sum = 0;
    while (head)
    {
      sum += head->val;
      ListNode *temp = m[sum];
      if (temp != head)
      {
        // skip
        head->next = temp->next;
      }
      head = head->next;
    }
    return dummy.next;
  }
};

/*
  Reason: did not remove items from m after skip
*/
class Solution_Wrong
{
public:
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = prev->next;
    unordered_map<int, ListNode *> m{{0, prev}};
    int s = 0;
    while (curr)
    {
      s += curr->val;
      if (m.count(s))
        // did not remove items from m after skip!
        m[s]->next = curr->next; // skip
      else
        m[s] = curr;

      prev = curr;
      curr = curr->next;
    }
    return dummy.next;
  }
};