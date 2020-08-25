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

/*
就是维护两个指针，假设有一个相交结点P,
因为headA,headB，到达p的距离是不一样的，为了让他们的距离一样，可以在其中任何一个指针走到尾结点或者NULL时，指向对方的首地址。这样
粗略理解就是，因为某个链表首地址到相交点短一些，那么第一次先到，那么再让他从对方的首地址走，因为这个距离长些，走的多些，这一消一涨就弥补了
差距，也就是说，在两个指针都走了对方的路后，那么这个时刻以后，两个指针到相交结点的步数相同。最坏情况是O(M+N)，空间复杂度上只需要维护两个指针即可
*/
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (!headA || !headB)
      return NULL;
    ListNode *pa, *pb;
    pa = headA;
    pb = headB;

    while (pa != pb)
    {
      if (!pa)
        pa = headB;
      else
        pa = pa->next;

      if (!pb)
        pb = headA;
      else
        pb = pb->next;
    }
    
    if (pa)
      return pa;
    else
      return NULL;
  }
};
