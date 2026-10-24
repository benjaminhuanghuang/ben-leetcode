package cn.huang.leetcode;

import java.util.Stack;

/*
224. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2

Example 2:

Input: " 2-1 + 2 "
Output: 3

Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23

 */

/*

 */
public class LC_0224_BasicCalculator {

    public int calculate(String s) {
        s = s.trim();
        Stack<Integer> stack_Operand = new Stack<>();

        int num = 0;
        int ans = 0;
        int sign = 1; // "+"
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == ' ')
                continue;
            if (Character.isDigit(c)) {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '(' || c == ')' || i == s.length() - 1) {
                if (c == '(') {
                    stack_Operand.push(ans);
                    stack_Operand.push(sign);
                    ans = 0;
                    sign = 1;
                } else if (c == ')') {
                    ans += num * sign;
                    sign = stack_Operand.pop();
                    num = stack_Operand.pop();
                    ans = num + ans * sign;
                    sign = 1;
                } else {
                    // +, -, number(not the last one)
                    ans += num * sign;
                    sign = c == '+' ? 1 : -1;
                }
                num = 0;
            }
        }
        return ans;
    }

    /*
    https://www.youtube.com/watch?v=ijyUwyt5vkU
    认为只有加法， 遇到"+， -"赋值给sign， 遇到数字和sign， 遇到"("压栈
     */
    public int calculate2(String s) {
        s = s.trim();
        Stack<Integer> stack = new Stack<>();

        int ans = 0;
        int sign = 1; // "+"


        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == ' ')
                continue;

            if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                stack.push(ans);
                stack.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')') {
                ans *= stack.pop(); // current ans = current ans * sign
                ans += stack.pop(); // previous ans
            } else {
                //(Character.isDigit(c))
                int num = c - '0';
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    num = num * 10 + s.charAt(i + 1) - '0';
                    i++;
                }
                ans += num * sign;
            }
        }
        return ans;
    }
}
