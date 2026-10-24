/*
652. Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/
 */
#include <vector>
#include <unordered_map>
using namespace std;

#include "common/TreeNode.h"

class Solution
{
public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    unordered_map<long, pair<int, int>> counts;
    vector<TreeNode *> ans;
    getId(root, counts, ans);
    return ans;
  }

private:
  int getId(TreeNode *root,
            unordered_map<long, pair<int, int>> &counts,
            vector<TreeNode *> &ans)
  {
    if (!root)
      return 0;
    long key = (static_cast<long>(static_cast<unsigned>(root->val)) << 32) +
               (getId(root->left, counts, ans) << 16) +
               getId(root->right, counts, ans);
    auto &p = counts[key];
    if (p.second++ == 0)
      p.first = counts.size();
    else if (p.second == 2)
      ans.push_back(root);
    return p.first;
  }
};

/*
https://www.youtube.com/watch?v=LYU3y0-59_k FLAG高频精选面试题讲解
 */