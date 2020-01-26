package cn.huang.leetcode;

/*
984. String Without AAA or BBB


Given two integers A and B, return any string S such that:

    S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
    The substring 'aaa' does not occur in S;
    The substring 'bbb' does not occur in S.



Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Example 2:

Input: A = 4, B = 1
Output: "aabaa"



Note:

    0 <= A <= 100
    0 <= B <= 100
    It is guaranteed such an S exists for the given A and B.


 */
/*
构造出来一个字符串，要求出现A个a和B个b，同时要求不能出现连续三个的a或者b.
但是如果前兩字已經是一樣的 (連續的 a 或連續的 b) 則必須加上另一個字元
 Time Complexity: O(A+B)
 */
public class LC_0984_StringWithoutAAAorBBB {
    public String strWithout3a3b(int A, int B) {
        char a = 'a';
        char b = 'b';
        if (B > A) {
            int tmp = A;
            A = B;
            B = tmp;
            a = 'b';
            b = 'a';
        }
        String ans = "";
        while (A > 0 || B > 0) {
            if (A > 0) {
                ans += a;
                --A;
            }
            if (A > B) {
                ans += a;
                --A;
            }
            if (B > 0) {
                ans += b;
                --B;
            }
        }
        return ans;
    }
}
