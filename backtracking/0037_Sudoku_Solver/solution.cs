/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


https://miafish.wordpress.com/2015/02/17/leetcode-ojc-valid-sudoku/

*/
public class Solution037 {
    public void SolveSudoku(char[,] board) {
         this.Slove(0, board);
    }

    private bool Slove(int curr, char[,] board)
    {
        if (curr == 81)
            return true;
        int i = curr / 9;
        int j = curr % 9;
        if (board[i, j] != '.')
            return this.Slove(curr +1, board);
        
        for (int k = 1; k <=9 ; k++)  // try num 1 to 9 at borad[i, j]
        {
            board[i, j] = (char)(k +'0');
            if (this.Check(board, i, j) && this.Slove(curr+1, board))
                return true;
            board[i, j] = '.';
        }

        return false;
    }


    // Check the char at board[x, y] is valid or not.
    private bool Check(char[,] board, int x, int y )
    {
        int size = board.GetLength(0);

        // Check the cross board[x, i], board[i, y]
        for (int i = 0; i < 9; i++)
        {
            if ((board[x, i] == board[x, y] && i != y) || 
                (board[i, y] == board[x, y] && i != x))
            {
                return false;
            }
        }  
        // Check the square contains [x, y]
        for (int i =0; i< 3; i++)
        {
            for (int j =0; j< 3; j++)
            {
                int col = x / 3 * 3 + i;
                int row = y / 3 * 3 + j;
                if ( board[col, row ] == board[x, y] && x != col && y != row)
                    return false;
            }
        }
        return true;
    }
}

