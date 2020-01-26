package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

/*
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false


 */


public class LC_0139_WordBreak {
    /*
    // Use dp[i] as the sub string s[0:i] can be segmented into a space-separated sequence of one or more dictionary words.
    // put dp[0] as empty string and it is true.
    // dp[k] =  dp[0] + string(0 ~ k) in dict; dp[1] + string(1 ~ k) in dict
    // 如果s[j:i]在给定的字符串组中 && dp[j]为True（即字符串s[:j]能够拆分成符合要求的子字符串），那么此时dp[i]也就为True了。
     */
    public boolean wordBreak(String s, List<String> wordDict) {
        if (wordDict == null || s == null) {
            return false;
        }

        int count = s.length();
        boolean[] dp = new boolean[count + 1];
        dp[0] = true;

        for (int i = 1; i <= dp.length; i++) {
            for (int j = 0; j < i; j++) {
                String word = s.substring(j, i); //the ending index, exclusive.
                // dp[j] is true and s[j:i] in wordDict
                if (wordDict.contains(word) && dp[j]) {
                    dp[i] = true;
                }
            }
        }

        return dp[count];
    }

    /*
    https://www.youtube.com/watch?v=ptlwluzeC1I
    */
    public boolean wordBreak_recursion(String s, List<String> wordDict) {
        // Hashset for fast query
        HashSet<String> set = new HashSet<>(wordDict);

        return wordBreakHelper(s, set);
    }

    private boolean wordBreakHelper(String s, HashSet<String> wordDict) {
        if (mem.containsKey(s))
            return mem.get(s);

        if (wordDict.contains(s)) {
            mem.put(s, true);
            return true;
        }

        for (int j = 1; j < s.length(); j++) {
            String left = s.substring(0, j);  // exclude j
            String right = s.substring(j);

            if (wordDict.contains(right) && wordBreakHelper(left, wordDict)) {
                mem.put(s, true);
                return true;
            }
        }

        mem.put(s, false);
        return false;
    }

    private Map<String, Boolean> mem = new HashMap<>();
}
