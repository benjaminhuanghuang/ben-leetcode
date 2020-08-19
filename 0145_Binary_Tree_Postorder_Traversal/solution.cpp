/*
145. Binary Tree Postorder Traversal

Level: Hard

https://leetcode.com/problems/binary-tree-postorder-traversal
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;        
        postorderTraversal(root, ans);
        return ans;
    }
    
    void postorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
};

/*
  Use deque
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        deque<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            ans.push_front(n->val); // O(1)
            if (n->left) s.push(n->left);
            if (n->right) s.push(n->right);
        }   
        return vector<int>(ans.begin(), ans.end());
    }
};