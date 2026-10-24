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