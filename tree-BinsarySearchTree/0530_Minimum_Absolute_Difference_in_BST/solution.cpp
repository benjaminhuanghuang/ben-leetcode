/*
530. Minimum Absolute Difference in BST

https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/
#include <climits>
#include <algorithm>
#include <vector>
#include "common/TreeNode.h"

using namespace std;
/*
O(h) space
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        min_diff_ = INT_MAX;
        prev_ = nullptr;
        inorder(root);
        return min_diff_;
    }
private:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev_) min_diff_ = min(min_diff_, root->val - *prev_);
        prev_ = &root->val;
        inorder(root->right);
    }
    
    int* prev_;
    int min_diff_;
};
/*
O(N) space
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> sorted;
        inorder(root, sorted);
        int min_diff = sorted.back();
        for (int i = 1; i < sorted.size(); ++i)
            min_diff = min(min_diff, sorted[i] - sorted[i - 1]);
        return min_diff;
    }
private:
    void inorder(TreeNode* root, std::vector<int>& sorted) {
        if (!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
};