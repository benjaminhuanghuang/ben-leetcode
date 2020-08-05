/*
662. Maximum Width of Binary Tree

https://leetcode.com/problems/maximum-width-of-binary-tree/
 */
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

#include "common/TreeNode.h"
/*
    对二叉树节点进行标号，根节点标号为0；若某节点标号为c，则其左右孩子标号分别为2c, 2c + 1
    某层的宽度即为最右、最左节点标号之差+1
     */
class Solution_Overflow
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    vector<int> lefts; // left most nodes at each level;
    return dfs(root, 1, 0, lefts);
  }

private:
  int dfs(TreeNode *n, int id, int d, vector<int> &lefts)
  { // d : depth
    if (!n)
      return 0;
    if (d >= lefts.size())
      lefts.push_back(id); // add left most node  signed integer overflow: 2147483647 * 2
    return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts), dfs(n->right, id * 2 + 1, d + 1, lefts)});
  }
};

class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    vector<int> node_store;
    return dfs(root, node_store, 0, 0);
  }

private:
  int dfs(TreeNode *root, vector<int> &node_store, unsigned long int index, int level)
  {
    if (root == nullptr)
      return 0;
    if (node_store.size() == level)
      node_store.push_back(index);
    int ans = 1;
    ans = max(ans, (int)(index - node_store[level] + 1));
    ans = max(ans, max(
                       dfs(root->left, node_store, 2 * index, level + 1),
                       dfs(root->right, node_store, 2 * index + 1, level + 1)));
    return ans;
  }
};

/*
https://www.cnblogs.com/grandyang/p/7538821.html
*/
class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;
    int res = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
      if (q.size() == 1)
        q.front().second = 1;
      int left = q.front().second, right = left, n = q.size();
      for (int i = 0; i < n; ++i)
      {
        auto t = q.front().first;
        right = q.front().second;
        q.pop();
        if (t->left)
          q.push({t->left, right * 2});
        if (t->right)
          q.push({t->right, right * 2 + 1});
      }
      res = max(res, right - left + 1);
    }
    return res;
  }
};