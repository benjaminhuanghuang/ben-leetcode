'''
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
'''


class Solution(object):
    # Time limit exceeded
    # if p[j+1] == *, s[i]==p[j]
    # if p[j+1] != *,
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0:  # "","", finally match
            return len(s) == 0
        if len(p) == 1 or p[1] != '*':
            if len(s) == 0 or (s[0] != p[0] and p[0] != '.'):
                return False
            return self.isMatch(s[1:], p[1:])
        else:
            i = -1
            length = len(s)
            while i < length and (i < 0 or p[0] == '.' or p[0] == s[i]):
                if self.isMatch(s[i + 1:], p[2:]):
                    return True
                i += 1
            return False


    # http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
    # dp[i][j] means s[0:i-1] can match p[0:j-1]
    # p[j-1] != '.' and p[j-1] != '*':
    #       dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
    # p[j-1] == '.':
    #       dp[i][j] = dp[i-1][j-1]
    # p[j-1] == '*'
    #      match 0 chart,  dp[i][j] = dp[i][j-2]
    #      match 1 chart,
    #      match n chart, dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])
    def isMatch_dp(self, s, p):
        dp = [[False for i in range(len(p) + 1)] for j in range(len(s) + 1)]
        dp[0][0] = True
        for i in range(1, len(p) + 1):
            if p[i - 1] == '*':
                if i >= 2:
                    dp[0][i] = dp[0][i - 2]
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i][j - 2] or (
                        dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.'))
                else:
                    dp[i][j] = dp[i - 1][j - 1] and s[i - 1] == p[j - 1]
        return dp[len(s)][len(p)]
