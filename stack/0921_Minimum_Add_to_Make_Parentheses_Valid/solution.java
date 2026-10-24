package cn.huang.leetcode;

import java.util.Stack;

/*
921. Minimum Add to Make Parentheses Valid

 */
public class LC_0921_MinimumAddtoMakeParenthesesValid {
    public int minAddToMakeValid(String S) {
        Stack<Character> stack = new Stack<>();

        for (char c : S.toCharArray()) {
            if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                if (stack.size() > 0 && stack.peek() == '(')
                    stack.pop();
                else
                    stack.push(c);
            }
        }
        return stack.size();
    }
}
