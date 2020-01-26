/*
606. Construct String from Binary Tree

https://leetcode.com/problems/construct-string-from-binary-tree/

You need to construct a string consists of parenthesis and integers from a binary tree 
with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". 
And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping 
relationship between the string and the original binary tree.
*/

#include <string>
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  string tree2str(TreeNode *t)
  {
    if (t == nullptr)
      return "";

    const string s = std::to_string(t->val);
    // case 0: s
    if (!t->left && !t->right)
      return s;
    // case 1: s(l)
    if (!t->right)
      return s + "(" + tree2str(t->left) + ")";
    // general: s(l)(r)
    return s + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
  }
};