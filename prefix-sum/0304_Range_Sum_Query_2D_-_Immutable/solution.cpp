/*
304. Range Sum Query 2D - Immutable

Level: Medium

https://leetcode.com/problems/range-sum-query-2d-immutable

# 221. Maximal Square

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
  Solution: preprocessing
*/

class NumMatrix
{
private:
  vector<vector<int>> sums_;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    sums_.clear();

    if (matrix.empty())
      return;

    int m = matrix.size();
    int n = matrix[0].size();

    // sums_[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
    sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        sums_[i][j] = matrix[i - 1][j - 1] + sums_[i - 1][j] + sums_[i][j - 1] - sums_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] - sums_[row1][col2 + 1] + sums_[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */