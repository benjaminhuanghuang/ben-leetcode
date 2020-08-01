/*
529. Minesweeper

Level: Medium

https://leetcode.com/problems/minesweeper
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
  Solution: DFS
    Time complexity: O(m*n)
    Space complexity: O(m* n)

  未点开时状态为 M 或 E
  点开后 状态 为 M->X   E-> nubmer or B 
*/

class Solution
{
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
  {
    const int m = board.size();
    const int n = board[0].size();
    function<void(int, int)> dfs = [&](int x, int y) {
      if (board[y][x] != 'E')
        return;
      int c = 0; 
      for (int tx = x - 1; tx <= x + 1; ++tx)
        for (int ty = y - 1; ty <= y + 1; ++ty)
          if (tx >= 0 && tx < n && ty >= 0 && ty < m)
            c += board[ty][tx] == 'M';

      if (c > 0)
      {
        board[y][x] = '0' + c;
        return;
      }

      board[y][x] = 'B';

      for (int tx = x - 1; tx <= x + 1; ++tx)
        for (int ty = y - 1; ty <= y + 1; ++ty)
          if (tx >= 0 && tx < n && ty >= 0 && ty < m)
            dfs(tx, ty);
    };

    int x = click[1];
    int y = click[0];
    dfs(x, y);
    if (board[y][x] == 'M')
      board[y][x] = 'X';
    return board;
  }
};