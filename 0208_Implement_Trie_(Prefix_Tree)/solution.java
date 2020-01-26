package cn.huang.leetcode;
/*
 208. Implement Trie (Prefix Tree)

 */


/*
https://leetcode.com/articles/implement-trie-prefix-tree/
 */
public class LC_0208_ImplementTrie_PrefixTree {
    class TrieNode {
        // Initialize your data structure here.
        int num;// 有多少单词通过这个节点,即节点字符出现的次数
        TrieNode[] children;// 所有的儿子节点
        boolean isEnd;// 是不是最后一个节点
        char val;// 节点的值

        TrieNode() {
            this.num = 0;
            this.children = new TrieNode[26];
            this.isEnd = false;
        }
    }


    class Trie {
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
            char[] letters = word.toCharArray();
            for (int i = 0; i < word.length(); i++) {
                int pos = letters[i] - 'a';
                if (node.children[pos] == null) {
                    node.children[pos] = new TrieNode();
                    node.children[pos].val = letters[i];
                } else {
                    node.children[pos].num++;
                }
                node = node.children[pos];
            }
            node.isEnd = true;
        }

        private TrieNode searchPrefix(String word) {
            TrieNode node = root;
            for (int i = 0; i < word.length(); i++) {
                char curLetter = word.charAt(i);
                int pos = curLetter - 'a';
                if (node.children[pos] != null) {
                    node = node.children[pos];
                } else {
                    return null;
                }
            }
            return node;
        }
        public boolean search(String word) {
            if (word == null || word.length() == 0) {
                return false;
            }
            TrieNode node = root;
            char[] letters = word.toCharArray();
            for (int i = 0; i < word.length(); i++) {
                int pos = letters[i] - 'a';
                if (node.children[pos] != null) {
                    node = node.children[pos];
                } else {
                    return false;
                }
            }
            return node.isEnd;
        }
        /** Returns if the word is in the trie. */
        public boolean search2(String word) {
            if (word == null || word.length() == 0) {
                return false;
            }
            TrieNode node = root;
            char[] letters = word.toCharArray();
            for (int i = 0; i < word.length(); i++) {
                int pos = letters[i] - 'a';
                if (node.children[pos] != null) {
                    node = node.children[pos];
                } else {
                    return false;
                }
            }
            return node.isEnd;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        public boolean startsWith(String prefix) {
            if (prefix == null || prefix.length() == 0) {
                return false;
            }
            TrieNode node = root;
            char[] letters = prefix.toCharArray();
            for (int i = 0; i < prefix.length(); i++) {
                int pos = letters[i] - 'a';
                if (node.children[pos] != null) {
                    node = node.children[pos];
                } else {
                    return false;
                }
            }
            return true;
        }
    }
}
