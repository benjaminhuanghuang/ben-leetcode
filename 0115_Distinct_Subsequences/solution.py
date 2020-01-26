'''
115. Distinct Subsequences [string] [hard] [dp]

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
'''


class Solution(object):
    # http://www.cnblogs.com/zuoyuan/p/3767256.html
    # https://www.hrwhisper.me/leetcode-dynamic-programming/
    # https://shenjie1993.gitbooks.io/leetcode-python/content/115%20Distinct%20Subsequences.html
    #
    # dp[i][j] is the count of subsequence in s[:i] match t[:j]
    # dp[i][0] = 1, t is empty, delete all char in s can get t
    # if s[i] == t[j] , dp[i][j]=dp[i-1][j] + dp[i-1][j-1]
    # if s[i]!=t[j]: dp[i][j]=dp[i-1][j]
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        len_s, len_t = len(s), len(t)
        dp = [[0 for j in range(len_t + 1)] for i in range(len_s + 1)]
        for i in xrange(0, len_s + 1):
            dp[i][0] = 1

        for i in xrange(1, len_s + 1):
            for j in xrange(1, len_t + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j]

        return dp[len_s][len_t]
