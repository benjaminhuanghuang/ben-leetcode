/*
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 */


#include <vector>
#include <queue>
using namespace std;

#include "common/TreeNode.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        bool left2right = true;
        while(!q.empty())
        {
            int count = q.size();
            vector<int> layer;
            for(int i =0; i<count; i++) {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            if(!left2right)
            {
                reverse(layer.begin(), layer.end());
            }
            res.push_back(layer);
            left2right = !left2right;
        }

        return res;
    }
};