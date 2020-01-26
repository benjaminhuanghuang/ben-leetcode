/*
74. Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    if (matrix.empty())
      return false;

    
    int l = 0;
    int r = matrix.size() * matrix[0].size()-1;
    const int cols = matrix[0].size();
    while (l <= r)
    {
      const int m = l + (r - l) / 2;
      if (matrix[m / cols][m % cols] == target)
      {
        return true;
      }
      else if (matrix[m / cols][m % cols] > target)
      {
        r = m - 1;
      }
      else
      {
        l = m + 1;
      }
    }
    return false;
  }
};