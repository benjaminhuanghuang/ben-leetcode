/*
1372. Longest ZigZag Path in a Binary Tree

Level: Medium

https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
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
  int longestZigZag(TreeNode *root)
  {
    return get<2>(ZigZag(root));
  }

  // Returns {left, right, max}
  tuple<int, int, int> ZigZag(TreeNode *root)
  {
    if (!root)
      return {-1, -1, -1};
    auto [ll, lr, lm] = ZigZag(root->left);
    auto [rl, rr, rm] = ZigZag(root->right);
    int l = lr + 1;
    int r = rl + 1;
    return {l, r, max({l, r, lm, rm})};
  }
};