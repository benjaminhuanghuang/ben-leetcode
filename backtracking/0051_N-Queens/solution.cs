/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens 
attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
using System;
using System.Text;
using System.Collections.Generic;


public class Solution051 {
    /*
        Assume there are n queens in the board in 0 – n-1 rows. 
        then in nth row, put a queen in each cell, check if it a valid solution. 
        if it is go ahead and do the n + 1 queens in the board in 0 – n rows. 
        if not, back trace and remove that queen and test another cell.
    */

    public IList<IList<string>> SolveNQueens(int n) {
        var res = new List<IList<string>>();
        var queens = new List<Tuple<int, int>>();
        TotalNQueensRecursion2(n, queens, res);

        return res;
    }
    private void TotalNQueensRecursion2(int n, List<Tuple<int, int>> queens, IList<IList<string>> res)
    {
        if (queens.Count == n)
        {
            var strarray = new string[n];
            for (int row = 0; row < n; row++)
            {
                var stringbuilder = new StringBuilder();
                for (int col = 0; col < n; col++)
                {
                    stringbuilder.Append(queens[row].Item2 == col ? 'Q' : '.');
                }
                strarray[row] = stringbuilder.ToString();
            }
            res.Add(new List<string>(strarray));
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (queens.Count != i)
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (canAdd(queens, i, j))
                {
                    queens.Add(new Tuple<int, int>(i, j));
                    TotalNQueensRecursion2(n, queens,res);
                    queens.Remove(new Tuple<int, int>(i, j));
                }
            }
        }
    }

    private bool canAdd(List<Tuple<int, int>> queens, int i, int j)
    {
        foreach (var queen in queens)
        {
            // check if it is in same row
            if (queen.Item1 == i)
                return false;
         
            // check if it is in same column
            if (queen.Item2 == j)
                return false;
            
            // check if it is same slope
            if (Math.Abs(queen.Item1 - i) == Math.Abs(queen.Item2 - j))
                return false;
        }

        return true;
    }
}