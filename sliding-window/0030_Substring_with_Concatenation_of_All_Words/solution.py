'''
30. Substring with Concatenation of All Words [Hard]

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices
of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).


'''


class Solution(object):
    # http://www.jiuzhang.com/solutions/substring-with-concatenation-of-all-words/
    # http://blog.csdn.net/wwh578867817/article/details/46487183
    def findSubstring(self, s, words):
        hash = {}
        res = []
        word_size = len(words[0])

        for word in words:
            if word in hash:
                hash[word] += 1
            else:
                hash[word] = 1

        for start in range(0, len(words[0])):
            slidingWindow = {}
            wCount = 0
            for i in range(start, len(s), word_size):
                word = s[i: i + word_size]
                if word in hash:
                    if word in slidingWindow:
                        slidingWindow[word] += 1
                    else:
                        slidingWindow[word] = 1
                    wCount += 1
                    while hash[word] < slidingWindow[word]:
                        pos = i - word_size * (wCount - 1)
                        removeWord = s[pos: pos + word_size]
                        print i, removeWord
                        slidingWindow[removeWord] -= 1
                        wCount -= 1
                else:
                    slidingWindow.clear()
                    wCount = 0
                if wCount == len(words):
                    res.append(i - word_size * (wCount - 1))

        return res

    # http://wulc.me/2016/04/04/LeetCode%E8%A7%A3%E9%A2%98%E6%8A%A5%E5%91%8A(30.%20Substring%20with%20Concatenation%20of%20All%20Words)/
    def findSubstring_1(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        wordDict = {}
        for word in words:
            if word in wordDict:
                wordDict[word] += 1
            else:
                wordDict[word] = 1

        wordLen = len(words[0])
        wordNum = len(words)
        result = []

        for i in range(len(s) - wordLen * wordNum + 1):
            tmp = s[i:i + wordLen]
            tmpDict = {}
            if tmp in words:
                head = i
                while tmp in words and i < len(s) - wordLen + 1:
                    if tmp in tmpDict:
                        tmpDict[tmp] += 1
                    else:
                        tmpDict[tmp] = 1

                    if tmpDict[tmp] > wordDict[tmp]:
                        tmpDict[tmp] -= 1
                        break

                    i += wordLen
                    tmp = s[i:i + wordLen]
                if tmpDict == wordDict:
                    result.append(head)
            else:
                continue
        return result
        # http://wulc.me/2016/04/04/LeetCode%E8%A7%A3%E9%A2%98%E6%8A%A5%E5%91%8A(30.%20Substring%20with%20Concatenation%20of%20All%20Words)/


s = "barfoothefoobarman"
words = ["foo", "bar"]

s = "barfoofoobarthefoobarman"
words = ["bar", "foo", "the"]

sol = Solution()
print sol.findSubstring_1(s, words)
"""
:type s: str
:type words: List[str]
:rtype: List[int]
"""
