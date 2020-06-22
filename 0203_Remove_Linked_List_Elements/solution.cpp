/*
203. Remove Linked List Elements

Level: Easy

https://leetcode.com/problems/remove-linked-list-elements
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
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    auto prev = dummy;
    auto curr = head;
    while (curr != nullptr)
    {
      if (curr->val == val)
      {
        prev->next = curr->next;
        curr = prev->next;
      }
      else
      {
        prev = prev->next;
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};