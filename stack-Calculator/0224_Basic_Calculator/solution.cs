/*
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

using System.Collections.Generic;

public class Solution224 {
    public int Calculate(string s) {

        s = s.Trim();
        var stack_Operand = new Stack<int>();
        
        int num = 0;
        int ans = 0;
        int sign = 1;
        for(int i=0; i < s.Length; i++)
        {
            char c = s[i];

            if (c == ' ')
                continue;
            if (char.IsDigit(c))
            {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '(' || c == ')' || i== s.Length -1)
            {
                if ( c == '(')
                {
                    stack_Operand.Push(ans);
                    stack_Operand.Push(sign);
                    ans = 0;
                    sign = 1;
                }
                else if(c == ')')
                {
                    ans += num * sign;
                    sign = stack_Operand.Pop();
                    num = stack_Operand.Pop();
                    ans = num + ans * sign;
                    sign = 1;
                }
                else{
                    // +, -, number(not the last one)
                    ans += num * sign;
                    sign = c == '+'? 1 : -1;
                }
                num = 0;
            }
        }
        return ans;        
    }
}