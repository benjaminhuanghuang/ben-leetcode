package cn.huang.leetcode;

/*
696. Count Binary Substrings
Give a string s, moves the number of non-empty (contiguous) substrings that have the same number of 0's and 1's,0
and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.


 */
public class LC_0696_CountBinarySubstrings {
    public int countBinarySubstrings(String s) {
        int result = 0;
        int prevLength = 0;
        int curLength = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                curLength++;
            } else {
                prevLength = curLength;
                curLength = 1;
            }
            if (prevLength >= curLength) {
                result++;
            }
        }
        return result;
    }
}
