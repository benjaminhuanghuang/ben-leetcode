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


class Solution
{
public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    return build(preorder, 0, preorder.size() -1);
  }

private:
  /*
    [start, end] 区间中包含了 root， left， right 3部分
  */
  TreeNode *build(vector<int> &preorder, int start, int end)
  {
    if (start > end)
      return nullptr;
    auto root = new TreeNode(preorder[start]);
    int  mid = start;  // mid 是第一个比start大的数
    while (mid <= end && preorder[mid] <= preorder[start])
      ++mid;
    root->left = build(preorder, start + 1, mid-1);
    root->right = build(preorder, mid, end);
    return root;
  }
};