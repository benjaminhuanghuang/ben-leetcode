package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;

/*
899. Orderly Queue

A string S of lowercase letters is given.  Then, we may make any number of moves.

In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.

Return the lexicographically smallest string we could have after any number of moves.



Example 1:

Input: S = "cba", K = 1
Output: "acb"
Explanation:
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".

Example 2:

Input: S = "baaca", K = 3
Output: "aaabc"
Explanation:
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".



Note:

    1 <= K <= S.length <= 1000
    S consists of lowercase letters only.

 */
public class LC_0899_OrderlyQueue {
    public String orderlyQueue(String S, int K) {
        if (S.equals("")) {
            return "";
        }
        char[] s = S.toCharArray();
        if (K > 1) {
            Arrays.sort(s);
            return new String(s);
        } else {
            char min = 'z';
            for (int i = 0; i < s.length; i++) {
                if (s[i] < min) {
                    min = s[i];
                }
            }
            ArrayList<Integer> starts = new ArrayList<>();
            for (int i = 0; i < s.length; i++) {
                if (s[i] == min) {
                    starts.add(i);
                    while (i < s.length && s[i] == min) {
                        i++;
                    }
                }
            }
            String result = S.substring(starts.get(0)) + S.substring(0, starts.get(0));
            for (int i = 1; i < starts.size(); i++) {
                String temp = S.substring(starts.get(i)) + S.substring(0, starts.get(i));
                if (temp.compareTo(result) < 0) {
                    result = temp;
                }
            }
            return result;
        }
    }
}
