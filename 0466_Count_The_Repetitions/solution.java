package cn.huang.leetcode;

/*
466. Count The Repetitions

Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from
s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can
not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and
1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such
that [S2,M] can be obtained from S1.

Example:

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2

 */

/*
http://www.cnblogs.com/grandyang/p/6149294.html

如果s2在S1中出现了N次，那么S2肯定在S1中出现了N/n2次，注意这里的大写表示字符串加上重复次数组成的大字符串。

所以我们得出结论，我们只要算出s2出现的次数，然后除以n2，就可以得出S2出现的次数了。
 */
public class LC_0466_CountTheRepetitions {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int i = 0, count1 = 0, j = 0, count2 = 0;
        while (count1 < n1) {
            if (s1.charAt(i) == s2.charAt(j)) {
                j++;
                if (j == s2.length()) {
                    count2++;
                    j = 0;
                }
            }

            i++;
            if (i == s1.length()) {
                count1++;
                i = 0;
            }
        }
        return count2 / n2;
    }
}
