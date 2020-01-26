/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

public class Solution096 {
    // http://www.programcreek.com/2014/05/leetcode-unique-binary-search-trees-java/
    // set random x as root, then left side has x – 1 nodes, right side has n – x nodes. 
    // that is f(x – 1) * f(n – x) 
    // so n nodes have sum of cases x from 1 to n.
    // dp[n] is the count of BST created by array [0 to n] 
    // dp[n] = dp[0]* dp[n-1] + dp[1]*dp[n-2] + ... + dp[i]*dp[n-1-i] +... + dp[n-1]*dp[0]
    public int NumTrees(int n) {
        var dp = new int[n + 1];
        dp[0] = 1; // array is []
        dp[1] = 1; // array has 1 element
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j]*dp[i - j - 1];
            }
        }

        return dp[n];
    }
} 