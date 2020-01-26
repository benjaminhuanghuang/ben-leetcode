/*
106. Construct Binary Tree from Inorder and Postorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
#include <vector>
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight)
  {
    if (iLeft > iRight || pLeft > pRight)
      return nullptr;

    TreeNode *cur = new TreeNode(postorder[pRight]);
    int i = 0;
    for (i = iLeft; i < inorder.size(); ++i)
    {
      if (inorder[i] == cur->val)
        break;
    }

    cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
    cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
    return cur;
  }
};