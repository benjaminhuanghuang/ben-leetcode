package cn.huang.leetcode;

/*
920. Number of Music Playlists

Your music player contains N different songs and she wants to listen to L (not necessarily different) songs
during your trip.  You create a playlist so that:

    Every song is played at least once
    A song can only be played again only if K other songs have been played

Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.



Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].

Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]

Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]



Note:

    0 <= K < N <= L <= 100


 */

/*

    音乐播放器，总共有N首不同的歌曲，有L个位置（就是总共在这N首歌里面循环放了L首），
    要求每首歌至少放一次，然后一首歌要想重复放，必须要有K首其他歌放过了才可以再放

 */
public class LC_0920_NumberofMusicPlaylists {
    public int numMusicPlaylists(int N, int L, int K) {
        long[][] dp = new long[L + 1][N + 1];
        for (int i = 1; i < L + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                if (i < j) dp[i][j] = 0;
                else if (i == 1 && j == 1) dp[i][j] = N;
                else if (i > 1 && j == 1) {
                    if (K == 0) dp[i][j] = N;
                    else dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] * (N - j + 1) + dp[i - 1][j] * Math.max(j - K, 0);
                    dp[i][j] %= 1_000_000_007;
                }

            }
        }
        return (int) dp[L][N];
    }
}
