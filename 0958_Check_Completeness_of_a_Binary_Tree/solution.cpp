/*
958. Check Completeness of a Binary Tree

https://leetcode.com/problems/check-completeness-of-a-binary-tree/

判断一个二叉树是不是完全二叉树

 */
#include <queue>
using namespace std;

#include "common/TreeNode.h"
/*
Level order traversal, if any nodes appears after a missing node then the tree is not a perfect binary tree.

 */
class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode* > q;
    q.push(root);
    bool missing = false;
    while (!q.empty()) {
      auto size = q.size();      
      while (size--) {
        auto node = q.front(); q.pop();        
        if (node != nullptr) {
          if (missing) return false;
          q.push(node->left);
          q.push(node->right);
        } else {
          missing = true;
        }
      }      
    }
    return true;
  }
};