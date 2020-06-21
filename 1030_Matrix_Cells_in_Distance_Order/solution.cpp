/*
  1030. Matrix Cells in Distance Order

  https://leetcode.com/problems/matrix-cells-in-distance-order/

*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
  {
    vector<vector<int>> ans;
    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        ans.push_back({i, j});
      }
    }
    // sort by |r1 - r2| + |c1 - c2|
    // cmp 
    sort(begin(ans), end(ans), [r0, c0](const auto &a, const auto &b) {
      return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
    });
    return ans;
  }
};