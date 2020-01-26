package cn.huang.leetcode;

/*
245	 Shortest Word Distance III

This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
 */
public class LC_0245_ShortestWordDistance_III {
    public int shortestDistance(String[] words, String word1, String word2) {
        int index1 = -1;
        int index2 = -1;

        int min = Integer.MAX_VALUE;

        for (int i = 0; i < words.length; i++) {
            String word = words[i];

            if (word.equals(word1)) {
                index1 = i;
            } else if (word.equals(word2)) {
                index2 = i;
            }

            if (index1 != -1 && index2 != -1 && index1 != index2) {
                min = Math.min(min, Math.abs(index1 - index2));
            }

            if (word1.equals(word2)) {
                index2 = index1;
            }
        }

        return min;
    }
}
