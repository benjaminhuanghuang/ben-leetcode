#include "common/TreeNode.h"

class Solution
{
public:
  int sumRootToLeaf(TreeNode *root)
  {
    return sums(root, 0);
  }

private:
  int sums(TreeNode *root, int sum)
  {
    if (!root)
      return 0;
    sum = (sum << 1) | root->val;
    if (!root->left && !root->right)
    {
      return sum;
    }
    return sums(root->left, sum) + sums(root->right, sum);
  }
};