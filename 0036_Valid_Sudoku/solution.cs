/*
36. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need 
to be validated.


https://miafish.wordpress.com/2015/02/17/leetcode-ojc-valid-sudoku/
*/
using System.Collections.Generic;

public class Solution036
{
  // This solution is easy to unsderstand
  public bool IsValidSudoku(char[,] board)
  {
    Dictionary<char, bool> hashtable;
    // check columns
    for (var i = 0; i < 9; i++)
    {
      hashtable = new Dictionary<char, bool>();
      for (var j = 0; j < 9; j++)
      {
        var value = board[i, j];
        if (value.Equals('.'))
        {
          continue;
        }

        if (hashtable.ContainsKey(value))
        {
          return false;
        }

        hashtable.Add(value, true);
      }
    }

    // check rows
    for (var i = 0; i < 9; i++)
    {
      hashtable = new Dictionary<char, bool>();
      for (var j = 0; j < 9; j++)
      {
        var value = board[j, i];
        if (value.Equals('.'))
        {
          continue;
        }

        if (hashtable.ContainsKey(value))
        {
          return false;
        }

        hashtable.Add(value, true);
      }
    }

    // check squares
    for (var i = 0; i < 3; i++)
    {
      for (var j = 0; j < 3; j++)
      {
        hashtable = new Dictionary<char, bool>();

        for (var m = 0; m < 3; m++)
        {
          for (var n = 0; n < 3; n++)
          {
            var value = board[i * 3 + m, j * 3 + n];
            if (value.Equals('.'))
            {
              continue;
            }

            if (hashtable.ContainsKey(value))
            {
              return false;
            }

            hashtable.Add(value, true);
          }
        }
      }
    }

    return true;
  }
  public bool isValidSudoku_Better(char[][] board)
  {
    if (board == null || board.Length != 9 || board[0].Length != 9)
      return false;

    // check each column
    for (int i = 0; i < 9; i++)
    {
      bool[] m = new bool[9];
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j] != '.')
        {
          if (m[(int)(board[i][j] - '1')])
          {
            return false;
          }
          m[(int)(board[i][j] - '1')] = true;
        }
      }
    }

    //check each row
    for (int j = 0; j < 9; j++)
    {
      bool[] m = new bool[9];
      for (int i = 0; i < 9; i++)
      {
        if (board[i][j] != '.')
        {
          if (m[(int)(board[i][j] - '1')])
          {
            return false;
          }
          m[(int)(board[i][j] - '1')] = true;
        }
      }
    }

    //check each 3*3 matrix
    for (int block = 0; block < 9; block++)
    {
      bool[] m = new bool[9];
      for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++)
      {
        for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++)
        {
          if (board[i][j] != '.')
          {
            if (m[(int)(board[i][j] - '1')])
            {
              return false;
            }
            m[(int)(board[i][j] - '1')] = true;
          }
        }
      }
    }

    return true;
  }

  public bool isValidSudoku_2(char[][] board)
  {
    for (var i = 0; i < 9; i++)
    {
      var hashtableRow = new Dictionary<char, bool>();
      var hashtableColumn = new Dictionary<char, bool>();
      var hashtableSquare = new Dictionary<char, bool>();

      for (var j = 0; j < 9; j++)
      {
        var columnValue = board[i][j];
        var rowValue = board[j][i];
        var squareValue = board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3];
        if (columnValue != '.' && hashtableColumn.ContainsKey(columnValue))
        {
          return false;
        }

        hashtableColumn.Add(columnValue, true);

        if (rowValue != '.' && hashtableRow.ContainsKey(rowValue))
        {
          return false;
        }

        hashtableRow.Add(rowValue, true);

        if (squareValue != '.' && hashtableSquare.ContainsKey(squareValue))
        {
          return false;
        }

        hashtableSquare.Add(squareValue, true);
      }
    }

    return true;
  }
}