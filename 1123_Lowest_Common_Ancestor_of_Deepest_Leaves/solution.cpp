/*
1123. Lowest Common Ancestor of Deepest Leaves

Given a rooted binary tree, find the lowest common ancestor of its deepest leaves.

Recall that:

    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
    The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.

 

Example 1:

Input: root = [1,2,3]
Output: [1,2,3]

Example 2:

Input: root = [1,2,3,4]
Output: [4]

Example 3:

Input: root = [1,2,3,4,5]
Output: [2,4,5]

 */

#include "common/TreeNode.h"
#include <vector>

using namespace std;
class ReturnVal
{
public:
  int depth;     //The depth of the deepest leaves on the current subtree
  TreeNode *lca; //The lca of the deepest leaves on the current subtree

  ReturnVal(int d, TreeNode *n)
  {
    depth = d;
    lca = n;
  }
};

class Solution
{
public:
  TreeNode *lcaDeepestLeaves(TreeNode *root)
  {
    ReturnVal res = find(root);
    return res.lca;
  }

private:
  ReturnVal find(TreeNode *root)
  {
    if (root == nullptr)
    {
      return ReturnVal(0, nullptr);
    }
    else
    {
      ReturnVal lRes = find(root->left);
      ReturnVal rRes = find(root->right);

      if (lRes.depth == rRes.depth)
      {
        return ReturnVal(lRes.depth + 1, root);
      }
      else
      {
        return ReturnVal(max(rRes.depth, lRes.depth) + 1, rRes.depth > lRes.depth ? rRes.lca : lRes.lca);
      }
    }
  }
};