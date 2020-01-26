/*
419. Battleships in a Board  [Microsoft]

Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, 
empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 
1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
    X..X
    ...X
    ...X
In the above board there are 2 battleships.
Invalid Example:
    ...X
    XXXX
    ...X
This is not a valid board - as battleships will always have a cell separating between them.
Your algorithm should not modify the value of the board.
*/

public class Solution419
{
    public int CountBattleships(char[,] board)
    {
        int rows = board.GetLength(0);
        int cols = board.GetLength(1);

        if (rows == 0 || cols == 0)
        {
            return 0;
        }

        int ret = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // if 'X' is adjacent with '.', it is battleship.
                if (board[i, j] == 'X')
                {
                    if ((i + 1 >= rows || board[i + 1, j] == '.') &&
                            (j + 1 >= cols || board[i, j + 1] == '.'))
                    {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
}