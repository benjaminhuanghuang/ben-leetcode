/*
329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally 
or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
using System;
// Passed with Brute Force
public class Solution329 {
    int row;
    int col;
    private int[][] path;
    public int LongestIncreasingPath(int[,] matrix) {
        row = matrix.GetLength(0);
        col = matrix.GetLength(1);
        if(row == 0 || col==0)
            return 0;
        path = new int[row][];
        for (int r = 0; r < row; r++)
            path[r] = new int[col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(matrix, i, j);
            }
        }

        return max(path) + 1;
    }

     private int max(int[][] path) {
        int len = 0;
        for (int i = 0; i < path.Length; i++) {
            for (int j = 0; j < path[0].Length; j++) {
                len = Math.Max(len, path[i][j]);
            }
        }
        
        return len;
    }

    private void dfs(int[,] matrix, int i, int j) {
        int[] v1 = new int[]{1, 0, -1, 0};
        int[] v2 = new int[]{0, 1, 0, -1};
        for (int m = 0; m < 4; m++) {
            int x = i + v1[m];
            int y = j + v2[m];
            if (x >= 0 && y >= 0 && x < row && y < col && 
                    matrix[i,j] < matrix[x,y] && path[i][j] >= path[x][y]) {
                path[x][y] = path[i][j] + 1;
                dfs(matrix, x, y);
            }
        }
    }
}