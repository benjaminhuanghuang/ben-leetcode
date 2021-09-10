/*
1302. Deepest Leaves Sum

Level: Medium

https://leetcode.com/problems/deepest-leaves-sum
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
class Solution_DFS
{
public:
  int deepestLeavesSum(TreeNode *root)
  {
    int sum = 0;
    int max_depth = 0;


    function<void(TreeNode *, int)> dfs = [&](TreeNode *n, int d) {
      if (!n)
        return;
      if (d > max_depth)
      {
        max_depth = d;
        sum = 0;
      }
      if (d == max_depth)
        sum += n->val;
      dfs(n->left, d + 1);
      dfs(n->right, d + 1);
    };

    dfs(root, 0);
    return sum;
  }
};


class Solution_BFS {
public:
    int deepestLeavesSum(TreeNode* root) {
        // idea: level order traversal
        queue<TreeNode*> que({root});
        int levelSum = 0;
        while( !que.empty() ){
            levelSum = 0;
            int level_size = que.size();
            for(int i=0; i<level_size; i++){
                TreeNode* tmp = que.front(); que.pop();
                levelSum += tmp->val;
                if( tmp->left ) que.push(tmp->left);
                if( tmp->right ) que.push(tmp->right);
            }
        } return levelSum;
    }
};