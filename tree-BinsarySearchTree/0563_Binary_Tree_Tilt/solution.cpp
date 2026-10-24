/*
563. Binary Tree Tilt

https://leetcode.com/problems/binary-tree-tilt/

返回树的总tilt值。对于一个节点的tilt值定义为左右子树元素和的绝对之差。
 */
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
