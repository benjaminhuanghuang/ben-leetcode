'''
28. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
'''


class Solution(object):
    def strStr_lazy(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtyp
        """
        return haystack.find(needle);

    def strStr_brutal_force(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtyp
        """
        if not needle:
            return 0
        if not haystack:
            return -1

        len_h = len(haystack)
        len_n = len(needle)

        for i in xrange(len_h - len_n + 1):  # + 1!!!
            for j in xrange(len_n):
                str_h = haystack[i + j]
                str_n = needle[j]
                if str_h != str_n:
                    break
                if j == len_n - 1:
                    return i

        return -1

    # http://bangbingsyb.blogspot.com/2014/11/leetcode-implement-strstr-kmp.html
    # http://www.matrix67.com/blog/archives/115
    def strStr_brutal_kmp(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtyp
        """
        if not needle:
            return 0
        if not haystack:
            return -1


s = Solution()
print s.strStr_brutal_force("a", "a")
