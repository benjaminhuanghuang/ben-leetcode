package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting
 of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []


 */
public class LC_0030_SubstringwithConcatenationofAllWords {
    /*
    Time O(n ^2) s.length * words.length
    Space O(n)   words.length
     */
    public List<Integer> findSubstring(String s, String[] words) {
        if (s == null || s.length() == 0 || words.length ==0 )
            return new ArrayList<>();

        List<Integer> res = new ArrayList<>();
        int n = words.length;    // how many words
        int m = words[0].length();  // length of word

        Map<String, Integer> map = new HashMap<>();

        for (String str : words) {
            map.put(str, map.getOrDefault(str, 0) + 1);
        }

        for (int i = 0; i <= s.length() - n * m; i++) {
            Map<String, Integer> copy = new HashMap<>(map);
            int count = n;
            int start = i;
            while (count > 0) {
                String word = s.substring(start, start + m);
                if (!copy.containsKey(word) || copy.get(word) < 1) {
                    // word is not in words list
                    break;
                }
                copy.put(word, copy.get(word) - 1);
                count--;
                start += m;
            }
            if( count == 0)   // all words are matched
                res.add(i);
        }


        return res;
    }
}
