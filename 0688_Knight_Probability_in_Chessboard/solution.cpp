/*
688. Knight Probability in Chessboard

Level: Medium

https://leetcode.com/problems/knight-probability-in-chessboard
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
*/

class Solution
{
public:
  double knightProbability(int N, int K, int r, int c)
  {
    vector<vector<double>> dp0(N, vector<double>(N, 0.0));
    dp0[r][c] = 1.0;
    int dirs[8][2] = {{1, 2}, {-1, -2}, {1, -2}, {-1, 2}, {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};
    for (int k = 0; k < K; ++k)
    {
      vector<vector<double>> dp1(N, vector<double>(N, 0.0));
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          for (int m = 0; m < 8; ++m)
          {
            int x = j + dirs[m][0];
            int y = i + dirs[m][1];
            if (x < 0 || y < 0 || x >= N || y >= N)
              continue;
            dp1[i][j] += dp0[y][x];
          }
      std::swap(dp0, dp1);
    }

    double total = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        total += dp0[i][j];

    return total / pow(8, K);
  }
};