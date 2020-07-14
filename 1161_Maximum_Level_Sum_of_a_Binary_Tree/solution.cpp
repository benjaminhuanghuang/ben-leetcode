/*
1161. Maximum Level Sum of a Binary Tree

Level: Medium

https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


/*
   利用先序 遍历对每层求和
*/
class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    vector<int> sums;

    function<void(TreeNode *, int)> preorder = [&](TreeNode *n, int d) {
      if (!n)
        return;
      while (sums.size() <= d)
        sums.push_back(0);
      sums[d] += n->val;
      preorder(n->left, d + 1);
      preorder(n->right, d + 1);
    };
    preorder(root, 1);

    int max_sum = sums[1];
    int ans = 1;
    for (int i = 2; i < sums.size(); ++i)
      if (sums[i] > max_sum)
      {
        max_sum = sums[i];
        ans = i;
      }
    return ans;
  }
};

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    if (root == nullptr)
      return -1;
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    int max_sum = INT_MIN;
    int ans = -1;
    int count = 1;
    while (!q.empty())
    {
      int level_count = 0;
      int level_sum = 0;
      while (count != 0)
      {
        TreeNode *curr = q.front();
        level_sum += curr->val;
        q.pop();
        if (curr->left)
        {
          q.push(curr->left);
          level_count++;
        }
        if (curr->right)
        {
          q.push(curr->right);
          level_count++;
        }
        count--;
      }
      if (max_sum < level_sum)
      {
        ans = level;
        max_sum = level_sum;
      }
      count = level_count;
      level++;
    }

    return ans;
  }
};