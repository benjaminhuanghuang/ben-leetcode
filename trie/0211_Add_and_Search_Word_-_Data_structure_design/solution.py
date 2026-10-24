'''
211. Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only
letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
'''

import collections


class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.dic = collections.defaultdict(list)

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        n = len(word)
        self.dic[n].append(word)

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        n = len(word)
        if n not in self.dic.keys():
            return False
        res = 0
        for w in self.dic[n]:
            if self.is_match(word, w):
                res += 1
        return res > 0

    def is_match(self, word1, word2):
        for i, c in enumerate(word1):
            if c != "." and c != word2[i]:
                return False
        return True


class TrieNode(object):
    def __init__(self):
        self.is_leaf = False
        self.children = [None] * 26


# http://www.jiuzhang.com/solutions/add-and-search-word/
class WordDictionary_tire(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.root = TrieNode()
        self.size = 0

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        if len(word) == 0:
            return
        p = self.root
        i = 0
        while i < len(word):
            if p.children[ord(word[i]) - ord('a')] is None:
                new_node = TrieNode()
                p.children[ord(word[i]) - ord('a')] = new_node
            p = p.children[ord(word[i]) - ord('a')]
            i += 1
        p.leaf = True
        self.size += 1

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        if len(word) == 0:
            return False
        return self.searchRe(word, self.root, 0)

    def searchRe(self, s, p, i):
        if len(s) == i:
            if p.leaf:
                return True
            return False

        result = False
        if s[i] == '.':
            for j in range(0, 26):
                if p.children[j] != None:
                    if self.searchRe(s, p.children[j], i + 1):
                        result = True
        else:
            if p.children[ord(s[i]) - ord('a')] != None:
                if self.searchRe(s, p.children[ord(s[i]) - ord('a')], i + 1):
                    result = True
        return result
