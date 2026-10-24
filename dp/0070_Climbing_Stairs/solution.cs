/*
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

public class Solution070 {
    // Time Limit Exceeded
    public int ClimbStairs_Recursive(int n) {
        if (n <= 2)
            return n;
        return ClimbStairs_Recursive(n - 2) + ClimbStairs_Recursive(n - 1);
    }
    public int ClimbStairs_DP1(int n) {
        if (n <= 2)
            return n;
        int[] dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for (int i =2; i< n ; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n-1];
    }

    public int ClimbStairs_DP(int n) {
        if (n <= 2)
            return n;
        int[] s = { 0, 1, 2 };
        int num =2;
        while(num < n)
        {
            s[num % 3] = s[(num + 1) % 3] + s[(num + 2) % 3];
        }
        return s[n%3];
    }

}