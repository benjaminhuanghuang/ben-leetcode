/*
623. Add One Row to Tree

https://leetcode.com/problems/add-one-row-to-tree/
 */
#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *addOneRow(TreeNode *root, int v, int d)
  {
    if (root == nullptr)
      return nullptr;

    // Special case.
    if (d == 1)
    {
      TreeNode *new_root = new TreeNode(v);
      new_root->left = root;
      return new_root;
    }

    if (d == 2)
    {
      TreeNode *l = root->left;
      root->left = new TreeNode(v);
      root->left->left = l;

      TreeNode *r = root->right;
      root->right = new TreeNode(v);
      root->right->right = r;
    }
    else
    {
      addOneRow(root->left, v, d - 1);
      addOneRow(root->right, v, d - 1);
    }

    return root;
  }
};

class Solution
{
public:
  TreeNode *addOneRow(TreeNode *root, int v, int d)
  {
    if (root == nullptr)
      return nullptr;

    // Special case.
    if (d == 1)
    {
      TreeNode *new_root = new TreeNode(v);
      new_root->left = root;
      return new_root;
    }
    else
    {
      int deep = d - 1;
      addRow(root, v, deep, 1);
    }
    return root;
  }

private:
  void addRow(TreeNode *node, int v, int deep, int thisDeep)
  {
    if (node == nullptr)
    {
      return;
    }
    if (deep == thisDeep)
    {
      TreeNode *leftTemp = node->left;
      TreeNode *rightTemp = node->right;
      node->left = new TreeNode(v);
      node->right = new TreeNode(v);
      node->left->left = leftTemp;
      node->right->right = rightTemp;
      return;
    }
    addRow(node->left, v, deep, thisDeep + 1);
    addRow(node->right, v, deep, thisDeep + 1);
  }
};