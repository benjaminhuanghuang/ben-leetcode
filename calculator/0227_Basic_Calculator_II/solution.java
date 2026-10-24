package cn.huang.leetcode;

import java.util.Stack;

/*
227. Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7

Example 2:

Input: " 3/2 "
Output: 1

Example 3:

Input: " 3+5 / 2 "
Output: 5

Note:

    You may assume that the given expression is always valid.
    Do not use the eval built-in library function.

 */
public class LC_0227_BasicCalculator_II {
    public int calculate(String s) {
        s = s.trim();

        int num = 0;
        int left = 0;
        int right = 0;
        char op = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == ' ')
                continue;
            if (Character.isDigit(c)) {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.length() - 1) {
                if (op == '+') {
                    left = left + right;
                    right = num;
                } else if (op == '-') {
                    left = left + right;
                    right = -num;
                } else if (op == '*') {
                    right *= num;
                } else {
                    right = right / num;
                }
                num = 0;
                op = c;
            }
        }
        return left + right;
    }

    public int calculate_stack(String s) {
        if (s == null || s.length() == 0)
            return 0;
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                num = s.charAt(i) - '0';
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    num = num * 10 + s.charAt(i + 1) - '0';
                    i++;
                }
            }
            if (!Character.isDigit(s.charAt(i)) && s.charAt(i) != ' ' || i == s.length() - 1) {
                // + - 直接放入stack
                if (sign == '+') stack.push(num);
                if (sign == '-') stack.push(-num);
                // * / 运算后压栈
                if (sign == '*') stack.push(stack.pop() * num);
                if (sign == '/') stack.push(stack.pop() / num);
                sign = s.charAt(i);
                num = 0;
            }
        }

        for (int i : stack)
            res += i;

        return res;
    }

    /*
    https://www.youtube.com/watch?v=ABMLLVzf4ZQ&t=394s
     */
    public int calculate_stack2(String s) {
        s = s.trim();
        Stack<Integer> stack = new Stack<>();

        int ans = 0;
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = c - '0';
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    num = num * 10 + s.charAt(i + 1) - '0';
                    i++;
                }
            }
            if(!Character.isDigit(s.charAt(i)) && s.charAt(i) !=' ' || i == s.length()-1)
            {
                if(sign == '+') stack.push(num);
                if(sign == '-') stack.push(-num);
                if(sign == '*') stack.push(stack.pop() * num);
                if(sign == '/') stack.push(stack.pop() / num);
                sign = s.charAt(i);
                num = 0;
            }
        }
        for (int i : stack)
            ans += i;

        return ans;
    }
}
