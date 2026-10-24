/*
993. Cousins in Binary Tree

https://leetcode.com/problems/cousins-in-binary-tree/
*/
#include <vector>
#include <queue>
#include "common/TreeNode.h"

class Solution {
public:
  bool isCousins(TreeNode* root, int x, int y) {    
    preorder(root, x, y, nullptr, 0);
    return px_ != py_ && dx_ == dy_;
  }
private:
  TreeNode* px_;
  TreeNode* py_;
  int dx_;
  int dy_;
  
  void preorder(TreeNode* root, int x, int y, TreeNode* p, int d) {
    if (!root) return;
    if (root->val == x) {
      px_ = p;
      dx_ = d;
    }
    if (root->val == y) {
      py_ = p;
      dy_ = d;
    }
    preorder(root->left, x, y, root, d + 1);
    preorder(root->right, x, y, root, d + 1);
  }
};

