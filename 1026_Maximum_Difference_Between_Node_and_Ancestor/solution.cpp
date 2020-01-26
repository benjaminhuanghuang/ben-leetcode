//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
#include "common/TreeNode.h"
#include <algorithm>

using namespace std;
/*
  Time complexity O(N)  每个node访问一次
  Space complexity O(N)  stack depth
*/
class Solution
{
public:
  int maxAncestorDiff(TreeNode *root)
  {
    if (!root)
      return 0;
    return maxDiff(root, root->val, root->val);
  }

private:
  int maxDiff(TreeNode *root, int minAncestor, int maxAncestor)
  {
    if (!root)
      return 0;
    int cur = max(abs(root->val - minAncestor), abs(root->val - maxAncestor));
    minAncestor = min(minAncestor, root->val);
    maxAncestor = max(maxAncestor, root->val);

    return max(cur, max(maxDiff(root->left, minAncestor, maxAncestor), maxDiff(root->right, minAncestor, maxAncestor)));
  }
};