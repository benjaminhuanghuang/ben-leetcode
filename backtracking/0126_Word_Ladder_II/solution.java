package cn.huang.leetcode;

import java.util.*;

/*
126. Word Ladder II

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s)
from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return an empty list if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

 */
public class LC_0126_WordLadder_II {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);

        // it is not necessary, bit it is good to add beginWord into the set,
        // so that we will have a complet graph that conrtains all nodes
        wordSet.add(beginWord);
        List<List<String>> res = new ArrayList<>();

        if (!wordSet.contains(endWord)) {
            return res;
        }

        List<String> path = new ArrayList<>();
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> dist = new HashMap<>();

        bfs(graph, dist, beginWord, endWord, wordSet);
        dfs(res, path, endWord, beginWord, dist, graph);

        return res;
    }

    // 利用BFS构建一幅图 adjacency list 表示
    public static void bfs(Map<String, List<String>> graph, Map<String,
            Integer> dist, String beginWord,
                           String endWord, Set<String> wordSet) {

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        dist.put(beginWord, 0);

        for (String w : wordSet) {
            graph.put(w, new ArrayList<String>());
        }

        while (!queue.isEmpty()) {
            String word = queue.poll();
            List<String> neighbors = getNeighbors(word, wordSet);
            for (String neighbor : neighbors) {
                graph.get(neighbor).add(word);
                if (!dist.containsKey(neighbor)) {
                    dist.put(neighbor, dist.get(word) + 1);
                    queue.offer(neighbor);
                }
            }
        }
    }


    // 利用深度优先搜多找出所有的最短路径
    public static void dfs(List<List<String>> res, List<String> path,
                           String word, String beginWord,
                           Map<String, Integer> dist, Map<String,
            List<String>> graph) {

        if (word.equals(beginWord)) {
            path.add(0, word);
            res.add(new ArrayList<String>(path));
            path.remove(0);
            return;
        }

        for (String neighbor : graph.get(word)) {
            if (dist.containsKey(neighbor) && dist.get(word) == dist.get(neighbor) + 1) {
                path.add(0, word);
                dfs(res, path, neighbor, beginWord, dist, graph);
                path.remove(0);
            }
        }

    }

    static List<String> getNeighbors(String word, Set<String> wordSet) {
        List<String> res = new ArrayList<String>();
        for (int i = 0; i < word.length(); i++) {
            for (char ch = 'a'; ch < 'z' + 1; ch++) {
                char[] chs = word.toCharArray();
                if (ch != chs[i]) {
                    chs[i] = ch;
                    String next = new String(chs);
                    //System.out.println(next);
                    if (wordSet.contains(next)) {
                        res.add(next);
                    }
                }
            }
        }
        return res;
    }
}
