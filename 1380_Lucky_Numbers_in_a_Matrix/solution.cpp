/*
1380. Lucky Numbers in a Matrix

Level: Easy

https://leetcode.com/problems/lucky-numbers-in-a-matrix
*/
#include <vector>
#include <string>
#include <unordered_set>

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
  vector<int> luckyNumbers(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int minRow[rows];
    int maxCol[cols];
    std::fill(minRow, minRow + rows, INT_MAX);

    for (int row = 0; row < rows; ++row)
    {
      for (int col = 0; col < cols; ++col)
      {
        minRow[row] = min(matrix[row][col], minRow[row]);
        maxCol[col] = max(matrix[row][col], maxCol[col]);
      }
    }
    vector<int> lockyNums;
    for (int row = 0; row < rows; ++row)
    {
      for (int col = 0; col < cols; ++col)
      {
        if (minRow[row] == maxCol[col])
          lockyNums.push_back(minRow[row]);
      }
    }
    return lockyNums;
  }
};