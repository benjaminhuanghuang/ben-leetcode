/*
234. Palindrome Linked List

Level: Easy

https://leetcode.com/problems/palindrome-linked-list


- 206. Reverse Linked List

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return true;

    //find list center
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *secondHead = slow->next;
    slow->next = nullptr;

    //reverse second part of the list
    ListNode *prev = nullptr;
    ListNode *curr = secondHead;

    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    //compare two sublists
    ListNode* p = prev;
    ListNode* q = head;
    while (p)
    {
      if (p->val != q->val)
        return false;

      p = p->next;
      q = q->next;
    }

    return true;
  }
};