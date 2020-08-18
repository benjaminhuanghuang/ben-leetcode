/*
1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

Level: Hard

https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix
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
  Solution:  BFS Search 
  https://zxi.mytechroad.com/blog/searching/leetcode-1284-minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

*/

class Solution
{
public:
  int minFlips(vector<vector<int>> &mat)
  {
    const int m = mat.size();
    const int n = mat[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0, 0};

    auto flip = [&](int s, int x, int y) {
      for (int i = 0; i < 5; ++i)
      {
        const int tx = x + dirs[i];
        const int ty = y + dirs[i + 1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m)
          continue;
        s ^= (1 << ty * n + tx);
      }
      return s;
    };

    int steps = 0;
    queue<int> q;
    vector<int> seen(1 << (n * m));
    int start = 0;
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        start |= (mat[y][x] << (y * n + x));
    q.push(start);
    seen[start] = 1;

    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int s = q.front();
        if (s == 0)
          return steps;
        q.pop();
        for (int y = 0; y < m; ++y)
          for (int x = 0; x < n; ++x)
          {
            int t = flip(s, x, y);
            if (seen[t])
              continue;
            seen[t] = 1;
            q.push(t);
          }
      }
      ++steps;
    }
    return -1;
  }
};