/*
212. Word Search II [Hard]

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/
using System.Linq;
using System.Collections.Generic;

public class Solution212 {
    public class TrieNode
    {
        public bool IsEnd;
        public int index;
        public char Data;
        public Dictionary<char, TrieNode> Neighbors;
        public TrieNode()
        {
            this.IsEnd = false;
            this.Neighbors = new Dictionary<char, TrieNode>();
        }
        public TrieNode(char c)
        {
            this.IsEnd = false;
            this.Neighbors = new Dictionary<char, TrieNode>();
            this.Data = c;
        }
    }

    public class Trie
    {
        public readonly TrieNode root;

        public Trie()
        {
            root = new TrieNode();
        }

        public void Insert(string word, int i)
        {
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
            start.index = i;
        }
    }

    public IList<string> FindWords(char[,] board, string[] words) {
        var res = new HashSet<string>();
        var visited = new bool[board.GetLength(0), board.GetLength(1)];

        var trie = new Trie();
        for (var i = 0; i < words.Length; i++)
        {
            trie.Insert(words[i], i);
        }

        for (int i = 0; i < board.GetLength(0); i++)
        {
            for (int j = 0; j < board.GetLength(1); j++)
            {
                FindWordsHelper(board, i, j, visited, trie.root, res, words);
            }
        }

        return res.ToList();
    }

    private void FindWordsHelper(char[,] board, int i, int j, bool[,] visited, TrieNode root, HashSet<string> res, string[] words)
    {
        if (visited[i, j]) return;
        if (!root.Neighbors.ContainsKey(board[i, j])) return;

        if (root.Neighbors[board[i, j]].IsEnd)
        {
            res.Add(words[root.Neighbors[board[i,j]].index]);
        }

        visited[i, j] = true;

        if (i > 0)
        {
            this.FindWordsHelper(board, i - 1, j, visited, root.Neighbors[board[i,j]], res, words);
        }
        if (i + 1 < board.GetLength(0))
        {                 
            this.FindWordsHelper(board, i + 1, j, visited, root.Neighbors[board[i,j]], res, words);             
        }             
        if (j > 0)
        {
            this.FindWordsHelper(board, i, j - 1, visited, root.Neighbors[board[i, j]], res, words);                
        }
        if (j + 1 < board.GetLength(1))
        {
            this.FindWordsHelper(board, i, j + 1, visited, root.Neighbors[board[i, j]], res, words);                
        }

        visited[i, j] = false;
    }

}