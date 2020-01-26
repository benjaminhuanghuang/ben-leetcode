/*
110. Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/
 */
#include <algorithm>
using namespace std;

#include "common/TreeNode.h"

/*
get height
Solution 1: O(nlogn)
 */
class Solution
{
public:
  bool isBalanced(TreeNode *root)
  {
    if (!root)
      return true;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (abs(left_height - right_height) <= 1) && isBalanced(root->left) && isBalanced(root->right);
  }

private:
  int height(TreeNode *root)
  {
    if (!root)
      return 0;
    return max(height(root->left), height(root->right)) + 1;
  }
};

// O(n)
class Solution
{
public:
  bool isBalanced(TreeNode *root)
  {
    if (!root)
      return true;
    bool balanced = true;
    height(root, &balanced);
    return balanced;
  }

private:
  int height(TreeNode *root, bool *balanced)
  {
    if (!root)
      return 0;
    int left_height = height(root->left, balanced);
    if (!balanced)
      return -1;
    int right_height = height(root->right, balanced);
    if (!balanced)
      return -1;
    if (abs(left_height - right_height) > 1)
    {
      *balanced = false;
      return -1;
    }
    return max(left_height, right_height) + 1;
  }
};