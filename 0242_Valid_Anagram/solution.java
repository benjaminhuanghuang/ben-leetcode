package cn.huang.leetcode;

/*
    242. Valid Anagram
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

    Note:
    You may assume the string contains only lowercase alphabets.

    Follow up:
    What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
public class LC_0242_ValidAnagram {
    public boolean isAnagram(String s, String t) {
        int[] sArray = new int[26];
        int[] tArray = new int[26];

        char[] sCharArr = s.toCharArray();
        for (int i = 0; i < sCharArr.length; i++) {
            int index = sCharArr[i] - 'a';
            sArray[index] += 1;
        }
        char[] tCharArr = t.toCharArray();
        for (int i = 0; i < tCharArr.length; i++) {
            int index = tCharArr[i] - 'a';
            tArray[index] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (sArray[i] != tArray[i]) return false;
        }
        return true;
    }

    public boolean isAnagram_better(String s, String t) {
        int[] times = new int[26];

        char[] sCharArr = s.toCharArray();
        for (int i = 0; i < sCharArr.length; i++) {
            int index = sCharArr[i] - 'a';
            times[index] += 1;
        }
        char[] tCharArr = t.toCharArray();
        for (int i = 0; i < tCharArr.length; i++) {
            int index = tCharArr[i] - 'a';
            times[index] -= 1;
        }

        for (int i = 0; i < 26; i++) {
            if (times[i] != 0) return false;
        }
        return true;
    }
}
