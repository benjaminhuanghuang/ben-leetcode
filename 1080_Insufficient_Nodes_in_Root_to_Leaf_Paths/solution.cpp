/*
1080. Insufficient Nodes in Root to Leaf Paths

Level: Medium

https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *sufficientSubset(TreeNode *root, int limit)
  {
    cut(root, limit, root->val);
    return root;
  }

private:
  void cut(TreeNode *&root, int limit, int sum)
  {
    if (root->left == NULL && root->right == NULL)
    {
      if (sum < limit)
        root = NULL;
      return;
    }
    if (root->left)
    {
      cut(root->left, limit, sum + root->left->val);
    }
    if (root->right)
    {
      cut(root->right, limit, sum + root->right->val);
    }
    if (root->left == NULL && root->right == NULL)
      root = NULL;
  }
};