/*
1557. Minimum Number of Vertices to Reach All Nodes

Level: Medium

https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
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
  有入度的点一定能从某个起点开始的路径覆盖到，所以这道题的答案就是所有入度为 0 的点。

  遍历所有的边和点一次，故时间复杂度为 O(n+m)
*/

class Solution
{
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    bool hasPredecessor[n];
    fill_n(hasPredecessor, n, false);
    for (auto dege : edges)
    {
      hasPredecessor[dege[1]] = true;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (!hasPredecessor[i])
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};