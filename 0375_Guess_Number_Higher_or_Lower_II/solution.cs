/*
375. Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Hint:
    The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
    Take a small example (n = 3). What do you end up paying in the worst case?
    Check out this article if you're still stuck.
    The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
    As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
*/

/*
https://www.hrwhisper.me/leetcode-guess-number-higher-lower-ii/
在猜测数字y未知的情况下,要我们在最坏情况下我们支付最少的钱。也就是说要考虑所有y的情况。
我们假定选择了一个错误的数x，（1<= x<=n && x!=y ）那么就知道接下来应该从[1,x-1 ] 或者[x+1,n]中进行查找。 
假如我们已经解决了[1,x-1] 和 [x+1,n]计算问题，我们将其表示为solve(L,x-1) 和solve(x+1,n)，
那么max(solve(L,x-1),solve(x+1,n))就是求最坏情况下的损失。
总的损失就是 f(x) = x + max(solve(L,x-1),solve(x+1,n))

那么将x从1~n进行遍历，取使得 f(x) 达到最小，来确定最坏情况下最小的损失，也就是我们初始应该选择哪个数。

*/
using System;

public class Solution375 {
    public int GetMoneyAmount(int n) {
        int[,] dp = new int[n+1,n+1];
        return solve(dp, 1, n);
    }

    int solve(int[,] dp, int L, int R) {
		if (L >= R) 
            return 0;
		if (dp[L,R] != 0) 
            return dp[L,R];
		dp[L,R] = int.MaxValue;
		for (int i = L; i <= R; i++) {
			dp[L,R] = Math.Min(dp[L,R], i + Math.Max(solve(dp,L,i-1),solve(dp,i+1,R)));
		}
		return dp[L,R];
	}
}