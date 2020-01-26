/*
998. Maximum Binary Tree II

https://leetcode.com/problems/maximum-binary-tree-ii/
 */

#include "common/TreeNode.h"
/*
https://www.youtube.com/watch?time_continue=126&v=ACBdojAxPSc

Since val is the last element of the array, we compare root->val with val, 
if root->val > val then val can be inserted into the right subtree recursively, 
otherwise, root will be the left subtree of val.
 */
class Solution
{
public:
  TreeNode *insertIntoMaxTree(TreeNode *root, int val)
  {
    if (root && root->val > val)
    {
      root->right = insertIntoMaxTree(root->right, val);
      return root;
    }
    auto node = new TreeNode(val);
    node->left = root;
    return node;
  }
};