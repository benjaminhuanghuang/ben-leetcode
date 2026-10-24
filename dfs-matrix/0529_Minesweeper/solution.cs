using System;
public class Solution529
{
    private int[,] dir = { {0,1}, {0,-1}, {1,0}, {-1,0},
                           {1,1}, {1,-1}, {-1,1},{-1,-1}};
    public char[,] UpdateBoard(char[,] board, int[] click)
    {
        // Note! x is row and y is col
        int row = click[0];
        int col = click[1];

        dfs(board, row, col);

        return board;
    }
    
    // row is x and col is y
    private void dfs(char[,] board, int row, int col)
    {
        int rows = board.GetLength(0);
        int cols = board.GetLength(1);


        if (board[row, col] == 'M')    //click on a unrevealed mine, game over
        {
            board[row, col] = 'X';
            return;
        }
        else if (board[row, col] == 'E') // click on a unrevealed empty square
        {
            int mineCount = 0; // count of mine around cell[col, row]
            for (int i = 0; i < 8; i++)
            {
                int xx = row + dir[i, 0];
                int yy = col + dir[i, 1];
                if (xx >= 0 && xx < rows && yy >= 0 && yy < cols && board[xx, yy] == 'M')
                    mineCount++;
            }
            if (mineCount > 0)
            {
                //board[row, col] = Convert.ToChar(mineCount);  //it is unicode
                board[row, col] = (char)(mineCount + '0');
                return;
            }
            else
            {
                board[row, col] = 'B';  //revealed blank square that has no adjacent mine
                for (int i = 0; i < 8; i++)
                {
                    int xx = row + dir[i, 0];
                    int yy = col + dir[i, 1];
                    if (xx >= 0 && xx < rows && yy >= 0 && yy < cols)   // cell is in board
                        dfs(board, xx, yy);
                }
            }
        }
    }
}

/*

 char[,] matrix = {{'E', 'E', 'E', 'E', 'E'},
                        {'E', 'E', 'M', 'E', 'E'},
                        {'E', 'E', 'E', 'E', 'E'},
                        {'E', 'E', 'E', 'E', 'E'}};
 var s = new Solution529();
 var b = s.UpdateBoard(matrix, new int[]{3,0});
*/