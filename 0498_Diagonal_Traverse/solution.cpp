/*
498. Diagonal Traverse

Level: Medium

https://leetcode.com/problems/diagonal-traverse
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
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
  {
    if (matrix.size() == 0)
      return {};

    int row = 0,
        col = 0,
        rows = matrix.size(),
        cols = matrix[0].size();
    vector<int> res;

    for (int k = 0; k < cols * rows; k++)
    {
      res.push_back(matrix[row][col]);
      if ((row + col) % 2 == 0)
      {
        // goes up
        if (col == cols - 1)
        {
          row++;
        }
        else if (row == 0)
        {
          col++;
        }
        else
        {
          row--;
          col++;
        }
      }
      else
      {
        //goes down
        if (row == rows - 1)
        {
          col++;
        }
        else if (col == 0)
        {
          row++;
        }
        else
        {
          row++;
          col--;
        }
      }
    }
    return res;
  }
};