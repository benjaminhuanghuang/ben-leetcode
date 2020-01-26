/*
243. Shortest Word Distance 
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/
using System;

public class Solution243 {
    public int shortestDistance(String[] words, String word1, String word2) {
        int idx1 = -1, idx2 = -1, distance = Int32.MaxValue;
        for(int i = 0; i < words.Length; i++){
            if(words[i] == word1){
                idx1 = i;
                // 第一次写入idx就先不比较
                if(idx2 != -1)
                {
                    distance = Math.Min(distance, idx1 - idx2);
                    break;
                }
            }
            if(words[i] == word2){
                idx2 = i;
                // 第一次写入idx就先不比较
                if(idx1 != -1)
                {
                    distance = Math.Min(distance, idx2 - idx1);
                    break;
                }
            }
        }
        return distance;
    }
}