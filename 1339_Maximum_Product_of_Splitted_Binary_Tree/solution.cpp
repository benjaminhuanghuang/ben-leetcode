/*
1339. Maximum Product of Splitted Binary Tree

Level: Medium

https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
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
  int maxProduct(TreeNode *root)
  {
    const int kMod = 1e9 + 7;
    long s = 0;
    long ans = 0;

    function<int(TreeNode *)> sum = [&](TreeNode *r) {
      if (!r)
        return 0;
      int sl = sum(r->left);
      int sr = sum(r->right);
      if (s)
        ans = max({ans, (s - sl) * sl, (s - sr) * sr});
      return r->val + sl + sr;
    };
    
    s = sum(root);
    sum(root);
    return ans % kMod;
  }
};