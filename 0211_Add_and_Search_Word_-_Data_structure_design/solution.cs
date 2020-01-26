/*
211. Add and Search Word

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

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

# 208. Implement Trie
*/
/*
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
*/
public class WordDictionary {
    private TrieNode root;

    public WordDictionary()
    {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    public void AddWord(string word) {
        TrieNode cur = root;
        foreach (var ch in word){
            if (!cur.Neighbors.ContainsKey(ch)) {
                cur.Neighbors.Add(ch, new TrieNode(ch));
            }
            cur = cur.Neighbors[ch];
        }
        cur.IsEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public bool Search(string word) {
        TrieNode cur = root;
        int len = word.Length;
        return dfs(root, word, 0, len);
    }

    private bool dfs(TrieNode node, string word, int pos, int len) {
        if (node == null || (pos == len && !node.IsEnd))
                return false;
        if (pos == len && node.IsEnd)
            return true;
        if (word[pos] == '.') {
            foreach (var ky in node.Neighbors ) {
                bool re = dfs(ky.Value, word, pos + 1, len);
                if (re)
                    return re;
            }
            return false;
        } 
        else 
        {
            if (!node.Neighbors.ContainsKey(word[pos]))
                return false;
            return dfs(node.Neighbors[word[pos]], word, pos + 1, len);
        }
    }
}