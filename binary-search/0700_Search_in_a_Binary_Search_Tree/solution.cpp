
/*
700. Search in a Binary Search Tree

https://leetcode.com/problems/search-in-a-binary-search-tree/
*/
#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == nullptr)
      return nullptr;
    if (val == root->val)
      return root;
    else if (val > root->val)
      return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
};