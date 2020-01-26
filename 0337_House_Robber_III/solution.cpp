/*
337. House Robber III
https://leetcode.com/problems/house-robber-iii/

给你一棵二叉树，不能同时取两个相邻的节点(parent/child)，问最多能取得的节点的值的和是多少。
 */
#include "common/TreeNode.h"

#include <algorithm>
using namespace std;

/*
https://zxi.mytechroad.com/blog/tree/leetcode-337-house-robber-iii/

Time complexity: O(n^2)

Space complexity: O(n)

 */
class Solution
{
public:
  int rob(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int val = root->val;
    int ll = root->left ? rob(root->left->left) : 0;
    int lr = root->left ? rob(root->left->right) : 0;
    int rl = root->right ? rob(root->right->left) : 0;
    int rr = root->right ? rob(root->right->right) : 0;
    return max(val + ll + lr + rl + rr, rob(root->left) + rob(root->right));
  }
};

class Solution {
public:
  int rob(TreeNode* root) {
    int l = 0;
    int r = 0;
    return rob(root, l, r);    
  }
private:
  // return rob(root) and stores rob(root->left/right) in l/r.
  int rob(TreeNode* root, int& l, int& r) {
    if (root == nullptr) return 0;
    int ll = 0;
    int lr = 0;
    int rl = 0;
    int rr = 0;
    l = rob(root->left, ll, lr);
    r = rob(root->right, rl, rr);    
    return max(root->val + ll + lr + rl + rr, l + r);
  }
};