#include "common/TreeNode.h"
/*
 Using max_row
 */
class Solution
{
public:
  int findBottomLeftValue(TreeNode *root)
  {
    int max_row = -1;
    int ans;
    inorder(root, 0, max_row, ans);
    return ans;
  }

private:
  void inorder(TreeNode *root, int row, int &max_row, int &ans)
  {
    if (root == nullptr)
      return;
    inorder(root->left, row + 1, max_row, ans);
    if (row > max_row)
    {
      ans = root->val;
      max_row = row;
    }
    inorder(root->right, row + 1, max_row, ans);
  }
};