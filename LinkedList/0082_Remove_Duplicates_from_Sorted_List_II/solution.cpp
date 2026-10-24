/*
82. Remove Duplicates from Sorted List II

Level: Medium

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == nullptr)
      return head;
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *unique = &dummy;
    while (head != nullptr && head->next != nullptr)
    {
      // find deuplicate value, update value for delete
      if (head->val == head->next->val)
      {
        int value = head->val;
        while (head != nullptr && head->val == value)
          head = head->next;
        unique->next = head;
      }
      else
      {
        head = head->next;
        unique = unique->next;
      }
    }

    return dummy.next;
  }
};