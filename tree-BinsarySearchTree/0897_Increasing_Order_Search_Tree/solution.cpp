/*
897. Increasing Order Search Tree
https://leetcode.com/problems/increasing-order-search-tree/
 */

#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *increasingBST(TreeNode *root)
  {
    TreeNode dummy(0);
    prev_ = &dummy;
    inorder(root);
    return dummy.right;
  }

private:
  TreeNode *prev_;
  void inorder(TreeNode *root)
  {
    if (root == nullptr)
      return;
    inorder(root->left);
    prev_->right = root;
    prev_ = root;
    prev_->left = nullptr;
    inorder(root->right);
  }
};