/*
94. Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/
 */

#include <vector>
#include <stack>

using namespace std;

#include "common/TreeNode.h"
/*
Time complexity: O(n)
Space complexity: O(h)
 */
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    inorderTraversal(root, ans);
    return ans;
  }

private:
  void inorderTraversal(TreeNode *root, vector<int> &ans)
  {
    if (root == nullptr)
      return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
  }
};

/*

Iterative, using stack

 */
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    if (root == nullptr)
      return {};
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
      while (curr != nullptr)
      {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top();
      s.pop();
      ans.push_back(curr->val);
      curr = curr->right;
    }
    return ans;
  }
};
