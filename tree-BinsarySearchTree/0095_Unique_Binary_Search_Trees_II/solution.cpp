/*
95. Unique Binary Search Trees II

Level: Medium

https://leetcode.com/problems/unique-binary-search-trees-ii
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
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

/*

Recursion


Trees(n) = Trees(0)*Trees(n-1) + Trees(1)*Trees(n-2) + … + Tress(n-1)*Trees(0)

Time complexity: O(3^n)

Space complexity: O(3^n)

*/
class Solution
{
public:
  vector<TreeNode *> generateTrees(int n)
  {
    if (n == 0)
      return {};
    const auto &ans = generateTrees(1, n);
    return ans;
  }

private:
  vector<TreeNode *> generateTrees(int l, int r)
  {
    if (l > r)
      return {nullptr};
    vector<TreeNode *> ans;
    for (int i = l; i <= r; ++i)
      for (TreeNode *left : generateTrees(l, i - 1))
        for (TreeNode *right : generateTrees(i + 1, r))
        {
          ans.push_back(new TreeNode(i));
          ans.back()->left = left;
          ans.back()->right = right;
        }
    return ans;
  }
};

/*
  DP
*/
class Solution
{
public:
  vector<TreeNode *> generateTrees(int n)
  {
    if (n == 0)
      return {};
    vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
    dp[0].push_back(nullptr);
    for (int i = 1; i <= n; ++i)
    { //select all nodes in the tree
      for (int j = 0; j < i; ++j)
      { //select j nodes in the left tree
        for (TreeNode *l : dp[j])
        { // all possible left tree nodes in left tree
          for (TreeNode *r : dp[i - j - 1])
          { //all possible tree nodes in right tree
            TreeNode *newNode = new TreeNode(j + 1);
            newNode->left = l;
            newNode->right = clone(r, j + 1);
            dp[i].push_back(newNode);
          }
        }
      }
    }
    return dp[n];
  }

private:
  TreeNode *clone(TreeNode *root, int delta)
  {
    if (root == nullptr)
      return root;
    TreeNode *node = new TreeNode(root->val + delta);
    node->left = clone(root->left, delta);
    node->right = clone(root->right, delta);
    return node;
  }
};