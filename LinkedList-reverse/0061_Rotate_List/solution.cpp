/*
61. Rotate List

Level: Medium

https://leetcode.com/problems/rotate-list
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
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == nullptr || k == 0)
      return head;
    ListNode *p = head;

    // Get list length
    int length = 1;
    while (p->next != nullptr)
    {
      p = p->next;
      length++;
    }
    p->next = head; // make a cycle

    // rotate the list to the right by k places,意味着把最右的 k个 node砍下来，接到头上
    int step = length - (k % length);
    // find the cutting point
    for (int i = 0; i < step; i++)
    {
      p = p->next;
    }
    // p is the new tail
    head = p->next;
    p->next = nullptr; // cut the cycle
    return head;
  }
};