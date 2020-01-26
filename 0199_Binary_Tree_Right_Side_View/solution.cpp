/*
199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
 */

#include <vector>
#include <queue>
using namespace std;
#include "common/TreeNode.h"

class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    queue<TreeNode *> q;
    if (root == nullptr)
      return res;

    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      { //traveling current level
        TreeNode *curr = q.front();
        q.pop();
        if (i == size - 1)
          res.push_back(curr->val);
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
    }
    return res;
  }
};

class Solution_DFS
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    traverse(root, res, 0);
    return res;
  }

private:
  void traverse(TreeNode *root, vector<int> &result, int depth)
  {
    if (root == nullptr)
      return;
    if (depth == result.size())
    {
      result.push_back(root->val);
    }
    traverse(root->right, result, depth + 1);
    traverse(root->left, result, depth + 1);
  }
};