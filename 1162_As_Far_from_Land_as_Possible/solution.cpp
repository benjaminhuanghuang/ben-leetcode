/*
1162. As Far from Land as Possible

Level: Medium

https://leetcode.com/problems/as-far-from-land-as-possible
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
   BFS
    Put all land cells into a queue as source nodes and BFS for water cells, the last expanded one will be the farthest.
    
    Time compleixty: O(n^2)
    Space complexity: O(n^2)

    把所有的 land cell 放入一个队列
    把land cell 向外扩展一圈， 被波及的cell 标记为 2，同时把被波及的cell放入队列，扩展一圈，step++
    如果queue中还有cell，就说明还可以继续扩展
    

*/

class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    const int n = grid.size();
    const int m = grid[0].size();
    queue<pair<int, int>> q;
    // Put all land cells into a queue
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1)
          q.push({i, j}); // land

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int steps = 0;
    while (q.size())
    {
      int size = q.size();
      while (size--)
      {
        auto p = q.front();
        q.pop();
        int x = p.second;
        int y = p.first;
        for (auto d : dirs)
        {
          int tx = x + d.first;
          int ty = y + d.second;
          if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0)
            continue;
          grid[ty][tx] = 2;
          q.push({ty, tx});
        }
      }
      ++steps;
    }
    return steps == 1 ? -1 : steps - 1;
  }
};