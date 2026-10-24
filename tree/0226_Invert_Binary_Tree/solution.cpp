/*
226. Invert Binary Tree

https://leetcode.com/problems/invert-binary-tree/
*/

#include "common/TreeNode.h"
class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
      return root;

    TreeNode *tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;

    return root;
  }
};