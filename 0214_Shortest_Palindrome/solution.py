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
