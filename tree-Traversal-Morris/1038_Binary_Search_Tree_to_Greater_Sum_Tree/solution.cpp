/*
1038. Binary Search Tree to Greater Sum Tree

https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/
#include <functional>
#include "common/TreeNode.h"

using namespace std;

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-135-1037-1038-1039-1040/

Solution: Recursion: right, root, left

Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
  TreeNode *bstToGst(TreeNode *root)
  {
    int s = 0;
    function<void(TreeNode *)> dfs = [&](TreeNode *n) {
      if (!n)
        return;
      dfs(n->right);
      n->val = s += n->val;
      dfs(n->left);
    };

    dfs(root);
    return root;
  }
};

class Solution2
{
public:
  TreeNode *bstToGst(TreeNode *root)
  {
    int s = 0;
    dfs(root);
    return root;
  }

private:
  int s;
  void dfs(TreeNode *n)
  {
    if (n == nullptr)
      return;
    dfs(n->right);
    s += n->val;
    n->val = s;
    dfs(n->left);
  };
};