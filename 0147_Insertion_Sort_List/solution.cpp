/*
147. Insertion Sort List

Level: Medium

https://leetcode.com/problems/insertion-sort-list
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
  ListNode *insertionSortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode* curr = head;

    while (curr->next)
    {
      if (curr->val <= curr->next->val)
      { //curr node <= next node
        curr = curr->next;
      }
      else
      {
        //curr.val > curr.next.val，那么就将 curr.next取出，从dummyHead向后扫描，在第一个比它的值大的节点之前插入该节点
        ListNode* temp = curr->next;
        ListNode* p = &dummyHead;
        curr->next = curr->next->next;   // 取出 curr.next
        while (p->next->val < temp->val) //找到第一个大于该节点的前一节点
          p = p->next;
        temp->next = p->next; //将 temp 节点插入 p 与 p.next 之间
        p->next = temp;
      }
    }
    return dummyHead.next;
  }
};