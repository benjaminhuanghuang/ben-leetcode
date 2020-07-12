/*
36. Valid Sudoku

Level: Medium

https://leetcode.com/problems/valid-sudoku

- 37. Sudoku Solver
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

class Solution2
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    //  记录 某行, 某列，某block是否包含某个数字
    int row[9][9] = {0};
    int col[9][9] = {0};
    int square[9][9] = {0};   // block index: (y/3)*3 + x/3

    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] == '.')
        {
          continue;
        }
        int num = board[i][j] - '0' - 1; // index 从 0 开始
        int k = (i / 3) * 3 + (j / 3);   // index of block

        if (row[i][num] || col[j][num] || square[k][num])
        {
          return false;
        }
        row[i][num] = col[j][num] = square[k][num] = 1;
      }
    }
    return true;
  }
};

/*
  Solution: 
  Hua Hua
  https://zxi.mytechroad.com/blog/hashtable/leetcode-36-valid-sudoku/

  Solution: HashTable
  Use set to store the numbers of each row, column and each 3×3 box. 
  set() can be used to check duplicated element.
  
  Time complexity: O(1)
  Space complexity: O(1)
*/

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; i++)
    {
      unordered_set<char> r, c;
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j] != '.' && !r.insert(board[i][j]).second)
          return false;
        if (board[j][i] != '.' && !c.insert(board[j][i]).second)
          return false;
      }
    }
    // check the 9 blocks
    for (int p = 0; p < 3; p++)
      for (int q = 0; q < 3; q++)
      {
        unordered_set<char> b;
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++)
          {
            int x = p * 3 + i;
            int y = q * 3 + j;
            if (board[y][x] != '.' && !b.insert(board[y][x]).second)
              return false;
          }
      }
    return true;
  }
};
