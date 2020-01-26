package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
472. Concatenated Words

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:

Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Note:

    The number of elements of the given array will not exceed 10,000
    The length sum of elements in the given array will not exceed 600,000.
    All the input string will only include lower case letters.
    The returned elements order does not matter.

 */
public class LC_0472_ConcatenatedWords {
    /*
    找到一个数组中所有的连接词。连接词的定义是，这个词完全由数组中已经存在的单词组成。
    把所有的单词放入HashSet中，然后每个单词去判断。判断的时候使用递归即可。
     */
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Set<String> set = new HashSet<>();
        for (String word : words) {
            if (word.length() > 0) {
                set.add(word);
            }
        }
        List<String> results = new ArrayList<>();
        for (String word : words) {
            if (word.length() > 0 && this.helper(word, set, 0)) {
                results.add(word);
            }
        }
        return results;
    }

    private boolean helper(String word, Set<String> set, int start) {
        if (start == word.length()) {
            return true;
        }
        for (int i = start + 1; i <= word.length(); i++) {
            String first = word.substring(start, i);
            if (set.contains(first) && !first.equals(word)) {
                if (this.helper(word, set, i)) {
                    return true;
                }
            }
        }
        return false;
    }
}
