/*
24. Swap Nodes in Pairs

Level: Medium

https://leetcode.com/problems/swap-nodes-in-pairs
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
  ListNode *swapPairs(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode dummy(-1);
    dummy.next = head;
    head = &dummy;

    while (head && head->next && head->next->next)
    {
      ListNode *n1 = head->next;
      ListNode *n2 = n1->next;

      n1->next = n2->next;
      n2->next = n1;
      head->next = n2;

      head = n1;
    }

    return dummy.next;
  }
};