/*
542. 01 Matrix

Level: Medium

https://leetcode.com/problems/01-matrix
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-542-01-matrix/
  Solution : BFS

    Start from all 0 cells and find shortest paths to rest of the cells.

    Time complexity: O(mn)

    Space complexity: O(mn)
*/

class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
  {
    const int m = matrix.size();
    const int n = matrix[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<int>> seen(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (matrix[i][j] == 0)
        {
          q.push({i, j});
          seen[i][j] = 1;
        }

    vector<int> dirs{0, -1, 0, 1, 0};
    int steps = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        auto pair = q.front();
        q.pop();
        int i = pair.first;
        int j = pair.second;
        ans[i][j] = steps;
        for (int k = 0; k < 4; ++k)
        {
          int x = j + dirs[k];
          int y = i + dirs[k + 1];
          if (x < 0 || x >= n || y < 0 || y >= m || seen[y][x])
            continue;
          seen[y][x] = 1;
          q.push({y, x});
        }
      }
      ++steps;
    }

    return ans;
  }
};