/*
894. All Possible Full Binary Trees
https://leetcode.com/problems/all-possible-full-binary-trees/
 */
#include <vector>
using namespace std;

#include "common/TreeNode.h"

/*
https://zxi.mytechroad.com/blog/tree/leetcode-894-all-possible-full-binary-trees/
 */
class Solution
{
public:
  vector<TreeNode *> allPossibleFBT(int N)
  {
    if (N % 2 == 0)
      return {};
    if (N == 1)
      return {new TreeNode(0)};
    vector<TreeNode *> ans;
    for (int i = 1; i < N; i += 2)
    {
      for (const auto &l : allPossibleFBT(i))
        for (const auto &r : allPossibleFBT(N - i - 1))
        {
          auto root = new TreeNode(0);
          root->left = l;
          root->right = r;
          ans.push_back(root);
        }
    }
    return ans;
  }
};