/*
222. Count Complete Tree Nodes

Level: Medium

https://leetcode.com/problems/count-complete-tree-nodes
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
  int countNodes(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

class Solution_2
{
public:
  int count = 0;
  void find(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    count++;
    find(root->left);
    find(root->right);
  }
  int countNodes(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    find(root);
    return count;
  }
};