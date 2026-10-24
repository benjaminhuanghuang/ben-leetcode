package cn.huang.leetcode;
/*
 208. Implement Trie (Prefix Tree)


 https://leetcode.com/articles/implement-trie-prefix-tree/

*/

/*
http://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
*/
public class LC_0208_ImplementTrie_PrefixTree {
  class Trie {
    class TrieNode {
      TrieNode[] children;
      boolean isWord;
  
      TrieNode() {
        this.children = new TrieNode[26];
        this.isEnd = false;
      }
    }

    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
      root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
      if (word == null || word.length() == 0)
        return;
      TrieNode node = this.root;
      for (int i = 0; i < word.length(); i++) {
        int pos =  (int)(word.charAt(i) - 'a');
        if (node.children[pos] == null) {
          node.children[pos] = new TrieNode();
        }
        node = node.children[pos];
      }
      node.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
      TrieNode node = find(word);
      return node != null && node.isWord;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
      TrieNode node = find(prefix);
      return node != null;
    }

    private TrieNode find(String prefix) {
      TrieNode p = root;
      for(int i = 0; i < prefix.length(); i++) {
          int index = (int)(prefix.charAt(i) - 'a');
          if (p.children[index] == null) 
            return null;
          p = p.children[index];
      }
      return p;
    }
  }
}
