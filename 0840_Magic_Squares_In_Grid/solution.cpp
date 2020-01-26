/*
840. Magic Squares In Grid

https://leetcode.com/problems/magic-squares-in-grid/
*/

#include <vector>

using namespace std;

class Solution
{
public:
  int numMagicSquaresInside(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m - 2; ++i)
      for (int j = 0; j < n - 2; ++j)
        ans += magic(grid, j, i);
    return ans;
  }

private:
  int magic(const vector<vector<int>> &grid, int x, int y)
  {
    vector<int> rows(3);
    vector<int> cols(3);
    vector<int> exps{15, 15, 15};
    vector<int> cnt(10);
        
    int dig = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
      {
        int v = grid[y + i][x + j];
        if (v <= 0 || v > 9 || cnt[v])
          return 0; // must between 1 and 9
        rows[i] += v;
        cols[j] += v;
        cnt[v] = 1;
        if (i == j)
          dig += v;
      }
    return rows == exps && cols == exps && dig == 15;
  }
};