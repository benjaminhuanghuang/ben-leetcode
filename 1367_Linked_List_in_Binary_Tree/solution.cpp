/*
1367. Linked List in Binary Tree

Level: Medium

https://leetcode.com/problems/linked-list-in-binary-tree
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
  bool isSubPath(ListNode *head, TreeNode *root)
  {
    if (!root)
      return false;
    return isPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }

private:
  bool isPath(ListNode *head, TreeNode *root)
  {
    if (!head)
      return true;
    if (!root)
      return false;
    if (root->val != head->val)
      return false;
    return isPath(head->next, root->left) || isPath(head->next, root->right);
  }
};