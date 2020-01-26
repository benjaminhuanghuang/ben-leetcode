/*
130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution130 {
    // 1. find that all O at edge of board will definitely not surrounded by ‘X’. 
    // 2. then for each ‘O’, find its adjacent ‘O’ by BFS and add to its white list 
    //    (list of ‘O’ that is not surrounded by ‘X’).
    public void Solve(char[,] board) {
        var rows = board.GetLength(0);
        var columns = board.GetLength(1);

        var curQueues = new Queue<Tuple<int, int>>();
        var cur = new HashSet<Tuple<int, int>>();

        // Step 1. find that all O at edge of board
        for (int i = 0; i < rows; i++)
        {
            if (board[i, 0] == 'O') 
                curQueues.Enqueue(new Tuple<int, int>(i, 0));
            if (board[i, columns - 1] == 'O') 
                curQueues.Enqueue(new Tuple<int, int>(i, columns - 1));
        }

        for (int j = 1; j < columns - 1; j++)
        {
            if (board[0, j] == 'O') 
                curQueues.Enqueue(new Tuple<int, int>(0, j));
            if (board[rows - 1, j] == 'O') 
                curQueues.Enqueue(new Tuple<int, int>(rows - 1, j));
        }
        // Step2. find its adjacent ‘O’ by BFS
        while (curQueues.Any())
        {
                var top = curQueues.Dequeue();

                if(cur.Contains(top)) continue;
                cur.Add(top);

                if(top.Item1 - 1 >= 0 && board[top.Item1 - 1, top.Item2] == 'O') 
                    curQueues.Enqueue(new Tuple<int, int>(top.Item1 - 1, top.Item2));
                if (top.Item1 + 1 < rows  && board[top.Item1 + 1, top.Item2] == 'O') 
                    curQueues.Enqueue(new Tuple<int, int>(top.Item1 + 1, top.Item2));
                if (top.Item2 - 1 >= 0 && board[top.Item1, top.Item2 - 1] == 'O') 
                    curQueues.Enqueue(new Tuple<int, int>(top.Item1, top.Item2 - 1));
                if (top.Item2 + 1 < columns && board[top.Item1, top.Item2 + 1] == 'O') 
                    curQueues.Enqueue(new Tuple<int, int>(top.Item1, top.Item2 + 1));
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (!cur.Contains(new Tuple<int, int>(i, j)))
                {
                    board[i, j] = 'X';
                }
            }
        }
    }

//DFS solution. Find all the ‘O’ connect to edge and change them to ‘#’. Then, change all the ‘O’ to ‘X’ and all the ‘#’ to ‘O’.
        public void Solve_2(char[,] board) {
        var row = board.GetLength(0);
        var column = board.GetLength(1);

        for (int i = 0; i < row; i++)
        {
            if (board[i, 0] == 'O')
            {
                SolveHelper(board, i, 0);
            }

            if (board[i, column - 1] == 'O')
            {
                SolveHelper(board, i, column - 1);
            }
        }

        for (int i = 0; i < column; i++)
        {
            if (board[0, i] == 'O')
            {
                SolveHelper(board, 0, i);
            }
            if (board[row - 1, i] == 'O')
            {
                SolveHelper(board, row - 1, i);
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i, j] == 'O')
                {
                    board[i, j] = 'X';
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)             
            {                 
                if (board[i, j] == '#')                 
                {                     
                    board[i, j] = 'O';                 
                }             
            }         
        }        
    }          
    private void SolveHelper(char[,] board, int i, int j)     
    {         
        board[i, j] = '#';         
        if (i - 1 > 0 && board[i - 1, j] == 'O')
        {
            SolveHelper(board, i - 1, j);
        }

        if (i + 1 < board.GetLength(0) - 1&& board[i + 1, j] == 'O')         
        {             
            SolveHelper(board, i + 1, j);         
        }         
        if (j - 1 > 0 && board[i, j - 1] == 'O')
        {
            SolveHelper(board, i, j - 1);
        }

        if (j + 1 < board.GetLength(1) - 1&& board[i, j + 1] == 'O')
        {
            SolveHelper(board, i, j + 1);
        }
    }
}