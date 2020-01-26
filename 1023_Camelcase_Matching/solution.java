package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
1023. Binary String With Substrings Representing 1 To N

Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N,
return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.



Example 1:

Input: S = "0110", N = 3
Output: true

Example 2:

Input: S = "0110", N = 4
Output: false



Note:

    1 <= S.length <= 1000
    1 <= N <= 10^9


 */
public class LC_1023_BinaryStringWithSubstringsRepresenting1ToN {
    /*
    Brute Force, try all possible substrings and convert them into decimals.

    Time complexity: O(|S|*log(N)^2)
    */
    public boolean queryString(String S, int N) {
        Set s = new HashSet();
        int c = 0;
        for (int l = 1; l < 32; l++) {
            for (int i = 0; i < S.length() - l + 1; i++) {
                int n = Integer.parseInt(S.substring(i, i + l), 2);
                if (n == 0 || n > N || s.contains(n))
                    continue;
                s.add(n);
                c += 1;
            }
        }

        return c == N;
    }
}
