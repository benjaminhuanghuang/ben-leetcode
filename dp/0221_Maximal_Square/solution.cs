/*
221. Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

*/

/*
首先最小的正方形边长就是1，那什么时候可以扩展成2呢？要满足三个条件：
    当前元素是1
    当前元素的左上角是1
    当前元素的左边和上面也是1
从上面类推可以发现什么时候一个正方形边长会从n扩展到n+1呢？同样也是上面3个条件，即当前为1，左上角为n,左边和右边也是n
当前元素为0的时候当前正方形肯定是0，如果出现上面任意一个条件不满足，就无法扩展正方形，因为总会有一个边有缺失。所以最终的DP方程就是成
DP[i,j]=Min(DP[i-1,j-1],DP[i-1,j],DP[i,j-1])+1
为了防止各种数组越界，所以刚开始就要初始化第一行和第一列，有一个小细节就是有可能最大正方形就是出现在第一行第一列，所以初始化时要判断max
*/

using System;

public class Solution221 {
    //http://www.voidcn.com/blog/huzhigenlaohu/article/p-6163771.html
    public int maximalSquare(char[,] matrix) {
        if(matrix.GetLength(0) == 0) return 0;
        int m = matrix.GetLength(0), n = matrix.GetLength(1);
        int max = 0;
        int[,] dp = new int[m,n];
        // 第一列赋值
        for(int i = 0; i < m; i++){
            dp[i,0] = matrix[i,0] - '0';
            max = Math.Max(max, dp[i,0]);
        }
        // 第一行赋值
        for(int i = 0; i < n; i++){
            dp[0,i] = matrix[0,i] - '0';
            max = Math.Max(max, dp[0,i]);
        }
        // 递推
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i,j] = matrix[i,j] == '1' ? Math.Min(dp[i-1,j-1], Math.Min(dp[i-1,j], dp[i,j-1])) + 1 : 0;
                max = Math.Max(max, dp[i,j]);
            }
        }
        return max * max;
    }

    //http://magicsong.xyz/leetcode/leetcode%E4%B9%8Bmaximal-square%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF%EF%BC%88c%EF%BC%89/
    public int MaximalSquare_2(char[,] matrix) {
        int m = matrix.GetLength(0);
        int n = matrix.GetLength(1);
        int max = 0;
        int[,] dp = new int[m, n];
        // 第一列赋值
        for (int i = 0; i < m; i++)
        {
            dp[i, 0] = matrix[i, 0] - '0';
            max = Math.Max(max, dp[i, 0]);
        }
        // 第一行赋值
        for (int i = 0; i < n; i++)
        {
            dp[0, i] = matrix[0, i] - '0';
            max = Math.Max(max, dp[0, i]);
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i, j] == '0')
                    dp[i, j] = 0;
                else
                {
                    dp[i, j] = Math.Min(Math.Min(dp[i - 1, j - 1], dp[i, j - 1]), dp[i - 1, j]) + 1;
                    if (dp[i, j] > max)
                        max = dp[i, j];
                }
            }
        }
        return max;
    }
}