import collections

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = collections.Counter(s)
        for index in range(len(s)):
            if dic[s[index]] == 1:
                return index
        return -1

s = Solution()
print s.firstUniqChar("loveleetcode")