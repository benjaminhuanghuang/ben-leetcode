/*
230. Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 */
#include <stack>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    return inorder(root, k);
  }

private:
  int inorder(TreeNode *root, int &k)
  {
    if (!root)
      return -1;
    int x = inorder(root->left, k);
    if (k == 0)
      return x;
    if (--k == 0)
      return root->val;
    return inorder(root->right, k);
  }
};

/*
  Using stack
 */
class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    stack<TreeNode *> stack;
    TreeNode *node = root;

    while (node != nullptr)
    {
      stack.push(node);
      node = node->left;
    }
    int x = 1;
    while (stack.size() > 0 && x <= k)
    {
      node = stack.top();
      stack.pop();
      x++;
      TreeNode *right = node->right;
      while (right != nullptr)
      {
        stack.push(right);
        right = right->left;
      }
    }
    return node->val;
  }
};