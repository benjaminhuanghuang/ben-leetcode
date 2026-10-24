/*
51. N-Queens

https://leetcode.com/problems/n-queens/

*/
#include <vector>
#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/searching/leetcode-51-n-queens/

pseudocode
available(x, y):
  return !col[x] && !diag(x,y) && !diag(x, y)

// 按行搜索
n_queen(y, n, solution, ans):
  if y==n:  // 超出棋盘，说明n个queen已经放好
    ans += solution
    return;
  for x in (0, n):
    if not available(x, y): continue
    put(x, y, solution)
    n_queen(y+1, n, solution, ans)
    remove(x, y, solution)


*/
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        sols_.clear();
        board_ = vector<string>(n, string(n, '.'));

        cols_ = vector<int>(n, 0);
        diag1_ = vector<int>(2 * n - 1, 0);
        diag2_ = vector<int>(2 * n - 1, 0);

        nqueens(n, 0);

        return sols_;
    }

private:
    vector<string> board_;
    vector<int> cols_;
    vector<int> diag1_;
    vector<int> diag2_;
    vector<vector<string>> sols_;

    bool available(int x, int y, int n)
    {
        return !cols_[x] && !diag1_[x + y] && !diag2_[x - y + n - 1];
    }

    void updateBoard(int x, int y, int n, bool is_put)
    {
        cols_[x] = is_put;
        diag1_[x + y] = is_put;
        diag2_[x - y + n - 1] = is_put;
        board_[y][x] = is_put ? 'Q' : '.';
    }

    // Try to put the queen on y-th row
    void nqueens(const int n, const int y)
    {
        if (y == n)
        {
            // found one solution, add to the ans set
            sols_.push_back(board_);
            return;
        }

        // Try every column
        for (int x = 0; x < n; ++x)
        {
            if (!available(x, y, n))
                continue;
            updateBoard(x, y, n, true);
            nqueens(n, y + 1);
            updateBoard(x, y, n, false);
        }
    }
};

/*
    Assume there are n queens in the board in 0 to n-1 rows.
    then in nth row, put a queen in each cell, check if it a valid solution.
    if it is go ahead and do the n + 1 queens in the board in 0 – n rows.
    if not, back trace and remove that queen and test another cell.
*/

class Solution_better
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> queens(n);

        putQueen(n, 0, queens, ans);

        return ans;
    }

private:
    /*
        queens 记录了每一行，第几列上有queen
    */
    bool available(vector<int> queens, int row, int col)
    {
        for (int r = 0; r < row; r++)
        {
            int c = queens[r];
            if (c == col)
                return false;
            if (c - r == col - row)
                return false;
            if (c + r == col + row)
                return false;
        }
        return true;
    }

    // Try to put the queen on y-th row
    void putQueen(const int n, const int row, vector<int> &queens, vector<vector<string>> &ans)
    {
        if (row == n)
        {
            // found one solution, add to the ans set
            vector<string> board = vector<string>(n, string(n, '.'));
            for (int row = 0; row < n; row++)
            {
                board[row][queens[row]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        // Try every column
        for (int col = 0; col < n; ++col)
        {
            if (!available(queens, row, col))
                continue;
            queens[row] = col;
            putQueen(n, row + 1, queens, ans);
        }
    }
};