package cn.huang.leetcode;

/*
856. Score of Parentheses
Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.


 */
public class LC_0856_ScoreofParentheses {
    public int scoreOfParentheses_Recursion(String S) {
        return score(S, 0, S.length() - 1);
    }

    int score(String S, int l, int r) {
        if (r - l == 1) return 1; // "()"
        int b = 0;
        for (int i = l; i < r; ++i) {   // exclude r, check sub string
            if (S.charAt(i) == '(') ++b;
            if (S.charAt(i) == ')') --b;
            if (b == 0) // balanced and is sub string
                // score("(A)(B)") = score("(A)") + score("(B)")
                return score(S, l, i) + score(S, i + 1, r);
        }
        // score("(A)") = 2 * score("A")
        return 2 * score(S, l + 1, r - 1);
    }

    public int scoreOfParentheses_Counting(String S) {
        int ans = 0;
        int d = -1;
        for (int i = 0; i < S.length(); ++i) {
            d += S.charAt(i) == '(' ? 1 : -1;
            if (S.charAt(i) == '(' && S.charAt(i + 1) == ')')
                ans += 1 << d;
        }
        return ans;
    }
}
