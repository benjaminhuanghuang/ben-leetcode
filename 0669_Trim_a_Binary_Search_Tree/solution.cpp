/*
669. Trim a Binary Search Tree
https://leetcode.com/problems/trim-a-binary-search-tree/
*/
#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *trimBST(TreeNode *root, int L, int R)
  {
    if (!root)
      return nullptr;
    // val not in range, return the left/right subtrees
    if (root->val < L)
      return trimBST(root->right, L, R);
    if (root->val > R)
      return trimBST(root->left, L, R);
    // val in [L, R], recusively trim left/right subtrees
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};
/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/
*/
class Solution
{
public:
  // With cleanup -> no memory leak
  TreeNode *&trimBST(TreeNode *&root, int L, int R)
  {
    if (!root)
      return root;

    if (root->val < L)
    {
      auto &result = trimBST(root->right, L, R);
      deleteTree(root->left);
      delete root;
      root = nullptr;
      return result;
    }
    else if (root->val > R)
    {
      auto &result = trimBST(root->left, L, R);
      deleteTree(root->right);
      delete root;
      root = nullptr;
      return result;
    }
    else
    {
      // recusively trim left/right subtrees
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    }
  }

  void deleteTree(TreeNode *&root)
  {
    if (!root)
      return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
  }
};