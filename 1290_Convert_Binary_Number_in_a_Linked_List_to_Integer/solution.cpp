/*
1290. Convert Binary Number in a Linked List to Integer

Level: Easy

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
*/
#include <vector>
#include <string>
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
  int getDecimalValue(ListNode *head)
  {
    int val = 0;
    while (head)
    {
      val = (val << 1) + head->val;
      head = head->next;
    }
    return val;
  }
};