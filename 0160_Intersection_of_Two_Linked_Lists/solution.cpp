/*
160. Intersection of Two Linked Lists

Level: Easy

https://leetcode.com/problems/intersection-of-two-linked-lists
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (headA == NULL || headB == NULL)
      return NULL;
    auto getLength = [](ListNode *head) {
      int len = 0;
      while (head != NULL)
      {
        ++len;
        head = head->next;
      }
      return len;
    };

    int lenA = getLength(headA), lenB = getLength(headB);
    if (lenA > lenB)
    {
      while (lenA != lenB)
      {
        headA = headA->next;
        lenA--;
      }
    }
    else
    {
      while (lenA != lenB)
      {
        headB = headB->next;
        lenB--;
      }
    }
    while (headA != NULL && headB != NULL && headA != headB)
    {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};