package cn.huang.leetcode;

import java.util.Arrays;

/*
838. Push Dominoes

There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left;
S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state.

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Note:

    0 <= N <= 10^5
    String dominoes contains only 'L', 'R' and '.'


 */
public class LC_0838_PushDominoes {
    public String pushDominoes(String dominoes) {
        dominoes = "L" + dominoes + "R";
        char[] a = dominoes.toCharArray();

        // This changes "R...R" to "RRRR" and changes "L...L" to "LLLL".
        for (int i = 0, j; i < a.length; i++)
            if (a[i] == 'L' || a[i] == 'R') {
                for (j = i + 1; j < a.length && a[j] == '.'; j++) ; // process .
                if (j < a.length && a[j] == a[i])
                    Arrays.fill(a, i, j, a[i]);
            }

        // Then, handle the case for "R....L" separately.
        for (int i = 0, j = 0; i < a.length; )
            if (a[i] == 'R') {
                for (j = i + 1; j < a.length && a[j] == '.'; j++) ;

                if (j < a.length && a[j] == 'L') {
                    for (int begin = i, end = j; begin < end; begin++, end--) {
                        a[begin] = 'R';
                        a[end] = 'L';
                    }
                }
                i = j;
            } else {
                i++;
            }

        String str = String.valueOf(a);
        return str.substring(1, str.length() - 1);
    }
}
