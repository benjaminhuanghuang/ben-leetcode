/*
109. Convert Sorted List to Binary Search Tree

Level: Medium

https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    ListNode *end = head;
    while (end->next != nullptr)
    {
      end = end->next;
    }

    return sortedListToBSTRecursion(head, end);
  }

private:
  TreeNode *sortedListToBSTRecursion(ListNode *head, ListNode *end)
  {
    if (head == nullptr || end == nullptr || head == end->next)
    {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *preslow = nullptr;
    ListNode *fast = head;
    while (fast != end && fast->next != end)
    {
      preslow = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBSTRecursion(head, preslow);
    root->right = sortedListToBSTRecursion(slow->next, end);

    return root;
  }
};