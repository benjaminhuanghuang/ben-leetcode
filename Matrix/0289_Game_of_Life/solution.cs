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