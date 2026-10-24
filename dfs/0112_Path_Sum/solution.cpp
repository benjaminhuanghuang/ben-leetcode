/*
112. Path Sum
https://leetcode.com/problems/path-sum/
 */

#include "common/TreeNode.h"
/*
Time complexity: O(n)

Space complexity: O(n)
 */
class Solution
{
public:
  bool hasPathSum(TreeNode *root, int sum)
  {
    if (!root)
      return false;
    if (!root->left && !root->right)
      return root->val == sum;
    int new_sum = sum - root->val;
    return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
  }
};