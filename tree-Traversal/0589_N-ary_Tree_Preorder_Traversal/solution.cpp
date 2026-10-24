/*
589. N-ary Tree Preorder Traversal
https://leetcode.com/problems/n-ary-tree-preorder-traversal/
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
  vector<int> preorder(Node *root)
  {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }

private:
  void helper(Node *root, vector<int> &ans)
  {
    if(root == nullptr)
      return;

    ans.push_back(root->val);
    for(Node *node: root->children){
      helper(node, ans);
    }
  }
};