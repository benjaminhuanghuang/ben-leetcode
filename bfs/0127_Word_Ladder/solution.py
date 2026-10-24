'''
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Hints:
http://blog.csdn.net/qq508618087/article/details/51344102

'''

import Queue


class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if not wordList or len(wordList) == 0:
            return 0

        queue = []
        queue.append(beginWord)
        res = 1
        chars = [chr(x) for x in range(ord('a'), ord('z') + 1)]

        while queue:
            n = len(queue)

            for i in range(n):
                pop = queue.pop(0)

                for c in chars:
                    for j in range(len(pop)):
                        if c != pop[j]:
                            tmp = pop[:j] + c + pop[j + 1:]

                            if tmp == endWord:
                                return res + 1

                            if tmp in wordList:
                                queue.append(tmp)
                                wordList.remove(tmp)
            res += 1

        return 0

    def ladderLength_v1(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        if not wordList or len(wordList) == 0:
            return 0

        queue = []
        queue.append(beginWord)
        res = 1

        while queue:
            n = len(queue)

            for i in range(n):
                word = queue.pop(0)

                next_words = self.getNextWords_v1(word, wordList)
                for next_word in next_words:
                    if next_word == endWord:
                        return res + 1

                    if next_word in wordList:
                        queue.append(next_word)
                        print next_word
                        wordList.remove(next_word)
            res += 1  #

        return 0

    def getNextWords_v1(self, word, dict):
        # aToz = string.ascii_lowercase
        # a2z = [chr(x) for x in range(ord('a'), ord('z') + 1)]
        aToz = 'abcdefghijklmnopqrstuvwxyz'
        res = []
        for char in aToz:
            for j in range(len(word)):
                if word[j] == char:
                    continue
                newWord = word[:j] + char + word[j + 1:]
                res.append(newWord)
        return res

    # Problem : can not get endword when endword is not in the wordlist
    def getNextWords(self, word, dict):
        # aToz = string.ascii_lowercase
        # a2z = [chr(x) for x in range(ord('a'), ord('z') + 1)]
        aToz = 'abcdefghijklmnopqrstuvwxyz'
        res = []
        for char in aToz:
            for j in range(len(word)):
                if word[j] == char:
                    continue
                newWord = word[:j] + char + word[j + 1:]
                if newWord in dict:
                    res.append(newWord)
        return res


b = "hit"
e = "cog"
# wl = ["hot", "cog", "dot", "dog", "hit", "lot", "log"]
wl = ["hot", "dot", "dog", "lot", "log"]

s = Solution()

print s.getNextWords("hit", wl)
print s.ladderLength_v1(b, e, wl)
