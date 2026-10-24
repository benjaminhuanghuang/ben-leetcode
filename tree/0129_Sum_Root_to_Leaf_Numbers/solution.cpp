/*
129. Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/
 */
#include "common/TreeNode.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

  private:
  int helper(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr)
            return root->val + sum*10;
        sum = root->val + sum*10;
        return helper(root->left, sum) + helper(root->right, sum);
    }
};