/*
21. Merge Two Sorted Lists

[#88]
*/
#include "common/ListNode.h"
/*
  Solution:
    Using dummy header
*/
class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for (; l1 != nullptr && l2 != nullptr; p = p->next)
    {
      if (l1->val > l2->val)
      {
        p->next = l2;
        l2 = l2->next;
      }
      else
      {
        p->next = l1;
        l1 = l1->next;
      }
    }
    // Append the rest part of longer list
    p->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
  }
};