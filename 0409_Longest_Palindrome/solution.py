import collections


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count_dict = collections.Counter(s)
        res = 0
        hasSingle = False

        for c, count in count_dict.iteritems():
            if count % 2 == 1:
                hasSingle = True
            res += count / 2
        res = res * 2
        if hasSingle:
            res += 1
        return res
