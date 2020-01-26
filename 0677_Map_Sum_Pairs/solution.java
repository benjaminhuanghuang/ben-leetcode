package cn.huang.leetcode;

import java.util.HashMap;

/*
677. Map Sum Pairs

 Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer
represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs'
value whose key starts with the prefix.

Example 1:

Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5

 */
public class LC_0677_MapSumPairs {
    class MapSum1 {
        HashMap<String, Integer> map;

        public MapSum1() {
            map = new HashMap<>();
        }

        public void insert(String key, int val) {
            map.put(key, val);
        }

        public int sum(String prefix) {
            int sum = 0;
            for (String s : map.keySet()) {
                if (s.startsWith(prefix)) {  // startWith = prefix
                    sum += map.get(s);
                }
            }
            return sum;
        }
    }

    class TrieNode {
        public TrieNode[] children = new TrieNode[26];
        public int value;   // only valid when finished == true
        public boolean finished;

        // Initialize your data structure here.
        public TrieNode() {
            finished = false;
            value = 0;
        }
    }

    class MapSum {
        private TrieNode root;

        /**
         * Initialize your data structure here.
         */
        public MapSum() {
            root = new TrieNode();
        }

        public void insert(String key, int val) {
            TrieNode node = root;
            for (int i = 0; i < key.length(); ++i) {
                int index = key.charAt(i) - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.finished = true;
            node.value = val;
        }

        public int sum(String prefix) {
            TrieNode node = root;
            for (int i = 0; i < prefix.length(); ++i) {
                int index = prefix.charAt(i) - 'a';
                if (node.children[index] == null) {
                    return 0;
                }
                node = node.children[index];
            }
            return DFS(node);
        }

        int DFS(TrieNode node) {
            if (node == null) {
                return 0;
            }
            int ret = 0;
            if (node.finished) {
                ret += node.value;
            }
            for (int i = 0; i < 26; ++i) {
                ret += DFS(node.children[i]);
            }
            return ret;
        }
    }
}
