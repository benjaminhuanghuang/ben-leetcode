/*
807. Max Increase to Keep City Skyline

Level: Medium

https://leetcode.com/problems/max-increase-to-keep-city-skyline
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
  首先需要求出各行各列的最大值，成为一个限制高度，
*/

class Solution
{
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size(), res = 0;
    // 首先需要求出各行各列的最大值，成为一个限制高度，
    vector<int> row(m, 0), col(n, 0);
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
      }
    }
    
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        res += min(row[i] - grid[i][j], col[j] - grid[i][j]);
      }
    }
    return res;
  }
};