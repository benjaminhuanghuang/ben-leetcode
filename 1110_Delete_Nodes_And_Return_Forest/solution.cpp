/*
1110. Delete Nodes And Return Forest

Level: Medium

https://leetcode.com/problems/delete-nodes-and-return-forest
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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {
    vector<TreeNode *> ans;
    unordered_set<int> s{begin(to_delete), end(to_delete)};

    function<TreeNode *(TreeNode *)> del = [&](TreeNode *n) -> TreeNode * {
      if (!n)
        return nullptr;
      if (n->left)
        n->left = del(n->left);
      if (n->right)
        n->right = del(n->right);
        
      if (!s.count(n->val))
        return n;
      if (n->left)
        ans.push_back(n->left);
      if (n->right)
        ans.push_back(n->right);
      return nullptr;
    };

    TreeNode *r = del(root);
    if (r)
      ans.push_back(r);
    return ans;
  }
};