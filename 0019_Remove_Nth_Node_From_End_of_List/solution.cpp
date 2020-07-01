/*
19. Remove Nth Node From End of List

Level: Medium

https://leetcode.com/problems/remove-nth-node-from-end-of-list
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *start = dummy;
    ListNode *end = dummy;

    // Note "start" is node before Nth node from end 
    while (n >= 0)
    {
      end = end->next;
      n--;
    }

    while (end)
    {
      end = end->next;
      start = start->next;
    }
    start->next = start->next->next;
    return dummy->next;
  }
};