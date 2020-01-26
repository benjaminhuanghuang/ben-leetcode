'''
214. Shortest Palindrome

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".


'''


class Solution(object):
    # Find the prefix of s in reversed string of s.
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""

        t = s[::-1]

        for i in range(len(s)):
            if s.startswith(t[i:]):
                return t[:i] + s


s = Solution()
input = "aacecaaa"
input = "abcd"
print s.shortestPalindrome(input)
print input[3:]
