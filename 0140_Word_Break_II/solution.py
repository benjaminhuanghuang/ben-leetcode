'''
140. Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a
valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
'''


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
        """
        tokenDict = {}

        def dfs(s):
            ans = []
            if s in wordDict:
                ans.append(s)

            for x in range(len(s) - 1):
                prefix, suffix = s[:x + 1], s[x + 1:]
                if prefix not in wordDict:
                    continue

                if suffix in tokenDict:
                    rest = tokenDict[suffix]
                else:
                    rest = dfs(suffix)
                for n in rest:
                    ans.append(prefix + ' ' + n)
            tokenDict[s] = ans
            return ans

        return dfs(s)


    # http://www.cnblogs.com/zuoyuan/p/3760804.html
    def wordBreak_2(self, s, dict):
        Solution.res = []
        self.dfs(s, dict, '')
        return Solution.res

    def check(self, s, dict):
        dp = [False for i in range(len(s) + 1)]
        dp[0] = True
        for i in range(1, len(s) + 1):
            for k in range(0, i):
                if dp[k] and s[k:i] in dict:
                    dp[i] = True
        return dp[len(s)]

    def dfs(self, s, dict, stringlist):
        if self.check(s, dict):
            if len(s) == 0:
                Solution.res.append(stringlist[1:])
            for i in range(1, len(s) + 1):
                if s[:i] in dict:
                    self.dfs(s[i:], dict, stringlist + ' ' + s[:i])

input = "catsanddog"
dict = ["cat", "cats", "and", "sand", "dog"]

s = Solution()
print s.wordBreak(input, dict)
