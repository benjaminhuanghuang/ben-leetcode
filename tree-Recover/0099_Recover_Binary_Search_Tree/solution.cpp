/*
99. Recover Binary Search Tree

Level: Hard

https://leetcode.com/problems/recover-binary-search-tree
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


/*
  https://www.youtube.com/watch?v=sDQhHZJkNh0
  
  Solution:  Inorder traversal

    Using inorder traversal to find two nodes that have val < prev.val

    Time complexity: O(n)
    Space complexity: O(h)
*/
class Solution
{
public:
  void recoverTree(TreeNode *root)
  {
    inorder(root);
    swap(first->val, second->val);
  }

  void inorder(TreeNode *node)
  {
    if (!node)
      return;
    inorder(node->left);
    
    {
      // prev 是当前node的前一个node， 正常情况下 prev->val <= node->val
      if (prev && prev->val > node->val)
      {
        if (!first)
          first = prev;
        second = node;
      }
      prev = node;
    }
    
    inorder(node->right);
  }

private:
  TreeNode *first;
  TreeNode *second;
  TreeNode *prev;
};