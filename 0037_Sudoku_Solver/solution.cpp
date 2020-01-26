/*
37. Sudoku Solver

https://leetcode.com/problems/sudoku-solver/
*/

#include <vector>

using namespace std;


/*
https://zxi.mytechroad.com/blog/searching/leetcode-37-sudoku-solver/

DFS + back-tracking
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows_ = vector<vector<int>>(9, vector<int>(10)); // key : y, vector<int>(10) 0: 表示没有使用过， 1表示使用过
        cols_ = vector<vector<int>>(9, vector<int>(10)); // key: x
        boxes_ = vector<vector<int>>(9, vector<int>(10)); // key: (y/3)*3 + x/3
        
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                const char c = board[i][j];                
                if ( c != '.') {
                    int n = c - '0';                    
                    int bx = j / 3;
                    int by = i / 3;
                    // set n to used
                    rows_[i][n] = 1;    
                    cols_[j][n] = 1;
                    boxes_[by * 3 + bx][n] = 1;
                }
            }
        
        dfs_fill(board, 0, 0);
    }
    
private:
    vector<vector<int>> rows_, cols_, boxes_;
    
    bool dfs_fill(vector<vector<char>>& board, int x, int y) {
        if (y == 9)
            return true;
        // next cell
        int nx = (x + 1) % 9;
        int ny = (nx == 0) ? y + 1 : y;
        
        if (board[y][x] != '.') 
            return dfs_fill(board, nx, ny);
        
        for (int i = 1; i <= 9; i++) {
            int bx = x / 3;
            int by = y / 3;
            int box_key = by * 3 + bx;
            // validate
            if (!rows_[y][i] && !cols_[x][i] && !boxes_[box_key][i]) {
                rows_[y][i] = 1;
                cols_[x][i] = 1;
                boxes_[box_key][i] = 1;
                board[y][x] = i + '0';
                if (dfs_fill(board, nx, ny)) 
                    return true;
                // recover
                board[y][x] = '.';
                boxes_[box_key][i] = 0;
                cols_[x][i] = 0;
                rows_[y][i] = 0;
            }
        }
        return false;
    }
};