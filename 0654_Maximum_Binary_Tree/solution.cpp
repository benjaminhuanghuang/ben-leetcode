/*
654. Maximum Binary Tree
https://leetcode.com/problems/maximum-binary-tree/
 */
#include <vector>
using namespace std;

#include "common/TreeNode.h"

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-654-maximum-binary-tree/
Solution:

With copy

Time complexity: O(nlogn) ~ O(n^2)
Space complexity: O(nlogn) ~ O(n^2)
 */
class Solution
{
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums)
  {
    return makeMBT(nums, 0, nums.size());
  }

private:
  TreeNode *makeMBT(const vector<int> &nums, int begin, int end)
  {
    if (begin >= end)
      return nullptr;
    auto it = std::max_element(nums.begin() + begin, nums.begin() + end);
    TreeNode *root = new TreeNode(*it);
    int index = it - nums.begin();
    root->left = makeMBT(nums, begin, index);
    root->right = makeMBT(nums, index + 1, end);
    return root;
  }
};
