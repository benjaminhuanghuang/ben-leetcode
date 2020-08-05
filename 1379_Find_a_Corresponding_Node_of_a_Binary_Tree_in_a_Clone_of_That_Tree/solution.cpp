/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Level: Medium

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
  Solution: 
  Travel two trees at same time
*/


class Solution
{
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
  {
    if (!original)
      return nullptr;
    if (original == target)
      return cloned;
    auto l = getTargetCopy(original->left, cloned->left, target);
    auto r = getTargetCopy(original->right, cloned->right, target);
    return l ? l : r;
  }
};