/*
235. Lowest Common Ancestor of a Binary Search Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
#include <vector>
#include <string>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root->val > p->val && root->val > q->val)
    {
      // left part
      return lowestCommonAncestor(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val)
    {
      // right parts
      return lowestCommonAncestor(root->right, p, q);
    }
    //root->val > p->val && root->val < q->val
    return root;
  }
};