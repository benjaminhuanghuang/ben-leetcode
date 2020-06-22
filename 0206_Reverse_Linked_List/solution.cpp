/*
206. Reverse Linked List

Level: Easy

https://leetcode.com/problems/reverse-linked-list
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
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};