/*
113. Path Sum II

https://leetcode.com/problems/path-sum-ii/
 */
#include <vector>
#include <queue>
using namespace std;

#include "common/TreeNode.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        pathSum(root, sum, curr, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr) {
            if(root->val == sum) {
                ans.push_back(curr);
                ans.back().push_back(root->val);
            }
            return;
        }
        
        curr.push_back(root->val);
        int new_sum = sum - root->val;
        pathSum(root->left, new_sum, curr, ans);
        pathSum(root->right, new_sum, curr, ans);
        curr.pop_back();
    }
};