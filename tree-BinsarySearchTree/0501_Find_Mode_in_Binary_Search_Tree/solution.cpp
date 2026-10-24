/*
501. Find Mode in Binary Search Tree
https://leetcode.com/problems/find-mode-in-binary-search-tree/
 */
#include <vector>
using namespace std;

#include "common/TreeNode.h"
/*
https://zxi.mytechroad.com/blog/tree/leetcode-501-find-mode-in-binary-search-tree/
 */
class Solution
{
public:
  vector<int> findMode(TreeNode *root)
  {
    inorder(root);
    mode_count_ = max_count_;
    count_ = 0;
    inorder(root);
    return ans_;
  }

private:
  int val_ = 0;
  int count_ = 0;
  int mode_count_ = INT_MAX;
  int max_count_ = 0;
  vector<int> ans_;

  void inorder(TreeNode *root)
  {
    if (root == nullptr)
      return;
    inorder(root->left);
    visit(root->val);
    inorder(root->right);
  }

  void visit(int val)
  {
    if (count_ > 0 && val == val_)
    {
      ++count_;
    }
    else
    {
      val_ = val;
      count_ = 1;
    }

    if (count_ > max_count_)
      max_count_ = count_;

    if (count_ == mode_count_)
      ans_.push_back(val);
  }
};