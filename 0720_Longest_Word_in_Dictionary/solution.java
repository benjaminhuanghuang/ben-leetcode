package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
    720. Longest Word in Dictionary
    Given a list of strings words representing an English Dictionary, find the longest word in words that can be
    built one character at a time by other words in words. If there is more than one possible answer, return the
    longest word with the smallest lexicographical order.

    If there is no answer, return the empty string.
    Example 1:
    Input:
    words = ["w","wo","wor","worl", "world"]
    Output: "world"
    Explanation:
    The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

    Example 2:
    Input:
    words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
    Output: "apple"
    Explanation:
    Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
*/
public class LC_0720_LongestWordinDictionary {
    /*

    找出其中长度最长的单词，并且该单词是由集合中其它的单词一次追加一个字符构造出来的。

    sort words，让所有words排序。

　　遍历words，遇到长度等于 1的 word 或者 这个word 去掉最后一个char 已经存在于 set：

　　　　与res 比较 留下 较长的；

　　　　把这个word 加入set。
     */
    public String longestWord(String[] words) {
        Arrays.sort(words);

        Set<String> set = new HashSet<>();
        String res = "";

        for (String word : words) {
            if (word.length() == 1 || set.contains(word.substring(0, word.length() - 1))) {
                res = word.length() > res.length() ? word : res; // keep the longer one
                set.add(word);
            }

        }

        return res;
    }
    // Trie
    //https://blog.csdn.net/liqinzhe11/article/details/78662375
}
