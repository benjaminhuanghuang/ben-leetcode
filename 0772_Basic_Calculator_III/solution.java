package cn.huang.leetcode;

import java.util.Stack;

/*
	772. Basic Calculator III

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12



Note: Do not use the eval built-in library function.
 */
public class LC_0772_BasicCalculator_III {
    int calculate(String s) {
        s = s.replaceAll(" ", "");
        if (s.length() == 0) return 0;
        Stack<Integer> stack = new Stack<>();
        char sign = '+';
        int res = 0, pre = 0, i = 0;
        while (i < s.length()) {
            char ch = s.charAt(i);
            //consecutive digits as a number, save in `pre`
            if (Character.isDigit(ch)) {
                pre = pre * 10 + (ch - '0');
            }
            //recursively calculate results in parentheses
            if (ch == '(') {
                int j = findClosing(s.substring(i));
                pre = calculate(s.substring(i + 1, i + j));
                i += j;
            }
            //for new signs, calculate with existing number/sign, then update number/sign
            if (i == s.length() - 1 || !Character.isDigit(ch)) {
                switch (sign) {
                    case '+':
                        stack.push(pre);
                        break;
                    case '-':
                        stack.push(-pre);
                        break;
                    case '*':
                        stack.push(stack.pop() * pre);
                        break;
                    case '/':
                        stack.push(stack.pop() / pre);
                        break;
                }
                pre = 0;
                sign = ch;
            }
            i++;
        }
        while (!stack.isEmpty()) res += stack.pop();
        return res;
    }

    private int findClosing(String s) {
        int level = 0, i = 0;
        for (i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                level++;
            else if (s.charAt(i) == ')') {
                level--;
                if (level == 0)
                    break;
            }
        }
        return i;
    }
}
