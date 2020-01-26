/*
687. Longest Univalue Path

https://leetcode.com/problems/longest-univalue-path/
 */
#include <algorithm>
using namespace std;

#include "common/TreeNode.h"

/*
https://zxi.mytechroad.com/blog/tree/leetcode-687-longest-univalue-path/
Recursion

Time complexity: O(n)

Space complexity: O(n)
 */
class Solution
{
public:
  int longestUnivaluePath(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int ans = 0;
    univaluePath(root, &ans);
    return ans;
  }

private:
  int univaluePath(TreeNode *root, int *ans)
  {
    if (root == nullptr)
      return 0;
    int l = univaluePath(root->left, ans);
    int r = univaluePath(root->right, ans);
    int pl = 0;
    int pr = 0;
    if (root->left && root->val == root->left->val)
      pl = l + 1;
    if (root->right && root->val == root->right->val)
      pr = r + 1;
    *ans = max(*ans, pl + pr);
    return max(pl, pr);
  }
};