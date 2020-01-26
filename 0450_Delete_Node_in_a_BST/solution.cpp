
/*
450. Delete Node in a BST
https://leetcode.com/problems/delete-node-in-a-bst/
*/

#include <vector>
#include <queue>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == nullptr)
      return root;
    if (key > root->val)
    {
      root->right = deleteNode(root->right, key);
    }
    else if (key < root->val)
    {
      root->left = deleteNode(root->left, key);
    }
    else
    {
      if (root->left != nullptr && root->right != nullptr)
      {
        TreeNode *min = root->right;
        while (min->left != nullptr)
          min = min->left;
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
      }
      else
      {
        TreeNode *new_root = root->left == nullptr ? root->right : root->left;
        root->left = root->right = nullptr;
        delete root;
        return new_root;
      }
    }
    return root;
  }
};
