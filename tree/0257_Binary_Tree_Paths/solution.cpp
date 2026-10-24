/*
257. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/
 */

#include <vector>
#include <string>
using namespace std;

#include "common/TreeNode.h"
class Solution
{
public:
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> res;
    if (root == nullptr)
      return res;

    if (root->left == nullptr && root->right == nullptr)
    {
      res.push_back(to_string(root->val));
    }
    if (root->left != nullptr)
    {
      for (string path : binaryTreePaths(root->left))
      {
        res.push_back(to_string(root->val) + "->" + path);
      }
    }
    if (root->right != nullptr)
    {
      for (string path : binaryTreePaths(root->right))
      {
        res.push_back(to_string(root->val) + "->" + path);
      }
    }

    return res;
  }
};