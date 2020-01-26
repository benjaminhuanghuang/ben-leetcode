package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/*
737. Sentence Similarity II
 */
public class LC_0737_SentenceSimilarity_II {
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, String[][] pairs) {
        if (words1.length != words2.length) {
            return false;
        }
        // Build the graph of pairs
        HashMap<String, Set<String>> pairMap = new HashMap<>();
        for (String[] pair : pairs) {
            // Create keys(words in [][]pairs without duplication) and empty set
            if (!pairMap.containsKey(pair[0])) {
                pairMap.put(pair[0], new HashSet<String>());
            }
            if (!pairMap.containsKey(pair[1])) {
                pairMap.put(pair[1], new HashSet<String>());
            }
            // Add the corresponding pairs to each other
            pairMap.get(pair[0]).add(pair[1]);
            pairMap.get(pair[1]).add(pair[0]);
        }

        // Iterate throught each word in both input strings and do DFS search
        for (int i = 0; i < words1.length; i++) {
            // If same, then we don't need to do DFS search
            if (words1[i].equals(words2[i])) continue;
            // If they are not the same and no such strings in the pairs
            if (!pairMap.containsKey(words1[i]) || !pairMap.containsKey(words2[i])) return false;
            // Do DFS search, initialize the set to prevent revisiting.
            if (!dfs(words1[i], words2[i], pairMap, new HashSet<>())) return false;
        }
        return true;
    }

    public boolean dfs(String source, String target, HashMap<String, Set<String>> pairMap, HashSet<String> visited) {
        if (pairMap.get(source).contains(target)) {
            return true;
        }
        // Mark as visited
        visited.add(source);
        for (String next : pairMap.get(source)) {
            // DFS other connected node, except the mirrowed string
            if (!visited.contains(next) && next.equals(target) ||
                    !visited.contains(next) && dfs(next, target, pairMap, visited)) {
                return true;
            }
        }
        // We've done dfs still can't find the target
        return false;
    }
}
