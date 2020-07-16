/*
130. Surrounded Regions

Level: Medium

https://leetcode.com/problems/surrounded-regions
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
  Space complexity: O(m*n)
*/

class Solution
{
private:
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  void dfs(vector<vector<char>> &board, int rows, int cols, int row, int col)
  {
    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O')
      return;
    board[row][col] = 'G'; // mark it as good if it is 'O'
    for (auto dir : dirs)
    {
      dfs(board, rows, cols, row + dir.first, col + dir.second);
    }
  }

public:
  void solve(vector<vector<char>> &board)
  {
    const int rows = board.size();
    if (rows == 0)
      return;
    const int cols = board[0].size();

    for (int y = 0; y < rows; ++y)
    {
      dfs(board, rows, cols, y, 0);
      dfs(board, rows, cols, y, cols - 1);
    }

    for (int x = 0; x < cols; ++x)
    {
      dfs(board, rows, cols, 0, x);
      dfs(board, rows, cols, rows-1, x);
    }

    unordered_map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};
    for (int y = 0; y < rows; ++y)
      for (int x = 0; x < cols; ++x)
        board[y][x] = v[board[y][x]];
  }
};