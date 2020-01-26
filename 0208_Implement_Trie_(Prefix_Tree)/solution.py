'''
208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

'''

import collections


class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.isWord = False  # this node is end of a word


class Trie(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        node = self.root
        for c in word:
            if not c in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.isWord = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.root
        for c in word:
            if not c in node.children:
                return False
            node = node.children[c]
        return node.isWord

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        for c in prefix:
            if not c in node.children:
                return False
            node = node.children[c]
        return True


trie = Trie()
print trie.insert("abc")
print trie.search("abc")
print trie.search("ab")
print trie.insert("ab")
print trie.search("ab")
print trie.insert("ab")
print trie.search("ab")
