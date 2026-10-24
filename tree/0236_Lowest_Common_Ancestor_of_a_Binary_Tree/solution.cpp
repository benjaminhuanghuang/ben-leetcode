/*
236. Lowest Common Ancestor of a Binary Tree

Level: Medium

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    //发现目标节点则通过返回值,标记该子树发现了某个目标结点
    if (root == nullptr || root == p || root == q)
      return root;
    //查看左子树中是否有目标结点，没有为null
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    //查看右子树是否有目标节点，没有为null
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    //都不为空，说明做右子树都有目标结点，则公共祖先就是本身
    if (left && right)
      return root;
    return left ? left : right;
  }
};