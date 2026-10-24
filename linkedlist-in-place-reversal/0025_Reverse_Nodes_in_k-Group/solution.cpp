/*
25. Reverse Nodes in k-Group

Level: Hard

https://leetcode.com/problems/reverse-nodes-in-k-group
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
  Solution: Two passes.

    First pass, get the length of the list.

    Second pass, swap in groups.

    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (!head || k == 1)
      return head;

    ListNode dummy(0);
    dummy.next = head;

    // get length 
    int len = 1;
    while (head = head->next)
      len++;
      
    // reverse  
    ListNode *pre = &dummy;
    for (int l = 0; l + k <= len; l += k)
    {
      ListNode *cur = pre->next;
      ListNode *nxt = cur->next;
      for (int i = 1; i < k; ++i)
      {
        cur->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;
        nxt = cur->next;
      }
      pre = cur;
    }
    return dummy.next;
  }
};