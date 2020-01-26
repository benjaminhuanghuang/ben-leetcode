package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
842. Split Array into Fibonacci Sequence

Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

    0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
    F.length >= 3;
    and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]

Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]

Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.

Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.

Note:

    1 <= S.length <= 200
    S contains only digits.


 */
public class LC_0842_SplitArrayintoFibonacciSequence
{
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> res = new ArrayList<>();
        int len = S.length();
        for (int i = 1; i < len && i < 11; i++) {
            if (S.charAt(0) == '0' && i > 1) return res;
            for (int j = 1; j < len - i && j < 11; j++) {
                if (S.charAt(i) == '0' && j > 1) continue;
                long a = Long.valueOf(S.substring(0, i));
                long b = Long.valueOf(S.substring(i, i + j));
                res.add((int)a);
                res.add((int)b);
                if (isFibonacci(S, a, b, i + j, res)) {
                    return res;
                }
                res.clear();
            }
        }
        return res;
    }

    private boolean isFibonacci(String S, long a, long b, int idx, List<Integer> res) {

        long sum = a + b;
        if (a + b > Integer.MAX_VALUE) return false;
        String sumStr = String.valueOf(sum);
        if (S.startsWith(sumStr, idx)) {
            res.add((int)sum);
            if (idx + sumStr.length() == S.length()) return true;
            return isFibonacci(S, b, sum, idx + sumStr.length(), res);
        }
        return false;
    }
}
