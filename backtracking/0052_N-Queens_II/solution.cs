/*
52. N-Queens II

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/
using System;
using System.Text;
using System.Collections.Generic;

/*
    Time complexity: O(n!)
    Space complexity: O(n)
*/
public class Solution052
{
    private int totalNumber = 0;
    public int totalNQueens(int n)
    {
        var queens = new List<Tuple<int, int>>();
        TotalNQueensRecursion(n, queens);
        return totalNumber;
    }
    private void TotalNQueensRecursion(int n, List<Tuple<int, int>> queens)
    {
        /*
            queens 中存放的是已经摆上棋盘的queen的坐标，
        */
        if (queens.Count == n)   // N queen were put on the board
        {
            totalNumber++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (queens.Count != i)
            {
                //
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (canAdd(queens, i, j))
                {
                    queens.Add(new Tuple<int, int>(i, j));
                    TotalNQueensRecursion(n, queens);
                    queens.Remove(new Tuple<int, int>(i, j));
                }
            }
        }
    }

    /*
        queens 中存放的是已经摆上棋盘的queen的坐标，
        检查 能否放一个queen到 i,j
    */
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