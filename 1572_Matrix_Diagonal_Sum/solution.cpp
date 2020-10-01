/*
1572. Matrix Diagonal Sum

Level: Easy

https://leetcode.com/problems/matrix-diagonal-sum
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Time complexity: O(n)
  Space complexity: O(1)

  be careful not to double count the center one.
*/
class Solution_Wrong
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    const int rows = mat.size();
    int ans = 0;
    for (int row = 0; row < rows; ++row)
      ans += mat[row][row] + mat[row][rows -1 - row];


    if (rows & 1)
      ans -= mat[rows / 2][rows / 2];
    return ans;
  }
};

/*
  Solution: 
  if n is odd, be careful not to double count the center one.
*/

class Solution_Wrong
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    int sum = 0;
    for (int row = 0; row < mat.size(); row++)
    {
      for (int col = 0; col < mat[0].size(); col++)
      {
        if (row == col)
        {
          sum += mat[row][col];
        }
      }
    }

    for (int row = 0; row < mat.size(); row++)
    {
      for (int col = mat[0].size() - 1; col >= 0; col--)
      {
        if (row == mat[0].size() - 1 - col)
        {
          sum += mat[row][col];
        }
      }
    }
    return sum;
  }
};