/*
987. Vertical Order Traversal of a Binary Tree

Level: Medium

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    map<pair<int, int>, set<int>> h; // {y, x} -> {vals}
    traverse(root, 0, 0, h, min_x, max_x);
    vector<vector<int>> ans(max_x - min_x + 1);
    for (const auto& m : h) {      
      int x = m.first.second - min_x;
      ans[x].insert(end(ans[x]), begin(m.second), end(m.second));
    }
    return ans;
  }
private:
  void traverse(TreeNode* root, int x, int y, 
                map<pair<int, int>, set<int>>& h,
                int& min_x,
                int& max_x) {
    if (!root) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);    
    h[{y, x}].insert(root->val);
    traverse(root->left, x - 1, y + 1, h, min_x, max_x);
    traverse(root->right, x + 1, y + 1, h, min_x, max_x);
  }
};