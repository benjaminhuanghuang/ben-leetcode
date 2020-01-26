package cn.huang.leetcode;

/*
474. Ones and Zeroes

In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:

    The given numbers of 0s and 1s will both not exceed 100
    The size of given string array won't exceed 600.

Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”

Example 2:

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

 */
public class LC_0474_OnesandZeroes {
    /*
    https://www.youtube.com/watch?v=WHNwY8YPRgA
    https://blog.csdn.net/H12590400327/article/details/78930361


    给定一组01字符串strs。求用m个0和n个1最多可以组成多少个strs中的字符串。

    物品的价值：1，用于计数，要求最大总价值即选出字符串的数量最多
    背包总容量：[m][n]，m为给定 0 的个数，n为给定 1 的个数
    dp[zero][one] = max(1 + dp[zero - n0][one - n1], dp[zero][one])

     */
    public int findMaxForm(String[] strs, int m, int n) {
        // result[i][j]表示有i个0和j个1可以装下的字符串的数量
        int[][] result = new int[m + 1][n + 1];
        for (String s : strs) {
            int numOne = 0, numZero = 0;
            for (char c : s.toCharArray()) {
                if (c == '0')
                    numZero++;
                else if (c == '1')
                    numOne++;
            }

            for (int i = m; i >= numZero; i--) {
                for (int j = n; j >= numOne; j--) {
                    result[i][j] = Math.max(result[i][j], 1 + result[i - numZero][j - numOne]);
                }
            }
        }
        return result[m][n];
    }
}
