//https://leetcode.com/problems/symmetric-tree/submissions/

#include "common/TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;

        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == nullptr && node2 == nullptr)
            return true;
        if(node1 == nullptr || node2 == nullptr)
            return false;

        return (node1->val == node2->val) && isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
};