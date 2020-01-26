/*
144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Follow up: Recursive solution is trivial, could you do it iteratively?
 */
#include <vector>
#include <stack>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    preorderTrav(root, ans);
    return ans;
  }

private:
  void preorderTrav(TreeNode *root, vector<int> &ans)
  {
    if (!root)
      return;
    ans.push_back(root->val);
    preorderTrav(root->left, ans);
    preorderTrav(root->right, ans);
  }
};

class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
     if (!root)
      return ans;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
      TreeNode *n = s.top();
      s.pop();
      ans.push_back(n->val);

      // right, then left
      if (n->right != nullptr)
      {
        s.push(n->right);
      }
      if (n->left != nullptr)
      {
        s.push(n->left);
      }
    }

    return ans;
  }
};