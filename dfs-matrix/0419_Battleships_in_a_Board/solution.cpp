/*
419. Battleships in a Board

Level: Medium

https://leetcode.com/problems/battleships-in-a-board
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
  int countBattleships(vector<vector<char>> &board)
  {
    int count = 0;
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
      {
        if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
          ++count;
      }
    return count;
  }
};

/*
  https://www.youtube.com/watch?v=q7kHTti3910
*/
class Solution
{
public:
  int countBattleships(vector<vector<char>> &board)
  {
    int count = 0;
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
      {
        if (board[i][j] == 'X')
        {
          if (i > 0 && board[i][j] == board[i - 1][j])
            continue;
          if (i > 0 && board[i][j] == board[i][j - 1])
            continue;
          ++count;
        }
      }
    return count;
  }
};