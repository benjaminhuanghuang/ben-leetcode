package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
522. Longest Uncommon Subsequence II

 Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon
 subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any
 subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the
order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.
If the longest uncommon subsequence doesn't exist, return -1.

Example 1:

Input: "aba", "cdc", "eae"
Output: 3

Note:

    All the given strings' lengths will not exceed 10.
    The length of the given list will be in the range of [2, 50].

 */
public class LC_0522_LongestUncommonSubsequence_II {
    public int findLUSlength(String[] strs) {
        HashMap<String, Integer> map = new HashMap();
        for (String str : strs) {
            HashSet<String> set = getSubs(str);
            for (String s : set) {
                map.put(s, map.getOrDefault(s, 0) + 1);
            }
        }
        int res = -1;
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            if (e.getValue() == 1) {
                res = Math.max(res, e.getKey().length());
            }
        }
        return res;
    }

    private HashSet<String> getSubs(String s) {
        HashSet<String> res = new HashSet();
        if (s.length() == 0) {
            res.add("");
        } else {
            Set<String> set = getSubs(s.substring(1));
            res.addAll(set);
            for (String str : set) {
                res.add(s.charAt(0) + str);
            }
        }
        return res;
    }
}
