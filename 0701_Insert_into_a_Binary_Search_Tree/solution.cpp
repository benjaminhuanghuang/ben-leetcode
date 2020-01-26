/*
701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/
 */

#include "common/TreeNode.h"
/*
https://zxi.mytechroad.com/blog/tree/leetcode-701-insert-into-a-binary-search-tree/
Solution: Recursion

Time complexity: O(logn ~ n)

Space complexity: O(logn ~ n)
 */
class Solution
{
public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (root == nullptr)
      return new TreeNode(val);
    if (val > root->val)
      root->right = insertIntoBST(root->right, val);
    else
      root->left = insertIntoBST(root->left, val);
    return root;
  }
};