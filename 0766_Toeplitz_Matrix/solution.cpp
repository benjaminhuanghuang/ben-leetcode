/*
867. Transpose Matrix

https://leetcode.com/problems/toeplitz-matrix/
*/

#include <vector>
using namespace std;

class Solution
{
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix)
  {
    if (matrix.empty())
      return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 1; row < rows; row++)
    {
      for (int col = 1; col < cols; col++)
      {
        if (matrix[row][col] != matrix[row - 1][col - 1])
          return false;
      }
    }
    return true;
  }
};