/*
1261. Find Elements in a Contaminated Binary Tree

Level: Medium

https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree
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
class FindElements
{
public:
  FindElements(TreeNode *root)
  {
    recover(root, 0);
  }

  bool find(int target)
  {
    return s_.count(target);
  }

private:
  unordered_set<int> s_;
  void recover(TreeNode *root, int val)
  {
    if (!root)
      return;
    root->val = val;
    s_.insert(val);
    recover(root->left, val * 2 + 1);
    recover(root->right, val * 2 + 2);
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */