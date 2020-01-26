package cn.huang.leetcode;

/*
861. Score After Flipping Matrix
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.



Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39



 */
public class LC_0861_ScoreAfterFlippingMatrix {
    /*
    http://massivealgorithms.blogspot.com/2018/11/leetcode-861-score-after-flipping-matrix.html
    本题需要知道一个数字规律，即pow(2,n) > sum(pow(2,0)+pow(2,1)+...+pow(2,n-1))。
    所以，为了获得最大值，要保证所有行的最高位是1，即需要优先进行行变换，把最高位变成1。接下来就是列变换，把0多于1的列做变换变成1多于0的列即可。
     */
    public int matrixScore(int[][] A) {
        int M = A.length, N = A[0].length;

        int res = (1 << (N - 1)) * M;
        for (int j = 1; j < N; j++) {
            int cur = 0;
            for (int i = 0; i < M; i++) cur += A[i][j] == A[i][0] ? 1 : 0;
            res += Math.max(cur, M - cur) * (1 << (N - j - 1));
        }
        return res;
    }
}
