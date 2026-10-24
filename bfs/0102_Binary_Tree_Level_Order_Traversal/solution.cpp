/*
102. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
#include <vector>
#include <queue>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      vector<int> layer;
      // for (int i = 0; i < q.size(); i++) // ERROR!!
      int count = q.size();
      for (int i = 0; i < count; i++)
      {
        TreeNode *n = q.front();
        q.pop();
        layer.push_back(n->val);
        if (n->left)
        {
          q.push(n->left);
        }
        if (n->right)
        {
          q.push(n->right);
        }
      }
      ans.push_back(layer);
    }
    return ans;
  }
};

/*
DFS O(n)
 */
class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    DFS(root, 0 /* depth */, ans);
    return ans;
  }

private:
  void DFS(TreeNode *root, int depth, vector<vector<int>> &ans)
  {
    if (!root)
      return;
    // Works with pre/in/post order
    while (ans.size() <= depth)
      ans.push_back({});
    ans[depth].push_back(root->val); // pre-order
    DFS(root->left, depth + 1, ans);
    DFS(root->right, depth + 1, ans);
  }
};