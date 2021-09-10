
5. Longest Palindromic Substring

- Solution 1:
Greedy, expend string from the middle

- Solution 2:
DP
维护一个二维数组 dp，dp[i][j] 表示字符串区间 [i, j] 是否为回文串，

当 i = j 时，只有一个字符，肯定是回文串，

如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]，

如果i和j不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i + 1][j - 1] 若为真，就是回文串

dp[i, j] = 1                                               if i == j

           = s[i] == s[j]                                if j = i + 1

           = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1      

132. Palindrome Partitioning II





