/*
1275. Find Winner on a Tic Tac Toe Game

Level: Easy

https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
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
  string tictactoe(vector<vector<int>> &moves)
  {
    vector<vector<string>> board(3, vector<string>(3, "#"));
    bool ATurn = true;
    for (const auto &move : moves)
    {
      board[move[0]][move[1]] = ATurn ? "A" : "B";
      ATurn = !ATurn;
    }

    for (int i = 0; i < 3; ++i)
    {
      // horizontal
      if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != "#")
        return board[i][0];
      // vertial
      if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[0][i] != "#")
        return board[0][i];
    }
    // na
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != "#")
      return board[1][1];
    // pie
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != "#")
      return board[1][1];
    return moves.size() == 9 ? "Draw" : "Pending";
  }
}
;