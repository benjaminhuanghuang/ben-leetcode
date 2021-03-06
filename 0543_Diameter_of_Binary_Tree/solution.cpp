/*
543. Diameter of Binary Tree

Level: Easy

https://leetcode.com/problems/diameter-of-binary-tree
 */
#include <string>
#include <vector>
#include <set>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  int diameterOfBinaryTree(TreeNode *root)
  {
    maxDepth(root);
    return diameter;
  }

private:
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    diameter = max(diameter, left + right);  //diameter 是edge的数量而不是node的数量，因此不用 + 1
    return 1 + max(left, right);
  }
  int diameter = 0;
};