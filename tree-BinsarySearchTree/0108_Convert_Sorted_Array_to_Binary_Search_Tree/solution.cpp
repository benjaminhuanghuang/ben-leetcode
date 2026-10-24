/*
108. Convert Sorted Array to Binary Search Tree

 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */
#include <vector>
#include <functional>

using namespace std;

#include "common/TreeNode.h"

/*
  https://zxi.mytechroad.com/blog/tree/leetcode-108-convert-sorted-array-to-binary-search-tree/

  Time complexity: O(n)    
  Space complexity: O(logn)
*/
class Solution
{
public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    //- the helper function
    function<TreeNode *(int l, int r)> build = [&](int l, int r) {
      if (l > r)
        return static_cast<TreeNode *>(nullptr);
      int m = l + (r - l) / 2;
      TreeNode *root = new TreeNode(nums[m]);
      root->left = build(l, m - 1);
      root->right = build(m + 1, r);
      return root;
    };

    return build(0, nums.size() - 1);
  }
};

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
    if (left > right)
      return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
  }
};