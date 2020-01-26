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

/*
https://www.youtube.com/watch?v=sm4UdCO2868
 */