/*
885. Spiral Matrix III

Level: Medium

https://leetcode.com/problems/spiral-matrix-iii
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
  The pattern is 1,1,2,2,3,3,4,4,... steps in one direction, and turn right for 90 degrees.

    directions are E,S,W,N,E,S,W,N…

    Time complexity: O(max(R,C)^2)
*/

class Solution
{
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0)
  {
    vector<vector<int>> ans;
    int k = 0;
    int dirs[][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // ESWN
    int d = 0;                                       // E
    
    ans.push_back({r0, c0});
    if (ans.size() == R * C)
      return ans;
    while (++k)
    {
      for (int i = 0; i < 2; ++i)
      {
        for (int j = 0; j < k; ++j)
        {
          c0 += dirs[d][0];
          r0 += dirs[d][1];
          if (c0 < 0 || c0 >= C || r0 < 0 || r0 >= R)
            continue;
          ans.push_back({r0, c0});
          if (ans.size() == R * C)
            return ans;
        }
        d = (d + 1) % 4;
      }
    }
    return {};
  }
};