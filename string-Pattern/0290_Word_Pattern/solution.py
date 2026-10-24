'''
290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


'''


class Solution(object):
    #  Wrong answer for case: "abba" "dog dog dog dog"
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """

        if not pattern or not str:
            return True

        words = str.split(" ")
        if len(pattern) != len(words):
            return False

        dic = {}
        for i in range(len(pattern)):
            word = words[i]
            p = pattern[i]
            if not p in dic.keys():
                dic[p] = word
            else:
                if dic[p] != word:
                    return False

        return True

    def wordPattern_2(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """

        if not pattern or not str:
            return False

        words = str.split(" ")
        if len(pattern) != len(words):
            return False

        pdict = {}
        wdict = {}
        for p, w in zip(pattern, words):
            if p not in pdict:
                pdict[p] = w
            if w not in wdict:
                wdict[w] = p
            if pdict[p] != w or wdict[w] != p:
                return False
        return True


s = Solution()
print  s.wordPattern("abba", "dog dog dog dog")

print  s.wordPattern_2("", "beef")
