/*
120. Triangle [Medium]

https://leetcode.com/problems/triangle/
*/
#include <vector>
#include <algorithm>

using namespace std;

/*
Solution:

Time complexity: O(n^2)

Space complexity: O(1)

  [[2]                 [[2]
   [3, 4]]              [5, 6]
   [6, 5, 7]]           [11, 10, 11]
   [4, 1, 8, 3]]        [15, 11, 18, 14]]

*/
class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int height = triangle.size();
    if (height == 0)
      return 0;

    vector<int> tempRow = triangle[height - 1];

    for (int i = height - 2; i >= 0; i--)
    {
      auto tempRowCopy = tempRow;

      for (int j = 0; j <= i; j++)
        tempRow[j] = triangle[i][j] + min(tempRowCopy[j], tempRowCopy[j + 1]);
    }
    return tempRow[0];
  }

  int minimumTotal_huahua(vector<vector<int>> &t)
  {
    int n = t.size();

    // t[i][j] := minTotalOf(i,j)
    // t[i][j] += min(t[i - 1][j], t[i - 1][j - 1])

    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j)
      {
        if (i == 0 && j == 0)
          continue;
        if (j == 0)
          t[i][j] += t[i - 1][j];
        else if (j == i)
          t[i][j] += t[i - 1][j - 1];
        else
          t[i][j] += min(t[i - 1][j], t[i - 1][j - 1]);
      }

    return *std::min_element(begin(t.back()), end(t.back()));
  }
};