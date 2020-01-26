/*
404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/
 */
#include "common/TreeNode.h"
#include <queue>

using namespace std;

class Solution
{
public:
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (!root)
      return 0;
    if (root->left && !root->left->left && !root->left->right)
      return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

class Solution
{
public:
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int sum = 0;
    while (!q.empty())
    {
      TreeNode *n = q.front();
      q.pop();

      TreeNode *l = n->left;
      if (l)
      {
        if (!l->left && !l->right)
          sum += l->val;
        else
          q.push(l);
      }
      if (n->right)
        q.push(n->right);
    }
    return sum;
  }
};