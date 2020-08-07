/*
1457. Pseudo-Palindromic Paths in a Binary Tree

Level: Medium

https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
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
  检测每个字符出现的次数odd, even
*/
class Solution
{
public:
  int pseudoPalindromicPaths(TreeNode *root)
  {
    vector<int> counts(10);

    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node)
        return 0;
      ++counts[node->val];
      int c = 0;
      if (!node->left && !node->right)  // leaf onde
      {
        int odds = 0;
        for (int i = 1; i <= 9; ++i)
          if (counts[i] & 1)
            ++odds;
        if (odds <= 1)
          c = 1;
      }
      int l = dfs(node->left);
      int r = dfs(node->right);
      --counts[node->val];
      return c + l + r;
    };

    return dfs(root);
  }
};