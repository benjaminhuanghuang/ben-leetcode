package cn.huang.leetcode;
/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


 */
public class LC_0096_UniqueBinarySearchTrees {
    /*
     // http://www.programcreek.com/2014/05/leetcode-unique-binary-search-trees-java/
    // set random x as root, then left side has x – 1 nodes, right side has n – x nodes.
    // that is f(x – 1) * f(n – x)
    // so n nodes have sum of cases x from 1 to n.
    // dp[n] is the moves of BST created by array [0 to n]
    // dp[n] = dp[0]* dp[n-1] + dp[1]*dp[n-2] + ... + dp[i]*dp[n-1-i] +... + dp[n-1]*dp[0]
     */

    /*
    https://www.youtube.com/watch?v=HWJEMKWzy-Q
    1 to n , every number x can be the root of the tree
    left sub tree can have x - 1 nodes, right sub tree can have n - x nodes

     */
    public int numTrees(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1; // array is []
        dp[1] = 1; // array has 1 element
        for (int i = 2; i <= n; i++)     // total nodes moves
        {
            for (int j = 0; j < i; j++)   // j =  node of left sub tree
            {
                //i - j - 1 is the nodes of right sub tree
                dp[i] += dp[j]*dp[i - j - 1];
            }
        }

        return dp[n];
    }
}
