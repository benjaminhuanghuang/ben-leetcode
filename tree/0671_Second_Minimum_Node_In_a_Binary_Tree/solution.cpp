/*
671. Second Minimum Node In a Binary Tree
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

 If the node has two sub-nodes, then this node’s value is the smaller value among its two sub-nodes.
 
 */

#include "common/TreeNode.h"
#include "algorithm"

using namespace std;

class Solution
{
public:
  int findSecondMinimumValue(TreeNode *root)
  {
    if (!root)
      return -1;

    return DFS(root, root->val);
  }

private:
  // Return the second smallest number in the (sub-tree)
  // s1 is the smallest value
  int DFS(TreeNode *root, int s1)
  {
    if (!root)
      return -1;

    // If root's value is already grater than s1,
    // then all its children's value should be >= s1.
    // Thus root's value is the second smallest one.
    // No need to visit the
    if (root->val > s1)
      return root->val;

    int sl = DFS(root->left, s1);
    int sr = DFS(root->right, s1);

    if (sl == -1)
      return sr;
    if (sr == -1)
      return sl;

    // Return the smaller one among two subtrees
    return min(sl, sr);
  }
};