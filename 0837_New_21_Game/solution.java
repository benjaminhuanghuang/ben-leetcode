package cn.huang.leetcode;

/*
837. New 21 Game

Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an
integer number of points randomly from the range [1, W], where W is an integer.
Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Example 1:

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.

Example 2:

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.

Example 3:

Input: N = 21, K = 17, W = 10
Output: 0.73278

Note:

    0 <= K <= N <= 10000
    1 <= W <= 10000
    Answers will be accepted as correct if they are within 10^-5 of the correct answer.
    The judging time limit has been reduced for this question.


 */

/*
    这道题是在求概率，在已有点数不超过K的情况下从1至w中选数，之后和不超过N,注意K,N,W可以取到10000,所以N^2是肯定不行的，
    并且递归也会超出最大深度(即使使用记忆化也不行)。

    思路：
    使用动态规划，dp[i]表示点数和为i的概率，那么最后结果应该是dp[k]+dp[k+1]+…+dp[n]
    其中，dp[i]又应该为前w个的dp的平均值
    例如W=10，那么dp[20] = 1/10 * (dp[10]+dp[11]+…+dp[19])
*/
public class LC_0837_New21Game {
    public double new21Game(int N, int K, int W) {
        double[] dp = new double[N + W + 2];
        double[] sum = new double[N + W + 2];

        for (int i = N + W + 1; i >= 0; i--) {
            if (i > N)
                continue;
            if (i >= K)
                dp[i] = 1.0;
            else
                dp[i] = (sum[i + 1] - sum[i + 1 + W]) / W;

            sum[i] = sum[i + 1] + dp[i];
        }
        return dp[0];

    }
}
