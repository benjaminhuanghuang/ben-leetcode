'''
139. Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one
or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

'''


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for k in range(i):
                if dp[k] and s[k:i] in wordDict:
                    dp[i] = True
        return dp[n]

    # dp[i] means s[:i] can be broken into the words in dict.
    # if s[j:i] in word dict and dp[j] is true, we can say dp[i] is true
    def wordBreak_2(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n):
            for j in range(i, -1, -1):
                if dp[j] and s[j:i + 1] in wordDict:
                    dp[i + 1] = True
                    break
        return dp[n]


s = Solution()
print s.wordBreak("leetcode", ["leet", "code"])
