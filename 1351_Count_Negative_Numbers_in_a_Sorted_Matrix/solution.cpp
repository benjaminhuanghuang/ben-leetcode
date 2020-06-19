/*
1351. Count Negative Numbers in a Sorted Matrix

Level: Easy

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
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
  /*
    O(m*n)
  */
  int countNegatives(vector<vector<int>> &grid)
  {
    int ans = 0;
    for (auto row : grid)
    {
      for (auto num : row)
      {
        if (num < 0)
          ans++;
      }
    }
    return ans;
  }
  /*
    O(n+m) ; n: #rows, m: #columns
  */
  int countNegatives_v2(vector<vector<int>> &grid)
  {
    int rows = grid.size();    //#rows
    int cols = grid[0].size(); //#columns

    int row = 0;
    int col = cols - 1;

    int negativeNumbers = 0;

    while (row < rows && col >= 0)
    {
      if (grid[row][col] < 0)
      {
        negativeNumbers += (rows - 1) - row + 1; //negative elements below this row need to be included (taking current element into account)
        col--;                                   //go left since elements below current element will be negative (columns are sorted as non-increasing, top to bottom)
      }
      else
      {
        row++; //go down, since all elements to left of this positive element will be positive (rows are non-increasing, left to right)
      }
    }

    return negativeNumbers;
  }
};