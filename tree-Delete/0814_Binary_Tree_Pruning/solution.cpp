/*
814. Binary Tree Pruning
https://leetcode.com/problems/binary-tree-pruning/
 把不含有1的节点的子树全部删除。
 */

#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *pruneTree(TreeNode *root)
  {
    if (!root)
      return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 1 || root->left || root->right)
      return root;
    delete root; // note!
    return nullptr;
  }
};