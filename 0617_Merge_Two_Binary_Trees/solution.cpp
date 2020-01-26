/*
617. Merge Two Binary Trees

https://leetcode.com/problems/merge-two-binary-trees/
 */
#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == nullptr)
      return t2;
    if (t2 == nullptr)
      return t1;

    auto root = t1;
    root->val += t2->val;
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);

    return root;
  }
};
/*
  Create copy
 */
class Solution
{
public:
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == nullptr)
      return copyTree(t2);
    if (t2 == nullptr)
      return copyTree(t1);

    TreeNode *root = new TreeNode(t1->val + t2->val);
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);

    return root;
  }

private:
  TreeNode *copyTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;
    TreeNode *r = new TreeNode(root->val);
    r->left = copyTree(root->left);
    r->right = copyTree(root->right);
    return r;
  }
};