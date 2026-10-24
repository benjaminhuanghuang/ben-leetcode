/*
1305. All Elements in Two Binary Search Trees

Level: Medium

https://leetcode.com/problems/all-elements-in-two-binary-search-trees
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

/*
  Solution: Put data to array and sort 

  Time complexity: O(NLogN)
  Space complexity: O(N)

*/


/*
  Solution: Inorder traversal get sorted array + Merge Sort

  Time complexity: O(t1 + t2)
  Space complexity: O(t1 + t2)
*/
class Solution
{
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
  {
    function<void(TreeNode *, vector<int> &)> inorder = [&](TreeNode *root, vector<int> &t) {
      if (!root)
        return;
      inorder(root->left, t);
      t.push_back(root->val);
      inorder(root->right, t);
    };


    vector<int> t1;
    vector<int> t2;
    inorder(root1, t1);
    inorder(root2, t2);

    vector<int> all;
    int i = 0;
    int j = 0;
    while (all.size() != t1.size() + t2.size())
    {
      if (j == t2.size())
        all.push_back(t1[i++]);
      else if (i == t1.size())
        all.push_back(t2[j++]);
      else
        all.push_back(t1[i] < t2[j] ? t1[i++] : t2[j++]);
    }
    return all;
  }
};