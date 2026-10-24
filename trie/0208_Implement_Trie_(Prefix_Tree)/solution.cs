/*
208. Implement Trie

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
// Each node in Trie would be like node in directly graph. 
// node with data and its neighbors. Use dictionary to store all its neighbors would 
// save lots of time for searching. And we need a Boolean to indicate it is the terminate of word or not.

using System.Collections.Generic;

class TrieNode {
    // Initialize your data structure here.
    public char Data;
    public bool IsEnd;
    public Dictionary<char, TrieNode> Neighbors;
    public TrieNode()
    {
        this.Data = '#';
        this.IsEnd = true;
        this.Neighbors = new Dictionary<char, TrieNode>();
    }

    public TrieNode(char ch)
    {
        this.Data = ch;
        this.IsEnd = false;
        this.Neighbors = new Dictionary<char, TrieNode>();
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void Insert(string word) {
        var start = root;
        foreach (var ch in word)
        {
            if (!start.Neighbors.ContainsKey(ch))
            {
                var newnode = new TrieNode(ch);
                start.Neighbors.Add(ch, newnode);
            }

            start = start.Neighbors[ch];
        }

        start.IsEnd = true;
    }

    // Returns if the word is in the trie.
    public bool Search(string word) {
        var start = root;
        foreach (var ch in word)
        {
            if (!start.Neighbors.ContainsKey((ch)))
            {
                return false;
            }

            start = start.Neighbors[ch];
        }

        return start.IsEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public bool StartsWith(string word) {
        var start = root;
        foreach (var ch in word)
        {
            if (!start.Neighbors.ContainsKey((ch)))
            {
                return false;
            }

            start = start.Neighbors[ch];
        }

        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.Insert("somestring");
// trie.Search("key");