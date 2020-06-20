/*
1252. Cells with Odd Values in a Matrix

Level: Easy

https://leetcode.com/problems/cells-with-odd-values-in-a-matrix
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
  int oddCells(int n, int m, vector<vector<int>> &indices)
  {
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (auto rc : indices)
    {
      for (int col = 0; col < m; col++)
      {
        matrix[rc[0]][col]++;
      }
      for (int row = 0; row < n; row++)
      {
        matrix[row][rc[1]]++;
      }
    }

    int count = 0;
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (matrix[row][col] & 1)
        {
          count++;
        }
      }
    }
    return count;
  }
};