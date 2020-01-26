package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    745. Prefix and Suffix Search

 Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix).
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:

Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1

Note:

    words has length in range [1, 15000].
    For each test case, up to words.length queries WordFilter.f may be made.
    words[i] has length in range [1, 10].
    prefix, suffix have lengths in range [0, 10].
    words[i] and prefix, suffix queries consist of lowercase letters only.

*/
public class LC_0745_PrefixandSuffixSearch {
    class WordFilter {

        Map<String, Integer> map = new HashMap<>();

        public WordFilter(String[] words) {
            int index = 0;
            for (String word : words) {
                int len = word.length();
                String[] prefixes = new String[len + 1];
                String[] suffixes = new String[len + 1];
                // 计算该单词对应的所有前后缀
                prefixes[0] = "";
                suffixes[0] = "";
                for (int i = 1; i <= len; i++) {
                    prefixes[i] = prefixes[i - 1] + word.charAt(i - 1);
                    suffixes[i] = word.charAt(len - i) + suffixes[i - 1];
                }
                // 将前后缀所有可能的组合与对应的 index 记录到 map 以供查询
                for (String prefix : prefixes) {
                    for (String suffix : suffixes) {
                        map.put(prefix + "_" + suffix, index);
                    }
                }
                index++;
            }
        }

        public int f(String prefix, String suffix) {
            String key = prefix + "_" + suffix;
            if (map.containsKey(key)) {
                return map.get(key);
            } else {
                return -1;
            }
        }
    }

    class WordFilter2 {
        Trie trie;

        public WordFilter2(String[] words) {
            trie = new Trie();
            for (int i = 0; i < words.length; i++) {
                // 遍历所有的后缀可能，并将其与该单词拼接起来，插入到 Trie 中
                StringBuilder key = new StringBuilder("{").append(words[i]);
                trie.insert(key.toString(), i);
                for (int j = 0; j < words[i].length(); j++) {
                    key.insert(0, words[i].charAt(words[i].length() - j - 1));
                    trie.insert(key.toString(), i);
                }
            }
        }

        public int f(String prefix, String suffix) {
            String key = suffix + '{' + prefix;
            return trie.prefixNumber(key);
        }

        class TrieNode {
            public TrieNode[] child;
            public int rank;

            public TrieNode() {
                this.child = new TrieNode[27];
                this.rank = -1;
            }
        }

        class Trie {
            private TrieNode root;

            public Trie() {
                root = new TrieNode();
            }

            public void insert(String word, int rank) {
                if (word == null) {
                    return;
                }
                char[] chars = word.toCharArray();
                TrieNode currNode = root;
                int index = 0;
                for (int i = 0; i < chars.length; i++) {
                    index = chars[i] - 'a';
                    if (currNode.child[index] == null) {
                        currNode.child[index] = new TrieNode();
                    }
                    currNode = currNode.child[index];
                    currNode.rank = rank;
                }
            }

            public int prefixNumber(String prefix) {
                if (prefix == null) {
                    return 0;
                }
                char[] chars = prefix.toCharArray();
                TrieNode currNode = root;
                int index = 0;
                for (int i = 0; i < chars.length; i++) {
                    index = chars[i] - 'a';
                    if (currNode.child[index] == null) {
                        return -1;
                    }
                    currNode = currNode.child[index];
                }
                return currNode.rank;
            }
        }
    }
}
