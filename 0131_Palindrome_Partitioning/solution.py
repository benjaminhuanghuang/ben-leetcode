'''
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
'''


class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        res = []
        self.dfs(res, s, [])
        return res

    def isPalindrome(self, s):
        for i in range(len(s)):
            if s[i] != s[len(s) - 1 - i]:
                return False
        return True

    def dfs(self, res, s, stringlist):
        if len(s) == 0:
            res.append(stringlist)
        for i in range(1, len(s) + 1):
            if self.isPalindrome(s[:i]):
                self.dfs(res, s[i:], stringlist + [s[:i]])

input = "aab"
s = Solution()
print s.partition(input)