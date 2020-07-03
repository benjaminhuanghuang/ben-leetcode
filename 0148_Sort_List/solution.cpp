/*
148. Sort List

Level: Medium

https://leetcode.com/problems/sort-list
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
  Note:
    Sort a linked list in O(n log n) time using constant space complexity. 
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
  /*
    Hua Hua
    https://www.youtube.com/watch?v=M1TwY0nsTZA
    Merge Sort(Top-Down): 
      1.Split list into two parts
      2. Sort 递归深度N
      3. Merge logN

    Time complexity: O(NlogN)
    Space complexity: O(logN)   logN为递归深度
    */
  ListNode *sortList(ListNode *head)
  {
    // 递归终止条件 0 or 1 element, we are done.
    if (!head || !head->next)
      return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr; // Break the list.
    return merge(sortList(head), sortList(mid));
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (l1 && l2)
    {
      if (l1->val > l2->val)
        swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }

  /*
      Hua Hua
      https://www.youtube.com/watch?v=M1TwY0nsTZA
      Merge Sort(Bottom-Top)
      logN rounds, each round has 2^(i-1) elements
       Time complexity: O(NlogN)
      Space complexity: O(1) 
    */
  ListNode *sortList(ListNode *head)
  {
    // 0 or 1 element, we are done.
    if (!head || !head->next)
      return head;

    int len = 1;
    ListNode *cur = head;
    while (cur = cur->next)
      ++len;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *l;
    ListNode *r;
    ListNode *tail;
    for (int n = 1; n < len; n <<= 1)
    {
      cur = dummy.next; // partial sorted head
      tail = &dummy;
      while (cur)
      {
        l = cur;
        r = split(l, n);
        cur = split(r, n);
        auto merged = merge2(l, r);
        tail->next = merged.first;
        tail = merged.second;
      }
    }
    return dummy.next;
  }
  // Splits the list into two parts, first n element and the rest.
  // Returns the head of the rest.
  ListNode *split(ListNode *head, int n)
  {
    while (--n && head)
      head = head->next;
    ListNode *rest = head ? head->next : nullptr;
    if (head)
      head->next = nullptr;
    return rest;
  }

  // Merges two lists, returns the head and tail of the merged list.
  pair<ListNode *, ListNode *> merge2(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (l1 && l2)
    {
      if (l1->val > l2->val)
        swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    while (tail->next)
      tail = tail->next;
    return {dummy.next, tail};
  }
};