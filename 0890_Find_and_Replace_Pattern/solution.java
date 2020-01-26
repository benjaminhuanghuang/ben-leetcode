package cn.huang.leetcode;

import java.util.*;

/*
890. Find and Replace Pattern

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.



Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 */
public class LC_0890_FindandReplacePattern {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        int[] patternPos = getStrPos(pattern);
        List<String> retList = new ArrayList<>();
        for (String word : words) {
            if (Arrays.equals(getStrPos(word), patternPos))
                retList.add(word);
        }
        return retList;
    }

    private int[] getStrPos(String str) {
        Map<Character, Integer> posMap = new HashMap<>();
        char[] arr = str.toCharArray();
        int[] posArr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (posMap.get(arr[i]) == null) {
                posMap.put(arr[i], i);
            }
            posArr[i] = posMap.get(arr[i]);
        }
        return posArr;
    }
}
