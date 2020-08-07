/*
1448. Count Good Nodes in Binary Tree

Level: Medium

https://leetcode.com/problems/count-good-nodes-in-binary-tree
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
  int goodNodes(TreeNode *root, int max_val = INT_MIN)
  {
    if (!root)
      return 0;
    return goodNodes(root->left, max(max_val, root->val)) + goodNodes(root->right, max(max_val, root->val)) + (root->val >= max_val ? 1 : 0);
  }
};

class Solution_My_Wrong
{
public:
  int goodNodes(TreeNode *root)
  {
    if (root)
    {
      return goodNodes(root->left, root->val) + goodNodes(root->right, root->val) + 1;
    }
    return 0;
  }

private:
  int goodNodes(TreeNode *root, int target)
  {
    if (root)
    {
      return goodNodes(root->left, target) + goodNodes(root->right, target) + target >= root->val;
    }
    return 0;
  }
};