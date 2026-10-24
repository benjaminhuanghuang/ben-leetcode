/*
590. N-ary Tree Postorder Traversal
https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 */
#include <vector>

using namespace std;
class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<int> postorder(Node *root)
  {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }

private:
  void helper(Node *root, vector<int> &ans)
  {
    if (root == nullptr)
      return;

    for (Node *node : root->children)
    {
      helper(node, ans);
    }
    ans.push_back(root->val);
  }
};