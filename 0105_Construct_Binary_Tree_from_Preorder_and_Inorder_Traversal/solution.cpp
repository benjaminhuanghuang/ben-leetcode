/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include <vector>
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight)
  {
    if (iLeft > iRight || pLeft > pRight)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[pLeft]);

    for (int k = iLeft; k <= iRight; k++)
    {
      if (preorder[pLeft] == inorder[k])
      {
        root->left = buildTree(preorder, pLeft + 1, pLeft + (k - iLeft), inorder, iLeft, k - 1);
        root->right = buildTree(preorder, pLeft + (k - iLeft) + 1, pRight, inorder, k + 1, iRight);
      }
    }
    return root;
  }
};