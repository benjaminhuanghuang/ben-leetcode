/*
328. Odd Even Linked List

Level: Medium

https://leetcode.com/problems/odd-even-linked-list
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *evenHeader = head->next;

        ListNode *p1 = head;
        ListNode *p2 = head->next;

        while (p1 && p2)
        {
            if (p2->next == nullptr)
                break;

            p1->next = p2->next;
            p1 = p1->next;

            p2->next = p1->next;
            p2 = p2->next;
        }

        p1->next = evenHeader;

        return head;
    }
};