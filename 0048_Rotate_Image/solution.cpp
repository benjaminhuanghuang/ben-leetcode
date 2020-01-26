/*
48. Rotate Image

https://leetcode.com/problems/rotate-image/


You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

*/
#include <vector>

using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int layerNum = n / 2;
    for (int layer = 0; layer < layerNum; layer++)
    {
      int start = layer;
      int end = n - 1 - layer;

      for (int i = start; i < end; i++)
      {
        int offset = i - start;
        int temp = matrix[start][i]; // back the up layer
        // left to up
        matrix[start][i] = matrix[end - offset][start];
        // bottom to left
        matrix[end - offset][start] = matrix[end][end - offset];
        // right to bottom
        matrix[end][end - offset] = matrix[i][end];
        // up to right
        matrix[i][end] = temp;
      }
    }
  }
};

class Solution2
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    // 沿着副对角线旋转, i, j 调换
    for (int row = 0; row < n; row++)
      for (int col = row; col < n; col++)
      {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
      }
    // 沿着中线左右调换
    for (int row = 0; row < n; row++)
      for (int col = 0; col < n / 2; col++)
      {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[row][n - 1 - col];
        matrix[row][n - 1 - col] = temp;
      }
  }
};