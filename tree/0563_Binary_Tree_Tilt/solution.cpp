#include <algorithm>

#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  int findTilt(TreeNode *root)
  {
    return findTiltSum(root).first;
  }

private:
  pair<int, int> findTiltSum(TreeNode *root)
  {
    if (root == nullptr)
      return {0, 0};
    auto l = findTiltSum(root->left);
    auto r = findTiltSum(root->right);
    return {l.first + r.first + abs(l.second - r.second),
            root->val + l.second + r.second};
  }
};
