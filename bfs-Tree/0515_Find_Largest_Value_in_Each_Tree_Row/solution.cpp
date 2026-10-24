/*
515. Find Largest Value in Each Tree Row

https://leetcode.com/problems/find-largest-value-in-each-tree-row/
*/

#include <vector>
using namespace std;

#include "common/TreeNode.h"
/* 
    Using row index
 */
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    inorder(root, 0, ans);
    return ans;
  }
private:
  void inorder(TreeNode* root, int row, vector<int>& ans) {
    if (root == nullptr) return;
    while (ans.size() <= row) 
        ans.push_back(INT_MIN);    
    inorder(root->left, row + 1, ans);
    ans[row] = max(ans[row], root->val);
    inorder(root->right, row + 1, ans);
  }
};