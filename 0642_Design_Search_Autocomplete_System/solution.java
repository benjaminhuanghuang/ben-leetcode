package cn.huang.leetcode;

import java.util.*;

/*
642. Design Search Autocomplete System

 */
public class LC_0642_DesignSearchAutocompleteSystem {
    class AutocompleteSystem {
        class TrieNode {
            public boolean isEnd;
            public Map<String, Integer> freq;
            public Map<Character, TrieNode> children; // Map is more applicable to all chars, not limited to 256 ASCII
            public TrieNode() {
                this.freq = new HashMap<>();
                this.children = new HashMap<>();
            }
        }
        class Pair {
            String s;
            int count;
            public Pair(String s, int count) {
                this.s = s;
                this.count = count;
            }
        }
        TrieNode root, curr;
        StringBuffer sb;
        public AutocompleteSystem(String[] sentences, int[] times) {
            if (sentences == null || times == null || sentences.length != times.length) return;
            reset();
            root = new TrieNode();
            for (int i = 0; i < times.length; i++) {
                insert(sentences[i], times[i]);
            }
        }

        public List<String> input(char c) {
            List<String> rst = new ArrayList<>();
            if (curr == null) curr = root;
            if (c == '#') { // save sentence and reset state
                insert(sb.toString(), 1);
                reset();
                return rst;
            }

            // Update global variable (curr TrieNode and string buffer); or append new character if not exist.
            sb.append(c);
            curr.children.putIfAbsent(c, new TrieNode());
            curr = curr.children.get(c);

            // MinHeap to find top 3.
            rst.addAll(findTopK(curr, 3));

            return rst;
        }

        private List<String> findTopK(TrieNode node, int k) {
            List<String> rst = new ArrayList<>();
            if (node.freq.isEmpty()) return rst;
            PriorityQueue<Pair> queue = new PriorityQueue<>(
                    (a, b) -> a.count == b.count ? b.s.compareTo(a.s) : a.count - b.count);
            for (Map.Entry<String, Integer> entry : node.freq.entrySet()) {
                if (queue.size() < 3 || entry.getValue() >= queue.peek().count) {
                    queue.offer(new Pair(entry.getKey(), entry.getValue()));
                }
                if (queue.size() > 3) queue.poll();
            }

            while (!queue.isEmpty()) {
                rst.add(0, queue.poll().s);
            }

            return rst;
        }

        private void reset() {
            curr = null;
            sb = new StringBuffer();
        }

        private void insert(String sentence, int count) {
            if (sentence == null || sentence.length() == 0) return;
            TrieNode node = root;
            for (char c : sentence.toCharArray()) {
                node.children.putIfAbsent(c, new TrieNode());
                node = node.children.get(c);
                node.freq.put(sentence, node.freq.getOrDefault(sentence, 0) + count);
            }
            node.isEnd = true; // can set word to node as well, if needed
        }
    }
}
