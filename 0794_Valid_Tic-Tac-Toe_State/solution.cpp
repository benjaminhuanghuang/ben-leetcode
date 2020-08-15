/*
794. Valid Tic-Tac-Toe State

Level: Medium

https://leetcode.com/problems/valid-tic-tac-toe-state
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
  bool validTicTacToe(vector<string> &board)
  {
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[i][j] == 'X')
          x++;
        if (board[i][j] == 'O')
          o++;
      }
    }
    if (!(x == o || x == o + 1))
      return false;
    if (x == o && win(board, 'X'))
      return false;
    if (x == o + 1 && win(board, 'O'))
      return false;
    return true;
  }

private:
  bool win(vector<string> &board, char ch)
  {
    for (int i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == ch)
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == ch)
        return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == ch)
      return true;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == ch)
      return true;

    return false;
  }
};