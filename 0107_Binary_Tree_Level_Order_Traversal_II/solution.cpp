/*
107. Binary Tree Level Order Traversal II

https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 */
#include "common/TreeNode.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    queue<TreeNode *> que;
    vector<vector<int>> result;
    que.push(root);
    while (!que.empty())
    {
      vector<int> currentList;
      int size = que.size();
      for (int i = 0; i < size; i++)
      {
        TreeNode *node = que.front();
        que.pop();
        if (node != nullptr)
        {
          currentList.push_back(node->val);
          que.push(node->left);
          que.push(node->right);
        }
      }
      if (!currentList.empty())
      {
        result.push_back(currentList);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};