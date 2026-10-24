/*
653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/

#include <vector>
#include <unordered_set>
#include "common/TreeNode.h"

using namespace std;
class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    vector<int> nums;
    inorder(root, nums);
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
      int sum = nums[l] + nums[r];
      if (sum == k)
        return true;
      else if (sum < k)
        ++l;
      else
        --r;
    }

    return false;
  }

private:
  void inorder(TreeNode *root, vector<int> &nums)
  {
    if (root == nullptr)
      return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
};

class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    unordered_set<int> set;
    return find(root, k, set);
  }

private:
  bool find(TreeNode *root, int k, unordered_set<int> &set)
  {
    if (root == nullptr)
      return false;
    if (set.count(k - root->val))
      return true;

    set.insert(root->val);
    return find(root->left, k, set) || find(root->right, k, set);
  }
};