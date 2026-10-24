package cn.huang.leetcode;

/*
243	 Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
 */
public class LC_0243_ShortestWordDistance {
    public int shortestDistance(String[] words, String word1, String word2) {
        int index1 = -1;
        int index2 = -1;

        int min = Integer.MAX_VALUE;

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (word1.equals(word)) {
                index1 = i;
                if (index2 != -1)
                    min = Math.min(min, index1 - index2);
            } else if (word2.equals(word)) {
                index2 = i;
                if (index1 != -1)
                    min = Math.min(min, index2 - index1);
            }
        }

        return min;
    }
}
