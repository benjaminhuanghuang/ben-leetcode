package cn.huang.leetcode;

/*
409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be
built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */
public class LC_0409_LongestPalindrome {
    //统计所有的字母，最终等于所有的出现为偶数的次数+所有奇数的次数-（奇数的个数 - 1）,如果没有奇数则不减
    public int longestPalindrome(String s) {
        char chars[] = s.toCharArray();
        int lowerCount[] = new int[26];
        int upperCount[] = new int[26];
        int odds = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (chars[i] < 'a')
                upperCount[chars[i] - 'A']++;
            else
                lowerCount[chars[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (lowerCount[i] % 2 == 1) odds++;
            if (upperCount[i] % 2 == 1) odds++;
        }
        if (odds == 0)
            return n;
        else
            return n - odds + 1;
    }

    public int longestPalindrome_Better(String s) {
        char chars[] = s.toCharArray();
        int count[] = new int[128];
        int odds = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[chars[i]]++;
        }

        for (int i = 0; i < 128; i++) {
            if (count[i] % 2 == 1) odds++;
        }
        if (odds == 0)
            return n;
        else
            return n - odds + 1;
    }
}
