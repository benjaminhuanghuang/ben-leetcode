/*
919. Complete Binary Tree Inserter

https://leetcode.com/problems/complete-binary-tree-inserter/

CBTInserter.insert(int v) 将 TreeNode 插入到存在值为 node.val = v 的树中以使其保持完全二叉树的状态，
并返回插入的 TreeNode 的父结点的值；
 */
#include <queue>
using namespace std;

#include "common/TreeNode.h"

class CBTInserter
{
public:
  CBTInserter(TreeNode *root) : root_(root), d_({root}) {}

  int insert(int v)
  {
    while (!d_.empty())
    {
      TreeNode *r = d_.front();
      if (r->left && r->right)
      {
        d_.push_back(r->left);
        d_.push_back(r->right);
        d_.pop_front();
      }
      else if (r->left)
      {
        r->right = new TreeNode(v);
        return r->val;
      }
      else
      {
        r->left = new TreeNode(v);
        return r->val;
      }
    }
    return root_->val;
  }

  TreeNode *get_root() { return root_; }

private:
  std::deque<TreeNode *> d_;
  TreeNode *root_;
};