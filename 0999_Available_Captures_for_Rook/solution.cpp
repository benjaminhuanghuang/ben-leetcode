/*
999. Available Captures for Rook

https://leetcode.com/problems/available-captures-for-rook/
*/
#include <vector>
#include <array>

using namespace std;
class Solution
{
public:
  int numRookCaptures(vector<vector<char>> &board)
  {
    int ans = 0;
    auto check = [&board](int x, int y, int dx, int dy) {
      x += dx;
      y += dy;
      while (x >= 0 && x < 8 && y >= 0 && y < 8)
      {
        if (board[y][x] == 'p')
          return 1;
        if (board[y][x] != '.')
          break;
        x += dx;
        y += dy;
      }
      return 0;
    };

    array<int, 5> dirs{1, 0, -1, 0, 1};
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (board[i][j] == 'R')
          for (int d = 0; d < 4; ++d)
            ans += check(j, i, dirs[d], dirs[d + 1]);
    return ans;
  }
};