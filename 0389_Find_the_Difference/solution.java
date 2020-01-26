package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    389. Find the Difference
 */
public class LC_0389_FindtheDifference {
    public char findTheDifference(String s, String t) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            ret -= (int) s.charAt(i);
        }
        for (int i = 0; i < t.length(); i++) {
            ret += (int) t.charAt(i);
        }
        return (char) ret;
    }

    public char findTheDifference2(String s, String t) {
        int[] nums = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            ++nums[ch - 'a'];
        }
        char ret = 'a';
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            --nums[ch - 'a'];
            if (nums[ch - 'a'] < 0) {
                ret = ch;
                break;
            }
        }
        return ret;
    }

    public char findTheDifference3(String s, String t) {
        char ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans ^= s.charAt(i);
        }
        for (int i = 0; i < t.length(); i++) {
            ans ^= t.charAt(i);
        }
        return ans;
    }
}

