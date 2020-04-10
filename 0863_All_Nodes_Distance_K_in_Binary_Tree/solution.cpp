/*
863. All Nodes Distance K in Binary Tree

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#include "common/TreeNode.h"

/*
https://zxi.mytechroad.com/blog/searching/leetcode-863-all-nodes-distance-k-in-binary-tree/
https://www.youtube.com/watch?v=o1siL8eKCos

Solution1 : Graph + BFS
Time complexity: O(n)
Space complexity: O(n)

Solution1 : Recursion
Time complexity: O(n)
Space complexity: O(n)

 */
class Solution
{
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
  {
    buildGraph(nullptr, root);
    vector<int> ans;
    unordered_set<TreeNode *> seen;
    queue<TreeNode *> q;
    seen.insert(target);
    q.push(target);
    int k = 0;
    while (!q.empty() && k <= K)
    {
      int s = q.size();
      while (s--)
      {
        TreeNode *node = q.front();
        q.pop();
        if (k == K)
          ans.push_back(node->val);
        for (TreeNode *child : g[node])
        {
          if (seen.count(child))
            continue;
          q.push(child);
          seen.insert(child);
        }
      }
      ++k;
    }
    return ans;
  }

private:
  unordered_map<TreeNode *, vector<TreeNode *>> g;

  void buildGraph(TreeNode *parent, TreeNode *child)
  {
    if (parent)
    {
      g[parent].push_back(child);
      g[child].push_back(parent);
    }
    if (child->left)
      buildGraph(child, child->left);
    if (child->right)
      buildGraph(child, child->right);
  }
};