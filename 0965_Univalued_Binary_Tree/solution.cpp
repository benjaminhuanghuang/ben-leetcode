/*
965. Univalued Binary Tree
https://leetcode.com/problems/univalued-binary-tree/
 */
#include "common/TreeNode.h"

class Solution
{
public:
  bool isUnivalTree(TreeNode *root)
  {
    if (root == nullptr)
      return true;
    return helper(root->left, root->val) && helper(root->right, root->val);
  }

private:
  bool helper(TreeNode *root, int val)
  {
    if (root == nullptr)
      return true;

    return root->val == val && helper(root->left, val) && helper(root->right, val);
  }
};

class Solution
{
public:
  bool isUnivalTree(TreeNode *root)
  {
    if (!root)
      return true;
    if (root->left && root->val != root->left->val)
      return false;
    if (root->right && root->val != root->right->val)
      return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
  }
};