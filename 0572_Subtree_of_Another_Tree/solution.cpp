/*
572. Subtree of Another Tree

https://leetcode.com/problems/subtree-of-another-tree/
 */
#include "common/TreeNode.h"
/*
Recursion
Time complexity: O(max(n, m))
Space complexity: O(max(n, m))
 */
class Solution
{
public:
  bool isSubtree(TreeNode *s, TreeNode *t)
  {
    if (t == nullptr)
      return true;
    if (s == nullptr)
      return false;
    if (isSameTree(s, t))
      return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

private:
  bool isSameTree(TreeNode *s, TreeNode *t)
  {
    if (s == nullptr && t == nullptr)
      return true;
    if (s == nullptr || t == nullptr)
      return false;
    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
  }
};