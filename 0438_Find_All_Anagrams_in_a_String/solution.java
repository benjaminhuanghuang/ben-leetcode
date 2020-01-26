package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not
be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */


public class LC_0438_FindAllAnagramsinaString {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        if (s == null || s.length() == 0 || p == null || p.length() == 0)
            return list;

        int[] hash = new int[128];
        // p中每个字符出现多少次
        for (char c : p.toCharArray()) {
            hash[c]++;
        }

        int left = 0, right = 0, count = p.length();
        while (right < s.length()) {

            if (hash[s.charAt(right)] >= 1) {
                count--;
            }
            hash[s.charAt(right)]--;
            right++;

            if (count == 0) {
                list.add(left);
            }

            if (right - left == p.length()) {

                if (hash[s.charAt(left)] >= 0) {
                    count++;
                }
                hash[s.charAt(left)]++;
                left++;

            }
        }
        return list;
    }

    /*
    https://www.youtube.com/watch?v=86fQQ7rVGxA
    */
    public List<Integer> findAnagrams2(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        if (s == null || s.length() == 0 || p == null || p.length() == 0)
            return ans;

        int[] hashS = new int[26];
        int[] hashP = new int[26];

        for (char c : p.toCharArray()) {
            hashP[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (i >= p.length())
                hashS[s.charAt(i - p.length()) - 'a']--;   // remove the char at left
            hashS[s.charAt(i) - 'a']++;       // add char at right
            if (Arrays.equals(hashP, hashS))
                ans.add(i + 1 - p.length());
        }
        return ans;
    }
}
