
//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include <climits>
#include <algorithm>

#include "common/TreeNode.h"

using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
  int minDiffInBST(TreeNode *root)
  {
    min_diff = INT_MAX;
    prev = nullptr;
    minDiff(root);
    return min_diff;
  }

private:
  int min_diff;
  int *prev;
  void minDiff(TreeNode *root)
  {
    if (root == nullptr)
      return;
    minDiff(root->left);
    if (prev != nullptr)
      min_diff = min(min_diff, abs(root->val - *prev));
    prev = &root->val;
    minDiff(root->right);
  }
};