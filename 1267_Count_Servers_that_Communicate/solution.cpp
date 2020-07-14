/*
1267. Count Servers that Communicate

Level: Medium

https://leetcode.com/problems/count-servers-that-communicate
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
  Two passes:
  First pass, count number of computers for each row and each column.
  Second pass, count grid[i][j] if rows[i] or cols[j] has more than 1 computer.

  Time complexity: O(m*n)
  Space complexity: O(m + n)
*/

class Solution
{
public:
  int countServers(vector<vector<int>> &grid)
  {
    const size_t m = grid.size();
    const size_t n = grid[0].size();
    vector<int> rows(m);
    vector<int> cols(n);
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j)
      {
        rows[i] += grid[i][j];
        cols[j] += grid[i][j];
      }
    int ans = 0;
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j)
        ans += (rows[i] > 1 || cols[j] > 1) ? grid[i][j] : 0;
    return ans;
  }
};