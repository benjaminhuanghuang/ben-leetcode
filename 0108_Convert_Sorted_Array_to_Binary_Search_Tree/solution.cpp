/*
108. Convert Sorted Array to Binary Search Tree
 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */
#include <vector>

using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return helper(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *helper(vector<int> &nums, int left, int right)
  {
    if(left>right)
      return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid-1);
    root->right = helper(nums, mid+1, right);
  }
};