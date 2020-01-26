/*
1008. Construct Binary Search Tree from Preorder Traversal [Medium]

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    return build(begin(preorder), end(preorder));
  }

private:
  typedef vector<int>::const_iterator IT;
  TreeNode *build(IT s, IT e)
  {
    if (s >= e)
      return nullptr;
    auto root = new TreeNode(*s);
    IT m = s;
    while (m < e && *m <= *s)
      ++m;
    root->left = build(s + 1, m);
    root->right = build(m, e);
    return root;
  }
};