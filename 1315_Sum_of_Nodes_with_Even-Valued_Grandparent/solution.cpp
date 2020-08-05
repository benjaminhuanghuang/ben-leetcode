/*
1315. Sum of Nodes with Even-Valued Grandparent

Level: Medium

https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent
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
  int sumEvenGrandparent(TreeNode *root)
  {
    return dfs(root, 1, 1);
  }

private:
  int dfs(TreeNode *root, int parentVal = 1, int gpVal = 1)
  {
    if (!root)
      return 0;
    return dfs(root->left, root->val, parentVal) + dfs(root->right, root->val, parentVal) + (gpVal & 1 ? 0 : root->val);
  }
};