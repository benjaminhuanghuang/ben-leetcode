package cn.huang.leetcode;
/*
880. Decoded String at Index

An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one
character at a time and the following steps are taken:

    If the character read is a letter, that letter is written onto the tape.
    If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.

Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.



Example 1:

Input: S = "leet2code3", K = 10
Output: "o"
Explanation:
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

Example 2:

Input: S = "ha22", K = 5
Output: "h"
Explanation:
The decoded string is "hahahaha".  The 5th letter is "h".

Example 3:

Input: S = "a2345678999999999999999", K = 1
Output: "a"
Explanation:
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".



Note:

    2 <= S.length <= 100
    S will only contain lowercase letters and digits 2 through 9.
    S starts with a letter.
    1 <= K <= 10^9
    The decoded string is guaranteed to have less than 2^63 letters.


 */

/*
用size表示在i处，字符串进行解码后的长度。
如果有一个解码后的字符串为appleappleappleappleappleapple，且K=24，那么答案相当于在字符串apple中求K = 4的字符。即size=26,K=24的问题可转化为size=5，K=4的问题。
利用这一点可以先找到刚好size>=K的位置，再反向遍历S，不断化简问题，最后求得答案。

 */
public class LC_0880_DecodedStringatIndex {
    public String decodeAtIndex(String S, int K) {
        long size = 0;
        int N = S.length();
        for (int i = 0; i < N; ++i) {
            char c = S.charAt(i);
            if (Character.isDigit(c)) size *= c - '0';
            else size++;
        }
        for (int j = N - 1; j >= 0; --j) {
            char s = S.charAt(j);
            K %= size;
            if (K == 0 && Character.isLetter(s)) {
                return Character.toString(s);
            }
            if (Character.isDigit(s)) {
                size /= (s - '0');
            } else {
                size--;
            }
        }
        return null;
    }
}
