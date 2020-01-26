package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
820. Short Encoding of Words
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].



Note:

    1 <= words.length <= 2000.
    1 <= words[i].length <= 7.
    Each word has only lowercase letters.


 */
public class LC_0820_ShortEncodingofWords {
    class TrieNode {
        char ch;
        boolean isLeaf;
        TrieNode[] nextNode = new TrieNode[26];

        public TrieNode(char cCh) {
            ch = cCh;
        }
    }

    class Trie {
        TrieNode root;

        public Trie() {
            root = new TrieNode('?');
        }

        public void insert(String s) {
            TrieNode curNode = root;
            for (int i = 0; i < s.length(); i++) {
                if (curNode.nextNode[s.charAt(i) - 'a'] == null)
                    curNode.nextNode[s.charAt(i) - 'a'] = new TrieNode(s.charAt(i));
                curNode = curNode.nextNode[s.charAt(i) - 'a'];
            }
            curNode.isLeaf = true;
        }
    }

    int res = 0;

    /*
    将word翻转 插入 trie中。
    最后统计tire 中所有 叶子的深度 + 1 (’#’)
     */
    public int minimumLengthEncoding(String[] words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert((new StringBuilder(word)).reverse().toString());
        }
        calStringLen(trie.root, 0);
        return res;
    }

    public void calStringLen(TrieNode root, int level) {
        if (root == null)
            return;

        boolean isTreeLeaf = true;
        for (int i = 0; i < 26; i++) {
            if (root.nextNode[i] != null) {
                calStringLen(root.nextNode[i], level + 1);
                isTreeLeaf = false;
            }
        }
        if (isTreeLeaf)
            res += level + 1;
    }

    /*
    将所有word 放入set中，然后遍历所有set中的word，将word的从头的子串都从set中删除，最后统计 set中所有（word 的长度 + 1）(’#’)
     */
    public int minimumLengthEncoding2(String[] words) {
        Set<String> set = new HashSet(Arrays.asList(words));
        for (String word : words) {
            for (int i = 1; i < word.length(); i++) {
                set.remove(word.substring(i));
            }
        }
        int res = 0;
        for (String word : set) {
            res += word.length() + 1;
        }
        return res;
    }
}
