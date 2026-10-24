'''
151. Reverse Words in a String

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".


'''


class Solution(object):
    def reverseWords_lazy(self, s):
        """
        :type s: str
        :rtype: str
        """
        word_list = s.strip().split(" ")
        # word_list = map(str.strip, word_list)
        word_list = [w.strip() for w in word_list]
        word_list = reversed(word_list)
        return " ".join(word_list)

    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        end = len(s) - 1
        for i in xrange(len(s) - 1, -1, -1):
            if s[i] == " ":
                end = i - 1
            elif i == 0 or s[i - 1] == " ":
                if len(res) > 0:
                    res += " "
                res += s[i: end + 1]

        return res


s = Solution()

print s.reverseWords_lazy("the sky is blue")
print s.reverseWords("  the   sky  is blue  ")
print s.reverseWords("a")
