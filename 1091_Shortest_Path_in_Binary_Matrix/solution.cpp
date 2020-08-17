/*
1091. Shortest Path in Binary Matrix

Level: Medium

https://leetcode.com/problems/shortest-path-in-binary-matrix
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
  Solution: BFS

    从( 0， 0 )点开始进行bfs
    将点放入queue中后，将对应的grid上的值置为1
*/

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1])
      return -1;
    int goal = -1;

    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 1});
    grid[0][0] = 1;

    while (!q.empty())
    {
      auto now = q.front();
      q.pop();
      int x = now.first.first;
      int y = now.first.second;
      int val = now.second;

      if (x == n - 1 && y == n - 1)
      {
        goal = val;
        break;
      }

      for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
          if (i == 0 && j == 0)
            continue;
          int nx = x + i;
          int ny = y + j;
          if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny])
            continue;
          q.push({{nx, ny}, val + 1});
          grid[nx][ny] = 1;
        }
    }
    return goal;
  }
};