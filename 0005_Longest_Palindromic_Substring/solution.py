'''
5. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


reference:
    http://fisherlei.blogspot.com/2012/12/leetcode-longest-palindromic-substring.html
'''


class Solution(object):
    # O(n^3)  Time Limit Exceeded
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        substr = ''
        for i in range(len(s)):
            for j in range(i, len(s) + 1):
                if self.checkpali(s[i:j]):
                    if len(substr) < len(s[i:j]):
                        substr = s[i:j]
        return substr

    def checkpali(self, substr):
        for index in range(len(substr)):
            if substr[index] != substr[len(substr) - index - 1]:
                return False
        return True

    def longestPalindrome_2(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        for i in xrange(len(s)):
            sub_str = self.get_pali(s, i, i)       # for aba
            if len(res) < len(sub_str):
                res = sub_str
            sub_str = self.get_pali(s, i, i + 1)   # for abba
            if len(res) < len(sub_str):
                res = sub_str
        return res

    # a, aba, abba
    def get_pali(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1: right]   # note the index


s = Solution()
print s.longestPalindrome_2("baab")
