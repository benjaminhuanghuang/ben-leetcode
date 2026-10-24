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