/*
865. Smallest Subtree with all the Deepest Nodes
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
 */

#include <algorithm>
using namespace std;

#include "common/TreeNode.h"
/*
https://zxi.mytechroad.com/blog/tree/leetcode-865-smallest-subtree-with-all-the-deepest-nodes/

 */

class Solution
{
public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root)
  {
    return depth(root).second;
  }

private:
  pair<int, TreeNode *> depth(TreeNode *root)
  {
    if (root == nullptr)
      return {-1, nullptr};
    auto l = depth(root->left);
    auto r = depth(root->right);
    int dl = l.first;
    int dr = r.first;
    return {max(dl, dr) + 1,
            dl == dr ? root : (dl > dr) ? l.second : r.second};
  }
};

class Solution
{
public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root)
  {
    TreeNode *ans;
    depth(root, &ans);
    return ans;
  }

private:
  int depth(TreeNode *root, TreeNode **s)
  {
    if (root == nullptr)
      return -1;
    TreeNode *sl;
    TreeNode *sr;
    int l = depth(root->left, &sl);
    int r = depth(root->right, &sr);
    *s = (l == r) ? root : ((l > r) ? sl : sr);
    return max(l, r) + 1;
  }
};