class Solution(object):
    # http://bookshadow.com/weblog/2015/04/05/leetcode-longest-substring-without-repeating-characters/
    def lengthOfLongestSubstring(self, s):

        max_len = 0
        start, end = 0, 0   # start and end of substring
        countDict = {}    # count of charts in substring
        for c in s:
            end += 1
            countDict[c] = countDict.get(c, 0) + 1
            while countDict[c] > 1:     # my mistake:  use if here , can not pass "pwwk"
                countDict[s[start]] -= 1
                start += 1
            max_len = max(max_len, end - start)    # my mistake : use end - start + 1
        return max_len

    def lengthOfLongestSubstring_2(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = 0
        maxlen = 0
        dict = [-1 for i in range(256)]
        for i in range(len(s)):
            if dict[ord(s[i])] != -1:
                while start <= dict[ord(s[i])]:
                    dict[ord(s[start])] = -1
                    start += 1
            if i - start + 1 > maxlen:
                maxlen = i - start + 1
            dict[ord(s[i])] = i
        return maxlen

    def lengthOfLongestSubstring_3(self, s):
        start = 0
        maxlen = 0
        dict = {}
        for i in range(len(s)):
            dict[s[i]] = -1
        for i in range(len(s)):
            if dict[s[i]] != -1:  # s[i] is repeating
                while start <= dict[s[i]]:
                    dict[s[start]] = -1
                    start += 1
            if i - start + 1 > maxlen:
                maxlen = i - start + 1
            dict[s[i]] = i
        return maxlen



s = Solution()
s.lengthOfLongestSubstring("pwwkew")