package cn.huang.leetcode;

import java.util.List;

/*
524. Longest Word in Dictionary through Deleting

 Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some
 characters of the given string. If there are more than one possible results, return the longest word with the smallest
 lexicographical order. If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"

Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"

Note:

    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.

 */
public class LC_0524_LongestWordinDictionarythroughDeleting {

    public String findLongestWord(String s, List<String> d) {
        String max_str = "";
        for (String dicWord : d) {
            if (isSubSeq(s, dicWord)) {
                if (dicWord.length() > max_str.length() || (dicWord.length() == max_str.length() && dicWord.compareTo(max_str) < 0))
                    max_str = dicWord;
            }
        }
        return max_str;
    }

    private boolean isSubSeq(String s, String p) {
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (s.charAt(i) == p.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == p.length();

    }
}
