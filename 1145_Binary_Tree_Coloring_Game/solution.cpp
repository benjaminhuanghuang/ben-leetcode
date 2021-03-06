/*
1145. Binary Tree Coloring Game

Level: Medium

https://leetcode.com/problems/binary-tree-coloring-game
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  bool btreeGameWinningMove(TreeNode *root, int n, int x)
  {
    int red_left;
    int red_right;

    // get count of nodes
    function<int(TreeNode *)> count = [&](TreeNode *node) {
      if (!node)
        return 0;
      int l = count(node->left);
      int r = count(node->right);
      if (node->val == x)
      {
        red_left = l;
        red_right = r;
      }
      return 1 + l + r;
    };
    count(root);

    return max(max(red_left, red_right), n - red_left - red_right - 1) > n /2 ;
  }
};