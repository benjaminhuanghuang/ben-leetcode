/*
52. N-Queens II

https://leetcode.com/problems/n-queens-ii/
*/
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
          vector<int> queens(n);

        putQueen(n, 0, queens);

        return res;
    }
private:
    int res = 0;
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
    void putQueen(const int n, const int row, vector<int> &queens)
    {
        if (row == n)
        {
            res ++;
            return;
        }

        // Try every column
        for (int col = 0; col < n; ++col)
        {
            if (!available(queens, row, col))
                continue;
            queens[row] = col;
            putQueen(n, row + 1, queens);
        }
    }
};