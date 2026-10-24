/*
114. Flatten Binary Tree to Linked List

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 */

#include <vector>
using namespace std;
#include "common/TreeNode.h"
/*
each node’s right child points to the next node of a pre-order traversal.
每一个节点的右孩子都是其先序遍历的下一个节点。

 */

class Solution
{
public:
  void flatten(TreeNode *root)
  {
    vector<TreeNode*> nodes;
    preOrder(root, nodes);

    TreeNode* start = root;
    for (int i = 1; i < nodes.size(); i++)
    {
      start->right = nodes[i];
      start->left = nullptr;

      start = start->right;
    }
  }

private:
  void preOrder(TreeNode* root, vector<TreeNode*> &nodes)
  {
    if (root == nullptr)
      return;
    // visited root
    nodes.push_back(root);

    preOrder(root->left, nodes);
    preOrder(root->right, nodes);
  }
};