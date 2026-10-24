#include <vector>
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  TreeNode *convertBST(TreeNode *root)
  {
    sum = 0;
    rinorder(root);
    return root;
  }

private:
  int sum;
  void rinorder(TreeNode *root)
  {
    if (root == nullptr)
      return;
    rinorder(root->right);
    root->val = (sum += root->val);
    rinorder(root->left);
  }
};