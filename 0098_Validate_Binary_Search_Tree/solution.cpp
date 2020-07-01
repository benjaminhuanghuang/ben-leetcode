/*
98. Validate Binary Search Tree

Level: Medium

https://leetcode.com/problems/validate-binary-search-tree
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  bool isValidBST(TreeNode *root)
  {
    return isBST(root, LONG_MIN, LONG_MAX);
  }

  // int can not handle [2147483647]
  bool isBST(TreeNode *n, long min, long max)
  {
    if (n == nullptr)
      return true;
    if (n->val <= min || n->val >= max)
      return false;

    if (!isBST(n->left, min, n->val) || !isBST(n->right, n->val, max))
      return false;
    return true;
  }
};