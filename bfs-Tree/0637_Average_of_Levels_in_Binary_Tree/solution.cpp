/*
637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/
 */
#include <vector>
#include <queue>
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
         if(root == nullptr) return {};
        vector<double> ans;
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        
        // process every level one by one
        while(!curr.empty()) {
            long long sum = 0;
            for(const auto& node : curr) {
                sum += node->val;
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            
            ans.push_back(static_cast<double>(sum) / curr.size());
            
            curr.swap(next);
            next.clear();
        }
        
        return ans;
    }
};