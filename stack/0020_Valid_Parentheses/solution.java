package cn.huang.leetcode;

import java.util.Stack;

/*
    20. Valid Parentheses
 */
public class LC_0020_ValidParentheses {
    public boolean isValid(String s) {
        if (s == null || s.length() < 2)
            return false;

        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                } else {
                    char curr = stack.pop();
                    if (!isPair(curr, c))
                        return false;
                }
            }
        }
        return stack.isEmpty();
    }

    private boolean isPair(char left, char right) {
        return left == '(' && right == ')' ||
                left == '{' && right == '}' ||
                left == '[' && right == ']';
    }
}
