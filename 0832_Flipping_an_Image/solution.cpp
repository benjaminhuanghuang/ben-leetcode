/*
832. Flipping an Image
https://leetcode.com/problems/flipping-an-image/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
  {
    int rows = A.size();
    int cols = A[0].size();

    for (int r = 0; r < rows; r++)
    {
      int c1 = 0;
      int c2 = cols - 1;
      while (c1 <= c2)
      {
        int tmp = A[r][c1];
        A[r][c1] = A[r][c2] ^ 1;
        A[r][c2] = tmp ^ 1;
        c1++;
        c2--;
      }
    }
    return A;
  }
};
/*
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-832-flipping-an-image/
*/
class Solution
{
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
  {
    auto B = A;
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        B[i][j] = 1 - A[i][n - j - 1];
    return B;
  }
};
