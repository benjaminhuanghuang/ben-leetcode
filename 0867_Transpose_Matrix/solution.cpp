/*
867. Transpose Matrix

https://leetcode.com/problems/transpose-matrix/

Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and 
column indices of the matrix.
Input: [[1,2,3],
        [4,5,6],
        [7,8,9]]
Output: [[1,4,7],
         [2,5,8],
         [3,6,9]]
*/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &A)
  {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> ans(cols, vector<int>(rows));
    for (int r = 0; r < rows; ++r)
      for (int c = 0; c < cols; ++c)
        ans[c][r] = A[r][c];
    return ans;
  }
};
