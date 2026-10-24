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