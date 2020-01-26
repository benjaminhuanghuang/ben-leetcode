package cn.huang.leetcode;

/*
678. Valid Parenthesis String

 Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether
 this string is valid. We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.

Example 1:

Input: "()"
Output: True

Example 2:

Input: "(*)"
Output: True

Example 3:

Input: "(*))"
Output: True

Note:

    The string size will be in the range [1, 100].

 */
public class LC_0678_ValidParenthesisString {
    public boolean checkValidString1(String s) {
        if (s == null) return true;
        return isValid(s, 0, 0);
    }

    private boolean isValid(String s, int index, int count) {
        if (count < 0)
            return false;
        for (int i = index; i < s.length(); i++) {
            if (s.charAt(i) == '(') count++;
            else if (s.charAt(i) == ')') if (count <= 0) return false;
            else count--;
            else if (s.charAt(i) == '*')
                return isValid(s, i + 1, count + 1) || isValid(s, i + 1, count) || isValid(s, i + 1, count - 1);
        }
        return count == 0;
    }

    /*
    https://www.youtube.com/watch?v=h9Y3i7hhCpo

     */
    public boolean checkValidString(String s) {
        // track the min/max possible open "("
        int min_op = 0;   // 需要强制匹配
        int max_op = 0;   // 可选匹配

        for (char c : s.toCharArray()) {
            if (c == '(')
                ++min_op;
            else   // ")" or "*"
                --min_op;
            if (c == ')')
                --max_op;
            else
                ++max_op;
            if (max_op < 0)
                return false;
            min_op = Math.max(0, min_op);
        }

        return min_op == 0;
    }
}
