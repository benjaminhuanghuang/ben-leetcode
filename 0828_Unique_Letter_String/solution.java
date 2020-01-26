package cn.huang.leetcode;

/*
828. Unique Letter String

A character is unique in string S if it occurs exactly once in it.

For example, in string S = "LETTER", the only unique characters are "L" and "R".

Let's define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ("LETTER") =  2.

Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.



Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1.



Note: 0 <= S.length <= 10000.

 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
　定义unique character为字符串中出现正好一次的字母，定义UNIQ(S)为字符串S中unique character的个数。给定一个只含有大写字母的字符串S，
求S的所有非空子串的UNIQ之和，如果两个不同位置的子串相同被认为是不同的子串。结果对10^9+7取模。
　　样例：1、”ABC”->10；2、”ABA”->8。
解题思路

　　比较简单的一道题目，考虑每个单独的字母对于最终答案的贡献。如果某个字母a对答案有贡献，那么包含他的子串一定在从这个a往两边延伸到边界
或者另一个a之内位置的范围内。那么总共可能的子串有u*v个，其中u、v分别为延伸到边界或者另一个a之内位置的长度。对每个’A’到’Z’的字母a，
找到每个a的位置，计算往外延伸的长度，乘起来累加到答案即可。
复杂度分析

　　时间复杂度为 O(NM) ，其中M为字母个数，可以认为是常数26。
　　空间复杂度为 O(N)。
*/
public class LC_0828_UniqueLetterString {
    Map<Character, List<Integer>> index;
    int[] peek;
    int N;

    public int uniqueLetterString(String S) {
        index = new HashMap();
        peek = new int[26];
        N = S.length();

        for (int i = 0; i < S.length(); ++i) {
            char c = S.charAt(i);
            index.computeIfAbsent(c, x -> new ArrayList<Integer>()).add(i);
        }

        long cur = 0, ans = 0;
        for (char c : index.keySet()) {
            index.get(c).add(N);
            index.get(c).add(N);
            cur += get(c);
        }

        for (char c : S.toCharArray()) {
            ans += cur;
            long oldv = get(c);
            peek[c - 'A']++;
            cur += get(c) - oldv;
        }
        return (int) ans % 1_000_000_007;
    }

    public long get(char c) {
        List<Integer> indexes = index.get(c);
        int i = peek[c - 'A'];
        return indexes.get(i + 1) - indexes.get(i);
    }
}
