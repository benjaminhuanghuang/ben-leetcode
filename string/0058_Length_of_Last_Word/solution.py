'''
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
'''


class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """

        if not s or len(s) <= 0:
            return 0
        words = s.strip().split(" ")

        return len(words[-1])

    def lengthOfLastWord_2(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or len(s) <= 0:
            return 0
        s = s.strip()
        length = 0
        for i in xrange(len(s)):
            if s[i] == " ":
                length = 0
            else:
                length += 1

        return length


class Solution_my(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == " " and l == 0:
                continue
            if s[i] == " ":
                break
            else:
                l += 1
        return l


s = Solution()
print s.lengthOfLastWord("a ")

print s.lengthOfLastWord_2("a ")

print s.lengthOfLastWord_2("Hello World")
