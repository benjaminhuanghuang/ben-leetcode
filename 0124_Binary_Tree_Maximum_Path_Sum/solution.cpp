/*
124. Binary Tree Maximum Path Sum

Level: Hard

https://leetcode.com/problems/binary-tree-maximum-path-sum
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
private:
  long res = LONG_MIN;

public:
    // 1 是左子树的路径加上当前节点，
    // 2 右子树的路径加上当前节点，
    // 3 左右子树的路径加上当前节点（相当于一条横跨当前节点的路径），
    // 4 只有自己的路径。
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return (int)res;
    }

    long maxPathSumHelper(TreeNode* root)
    {
        if (root == nullptr) 
            return 0;

        long left = maxPathSumHelper(root->left);
        long right = maxPathSumHelper(root->right);
        // case: 1,2,4
        long currSum = max(max(left, right) + root->val, (long)root->val);
        // case: 1,2,3,4
        res = max(res, max(currSum, left + right + root->val));
        return currSum;
    }
};