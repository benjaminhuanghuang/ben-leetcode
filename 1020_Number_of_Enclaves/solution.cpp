/*
1020. Number of Enclaves

Level: Medium

https://leetcode.com/problems/number-of-enclaves
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
  Solution: DFS + Connected Components

  0 (representing sea) or 1 (representing land)
*/

class Solution
{
public:
  int numEnclaves(vector<vector<int>> &A)
  {
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j < A[0].size(); ++j)
      {
        int count = 0;
        if (!dfs(A, j, i, count))
          ans += count;
      }
    return ans;
  }

private:
  static constexpr int dirs[5]{0, -1, 0, 1, 0};
  bool dfs(vector<vector<int>> &A, int x, int y, int &count)
  {
    if (x < 0 || x == A[0].size() || y < 0 || y == A.size())
      return true;
    if (A[y][x] == 0)
      return false;
    ++count;
    A[y][x] = 0;
    bool valid = false;
    for (int i = 0; i < 4; ++i)
      valid |= dfs(A, x + dirs[i], y + dirs[i + 1], count);
    return valid;
  }
};