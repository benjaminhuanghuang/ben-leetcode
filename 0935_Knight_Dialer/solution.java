package cn.huang.leetcode;

/*
935. Knight Dialer

A chess knight can move as indicated in the chess diagram below:

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.
Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing
N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.



Example 1:

Input: 1
Output: 10

Example 2:

Input: 2
Output: 20

Example 3:

Input: 3
Output: 46



Note:

    1 <= N <= 5000


 */
public class LC_0935_KnightDialer {
    public int knightDialer(int N) {
        int MOD = (int) (1e9 + 7);
        int[][] map = new int[][]{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        int[][] dp = new int[2][10];

        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }

        int pre, now = 0;
        for (int i = 2; i <= N; i++) {
            pre = now;
            now = 1 - now;
            for (int j = 0; j < 10; j++) {
                dp[now][j] = 0;
                for (int x : map[j]) {
                    dp[now][j] = (dp[now][j] + dp[pre][x]) % MOD;
                }
            }
        }

        int result = 0;
        for (int num : dp[now]) {
            result = (result + num) % MOD;
        }
        return result;
    }
}
