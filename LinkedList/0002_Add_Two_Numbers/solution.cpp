/*
2. Add Two Numbers

Level: Medium

https://leetcode.com/problems/add-two-numbers
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
    int carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (l1 && l2)
    {
      int sum = l1->val + l2->val + carry;
      int digit = sum % 10;
      carry = sum / 10;
      curr->next = new ListNode(digit);
      curr = curr->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1)
    {
      int sum = l1->val + carry;
      int digit = sum % 10;
      carry = sum / 10;
      curr->next = new ListNode(digit);
      curr = curr->next;
      l1 = l1->next;
    }
    while (l2)
    {
      int sum = l2->val + carry;
      int digit = sum % 10;
      carry = sum / 10;
      curr->next = new ListNode(digit);
      curr = curr->next;
      l2 = l2->next;
    }

    if (carry > 0)
    {
      curr->next = new ListNode(carry);
    }

    return dummy->next;
  }

  ListNode *addTwoNumbers_v2(ListNode *l1, ListNode *l2)
  {
    int carry = 0, ans = 0;
    ListNode dummy(0);
    ListNode *res = &dummy;
    int x = 0, y = 0;
    while (l1 || l2 || carry)
    {
      x = l1 ? l1->val : 0;
      y = l2 ? l2->val : 0;
      ans = x + y + carry;
      carry = ans / 10;
      ans %= 10;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
      ListNode *no = new ListNode(ans);
      res->next = no;
      res = no;
    }
    return dummy.next;
  }
};