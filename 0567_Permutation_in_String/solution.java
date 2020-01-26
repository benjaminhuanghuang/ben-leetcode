package cn.huang.leetcode;

/*
567. Permutation in String

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].

 */
public class LC_0567_PermutationinString {
    /*
    每次s2中截取和s1等长的字符串，与s1进行比较，利用数组来统计a-z的数量，辅助比较。
     */
    public boolean checkInclusion(String s1, String s2) {

        if (s1.length() > s2.length()) {
            return false;
        }
        int[] chars1 = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            chars1[s1.charAt(i) - 'a']++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            String target = s2.substring(i, i + s1.length());
            if (helper(chars1, target)) {
                return true;
            }
        }
        return false;
    }

    public boolean helper(int[] chars1, String target) {
        int[] temp = new int[26];
        for (int i = 0; i < chars1.length; i++) {
            temp[i] = chars1[i];
        }
        for (int i = 0; i < target.length(); i++) {
            if (temp[target.charAt(i) - 'a'] > 0) {
                temp[target.charAt(i) - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
}
