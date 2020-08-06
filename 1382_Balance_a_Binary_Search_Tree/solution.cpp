/*
1382. Balance a Binary Search Tree

Level: Medium

https://leetcode.com/problems/balance-a-binary-search-tree
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
  Solution: 
  inorder + rebuild

*/

class Solution
{
public:
  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> vals;
    function<void(TreeNode *)> inorder = [&](TreeNode *root) {
      if (!root)
        return;
      inorder(root->left);
      vals.push_back(root->val);
      inorder(root->right);
    };

    function<TreeNode *(int, int)> build = [&](int l, int r) {
      if (l > r)
        return (TreeNode *)nullptr;
      int m = l + (r - l) / 2;
      auto root = new TreeNode(vals[m]);
      root->left = build(l, m - 1);
      root->right = build(m + 1, r);
      return root;
    };

    inorder(root);
    return build(0, vals.size() - 1);
  }
};