/*
463. Island Perimeter

Level: Easy

https://leetcode.com/problems/island-perimeter
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  列举可以贡献边长的block
*/

class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int ans = 0;
    for (int r = 0; r < grid.size(); r++)
    {
      for (int c = 0; c < grid[0].size(); c++)
      {
        if (grid[r][c] == 1)
        {
          if (r == 0 || (r > 0 && grid[r - 1][c] == 0))
            ans++;
          if (r == grid.size() - 1 || (r < grid.size() - 1 && grid[r + 1][c] == 0))
            ans++;
          if (c == 0 || (c > 0 && grid[r][c - 1] == 0))
            ans++;
          if (c == grid[0].size() - 1 || (c < grid[0].size() - 1 && grid[r][c + 1] == 0))
            ans++;
        }
      }
    }
    return ans;
  }
};