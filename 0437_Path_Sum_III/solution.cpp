/*
437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(traveling only from parent nodes to child nodes).
 */

#include "common/TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int pathSum(TreeNode *root, int sum)
  {
    if (root == nullptr)
      return 0;
    helper(root, sum);
    pathSum(root->left, sum);
    pathSum(root->right, sum);

    return count;
  }

private:
  int count;
  //dfs
  void helper(TreeNode *root, int sum)
  {
    if (root == nullptr)
      return;

    sum -= root->val;

    if (sum == 0)
      count++;
    helper(root->left, sum);
    helper(root->right, sum);
  }
};
/*
https://zxi.mytechroad.com/blog/tree/leetcode-437-path-sum-iii/
 
Recursion
Time complexity: O(n^2)

Space complexity: O(n)
 */
class Solution
{
public:
  int pathSum(TreeNode *root, int sum)
  {
    if (!root)
      return 0;
    return numberOfPaths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }

private:
  int numberOfPaths(TreeNode *root, int sum)
  {
    if (!root)
      return 0;
    sum -= root->val;
    return (sum == 0 ? 1 : 0) + numberOfPaths(root->left, sum) + numberOfPaths(root->right, sum);
  }
};

/*
https://zxi.mytechroad.com/blog/tree/leetcode-437-path-sum-iii/

Running Prefix Sum

Same idea to 花花酱 LeetCode 560. Subarray Sum Equals K

Time complexity: O(n)

Space complexity: O(h)

 */
class Solution
{
public:
  int pathSum(TreeNode *root, int sum)
  {
    ans_ = 0;
    sums_ = {{0, 1}};
    pathSum(root, 0, sum);
    return ans_;
  }

private:
  int ans_;
  unordered_map<int, int> sums_;

  void pathSum(TreeNode *root, int cur, int sum)
  {
    if (!root)
      return;
    cur += root->val;
    ans_ += sums_[cur - sum];
    ++sums_[cur];
    pathSum(root->left, cur, sum);
    pathSum(root->right, cur, sum);
    --sums_[cur];
  }
};