/*
445. Add Two Numbers II

Level: Medium

https://leetcode.com/problems/add-two-numbers-ii
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> s1;
    stack<int> s2;
    while (l1)
    {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2)
    {
      s2.push(l2->val);
      l2 = l2->next;
    }
    ListNode *head = nullptr;
    int sum = 0;
    while (!s1.empty() || !s2.empty() || sum)
    {
      sum += s1.empty() ? 0 : s1.top();
      sum += s2.empty() ? 0 : s2.top();
      if (!s1.empty())
        s1.pop();
      if (!s2.empty())
        s2.pop();
      ListNode *n = new ListNode(sum % 10);
      sum /= 10;
      n->next = head;
      head = n;
    }
    return head;
  }
};