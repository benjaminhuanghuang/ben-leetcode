/*
79. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


public class Solution079 {
    //use visited array to mark which ones has visited, we need backtracking.
    public bool Exist(char[,] board, string word) {
        var row = board.GetLength(0);
        var column = board.GetLength(1);
        var visited = new bool[row, column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i, j] == word[0])
                {
                    if(ExistHelper(board, i, j, word, 0, visited)) 
                        return true;
                }
            }
        }

        return false;
    }

    private bool ExistHelper(char[,] board, int i, int j, string word, int index, bool[,] visited)
    {
        if (i < 0 || i >= board.GetLength(0) || 
            j < 0 || j >= board.GetLength(1) || 
            board[i, j] != word[index] || visited[i, j]) 
           return false;
        if (index == word.Length - 1) return true;

        visited[i, j] = true;

        if (ExistHelper(board, i - 1, j, word, index + 1, visited)) return true;
        if (ExistHelper(board, i + 1, j, word, index + 1, visited)) return true;
        if (ExistHelper(board, i, j - 1, word, index + 1, visited)) return true;
        if (ExistHelper(board, i, j + 1, word, index + 1, visited)) return true;

        visited[i, j] = false;

        return false;
    }
}