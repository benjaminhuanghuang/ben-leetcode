/*
289. Game of Life

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton 
devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts 
with its eight neighbors (horizontal, vertical, diagonal) using the following four rules 
(taken from the above Wikipedia article):
    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update 
some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would 
cause problems when the active area encroaches the border of the array. How would you address these problems?

*/

public class Solution289 {
    // http://www.cnblogs.com/grandyang/p/4854466.html
    // http://blog.csdn.net/xudli/article/details/48896549
    //不能新建一个相同大小的数组，那么我们只能更新原有数组，但是题目中要求所有的位置必须被同时更新，
    // 只要有办法区分 4种状态,   DEAD->LIVE, DEAD->DEAD, LIVE->LIVE, LIVE->DEAD 即可.   
    //int 完全可以找4个数来表示这4种状态. 这里我用了   0,1, 10, 11 表示. 
    public void GameOfLife(int[,] board) {
        int m = board.GetLength(0);  
        int n = board.GetLength(1);  
        if(m==0 || n ==0) 
            return;  

        for(int i=0; i<m; i++) {  
            for(int j=0; j<n; j++) {  
                int x = getLiveNum(board, i, j);  
                if(board[i,j] == 0)   // [i, j] is dead
                {  
                    if(x==3) 
                        board[i,j]+=10;  
                } 
                else                 // [i, j] is live
                {  
                    if(x==2 || x==3) 
                        board[i,j]+=10;       
                }  
            }  
        }  
          
        for(int i=0; i<m; i++) {  
            for(int j=0; j<n; j++) {  
                board[i,j] /= 10;   
            }  
        }  
    }

    private int getLiveNum(int[,] board, int x, int y) { 
        int rows = board.GetLength(0);  
        int cols = board.GetLength(1);

        int liveCells = 0;  
        for(int i=x-1; i<=x+1; i++) {  
            for(int j=y-1; j<=y+1; j++) {  
                if(i<0 || j<0 || i >rows-1 || j >cols-1 || (i==x && j==y)) 
                    continue;  
                if(board[i,j]%10==1) 
                    liveCells++;  
            }  
        }  
        return liveCells;  
    }  
}