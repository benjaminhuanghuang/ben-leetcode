package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/*
    205. Isomorphic Strings

    Given two strings s and t, determine if they are isomorphic.

    Two strings are isomorphic if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character while preserving the order of characters.
    No two characters may map to the same character but a character may map to itself.

    Example 1:

    Input: s = "egg", t = "add"
    Output: true
    Example 2:

    Input: s = "foo", t = "bar"
    Output: false
    Example 3:

    Input: s = "paper", t = "title"
    Output: true

 */
public class LC_0205_IsomorphicStrings {
    public boolean isIsomorphic(String s, String t) {
        if (s == null || t == null)
            return false;

        if (s.length() != t.length())
            return false;

        HashMap<Character, Character> map = new HashMap<Character, Character>();


        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            if (map.containsKey(c1)) {
                if (map.get(c1) != c2)// if not consistant with previous ones
                    return false;
            } else {
                // no map[c1]
                if (map.containsValue(c2)) //if c2 is already being mapped. Time complexity O(n) here
                    return false;
                map.put(c1, c2);
            }
        }
        return true;
    }

    public boolean isIsomorphic2(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Character> map = new HashMap<>();
        Set<Character> set = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);

            if (map.containsKey(sc)) {
                if (map.get(sc) != tc)
                    return false;
            } else {
                if (set.contains(tc)) {
                    return false;
                } else {
                    map.put(sc, tc);
                    set.add(tc);
                }
            }
        }
        return true;
    }
}
